/*
 * rtGetInf.h
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "Spike".
 *
 * Model version              : 1.155
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Sat Jul 11 03:25:26 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rtGetInf_h_
#define RTW_HEADER_rtGetInf_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern real_T rtGetInf(void);
  extern real32_T rtGetInfF(void);
  extern real_T rtGetMinusInf(void);
  extern real32_T rtGetMinusInfF(void);

#ifdef __cplusplus

}                                      /* extern "C" */
#endif
#endif                                 /* RTW_HEADER_rtGetInf_h_ */
