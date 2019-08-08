#include "FreeRTOS.h"
#include "task.h"

#include "apptask.h"
#include "adc.h"
#include "dbg.h"
#include "uart.h"
#include "pwm.h"

void AppTask_Flash(void* params) {
  uint32_t adc_data;
  uint16_t pwmcnt = 0;
  TickType_t last_wake_time = xTaskGetTickCount();
  float dc = 0.;
  uint16_t idx;
  for(;;) {
    GPIO_LedToggle();

    adc_data = ADC_ReadCh(ADC_POT_CH_E);
    dc = adc_data / 4096.;

    PWM_SetDC(PWM_PH_U, 100 * dc);
    PWM_SetDC(PWM_PH_V, 0.);
    PWM_SetDC(PWM_PH_W, 0.);

    DBG_DEBUG("PHA: %u\n\r", ADC_ReadCh(ADC_PHA_IFBK_CH_E));
    DBG_DEBUG("PHB: %u\n\r", ADC_ReadCh(ADC_PHB_IFBK_CH_E));
    DBG_DEBUG("PHC: %u\n\r", ADC_ReadCh(ADC_PHC_IFBK_CH_E));
    DBG_DEBUG("POT: %u\n\r\n\r", ADC_ReadCh(ADC_POT_CH_E));

    vTaskDelayUntil(&last_wake_time, APP_TASK_FLASH_TS);
  }
}

void AppTask_PrintK(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  for(;;) {
    vTaskDelayUntil(&last_wake_time, APP_TASK_PRINTK_TS);
  }
}
