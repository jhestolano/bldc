#include <string.h>
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
  sigbuf[0] = 0x00CD00AB;
  sigbuf[1] = (int32_t)App_GetCurrent(IfbkPhC_E);
  sigbuf[2] = (int32_t)MtrIf_GetPos(&gs_mtr_if);
  sigbuf[3] = (int32_t)MtrIf_GetPosTgt(&gs_mtr_if);
  sigbuf[4] = (int32_t)MtrIf_GetSpd(&gs_mtr_if);
  sigbuf[5] = (int32_t)rtY.MtrPosEst;
  sigbuf[6] = (int32_t)rtY.MtrDisEst;
  sigbuf[7] = (int32_t)rtY.IfbkPhATgt;
}

void AppTask_SLog(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  uint32_t sigbuf[SLOG_SIGBUF_SIZE] = {0};
  for(;;) {
    _slog(sigbuf);
    UART_DMAPutBytes((uint8_t*)sigbuf, sizeof(sigbuf));
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
  const int32_t PosTgtArr[] = {45000, -0, 100.0, 30000, 0, -10000, 0.};
  TickType_t last_wake_time = xTaskGetTickCount();
  MtrIf_Init(&gs_mtr_if);
  uint32_t cnt = 0;
  uint32_t idx = 0;
  for(;;) {
//    Ctrl_1Khz_Step(MtrIf_GetPosTgt(&gs_mtr_if), MtrIf_GetSpd(&gs_mtr_if), &itgt);
    rtU.MtrPosTgt = PosTgtArr[idx];
    cnt++;
    if(cnt >= 2000) {
      idx++;
      cnt = 0;
      if(idx > sizeof(PosTgtArr) / sizeof(uint32_t)) {
        idx = 0;
      }
    }
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
