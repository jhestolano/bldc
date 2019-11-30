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
  .IC1Polarity = TIM_ICPOLARITY_BOTHEDGE,                                      \
  .IC1Selection = TIM_ICSELECTION_DIRECTTI,                                    \
  .IC1Prescaler = TIM_ICPSC_DIV1,                                              \
  .IC1Filter = 0x00,                                                           \
  .IC2Polarity = TIM_ICPOLARITY_BOTHEDGE,                                      \
  .IC2Selection = TIM_ICSELECTION_DIRECTTI,                                    \
  .IC2Prescaler = TIM_ICPSC_DIV1,                                              \
  .IC2Filter = 0x00,                                                           \
};

void ENC_Init(void);

void ENC_Start(void);

uint16_t ENC_GetCnt(void);

void ENC_DeInit(void);

#endif // _ENC_H_
