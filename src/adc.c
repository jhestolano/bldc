#include "adc.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_rcc.h"

void HAL_ADC_MspInit(ADC_HandleTypeDef* adc_handle) {
	GPIO_InitTypeDef gpio_init;
	
	// GPIO & ADC Clock Enable.
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_ADC1_CLK_ENABLE();

	// GPIO Init.
	gpio_init.Pin = GPIO_PIN_4;
	gpio_init.Mode = GPIO_MODE_ANALOG;
	gpio_init.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &gpio_init);

	// Configure DMA if needed.
	// NVIC Priority / Enable.
	return;
}

void ADC_Init(void) {

	// ADC_HandleTypeDef config. & Call to HAL_ADC_Init.
	ADC_HandleTypeDef adcinit;
	adcinit.Instance = ADC1;
	adcinit.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV1;
	adcinit.Init.Resolution = ADC_RESOLUTION_12B;
	adcinit.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	adcinit.Init.ScanConvMode = ADC_SCAN_DISABLE;
	adcinit.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	adcinit.Init.LowPowerAutoWait = DISABLE;
	adcinit.Init.ContinuousConvMode = DISABLE;
	adcinit.Init.DiscontinuousConvMode = DISABLE;
	adcinit.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONVEDGE_NONE;
	adcinit.Init.DMAContinuousRequests = DISABLE;
	adcinit.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
	HAL_ADC_Init(&adcinit);

	// ADC Channel Config. & Call to HAL_ADC_ConfigChannel.
	ADC_ChannelConfTypeDef adcchconfig;
	adcchconfig.Channel = ADC_CHANNEL_12;
	adcchconfig.Rank = ADC_REGULAR_RANK_1;
	adcchconfig.SamplingTime = ADC_SAMPLETIME_19CYCLES_5;
	adcchconfig.SingleDiff = ADC_SINGLE_ENDED;
	adcchconfig.OffsetNumber = ADC_OFFSET_NONE;
	adcchconfig.Offset = 0;
	HAL_ADC_ConfigChannel(&adcinit, &adcchconfig);


	HAL_ADCEx_Calibration_Start(&adcinit, ADC_SINGLE_ENDED);
	// Additional calls to Cahnnel Config if multiple.

	return;
}

