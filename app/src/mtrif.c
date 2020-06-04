#include "mtrif.h"
#include "app.h"
#include <string.h>
#include <stddef.h>

void MtrIf_SetVin(int32_t vin) {
  if(vin >= 0) {
    App_SetPwmVoltage(MTRIF_POS_PH, (uint32_t)vin);
    App_SetPwmVoltage(MTRIF_NEG_PH, 0);
  } else {
    App_SetPwmVoltage(MTRIF_POS_PH, 0);
    App_SetPwmVoltage(MTRIF_NEG_PH, (uint32_t)(-vin));
  }
}

int32_t MtrIf_GetVin(void) {
  int32_t vin = (int32_t)App_GetPwmVoltage(MTRIF_POS_PH)
               -(int32_t)App_GetPwmVoltage(MTRIF_NEG_PH);
  return vin;
}

int32_t MtrIf_GetCurrent(void) {
  int32_t current = App_GetCurrent(MTRIF_POS_PH_IFBK)
                  - App_GetCurrent(MTRIF_NEG_PH_IFBK);
  return current;
}

int32_t MtrIf_GetPos(void) {
  return App_GetPosition();
}
