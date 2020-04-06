#include "uart.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_uart.h"
#include "stm32f3xx_hal_uart_ex.h"
#include "stm32f3xx_hal_rcc_ex.h"
#include "stm32f3xx_hal_rcc.h"
#include "stm32f3xx_hal_cortex.h"
#include <string.h>

/* UART xmit delay in milliseconds. */
#define UART_TX_DELAY (1)

static UART_HandleTypeDef gs_uart_init_conf = UART_INIT_CONF;

static DMA_HandleTypeDef gs_uart_dma_conf = DMA_UART_INIT_CONF;

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

  /* Configure DMA. */
  if(!__HAL_RCC_DMA1_IS_CLK_ENABLED()) {
    __HAL_RCC_DMA1_CLK_ENABLE();
  }
  if(HAL_DMA_Init(&gs_uart_dma_conf) != HAL_OK) {
    UART_ErrorHandler();
  }
  __HAL_LINKDMA(&gs_uart_init_conf, hdmatx, gs_uart_dma_conf);

  HAL_NVIC_SetPriority(DMA1_Channel7_IRQn, UART_DMA_TX_PRIO, UART_DMA_TX_SUBPRIO);
  HAL_NVIC_EnableIRQ(DMA1_Channel7_IRQn);
  HAL_NVIC_SetPriority(USART2_IRQn, UART_DMA_TX_PRIO, UART_DMA_TX_SUBPRIO);
  HAL_NVIC_EnableIRQ(USART2_IRQn);
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

void UART_DMAPutBytes(uint8_t* bufdata, size_t bufsz) {
  if(HAL_UART_Transmit_DMA(&gs_uart_init_conf, bufdata, bufsz) != HAL_OK) {
  }
}

void _putchar(char ch) {
  UART_Putc(ch);
}

void UART_Puts(const char* str) {
  HAL_UART_Transmit(&gs_uart_init_conf, str, strlen(str), UART_TX_DELAY);
}

void DMA1_Channel7_IRQHandler(void) {
  HAL_DMA_IRQHandler(&gs_uart_dma_conf);
}

void USART2_IRQHandler(void) {
  HAL_UART_IRQHandler(&gs_uart_init_conf);
}
