#include "gpio.h"

void GPIO_Init(void) {

  GPIO_InitTypeDef s_gpioc_input_conf = GPIOC_INPUT_CONF;
  GPIO_InitTypeDef s_gpioa_output_conf = GPIOA_OUTPUT_CONF;
  GPIO_InitTypeDef s_gpioa_pwm_enable_conf = GPIOA_PWM_ENABLE_CONF;
  GPIO_InitTypeDef s_gpioa_bkin2_conf = GPIOA_BKIN2_CONF;

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

  HAL_GPIO_Init(USR_BUTTON_PORT, &s_gpioc_input_conf);
  HAL_GPIO_Init(USR_LED_PORT, &s_gpioa_output_conf);
  HAL_GPIO_Init(XH_PWM_ENABLE_PORT, &s_gpioa_pwm_enable_conf);
  HAL_GPIO_Init(BKIN2_PORT, &s_gpioa_bkin2_conf);

  HAL_GPIO_WritePin(USR_LED_PORT, USR_LED_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(BKIN2_PORT, BKIN2_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(XH_PWM_ENABLE_PORT, UH_PWM_ENABLE_PIN | VH_PWM_ENABLE_PIN | WH_PWM_ENABLE_PIN, GPIO_PIN_SET);

  return;
}

void GPIO_LedToggle(void) {
  HAL_GPIO_TogglePin(USR_LED_PORT, USR_LED_PIN);
  return;
}
