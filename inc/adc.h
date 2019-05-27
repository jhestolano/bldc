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
#define GPIOB_INPUT_CONF {                                                     \
  .Pin = POT_ADC_PIN,                                                          \
  .Mode = GPIO_MODE_ANALOG,                                                    \
  .Pull = GPIO_NOPULL,                                                         \
}

/*******************************************************************************
 * GPIO INPUT CONFIGURATION: PHASE-B, PHASE-C, TEMP. SENSOR.
*******************************************************************************/
#define GPIOC_INPUT_CONF {                                                     \
  .Pin = PHB_IFBK_ADC_PIN | PHC_IFBK_ADC_PIN | TEMP_SENS_ADC_PIN,              \
  .Mode = GPIO_MODE_ANALOG,                                                    \
  .Pull = GPIO_NOPULL,                                                         \
}

/*******************************************************************************
 * GPIO INPUT CONFIGURATION: PHASE-A, VBUS.
*******************************************************************************/
#define GPIOA_INPUT_CONF {                                                     \
  .Pin = PHA_IFBK_ADC_PIN | VBUS_ADC_PIN,                                      \
  .Mode = GPIO_MODE_ANALOG,                                                    \
  .Pull = GPIO_NOPULL,                                                         \
}

/*******************************************************************************
 * ADC INITIAL CONFIGURATION.
*******************************************************************************/
#define ADC_INIT_CONF {                                                        \
  .Instance = ADC1,                                                            \
  .Init = {                                                                    \
    .ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV1,                                \
    .Resolution = ADC_RESOLUTION_12B,                                          \
    .ScanConvMode = ADC_SCAN_ENABLE,                                           \
    .ContinuousConvMode = DISABLE,                                             \
    .DiscontinuousConvMode = DISABLE,                                          \
    .ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE,                     \
    .ExternalTrigConv = ADC_SOFTWARE_START,                                    \
    .DataAlign = ADC_DATAALIGN_RIGHT,                                          \
    .NbrOfConversion = 3,                                                      \
    .DMAContinuousRequests = DISABLE,                                          \
    .EOCSelection = ADC_EOC_SINGLE_CONV,                                       \
    .LowPowerAutoWait = DISABLE,                                               \
    .Overrun = ADC_OVR_DATA_PRESERVED,                                         \
  },                                                                           \
}

/*******************************************************************************
 * ADC INJECTED CHANNEL CONFIG: POTENTIOMETER.
*******************************************************************************/
#define POT_ADC_INJ_CONF {                                                     \
  .InjectedChannel = POT_ADC_CHANNEL,                                          \
  .InjectedRank = ADC_INJECTED_RANK_1,                                         \
  .InjectedSingleDiff = ADC_SINGLE_ENDED,                                      \
  .InjectedNbrOfConversion = 3,                                                \
  .InjectedSamplingTime = ADC_SAMPLETIME_19CYCLES_5,                           \
  .ExternalTrigInjecConvEdge = ADC_EXTERNALTRIGINJECCONV_EDGE_NONE,            \
  .ExternalTrigInjecConv = ADC_INJECTED_SOFTWARE_START,                        \
  .AutoInjectedConv = DISABLE,                                                 \
  .InjectedDiscontinuousConvMode = DISABLE,                                    \
  .QueueInjectedContext = DISABLE,                                             \
  .InjectedOffset = 0,                                                         \
  .InjectedOffsetNumber = ADC_OFFSET_NONE,                                     \
}

/*******************************************************************************
 * ADC INJECTED CHANNEL CONFIG: TEMP. SENSOR.
*******************************************************************************/
#define TEMP_SENS_ADC_INJ_CONF {                                               \
  .InjectedChannel = TEMP_SENS_ADC_CHANNEL,                                    \
  .InjectedRank = ADC_INJECTED_RANK_2,                                         \
  .InjectedSingleDiff = ADC_SINGLE_ENDED,                                      \
  .InjectedNbrOfConversion = 3,                                                \
  .InjectedSamplingTime = ADC_SAMPLETIME_19CYCLES_5,                           \
  .ExternalTrigInjecConvEdge = ADC_EXTERNALTRIGINJECCONV_EDGE_NONE,            \
  .ExternalTrigInjecConv = ADC_INJECTED_SOFTWARE_START,                        \
  .AutoInjectedConv = DISABLE,                                                 \
  .InjectedDiscontinuousConvMode = DISABLE,                                    \
  .QueueInjectedContext = DISABLE,                                             \
  .InjectedOffset = 0,                                                         \
  .InjectedOffsetNumber = ADC_OFFSET_NONE,                                     \
}

/*******************************************************************************
 * ADC INJECTED CHANNEL CONFIG: VOLTAGE BUS.
*******************************************************************************/
#define VBUS_ADC_INJ_CONF {                                                    \
  .InjectedChannel = VBUS_ADC_CHANNEL,                                         \
  .InjectedRank = ADC_INJECTED_RANK_3,                                         \
  .InjectedSingleDiff = ADC_SINGLE_ENDED,                                      \
  .InjectedNbrOfConversion = 3,                                                \
  .InjectedSamplingTime = ADC_SAMPLETIME_19CYCLES_5,                           \
  .ExternalTrigInjecConvEdge = ADC_EXTERNALTRIGINJECCONV_EDGE_NONE,            \
  .ExternalTrigInjecConv = ADC_INJECTED_SOFTWARE_START,                        \
  .AutoInjectedConv = DISABLE,                                                 \
  .InjectedDiscontinuousConvMode = DISABLE,                                    \
  .QueueInjectedContext = DISABLE,                                             \
  .InjectedOffset = 0,                                                         \
  .InjectedOffsetNumber = ADC_OFFSET_NONE,                                     \
}

/*******************************************************************************
*******************************************************************************/

void HAL_ADC_MspInit(ADC_HandleTypeDef* adc_handle);

void ADC_Init(void);

void ADC_Start(void);

void ADC_WaitConv(void);

uint32_t ADC_Read(void);

#endif
