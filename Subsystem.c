/*
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Jun 22 14:42:49 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subsystem.h"
#include <math.h>
#include "rtwtypes.h"

/* External inputs (root inport signals with default storage) */
ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Subsystem_T Subsystem_Y;

/* Real-time model */
static RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;

/* Model step function */
void Subsystem_step(void)
{
  real_T rtb_Add2;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_d;
  boolean_T rtb_Compare_l;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator3;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Sum: '<S2>/Add2' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Inport: '<Root>/Steering_Angle'
   *  Inport: '<Root>/Vehicle_speed'
   *  Inport: '<Root>/Yaw_Rate'
   *  Product: '<S2>/Divide'
   *  Product: '<S2>/Product'
   */
  rtb_Add2 = Subsystem_U.Steering_Angle * Subsystem_U.Vehicle_speed / 2.5 -
    Subsystem_U.Yaw_Rate;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Compare = (rtb_Add2 < -5.0);

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   */
  rtb_Compare_l = (rtb_Add2 > 5.0);

  /* Logic: '<S3>/Logical Operator' */
  Subsystem_Y.VSC_status = (rtb_Compare || rtb_Compare_l);

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/Steering_Angle'
   */
  rtb_Compare_d = (Subsystem_U.Steering_Angle < 0.0);

  /* Logic: '<S3>/Logical Operator3' */
  rtb_LogicalOperator3 = (rtb_Compare_l && rtb_Compare_d);

  /* Logic: '<S3>/Logical Operator1' */
  rtb_LogicalOperator1 = (rtb_Compare && rtb_Compare_d);

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/Steering_Angle'
   */
  rtb_Compare_d = (Subsystem_U.Steering_Angle > 0.0);

  /* Switch: '<S3>/Switch' incorporates:
   *  Logic: '<S3>/Logical Operator2'
   */
  if (rtb_Compare && rtb_Compare_d) {
    /* Outport: '<Root>/•	Brake_Pressure_FL' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    Subsystem_Y.Brake_Pressure_FL = 100.0;
  } else {
    /* Outport: '<Root>/•	Brake_Pressure_FL' incorporates:
     *  Constant: '<S3>/Constant3'
     */
    Subsystem_Y.Brake_Pressure_FL = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Switch: '<S3>/Switch1' */
  if (rtb_LogicalOperator1) {
    /* Outport: '<Root>/Brake_Pressure_RL' incorporates:
     *  Constant: '<S3>/Constant'
     */
    Subsystem_Y.Brake_Pressure_RL = 100.0;
  } else {
    /* Outport: '<Root>/Brake_Pressure_RL' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    Subsystem_Y.Brake_Pressure_RL = 0.0;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Switch: '<S3>/Switch2' */
  if (rtb_LogicalOperator3) {
    /* Outport: '<Root>/Brake_Pressure_FR' incorporates:
     *  Constant: '<S3>/Constant'
     */
    Subsystem_Y.Brake_Pressure_FR = 100.0;
  } else {
    /* Outport: '<Root>/Brake_Pressure_FR' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    Subsystem_Y.Brake_Pressure_FR = 0.0;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* Switch: '<S3>/Switch3' incorporates:
   *  Logic: '<S3>/Logical Operator4'
   */
  if (rtb_Compare_l && rtb_Compare_d) {
    /* Outport: '<Root>/Brake_Pressure_RR' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    Subsystem_Y.Brake_Pressure_RR = 100.0;
  } else {
    /* Outport: '<Root>/Brake_Pressure_RR' incorporates:
     *  Constant: '<S3>/Constant3'
     */
    Subsystem_Y.Brake_Pressure_RR = 0.0;
  }

  /* End of Switch: '<S3>/Switch3' */

  /* Outport: '<Root>/Sensor_fault' incorporates:
   *  Abs: '<S2>/Abs'
   *  Abs: '<S2>/Abs1'
   *  Constant: '<S1>/Wheel_Speed_RR'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/Wheel_Speed_FL'
   *  Inport: '<Root>/Wheel_Speed_FR'
   *  Inport: '<Root>/Wheel_Speed_RL'
   *  Logic: '<S2>/Logical Operator'
   *  Logic: '<S3>/Logical Operator5'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  RelationalOperator: '<S2>/Relational Operator1'
   *  Sum: '<S2>/Add'
   *  Sum: '<S2>/Add1'
   */
  Subsystem_Y.Sensor_fault = ((fabs(Subsystem_U.Wheel_Speed_FL -
    Subsystem_U.Wheel_Speed_FR) >= 5.0) || (fabs(Subsystem_U.Wheel_Speed_RL -
    50.0) >= 5.0)) ^ Subsystem_Y.VSC_status;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
