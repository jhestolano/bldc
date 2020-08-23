#include "command.h"
#include "ucmd.h"
#include "line.h"
#include "dbg.h"

extern void GPIO_LedToggle(void);

/******************************************************************************/
/* Callback definitions. */
/******************************************************************************/
static ErrCode_e command_led_toggle(Arg_s* args, void* usrargs) {
  (void)args;
  (void)usrargs;
  GPIO_LedToggle();
  return E_OK;
}

/******************************************************************************/
/* Table definition. */
/******************************************************************************/
const uCmdInfo_s CommandTable_a[] = {
  {"led_toggle", command_led_toggle, UCMD_ARG_NONE, UCMD_ARG_USER_NONE},
  /* Keep this element last. Denotes end of table. */
  UCMD_TABLE_END,
};

void command_init(void) {
  Line_Init();
  uCmd_InitTable(CommandTable_a, UCMD_GET_TABLE_SIZE(CommandTable_a));
}

void command_update(void) {
  uCmd_Loop();
}

void command_uart_rx_callback(uint8_t data) {
  DBG_DEBUG("Rx data: %d\n\r", data);
  Line_AddChar(data);
  if(Line_BuffIsFull()) {
    DBG_WARN("Buffer is full!\n\r");
  } if(Line_BuffIsOvrFlwn()) {
    DBG_WARN("Buffer overflow!!\n\r");
  }
}
