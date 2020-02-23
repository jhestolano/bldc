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
#include "ctrl.h"
#include "math.h"

#define SLOG_SIGBUF_SIZE (8)

static MtrIf_S gs_mtr_if = {0};

#ifdef __SLOG__
static void _slog(uint32_t* sigbuf) {
  sigbuf[0] = (int32_t)App_GetCurrent(IfbkPhC_E);
  sigbuf[1] = (int32_t)MtrIf_GetPos(&gs_mtr_if);
  sigbuf[2] = (int32_t)MtrIf_GetPosTgt(&gs_mtr_if);
  sigbuf[3] = (int32_t)MtrIf_GetSpd(&gs_mtr_if);
  sigbuf[4] = (int32_t)rtY.MtrPosEst;
  sigbuf[5] = (int32_t)rtY.MtrDisEst;
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
    vTaskDelayUntil(&last_wake_time, APP_TASK_500MS);
  }
}

void AppTask_MotorControl(void* params) {
  float itgt, spd, spdtgt;
  TickType_t last_wake_time = xTaskGetTickCount();
  MtrIf_Init(&gs_mtr_if);
  uint32_t cnt = 0;
  for(;;) {
//    Ctrl_1Khz_Step(MtrIf_GetPosTgt(&gs_mtr_if), MtrIf_GetSpd(&gs_mtr_if), &itgt);
    rtU.MtrPosTgt = 45000;
    cnt++;
    Trig_1Khz();
    MtrIf_SetSpd(&gs_mtr_if, rtY.MtrSpdFil);
    MtrIf_SetIfbkTgt(&gs_mtr_if, (int32_t)rtY.IfbkPhATgt);
    MtrIf_SetPosTgt(&gs_mtr_if, (int32_t)rtY.MtrPosRef);
    vTaskDelayUntil(&last_wake_time, APP_TASK_MOTOR_CONTROL_TS); 
  }
}

MtrIf_S* AppTask_GetMtrIf(void) {
  return &gs_mtr_if;
}
