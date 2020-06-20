/*
 * Spike.h
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

#ifndef RTW_HEADER_Spike_h_
#define RTW_HEADER_Spike_h_
#include <string.h>
#include <cmath>
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
  P_Spike_T Spike_P;

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
  int8_T Spike_filedata_f(void);
  int8_T Spike_cfopen_p(const char * cfilename, const char * cpermission);
  void Spike_fclose_er(void);
  void Spike_emxInit_char_T(emxArray_char_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  void Spike_emxInit_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  void Spike_emxInit_int32_T(emxArray_int32_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  int8_T Spike_filedata_o(void);
  int8_T Spike_cfopen_g0(const char * cfilename, const char * cpermission);
  FILE * Spike_fileManager_l(real_T varargin_1);
  void Spike_emxInit_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  void Spike_emxEnsureCapacity_uint8_T(emxArray_uint8_T_Spike_T *emxArray,
    int32_T oldNumel);
  void Spike_emxEnsureCapacity_int32_T(emxArray_int32_T_Spike_T *emxArray,
    int32_T oldNumel);
  void Spike_emxFree_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray);
  void Spike_emxFree_int32_T(emxArray_int32_T_Spike_T **pEmxArray);
  void Spike_fclose_g(real_T fileID);
  void Spike_emxEnsureCapacity_char_T(emxArray_char_T_Spike_T *emxArray, int32_T
    oldNumel);
  void Spike_readfile_e(emxArray_char_T_Spike_T *y);
  void Spi_emxEnsureCapacity_boolean_T(emxArray_boolean_T_Spike_T *emxArray,
    int32_T oldNumel);
  void Spike_isstrprop(const emxArray_char_T_Spike_T *x,
                       emxArray_boolean_T_Spike_T *y);
  boolean_T Spike_ifWhileCond(const boolean_T x[2]);
  void Spike_emxInit_real_T(emxArray_real_T_Spike_T **pEmxArray, int32_T
    numDimensions);
  void Spike_emxEnsureCapacity_real_T(emxArray_real_T_Spike_T *emxArray, int32_T
    oldNumel);
  void Spike_char(const emxArray_real_T_Spike_T *varargin_1,
                  emxArray_char_T_Spike_T *y);
  void Spike_copysign(emxArray_char_T_Spike_T *s1, const emxArray_char_T_Spike_T
                      *s, int32_T *k, int32_T n, int32_T *idx, boolean_T
                      *success);
  void Spike_readNonFinite(const emxArray_char_T_Spike_T *s, int32_T *k, int32_T
    n, boolean_T *b_finite, real_T *fv);
  boolean_T Spike_copydigits(emxArray_char_T_Spike_T *s1, int32_T *idx, const
    emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowpoint);
  boolean_T Spike_copyexponent(emxArray_char_T_Spike_T *s1, int32_T *idx, const
    emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
  void Spike_skipspaces(const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
  boolean_T Spike_copysign_k(emxArray_char_T_Spike_T *s1, int32_T *idx, const
    emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
  void Spike_readfloat_p(emxArray_char_T_Spike_T *s1, int32_T *idx, const
    emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *isimag,
    boolean_T *b_finite, real_T *nfv, boolean_T *success);
  void Spike_readfloat(emxArray_char_T_Spike_T *s1, const
                       emxArray_char_T_Spike_T *s, int32_T n, int32_T *idx,
                       int32_T *k, boolean_T *isimag, boolean_T *b_finite,
                       real_T *nfv, boolean_T *success);
  void Spike_emxFree_real_T(emxArray_real_T_Spike_T **pEmxArray);
  void Spike_readfloat_pk(emxArray_char_T_Spike_T *s1, int32_T *idx, const
    emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *isimag,
    boolean_T *b_finite, real_T *nfv, boolean_T *success);
  real_T Spike_sscanfd_d(const emxArray_char_T_Spike_T *s);
  void Spike_sscanfd(const emxArray_char_T_Spike_T *s, real_T *out1, real_T
                     *out2);
  void Spike_emxFree_char_T(emxArray_char_T_Spike_T **pEmxArray);
  creal_T Spike_str2double(const emxArray_char_T_Spike_T *s);
  void Spike_fclose_gy(void);
  int8_T Spike_filedata(void);
  int8_T Spike_cfopen(const char * cfilename, const char * cpermission);
  FILE * Spike_fileManager(real_T varargin_1);
  void Spike_fclose(real_T fileID);
  void Spike_readfile(emxArray_char_T_Spike_T *y);
  void Spike_fclose_e(void);
  int8_T Spike_filedata_e(void);
  int8_T Spike_cfopen_m(const char * cfilename, const char * cpermission);
  FILE * Spike_fileManager_hw(real_T varargin_1);
  void Spike_fclose_m(real_T fileID);
  void Spike_readfile_f(emxArray_char_T_Spike_T *y);
  void Spike_fclose_m2(void);
  int8_T Spike_filedata_i(void);
  int8_T Spike_cfopen_g(const char * cfilename, const char * cpermission);
  FILE * Spike_fileManager_h(real_T varargin_1);
  void Spike_fclose_d(real_T fileID);
  void Spike_readfile_m(emxArray_char_T_Spike_T *y);
  void Spike_emxFree_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray);
  void Spike_fclose_dh(void);

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
