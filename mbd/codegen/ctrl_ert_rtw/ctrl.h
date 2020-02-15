/*
 * ctrl.h
 *
 * Code generation for model "ctrl".
 *
 * Model version              : 1.252
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 *
 */

#ifndef RTW_HEADER_ctrl_h_
#define RTW_HEADER_ctrl_h_
#include "rtwtypes.h"
#include <math.h>
#include <stddef.h>
#ifndef ctrl_COMMON_INCLUDES_
# define ctrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ctrl_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef DEFINED_TYPEDEF_FOR_Ifbk_
#define DEFINED_TYPEDEF_FOR_Ifbk_

typedef real32_T Ifbk;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Degs_s_
#define DEFINED_TYPEDEF_FOR_Degs_s_

typedef real32_T Degs_s;

#endif

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Add1;                       /* '<S11>/Add1' */
  real32_T SignalConversion;           /* '<S8>/Signal Conversion' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S13>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_o;/* '<S12>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S10>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S9>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S5>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S6>/Discrete-Time Integrator' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T MtrPos;                     /* '<Root>/MtrPos' */
  real32_T MtrPosTgt;                  /* '<Root>/MtrPosTgt' */
  real32_T IfbkPhA;                    /* '<Root>/IfbkPhA' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T PwmChA;                     /* '<Root>/PwmChA' */
  real32_T MtrSpd;                     /* '<Root>/MtrSpd' */
  real32_T MtrSpdFil;                  /* '<Root>/MtrSpdFil' */
  Ifbk IfbkPhATgt;                     /* '<Root>/IfbkPhATgt' */
} ExtY;

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void ctrl_initialize(void);

/* Exported entry point functions */
extern void Trig_1Khz(void);

/* Exported entry point functions */
extern void Trig_30Khz(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ctrl'
 * '<S1>'   : 'ctrl/Task_1khz'
 * '<S2>'   : 'ctrl/Task_30khz'
 * '<S3>'   : 'ctrl/Task_1khz/PosCtrl'
 * '<S4>'   : 'ctrl/Task_1khz/SpdCtrl'
 * '<S5>'   : 'ctrl/Task_1khz/PosCtrl/Integrator'
 * '<S6>'   : 'ctrl/Task_1khz/SpdCtrl/Integrator'
 * '<S7>'   : 'ctrl/Task_30khz/IfbkCtrl'
 * '<S8>'   : 'ctrl/Task_30khz/SpeedObserver'
 * '<S9>'   : 'ctrl/Task_30khz/IfbkCtrl/Integrator'
 * '<S10>'  : 'ctrl/Task_30khz/SpeedObserver/D-1LPF'
 * '<S11>'  : 'ctrl/Task_30khz/SpeedObserver/SM-Differentiator'
 * '<S12>'  : 'ctrl/Task_30khz/SpeedObserver/SM-Differentiator/Integrator'
 * '<S13>'  : 'ctrl/Task_30khz/SpeedObserver/SM-Differentiator/Integrator1'
 */
#endif                                 /* RTW_HEADER_ctrl_h_ */
