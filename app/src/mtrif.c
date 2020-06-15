#include "mtrif.h"
#include "app.h"
#include <string.h>
#include <stddef.h>
#include "adc.h"
#include "rtwtypes.h"
#include "ctrl_30khz.h"
#include "ctrl_1khz.h"
/* #include "ctrl.h" */

real32_T Spd_PI_Kp = 0.0047f;

real32_T Spd_PI_Ki = 0.0092f;

real32_T Pos_PI_Kp = 13.33f;

real32_T Pos_PI_Ki = 0.0f;

typedef struct MtrIf_tag {

  float mtr_spd; /* Actual motor speed. */
 
  float mtr_spd_fil; /* Actual motor speed after filter. */

  float dist_trq; /* Disturbance torque estimation. */

  float pos_est; /* Position estimation by dustrbance observer. */

  float pwm_rqst; /* Output of 30khz controller. */

  float ifbk_tgt; /* Output of 1khz controller. */

  float mtr_tgt; /* Target for 1khz controller. The meaning (units) of this
                    depends on the control mode: Position, Speed or Current
                    control mode. */

  uint8_t ctrl_fast_is_init; /* Indicates if 30khz controller is initialized.
                                The controller algorithm will not run until
                                this flag is set.*/

  uint8_t ctrl_is_init; /* Indicates if 1khz controller is initialized.
                           The controller will not run until this flag
                           is set.*/

  MtrCtlMd_T ctrl_md; /* Position, Speed or Current control mode. */

  uint8_t mtr_is_idnt; /* Identification routine has been ran. */

  float mtr_tau;

  float mtr_kdc;

} MtrIf_S;

static volatile MtrIf_S _mtr_if_s;

static RT_MODEL_ctrl_30khz_T _ctrl_30khz_s;

static RT_MODEL_ctrl_1khz_T _ctrl_1khz_s;

static void _mtr_if_adc_isr_callback(void *params) {
  if(_mtr_if_s.ctrl_fast_is_init) {
    Ctrl30Khz(
      &_ctrl_30khz_s,
      (float)MtrIf_GetPos(),
      (float)MtrIf_GetIfbk(),
      _mtr_if_s.ifbk_tgt,
      &_mtr_if_s.dist_trq,
      &_mtr_if_s.pos_est,
      &_mtr_if_s.mtr_spd,
      &_mtr_if_s.pwm_rqst
    );
    MtrIf_SetVin((int32_t)_mtr_if_s.pwm_rqst);
  }
}

void MtrIf_Init(void) {
  MTRIF_LOCK();
  ADC_IsrCallback = _mtr_if_adc_isr_callback;
  Ctrl30Khz_Init(&_ctrl_30khz_s);
  Ctrl1Khz_Init(&_ctrl_1khz_s);
  /* Control task at 30khz is ready. */
  _mtr_if_s.ctrl_fast_is_init = true;
  /* Control task at 1khz is ready. */
  _mtr_if_s.ctrl_is_init = true;

  MTRIF_UNLOCK();

  _mtr_if_s.mtr_is_idnt = false;

  _mtr_if_s.mtr_tau = 0.0f;

  _mtr_if_s.mtr_kdc = 0.0f;

  App_ArmMotor();
}

void MtrIf_SetVin(int32_t vin) {
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

int32_t MtrIf_GetVin(void) {
  int32_t vin = (int32_t)App_GetPwmVoltage(MTRIF_POS_PH)
               -(int32_t)App_GetPwmVoltage(MTRIF_NEG_PH);
  return vin;
}

int32_t MtrIf_GetIfbk(void) {
  int32_t ifbk;
  if (MtrIf_GetVin() >= 0) {
    ifbk = App_GetCurrent(MTRIF_NEG_PH_IFBK);
  } else {
    ifbk = -App_GetCurrent(MTRIF_POS_PH_IFBK);
  }
  return ifbk;
}

int32_t MtrIf_GetPos(void) {
  return App_GetPosition();
}

int32_t MtrIf_GetPosEst(void) {
  int32_t pos_est;
  MTRIF_LOCK();
  pos_est = (int32_t)_mtr_if_s.pos_est;
  MTRIF_UNLOCK();
  return pos_est;
}

int32_t MtrIf_GetSpd(void) {
  int32_t spd;
  MTRIF_LOCK();
  spd = (int32_t)_mtr_if_s.mtr_spd;
  MTRIF_UNLOCK();
  return spd;
}

void MtrIf_SetIfbkTgt(int32_t ifbktgt) {
  MTRIF_LOCK();
  _mtr_if_s.ifbk_tgt = (float)ifbktgt;
  MTRIF_UNLOCK();
}

int32_t MtrIf_GetIfbkTgt(void) {
  int32_t ifbk_tgt;
  MTRIF_LOCK();
  ifbk_tgt = (int32_t)_mtr_if_s.ifbk_tgt;
  MTRIF_UNLOCK();
  return ifbk_tgt;
}

void MtrIf_Ctl(void) {
  float ifbk_tgt;
  float mtr_ref;
  if (_mtr_if_s.ctrl_is_init == true) {
    Ctrl1Khz(
      &_ctrl_1khz_s,
      /* Controller target value: Position/Speed/Current. */
      _mtr_if_s.mtr_tgt,
      MtrIf_GetPos(),
      MtrIf_GetSpd(),
      /* Control mode: Position/Speed/Current. */
      _mtr_if_s.ctrl_md,
      /* Control output. Input to 30khz controller. */
      &ifbk_tgt,
      /* Unimplemented. */
      &mtr_ref
    );
    MtrIf_SetIfbkTgt((int32_t)ifbk_tgt);
  }
}

MtrCtlMd_T MtrIf_GetCtlMd(void) {
  return _mtr_if_s.ctrl_md;
}

void MtrIf_SetCtlMd(MtrCtlMd_T ctrl_md) {
  _mtr_if_s.ctrl_md = ctrl_md;
}

void MtrIf_SetTgt(int32_t tgt) {
  _mtr_if_s.mtr_tgt = (float)tgt;
}

void MtrIf_CtlTune(float tau, float kdc) {
  Spd_PI_Ki = 4.0f / (kdc * (float)MTRIF_CTL_SPD_TS);
  Spd_PI_Kp = tau * Spd_PI_Ki;
  Pos_PI_Kp = 4.0f / (float)MTRIF_CTL_POS_TS;
  Pos_PI_Ki = 0.0f;
}
