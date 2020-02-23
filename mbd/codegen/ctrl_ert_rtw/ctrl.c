/*
 * ctrl.c
 *
 * Code generation for model "ctrl".
 *
 * Model version              : 1.332
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
  real32_T rtb_Add1_o;
  real32_T rtb_Add_iu;
  real32_T rtb_Sign_nw;
  real32_T rtb_Gain_g;
  real32_T DiscreteTimeIntegrator;
  real32_T u;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_1Khz_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Task_1khz'
   */
  /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE_m;

  /* Sum: '<S8>/Subtract' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S7>/Gain1'
   *  Inport: '<Root>/MtrPos'
   *  Sum: '<S5>/Add'
   *  Sum: '<S7>/Add'
   *  Sum: '<S7>/Subtract'
   */
  rtb_Add_iu = (((rtDW.DiscreteTimeIntegrator1_DSTAT_f - 0.1F * rtU.MtrPos) *
                 13.333333F + rtDW.DiscreteTimeIntegrator_DSTATE_c) +
                rtDW.DiscreteTimeIntegrator_DSTATE_m) - rtDW.Add1;

  /* Sum: '<S8>/Add' incorporates:
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
   *  Gain: '<S8>/Gain1'
   */
  rtb_Gain_g = 8.13814E-5F * rtb_Add_iu + rtDW.DiscreteTimeIntegrator_DSTATE_a;

  /* Saturate: '<S4>/Saturation' */
  if (rtb_Gain_g > 2.0F) {
    rtb_Gain_g = 2.0F;
  } else {
    if (rtb_Gain_g < -2.0F) {
      rtb_Gain_g = -2.0F;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Outport: '<Root>/IfbkPhATgt' incorporates:
   *  Gain: '<S4>/Gain'
   */
  rtY.IfbkPhATgt = 1000.0F * rtb_Gain_g;

  /* Outport: '<Root>/MtrSpd' incorporates:
   *  Gain: '<S4>/Gain1'
   *  SignalConversion: '<S1>/Signal Conversion'
   */
  rtY.MtrSpd = 10.0F * rtDW.Add1;

  /* Outport: '<Root>/MtrSpdFil' incorporates:
   *  Gain: '<S4>/Gain2'
   *  SignalConversion: '<S1>/Signal Conversion1'
   */
  rtY.MtrSpdFil = 10.0F * rtDW.SignalConversion;

  /* Outport: '<Root>/MtrDisEst' incorporates:
   *  Gain: '<S4>/Gain3'
   *  SignalConversion: '<S1>/Signal Conversion2'
   */
  rtY.MtrDisEst = 1.0E+6F * rtDW.Gain5;

  /* Outport: '<Root>/MtrPosEst' incorporates:
   *  Gain: '<S4>/Gain4'
   *  SignalConversion: '<S1>/Signal Conversion3'
   */
  rtY.MtrPosEst = 10.0F * rtDW.Gain;

  /* Gain: '<S8>/Gain' */
  rtb_Gain_g = 0.000161220698F * rtb_Add_iu;

  /* Outport: '<Root>/MtrPosRef' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
   *  SignalConversion: '<S1>/OutportBufferForMtrPosRef'
   */
  rtY.MtrPosRef = rtDW.DiscreteTimeIntegrator1_DSTAT_f;

  /* Gain: '<S11>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   */
  rtb_Sign_nw = 0.001F * rtDW.DiscreteTimeIntegrator_DSTATE_m;

  /* Sum: '<S11>/Add8' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
   *  Gain: '<S3>/Gain1'
   *  Inport: '<Root>/MtrPosTgt'
   *  Sum: '<S6>/Add'
   */
  rtb_Add_iu = (rtDW.DiscreteTimeIntegrator1_DSTAT_f - 0.1F * rtU.MtrPosTgt) +
    rtb_Sign_nw;

  /* Signum: '<S13>/Sign' */
  if (rtb_Add_iu < 0.0F) {
    rtb_Add1_o = -1.0F;
  } else if (rtb_Add_iu > 0.0F) {
    rtb_Add1_o = 1.0F;
  } else {
    rtb_Add1_o = rtb_Add_iu;
  }

  /* End of Signum: '<S13>/Sign' */

  /* Sum: '<S13>/Add1' incorporates:
   *  Abs: '<S12>/Abs'
   *  Constant: '<S11>/d'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S13>/Gain'
   *  Product: '<S12>/Product'
   *  Product: '<S13>/Product'
   *  Sqrt: '<S12>/Sqrt'
   *  Sum: '<S12>/Add'
   *  Sum: '<S13>/Add'
   */
  rtb_Add1_o = (sqrtf((8.0F * fabsf(rtb_Add_iu) + 0.01F) * 0.01F) - 0.01F) *
    rtb_Add1_o * 0.5F + rtb_Sign_nw;

  /* Sum: '<S14>/Add1' */
  rtb_Sign_nw = (rtb_Sign_nw + rtb_Add_iu) - rtb_Add1_o;

  /* Sum: '<S17>/Add1' incorporates:
   *  Constant: '<S11>/d'
   */
  u = 0.01F + rtb_Add_iu;

  /* Sum: '<S17>/Add2' incorporates:
   *  Constant: '<S11>/d'
   */
  rtb_Add_iu -= 0.01F;

  /* Signum: '<S17>/Sign' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* End of Signum: '<S17>/Sign' */

  /* Signum: '<S17>/Sign1' */
  if (rtb_Add_iu < 0.0F) {
    rtb_Add_iu = -1.0F;
  } else {
    if (rtb_Add_iu > 0.0F) {
      rtb_Add_iu = 1.0F;
    }
  }

  /* End of Signum: '<S17>/Sign1' */

  /* Sum: '<S14>/Add2' incorporates:
   *  Gain: '<S17>/Gain1'
   *  Product: '<S14>/Product'
   *  Sum: '<S17>/Add'
   */
  rtb_Add1_o += (u - rtb_Add_iu) * 0.5F * rtb_Sign_nw;

  /* Signum: '<S15>/Sign' */
  if (rtb_Add1_o < 0.0F) {
    rtb_Sign_nw = -1.0F;
  } else if (rtb_Add1_o > 0.0F) {
    rtb_Sign_nw = 1.0F;
  } else {
    rtb_Sign_nw = rtb_Add1_o;
  }

  /* End of Signum: '<S15>/Sign' */

  /* Sum: '<S15>/Add' incorporates:
   *  Constant: '<S11>/d'
   *  Product: '<S15>/Divide'
   */
  rtb_Add_iu = rtb_Add1_o / 0.01F - rtb_Sign_nw;

  /* Sum: '<S16>/Add' incorporates:
   *  Constant: '<S11>/d'
   */
  u = rtb_Add1_o + 0.01F;

  /* Sum: '<S16>/Add1' incorporates:
   *  Constant: '<S11>/d'
   */
  rtb_Add1_o -= 0.01F;

  /* Signum: '<S16>/Sign' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* End of Signum: '<S16>/Sign' */

  /* Signum: '<S16>/Sign1' */
  if (rtb_Add1_o < 0.0F) {
    rtb_Add1_o = -1.0F;
  } else {
    if (rtb_Add1_o > 0.0F) {
      rtb_Add1_o = 1.0F;
    }
  }

  /* End of Signum: '<S16>/Sign1' */

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S15>/Gain'
   *  Gain: '<S16>/Gain'
   *  Product: '<S15>/Product'
   *  Sum: '<S15>/Add1'
   *  Sum: '<S16>/Add2'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_m += ((u - rtb_Add1_o) * 0.5F * rtb_Add_iu
    + rtb_Sign_nw) * -10000.0F * 0.001F;

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */
  rtDW.DiscreteTimeIntegrator1_DSTAT_f += 0.001F * DiscreteTimeIntegrator;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_a += 0.001F * rtb_Gain_g;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_1Khz_at_outport_1' */
}

/* Model step function */
void Trig_30Khz(void)
{
  real32_T rtb_Sqrt;
  real32_T rtb_DiscreteTimeIntegrator_d;
  Ifbk rtb_Gain1;
  real32_T rtb_Gain4;
  real32_T rtb_Gain2;
  real32_T rtb_Add;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_30Khz_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Task_30khz'
   */
  /* Gain: '<S2>/Gain4' incorporates:
   *  Outport: '<Root>/IfbkPhATgt'
   */
  rtb_Sqrt = 0.001F * rtY.IfbkPhATgt;

  /* Gain: '<S18>/Gain5' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   */
  rtDW.Gain5 = 3.10127E-6F * rtDW.DiscreteTimeIntegrator_DSTATE;

  /* Sum: '<S2>/Add' incorporates:
   *  Gain: '<S2>/Gain5'
   */
  rtb_Add = rtb_Sqrt - 9.64413166F * rtDW.Gain5;

  /* Gain: '<S2>/Gain2' incorporates:
   *  Inport: '<Root>/MtrPos'
   */
  rtb_DiscreteTimeIntegrator_d = 0.1F * rtU.MtrPos;

  /* Gain: '<S22>/Gain' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator2'
   */
  rtDW.Gain = 57.2957802F * rtDW.DiscreteTimeIntegrator2_DSTATE;

  /* Gain: '<S18>/Gain1' */
  rtb_Gain1 = 33434.6914F * rtb_Sqrt;

  /* Gain: '<S21>/Gain1' incorporates:
   *  Sum: '<S18>/Add'
   */
  rtb_Sqrt = (rtDW.Gain - rtb_DiscreteTimeIntegrator_d) * 0.0174532924F;

  /* Sum: '<S18>/Add2' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  Gain: '<S18>/Gain3'
   */
  rtb_Gain1 = (-250000.0F * rtb_Sqrt + rtb_Gain1) +
    rtDW.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<S18>/Gain4' */
  rtb_Gain4 = -800.0F * rtb_Sqrt;

  /* Gain: '<S18>/Gain2' */
  rtb_Gain2 = -2.5E+7F * rtb_Sqrt;

  /* Sum: '<S19>/Subtract' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Inport: '<Root>/IfbkPhA'
   */
  rtb_Sqrt = rtb_Add - 0.001F * rtU.IfbkPhA;

  /* Sum: '<S19>/Add' incorporates:
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
   *  Gain: '<S19>/Gain1'
   */
  rtb_Add = 95.8F * rtb_Sqrt + rtDW.DiscreteTimeIntegrator_DSTATE_f;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Add > 12.0F) {
    rtb_Add = 12.0F;
  } else {
    if (rtb_Add < -12.0F) {
      rtb_Add = -12.0F;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Outport: '<Root>/PwmChA' incorporates:
   *  Gain: '<S2>/Gain3'
   */
  rtY.PwmChA = 1000.0F * rtb_Add;

  /* Sum: '<S25>/Add' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_d -= rtDW.DiscreteTimeIntegrator_DSTATE_j;

  /* Signum: '<S25>/Sign' */
  if (rtb_DiscreteTimeIntegrator_d < 0.0F) {
    rtb_Add = -1.0F;
  } else if (rtb_DiscreteTimeIntegrator_d > 0.0F) {
    rtb_Add = 1.0F;
  } else {
    rtb_Add = rtb_DiscreteTimeIntegrator_d;
  }

  /* End of Signum: '<S25>/Sign' */

  /* Sum: '<S25>/Add1' incorporates:
   *  Abs: '<S25>/Abs'
   *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
   *  Gain: '<S25>/Gain1'
   *  Gain: '<S25>/Gain2'
   *  Product: '<S25>/Product'
   *  Sqrt: '<S25>/Sqrt'
   */
  rtDW.Add1 = sqrtf(fabsf(rtb_DiscreteTimeIntegrator_d)) * rtb_Add * 756.939819F
    + 630250.0F * rtDW.DiscreteTimeIntegrator_DSTATE_o;

  /* Sum: '<S24>/Add1' incorporates:
   *  Constant: '<S24>/Constant'
   *  Product: '<S24>/Product'
   *  Product: '<S24>/Product1'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  rtb_DiscreteTimeIntegrator_d = rtDW.Add1 * 0.038500011F + 0.9615F *
    rtDW.UnitDelay_DSTATE;

  /* SignalConversion: '<S20>/Signal Conversion' */
  rtDW.SignalConversion = rtb_DiscreteTimeIntegrator_d;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 3.33333337E-5F * rtb_Gain2;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
   *  Sum: '<S18>/Add3'
   */
  rtDW.DiscreteTimeIntegrator2_DSTATE += (rtb_Gain4 +
    rtDW.DiscreteTimeIntegrator1_DSTATE) * 3.33333337E-5F;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' */
  rtDW.DiscreteTimeIntegrator1_DSTATE += 3.33333337E-5F * rtb_Gain1;

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S19>/Gain'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE_f += 94539.0F * rtb_Sqrt * 3.33333337E-5F;

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_j += 3.33333337E-5F * rtDW.Add1;

  /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE_o += 3.33333337E-5F * rtb_Add;

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_DiscreteTimeIntegrator_d;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_30Khz_at_outport_1' */
}

/* Model initialize function */
void ctrl_initialize(void)
{
  /* (no initialization code required) */
}
