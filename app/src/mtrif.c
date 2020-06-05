#include "mtrif.h"
#include "app.h"
#include <string.h>
#include <stddef.h>
#include "adc.h"
#include "rtwtypes.h"
#include "ctrl_30khz.h"

typedef struct MtrIf_tag {
  float mtr_spd;
  float mtr_spd_fil;
  float dist_obs;
  float pos_est;
  float pwm_rqst;
} MtrIf_S;

static volatile MtrIf_S _mtr_if_s;

static RT_MODEL_ctrl_30khz_T mtr_ctrl_30k_s;

static void _mtr_if_adc_isr_callback(void *params) {
  CTRL_Task30KHz(
    &mtr_ctrl_30k_s,
    (real_T)MtrIf_GetPos(),
    (real_T)MtrIf_GetCurrent(),
    /* Motor current target. */
    0,
    (real_T*)&_mtr_if_s.mtr_spd,
    (real_T*)&_mtr_if_s.mtr_spd_fil,
    (real_T*)&_mtr_if_s.dist_obs,
    (real_T*)&_mtr_if_s.pos_est,
    (real_T*)&_mtr_if_s.pwm_rqst
  );
}

void MtrIf_Init(void) {
  MTRIF_LOCK();
  ADC_IsrCallback = _mtr_if_adc_isr_callback;
  MTRIF_UNLOCK();
  CTRL_Init(&mtr_ctrl_30k_s);
  App_ArmMotor();
}

void MtrIf_SetVin(int32_t vin) {
  if(vin >= 0) {
    App_SetPwmVoltage(MTRIF_POS_PH, (uint32_t)vin);
    App_SetPwmVoltage(MTRIF_NEG_PH, 0);
  } else {
    App_SetPwmVoltage(MTRIF_POS_PH, 0);
    App_SetPwmVoltage(MTRIF_NEG_PH, (uint32_t)(-vin));
  }
}

int32_t MtrIf_GetVin(void) {
  int32_t vin = (int32_t)App_GetPwmVoltage(MTRIF_POS_PH)
               -(int32_t)App_GetPwmVoltage(MTRIF_NEG_PH);
  return vin;
}

int32_t MtrIf_GetCurrent(void) {
  int32_t current = App_GetCurrent(MTRIF_POS_PH_IFBK)
                  - App_GetCurrent(MTRIF_NEG_PH_IFBK);
  return current;
}

int32_t MtrIf_GetPos(void) {
  return App_GetPosition();
}

int32_t MtrIf_GetSpd(void) {
  int32_t spd;
  MTRIF_LOCK();
  spd = (int32_t)_mtr_if_s.mtr_spd_fil;
  MTRIF_UNLOCK();
  return spd;
}
