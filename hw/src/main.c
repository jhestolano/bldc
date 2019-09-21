#include "FreeRTOS.h"
#include "task.h"

#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_rcc_ex.h"
#include "adc.h"
#include "gpio.h"
#include "pwm.h"
#include "uart.h"
#include "printf.h"
#include "dbg.h"
#include "apptask.h"

static void SystemClock_Config(void);
static void Error_Handler(void);
static void HwInit(void);
void vAssertCalled( const char *pcFile, int32_t ulLine );

int main(void)
{
  HwInit();
  TaskHandle_t h_task_flash;
  if(xTaskCreate(AppTask_Flash, (signed portCHAR*)"LED Task", APP_TASK_FLASH_STACK_SIZE, NULL, APP_TASK_FLASH_PRIO, &h_task_flash) == pdPASS) {
    DBG_DEBUG("Task created succesfully!\n\r");
  }
  vTaskStartScheduler();
  for(;;){
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                              | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_TIM1;
  PeriphClkInit.Tim1ClockSelection = RCC_TIM1CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
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

void vAssertCalled( const char *pcFile, int32_t ulLine )
{
volatile unsigned long ul = 0;

	( void ) pcFile;
	( void ) ulLine;

	taskENTER_CRITICAL();
	{
		/* Set ul to a non-zero value using the debugger to step out of this
		function. */
    DBG_ERR("Assertion Error: %s : %d\n\r", pcFile, ulLine);
		while( ul == 0 )
		{
			__NOP();
		}
	}
	taskEXIT_CRITICAL();
}

void HwInit(void) {
  HAL_Init();
  SystemClock_Config();
  GPIO_Init();
  UART_Init();
  PWM_Init();
  ADC_Init();
  HAL_GPIO_WritePin(XH_PWM_ENABLE_PORT, UH_PWM_ENABLE_PIN | VH_PWM_ENABLE_PIN | WH_PWM_ENABLE_PIN, GPIO_PIN_SET);

  if(HAL_GPIO_ReadPin(DIAG_PORT, DIAG_PIN)) {
    DBG_DEBUG("Diag pin enabled.\n\r"); 
  } else {
    DBG_ERR("Diag pin disabled!!!\n\r");
  }

}

