/*
 * ctrl.c
 *
 * Code generation for model "ctrl".
 *
 * Model version              : 1.252
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 *
 */

#include "ctrl.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Model step function */
void Trig_1Khz(void)
{
  real32_T rtb_Subtract_b;
  real32_T u0;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_1Khz_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Task_1khz'
   */
  /* Sum: '<S4>/Subtract' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain4'
   *  Gain: '<S3>/Gain1'
   *  Inport: '<Root>/MtrPos'
   *  Inport: '<Root>/MtrPosTgt'
   *  Sum: '<S3>/Add'
   *  Sum: '<S3>/Subtract'
   */
  rtb_Subtract_b = ((0.1F * rtU.MtrPosTgt - 0.1F * rtU.MtrPos) * 13.333333F +
                    rtDW.DiscreteTimeIntegrator_DSTATE_c) - rtDW.Add1;

  /* Sum: '<S4>/Add' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  Gain: '<S4>/Gain1'
   */
  u0 = 8.13814E-5F * rtb_Subtract_b + rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* Saturate: '<S1>/Saturation' */
  if (u0 > 2.0F) {
    u0 = 2.0F;
  } else {
    if (u0 < -2.0F) {
      u0 = -2.0F;
    }
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Outport: '<Root>/IfbkPhATgt' incorporates:
   *  Gain: '<S1>/Gain'
   */
  rtY.IfbkPhATgt = 1000.0F * u0;

  /* Outport: '<Root>/MtrSpd' incorporates:
   *  Gain: '<S1>/Gain1'
   *  SignalConversion: '<S1>/Signal Conversion'
   */
  rtY.MtrSpd = 10.0F * rtDW.Add1;

  /* Outport: '<Root>/MtrSpdFil' incorporates:
   *  Gain: '<S1>/Gain2'
   *  SignalConversion: '<S1>/Signal Conversion1'
   */
  rtY.MtrSpdFil = 10.0F * rtDW.SignalConversion;

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S4>/Gain'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += 0.000161220698F * rtb_Subtract_b *
    0.001F;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_1Khz_at_outport_1' */
}

/* Model step function */
void Trig_30Khz(void)
{
  real32_T rtb_Subtract_p;
  real32_T rtb_Sign;
  real32_T rtb_Add1;
  real32_T u0;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_30Khz_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Task_30khz'
   */
  /* Sum: '<S11>/Add' incorporates:
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
   *  Gain: '<S2>/Gain2'
   *  Inport: '<Root>/MtrPos'
   */
  rtb_Subtract_p = 0.1F * rtU.MtrPos - rtDW.DiscreteTimeIntegrator_DSTATE;

  /* Signum: '<S11>/Sign' */
  if (rtb_Subtract_p < 0.0F) {
    rtb_Sign = -1.0F;
  } else if (rtb_Subtract_p > 0.0F) {
    rtb_Sign = 1.0F;
  } else {
    rtb_Sign = rtb_Subtract_p;
  }

  /* End of Signum: '<S11>/Sign' */

  /* Sum: '<S11>/Add1' incorporates:
   *  Abs: '<S11>/Abs'
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S11>/Gain2'
   *  Product: '<S11>/Product'
   *  Sqrt: '<S11>/Sqrt'
   */
  rtDW.Add1 = sqrtf(fabsf(rtb_Subtract_p)) * rtb_Sign * 756.939819F + 630250.0F *
    rtDW.DiscreteTimeIntegrator_DSTATE_o;

  /* Sum: '<S10>/Add1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  UnitDelay: '<S10>/Unit Delay'
   */
  rtb_Add1 = rtDW.Add1 * 0.038500011F + 0.9615F * rtDW.UnitDelay_DSTATE;

  /* SignalConversion: '<S8>/Signal Conversion' */
  rtDW.SignalConversion = rtb_Add1;

  /* Sum: '<S7>/Subtract' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain4'
   *  Inport: '<Root>/IfbkPhA'
   *  Outport: '<Root>/IfbkPhATgt'
   */
  rtb_Subtract_p = 0.001F * rtY.IfbkPhATgt - 0.001F * rtU.IfbkPhA;

  /* Sum: '<S7>/Add' incorporates:
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
   *  Gain: '<S7>/Gain1'
   */
  u0 = 95.8F * rtb_Subtract_p + rtDW.DiscreteTimeIntegrator_DSTATE_f;

  /* Saturate: '<S2>/Saturation' */
  if (u0 > 12.0F) {
    u0 = 12.0F;
  } else {
    if (u0 < -12.0F) {
      u0 = -12.0F;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Outport: '<Root>/PwmChA' incorporates:
   *  Gain: '<S2>/Gain3'
   */
  rtY.PwmChA = 1000.0F * u0;

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 3.33333337E-5F * rtDW.Add1;

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_o += 3.33333337E-5F * rtb_Sign;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Add1;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S7>/Gain'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_f += 94539.0F * rtb_Subtract_p *
    3.33333337E-5F;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_30Khz_at_outport_1' */
}

/* Model initialize function */
void ctrl_initialize(void)
{
  /* (no initialization code required) */
}
