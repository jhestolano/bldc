#ifndef GPIO_H
#define GPIO_H

#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_rcc.h"

#define UH_PWM_ENABLE_PIN (GPIO_PIN_10)
#define VH_PWM_ENABLE_PIN (GPIO_PIN_11)
#define WH_PWM_ENABLE_PIN (GPIO_PIN_12)

#define UH_PWM_ENABLE_PORT (GPIOC)
#define VH_PWM_ENABLE_PORT (GPIOC)
#define WH_PWM_ENABLE_PORT (GPIOC)

#define BKIN_PIN (GPIO_PIN_6)
#define BKIN_PORT (GPIO_PIN_A)

#define USR_LED_PIN (GPIO_PIN_5)
#define USR_LED_PORT (GPIOA)

#define USR_BUTTON_PIN (GPIO_PIN_13)
#define USR_BUTTON_PORT (GPIOC)

void GPIO_Init(void);

#endif