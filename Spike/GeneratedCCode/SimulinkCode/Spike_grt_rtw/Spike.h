/*
 * Spike.h
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "Spike".
 *
 * Model version              : 1.15
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Jun 11 22:59:49 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Spike_h_
#define RTW_HEADER_Spike_h_
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#ifndef Spike_COMMON_INCLUDES_
# define Spike_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Spike_COMMON_INCLUDES_ */

#include "Spike_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T buffer[65536];
} B_Spike_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  boolean_T eml_autoflush[20];         /* '<Root>/MATLAB Function1' */
  FILE * eml_openfiles[20];            /* '<Root>/MATLAB Function' */
  FILE * eml_openfiles_d[20];          /* '<Root>/MATLAB Function1' */
} DW_Spike_T;

/* Real-time Model Data Structure */
struct tag_RTM_Spike_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Spike_T Spike_B;

/* Block states (default storage) */
extern DW_Spike_T Spike_DW;

/* Model entry point functions */
extern void Spike_initialize(void);
extern void Spike_step(void);
extern void Spike_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Spike_T *const Spike_M;

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
 * '<Root>' : 'Spike'
 * '<S1>'   : 'Spike/MATLAB Function'
 * '<S2>'   : 'Spike/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_Spike_h_ */
