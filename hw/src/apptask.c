#include <string.h>
#include "FreeRTOS.h"
#include "stream_buffer.h"
#include "task.h"
#include "apptask.h"
#include "dbg.h"
#include "uart.h"
#include "app.h"
#include "tmr.h"
#include "mtrif.h"
/* #include "ctrl_30khz.h" */
#include "ctrl.h"
#include "rlsq.h"

#define SLOG_START_FRAME (0x00CD00AB)
/* Size definition in bytes. */
#define SLOG_START_FRAME_SIZE (sizeof(int32_t))
#define SLOG_MOTOR_CONTROL_BUFF_SIZE (sizeof(int32_t) * APP_TASK_MOTOR_CONTROL_N_SIGNALS)
#define SLOG_ADC_ISR_BUFF_SIZE (sizeof(int32_t) * ADC_ISR_N_SIGNALS)
#define SLOG_BUFF_SIZE ((size_t)(SLOG_START_FRAME_SIZE + SLOG_MOTOR_CONTROL_BUFF_SIZE + SLOG_ADC_ISR_BUFF_SIZE))


#ifdef __SLOG__

void AppTask_SLog(void* params) {
  const uint32_t SlogStartFrame = (uint32_t)SLOG_START_FRAME;

  uint8_t buff_signal_log[SLOG_BUFF_SIZE] = {0};
  TickType_t last_wake_time = xTaskGetTickCount();
  StreamBufferHandle_t stream_buff_motor_control = (StreamBufferHandle_t)params;
  for(;;) {
    /* Make sure start header is always correct. */
    memcpy((void*)buff_signal_log, (void*)((uint8_t*)&SlogStartFrame), (size_t)SLOG_START_FRAME_SIZE);
    xStreamBufferReceive(stream_buff_motor_control,
                         /* Element 0 reserved for header. */
                         (void*)&buff_signal_log[SLOG_START_FRAME_SIZE],
                         (size_t)SLOG_MOTOR_CONTROL_BUFF_SIZE,
                         /* Do not wait. */
                         0);
    UART_DMAPutBytes((uint8_t*)buff_signal_log, sizeof(buff_signal_log));
    vTaskDelayUntil(&last_wake_time, APP_TASK_SLOG_TS);
  }
}
#endif

#ifdef ENBL_MOTOR_IDENT
void motor_ident_run(void) {
  const uint32_t TCycleMillis = 500;
  const uint32_t TSampleMillis = 1;
  static uint32_t cnt;
  static uint32_t idx;
  int32_t Vin[] = {-12000, 12000};
  float pot = (float)App_GetVoltage(VAdcChPot_E);
  if(cnt++ >= (uint32_t)(TCycleMillis / TSampleMillis)) {
    idx ^= 1;
    MtrIf_SetVin((int32_t)((float)Vin[idx] * (pot / 3300.0f)));
    cnt = 0;
  }
}
#endif

typedef struct RLSQ_tag {
  float SpdEst;
  float Err;
  float Params[3];
} RLSQ_S;

void AppTask_MotorControl(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  StreamBufferHandle_t stream_buff = (StreamBufferHandle_t)params;
  int32_t signal_buff[APP_TASK_MOTOR_CONTROL_N_SIGNALS] = {0};
  RLSQ_S RLSQ_Output = {0};
  MtrIf_Init();
  RLSQ_Init();
  for(;;) {

#ifdef ENBL_MOTOR_IDENT
    motor_ident_run();
#endif
    MtrIf_Ctl();

    RLSQ_Output.SpdEst = RLSQ_Estimate(
      MtrIf_GetIfbk(),
      MtrIf_GetVin(),
      MtrIf_GetSpd(),
      &RLSQ_Output.Params[0],
      &RLSQ_Output.Err
    );

    signal_buff[0] = App_GetVoltage(VAdcChPot_E);
    signal_buff[1] = MtrIf_GetPos();
    signal_buff[2] = MtrIf_GetVin();
    signal_buff[3] = MtrIf_GetIfbk();
    signal_buff[4] = MtrIf_GetSpd();;
    signal_buff[5] = (int32_t)RLSQ_Output.SpdEst;
    signal_buff[6] = (int32_t)RLSQ_Output.Err;
    signal_buff[7] = (int32_t)(RLSQ_Output.Params[0] * 1000.f);
    signal_buff[8] = (int32_t)(RLSQ_Output.Params[1] * 1000.f);
    signal_buff[9] = (int32_t)(RLSQ_Output.Params[2] * 1000.f);

    xStreamBufferSend(stream_buff,
                      (void*)signal_buff,
                      sizeof(signal_buff),
                      0);

    vTaskDelayUntil(&last_wake_time, APP_TASK_MOTOR_CONTROL_TS); 
  }
}

/* MtrIf_S* AppTask_GetMtrIf(void) { */
/*   return &gs_mtr_if; */
/* } */
