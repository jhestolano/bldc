#ifndef TMR_H
#define TMR_H

#include <stdint.h>

typedef uint8_t TmrCh_T;

/*******************************************************************************
** Timer channel definitions.
*******************************************************************************/
#define TMR_CH_INC_TICK ((TmrCh_T)0)
#define TMR_CH_INC_TICK_INSTANCE (TIM6)
#define TMR_CH_INC_TICK_IRQn (TIM6_DAC_IRQn)
#define TMR_ENC_LOCK() HAL_NVIC_DisableIRQ(TMR_CH_INC_TICK_IRQn)
#define TMR_ENC_UNLOCK() HAL_NVIC_EnableIRQ(TMR_CH_INC_TICK_IRQn)
#define TMR_CH_MAX      ((TmrCh_T)1)
/*******************************************************************************
** Timer channel interrupt configuration.
*******************************************************************************/
#define TMR_IT_CONF {                                                          \
  {                                                                            \
    .Tmr = TMR_CH_INC_TICK,                                                    \
    .IRQn = TMR_CH_INC_TICK_IRQn,                                              \
    .Prio = 8,                                                                 \
    .SubPrio = 0,                                                              \
  },                                                                           \
}
/*******************************************************************************
** Tmer used to increase HAL_SysTick. Interrupt @ 1ms.
*******************************************************************************/
#define TMR_INC_TICK {                                                         \
  .Instance = TIM6,                                                            \
  .Init = {                                                                    \
    .Prescaler = 1,                                                            \
    .CounterMode = TIM_COUNTERMODE_UP,                                         \
    .Period = 35999,                                                           \
    .RepetitionCounter = 0,                                                    \
    .ClockDivision = TIM_CLOCKDIVISION_DIV2,                                   \
    .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,                       \
  },                                                                           \
}
/*******************************************************************************
*******************************************************************************/

void TMR_Init(void);

void TMR_Start(TmrCh_T tmrch);

void TMR_Stop(TmrCh_T tmrch);

void TMR_Reset(TmrCh_T tmrch);

uint32_t TMR_GetCnt(TmrCh_T tmrch);

#endif
