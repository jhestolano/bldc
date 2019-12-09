#include "FreeRTOS.h"
#include "task.h"
#include "apptask.h"
#include "adc.h"
#include "dbg.h"
#include "uart.h"
#include "pwm.h"
#include "app.h"
#include "tmr.h"
#include "gpio.h"
#include "mtrif.h"
#include "enc.h"

#define SLOG_SIGBUF_SIZE (4)

static MtrIf_S gs_mtr_if = {0};

#ifdef __SLOG__
static void _slog(uint32_t* sigbuf) {
  static uint16_t idx;
  sigbuf[0] = (uint32_t)App_GetVoltage(VAdcChPot_E);
  sigbuf[1] = (uint32_t)MtrIf_CalcSpd(&gs_mtr_if);
  sigbuf[2] = (uint32_t)MtrIf_GetPos(&gs_mtr_if);
  sigbuf[3] = (uint32_t)App_GetCurrent(IfbkPhC_E);
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
  uint32_t idx = 0;
  for(;;) {
    vTaskDelayUntil(&last_wake_time, APP_TASK_500MS);
    idx ^= 1u;
  }
}

void AppTask_MotorControl(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  MtrIf_Init(&gs_mtr_if);
  for(;;) {
    MtrIf_Upd(&gs_mtr_if);
    vTaskDelayUntil(&last_wake_time, APP_TASK_MOTOR_CONTROL_TS); 
  }
}

MtrIf_S* AppTask_GetMtrIf(void) {
  return &gs_mtr_if;
}
