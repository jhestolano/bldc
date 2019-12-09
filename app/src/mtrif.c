#include "mtrif.h"
#include "app.h"
#include <string.h>
#include <stddef.h>

void MtrIf_Init(MtrIf_S* mtrif) {
  MTRIF_LOCK();
  memset(mtrif, 0, sizeof(MtrIf_S));
  mtrif->isarmed = 1;
  MTRIF_UNLOCK();
  App_ArmMotor();
}
 
void MtrIf_SetVin(MtrIf_S* mtrif, int32_t vin) {
  uint8_t isrev = 0;
  if(isrev) {
    vin = -vin;
  }
  if(vin >= 0) {
    App_SetPwmVoltage(MTRIF_POS_PH, vin);
    App_SetPwmVoltage(MTRIF_NEG_PH, 0);
  } else {
    App_SetPwmVoltage(MTRIF_POS_PH, 0);
    App_SetPwmVoltage(MTRIF_NEG_PH, -vin);
  }
}

void MtrIf_Upd(MtrIf_S* mtrif) {
  MTRIF_LOCK();
  mtrif->prvpos = mtrif->pos;
  mtrif->pos = App_GetPosition();
  MTRIF_UNLOCK();
}

int32_t MtrIf_GetPos(MtrIf_S* mtrif) {
  return App_GetPosition();
}

int32_t MtrIf_CalcSpd(MtrIf_S* mtrif) {
  int32_t pos = MtrIf_GetPos(mtrif);
  int32_t prvpos;
  int32_t spd;
  MTRIF_LOCK();
  prvpos = mtrif->prvpos;
  mtrif->prvpos = pos;
  MTRIF_UNLOCK();
  spd = (int32_t)MTRIF_TS * (pos - prvpos);
  return (int32_t)MTRIF_TO_RPM * spd;
}
