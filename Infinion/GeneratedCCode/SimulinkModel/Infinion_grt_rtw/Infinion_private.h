/*
 * Infinion_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Infinion".
 *
 * Model version              : 3.11
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Thu Apr 29 17:54:18 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Infinion_private_h_
#define RTW_HEADER_Infinion_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern void rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(const real_T u0[3], const real_T u1
  [9], real_T y[3]);
extern int32_T plook_s32dd_binxp(real_T u, const real_T bp[], uint32_T maxIndex,
  real_T *fraction, int32_T *prevIndex);
extern real_T intrp3d_s32dl_pw(const int32_T bpIndex[], const real_T frac[],
  const real_T table[], const uint32_T stride[]);
extern real_T intrp4d_s32dl_pw(const int32_T bpIndex[], const real_T frac[],
  const real_T table[], const uint32_T stride[]);
extern int32_T binsearch_s32d_prevIdx(real_T u, const real_T bp[], uint32_T
  startIndex, uint32_T maxIndex);

/* private model entry point functions */
extern void Infinion_derivatives();

#endif                                 /* RTW_HEADER_Infinion_private_h_ */
