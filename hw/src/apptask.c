#include "FreeRTOS.h"
#include "task.h"
#include "apptask.h"
#include "adc.h"
#include "dbg.h"
#include "uart.h"
#include "pwm.h"
#include "app.h"
#include "tmr.h"

#define SLOG_SIGBUF_SIZE (5)

#ifdef __SLOG__
static void _slog(uint32_t* sigbuf) {
  sigbuf[0] = (uint32_t)App_GetVoltage(VAdcChPot_E);
  sigbuf[1] = (uint32_t)App_GetCurrent(IfbkPhA_E);
//  sigbuf[2] = (uint32_t)App_GetCurrent(IfbkPhB_E);
  sigbuf[2] = TMR_GetCount();
  sigbuf[3] = (uint32_t)App_GetCurrent(IfbkPhC_E);
  sigbuf[4] = (uint32_t)App_GetPwmVoltage(PwmChA_E);
}

void AppTask_SLog(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  uint8_t idx;
  uint8_t *ptr;
  uint32_t sigbuf[SLOG_SIGBUF_SIZE] = {0};
  for(;;) {
    _slog(sigbuf);
    ptr = (uint8_t*)&sigbuf[0];
    UART_Putc(0xAA);
    for(idx = 0; idx < sizeof(sigbuf); idx++) {
      UART_Putc(ptr[idx]);
    }
    vTaskDelayUntil(&last_wake_time, APP_TASK_SLOG_TS);
  }
}
#endif

void AppTask_500ms(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();

  for(;;) {
    GPIO_LedToggle();
    vTaskDelayUntil(&last_wake_time, APP_TASK_500MS);
  }
}
