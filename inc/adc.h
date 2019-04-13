#ifndef ADC_H
#define ADC_H

#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_adc.h"
#include "stm32f3xx_hal_adc_ex.h"

ADC_HandleTypeDef gsAdcHandle;

void HAL_ADC_MspInit(ADC_HandleTypeDef* adC_handle);

void ADC_Init(void);

void ADC_Start(void);

void ADC_WaitConv(void);

uint32_t ADC_Read(void);

#endif