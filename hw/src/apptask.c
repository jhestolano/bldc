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
#include "ctrl.h"
#include "rlsq.h"
#include "adc.h"

/* Number of signals being logged. */
#define SLOG_SIGBUF_SIZE (10)
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
  const int32_t Vin[] = {-3000, 3000};
  const uint32_t TCycleMillis = 500;
  const uint32_t TSampleMillis = 1;
  static uint32_t cnt;
  static uint32_t idx;
  if(cnt++ >= (uint32_t)(TCycleMillis / TSampleMillis)) {
    idx ^= 1;
    MtrIf_SetVin(Vin[idx]);
    cnt = 0;
  }
}
#endif

void AppTask_MotorControl(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  StreamBufferHandle_t stream_buff = (StreamBufferHandle_t)params;
  int32_t signal_buff[APP_TASK_MOTOR_CONTROL_N_SIGNALS] = {0};
  int32_t heart_beat = 0;
  RLSQ_Init();
  App_ArmMotor();
  for(;;) {

#ifdef ENBL_MOTOR_IDENT
    motor_ident_run();
#endif

    /* RLSQ_Output.SpdEst = RLSQ_Estimate(MtrIf_GetCurrent(), */
    /*     MtrIf_GetVin(), MtrIf_GetSpd(&gs_mtr_if), */
    /*     &RLSQ_Output.Params[0], &RLSQ_Output.Err); */
    signal_buff[0] = App_GetVoltage(VAdcChPot_E);
    signal_buff[1] = MtrIf_GetPos();
    signal_buff[2] = MtrIf_GetVin();
    signal_buff[3] = MtrIf_GetCurrent();
    signal_buff[4] = heart_beat++;

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
