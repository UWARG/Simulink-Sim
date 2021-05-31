/*
 * Infinion_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Infinion".
 *
 * Model version              : 3.121
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Mon May 31 17:44:15 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Infinion_types_h_
#define RTW_HEADER_Infinion_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */

/* Custom Type definition for MATLAB Function: '<Root>/WriteToFile' */
#include <stdio.h>

/* Custom Type definition for MATLAB Function: '<Root>/Read Throttle' */
#include <stdio.h>
#ifndef struct_emxArray_char_T_Infinion_T
#define struct_emxArray_char_T_Infinion_T

struct emxArray_char_T_Infinion_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T_Infinion_T */

#ifndef struct_emxArray_boolean_T_Infinion_T
#define struct_emxArray_boolean_T_Infinion_T

struct emxArray_boolean_T_Infinion_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                /* struct_emxArray_boolean_T_Infinion_T */

#ifndef struct_emxArray_real_T_Infinion_T
#define struct_emxArray_real_T_Infinion_T

struct emxArray_real_T_Infinion_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_real_T_Infinion_T */

#ifndef struct_emxArray_uint8_T_Infinion_T
#define struct_emxArray_uint8_T_Infinion_T

struct emxArray_uint8_T_Infinion_T
{
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_uint8_T_Infinion_T */

/* Parameters (default storage) */
typedef struct P_Infinion_T_ P_Infinion_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Infinion_T RT_MODEL_Infinion_T;

#endif                                 /* RTW_HEADER_Infinion_types_h_ */
