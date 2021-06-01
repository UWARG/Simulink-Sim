/*
 * Infinion_data.cpp
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

#include "Infinion.h"
#include "Infinion_private.h"

/* Block parameters (default storage) */
P_Infinion_T InfinionModelClass::Infinion_P = {
  /* Mask Parameter: FlatEarthtoLLA_LL0
   * Referenced by: '<S4>/ref_position'
   */
  { 0.0, 0.0 },

  /* Mask Parameter: uDOFEulerAngles_Vm_0
   * Referenced by: '<S1>/ub,vb,wb'
   */
  { 15.0, 0.0, 0.0 },

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S62>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_n
   * Referenced by: '<S60>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_c
   * Referenced by: '<S63>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_e
   * Referenced by: '<S56>/Constant'
   */
  180.0,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S54>/Constant'
   */
  90.0,

  /* Mask Parameter: CompareToConstant_const_h
   * Referenced by: '<S57>/Constant'
   */
  180.0,

  /* Mask Parameter: uDOFEulerAngles_eul_0
   * Referenced by: '<S19>/phi theta psi'
   */
  { 0.0, 0.0, 0.0 },

  /* Mask Parameter: uDOFEulerAngles_inertia
   * Referenced by: '<S21>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Mask Parameter: uDOFEulerAngles_mass_0
   * Referenced by: '<S21>/Constant'
   */
  1.0,

  /* Mask Parameter: uDOFEulerAngles_pm_0
   * Referenced by: '<S1>/p,q,r '
   */
  { 0.0, 0.0, 0.0 },

  /* Mask Parameter: FlatEarthtoLLA_psi
   * Referenced by: '<S4>/ref_rotation'
   */
  0.0,

  /* Mask Parameter: uDOFEulerAngles_xme_0
   * Referenced by: '<S1>/xe,ye,ze'
   */
  { 0.0, 0.0, -15.0 },

  /* Expression: -90
   * Referenced by: '<S52>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S52>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S52>/Bias1'
   */
  90.0,

  /* Expression: 180
   * Referenced by: '<S55>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S55>/Bias1'
   */
  -180.0,

  /* Expression: 180
   * Referenced by: '<S53>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S53>/Bias1'
   */
  -180.0,

  /* Expression: -90
   * Referenced by: '<S58>/Bias'
   */
  -90.0,

  /* Expression: -1
   * Referenced by: '<S58>/Gain'
   */
  -1.0,

  /* Expression: +90
   * Referenced by: '<S58>/Bias1'
   */
  90.0,

  /* Expression: 360
   * Referenced by: '<S61>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S61>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S61>/Bias1'
   */
  -180.0,

  /* Expression: 180
   * Referenced by: '<S49>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S49>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S59>/Constant2'
   */
  360.0,

  /* Expression: 180
   * Referenced by: '<S59>/Bias'
   */
  180.0,

  /* Expression: -180
   * Referenced by: '<S59>/Bias1'
   */
  -180.0,

  /* Expression: [0 0 0]
   * Referenced by: '<S72>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S71>/Constant'
   */
  0.0,

  /* Expression: -100
   * Referenced by: '<S71>/Gain'
   */
  -100.0,

  /* Expression: -1
   * Referenced by: '<S71>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S71>/Saturation'
   */
  0.0,

  /* Expression: -inf
   * Referenced by: '<S71>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S71>/Saturation1'
   */
  0.0,

  /* Expression: -inf
   * Referenced by: '<S71>/Saturation1'
   */
  0.0,

  /* Expression: 21.322
   * Referenced by: '<Root>/HNLLat'
   */
  21.322,

  /* Expression: 1
   * Referenced by: '<S64>/Constant2'
   */
  1.0,

  /* Expression: R
   * Referenced by: '<S64>/Constant1'
   */
  6.378137E+6,

  /* Expression: 1
   * Referenced by: '<S67>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S69>/Constant'
   */
  1.0,

  /* Expression: F
   * Referenced by: '<S68>/Constant'
   */
  0.0033528106647474805,

  /* Expression: 1
   * Referenced by: '<S68>/f'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S64>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S64>/Constant3'
   */
  1.0,

  /* Expression: 360
   * Referenced by: '<S55>/Constant2'
   */
  360.0,

  /* Expression: -157.924
   * Referenced by: '<Root>/HNLLong'
   */
  -157.924,

  /* Expression: 180
   * Referenced by: '<S48>/Constant'
   */
  180.0,

  /* Expression: 0
   * Referenced by: '<S48>/Constant1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S53>/Constant2'
   */
  360.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<S19>/phi theta psi'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S19>/phi theta psi'
   */
  -3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S44>/Constant'
   */
  0.0,

  /* Expression: [0 0 0]
   * Referenced by: '<S5>/Merge'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: zeros(3)
   * Referenced by: '<S21>/Constant2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
};
