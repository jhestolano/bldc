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
#include "math.h"
#include <stdbool.h>
#include "ucmd.h"

#define SLOG_START_FRAME (0x00CD00AB)
/* Size definition in bytes. */
#define SLOG_START_FRAME_SIZE (sizeof(int32_t))
#define SLOG_MOTOR_CONTROL_BUFF_SIZE (sizeof(int32_t) * APP_TASK_MOTOR_CONTROL_N_SIGNALS)
#define SLOG_ADC_ISR_BUFF_SIZE (sizeof(int32_t) * ADC_ISR_N_SIGNALS)
#define SLOG_BUFF_SIZE ((size_t)(SLOG_START_FRAME_SIZE + SLOG_MOTOR_CONTROL_BUFF_SIZE + SLOG_ADC_ISR_BUFF_SIZE))

void AppTask_LowPrio(void* params) {
  const uint32_t SlogStartFrame = (uint32_t)SLOG_START_FRAME;
  uint8_t buff_signal_log[SLOG_BUFF_SIZE] = {0};
  TickType_t last_wake_time = xTaskGetTickCount();
  StreamBufferHandle_t stream_buff_motor_control = (StreamBufferHandle_t)params;
  uCmd_Init((uCmd_CharRxCallback*)&UART_NewCharCallback);
  for(;;) {
#ifdef __SLOG__
    /*-----------------------------------------------------------------------------
     * Signal logging. 
     *-----------------------------------------------------------------------------*/
    /* Make sure start header is always correct. */
    memcpy((void*)buff_signal_log, (void*)((uint8_t*)&SlogStartFrame), (size_t)SLOG_START_FRAME_SIZE);
    xStreamBufferReceive(stream_buff_motor_control,
                         /* Element 0 reserved for header. */
                         (void*)&buff_signal_log[SLOG_START_FRAME_SIZE],
                         (size_t)SLOG_MOTOR_CONTROL_BUFF_SIZE,
                         /* Do not wait. */
                         0);
    UART_DMAPutBytes((uint8_t*)buff_signal_log, sizeof(buff_signal_log));
#endif
    /*-----------------------------------------------------------------------------
     * Handle command line. 
     *-----------------------------------------------------------------------------*/
    vTaskDelayUntil(&last_wake_time, APP_TASK_SLOG_TS);
  }
}


void AppTask_MotorControl(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  StreamBufferHandle_t stream_buff = (StreamBufferHandle_t)params;
  float signal_buff[APP_TASK_MOTOR_CONTROL_N_SIGNALS] = {0};
  RLSQ_S RLSQ_Output = {0};
  uint8_t is_done = false;
  uint8_t is_tuned = false;
  uint32_t tmr = 0;
  MtrIf_Init();
  MtrIf_SetCtlMd(MtrCtlMdIfbk_E);

  for(;;) {

    MtrIf_Ctl();

    signal_buff[0] = (float)MtrIf_GetVin();
    signal_buff[1] = (float)MtrIf_GetIfbk();
    signal_buff[2] = (float)MtrIf_GetSpd();
    signal_buff[3] = (float)MtrIf_GetPos();

    xStreamBufferSend(stream_buff,
        (void*)signal_buff,
        sizeof(signal_buff),
        0);

    vTaskDelayUntil(&last_wake_time, APP_TASK_MOTOR_CONTROL_TS); 
  }
}