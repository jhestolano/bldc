#ifndef ADC_H
#define ADC_H

#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_adc.h"
#include "stm32f3xx_hal_adc_ex.h"

extern ADC_HandleTypeDef gs_adc_handle;

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

/*******************************************************************************
 * GPIO INPUT CONFIGURATION: POTENTIOMETER.
*******************************************************************************/
#define GPIOB_ADC_INPUT_CONF {                                                 \
  .Pin = POT_ADC_PIN,                                                          \
  .Mode = GPIO_MODE_ANALOG,                                                    \
  .Pull = GPIO_NOPULL,                                                         \
}

/*******************************************************************************
 * GPIO INPUT CONFIGURATION: PHASE-B, PHASE-C, TEMP. SENSOR.
*******************************************************************************/
#define GPIOC_ADC_INPUT_CONF {                                                 \
  .Pin = PHB_IFBK_ADC_PIN | PHC_IFBK_ADC_PIN | TEMP_SENS_ADC_PIN,              \
  .Mode = GPIO_MODE_ANALOG,                                                    \
  .Pull = GPIO_NOPULL,                                                         \
}

/*******************************************************************************
 * GPIO INPUT CONFIGURATION: PHASE-A, VBUS.
*******************************************************************************/
#define GPIOA_ADC_INPUT_CONF {                                                 \
  .Pin = PHA_IFBK_ADC_PIN | VBUS_ADC_PIN,                                      \
  .Mode = GPIO_MODE_ANALOG,                                                    \
  .Pull = GPIO_NOPULL,                                                         \
}

/*******************************************************************************
* ADC INITIAL CONFIGURATION.
********************************************************************************
* Type: ADC_HandleTypeDef
*******************************************************************************/
#define ADC_INIT_CONF {                                                        \
  .Instance = ADC1,                                                            \
  .Init = {                                                                    \
    .ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV1,                                \
    .Resolution = ADC_RESOLUTION_12B,                                          \
    .ScanConvMode = ADC_SCAN_ENABLE,                                           \
    .ContinuousConvMode = DISABLE,                                             \
    .DiscontinuousConvMode = DISABLE,                                          \
    .ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING,                   \
    .ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_TRGO2,                         \
    .DataAlign = ADC_DATAALIGN_RIGHT,                                          \
    .NbrOfConversion = 1,                                                      \
    .DMAContinuousRequests = DISABLE,                                          \
    .EOCSelection = ADC_EOC_SINGLE_CONV,                                       \
    .LowPowerAutoWait = DISABLE,                                               \
    .Overrun = ADC_OVR_DATA_PRESERVED,                                         \
  },                                                                           \
}

/*******************************************************************************
* ADC INJECTED CHANNEL GROUP CONFIGURATION.
*******************************************************************************/
#define ADC_INJ_GROUP_CONF                                                     \
  .InjectedNbrOfConversion = 3,                                                \
  .ExternalTrigInjecConvEdge = ADC_EXTERNALTRIGINJECCONV_EDGE_RISING,          \
  .ExternalTrigInjecConv = ADC_EXTERNALTRIGINJECCONV_T1_TRGO2,                 \
  .AutoInjectedConv = DISABLE,                                                 \
  .InjectedDiscontinuousConvMode = DISABLE,                                    \
  .QueueInjectedContext = DISABLE

/*******************************************************************************
 * ADC REGULAR CHANNEL CONFIG: POTENTIOMETER.
********************************************************************************
* Type: ADC_ChannelConfTypeDef
*******************************************************************************/
#define POT_ADC_CONF {                                                         \
  .Channel = POT_ADC_CHANNEL,                                                  \
  .Rank = ADC_INJECTED_RANK_1,                                                 \
  .SingleDiff = ADC_SINGLE_ENDED,                                              \
  .Offset = 0,                                                                 \
  .OffsetNumber = ADC_OFFSET_NONE,                                             \
  .SamplingTime = ADC_SAMPLETIME_19CYCLES_5,                                   \
}

/*******************************************************************************
 * ADC INJECTED CHANNEL CONFIG: POTENTIOMETER.
********************************************************************************
* Type: ADC_InjectionConfTypeDef
*******************************************************************************/
#define POT_ADC_INJ_CONF {                                                     \
  .InjectedChannel = POT_ADC_CHANNEL,                                          \
  .InjectedRank = ADC_INJECTED_RANK_1,                                         \
  .InjectedSingleDiff = ADC_SINGLE_ENDED,                                      \
  .InjectedOffset = 0,                                                         \
  .InjectedOffsetNumber = ADC_OFFSET_NONE,                                     \
  .InjectedSamplingTime = ADC_SAMPLETIME_19CYCLES_5,                           \
  ADC_INJ_GROUP_CONF,                                                          \
}

/*******************************************************************************
 * ADC INJECTED CHANNEL CONFIG: TEMP. SENSOR.
********************************************************************************
* Type: ADC_InjectionConfTypeDef
*******************************************************************************/
#define TEMP_SENS_ADC_INJ_CONF {                                               \
  .InjectedChannel = TEMP_SENS_ADC_CHANNEL,                                    \
  .InjectedRank = ADC_INJECTED_RANK_2,                                         \
  .InjectedSingleDiff = ADC_SINGLE_ENDED,                                      \
  .InjectedSamplingTime = ADC_SAMPLETIME_19CYCLES_5,                           \
  .InjectedOffset = 0,                                                         \
  .InjectedOffsetNumber = ADC_OFFSET_NONE,                                     \
  ADC_INJ_GROUP_CONF,                                                          \
}

/*******************************************************************************
 * ADC INJECTED CHANNEL CONFIG: VOLTAGE BUS.
********************************************************************************
* Type: ADC_InjectionConfTypeDef
*******************************************************************************/
#define VBUS_ADC_INJ_CONF {                                                    \
  .InjectedChannel = VBUS_ADC_CHANNEL,                                         \
  .InjectedRank = ADC_INJECTED_RANK_3,                                         \
  .InjectedSingleDiff = ADC_SINGLE_ENDED,                                      \
  .InjectedSamplingTime = ADC_SAMPLETIME_19CYCLES_5,                           \
  .InjectedOffset = 0,                                                         \
  .InjectedOffsetNumber = ADC_OFFSET_NONE,                                     \
  ADC_INJ_GROUP_CONF,                                                          \
}

/*******************************************************************************
*******************************************************************************/

void HAL_ADC_MspInit(ADC_HandleTypeDef* adc_handle);

void ADC_Init(void);

void ADC_Start(void);

void ADC_InjectedStart(void);

void ADC_WaitConv(void);

uint32_t ADC_Read(void);

#endif
