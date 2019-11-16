#include "tmr.h"
#include "adc.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_tim.h"
#include "stm32f3xx_hal_tim_ex.h"
#include "stm32f3xx_hal_rcc.h"

static TIM_HandleTypeDef gs_tim_init_conf = TMR_INIT_CONF;  

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* s_tim_conf) {
  UNUSED(s_tim_conf);

  if(!__HAL_RCC_TIM2_IS_CLK_ENABLED()) {
    __HAL_RCC_TIM2_CLK_ENABLE();
  }
}

void TMR_Init(void) {
  HAL_TIM_Base_Init(&gs_tim_init_conf);
}

void TMR_Start(void) {
  HAL_TIM_Base_Start(&gs_tim_init_conf);
}

void TMR_Stop(void) {
  __HAL_TIM_DISABLE(&gs_tim_init_conf);
}

void TMR_Resume(void) {
  __HAL_TIM_ENABLE(&gs_tim_init_conf);
}

void TMR_Reset(void) {
  __HAL_TIM_SET_COUNTER(&gs_tim_init_conf, 0u);
}

uint32_t TMR_GetCount(void) {
  uint32_t count;
  __ADC_DISABLE_ISR();
  count = (uint32_t)__HAL_TIM_GET_COUNTER(&gs_tim_init_conf);
  __ADC_ENABLE_ISR();
  return count;
}
