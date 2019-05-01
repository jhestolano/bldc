#include "adc.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_rcc.h"
#include "stm32f3xx_hal_cortex.h"

static void ADC_ErrorHandler(void) {
  while(1);
  return;
}

void ADC1_IRQHandler(void) {
  HAL_ADC_IRQHandler(&gsAdcHandle);
}

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* adc_handle) {
  uint8_t idx;
  uint16_t adc_a[3] = {0};
  for(idx = 0; idx < 3; idx++) {
     adc_a[idx] = HAL_ADCEx_InjectedGetValue(&gsAdcHandle, (uint32_t)ADC_INJECTED_RANK_1 + idx);
  }
  return;
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adc_handle) {
  GPIO_InitTypeDef gpio_init = {0};

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

  gpio_init.Pin = POT_ADC_PIN;
  gpio_init.Mode = GPIO_MODE_ANALOG;
  gpio_init.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(POT_ADC_PORT, &gpio_init);

  gpio_init.Pin = PHB_IFBK_ADC_PIN | PHC_IFBK_ADC_PIN | TEMP_SENS_ADC_PIN;
  gpio_init.Mode = GPIO_MODE_ANALOG;
  gpio_init.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PHB_IFBK_ADC_PORT, &gpio_init);

  gpio_init.Pin = PHA_IFBK_ADC_PIN | VBUS_ADC_PIN;
  gpio_init.Mode = GPIO_MODE_ANALOG;
  gpio_init.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PHA_IFBK_ADC_PORT, &gpio_init);

  return;
}


void ADC_Init(void) {

  ADC_InjectionConfTypeDef sConfigInjected = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  HAL_NVIC_SetPriority(ADC1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(ADC1_IRQn);

  gsAdcHandle.Instance = ADC1;
  gsAdcHandle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV1;
  gsAdcHandle.Init.Resolution = ADC_RESOLUTION_12B;
  gsAdcHandle.Init.ScanConvMode = ADC_SCAN_ENABLE;
  gsAdcHandle.Init.ContinuousConvMode = DISABLE;
  gsAdcHandle.Init.DiscontinuousConvMode = DISABLE;
  gsAdcHandle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  gsAdcHandle.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  gsAdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  gsAdcHandle.Init.NbrOfConversion = 3;
  gsAdcHandle.Init.DMAContinuousRequests = DISABLE;
  gsAdcHandle.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  gsAdcHandle.Init.LowPowerAutoWait = DISABLE;
  gsAdcHandle.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&gsAdcHandle) != HAL_OK)
  {
    ADC_ErrorHandler();
  }

  // HAL_ADCEx_Calibration_Start(&gsAdcHandle, ADC_SINGLE_ENDED);

  sConfigInjected.InjectedSingleDiff = ADC_SINGLE_ENDED;
  sConfigInjected.InjectedNbrOfConversion = 3;
  sConfigInjected.InjectedSamplingTime = ADC_SAMPLETIME_19CYCLES_5;
  sConfigInjected.ExternalTrigInjecConvEdge = ADC_EXTERNALTRIGINJECCONV_EDGE_NONE;
  sConfigInjected.ExternalTrigInjecConv = ADC_INJECTED_SOFTWARE_START;
  sConfigInjected.AutoInjectedConv = DISABLE;
  sConfigInjected.InjectedDiscontinuousConvMode = DISABLE;
  sConfigInjected.QueueInjectedContext = DISABLE;
  sConfigInjected.InjectedOffset = 0;
  sConfigInjected.InjectedOffsetNumber = ADC_OFFSET_NONE;

  sConfigInjected.InjectedChannel = POT_ADC_CHANNEL;
  sConfigInjected.InjectedRank = ADC_INJECTED_RANK_1;
  if (HAL_ADCEx_InjectedConfigChannel(&gsAdcHandle, &sConfigInjected) != HAL_OK)
  {
    ADC_ErrorHandler();
  }

  sConfigInjected.InjectedChannel = TEMP_SENS_ADC_CHANNEL;
  sConfigInjected.InjectedRank = ADC_INJECTED_RANK_2;
  if (HAL_ADCEx_InjectedConfigChannel(&gsAdcHandle, &sConfigInjected) != HAL_OK)
  {
    ADC_ErrorHandler();
  }
  sConfigInjected.InjectedChannel = VBUS_ADC_CHANNEL;
  sConfigInjected.InjectedRank = ADC_INJECTED_RANK_3;
  if (HAL_ADCEx_InjectedConfigChannel(&gsAdcHandle, &sConfigInjected) != HAL_OK)
  {
    ADC_ErrorHandler();
  }

  return;
}

void ADC_Start(void) {
  HAL_ADC_Start(&gsAdcHandle);
  return;
}

void ADC_WaitConv(void) {
  HAL_ADC_PollForConversion(&gsAdcHandle, (uint32_t)100);
  return;
}

uint32_t ADC_Read(void) {
  return HAL_ADC_GetValue(&gsAdcHandle);
}


