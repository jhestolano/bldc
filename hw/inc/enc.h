#ifndef _ENC_H_
#define _ENC_H_

#include <stdint.h>

#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_tim.h"
#include "stm32f3xx_hal_tim_ex.h"
#include "stm32f3xx_hal_rcc_ex.h"
#include "stm32f3xx_hal_rcc.h"
#include "stm32f3xx_ll_tim.h"

#define ENC_DIR_UNKNOWN (0)
#define ENC_DIR_FWD (1)
#define ENC_DIR_REV (-1)

/* Number of counts over which (positive or negative)
   the TIM counter is reset so that overflow does not occur.
   The current count is stored under the encoder handle
   structure. */
#define ENC_COUNTS_THRESHOLD (30000)

#define ENC_CH_A (TIM_CHANNEL_1)
#define ENC_CH_B (TIM_CHANNEL_2)
#define ENC_CH_ALL (TIM_CHANNEL_ALL)

#define ENC_CH_A_PIN (GPIO_PIN_15)
#define ENC_CH_A_PORT (GPIOA)

#define ENC_CH_B_PIN (GPIO_PIN_3)
#define ENC_CH_B_PORT (GPIOB)

#define ENC_CH_IDX_PIN (GPIO_PIN_10)
#define ENC_CH_IDX_PORT (GPIOB)
#define ENC_CH_IDX_IT_IRQn (EXTI15_10_IRQn)
#define ENC_CH_IDX_IT_PRIO (3)
#define ENC_CH_IDX_IT_SUBPRIO (1)

#define ENC_CH_A_GPIO_CONF {                                                   \
  .Pin = ENC_CH_A_PIN,                                                         \
  .Mode = GPIO_MODE_AF_PP,                                                     \
  .Pull = GPIO_NOPULL,                                                         \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
  .Alternate = GPIO_AF1_TIM2,                                                  \
}   

#define ENC_CH_B_GPIO_CONF {                                                   \
  .Pin = ENC_CH_B_PIN,                                                         \
  .Mode = GPIO_MODE_AF_PP,                                                     \
  .Pull = GPIO_NOPULL,                                                         \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
  .Alternate = GPIO_AF1_TIM2,                                                  \
}   

#define ENC_CH_IDX_GPIO_CONF {                                                 \
  .Pin = ENC_CH_IDX_PIN,                                                       \
  .Mode = GPIO_MODE_IT_RISING,                                                 \
  .Pull = GPIO_PULLUP,                                                         \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
}   

#define TIM_ENC_INIT_CONF {                                                    \
  .Instance = TIM2,                                                            \
  .Init = {                                                                    \
    .Prescaler = 0,                                                            \
    .CounterMode = TIM_COUNTERMODE_UP,                                         \
    .Period = UINT16_MAX,                                                      \
    .RepetitionCounter = 0,                                                    \
    .ClockDivision = TIM_CLOCKDIVISION_DIV1,                                   \
    .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,                       \
  },                                                                           \
}

#define ENC_INIT_CONF {                                                        \
  .EncoderMode = TIM_ENCODERMODE_TI12,                                         \
  .IC1Polarity = TIM_ICPOLARITY_RISING,                                        \
  .IC1Selection = TIM_ICSELECTION_DIRECTTI,                                    \
  .IC1Prescaler = TIM_ICPSC_DIV1,                                              \
  .IC1Filter = 0,                                                              \
  .IC2Polarity = TIM_ICPOLARITY_RISING,                                        \
  .IC2Selection = TIM_ICSELECTION_DIRECTTI,                                    \
  .IC2Prescaler = TIM_ICPSC_DIV1,                                              \
  .IC2Filter = 0,                                                              \
};

void ENC_Init(void);

void ENC_Start(void);

int32_t ENC_GetCnt(void);

void ENC_DeInit(void);

void ENC_TmrCallback(void);

#endif // _ENC_H_
