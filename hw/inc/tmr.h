#ifndef TMR_H
#define TMR_H

#include <stdint.h>

#define TMR_INIT_CONF {                                                         \
  .Instance = TIM2,                                                             \
  .Init = {                                                                     \
    .Prescaler = 0,                                                             \
    .CounterMode = TIM_COUNTERMODE_UP,                                          \
    .Period = 0xFFFF,                                                           \
    .RepetitionCounter = 0,                                                     \
    .ClockDivision = TIM_CLOCKDIVISION_DIV2,                                    \
    .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,                        \
  },                                                                            \
}

void TMR_Init(void);

void TMR_Start(void);

void TMR_Stop(void);

void TMR_Reset(void);

uint32_t TMR_GetCount(void);

#endif
