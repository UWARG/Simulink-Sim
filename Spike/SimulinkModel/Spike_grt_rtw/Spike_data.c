/*
 * Spike_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "Spike".
 *
 * Model version              : 1.83
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Sat Jun 13 21:57:13 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Spike.h"
#include "Spike_private.h"

/* Block parameters (default storage) */
P_Spike_T Spike_P = {
  /* Mask Parameter: uDOFEulerAngles_Vm_0
   * Referenced by: '<S1>/ub,vb,wb'
   */
  { 0.0, 0.0, 0.0 },

  /* Mask Parameter: uDOFEulerAngles_eul_0
   * Referenced by: '<S10>/phi theta psi'
   */
  { 0.0, 0.0, 0.0 },

  /* Mask Parameter: uDOFEulerAngles_inertia
   * Referenced by: '<S12>/Constant1'
   */
  { 0.003534, 0.0, 0.0, 0.0, 0.003788, 0.0, 0.0, 0.0, 0.005818 },

  /* Mask Parameter: uDOFEulerAngles_mass_0
   * Referenced by: '<S12>/Constant'
   */
  1.0,

  /* Mask Parameter: uDOFEulerAngles_pm_0
   * Referenced by: '<S1>/p,q,r '
   */
  { 0.0, 0.0, 0.0 },

  /* Mask Parameter: uDOFEulerAngles_xme_0
   * Referenced by: '<S1>/xe,ye,ze'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: pi
   * Referenced by: '<S10>/phi theta psi'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S10>/phi theta psi'
   */
  -3.1415926535897931,

  /* Expression: zeros(3)
   * Referenced by: '<S12>/Constant2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
};
