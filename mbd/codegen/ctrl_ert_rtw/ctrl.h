/*
 * ctrl.h
 *
 * Code generation for model "ctrl".
 *
 * Model version              : 1.332
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
  real32_T Gain5;                      /* '<S18>/Gain5' */
  real32_T Gain;                       /* '<S22>/Gain' */
  real32_T Add1;                       /* '<S25>/Add1' */
  real32_T SignalConversion;           /* '<S20>/Signal Conversion' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S18>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S18>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S18>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S23>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_j;/* '<S27>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_o;/* '<S26>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S24>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S6>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_f;/* '<S6>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S9>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S10>/Discrete-Time Integrator' */
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
  real32_T MtrPosRef;                  /* '<Root>/MtrPosRef' */
  real32_T MtrDisEst;                  /* '<Root>/MtrDisEst' */
  real32_T MtrPosEst;                  /* '<Root>/MtrPosEst' */
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
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<S3>'   : 'ctrl/Task_1khz/Iface_In'
 * '<S4>'   : 'ctrl/Task_1khz/Iface_Out'
 * '<S5>'   : 'ctrl/Task_1khz/MtrCtrl'
 * '<S6>'   : 'ctrl/Task_1khz/TrackDiff'
 * '<S7>'   : 'ctrl/Task_1khz/MtrCtrl/PosCtrl'
 * '<S8>'   : 'ctrl/Task_1khz/MtrCtrl/SpdCtrl'
 * '<S9>'   : 'ctrl/Task_1khz/MtrCtrl/PosCtrl/Integrator'
 * '<S10>'  : 'ctrl/Task_1khz/MtrCtrl/SpdCtrl/Integrator'
 * '<S11>'  : 'ctrl/Task_1khz/TrackDiff/fhan'
 * '<S12>'  : 'ctrl/Task_1khz/TrackDiff/fhan/a1_calc'
 * '<S13>'  : 'ctrl/Task_1khz/TrackDiff/fhan/a2_calc'
 * '<S14>'  : 'ctrl/Task_1khz/TrackDiff/fhan/a_calc'
 * '<S15>'  : 'ctrl/Task_1khz/TrackDiff/fhan/fhan_calc'
 * '<S16>'  : 'ctrl/Task_1khz/TrackDiff/fhan/sa_calc'
 * '<S17>'  : 'ctrl/Task_1khz/TrackDiff/fhan/sy_calc'
 * '<S18>'  : 'ctrl/Task_30khz/DistObs'
 * '<S19>'  : 'ctrl/Task_30khz/IfbkCtrl'
 * '<S20>'  : 'ctrl/Task_30khz/SpeedObserver'
 * '<S21>'  : 'ctrl/Task_30khz/DistObs/Degrees to Radians'
 * '<S22>'  : 'ctrl/Task_30khz/DistObs/Radians to Degrees'
 * '<S23>'  : 'ctrl/Task_30khz/IfbkCtrl/Integrator'
 * '<S24>'  : 'ctrl/Task_30khz/SpeedObserver/D-1LPF'
 * '<S25>'  : 'ctrl/Task_30khz/SpeedObserver/SM-Differentiator'
 * '<S26>'  : 'ctrl/Task_30khz/SpeedObserver/SM-Differentiator/Integrator'
 * '<S27>'  : 'ctrl/Task_30khz/SpeedObserver/SM-Differentiator/Integrator1'
 */
#endif                                 /* RTW_HEADER_ctrl_h_ */
