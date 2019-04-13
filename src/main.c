#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_gpio.h"
#include "adc.h"

static GPIO_InitTypeDef  GPIO_InitStruct;

static void SystemClock_Config(void);
static void Error_Handler(void);

int main(void)
{
  uint32_t tmp = 0;
  HAL_StatusTypeDef st;
  HAL_Init();

  SystemClock_Config();

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

  GPIO_InitStruct.Pin = GPIO_PIN_5;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  ADC_Init();

  while (1)
  {
    HAL_ADC_Start(&gsAdcHandle);
    st = HAL_ADC_PollForConversion(&gsAdcHandle, 100);
    if(st == HAL_OK) {
      tmp = HAL_ADC_GetValue(&gsAdcHandle);
    }
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    HAL_Delay(tmp);
  }
}

static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  
  /* HSI Oscillator already ON after system reset, activate PLL with HSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_NONE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct)!= HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_ACR_LATENCY_2)!= HAL_OK)
  {
    Error_Handler();
  }
}

static void Error_Handler(void)
{
  while(1)
  {
  }
}