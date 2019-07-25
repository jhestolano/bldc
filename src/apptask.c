#include "FreeRTOS.h"
#include "task.h"

#include "apptask.h"
#include "adc.h"
#include "dbg.h"
#include "uart.h"

void AppTask_Flash(void* params) {
  uint32_t adc_data;
  TickType_t last_wake_time = xTaskGetTickCount();
  for(;;) {
    vTaskDelayUntil(&last_wake_time, APP_TASK_FLASH_TS);
    GPIO_LedToggle();
//    ADC_Start();
//    ADC_WaitConv();
//    adc_data = ADC_Read();
//    DBG_DEBUG("ADC: %u\n\r", adc_data);
  }
}

void AppTask_PrintK(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  for(;;) {
    vTaskDelayUntil(&last_wake_time, APP_TASK_PRINTK_TS);
  }
}
