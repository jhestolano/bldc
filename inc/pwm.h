#ifndef PWM_H
#define PWM_H

#include "stm32f3xx_hal_gpio.h"

#define UH_PWM_PORT (GPIOA)
#define VH_PWM_PORT (GPIOA)
#define WH_PWM_PORT (GPIOA)

#define UH_PWM_PIN (GPIO_PIN_8)
#define VH_PWM_PIN (GPIO_PIN_9)
#define WH_PWM_PIN (GPIO_PIN_10)

void PWM_Init(void);

#endif