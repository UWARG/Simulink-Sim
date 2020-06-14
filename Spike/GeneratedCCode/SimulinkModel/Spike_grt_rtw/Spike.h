/*
 * Spike.h
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

#ifndef RTW_HEADER_Spike_h_
#define RTW_HEADER_Spike_h_
#include <string.h>
#include <math.h>
#include <stdlib.h>
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
  real_T TmpSignalConversionAtphithetaps[3];/* '<S10>/phidot thetadot psidot' */
  real_T Selector[9];                  /* '<S11>/Selector' */
  real_T Selector1[9];                 /* '<S11>/Selector1' */
  real_T Selector2[9];                 /* '<S11>/Selector2' */
  real_T Product2[3];                  /* '<S11>/Product2' */
  real_T Sum[3];                       /* '<S1>/Sum' */
  real_T Product[3];                   /* '<S17>/Product' */
  real_T elevator;                     /* '<Root>/SeperateYawAndPitch' */
  real_T rudder;                       /* '<Root>/SeperateYawAndPitch' */
  real_T throttle;                     /* '<Root>/Read Throttle' */
  real_T aileron;                      /* '<Root>/Read Aileron' */
} B_Spike_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Product2_DWORK4[9];           /* '<S11>/Product2' */
  boolean_T eml_autoflush[20];         /* '<Root>/WriteToFile' */
  FILE * eml_openfiles[20];            /* '<Root>/Read Aileron' */
  FILE * eml_openfiles_j[20];          /* '<Root>/Read Tail left' */
  FILE * eml_openfiles_l[20];          /* '<Root>/Read Tail right' */
  FILE * eml_openfiles_e[20];          /* '<Root>/Read Throttle' */
  FILE * eml_openfiles_c[20];          /* '<Root>/WriteToFile' */
} DW_Spike_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S1>/ub,vb,wb' */
  real_T phithetapsi_CSTATE[3];        /* '<S10>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S1>/p,q,r ' */
  real_T xeyeze_CSTATE[3];             /* '<S1>/xe,ye,ze' */
} X_Spike_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_Spike_T[3];
typedef real_T PeriodicRngX_Spike_T[6];

/* State derivatives (default storage) */
typedef struct {
  real_T ubvbwb_CSTATE[3];             /* '<S1>/ub,vb,wb' */
  real_T phithetapsi_CSTATE[3];        /* '<S10>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S1>/p,q,r ' */
  real_T xeyeze_CSTATE[3];             /* '<S1>/xe,ye,ze' */
} XDot_Spike_T;

/* State disabled  */
typedef struct {
  boolean_T ubvbwb_CSTATE[3];          /* '<S1>/ub,vb,wb' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S10>/phi theta psi' */
  boolean_T pqr_CSTATE[3];             /* '<S1>/p,q,r ' */
  boolean_T xeyeze_CSTATE[3];          /* '<S1>/xe,ye,ze' */
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
  real_T uDOFEulerAngles_Vm_0[3];      /* Mask Parameter: uDOFEulerAngles_Vm_0
                                        * Referenced by: '<S1>/ub,vb,wb'
                                        */
  real_T uDOFEulerAngles_eul_0[3];     /* Mask Parameter: uDOFEulerAngles_eul_0
                                        * Referenced by: '<S10>/phi theta psi'
                                        */
  real_T uDOFEulerAngles_inertia[9];   /* Mask Parameter: uDOFEulerAngles_inertia
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T uDOFEulerAngles_mass_0;       /* Mask Parameter: uDOFEulerAngles_mass_0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T uDOFEulerAngles_pm_0[3];      /* Mask Parameter: uDOFEulerAngles_pm_0
                                        * Referenced by: '<S1>/p,q,r '
                                        */
  real_T uDOFEulerAngles_xme_0[3];     /* Mask Parameter: uDOFEulerAngles_xme_0
                                        * Referenced by: '<S1>/xe,ye,ze'
                                        */
  real_T phithetapsi_WrappedStateUpperVa;/* Expression: pi
                                          * Referenced by: '<S10>/phi theta psi'
                                          */
  real_T phithetapsi_WrappedStateLowerVa;/* Expression: -pi
                                          * Referenced by: '<S10>/phi theta psi'
                                          */
  real_T Constant2_Value[9];           /* Expression: zeros(3)
                                        * Referenced by: '<S12>/Constant2'
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

/* Block parameters (default storage) */
extern P_Spike_T Spike_P;

/* Block signals (default storage) */
extern B_Spike_T Spike_B;

/* Continuous states (default storage) */
extern X_Spike_T Spike_X;

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
 * '<S1>'   : 'Spike/6DOF (Euler Angles)'
 * '<S2>'   : 'Spike/External Forces and torques '
 * '<S3>'   : 'Spike/Forces and torques due to commands'
 * '<S4>'   : 'Spike/Read Aileron'
 * '<S5>'   : 'Spike/Read Tail left'
 * '<S6>'   : 'Spike/Read Tail right'
 * '<S7>'   : 'Spike/Read Throttle'
 * '<S8>'   : 'Spike/SeperateYawAndPitch'
 * '<S9>'   : 'Spike/WriteToFile'
 * '<S10>'  : 'Spike/6DOF (Euler Angles)/Calculate DCM & Euler Angles'
 * '<S11>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot'
 * '<S12>'  : 'Spike/6DOF (Euler Angles)/Determine Force,  Mass & Inertia'
 * '<S13>'  : 'Spike/6DOF (Euler Angles)/Vbxw'
 * '<S14>'  : 'Spike/6DOF (Euler Angles)/Velocity Conversion'
 * '<S15>'  : 'Spike/6DOF (Euler Angles)/Velocity Conversion1'
 * '<S16>'  : 'Spike/6DOF (Euler Angles)/Velocity Conversion2'
 * '<S17>'  : 'Spike/6DOF (Euler Angles)/transform to Inertial axes '
 * '<S18>'  : 'Spike/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix'
 * '<S19>'  : 'Spike/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phidot thetadot psidot'
 * '<S20>'  : 'Spike/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S21>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product'
 * '<S22>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/I x w'
 * '<S23>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/I x w1'
 * '<S24>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem'
 * '<S25>'  : 'Spike/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
 * '<S26>'  : 'Spike/6DOF (Euler Angles)/Vbxw/Subsystem'
 * '<S27>'  : 'Spike/6DOF (Euler Angles)/Vbxw/Subsystem1'
 */
#endif                                 /* RTW_HEADER_Spike_h_ */
