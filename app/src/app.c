#include "app.h"
#include "pwm.h"
#include "adc.h"
#include "stdio.h"

#define APP_PWM_MAX_DC (PWM_MAX_DC) 
#define APP_ADC_MAX_VOLTS (3300)

static const uint16_t gsc_pwm_ch_map[] = {
  PWM_PH_U,
  PWM_PH_V,
  PWM_PH_W,
  PWM_PH_MAX,
};

static const uint16_t gsc_adc_ch_map[] = {
  ADC_PHA_IFBK_CH_E,
  ADC_PHB_IFBK_CH_E,
  ADC_PHC_IFBK_CH_E,
  ADC_POT_CH_E,
  ADC_TEMP_SENS_CH_E,
  ADC_VBUS_CH_E,
  ADC_CH_MAX_E,
  ADC_UNKNOWN_CH_E,
};

uint32_t App_GetVoltage(VAdcCh_E vch) {
  uint32_t adccnts;
  if(vch >= VAdcChMax_E) {
    return INT32_MAX;
  }
  adccnts = ADC_ReadCh(gsc_adc_ch_map[vch]);
  return (uint32_t)((adccnts * (uint32_t)APP_ADC_MAX_VOLTS) / ((uint32_t)ADC_MAX_COUNTS));
}

int32_t App_GetCurrent(IfbkPh_E ifbk) {
  int32_t mvolts;
  if(ifbk >= IfbkPhMax_E) {
    return INT32_MAX;
  }
  mvolts = (int32_t)App_GetVoltage((VAdcCh_E)ifbk) - (int32_t)APP_PARAMS_IFBK_BIAS;
  return (int32_t)(APP_PARAMS_IFBK_R_INV * (mvolts) / (int32_t)APP_PARAMS_IFBK_GAIN);
}

void App_SetPwmDutyCycle(PwmCh_E pwmch, uint32_t pwmdc) {
  if(( pwmch >= PwmChMax_E ) || ( pwmdc > APP_PWM_MAX_DC )) {
    return;
  }
  PWM_SetDC(gsc_pwm_ch_map[pwmch], pwmdc);
  return;
}

void App_SetPwmVoltage(PwmCh_E pwmch, uint32_t mvolts) {
  mvolts = (mvolts > APP_PARAMS_PWM_VOLTS) ? APP_PARAMS_PWM_VOLTS : mvolts;
  uint32_t dcycle = (uint32_t)(mvolts * (APP_PWM_MAX_DC) / ((uint32_t)APP_PARAMS_PWM_VOLTS));
  PWM_SetDC(gsc_pwm_ch_map[pwmch], dcycle);
  return;
}

uint32_t App_GetPwmDutyCycle(PwmCh_E pwmch) {
  if(pwmch >= PwmChMax_E) {
    return UINT32_MAX;
  }
  return PWM_GetDC(gsc_pwm_ch_map[pwmch]);
}

uint32_t App_GetPwmVoltage(PwmCh_E pwmch) {
  uint32_t dcycle;
  if(pwmch >= PwmChMax_E) {
    return UINT32_MAX;
  }
  dcycle = PWM_GetDC(pwmch);
  return (uint32_t)((dcycle * (uint32_t)APP_PARAMS_PWM_VOLTS) / (uint32_t)APP_PWM_MAX_DC);
}
