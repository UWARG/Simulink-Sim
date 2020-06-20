/*
 * Spike_types.h
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "Spike".
 *
 * Model version              : 1.84
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Fri Jun 19 23:11:26 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Spike_types_h_
#define RTW_HEADER_Spike_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Custom Type definition for MATLAB Function: '<Root>/WriteToFile' */
#include <stdio.h>

/* Custom Type definition for MATLAB Function: '<Root>/Read Throttle' */
#include <stdio.h>

/* Custom Type definition for MATLAB Function: '<Root>/WriteToFile' */
#ifndef struct_tag_sL6LJlPlxhdTxZzXh5NTaQC
#define struct_tag_sL6LJlPlxhdTxZzXh5NTaQC

struct tag_sL6LJlPlxhdTxZzXh5NTaQC
{
  int32_T intNumBits;
};

#endif                                 /*struct_tag_sL6LJlPlxhdTxZzXh5NTaQC*/

#ifndef typedef_sL6LJlPlxhdTxZzXh5NTaQC_Spike_T
#define typedef_sL6LJlPlxhdTxZzXh5NTaQC_Spike_T

typedef struct tag_sL6LJlPlxhdTxZzXh5NTaQC sL6LJlPlxhdTxZzXh5NTaQC_Spike_T;

#endif                                 /*typedef_sL6LJlPlxhdTxZzXh5NTaQC_Spike_T*/

/* Custom Type definition for MATLAB Function: '<Root>/Read Throttle' */
#ifndef struct_tag_su2dYx4D5wygFoF57GWu6uG
#define struct_tag_su2dYx4D5wygFoF57GWu6uG

struct tag_su2dYx4D5wygFoF57GWu6uG
{
  int32_T charSize;
  int32_T shortSize;
  int32_T intSize;
  int32_T longSize;
  int32_T longlongSize;
};

#endif                                 /*struct_tag_su2dYx4D5wygFoF57GWu6uG*/

#ifndef typedef_su2dYx4D5wygFoF57GWu6uG_Spike_T
#define typedef_su2dYx4D5wygFoF57GWu6uG_Spike_T

typedef struct tag_su2dYx4D5wygFoF57GWu6uG su2dYx4D5wygFoF57GWu6uG_Spike_T;

#endif                                 /*typedef_su2dYx4D5wygFoF57GWu6uG_Spike_T*/

#include <stddef.h>
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

#ifndef typedef_emxArray_char_T_Spike_T
#define typedef_emxArray_char_T_Spike_T

typedef struct emxArray_char_T emxArray_char_T_Spike_T;

#endif                                 /*typedef_emxArray_char_T_Spike_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T_Spike_T
#define typedef_emxArray_boolean_T_Spike_T

typedef struct emxArray_boolean_T emxArray_boolean_T_Spike_T;

#endif                                 /*typedef_emxArray_boolean_T_Spike_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T_Spike_T
#define typedef_emxArray_int32_T_Spike_T

typedef struct emxArray_int32_T emxArray_int32_T_Spike_T;

#endif                                 /*typedef_emxArray_int32_T_Spike_T*/

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint8_T*/

#ifndef typedef_emxArray_uint8_T_Spike_T
#define typedef_emxArray_uint8_T_Spike_T

typedef struct emxArray_uint8_T emxArray_uint8_T_Spike_T;

#endif                                 /*typedef_emxArray_uint8_T_Spike_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T_Spike_T
#define typedef_emxArray_real_T_Spike_T

typedef struct emxArray_real_T emxArray_real_T_Spike_T;

#endif                                 /*typedef_emxArray_real_T_Spike_T*/

/* Parameters (default storage) */
typedef struct P_Spike_T_ P_Spike_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Spike_T RT_MODEL_Spike_T;

#endif                                 /* RTW_HEADER_Spike_types_h_ */
