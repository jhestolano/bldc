#include "adc.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_rcc.h"

void HAL_ADC_MspInit(ADC_HandleTypeDef* adc_handle) {
	GPIO_InitTypeDef gpioinit;
	
	// GPIO & ADC Clock Enable.
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_ADC1_CLK_ENABLE();

	// GPIO Init.
	gpioinit.Pin = GPIO_PIN_4;
	gpioinit.Mode = GPIO_MODE_ANALOG;
	gpioinit.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &gpioinit);

	// Configure DMA if needed.
	// NVIC Priority / Enable.
	return;
}

void ADC_Init(void) {
	// ADC_HandleTypeDef config. & Call to HAL_ADC_Init.
	gsAdcHandle.Instance = ADC1;
	gsAdcHandle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV1;
	gsAdcHandle.Init.Resolution = ADC_RESOLUTION_12B;
	gsAdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	gsAdcHandle.Init.ScanConvMode = ADC_SCAN_DISABLE;
	gsAdcHandle.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	gsAdcHandle.Init.LowPowerAutoWait = DISABLE;
	gsAdcHandle.Init.ContinuousConvMode = DISABLE;
	gsAdcHandle.Init.DiscontinuousConvMode = DISABLE;
	gsAdcHandle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONVEDGE_NONE;
	gsAdcHandle.Init.DMAContinuousRequests = DISABLE;
	gsAdcHandle.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
	HAL_ADC_Init(&gsAdcHandle);

	// ADC Channel Config. & Call to HAL_ADC_ConfigChannel.
	ADC_ChannelConfTypeDef adcchconfig;
	adcchconfig.Channel = ADC_CHANNEL_12;
	adcchconfig.Rank = ADC_REGULAR_RANK_1;
	adcchconfig.SamplingTime = ADC_SAMPLETIME_19CYCLES_5;
	adcchconfig.SingleDiff = ADC_SINGLE_ENDED;
	adcchconfig.OffsetNumber = ADC_OFFSET_NONE;
	adcchconfig.Offset = 0;
	HAL_ADC_ConfigChannel(&gsAdcHandle, &adcchconfig);


	HAL_ADCEx_Calibration_Start(&gsAdcHandle, ADC_SINGLE_ENDED);
	// Additional calls to Cahnnel Config if multiple.

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
