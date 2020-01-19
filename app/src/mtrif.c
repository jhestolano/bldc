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
    App_SetPwmVoltage(MTRIF_POS_PH, (uint32_t)vin);
    App_SetPwmVoltage(MTRIF_NEG_PH, 0);
  } else {
    App_SetPwmVoltage(MTRIF_POS_PH, 0);
    App_SetPwmVoltage(MTRIF_NEG_PH, (uint32_t)(-vin));
  }
}

int32_t MtrIf_GetPos(MtrIf_S* mtrif) {
  return App_GetPosition();
}

int32_t MtrIf_GetPosTgt(MtrIf_S* mtrif) {
  int32_t ret;
  MTRIF_LOCK();
  ret = mtrif->postgt;
  MTRIF_UNLOCK();
  return ret;
}

void MtrIf_SetPosTgt(MtrIf_S* mtrif, int32_t postgt) {
  MTRIF_LOCK();
  mtrif->postgt = postgt;
  MTRIF_UNLOCK();
}

int32_t MtrIf_GetSpd(MtrIf_S* mtrif) {
  int32_t ret;
  MTRIF_LOCK();
  ret = mtrif->spd;
  MTRIF_UNLOCK();
  return ret;
}

void MtrIf_SetSpd(MtrIf_S* mtrif, int32_t spd) {
  MTRIF_LOCK();
  mtrif->spd = spd;
  MTRIF_UNLOCK();
}

void MtrIf_SetIfbkTgt(MtrIf_S* mtrif, int32_t itgt) {
  MTRIF_LOCK();
  mtrif->ifbktgt = itgt;
  MTRIF_UNLOCK();
}

int32_t MtrIf_GetIfbkTgt(MtrIf_S* mtrif) {
  int32_t ret;
  MTRIF_LOCK();
  ret = mtrif->ifbktgt;
  MTRIF_UNLOCK();
  return ret;
}

/*
int32_t MtrIf_GetSpdTgt(MtrIf_S* mtrif) {
  int32_t ret;
  MTRIF_LOCK();
  ret = mtrif->spdtgt;
  MTRIF_UNLOCK();
  return ret;
}

void MtrIf_SetSpdTgt(MtrIf_S* mtrif, int32_t spdtgt) {
  MTRIF_LOCK();
  mtrif->spdtgt = spdtgt;
  MTRIF_UNLOCK();
}
*/
