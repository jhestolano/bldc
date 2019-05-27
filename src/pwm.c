#include "pwm.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_tim.h"
#include "stm32f3xx_hal_tim_ex.h"
#include "stm32f3xx_hal_rcc_ex.h"
#include "stm32f3xx_hal_rcc.h"

#define PWM_TMR_CLOCK_HZ ((uint32_t)72000000)
#define PWM_TMR_FREQ_HZ ((uint32_t)30000)
#define PWM_TMR_PERIOD (PWM_TMR_CLOCK_HZ / PWM_TMR_FREQ_HZ)

void PWM_Error_Handler(void) {
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

  TIM_HandleTypeDef s_pwm_conf = PWM_INIT_CONF;
  TIM_BreakDeadTimeConfigTypeDef s_pwm_dt_conf = PWM_DEADTIME_CONF;
  TIM_OC_InitTypeDef s_pwm_oc_conf = PWM_OC_CONF;
  TIM_MasterConfigTypeDef s_master_out_conf = PWM_MASTER_OUT_CONF;

  if(HAL_TIM_PWM_Init(&s_pwm_conf) != HAL_OK) {
    PWM_Error_Handler();
  }

  if (HAL_TIMEx_ConfigBreakDeadTime(&s_pwm_conf, &s_pwm_dt_conf) != HAL_OK) {
    PWM_Error_Handler();
  }

  HAL_TIM_PWM_ConfigChannel(&s_pwm_conf, &s_pwm_oc_conf, UH_PWM_CHANNEL);
  HAL_TIM_PWM_ConfigChannel(&s_pwm_conf, &s_pwm_oc_conf, VH_PWM_CHANNEL);
  HAL_TIM_PWM_ConfigChannel(&s_pwm_conf, &s_pwm_oc_conf, WH_PWM_CHANNEL);

  HAL_TIM_PWM_Start(&s_pwm_conf, UH_PWM_CHANNEL);
  HAL_TIM_PWM_Start(&s_pwm_conf, VH_PWM_CHANNEL);
  HAL_TIM_PWM_Start(&s_pwm_conf, WH_PWM_CHANNEL);

  return;
}
