#include "ucmd.h"

uCmd_CharRxCallback MockUART_ChrRxCallback;

void MockUART_SendChar(uint8_t ch) {
  uint8_t buff = ch;
  MockUART_ChrRxCallback((void*)&buff);
}
