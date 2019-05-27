#ifndef PWM_H
#define PWM_H

#include "stm32f3xx_hal_gpio.h"

/*******************************************************************************
* PWM MACRO DEFINITIONS.
*******************************************************************************/
#define UH_PWM_PORT (GPIOA)
#define VH_PWM_PORT (GPIOA)
#define WH_PWM_PORT (GPIOA)

#define UH_PWM_PIN (GPIO_PIN_8)
#define VH_PWM_PIN (GPIO_PIN_9)
#define WH_PWM_PIN (GPIO_PIN_10)

#define UH_PWM_CHANNEL (TIM_CHANNEL_1)
#define VH_PWM_CHANNEL (TIM_CHANNEL_2)
#define WH_PWM_CHANNEL (TIM_CHANNEL_3)

/*******************************************************************************
* PWM GPIO INITIAL CONFIGURATION.
*******************************************************************************/
#define PWM_GPIO_CONF {                                                        \
  .Pin = UH_PWM_PIN | VH_PWM_PIN | WH_PWM_PIN,                                 \
  .Mode = GPIO_MODE_AF_PP,                                                     \
  .Pull = GPIO_PULLDOWN,                                                       \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
  .Alternate = GPIO_AF6_TIM1,                                                  \
}   

/*******************************************************************************
* PWM INITIAL CONFIGURATION.
*******************************************************************************/
#define PWM_INIT_CONF {                                                        \
  .Instance = TIM1,                                                            \
  .Init = {                                                                    \
    .Prescaler = 1,                                                            \
    .CounterMode = TIM_COUNTERMODE_UP,                                         \
    .Period = PWM_TMR_PERIOD,                                                  \
    .RepetitionCounter = 0,                                                    \
    .ClockDivision = TIM_CLOCKDIVISION_DIV2,                                   \
    .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,                       \
  },                                                                           \
}

/*******************************************************************************
* PWM DEADTIME CONFIGURATION.
*******************************************************************************/
#define PWM_DEADTIME_CONF {                                                    \
  .OffStateRunMode = TIM_OSSR_ENABLE,                                          \
  .OffStateIDLEMode = TIM_OSSI_ENABLE,                                         \
  .LockLevel = TIM_LOCKLEVEL_1,                                                \
  .DeadTime = 0,                                                               \
  .BreakState = TIM_BREAK_DISABLE,                                             \
  .BreakPolarity = TIM_BREAKPOLARITY_HIGH,                                     \
  .BreakFilter = 0,                                                            \
  .Break2State = TIM_BREAK2_ENABLE,                                            \
  .Break2Polarity = TIM_BREAK2POLARITY_LOW,                                    \
  .Break2Filter = 7,                                                           \
  .AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE,                              \
}

/*******************************************************************************
* PWM OUTPUT-COMPARE CONFIGURATION.
*******************************************************************************/
#define PWM_OC_CONF {                                                          \
  .OCMode = TIM_OCMODE_PWM1,                                                   \
  .Pulse = PWM_TMR_PERIOD * .90,                                               \
  .OCPolarity = TIM_OCPOLARITY_HIGH,                                           \
  .OCNPolarity = TIM_OCNPOLARITY_HIGH,                                         \
  .OCFastMode = TIM_OCFAST_DISABLE,                                            \
  .OCIdleState = TIM_OCIDLESTATE_RESET,                                        \
  .OCNIdleState = TIM_OCNIDLESTATE_RESET,                                      \
}

/*******************************************************************************
* PWM MASTER OUTPUT CONFIGURATION.
*******************************************************************************/
#define PWM_MASTER_OUT_CONF {                                                  \
  .MasterOutputTrigger = TIM_TRGO_RESET,                                       \
  .MasterOutputTrigger2 = TIM_TRGO_RESET,                                      \
  .MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE,                              \
}
/*******************************************************************************
*******************************************************************************/

void PWM_Init(void);

#endif
