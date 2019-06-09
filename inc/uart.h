#ifndef UART_H
#define UART_H

#include "stdint.h"
#include "stddef.h"

/*******************************************************************************
 * UART MACRO DEFINITIONS.
*******************************************************************************/
#define UART_GPIO_PORT (GPIOA)
#define UART_TX_PIN (GPIO_PIN_2)
#define UART_RX_PIN (GPIO_PIN_3)

/*******************************************************************************
 * GPIO UART TX CONFIGURATION.
*******************************************************************************/
#define GPIOA_UART_TX_CONF {                                                   \
  .Pin = UART_TX_PIN,                                                          \
  .Mode = GPIO_MODE_AF_PP,                                                     \
  .Pull = GPIO_PULLUP,                                                         \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
  .Alternate = GPIO_AF7_USART2,                                                \
}

/*******************************************************************************
 * GPIO UART RX CONFIGURATION.
*******************************************************************************/
#define GPIOA_UART_RX_CONF {                                                   \
  .Pin = UART_RX_PIN,                                                          \
  .Mode = GPIO_MODE_AF_OD,                                                     \
  .Pull = GPIO_PULLUP,                                                         \
  .Speed = GPIO_SPEED_FREQ_HIGH,                                               \
  .Alternate = GPIO_AF7_USART2                                                 \
}

/*******************************************************************************
* UART INIT CONFIGURATION.
********************************************************************************
* Type: UART_HandleTypeDef. 
*******************************************************************************/
#define UART_INIT_CONF {                                                       \
  .Instance = USART2,                                                          \
  .Init = {                                                                    \
    .BaudRate = 115200,                                                        \
    .WordLength = UART_WORDLENGTH_8B,                                          \
    .StopBits = UART_STOPBITS_1,                                               \
    .Parity = UART_PARITY_NONE,                                                \
    .HwFlowCtl = UART_HWCONTROL_NONE,                                          \
    .Mode = UART_MODE_TX_RX,                                                   \
  },                                                                           \
}

/*******************************************************************************
*******************************************************************************/

void UART_Init(void);

void UART_Putc(uint8_t ch);

void UART_Puts(uint8_t const * buff, size_t len);

void UART_Getc(uint8_t* ch);

void UART_Gets(uint8_t* buff, size_t buff_len);

#endif // UART_H
