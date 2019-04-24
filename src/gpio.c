#include "gpio.h"

void GPIO_Init(void) {

  GPIO_InitTypeDef gpio_init = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

  HAL_GPIO_WritePin(USR_LED_PORT, USR_LED_PIN, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOC, UH_PWM_ENABLE_PIN | VH_PWM_ENABLE_PIN | WH_PWM_ENABLE_PIN, GPIO_PIN_RESET);

  gpio_init.Pin = USR_BUTTON_PIN;
  gpio_init.Mode = GPIO_MODE_IT_FALLING;
  gpio_init.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USR_BUTTON_PORT, &gpio_init);

  gpio_init.Pin = USR_LED_PIN;
  gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
  gpio_init.Pull = GPIO_NOPULL;
  gpio_init.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USR_LED_PORT, &gpio_init);

  gpio_init.Pin = UH_PWM_ENABLE_PIN | VH_PWM_ENABLE_PIN | WH_PWM_ENABLE_PIN;
  gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
  gpio_init.Pull = GPIO_PULLDOWN;
  gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &gpio_init);

  return;
}

