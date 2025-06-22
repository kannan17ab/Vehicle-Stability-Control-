/*
 * File: Subsystem.h
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

#ifndef Subsystem_h_
#define Subsystem_h_
#ifndef Subsystem_COMMON_INCLUDES_
#define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

#include "Subsystem_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Wheel_Speed_FL;               /* '<Root>/Wheel_Speed_FL' */
  real_T Wheel_Speed_FR;               /* '<Root>/Wheel_Speed_FR' */
  real_T Wheel_Speed_RL;               /* '<Root>/Wheel_Speed_RL' */
  real_T Steering_Angle;               /* '<Root>/Steering_Angle' */
  real_T Vehicle_speed;                /* '<Root>/Vehicle_speed' */
  real_T Yaw_Rate;                     /* '<Root>/Yaw_Rate' */
} ExtU_Subsystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Brake_Pressure_FL;            /* '<Root>/•	Brake_Pressure_FL' */
  real_T Brake_Pressure_RL;            /* '<Root>/Brake_Pressure_RL' */
  real_T Brake_Pressure_FR;            /* '<Root>/Brake_Pressure_FR' */
  real_T Brake_Pressure_RR;            /* '<Root>/Brake_Pressure_RR' */
  boolean_T VSC_status;                /* '<Root>/VSC_status' */
  boolean_T Sensor_fault;              /* '<Root>/Sensor_fault' */
} ExtY_Subsystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_Subsystem_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Subsystem_T Subsystem_Y;

/* Model entry point functions */
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);
extern void Subsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Subsystem_T *const Subsystem_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Vehicle_stability_control/Subsystem')    - opens subsystem Vehicle_stability_control/Subsystem
 * hilite_system('Vehicle_stability_control/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Vehicle_stability_control'
 * '<S1>'   : 'Vehicle_stability_control/Subsystem'
 * '<S2>'   : 'Vehicle_stability_control/Subsystem/Sensor_inputs_and_preprocessing'
 * '<S3>'   : 'Vehicle_stability_control/Subsystem/Stability_Control_Logic'
 * '<S4>'   : 'Vehicle_stability_control/Subsystem/Stability_Control_Logic/Compare To Constant'
 * '<S5>'   : 'Vehicle_stability_control/Subsystem/Stability_Control_Logic/Compare To Constant1'
 * '<S6>'   : 'Vehicle_stability_control/Subsystem/Stability_Control_Logic/Compare To Constant2'
 * '<S7>'   : 'Vehicle_stability_control/Subsystem/Stability_Control_Logic/Compare To Constant3'
 */
#endif                                 /* Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
