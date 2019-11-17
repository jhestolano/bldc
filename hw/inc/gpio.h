#ifndef GPIO_H
#define GPIO_H

#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_rcc.h"

/*******************************************************************************
 * GPIO MACRO DEFINITIONS.
*******************************************************************************/
#define UH_PWM_ENABLE_PIN (GPIO_PIN_10)
#define VH_PWM_ENABLE_PIN (GPIO_PIN_11)
#define WH_PWM_ENABLE_PIN (GPIO_PIN_12)

#define UH_PWM_ENABLE_PORT (GPIOC)
#define VH_PWM_ENABLE_PORT (GPIOC)
#define WH_PWM_ENABLE_PORT (GPIOC)
#define XH_PWM_ENABLE_PORT (GPIOC)

#define BKIN_PIN (GPIO_PIN_6)
#define BKIN_PORT (GPIO_PIN_A)

#define BKIN2_PIN (GPIO_PIN_11)
#define BKIN2_PORT (GPIOA)

#define USR_LED_PIN (GPIO_PIN_5)
#define USR_LED_PORT (GPIOA)

#define USR_BUTTON_PIN (GPIO_PIN_13)
#define USR_BUTTON_PORT (GPIOC)

#define DIAG_PIN (GPIO_PIN_6)
#define DIAG_PORT (GPIOA)
#define DIAG_IT_PRIO (3)
#define DIAG_IT_SUBPRIO (0)
#define DIAG_IT_EXTI_IRQn (EXTI9_5_IRQn)

/*******************************************************************************
 * GPIO USER BUTTON CONFIGURATION.
*******************************************************************************/
#define GPIOC_INPUT_CONF {                                                     \
  .Pin = USR_BUTTON_PIN,                                                       \
  .Mode = GPIO_MODE_IT_FALLING,                                                \
  .Pull = GPIO_NOPULL,                                                         \
}                     
/*******************************************************************************
 * GPIO USER BUTTON CONFIGURATION.
*******************************************************************************/
#define GPIOA_OUTPUT_CONF {                                                    \
  .Pin = USR_LED_PIN,                                                          \
  .Mode = GPIO_MODE_OUTPUT_PP,                                                 \
  .Pull = GPIO_NOPULL,                                                         \
  .Speed = GPIO_SPEED_FREQ_LOW,                                                \
}
/*******************************************************************************
 * GPIO PWM ENABLE CONFIGURATION.
*******************************************************************************/
#define GPIOA_PWM_ENABLE_CONF {                                                \
  .Pin = UH_PWM_ENABLE_PIN | VH_PWM_ENABLE_PIN | WH_PWM_ENABLE_PIN,            \
  .Mode = GPIO_MODE_OUTPUT_PP,                                                 \
  .Pull = GPIO_PULLDOWN,                                                       \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
}
/*******************************************************************************
 * GPIO BKIN2 CONFIGURATION.
*******************************************************************************/
#define GPIOA_BKIN2_CONF {                                                     \
  .Pin = BKIN2_PIN,                                                            \
  .Mode = GPIO_MODE_OUTPUT_PP,                                                 \
  .Pull = GPIO_PULLDOWN,                                                       \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
}
/*******************************************************************************
 * GPIO DIAG CONFIGURATION.
*******************************************************************************/
#define GPIOA_DIAG_CONF {                                                      \
  .Pin = DIAG_PIN,                                                             \
  .Mode = GPIO_MODE_IT_FALLING,                                                \
  .Pull = GPIO_NOPULL,                                                         \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
}

/*******************************************************************************
*******************************************************************************/

void GPIO_Init(void);

void GPIO_LedToggle(void);

#endif
