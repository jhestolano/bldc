#ifndef TMR_H
#define TMR_H

#include <stdint.h>

typedef uint8_t TmrCh_T;

/*******************************************************************************
** Timer channel definitions.
*******************************************************************************/
#define TMR_CH_GENERAL  ((TmrCh_T)0)
#define TMR_CH_GENERAL_INSTANCE (TIM2)

#define TMR_CH_INC_TICK ((TmrCh_T)1)
#define TMR_CH_INC_TICK_INSTANCE (TIM6)

#define TMR_CH_MAX      ((TmrCh_T)2)

#define TMR_IT_CONF {                                                         \
  {                                                                           \
    .tmr = TMR_CH_GENERAL,                                                    \
    .irqn = TIM2_IRQn,                                                        \
    .prio = 8,                                                                \
    .subprio = 1,                                                             \
  },                                                                          \
  {                                                                           \
    .tmr = TMR_CH_INC_TICK,                                                   \
    .irqn = TIM6_DAC_IRQn,                                                    \
    .prio = 8,                                                                \
    .subprio = 0,                                                             \
  },                                                                          \
}

/*******************************************************************************
** General purpose timer used to measure execution time.
*******************************************************************************/
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

/*******************************************************************************
** Tmer used to increase HAL_SysTick. Interrupt @ 1ms.
*******************************************************************************/
#define TMR_INC_TICK {                                                          \
  .Instance = TIM6,                                                             \
  .Init = {                                                                     \
    .Prescaler = 1,                                                             \
    .CounterMode = TIM_COUNTERMODE_UP,                                          \
    .Period = 35999,                                                            \
    .RepetitionCounter = 0,                                                     \
    .ClockDivision = TIM_CLOCKDIVISION_DIV2,                                    \
    .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,                        \
  },                                                                            \
}

void TMR_Init(void);

void TMR_Start(TmrCh_T tmrch);

void TMR_Stop(TmrCh_T tmrch);

void TMR_Reset(TmrCh_T tmrch);

uint32_t TMR_GetCount(TmrCh_T tmrch);

#endif
