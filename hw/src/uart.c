#include "uart.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_uart.h"
#include "stm32f3xx_hal_uart_ex.h"
#include "stm32f3xx_hal_rcc_ex.h"
#include "stm32f3xx_hal_rcc.h"
#include <string.h>

/* UART xmit delay in milliseconds. */
#define UART_TX_DELAY (1)

UART_HandleTypeDef gs_uart_init_conf = UART_INIT_CONF;

void UART_ErrorHandler(void) {
  while(1);
}

void HAL_UART_MspInit(UART_HandleTypeDef* s_uart_conf) {
  UNUSED(s_uart_conf);

  GPIO_InitTypeDef s_gpio_tx_conf = GPIOA_UART_TX_CONF;
  GPIO_InitTypeDef s_gpio_rx_conf = GPIOA_UART_RX_CONF;

  if(!__HAL_RCC_GPIOA_IS_CLK_ENABLED()) {
    __HAL_RCC_GPIOA_CLK_ENABLE();
  }

  if(!__HAL_RCC_USART2_IS_CLK_ENABLED()) {
    __HAL_RCC_USART2_CLK_ENABLE();
  }

  HAL_GPIO_Init(UART_GPIO_PORT, &s_gpio_tx_conf);
  HAL_GPIO_Init(UART_GPIO_PORT, &s_gpio_rx_conf);
}

void UART_Init(void) {
  if(HAL_UART_Init(&gs_uart_init_conf) != HAL_OK) {
    UART_ErrorHandler();
  }
  return;
}

void UART_Putc(uint8_t ch) {
  char buff = ch;
  HAL_UART_Transmit(&gs_uart_init_conf, &buff, 1, UART_TX_DELAY);
  return;
}

void _putchar(char ch) {
  UART_Putc(ch);
}

void UART_Puts(const char* str) {
  HAL_UART_Transmit(&gs_uart_init_conf, str, strlen(str), UART_TX_DELAY);
}

