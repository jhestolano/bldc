#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include "mtrif.h"
#include "stdlib.h"
#include "gpio.h"
#include "pmsm_ctrl.h"
#include "pmsm_ctrl_types.h"

#define MTRIF_TO_DEG (0.1f) /* App layer position resolution is 0.1 degrees
                               represented as int. For example, a value of
                               13 represents 1.3 degrees. */
#define MTRIF_TO_MILLIS (1.0e3f) /* Convert to millis (amps, volts, etc.) */
#define MTRIF_FROM_MILLIS (1.0e-3f) /* Convert back from millis. */

typedef struct MtrIf_State_tag {
  uint8_t is_init;
  float pwm_dc[3];
  float mod_wave[3];
  float mtr_ifbk[3];
  float mtr_spd;
  float mtr_trq;
  int32_t enc_cnts;
} MtrIf_State_S;

MtrIf_State_S _mtr_if_s = {0};

/* Function called within interrupt context from ADC. */
static void _mtr_if_adc_isr_callback(void *params) {

  if(_mtr_if_s.is_init) {
    MtrIf_CtrlFast();
  }

  /* Heartbeat. */
  static int32_t tmr;
  if(tmr++ >= 30e3) {
    GPIO_LedToggle();
    tmr = 0;
  }

}

RT_MODEL pmsm_ctrl_obj;

void MtrIf_Init(void) {
  MTRIF_LOCK();

  ADC_AttachISRCallback(_mtr_if_adc_isr_callback);

  Trig_Pmsm_Init(&pmsm_ctrl_obj);

  _mtr_if_s.is_init = true;

  MTRIF_UNLOCK();
  App_ArmMotor();
}

void MtrIf_CtrlSlow(void) {
  boolean_T cal_actv;
  Trig_Pmsm_CtrlMgr(&pmsm_ctrl_obj);
  Trig_Pmsm_Cal(&pmsm_ctrl_obj, &cal_actv);
  Trig_Pmsm_MotnCtrl(&pmsm_ctrl_obj);
}

void MtrIf_CtrlFast(void) {

  MtrIf_GetIfbk(&_mtr_if_s.mtr_ifbk[0]);

  Trig_Pmsm_SetIn(
    &pmsm_ctrl_obj,
    App_GetEncCnt(), /* Encoder counts */
    (real32_T*)&_mtr_if_s.mtr_ifbk[0], /* Array with phase currents. */
    (real32_T)0.0f, /* Speed sensor */
    CTRL_MD_CAL, /* Control mode */
    (real32_T)0.0f, /* Control target */
    CAL_IND_ID /* Calibration request. */
  );

  Trig_Pmsm_Foc(&pmsm_ctrl_obj);

  Trig_Pmsm_GetOut(
    &pmsm_ctrl_obj,
    (real32_T*)&_mtr_if_s.pwm_dc[0],
    (real32_T*)&_mtr_if_s.mod_wave[0],
    (real32_T*)&_mtr_if_s.mtr_trq,
    (real32_T*)&_mtr_if_s.mtr_spd
  );

  MtrIf_SetPwmDc(&_mtr_if_s.pwm_dc[0]);
}

void MtrIf_SetVin(float mtrvin) {
  int32_t vin = (int32_t)(mtrvin * MTRIF_TO_MILLIS);
  if(vin > 0) {
    App_SetPwmVoltage(MTRIF_POS_PH, (uint32_t)vin);
    App_SetPwmVoltage(MTRIF_NEG_PH, 0);
  } else if(vin < 0){
    App_SetPwmVoltage(MTRIF_POS_PH, 0);
    App_SetPwmVoltage(MTRIF_NEG_PH, (uint32_t)(-vin));
  } else {
    App_SetPwmVoltage(MTRIF_POS_PH, 0);
    App_SetPwmVoltage(MTRIF_NEG_PH, 0);
  }
}

void MtrIf_SetPwmDc(float* pwm_a) {
  if(pwm_a) {
    for(size_t i = 0; i < PwmChMax_E; i++) {
      App_SetPwmDutyCycle((PwmCh_E)i, pwm_a[i] * (float)APP_PWM_MAX_DC);
    }
  }
}

void MtrIf_GetPwmDc(float* pwm_a) {
  if(pwm_a) {
    for(size_t i = 0; i < PwmChMax_E; i++) {
      pwm_a[i] = (float)App_GetPwmDutyCycle((PwmCh_E)i) / (float)APP_PWM_MAX_DC;
    }
  }
}

float MtrIf_GetPwmDcCh(PwmCh_E ch) {
    return (float)App_GetPwmDutyCycle((PwmCh_E)ch) / (float)APP_PWM_MAX_DC;
}

void MtrIf_GetVin(float* vin) {
  if(vin) {
    for(size_t i = 0; i < PwmChMax_E; i++) {
      vin[i] = MTRIF_FROM_MILLIS * (float)App_GetPwmVoltage((PwmCh_E)i);
    }
  }
}


float MtrIf_GetIfbk(float* ifbk) {
  if(ifbk) {
    for(size_t i = 0; i < IfbkPhMax_E; i++) {
      ifbk[i] = MTRIF_FROM_MILLIS * (float)App_GetCurrent((IfbkPh_E)i);
    }
  }
}

float MtrIf_GetIfbkPh(IfbkPh_E ph) {
  return MTRIF_FROM_MILLIS * (float)App_GetCurrent(ph);
}

float MtrIf_GetPos(void) {
  return (float)App_GetPosition() * (MTRIF_TO_DEG);
}

float MtrIf_GetPosEst(void) {
  float pos_est;
  MTRIF_LOCK();
  /* pos_est = _mtr_if_s.pos_est; */
  MTRIF_UNLOCK();
  return pos_est;
}

float MtrIf_GetSpd(void) {
  float spd;
  MTRIF_LOCK();
  spd = _mtr_if_s.mtr_spd;
  MTRIF_UNLOCK();
  return spd;
}

float MtrIf_GetTrq(void) {
  float trq;
  MTRIF_LOCK();
  trq = _mtr_if_s.mtr_trq;
  MTRIF_UNLOCK();
  return trq;
}

MtrCtlMd_T MtrIf_GetCtlMd(void) {
  /* return _mtr_if_s.ctrl_md; */
  return (MtrCtlMd_T)0;
}

void MtrIf_SetCtlMd(MtrCtlMd_T ctrl_md) {
  /* _mtr_if_s.ctrl_md = ctrl_md; */
}

void MtrIf_SetTgt(float tgt) {
  /* _mtr_if_s.mtr_tgt = tgt; */
}

void MtrIf_GetModWave(float* mod_wave) {
  if(mod_wave) {
    MTRIF_LOCK();
    mod_wave[0] = _mtr_if_s.mod_wave[0];
    mod_wave[1] = _mtr_if_s.mod_wave[1];
    mod_wave[2] = _mtr_if_s.mod_wave[2];
    MTRIF_UNLOCK();
  }
}
