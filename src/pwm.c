#include "pwm.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_tim.h"
#include "stm32f3xx_hal_tim_ex.h"
#include "stm32f3xx_hal_rcc_ex.h"
#include "stm32f3xx_hal_rcc.h"
#include "stm32f3xx_ll_tim.h"
#include "dbg.h"

TIM_HandleTypeDef gs_pwm_conf = PWM_INIT_CONF;

void Pwm_ErroHandler(char* errmsg) {
  DBG_ERR("PWM: %s\n\r", errmsg);
  while(1);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* s_pwm_conf) {
  UNUSED(s_pwm_conf);
  GPIO_InitTypeDef s_pwm_gpio_conf = PWM_GPIO_CONF;
  if(!__HAL_RCC_TIM1_IS_CLK_ENABLED()){
      __HAL_RCC_TIM1_CLK_ENABLE();
  }

  if(!__HAL_RCC_GPIOA_IS_CLK_ENABLED()) {
    __HAL_RCC_GPIOA_CLK_ENABLE();
  }

  HAL_GPIO_Init(GPIOA, &s_pwm_gpio_conf);
}

void PWM_Init(void) {

  TIM_BreakDeadTimeConfigTypeDef s_pwm_dt_conf = PWM_DEADTIME_CONF;
  TIM_OC_InitTypeDef s_pwm_oc_conf = PWM_OC_CONF;
  TIM_MasterConfigTypeDef s_master_out_conf = PWM_MASTER_OUT_CONF;

  DBG_DEBUG("Initializing PWM module...\n\r");
  if(HAL_TIM_PWM_Init(&gs_pwm_conf) != HAL_OK) {
    Pwm_ErroHandler("Error initializing TIM module.");
  }
  
  /*
  if(HAL_TIMEx_ConfigBrakDeadTime(&gs_pwm_conf, &s_pwm_dt_conf) != HAL_OK) {
    Pwm_ErroHandler();
  }
  */

  if(HAL_TIMEx_MasterConfigSynchronization(&gs_pwm_conf, &s_master_out_conf)) {
    Pwm_ErroHandler("Error in MasterConfigSynchronization configuration.");
  }

  if(HAL_TIM_PWM_ConfigChannel(&gs_pwm_conf, &s_pwm_oc_conf, UH_PWM_CHANNEL) != HAL_OK) {
    DBG_ERR("Error initializing U-PHASE PWM Channel.");
  }

  s_pwm_oc_conf.Pulse = 0;

  if(HAL_TIM_PWM_ConfigChannel(&gs_pwm_conf, &s_pwm_oc_conf, VH_PWM_CHANNEL) != HAL_OK) {
    DBG_ERR("Error initializing V-PHASE PWM Channel.");
  }
  if(HAL_TIM_PWM_ConfigChannel(&gs_pwm_conf, &s_pwm_oc_conf, WH_PWM_CHANNEL) != HAL_OK) {
    DBG_ERR("Error initializing W-PHASE PWM Channel.");
  }

  HAL_TIM_PWM_Start(&gs_pwm_conf, UH_PWM_CHANNEL);
  HAL_TIM_PWM_Start(&gs_pwm_conf, VH_PWM_CHANNEL);
  HAL_TIM_PWM_Start(&gs_pwm_conf, WH_PWM_CHANNEL);

  DBG_DEBUG("Done.\n\r");

  return;
}


void PWM_SetDC(uint32_t channel, uint32_t dc) {
//  __HAL_TIM_SET_COMPARE()
}
