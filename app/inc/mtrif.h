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

void MtrIf_SetVin(int32_t vin);

int32_t MtrIf_GetVin(void);

int32_t MtrIf_GetIfbk(void);

int32_t MtrIf_GetPos(void);

int32_t MtrIf_GetSpd(void);

void MtrIf_Ctl(void);

#endif // _MTRIF_H_
