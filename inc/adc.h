#ifndef ADC_H
#define ADC_H

#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_adc.h"

void HAL_ADC_MspInit(ADC_HandleTypeDef* adC_handle);

void ADC_Init(void);

#endif