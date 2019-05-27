#include "gpio.h"

void GPIO_Init(void) {

  GPIO_InitTypeDef s_gpioc_input_conf = GPIOC_INPUT_CONF;
  GPIO_InitTypeDef s_gpioa_output_conf = GPIOA_OUTPUT_CONF;

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

  HAL_GPIO_Init(USR_BUTTON_PORT, &s_gpioc_input_conf);
  HAL_GPIO_Init(USR_LED_PORT, &s_gpioa_output_conf);

  HAL_GPIO_WritePin(USR_LED_PORT, USR_LED_PIN, GPIO_PIN_RESET);

  return;
}

