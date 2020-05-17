#ifndef APP_TASK_H
#define APP_TASK_H

#include "mtrif.h"

#ifndef ENBL_MOTOR_IDENT
#define APP_TASK_SLOG_TS (10)
#else
/* When motor identification is enabled, it is useful
 * to transmit data faster to capture fast dybamics. */
#define APP_TASK_SLOG_TS (1)
#endif

#define APP_TASK_SLOG_PRIO (2)
#define APP_TASK_SLOG_STACK_SIZE (100)

#define APP_TASK_500MS (500)
#define APP_TASK_500MS_PRIO (1)
#define APP_TASK_500MS_STACK_SIZE (100)

#define APP_TASK_MOTOR_CONTROL_TS (1)
#define APP_TASK_MOTOR_CONTROL_PRIO (3)
#define APP_TASK_MOTOR_CONTROL_STACK_SIZE (300)

void AppTask_SLog(void* params);

void AppTask_500ms(void* params);

void AppTask_MotorControl(void* params);

MtrIf_S* AppTask_GetMtrIf(void);

#endif // APP_TASK_H
