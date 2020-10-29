/*
 * Spike.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Spike".
 *
 * Model version              : 1.168
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Thu Oct 29 12:19:37 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Spike_h_
#define RTW_HEADER_Spike_h_
#include <cstring>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Spike_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T buffer[65536];
  uint8_T buffer_m[65536];
  uint8_T buffer_c[65536];
  uint8_T buffer_k[65536];
  real_T SinCos_o1;                    /* '<S102>/SinCos' */
  real_T SinCos_o2;                    /* '<S102>/SinCos' */
  real_T Switch;                       /* '<S110>/Switch' */
  real_T TrigonometricFunction1;       /* '<S116>/Trigonometric Function1' */
  real_T TrigonometricFunction2;       /* '<S116>/Trigonometric Function2' */
  real_T Switch_i;                     /* '<S111>/Switch' */
  real_T fdelL;                        /* '<S2>/(deltal)' */
  real_T fde;                          /* '<S2>/(delta)' */
  real_T VectorConcatenate_n[9];       /* '<S74>/Vector Concatenate' */
  real_T Sum[3];                       /* '<S1>/Sum' */
  real_T TmpSignalConversionAtphithetaps[3];/* '<S18>/phidot thetadot psidot' */
  real_T Selector[9];                  /* '<S19>/Selector' */
  real_T Selector1[9];                 /* '<S19>/Selector1' */
  real_T VectorConcatenate_i[9];       /* '<S89>/Vector Concatenate' */
  real_T VectorConcatenate_m[9];       /* '<S59>/Vector Concatenate' */
  real_T Sum_j[3];                     /* '<S3>/Sum' */
  real_T Selector2[9];                 /* '<S19>/Selector2' */
  real_T Product2[3];                  /* '<S19>/Product2' */
  real_T Product[3];                   /* '<S25>/Product' */
  real_T forces[3];                    /* '<Root>/propulsion' */
  int32_T idxdelL;                     /* '<S2>/(deltal)' */
  int32_T idxde;                       /* '<S2>/(delta)' */
} B_Spike_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Product2_DWORK4[9];           /* '<S19>/Product2' */
  int32_T deltal_DWORK1;               /* '<S2>/(deltal)' */
  int32_T Mach_DWORK1;                 /* '<S2>/(Mach)' */
  int32_T altitude_DWORK1;             /* '<S2>/(altitude)' */
  int32_T alpha_DWORK1;                /* '<S2>/(alpha)' */
  int32_T delta_DWORK1;                /* '<S2>/(delta)' */
  int32_T alpha_DWORK1_n;              /* '<Root>/(alpha)' */
  int32_T Mach_DWORK1_m;               /* '<Root>/(Mach)' */
  int32_T altitude_DWORK1_p;           /* '<Root>/(altitude)' */
  boolean_T eml_autoflush[20];         /* '<Root>/WriteToFile' */
  FILE * eml_openfiles[20];            /* '<Root>/Read Aileron' */
  FILE * eml_openfiles_j[20];          /* '<Root>/Read Tail left' */
  FILE * eml_openfiles_l[20];          /* '<Root>/Read Tail right' */
  FILE * eml_openfiles_m[20];          /* '<Root>/Read Throttle' */
  FILE * eml_openfiles_g[20];          /* '<Root>/WriteToFile' */
} DW_Spike_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S1>/ub,vb,wb' */
  real_T xeyeze_CSTATE[3];             /* '<S1>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S18>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S1>/p,q,r ' */
} X_Spike_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_Spike_T[3];
typedef real_T PeriodicRngX_Spike_T[6];

/* State derivatives (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S1>/ub,vb,wb' */
  real_T xeyeze_CSTATE[3];             /* '<S1>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S18>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S1>/p,q,r ' */
} XDot_Spike_T;

/* State disabled  */
typedef struct {
  boolean_T ubvbwb_CSTATE[3];          /* '<S1>/ub,vb,wb' */
  boolean_T xeyeze_CSTATE[3];          /* '<S1>/xe,ye,ze' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S18>/phi theta psi' */
  boolean_T pqr_CSTATE[3];             /* '<S1>/p,q,r ' */
} XDis_Spike_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Spike_T_ {
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
                                       * Referenced by: '<S114>/Constant'
                                       */
  real_T CompareToConstant_const_n; /* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S112>/Constant'
                                     */
  real_T CompareToConstant_const_c; /* Mask Parameter: CompareToConstant_const_c
                                     * Referenced by: '<S115>/Constant'
                                     */
  real_T CompareToConstant_const_e; /* Mask Parameter: CompareToConstant_const_e
                                     * Referenced by: '<S108>/Constant'
                                     */
  real_T CompareToConstant_const_p; /* Mask Parameter: CompareToConstant_const_p
                                     * Referenced by: '<S106>/Constant'
                                     */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S109>/Constant'
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
                                        * Referenced by: '<S104>/Bias'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S104>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S104>/Bias1'
                                        */
  real_T Bias_Bias_m;                  /* Expression: 180
                                        * Referenced by: '<S107>/Bias'
                                        */
  real_T Bias1_Bias_j;                 /* Expression: -180
                                        * Referenced by: '<S107>/Bias1'
                                        */
  real_T Bias_Bias_k;                  /* Expression: 180
                                        * Referenced by: '<S105>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S105>/Bias1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S101>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 180
                                        * Referenced by: '<S101>/Constant'
                                        */
  real_T Bias_Bias_n;                  /* Expression: -90
                                        * Referenced by: '<S110>/Bias'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S110>/Gain'
                                        */
  real_T Bias1_Bias_a;                 /* Expression: +90
                                        * Referenced by: '<S110>/Bias1'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S113>/Constant2'
                                        */
  real_T Bias_Bias_o;                  /* Expression: 180
                                        * Referenced by: '<S113>/Bias'
                                        */
  real_T Bias1_Bias_jw;                /* Expression: -180
                                        * Referenced by: '<S113>/Bias1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 360
                                        * Referenced by: '<S111>/Constant2'
                                        */
  real_T Bias_Bias_f;                  /* Expression: 180
                                        * Referenced by: '<S111>/Bias'
                                        */
  real_T Bias1_Bias_b;                 /* Expression: -180
                                        * Referenced by: '<S111>/Bias1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant2_Value_d;            /* Expression: 1
                                        * Referenced by: '<S116>/Constant2'
                                        */
  real_T Constant1_Value_k;            /* Expression: R
                                        * Referenced by: '<S116>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S119>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S121>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: F
                                        * Referenced by: '<S120>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S120>/f'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S116>/Constant3'
                                        */
  real_T Constant2_Value_e;            /* Expression: 360
                                        * Referenced by: '<S107>/Constant2'
                                        */
  real_T Constant_Value_o;             /* Expression: 180
                                        * Referenced by: '<S100>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S100>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 360
                                        * Referenced by: '<S105>/Constant2'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
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
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T coefAdjust_Gain[3];           /* Expression: [1  1  1]
                                        * Referenced by: '<S4>/coefAdjust'
                                        */
  real_T Constant_Value_lm;            /* Expression: 0
                                        * Referenced by: '<S72>/Constant'
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
  real_T CD_Table[108];             /* Expression: permute(aero{1}.cd,[1  2  3])
                                     * Referenced by: '<Root>/CD'
                                     */
  real_T CYb_Table[108];           /* Expression: permute(aero{1}.cyb,[1  2  3])
                                    * Referenced by: '<Root>/CYb'
                                    */
  real_T CL_Table[108];             /* Expression: permute(aero{1}.cl,[1  2  3])
                                     * Referenced by: '<Root>/CL'
                                     */
  real_T Gain1_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T coefAdjust_Gain_h[3];         /* Expression: [-1 -1 -1]
                                        * Referenced by: '<S3>/coefAdjust'
                                        */
  real_T Constant2_Value_f[9];         /* Expression: zeros(3)
                                        * Referenced by: '<S20>/Constant2'
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
                                        * Referenced by: '<S87>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T zero3_Value[3];               /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/zero3'
                                        */
  real_T Clb_Table[108];           /* Expression: permute(aero{1}.clb,[1  2  3])
                                    * Referenced by: '<Root>/Clb'
                                    */
  real_T Cm_Table[108];             /* Expression: permute(aero{1}.cm,[1  2  3])
                                     * Referenced by: '<Root>/Cm'
                                     */
  real_T Cnb_Table[108];           /* Expression: permute(aero{1}.cnb,[1  2  3])
                                    * Referenced by: '<Root>/Cnb'
                                    */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain2'
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
  uint32_T CD_dimSize[3];              /* Computed Parameter: CD_dimSize
                                        * Referenced by: '<Root>/CD'
                                        */
  uint32_T CYb_dimSize[3];             /* Computed Parameter: CYb_dimSize
                                        * Referenced by: '<Root>/CYb'
                                        */
  uint32_T CL_dimSize[3];              /* Computed Parameter: CL_dimSize
                                        * Referenced by: '<Root>/CL'
                                        */
  uint32_T Xcp_dimSize[3];             /* Computed Parameter: Xcp_dimSize
                                        * Referenced by: '<S2>/Xcp'
                                        */
  uint32_T Clb_dimSize[3];             /* Computed Parameter: Clb_dimSize
                                        * Referenced by: '<Root>/Clb'
                                        */
  uint32_T Cm_dimSize[3];              /* Computed Parameter: Cm_dimSize
                                        * Referenced by: '<Root>/Cm'
                                        */
  uint32_T Cnb_dimSize[3];             /* Computed Parameter: Cnb_dimSize
                                        * Referenced by: '<Root>/Cnb'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Spike_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Spike_T *contStates;
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

/* Class declaration for model Spike */
class SpikeModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  SpikeModelClass();

  /* Destructor */
  ~SpikeModelClass();

  /* Real-Time Model get method */
  RT_MODEL_Spike_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_Spike_T Spike_P;

  /* Block signals */
  B_Spike_T Spike_B;

  /* Block states */
  DW_Spike_T Spike_DW;
  X_Spike_T Spike_X;                   /* Block continuous states */
  PeriodicIndX_Spike_T Spike_PeriodicIndX;/* Block periodic continuous states */
  PeriodicRngX_Spike_T Spike_PeriodicRngX;

  /* Real-Time Model */
  RT_MODEL_Spike_T Spike_M;

  /* private member function(s) for subsystem '<Root>'*/
  void Spike_emxInit_char_T(emxArray_char_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  int8_T Spike_filedata(void);
  int8_T Spike_cfopen(const char * cfilename, const char * cpermission);
  FILE * Spike_fileManager(real_T varargin_1);
  void Spike_emxInit_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  void Spike_emxEnsureCapacity_uint8_T(emxArray_uint8_T_Spike_T *emxArray,
    int32_T oldNumel);
  void Spike_emxFree_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray);
  int32_T Spike_cfclose(real_T fid);
  void Spike_emxEnsureCapacity_char_T(emxArray_char_T_Spike_T *emxArray, int32_T
    oldNumel);
  void Spike_readfile(emxArray_char_T_Spike_T *y);
  void Spike_emxInit_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  void Spike_deblank(const emxArray_char_T_Spike_T *x, emxArray_char_T_Spike_T
                     *y);
  void Spi_emxEnsureCapacity_boolean_T(emxArray_boolean_T_Spike_T *emxArray,
    int32_T oldNumel);
  void Spike_isspace(const emxArray_char_T_Spike_T *x,
                     emxArray_boolean_T_Spike_T *y);
  void Spike_emxFree_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray);
  void Spike_string_extractAfter(const emxArray_char_T_Spike_T *obj_Value, const
    real_T startStr_data[], emxArray_char_T_Spike_T *extracted_Value);
  void Spike_emxInit_real_T(emxArray_real_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  void Spike_emxEnsureCapacity_real_T(emxArray_real_T_Spike_T *emxArray, int32_T
    oldNumel);
  void Spike_char(const emxArray_real_T_Spike_T *varargin_1,
                  emxArray_char_T_Spike_T *y);
  void Spike_skipspaces(const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
  void Spike_copysign(emxArray_char_T_Spike_T *s1, int32_T *idx, const
                      emxArray_char_T_Spike_T *s, int32_T *k, int32_T n,
                      boolean_T *foundsign, boolean_T *success);
  boolean_T Spike_isUnitImag(const emxArray_char_T_Spike_T *s, int32_T k,
    int32_T n);
  void Spike_readNonFinite(const emxArray_char_T_Spike_T *s, int32_T *k, int32_T
    n, boolean_T *b_finite, real_T *fv);
  boolean_T Spike_copydigits(emxArray_char_T_Spike_T *s1, int32_T *idx, const
    emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowpoint);
  boolean_T Spike_copyexponent(emxArray_char_T_Spike_T *s1, int32_T *idx, const
    emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
  void Spike_skipspaces_a(const emxArray_char_T_Spike_T *s, int32_T *k, int32_T
    n);
  void Spike_readfloat(emxArray_char_T_Spike_T *s1, int32_T *idx, const
                       emxArray_char_T_Spike_T *s, int32_T *k, int32_T n,
                       boolean_T allowimag, boolean_T *isimag, boolean_T
                       *b_finite, real_T *nfv, boolean_T *foundsign, boolean_T
                       *success);
  void Spike_emxFree_real_T(emxArray_real_T_Spike_T **pEmxArray);
  real_T Spike_sscanfd_k(const emxArray_char_T_Spike_T *s);
  void Spike_sscanfd(const emxArray_char_T_Spike_T *s, real_T *out1, real_T
                     *out2);
  void Spike_emxFree_char_T(emxArray_char_T_Spike_T **pEmxArray);
  creal_T Spike_str2double(const emxArray_char_T_Spike_T *s);
  real_T Spike_lastStr2double(const emxArray_char_T_Spike_T *str);
  int8_T Spike_filedata_f(void);
  int8_T Spike_cfopen_b(const char * cfilename, const char * cpermission);
  FILE * Spike_fileManager_o(real_T varargin_1);
  int32_T Spike_cfclose_a(real_T fid);
  void Spike_readfile_b(emxArray_char_T_Spike_T *y);
  int8_T Spike_filedata_d(void);
  int8_T Spike_cfopen_a(const char * cfilename, const char * cpermission);
  FILE * Spike_fileManager_c(real_T varargin_1);
  int32_T Spike_cfclose_p(real_T fid);
  void Spike_readfile_e(emxArray_char_T_Spike_T *y);
  int8_T Spike_filedata_dy(void);
  int8_T Spike_cfopen_i(const char * cfilename, const char * cpermission);
  FILE * Spike_fileManager_l(real_T varargin_1);
  int32_T Spike_cfclose_o(real_T fid);
  void Spike_readfile_a(emxArray_char_T_Spike_T *y);
  int8_T Spike_filedata_o(void);
  int8_T Spike_cfopen_e(const char * cfilename, const char * cpermission);

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void Spike_derivatives();
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
 * '<Root>' : 'Spike'
 * '<S1>'   : 'Spike/6DOF (Euler Angles)'
 * '<S2>'   : 'Spike/Aerodynamic Coefficients'
 * '<S3>'   : 'Spike/Aerodynamic Forces and Moments'
 * '<S4>'   : 'Spike/Aerodynamic Forces and Moments '
 * '<S5>'   : 'Spike/Angle Conversion'
 * '<S6>'   : 'Spike/Dynamic Pressure'
 * '<S7>'   : 'Spike/Flat Earth to LLA'
 * '<S8>'   : 'Spike/Incidence, Sideslip, & Airspeed'
 * '<S9>'   : 'Spike/Mach Number'
 * '<S10>'  : 'Spike/Read Aileron'
 * '<S11>'  : 'Spike/Read Tail left'
 * '<S12>'  : 'Spike/Read Tail right'
 * '<S13>'  : 'Spike/Read Throttle'
 * '<S14>'  : 'Spike/SeperateYawAndPitch'
 * '<S15>'  : 'Spike/WriteToFile'
 * '<S16>'  : 'Spike/gravity'
 * '<S17>'  : 'Spike/propulsion'
 * '<S18>'  : 'Spike/6DOF (Euler Angles)/Calculate DCM & Euler Angles'
 * '<S19>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot'
 * '<S20>'  : 'Spike/6DOF (Euler Angles)/Determine Force,  Mass & Inertia'
 * '<S21>'  : 'Spike/6DOF (Euler Angles)/Vbxw'
 * '<S22>'  : 'Spike/6DOF (Euler Angles)/Velocity Conversion'
 * '<S23>'  : 'Spike/6DOF (Euler Angles)/Velocity Conversion1'
 * '<S24>'  : 'Spike/6DOF (Euler Angles)/Velocity Conversion2'
 * '<S25>'  : 'Spike/6DOF (Euler Angles)/transform to Inertial axes '
 * '<S26>'  : 'Spike/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix'
 * '<S27>'  : 'Spike/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phidot thetadot psidot'
 * '<S28>'  : 'Spike/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S29>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product'
 * '<S30>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/I x w'
 * '<S31>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/I x w1'
 * '<S32>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem'
 * '<S33>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
 * '<S34>'  : 'Spike/6DOF (Euler Angles)/Vbxw/Subsystem'
 * '<S35>'  : 'Spike/6DOF (Euler Angles)/Vbxw/Subsystem1'
 * '<S36>'  : 'Spike/Aerodynamic Coefficients/Aileron'
 * '<S37>'  : 'Spike/Aerodynamic Coefficients/Elevator'
 * '<S38>'  : 'Spike/Aerodynamic Coefficients/Rudder'
 * '<S39>'  : 'Spike/Aerodynamic Coefficients/alpha_rad1'
 * '<S40>'  : 'Spike/Aerodynamic Coefficients/alpha_rad2'
 * '<S41>'  : 'Spike/Aerodynamic Coefficients/alpha_rad3'
 * '<S42>'  : 'Spike/Aerodynamic Forces and Moments/3x3 Cross Product'
 * '<S43>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation'
 * '<S44>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation'
 * '<S45>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation'
 * '<S46>'  : 'Spike/Aerodynamic Forces and Moments/3x3 Cross Product/Subsystem'
 * '<S47>'  : 'Spike/Aerodynamic Forces and Moments/3x3 Cross Product/Subsystem1'
 * '<S48>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind'
 * '<S49>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Incidence, Sideslip, & Airspeed'
 * '<S50>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A11'
 * '<S51>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A12'
 * '<S52>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A13'
 * '<S53>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A21'
 * '<S54>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A22'
 * '<S55>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A23'
 * '<S56>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A31'
 * '<S57>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A32'
 * '<S58>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/A33'
 * '<S59>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Direction Cosine Matrix Body to Wind/Create Transformation Matrix'
 * '<S60>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S61>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S62>'  : 'Spike/Aerodynamic Forces and Moments/CG-CP Transformation/Incidence, Sideslip, & Airspeed/dot'
 * '<S63>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind'
 * '<S64>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Incidence, Sideslip, & Airspeed'
 * '<S65>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A11'
 * '<S66>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A12'
 * '<S67>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A13'
 * '<S68>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A21'
 * '<S69>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A22'
 * '<S70>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A23'
 * '<S71>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A31'
 * '<S72>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A32'
 * '<S73>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/A33'
 * '<S74>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Direction Cosine Matrix Body to Wind/Create Transformation Matrix'
 * '<S75>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S76>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S77>'  : 'Spike/Aerodynamic Forces and Moments/Force Transformation/Incidence, Sideslip, & Airspeed/dot'
 * '<S78>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind'
 * '<S79>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Incidence, Sideslip, & Airspeed'
 * '<S80>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A11'
 * '<S81>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A12'
 * '<S82>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A13'
 * '<S83>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A21'
 * '<S84>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A22'
 * '<S85>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A23'
 * '<S86>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A31'
 * '<S87>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A32'
 * '<S88>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/A33'
 * '<S89>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Direction Cosine Matrix Body to Wind/Create Transformation Matrix'
 * '<S90>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S91>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S92>'  : 'Spike/Aerodynamic Forces and Moments/Moment Transformation/Incidence, Sideslip, & Airspeed/dot'
 * '<S93>'  : 'Spike/Aerodynamic Forces and Moments /3x3 Cross Product'
 * '<S94>'  : 'Spike/Aerodynamic Forces and Moments /CG-CP Transformation'
 * '<S95>'  : 'Spike/Aerodynamic Forces and Moments /Force Transformation'
 * '<S96>'  : 'Spike/Aerodynamic Forces and Moments /Moment Transformation'
 * '<S97>'  : 'Spike/Aerodynamic Forces and Moments /3x3 Cross Product/Subsystem'
 * '<S98>'  : 'Spike/Aerodynamic Forces and Moments /3x3 Cross Product/Subsystem1'
 * '<S99>'  : 'Spike/Dynamic Pressure/dot'
 * '<S100>' : 'Spike/Flat Earth to LLA/LatLong wrap'
 * '<S101>' : 'Spike/Flat Earth to LLA/LatLong wrap1'
 * '<S102>' : 'Spike/Flat Earth to LLA/LongLat_offset'
 * '<S103>' : 'Spike/Flat Earth to LLA/pos_deg'
 * '<S104>' : 'Spike/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
 * '<S105>' : 'Spike/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
 * '<S106>' : 'Spike/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S107>' : 'Spike/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S108>' : 'Spike/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S109>' : 'Spike/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S110>' : 'Spike/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
 * '<S111>' : 'Spike/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
 * '<S112>' : 'Spike/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
 * '<S113>' : 'Spike/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
 * '<S114>' : 'Spike/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S115>' : 'Spike/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
 * '<S116>' : 'Spike/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
 * '<S117>' : 'Spike/Flat Earth to LLA/LongLat_offset/rotation_rad'
 * '<S118>' : 'Spike/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
 * '<S119>' : 'Spike/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
 * '<S120>' : 'Spike/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
 * '<S121>' : 'Spike/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
 * '<S122>' : 'Spike/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S123>' : 'Spike/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S124>' : 'Spike/Incidence, Sideslip, & Airspeed/dot'
 * '<S125>' : 'Spike/Mach Number/dot'
 */
#endif                                 /* RTW_HEADER_Spike_h_ */
