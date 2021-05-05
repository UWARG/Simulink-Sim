/*
 * Infinion.h
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

#ifndef RTW_HEADER_Infinion_h_
#define RTW_HEADER_Infinion_h_
#include <cstring>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Infinion_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
struct B_Infinion_T {
  uint8_T buffer[65536];
  uint8_T buffer_m[65536];
  uint8_T buffer_c[65536];
  uint8_T buffer_k[65536];
  real_T SinCos_o1;                    /* '<S103>/SinCos' */
  real_T SinCos_o2;                    /* '<S103>/SinCos' */
  real_T Switch;                       /* '<S111>/Switch' */
  real_T TrigonometricFunction1;       /* '<S117>/Trigonometric Function1' */
  real_T TrigonometricFunction2;       /* '<S117>/Trigonometric Function2' */
  real_T Switch_i;                     /* '<S112>/Switch' */
  real_T fdelL;                        /* '<S2>/(deltal)' */
  real_T fde;                          /* '<S2>/(delta)' */
  real_T fdelR;                        /* '<S2>/(deltaR)' */
  real_T VectorConcatenate[9];         /* '<S90>/Vector Concatenate' */
  real_T VectorConcatenate_m[9];       /* '<S60>/Vector Concatenate' */
  real_T Selector1[9];                 /* '<S19>/Selector1' */
  real_T Selector[9];                  /* '<S19>/Selector' */
  real_T Selector2[9];                 /* '<S19>/Selector2' */
  real_T Product2[3];                  /* '<S19>/Product2' */
  real_T Product[3];                   /* '<S25>/Product' */
  real_T VectorConcatenate_n[9];       /* '<S75>/Vector Concatenate' */
  real_T Sum[3];                       /* '<S1>/Sum' */
  real_T TmpSignalConversionAtphithetaps[3];/* '<S18>/phidot thetadot psidot' */
  real_T forces[3];                    /* '<Root>/propulsion' */
  int32_T idxdelL;                     /* '<S2>/(deltal)' */
  int32_T idxde;                       /* '<S2>/(delta)' */
  int32_T idxdelR;                     /* '<S2>/(deltaR)' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_Infinion_T {
  real_T Product2_DWORK4[9];           /* '<S19>/Product2' */
  int32_T deltal_DWORK1;               /* '<S2>/(deltal)' */
  int32_T Mach_DWORK1;                 /* '<S2>/(Mach)' */
  int32_T altitude_DWORK1;             /* '<S2>/(altitude)' */
  int32_T alpha_DWORK1;                /* '<S2>/(alpha)' */
  int32_T delta_DWORK1;                /* '<S2>/(delta)' */
  int32_T deltaR_DWORK1;               /* '<S2>/(deltaR)' */
  int32_T alpha_DWORK1_n;              /* '<Root>/(alpha)' */
  int32_T Mach_DWORK1_m;               /* '<Root>/(Mach)' */
  int32_T altitude_DWORK1_p;           /* '<Root>/(altitude)' */
  boolean_T eml_autoflush[20];         /* '<Root>/WriteToFile' */
  FILE * eml_openfiles[20];            /* '<Root>/Read Aileron' */
  FILE * eml_openfiles_m[20];          /* '<Root>/Read Elevator' */
  FILE * eml_openfiles_o[20];          /* '<Root>/Read Rudder' */
  FILE * eml_openfiles_h[20];          /* '<Root>/Read Throttle' */
  FILE * eml_openfiles_i[20];          /* '<Root>/WriteToFile' */
};

/* Continuous states (default storage) */
struct X_Infinion_T {
  real_T ubvbwb_CSTATE[3];             /* '<S1>/ub,vb,wb' */
  real_T xeyeze_CSTATE[3];             /* '<S1>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S18>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S1>/p,q,r ' */
};

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_Infinion_T[3];
typedef real_T PeriodicRngX_Infinion_T[6];

/* State derivatives (default storage) */
struct XDot_Infinion_T {
  real_T ubvbwb_CSTATE[3];             /* '<S1>/ub,vb,wb' */
  real_T xeyeze_CSTATE[3];             /* '<S1>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S18>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S1>/p,q,r ' */
};

/* State disabled  */
struct XDis_Infinion_T {
  boolean_T ubvbwb_CSTATE[3];          /* '<S1>/ub,vb,wb' */
  boolean_T xeyeze_CSTATE[3];          /* '<S1>/xe,ye,ze' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S18>/phi theta psi' */
  boolean_T pqr_CSTATE[3];             /* '<S1>/p,q,r ' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters (default storage) */
struct P_Infinion_T_ {
  real_T FlatEarthtoLLA_LL0[2];        /* Mask Parameter: FlatEarthtoLLA_LL0
                                        * Referenced by: '<S7>/ref_position'
                                        */
  real_T AerodynamicForcesandMoments_S;
                                /* Mask Parameter: AerodynamicForcesandMoments_S
                                 * Referenced by: '<S4>/reference area'
                                 */
  real_T AerodynamicForcesandMoments_S_g;
                              /* Mask Parameter: AerodynamicForcesandMoments_S_g
                               * Referenced by: '<S3>/reference area'
                               */
  real_T uDOFEulerAngles_Vm_0[3];      /* Mask Parameter: uDOFEulerAngles_Vm_0
                                        * Referenced by: '<S1>/ub,vb,wb'
                                        */
  real_T AerodynamicForcesandMoments_b;
                                /* Mask Parameter: AerodynamicForcesandMoments_b
                                 * Referenced by: '<S4>/Constant'
                                 */
  real_T AerodynamicForcesandMoments_b_h;
                              /* Mask Parameter: AerodynamicForcesandMoments_b_h
                               * Referenced by: '<S3>/Constant'
                               */
  real_T AerodynamicForcesandMoments_cba;
                              /* Mask Parameter: AerodynamicForcesandMoments_cba
                               * Referenced by: '<S4>/Constant1'
                               */
  real_T AerodynamicForcesandMoments_c_h;
                              /* Mask Parameter: AerodynamicForcesandMoments_c_h
                               * Referenced by: '<S3>/Constant1'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S115>/Constant'
                                       */
  real_T CompareToConstant_const_n; /* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S113>/Constant'
                                     */
  real_T CompareToConstant_const_c; /* Mask Parameter: CompareToConstant_const_c
                                     * Referenced by: '<S116>/Constant'
                                     */
  real_T CompareToConstant_const_e; /* Mask Parameter: CompareToConstant_const_e
                                     * Referenced by: '<S109>/Constant'
                                     */
  real_T CompareToConstant_const_p; /* Mask Parameter: CompareToConstant_const_p
                                     * Referenced by: '<S107>/Constant'
                                     */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S110>/Constant'
                                     */
  real_T uDOFEulerAngles_eul_0[3];     /* Mask Parameter: uDOFEulerAngles_eul_0
                                        * Referenced by: '<S18>/phi theta psi'
                                        */
  real_T uDOFEulerAngles_inertia[9];  /* Mask Parameter: uDOFEulerAngles_inertia
                                       * Referenced by: '<S20>/Constant1'
                                       */
  real_T uDOFEulerAngles_mass_0;       /* Mask Parameter: uDOFEulerAngles_mass_0
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T uDOFEulerAngles_pm_0[3];      /* Mask Parameter: uDOFEulerAngles_pm_0
                                        * Referenced by: '<S1>/p,q,r '
                                        */
  real_T FlatEarthtoLLA_psi;           /* Mask Parameter: FlatEarthtoLLA_psi
                                        * Referenced by: '<S7>/ref_rotation'
                                        */
  real_T uDOFEulerAngles_xme_0[3];     /* Mask Parameter: uDOFEulerAngles_xme_0
                                        * Referenced by: '<S1>/xe,ye,ze'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S105>/Bias'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S105>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S105>/Bias1'
                                        */
  real_T Bias_Bias_m;                  /* Expression: 180
                                        * Referenced by: '<S108>/Bias'
                                        */
  real_T Bias1_Bias_j;                 /* Expression: -180
                                        * Referenced by: '<S108>/Bias1'
                                        */
  real_T Bias_Bias_k;                  /* Expression: 180
                                        * Referenced by: '<S106>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S106>/Bias1'
                                        */
  real_T Bias_Bias_n;                  /* Expression: -90
                                        * Referenced by: '<S111>/Bias'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S111>/Gain'
                                        */
  real_T Bias1_Bias_a;                 /* Expression: +90
                                        * Referenced by: '<S111>/Bias1'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S114>/Constant2'
                                        */
  real_T Bias_Bias_o;                  /* Expression: 180
                                        * Referenced by: '<S114>/Bias'
                                        */
  real_T Bias1_Bias_jw;                /* Expression: -180
                                        * Referenced by: '<S114>/Bias1'
                                        */
  real_T Constant_Value;               /* Expression: 180
                                        * Referenced by: '<S102>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S102>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 360
                                        * Referenced by: '<S112>/Constant2'
                                        */
  real_T Bias_Bias_f;                  /* Expression: 180
                                        * Referenced by: '<S112>/Bias'
                                        */
  real_T Bias1_Bias_b;                 /* Expression: -180
                                        * Referenced by: '<S112>/Bias1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T HNLLat_Value;                 /* Expression: 21.322
                                        * Referenced by: '<Root>/HNLLat'
                                        */
  real_T Constant2_Value_d;            /* Expression: 1
                                        * Referenced by: '<S117>/Constant2'
                                        */
  real_T Constant1_Value_k;            /* Expression: R
                                        * Referenced by: '<S117>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S120>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S122>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: F
                                        * Referenced by: '<S121>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S121>/f'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S117>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S117>/Constant3'
                                        */
  real_T Constant2_Value_e;            /* Expression: 360
                                        * Referenced by: '<S108>/Constant2'
                                        */
  real_T HNLLong_Value;                /* Expression: -157.924
                                        * Referenced by: '<Root>/HNLLong'
                                        */
  real_T Constant_Value_o;             /* Expression: 180
                                        * Referenced by: '<S101>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S101>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 360
                                        * Referenced by: '<S106>/Constant2'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T phithetapsi_WrappedStateUpperVa;/* Expression: pi
                                          * Referenced by: '<S18>/phi theta psi'
                                          */
  real_T phithetapsi_WrappedStateLowerVa;/* Expression: -pi
                                          * Referenced by: '<S18>/phi theta psi'
                                          */
  real_T Constant2_Value_n;            /* Expression: 1.2754
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T u2rhoV2_Gain;                 /* Expression: 1/2
                                        * Referenced by: '<S6>/1//2rhoV^2'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T deltal_BreakpointsData[9];    /* Expression: aero{2}.deltal
                                        * Referenced by: '<S2>/(deltal)'
                                        */
  real_T Constant1_Value_g;            /* Expression: 343
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Mach_BreakpointsData[3];      /* Expression: aero{1}.mach
                                        * Referenced by: '<S2>/(Mach)'
                                        */
  real_T altitude_BreakpointsData[3];  /* Expression: aero{1}.alt
                                        * Referenced by: '<S2>/(altitude)'
                                        */
  real_T clroll_Table[81];      /* Expression: permute(aero{2}.clroll,[1  2  3])
                                 * Referenced by: '<S36>/clroll'
                                 */
  real_T alpha_BreakpointsData[12];    /* Expression: aero{1}.alpha
                                        * Referenced by: '<S2>/(alpha)'
                                        */
  real_T CmYaw_Table[972];             /* Expression: aero{2}.cn_asy
                                        * Referenced by: '<S36>/CmYaw '
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T delta_BreakpointsData[7];     /* Expression: aero{1}.delta
                                        * Referenced by: '<S2>/(delta)'
                                        */
  real_T DCDI_Table[756];    /* Expression: permute(aero{1}.dcdi_sym,[1 3 4 2 ])
                              * Referenced by: '<S37>/DCDI'
                              */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T DCL_Table[63];        /* Expression: permute(aero{1}.dcl_sym,[1  2  3])
                                * Referenced by: '<S37>/DCL'
                                */
  real_T DCm_Table[63];        /* Expression: permute(aero{1}.dcm_sym,[1  2  3])
                                * Referenced by: '<S37>/DCm'
                                */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T deltaR_BreakpointsData[5];    /* Expression: aero{3}.delta
                                        * Referenced by: '<S2>/(deltaR)'
                                        */
  real_T DCmrudder_Table[45];  /* Expression: permute(aero{3}.dcm_sym,[1  2  3])
                                * Referenced by: '<S38>/DCm (rudder)'
                                */
  real_T coefAdjust_Gain[3];           /* Expression: [1  1  1]
                                        * Referenced by: '<S4>/coefAdjust'
                                        */
  real_T Xcp_Table[108];           /* Expression: permute(aero{1}.xcp,[1  2  3])
                                    * Referenced by: '<S2>/Xcp'
                                    */
  real_T Gain_Gain_e;                  /* Expression: aero{1}.cbar
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T zero1_Value;                  /* Expression: 0
                                        * Referenced by: '<S2>/zero1'
                                        */
  real_T Constant_Value_lx;            /* Expression: 0
                                        * Referenced by: '<S88>/Constant'
                                        */
  real_T alpha_BreakpointsData_d[12];  /* Expression: aero{1}.alpha
                                        * Referenced by: '<Root>/(alpha)'
                                        */
  real_T Mach_BreakpointsData_e[3];    /* Expression: aero{1}.mach
                                        * Referenced by: '<Root>/(Mach)'
                                        */
  real_T altitude_BreakpointsData_i[3];/* Expression: aero{1}.alt
                                        * Referenced by: '<Root>/(altitude)'
                                        */
  real_T CDcoefficientofdrag_Table[108];
                                    /* Expression: permute(aero{1}.cd,[1  2  3])
                                     * Referenced by: '<Root>/CD (coefficient of drag)'
                                     */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T CLcoeffcientoflift_Table[108];
                                    /* Expression: permute(aero{1}.cl,[1  2  3])
                                     * Referenced by: '<Root>/CL (coeffcient of lift)'
                                     */
  real_T Gain1_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T coefAdjust_Gain_h[3];         /* Expression: [-1 -1 -1]
                                        * Referenced by: '<S3>/coefAdjust'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T zero3_Value[3];               /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/zero3'
                                        */
  real_T Clbderivativeofrollingmomentcoe[108];
                                   /* Expression: permute(aero{1}.clb,[1  2  3])
                                    * Referenced by: '<Root>/Clb (derivative of rolling moment coefficient)'
                                    */
  real_T Cmpitchingmomentcoefficient_Tab[108];
                                    /* Expression: permute(aero{1}.cm,[1  2  3])
                                     * Referenced by: '<Root>/Cm (pitching moment coefficient)'
                                     */
  real_T Cnbderivativeofyawingmomentcoef[108];
                                   /* Expression: permute(aero{1}.cnb,[1  2  3])
                                    * Referenced by: '<Root>/Cnb (derivative of yawing moment coefficient)'
                                    */
  real_T Gain2_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Constant2_Value_f[9];         /* Expression: zeros(3)
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T Constant_Value_lm;            /* Expression: 0
                                        * Referenced by: '<S73>/Constant'
                                        */
  uint32_T clroll_dimSize[3];          /* Computed Parameter: clroll_dimSize
                                        * Referenced by: '<S36>/clroll'
                                        */
  uint32_T CmYaw_dimSize[4];           /* Computed Parameter: CmYaw_dimSize
                                        * Referenced by: '<S36>/CmYaw '
                                        */
  uint32_T DCDI_dimSize[4];            /* Computed Parameter: DCDI_dimSize
                                        * Referenced by: '<S37>/DCDI'
                                        */
  uint32_T DCL_dimSize[3];             /* Computed Parameter: DCL_dimSize
                                        * Referenced by: '<S37>/DCL'
                                        */
  uint32_T DCm_dimSize[3];             /* Computed Parameter: DCm_dimSize
                                        * Referenced by: '<S37>/DCm'
                                        */
  uint32_T DCmrudder_dimSize[3];       /* Computed Parameter: DCmrudder_dimSize
                                        * Referenced by: '<S38>/DCm (rudder)'
                                        */
  uint32_T Xcp_dimSize[3];             /* Computed Parameter: Xcp_dimSize
                                        * Referenced by: '<S2>/Xcp'
                                        */
  uint32_T CDcoefficientofdrag_dimSize[3];
                              /* Computed Parameter: CDcoefficientofdrag_dimSize
                               * Referenced by: '<Root>/CD (coefficient of drag)'
                               */
  uint32_T CLcoeffcientoflift_dimSize[3];
                               /* Computed Parameter: CLcoeffcientoflift_dimSize
                                * Referenced by: '<Root>/CL (coeffcient of lift)'
                                */
  uint32_T Clbderivativeofrollingmomentc_p[3];
                          /* Computed Parameter: Clbderivativeofrollingmomentc_p
                           * Referenced by: '<Root>/Clb (derivative of rolling moment coefficient)'
                           */
  uint32_T Cmpitchingmomentcoefficient_dim[3];
                          /* Computed Parameter: Cmpitchingmomentcoefficient_dim
                           * Referenced by: '<Root>/Cm (pitching moment coefficient)'
                           */
  uint32_T Cnbderivativeofyawingmomentco_p[3];
                          /* Computed Parameter: Cnbderivativeofyawingmomentco_p
                           * Referenced by: '<Root>/Cnb (derivative of yawing moment coefficient)'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Infinion_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Infinion_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Class declaration for model Infinion */
class InfinionModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  InfinionModelClass();

  /* Destructor */
  ~InfinionModelClass();

  /* Real-Time Model get method */
  RT_MODEL_Infinion_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_Infinion_T Infinion_P;

  /* Block signals */
  B_Infinion_T Infinion_B;

  /* Block states */
  DW_Infinion_T Infinion_DW;
  X_Infinion_T Infinion_X;             /* Block continuous states */
  PeriodicIndX_Infinion_T Infinion_PeriodicIndX;/* Block periodic continuous states */
  PeriodicRngX_Infinion_T Infinion_PeriodicRngX;

  /* Real-Time Model */
  RT_MODEL_Infinion_T Infinion_M;

  /* private member function(s) for subsystem '<Root>'*/
  void Infinion_emxInit_char_T(emxArray_char_T_Infinion_T **pEmxArray, int32_T
    numDimensions);
  int8_T Infinion_filedata(void);
  int8_T Infinion_cfopen(const char_T *cfilename, const char_T *cpermission);
  real_T Infinion_fileManager(void);
  FILE * Infinion_fileManager_b(real_T varargin_1);
  void Infinion_fseek(real_T fileID);
  real_T Infinion_ftell(real_T fileID);
  void Infinion_fseek_m(real_T fileID);
  void Infinion_emxInit_real_T(emxArray_real_T_Infinion_T **pEmxArray, int32_T
    numDimensions);
  void Infinion_emxInit_uint8_T(emxArray_uint8_T_Infinion_T **pEmxArray, int32_T
    numDimensions);
  void Infinion_emxInit_uint8_T1(emxArray_uint8_T_Infinion_T **pEmxArray,
    int32_T numDimensions);
  void Infi_emxEnsureCapacity_uint8_T1(emxArray_uint8_T_Infinion_T *emxArray,
    int32_T oldNumel);
  void Infin_emxEnsureCapacity_uint8_T(emxArray_uint8_T_Infinion_T *emxArray,
    int32_T oldNumel);
  void Infini_emxEnsureCapacity_real_T(emxArray_real_T_Infinion_T *emxArray,
    int32_T oldNumel);
  void Infinion_emxFree_uint8_T(emxArray_uint8_T_Infinion_T **pEmxArray);
  void Infinion_fread(real_T fileID, int32_T sizeA, emxArray_real_T_Infinion_T
                      *A, real_T *count);
  void Infinion_emxFree_real_T(emxArray_real_T_Infinion_T **pEmxArray);
  int32_T Infinion_cfclose(real_T fid);
  void Infini_emxEnsureCapacity_char_T(emxArray_char_T_Infinion_T *emxArray,
    int32_T oldNumel);
  void Infinion_char(const emxArray_uint8_T_Infinion_T *varargin_1,
                     emxArray_char_T_Infinion_T *y);
  void Infinion_readfile(emxArray_char_T_Infinion_T *y);
  void Infinion_emxInit_boolean_T(emxArray_boolean_T_Infinion_T **pEmxArray,
    int32_T numDimensions);
  void Infinion_deblank(const emxArray_char_T_Infinion_T *x,
                        emxArray_char_T_Infinion_T *y);
  void Inf_emxEnsureCapacity_boolean_T(emxArray_boolean_T_Infinion_T *emxArray,
    int32_T oldNumel);
  void Infinion_isspace(const emxArray_char_T_Infinion_T *x,
                        emxArray_boolean_T_Infinion_T *y);
  void Infinion_emxFree_boolean_T(emxArray_boolean_T_Infinion_T **pEmxArray);
  void Infinion_extractAfter(const emxArray_char_T_Infinion_T *str, const real_T
    pos_data[], emxArray_char_T_Infinion_T *s);
  void Infinion_emxInit_real_T1(emxArray_real_T_Infinion_T **pEmxArray, int32_T
    numDimensions);
  void Infin_emxEnsureCapacity_real_T1(emxArray_real_T_Infinion_T *emxArray,
    int32_T oldNumel);
  void Infinion_char_b(const emxArray_real_T_Infinion_T *varargin_1,
                       emxArray_char_T_Infinion_T *y);
  int32_T Infinion_skipspaces(const emxArray_char_T_Infinion_T *s, int32_T n);
  void Infinion_copysign(emxArray_char_T_Infinion_T *s1, int32_T *idx, const
    emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n, boolean_T *foundsign,
    boolean_T *success);
  boolean_T Infinion_isUnitImag(const emxArray_char_T_Infinion_T *s, int32_T k,
    int32_T n);
  void Infinion_readNonFinite(const emxArray_char_T_Infinion_T *s, int32_T *k,
    int32_T n, boolean_T *b_finite, real_T *fv);
  boolean_T Infinion_copydigits(emxArray_char_T_Infinion_T *s1, int32_T *idx,
    const emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n, boolean_T
    allowpoint);
  boolean_T Infinion_copyexponent(emxArray_char_T_Infinion_T *s1, int32_T *idx,
    const emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n);
  void Infinion_skipspaces_k(const emxArray_char_T_Infinion_T *s, int32_T *k,
    int32_T n);
  void Infinion_readfloat(emxArray_char_T_Infinion_T *s1, int32_T *idx, const
    emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n, boolean_T allowimag,
    boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign,
    boolean_T *success);
  void Infinion_emxFree_char_T(emxArray_char_T_Infinion_T **pEmxArray);
  creal_T Infinion_str2double(const emxArray_char_T_Infinion_T *s);
  real_T Infinion_lastStr2double(const emxArray_char_T_Infinion_T *str);
  int8_T Infinion_filedata_d(void);
  int8_T Infinion_cfopen_l(const char_T *cfilename, const char_T *cpermission);
  real_T Infinion_fileManager_bt(void);
  FILE * Infinion_fileManager_btz(real_T varargin_1);
  void Infinion_fseek_o(real_T fileID);
  real_T Infinion_ftell_f(real_T fileID);
  void Infinion_fseek_ox(real_T fileID);
  void Infinion_fread_e(real_T fileID, int32_T sizeA, emxArray_real_T_Infinion_T
                        *A, real_T *count);
  int32_T Infinion_cfclose_k(real_T fid);
  void Infinion_readfile_n(emxArray_char_T_Infinion_T *y);
  int8_T Infinion_filedata_c(void);
  int8_T Infinion_cfopen_b(const char_T *cfilename, const char_T *cpermission);
  real_T Infinion_fileManager_p(void);
  FILE * Infinion_fileManager_pw(real_T varargin_1);
  void Infinion_fseek_k(real_T fileID);
  real_T Infinion_ftell_i(real_T fileID);
  void Infinion_fseek_kz(real_T fileID);
  void Infinion_fread_g(real_T fileID, int32_T sizeA, emxArray_real_T_Infinion_T
                        *A, real_T *count);
  int32_T Infinion_cfclose_h(real_T fid);
  void Infinion_readfile_a(emxArray_char_T_Infinion_T *y);
  int8_T Infinion_filedata_k(void);
  int8_T Infinion_cfopen_k(const char_T *cfilename, const char_T *cpermission);
  real_T Infinion_fileManager_e(void);
  FILE * Infinion_fileManager_e4(real_T varargin_1);
  void Infinion_fseek_c(real_T fileID);
  real_T Infinion_ftell_b(real_T fileID);
  void Infinion_fseek_cn(real_T fileID);
  void Infinion_fread_j(real_T fileID, int32_T sizeA, emxArray_real_T_Infinion_T
                        *A, real_T *count);
  int32_T Infinion_cfclose_i(real_T fid);
  void Infinion_readfile_e(emxArray_char_T_Infinion_T *y);
  int8_T Infinion_filedata_m(void);
  int8_T Infinion_cfopen_n(const char_T *cfilename, const char_T *cpermission);
  real_T Infinion_fileManager_n(void);
  real_T Infinion_fileManager_nv(void);
  real_T Infinion_fileManager_nvg(void);
  real_T Infinion_fileManager_nvg1(void);
  real_T Infinion_fileManager_nvg1z(void);
  real_T Infinion_fileManager_nvg1zl(void);
  real_T Infinion_fileManager_nvg1zlk(void);
  real_T Infinion_fileManager_nvg1zlk2(void);
  real_T Infinion_fileManager_nvg1zlk2m(void);
  real_T Infinion_fileManager_nvg1zlk2mj(void);
  real_T Infinio_fileManager_nvg1zlk2mjw(void);
  real_T Infini_fileManager_nvg1zlk2mjw5(void);
  real_T Infin_fileManager_nvg1zlk2mjw5f(void);
  real_T Infi_fileManager_nvg1zlk2mjw5fc(void);
  real_T Inf_fileManager_nvg1zlk2mjw5fch(void);
  real_T Inf_fileManager_k(void);
  real_T Inf_fileManager_e(void);
  real_T Inf_fileManager_f(void);
  real_T Inf_fileManager_o(void);
  real_T Inf_fileManager_oy(void);
  real_T Inf_fileManager_p(void);
  void Inf_fileManager_n(real_T varargin_1, FILE * *f, boolean_T *a);
  int32_T Inf_fileManager_el(void);

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void Infinion_derivatives();
};

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
 * '<Root>' : 'Infinion'
 * '<S1>'   : 'Infinion/6DOF (Euler Angles)'
 * '<S2>'   : 'Infinion/Aerodynamic Coefficients'
 * '<S3>'   : 'Infinion/Aerodynamic Forces and Moments'
 * '<S4>'   : 'Infinion/Aerodynamic Forces and Moments '
 * '<S5>'   : 'Infinion/Angle Conversion'
 * '<S6>'   : 'Infinion/Dynamic Pressure'
 * '<S7>'   : 'Infinion/Flat Earth to LLA'
 * '<S8>'   : 'Infinion/Incidence, Sideslip, & Airspeed'
 * '<S9>'   : 'Infinion/Mach Number'
 * '<S10>'  : 'Infinion/Read Aileron'
 * '<S11>'  : 'Infinion/Read Elevator'
 * '<S12>'  : 'Infinion/Read Rudder'
 * '<S13>'  : 'Infinion/Read Throttle'
 * '<S14>'  : 'Infinion/WriteToFile'
 * '<S15>'  : 'Infinion/compute track'
 * '<S16>'  : 'Infinion/gravity'
 * '<S17>'  : 'Infinion/propulsion'
 * '<S18>'  : 'Infinion/6DOF (Euler Angles)/Calculate DCM & Euler Angles'
 * '<S19>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot'
 * '<S20>'  : 'Infinion/6DOF (Euler Angles)/Determine Force,  Mass & Inertia'
 * '<S21>'  : 'Infinion/6DOF (Euler Angles)/Vbxw'
 * '<S22>'  : 'Infinion/6DOF (Euler Angles)/Velocity Conversion'
 * '<S23>'  : 'Infinion/6DOF (Euler Angles)/Velocity Conversion1'
 * '<S24>'  : 'Infinion/6DOF (Euler Angles)/Velocity Conversion2'
 * '<S25>'  : 'Infinion/6DOF (Euler Angles)/transform to Inertial axes '
 * '<S26>'  : 'Infinion/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix'
 * '<S27>'  : 'Infinion/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phidot thetadot psidot'
 * '<S28>'  : 'Infinion/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S29>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product'
 * '<S30>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/I x w'
 * '<S31>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/I x w1'
 * '<S32>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem'
 * '<S33>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
 * '<S34>'  : 'Infinion/6DOF (Euler Angles)/Vbxw/Subsystem'
 * '<S35>'  : 'Infinion/6DOF (Euler Angles)/Vbxw/Subsystem1'
 * '<S36>'  : 'Infinion/Aerodynamic Coefficients/Aileron'
 * '<S37>'  : 'Infinion/Aerodynamic Coefficients/Elevator'
 * '<S38>'  : 'Infinion/Aerodynamic Coefficients/Rudder'
 * '<S39>'  : 'Infinion/Aerodynamic Coefficients/alpha_rad1'
 * '<S40>'  : 'Infinion/Aerodynamic Coefficients/alpha_rad2'
 * '<S41>'  : 'Infinion/Aerodynamic Coefficients/alpha_rad3'
 * '<S42>'  : 'Infinion/Aerodynamic Coefficients/alpha_rad4'
 * '<S43>'  : 'Infinion/Aerodynamic Forces and Moments/3x3 Cross Product'
 * '<S44>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation'
 * '<S45>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation'
 * '<S46>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation'
 * '<S47>'  : 'Infinion/Aerodynamic Forces and Moments/3x3 Cross Product/Subsystem'
 * '<S48>'  : 'Infinion/Aerodynamic Forces and Moments/3x3 Cross Product/Subsystem1'
 * '<S49>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind'
 * '<S50>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Incidence, Sideslip, & Airspeed'
 * '<S51>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A11'
 * '<S52>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A12'
 * '<S53>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A13'
 * '<S54>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A21'
 * '<S55>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A22'
 * '<S56>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A23'
 * '<S57>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A31'
 * '<S58>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A32'
 * '<S59>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A33'
 * '<S60>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/Create Transformation Matrix'
 * '<S61>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S62>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S63>'  : 'Infinion/Aerodynamic Forces and Moments/CG-CP Transformation/Incidence, Sideslip, & Airspeed/dot'
 * '<S64>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind'
 * '<S65>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Incidence, Sideslip, & Airspeed'
 * '<S66>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A11'
 * '<S67>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A12'
 * '<S68>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A13'
 * '<S69>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A21'
 * '<S70>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A22'
 * '<S71>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A23'
 * '<S72>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A31'
 * '<S73>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A32'
 * '<S74>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A33'
 * '<S75>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/Create Transformation Matrix'
 * '<S76>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S77>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S78>'  : 'Infinion/Aerodynamic Forces and Moments/Force Transformation/Incidence, Sideslip, & Airspeed/dot'
 * '<S79>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind'
 * '<S80>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Incidence, Sideslip, & Airspeed'
 * '<S81>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A11'
 * '<S82>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A12'
 * '<S83>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A13'
 * '<S84>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A21'
 * '<S85>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A22'
 * '<S86>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A23'
 * '<S87>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A31'
 * '<S88>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A32'
 * '<S89>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A33'
 * '<S90>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/Create Transformation Matrix'
 * '<S91>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S92>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S93>'  : 'Infinion/Aerodynamic Forces and Moments/Moment Transformation/Incidence, Sideslip, & Airspeed/dot'
 * '<S94>'  : 'Infinion/Aerodynamic Forces and Moments /3x3 Cross Product'
 * '<S95>'  : 'Infinion/Aerodynamic Forces and Moments /CG-CP Transformation'
 * '<S96>'  : 'Infinion/Aerodynamic Forces and Moments /Force Transformation'
 * '<S97>'  : 'Infinion/Aerodynamic Forces and Moments /Moment Transformation'
 * '<S98>'  : 'Infinion/Aerodynamic Forces and Moments /3x3 Cross Product/Subsystem'
 * '<S99>'  : 'Infinion/Aerodynamic Forces and Moments /3x3 Cross Product/Subsystem1'
 * '<S100>' : 'Infinion/Dynamic Pressure/dot'
 * '<S101>' : 'Infinion/Flat Earth to LLA/LatLong wrap'
 * '<S102>' : 'Infinion/Flat Earth to LLA/LatLong wrap1'
 * '<S103>' : 'Infinion/Flat Earth to LLA/LongLat_offset'
 * '<S104>' : 'Infinion/Flat Earth to LLA/pos_deg'
 * '<S105>' : 'Infinion/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
 * '<S106>' : 'Infinion/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
 * '<S107>' : 'Infinion/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S108>' : 'Infinion/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S109>' : 'Infinion/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S110>' : 'Infinion/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S111>' : 'Infinion/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
 * '<S112>' : 'Infinion/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
 * '<S113>' : 'Infinion/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
 * '<S114>' : 'Infinion/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
 * '<S115>' : 'Infinion/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S116>' : 'Infinion/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
 * '<S117>' : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
 * '<S118>' : 'Infinion/Flat Earth to LLA/LongLat_offset/rotation_rad'
 * '<S119>' : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
 * '<S120>' : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
 * '<S121>' : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
 * '<S122>' : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
 * '<S123>' : 'Infinion/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S124>' : 'Infinion/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S125>' : 'Infinion/Incidence, Sideslip, & Airspeed/dot'
 * '<S126>' : 'Infinion/Mach Number/dot'
 */
#endif                                 /* RTW_HEADER_Infinion_h_ */
