#include <string.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "stream_buffer.h"
#include "task.h"
#include "apptasks.h"
#include "dbg.h"
#include "uart.h"
#include "app.h"
#include "tmr.h"
#include "mtrif.h"
#include "math.h"
#include "gpio.h"
#include "command.h"
#include "mtrif.h"

#define SLOG_START_FRAME (0x00CD00AB)
/* Size definition in bytes. */
#define SLOG_START_FRAME_SIZE (sizeof(int32_t))
#define SLOG_MOTOR_CONTROL_BUFF_SIZE (sizeof(int32_t) * APP_TASK_MOTOR_CONTROL_N_SIGNALS)
#define SLOG_ADC_ISR_BUFF_SIZE (sizeof(int32_t) * ADC_ISR_N_SIGNALS)
#define SLOG_BUFF_SIZE ((size_t)(SLOG_START_FRAME_SIZE + SLOG_MOTOR_CONTROL_BUFF_SIZE + SLOG_ADC_ISR_BUFF_SIZE))

void AppTask_LowPrio(void* params) {
#ifdef __SLOG__
  const uint32_t SlogStartFrame = (uint32_t)SLOG_START_FRAME;
  uint8_t buff_signal_log[SLOG_BUFF_SIZE] = {0};
  StreamBufferHandle_t stream_buff_motor_control = (StreamBufferHandle_t)params;
#endif
  TickType_t last_wake_time = xTaskGetTickCount();
  for(;;) {

    /* Application code goes here. */

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
  MtrParams_S mtr_params;
  float ifbk_dq[2];

#ifdef __SLOG__
  StreamBufferHandle_t stream_buff = (StreamBufferHandle_t)params;
  float signal_buff[APP_TASK_MOTOR_CONTROL_N_SIGNALS] = {0};
#endif

  MtrIf_Init();
  /* command_init(); */

  for(;;) {

    /* Motor control goes here. */
    MtrIf_CtrlSlow();

    /* Run command loop. */
    /* command_update(); */
    MtrIf_GetMtrParams(&mtr_params);
    MtrIf_GetIfbkDq(ifbk_dq);

#ifdef __SLOG__
    signal_buff[0] = (float)MtrIf_GetPos();
    signal_buff[1] = (float)MtrIf_GetIfbkPh(IfbkPhA_E);
    signal_buff[2] = (float)MtrIf_GetIfbkPh(IfbkPhB_E);
    signal_buff[3] = (float)MtrIf_GetIfbkPh(IfbkPhC_E);
    signal_buff[4] = (float)MtrIf_GetPwmDcCh(PwmChA_E);
    signal_buff[5] = (float)MtrIf_GetPwmDcCh(PwmChB_E);
    signal_buff[6] = (float)MtrIf_GetPwmDcCh(PwmChC_E);
    signal_buff[7] = mtr_params.ind;
    signal_buff[8] = mtr_params.res;
    signal_buff[9] = mtr_params.ifbk_ofs[0];

    xStreamBufferSend(stream_buff,
        (void*)signal_buff,
        sizeof(signal_buff),
        0);
#endif

    vTaskDelayUntil(&last_wake_time, APP_TASK_MOTOR_CONTROL_TS); 
  }
}
