#include "enc.h"
#include "stm32f3xx_hal_dma.h"
#include "stm32f3xx_hal_tim.h"
#include "stm32f3xx_hal_tim_ex.h"
#include "stm32f3xx_hal_rcc_ex.h"
#include "stm32f3xx_hal_rcc.h"
#include "stm32f3xx_ll_tim.h"
#include "dbg.h"

static TIM_HandleTypeDef gs_tim_enc_conf = TIM_ENC_INIT_CONF;

static void ENC_ErrorHandler(char* errmsg) {
  DBG_ERR(errmsg);
}

void ENC_Init(void) {
  DBG_DEBUG("Initializing encoder interface...");
  TIM_Encoder_InitTypeDef s_enc_conf = ENC_INIT_CONF;
  if(HAL_TIM_Encoder_Init(&gs_tim_enc_conf, &s_enc_conf) != HAL_OK) {
    ENC_ErrorHandler("Error initializing encoder interface!");
  }
}

void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef* s_enc_conf) {
  
}


void ENC_Start(void) {

}

uint16_t ENC_GetCnt(void) {

}

void ENC_DeInit(void) {

}
