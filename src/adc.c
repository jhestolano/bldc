#include "adc.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_rcc.h"
#include "stm32f3xx_hal_cortex.h"

ADC_HandleTypeDef gs_adc_handle = ADC_INIT_CONF;

static void ADC_ErrorHandler(void) {
  while(1);
  return;
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adc_handle) {

  GPIO_InitTypeDef s_gpioa_input_conf = GPIOA_ADC_INPUT_CONF;
  GPIO_InitTypeDef s_gpiob_input_conf = GPIOB_ADC_INPUT_CONF;
  GPIO_InitTypeDef s_gpioc_input_conf = GPIOC_ADC_INPUT_CONF;

  __HAL_RCC_ADC1_CLK_ENABLE();
  
  if(!__HAL_RCC_GPIOA_IS_CLK_ENABLED()) {
    __HAL_RCC_GPIOA_CLK_ENABLE();
  }

  if(!__HAL_RCC_GPIOB_IS_CLK_ENABLED()) {
    __HAL_RCC_GPIOB_CLK_ENABLE();
  }

  if(!__HAL_RCC_GPIOC_IS_CLK_ENABLED()) {
    __HAL_RCC_GPIOC_CLK_ENABLE();
  }

  HAL_GPIO_Init(GPIOA, &s_gpioa_input_conf);
  HAL_GPIO_Init(GPIOB, &s_gpiob_input_conf);
  HAL_GPIO_Init(GPIOC, &s_gpioc_input_conf);

  return;
}


void ADC_Init(void) {

  ADC_ChannelConfTypeDef s_pot_conf = POT_ADC_CONF;
  /*
  ADC_InjectionConfTypeDef s_pot_inj_conf = POT_ADC_INJ_CONF;
  ADC_InjectionConfTypeDef s_temp_sens_inj_conf = TEMP_SENS_ADC_INJ_CONF;
  ADC_InjectionConfTypeDef s_vbus_inj_conf = VBUS_ADC_INJ_CONF;
  */
  HAL_NVIC_SetPriority(ADC1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(ADC1_IRQn);

  if (HAL_ADC_Init(&gs_adc_handle) != HAL_OK)
  {
    ADC_ErrorHandler();
  }
  HAL_ADC_ConfigChannel(&gs_adc_handle, &s_pot_conf);
  // HAL_ADCEx_Calibration_Start(&gs_adc_handle, ADC_SINGLE_ENDED);
  /*
  if (HAL_ADCEx_InjectedConfigChannel(&gs_adc_handle, &s_pot_inj_conf) != HAL_OK)
  {
    ADC_ErrorHandler();
  }

  if (HAL_ADCEx_InjectedConfigChannel(&gs_adc_handle, &s_temp_sens_inj_conf) != HAL_OK)
  {
    ADC_ErrorHandler();
  }

  if (HAL_ADCEx_InjectedConfigChannel(&gs_adc_handle, &s_vbus_inj_conf) != HAL_OK)
  {
    ADC_ErrorHandler();
  }
  */
  return;
}

void ADC_Start(void) {
  HAL_ADC_Start_IT(&gs_adc_handle);
  return;
}

void ADC_WaitConv(void) {
  HAL_ADC_PollForConversion(&gs_adc_handle, (uint32_t)100);
  return;
}

uint32_t ADC_Read(void) {
  return HAL_ADC_GetValue(&gs_adc_handle);
}

void ADC1_IRQHandler(void) {
  HAL_ADC_IRQHandler(&gs_adc_handle);
}

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* adc_handle) {
  uint8_t idx;
  uint16_t adc_a[3] = {0};
  for(idx = 0; idx < 3; idx++) {
     adc_a[idx] = HAL_ADCEx_InjectedGetValue(&gs_adc_handle, (uint32_t)ADC_INJECTED_RANK_1 + idx);
  }
  return;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* adc_handle) {
  uint32_t adcval = ADC_Read();
  return;
}
