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
#include "enc.h"

#define SLOG_SIGBUF_SIZE (4)

#ifdef __SLOG__
static void _slog(uint32_t* sigbuf) {
  static uint16_t idx;
  sigbuf[0] = (uint32_t)App_GetVoltage(VAdcChPot_E);
  sigbuf[1] = (uint32_t)App_GetTemp();
//  sigbuf[2] = TMR_GetCount();
//  sigbuf[0] = gAdcChBuf[idx++];
  sigbuf[2] = (uint32_t)ENC_GetCnt();
  sigbuf[3] = (uint32_t)App_GetCurrent(IfbkPhC_E);
}

void AppTask_SLog(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  uint8_t idx;
  uint8_t *ptr;
  uint32_t sigbuf[SLOG_SIGBUF_SIZE] = {0};
  uint8_t done = 0;
  uint16_t adcidx = 0;
  for(;;) {
//    __ADC_DISABLE_ISR();
//    done = gFlagAdcBufFull;
//    __ADC_ENABLE_ISR();
//    if(done && (adcidx < (uint16_t)ADC_CH_BUF_LEN)) {
      _slog(sigbuf);
      ptr = (uint8_t*)&sigbuf[0];
      UART_Putc(0xAA);
      for(idx = 0; idx < sizeof(sigbuf); idx++) {
        UART_Putc(ptr[idx]);
      }
      adcidx++;
//    }
    vTaskDelayUntil(&last_wake_time, APP_TASK_SLOG_TS);
  }
}
#endif

void AppTask_500ms(void* params) {
  TickType_t last_wake_time = xTaskGetTickCount();
  uint32_t idx = 0;
  for(;;) {
//    GPIO_LedToggle();
    vTaskDelayUntil(&last_wake_time, APP_TASK_500MS);
    // App_SetPwmVoltage(PwmChA_E, 5e3 * idx);
    idx ^= 1u;

  }
}
