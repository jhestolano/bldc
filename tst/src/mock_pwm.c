#include "pwm.h"
#include <stdio.h>

uint16_t gs_pwm_ch_buf[PWM_PH_MAX];

#define __HAL_TIM_GET_COMPARE(__HANDLE__, __CHANNEL__) gs_pwm_ch_buf[__CHANNEL__]

uint16_t dctocnts(uint32_t dcycle) {
  dcycle = (dcycle > 10000) ? 10000 : dcycle;
  return (uint16_t)((dcycle * ((uint32_t)PWM_TMR_ARR)) / ((uint32_t)PWM_MAX_DC));
}

void PWM_SetDC(uint32_t pwmch, uint32_t pwmdc) {
  uint16_t pwmcnts = 0;
  if(pwmch >= PWM_PH_MAX) {
    return;
  }
  pwmcnts = dctocnts(pwmdc);
  gs_pwm_ch_buf[pwmch] = pwmcnts;
  return;
}

uint32_t PWM_GetDC(uint32_t pwmch) {
  uint32_t counts;
  if(pwmch >= PWM_PH_MAX) {
    return UINT32_MAX;
  }
  counts = (uint32_t)__HAL_TIM_GET_COMPARE(&gs_pwm_conf, pwmch); 
  return (uint32_t)(counts * (uint32_t)PWM_MAX_DC / ((uint32_t)PWM_TMR_ARR));
}
