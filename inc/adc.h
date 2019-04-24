#ifndef ADC_H
#define ADC_H

#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_adc.h"
#include "stm32f3xx_hal_adc_ex.h"

/******************************************************************************
 * GPIOA ADC CONFIGURATION.
******************************************************************************/
#define PHA_IFBK_ADC_CHANNEL (ADC_CHANNEL_1)
#define PHA_IFBK_ADC_PIN (GPIO_PIN_0)
#define PHA_IFBK_ADC_PORT (GPIOA)

#define VBUS_ADC_CHANNEL (ADC_CHANNEL_2)
#define VBUS_ADC_PIN (GPIO_PIN_1)
#define VBUS_ADC_PORT (GPIOA)

/******************************************************************************
 * GPIOB ADC CONFIGURATION.
******************************************************************************/
#define POT_ADC_CHANNEL (ADC_CHANNEL_12)
#define POT_ADC_PORT (GPIOB)
#define POT_ADC_PIN (GPIO_PIN_1)

/******************************************************************************
 * GPIOC ADC CONFIGURATION.
******************************************************************************/
#define PHB_IFBK_ADC_CHANNEL (ADC_CHANNEL_7)
#define PHB_IFBK_ADC_PIN (GPIO_PIN_1)
#define PHB_IFBK_ADC_PORT (GPIOC)

#define PHC_IFBK_ADC_CHANNEL (ADC_CHANNEL_6)
#define PHC_IFBK_ADC_PIN (GPIO_PIN_0)
#define PHC_IFBK_ADC_PORT (GPIOC)

#define TEMP_SENS_ADC_CHANNEL (ADC_CHANNEL_8)
#define TEMP_SENS_ADC_PIN (GPIO_PIN_2)
#define TEMP_SENS_ADC_PORT (GPIOC)

/*****************************************************************************/
/*****************************************************************************/

ADC_HandleTypeDef gsAdcHandle;

void HAL_ADC_MspInit(ADC_HandleTypeDef* adc_handle);

void ADC_Init(void);

void ADC_Start(void);

void ADC_WaitConv(void);

uint32_t ADC_Read(void);

#endif