#include "pwm.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_tim.h"
#include "stm32f3xx_hal_tim_ex.h"
#include "stm32f3xx_hal_rcc_ex.h"
#include "stm32f3xx_hal_rcc.h"


#define PWM_TMR_CLK_HZ ((uint32_t)72000000)
#define PWM_TMR_FREQ_HZ ((uint32_t)30000)
#define PWM_TMR_PERIOD (PWM_TMR_CLK_HZ / PWM_TMR_FREQ_HZ)

#define PWM_CHANNEL_LAST_ELEM (0xFFFFU)

const uint16_t PWMChannel_a[] = {
  UH_PWM_CHANNEL,
  VH_PWM_CHANNEL,
  WH_PWM_CHANNEL,
  PWM_CHANNEL_LAST_ELEM,
};

void PWM_Error_Handler(void) {
  while(1);
}

/*
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_handle) {
  // BKIN2 Functionality.

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Pin = M1_OCP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF12_TIM1;
  HAL_GPIO_Init(M1_OCP_GPIO_Port, &GPIO_InitStruct);
}
*/

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* tim_handle) {

  UNUSED(tim_handle);

  GPIO_InitTypeDef gpio_init = {0};

  if(!__HAL_RCC_TIM1_IS_CLK_ENABLED()){
      __HAL_RCC_TIM1_CLK_ENABLE();
  }

  if(!__HAL_RCC_GPIOA_IS_CLK_ENABLED()) {
    __HAL_RCC_GPIOA_CLK_ENABLE();
  }

  gpio_init.Pin = UH_PWM_PIN | VH_PWM_PIN | WH_PWM_PIN;
  gpio_init.Mode = GPIO_MODE_AF_PP;
  gpio_init.Pull = GPIO_PULLDOWN;
  gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio_init.Alternate = GPIO_AF6_TIM1;
  HAL_GPIO_Init(GPIOA, &gpio_init);
}

void PWM_Init(void) {
  uint8_t idx;
  TIM_HandleTypeDef tim_handle = {0};
  TIM_OC_InitTypeDef oc_init = {0};

  tim_handle.Instance = TIM1;
  tim_handle.Init.Prescaler =  1;
  tim_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  tim_handle.Init.Period = PWM_TMR_PERIOD;
  tim_handle.Init.RepetitionCounter = 0;
  tim_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV2;
  tim_handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  
  /*if(HAL_TIM_Base_Init(&tim_handle) != HAL_OK) {
    PWM_Error_Handler();
  }*/
  
  if(HAL_TIM_PWM_Init(&tim_handle) != HAL_OK) {
    PWM_Error_Handler();
  }

  oc_init.OCMode = TIM_OCMODE_PWM1;
  oc_init.Pulse = PWM_TMR_PERIOD * .90;
  oc_init.OCPolarity = TIM_OCPOLARITY_HIGH;
  oc_init.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  oc_init.OCFastMode = TIM_OCFAST_DISABLE;
  oc_init.OCIdleState = TIM_OCIDLESTATE_RESET;
  oc_init.OCNIdleState = TIM_OCNIDLESTATE_RESET;

  HAL_TIM_PWM_ConfigChannel(&tim_handle, &oc_init, UH_PWM_CHANNEL);

  oc_init.Pulse = 0;
  HAL_TIM_PWM_ConfigChannel(&tim_handle, &oc_init, VH_PWM_CHANNEL);
  HAL_TIM_PWM_ConfigChannel(&tim_handle, &oc_init, WH_PWM_CHANNEL);

/*
  for(idx = 0; PWMChannel_a[idx] != PWM_CHANNEL_LAST_ELEM; idx++) {
    if(HAL_TIM_PWM_ConfigChannel(&tim_handle, &oc_init, UH_PWM_CHANNEL) != HAL_OK) {
      PWM_Error_Handler();
    }
  }*/

  return;
}