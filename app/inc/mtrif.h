#ifndef _MTRIF_H_
#define _MTRIF_H_

#include <stdint.h>
#include "adc.h"
#include "app.h"
#include "cmsis_gcc.h"

#define MTRIF_POS_PH (PwmChA_E)
#define MTRIF_NEG_PH (PwmChC_E)

#define MTRIF_POS_PH_IFBK (IfbkPhA_E)
#define MTRIF_NEG_PH_IFBK (IfbkPhC_E)

/* Might need to add other interrupts that might share data. */
#define MTRIF_LOCK() __disable_irq()
#define MTRIF_UNLOCK() __enable_irq()

#define MTRIF_TS (1e3) /* Execution rate of Motor Interface. */

#define MTRIF_RPM_RES (1000) /* Represents a resolution of 0.001 RPM */

/* Transforms 0.1 deg/s to 0.001 RPM units */
#define MTRIF_TO_RPM ((60 * MTRIF_RPM_RES / (360 * (APP_PARAMS_POS_RES))))

typedef struct MtrIf {
  int32_t pos;
  int32_t postgt;
  int32_t spd;
  int32_t spdtgt;
  int32_t ifbk;
  int32_t ifbktgt;
  int32_t vin;
  uint8_t isarmed;
  uint8_t isrev;
} MtrIf_S;

void MtrIf_Init(MtrIf_S* mtrif);

void MtrIf_SetVin(MtrIf_S*, int32_t vin);

int32_t MtrIf_GetVin(void);

int32_t MtrIf_GetCurrent(void);

int32_t MtrIf_GetPos(MtrIf_S* mtrif);

int32_t MtrIf_GetPosTgt(MtrIf_S* mtrif);

void MtrIf_SetSpd(MtrIf_S* mtrif, int32_t spd);

int32_t MtrIf_GetSpd(MtrIf_S* mtrif);

void MtrIf_SetIfbkTgt(MtrIf_S* mtrif, int32_t itgt);

int32_t MtrIf_GetIfbkTgt(MtrIf_S* mtrif);

int32_t MtrIf_GetPosTgt(MtrIf_S* mtrif);

void MtrIf_SetPosTgt(MtrIf_S* mtrif, int32_t postgt);

//int32_t MtrIf_GetSpdTgt(MtrIf_S* mtrif);

//void MtrIf_SetSpdTgt(MtrIf_S* mtrif, int32_t spdtgt);

#endif // _MTRIF_H_
