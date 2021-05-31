/*
 * Infinion.h
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
  real_T SinCos_o1;                    /* '<S50>/SinCos' */
  real_T SinCos_o2;                    /* '<S50>/SinCos' */
  real_T Switch;                       /* '<S58>/Switch' */
  real_T TrigonometricFunction1;       /* '<S64>/Trigonometric Function1' */
  real_T TrigonometricFunction2;       /* '<S64>/Trigonometric Function2' */
  real_T Switch_i;                     /* '<S59>/Switch' */
  real_T Product[3];                   /* '<S26>/Product' */
  real_T VectorConcatenate_b[9];       /* '<S46>/Vector Concatenate' */
  real_T Merge[3];                     /* '<S5>/Merge' */
  real_T Sum[3];                       /* '<S1>/Sum' */
  real_T TmpSignalConversionAtphithetaps[3];/* '<S19>/phidot thetadot psidot' */
  real_T Selector[9];                  /* '<S20>/Selector' */
  real_T Selector1[9];                 /* '<S20>/Selector1' */
  real_T Selector2[9];                 /* '<S20>/Selector2' */
  real_T Product2[3];                  /* '<S20>/Product2' */
  real_T forces[3];                    /* '<Root>/propulsion' */
  real_T torques[3];                   /* '<Root>/SimpleActuators' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_Infinion_T {
  real_T Product2_DWORK4[9];           /* '<S20>/Product2' */
  int8_T If_ActiveSubsystem;           /* '<S5>/If' */
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
  real_T phithetapsi_CSTATE[3];        /* '<S19>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S1>/p,q,r ' */
};

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_Infinion_T[3];
typedef real_T PeriodicRngX_Infinion_T[6];

/* State derivatives (default storage) */
struct XDot_Infinion_T {
  real_T ubvbwb_CSTATE[3];             /* '<S1>/ub,vb,wb' */
  real_T xeyeze_CSTATE[3];             /* '<S1>/xe,ye,ze' */
  real_T phithetapsi_CSTATE[3];        /* '<S19>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S1>/p,q,r ' */
};

/* State disabled  */
struct XDis_Infinion_T {
  boolean_T ubvbwb_CSTATE[3];          /* '<S1>/ub,vb,wb' */
  boolean_T xeyeze_CSTATE[3];          /* '<S1>/xe,ye,ze' */
  boolean_T phithetapsi_CSTATE[3];     /* '<S19>/phi theta psi' */
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
                                        * Referenced by: '<S4>/ref_position'
                                        */
  real_T uDOFEulerAngles_Vm_0[3];      /* Mask Parameter: uDOFEulerAngles_Vm_0
                                        * Referenced by: '<S1>/ub,vb,wb'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S62>/Constant'
                                       */
  real_T CompareToConstant_const_n; /* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S60>/Constant'
                                     */
  real_T CompareToConstant_const_c; /* Mask Parameter: CompareToConstant_const_c
                                     * Referenced by: '<S63>/Constant'
                                     */
  real_T CompareToConstant_const_e; /* Mask Parameter: CompareToConstant_const_e
                                     * Referenced by: '<S56>/Constant'
                                     */
  real_T CompareToConstant_const_p; /* Mask Parameter: CompareToConstant_const_p
                                     * Referenced by: '<S54>/Constant'
                                     */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S57>/Constant'
                                     */
  real_T uDOFEulerAngles_eul_0[3];     /* Mask Parameter: uDOFEulerAngles_eul_0
                                        * Referenced by: '<S19>/phi theta psi'
                                        */
  real_T uDOFEulerAngles_inertia[9];  /* Mask Parameter: uDOFEulerAngles_inertia
                                       * Referenced by: '<S21>/Constant1'
                                       */
  real_T uDOFEulerAngles_mass_0;       /* Mask Parameter: uDOFEulerAngles_mass_0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T uDOFEulerAngles_pm_0[3];      /* Mask Parameter: uDOFEulerAngles_pm_0
                                        * Referenced by: '<S1>/p,q,r '
                                        */
  real_T FlatEarthtoLLA_psi;           /* Mask Parameter: FlatEarthtoLLA_psi
                                        * Referenced by: '<S4>/ref_rotation'
                                        */
  real_T uDOFEulerAngles_xme_0[3];     /* Mask Parameter: uDOFEulerAngles_xme_0
                                        * Referenced by: '<S1>/xe,ye,ze'
                                        */
  real_T Bias_Bias;                    /* Expression: -90
                                        * Referenced by: '<S52>/Bias'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S52>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: +90
                                        * Referenced by: '<S52>/Bias1'
                                        */
  real_T Bias_Bias_m;                  /* Expression: 180
                                        * Referenced by: '<S55>/Bias'
                                        */
  real_T Bias1_Bias_j;                 /* Expression: -180
                                        * Referenced by: '<S55>/Bias1'
                                        */
  real_T Bias_Bias_k;                  /* Expression: 180
                                        * Referenced by: '<S53>/Bias'
                                        */
  real_T Bias1_Bias_g;                 /* Expression: -180
                                        * Referenced by: '<S53>/Bias1'
                                        */
  real_T Bias_Bias_n;                  /* Expression: -90
                                        * Referenced by: '<S58>/Bias'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S58>/Gain'
                                        */
  real_T Bias1_Bias_a;                 /* Expression: +90
                                        * Referenced by: '<S58>/Bias1'
                                        */
  real_T Constant2_Value;              /* Expression: 360
                                        * Referenced by: '<S61>/Constant2'
                                        */
  real_T Bias_Bias_o;                  /* Expression: 180
                                        * Referenced by: '<S61>/Bias'
                                        */
  real_T Bias1_Bias_jw;                /* Expression: -180
                                        * Referenced by: '<S61>/Bias1'
                                        */
  real_T Constant_Value;               /* Expression: 180
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S49>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 360
                                        * Referenced by: '<S59>/Constant2'
                                        */
  real_T Bias_Bias_f;                  /* Expression: 180
                                        * Referenced by: '<S59>/Bias'
                                        */
  real_T Bias1_Bias_b;                 /* Expression: -180
                                        * Referenced by: '<S59>/Bias1'
                                        */
  real_T Constant_Value_m[3];          /* Expression: [0 0 0]
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -100
                                        * Referenced by: '<S71>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S71>/Gain1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0
                                        * Referenced by: '<S71>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -inf
                                        * Referenced by: '<S71>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S71>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -inf
                                        * Referenced by: '<S71>/Saturation1'
                                        */
  real_T HNLLat_Value;                 /* Expression: 21.322
                                        * Referenced by: '<Root>/HNLLat'
                                        */
  real_T Constant2_Value_d;            /* Expression: 1
                                        * Referenced by: '<S64>/Constant2'
                                        */
  real_T Constant1_Value_k;            /* Expression: R
                                        * Referenced by: '<S64>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S67>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T Constant_Value_j3;            /* Expression: F
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T f_Value;                      /* Expression: 1
                                        * Referenced by: '<S68>/f'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S64>/Constant3'
                                        */
  real_T Constant2_Value_e;            /* Expression: 360
                                        * Referenced by: '<S55>/Constant2'
                                        */
  real_T HNLLong_Value;                /* Expression: -157.924
                                        * Referenced by: '<Root>/HNLLong'
                                        */
  real_T Constant_Value_o;             /* Expression: 180
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 360
                                        * Referenced by: '<S53>/Constant2'
                                        */
  real_T Constant_Value_ml;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T phithetapsi_WrappedStateUpperVa;/* Expression: pi
                                          * Referenced by: '<S19>/phi theta psi'
                                          */
  real_T phithetapsi_WrappedStateLowerVa;/* Expression: -pi
                                          * Referenced by: '<S19>/phi theta psi'
                                          */
  real_T Constant_Value_jt;            /* Expression: 0
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Merge_InitialOutput[3];       /* Expression: [0 0 0]
                                        * Referenced by: '<S5>/Merge'
                                        */
  real_T Constant2_Value_f[9];         /* Expression: zeros(3)
                                        * Referenced by: '<S21>/Constant2'
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
  void Infinion_emxInit_boolean_T(emxArray_boolean_T_Infinion_T **pEmxArray,
    int32_T numDimensions);
  int8_T Infinion_filedata_k(void);
  int8_T Infinion_cfopen_k(const char_T *cfilename, const char_T *cpermission);
  real_T Infinion_fileManager_e(void);
  FILE * Infinion_fileManager_e4(real_T varargin_1);
  void Infinion_fseek_c(real_T fileID);
  real_T Infinion_ftell_b(real_T fileID);
  void Infinion_fseek_cn(real_T fileID);
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
  void Infinion_fread_j(real_T fileID, int32_T sizeA, emxArray_real_T_Infinion_T
                        *A, real_T *count);
  void Infinion_emxFree_real_T(emxArray_real_T_Infinion_T **pEmxArray);
  int32_T Infinion_cfclose_i(real_T fid);
  void Infini_emxEnsureCapacity_char_T(emxArray_char_T_Infinion_T *emxArray,
    int32_T oldNumel);
  void Infinion_char(const emxArray_uint8_T_Infinion_T *varargin_1,
                     emxArray_char_T_Infinion_T *y);
  void Infinion_readfile_e(emxArray_char_T_Infinion_T *y);
  void Infinion_deblank(const emxArray_char_T_Infinion_T *x,
                        emxArray_char_T_Infinion_T *y);
  void Inf_emxEnsureCapacity_boolean_T(emxArray_boolean_T_Infinion_T *emxArray,
    int32_T oldNumel);
  void Infinion_isspace(const emxArray_char_T_Infinion_T *x,
                        emxArray_boolean_T_Infinion_T *y);
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
  int8_T Infinion_filedata(void);
  int8_T Infinion_cfopen(const char_T *cfilename, const char_T *cpermission);
  real_T Infinion_fileManager(void);
  FILE * Infinion_fileManager_b(real_T varargin_1);
  void Infinion_fseek(real_T fileID);
  real_T Infinion_ftell(real_T fileID);
  void Infinion_fseek_m(real_T fileID);
  void Infinion_fread(real_T fileID, int32_T sizeA, emxArray_real_T_Infinion_T
                      *A, real_T *count);
  int32_T Infinion_cfclose(real_T fid);
  void Infinion_readfile(emxArray_char_T_Infinion_T *y);
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
  void Infinion_emxFree_boolean_T(emxArray_boolean_T_Infinion_T **pEmxArray);

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
 * '<S2>'   : 'Infinion/Direction Cosine Matrix Body to Wind'
 * '<S3>'   : 'Infinion/Dynamic Pressure'
 * '<S4>'   : 'Infinion/Flat Earth to LLA'
 * '<S5>'   : 'Infinion/Ground model'
 * '<S6>'   : 'Infinion/Incidence, Sideslip, & Airspeed'
 * '<S7>'   : 'Infinion/Mach Number'
 * '<S8>'   : 'Infinion/Read Aileron'
 * '<S9>'   : 'Infinion/Read Elevator'
 * '<S10>'  : 'Infinion/Read Rudder'
 * '<S11>'  : 'Infinion/Read Throttle'
 * '<S12>'  : 'Infinion/SimpleActuators'
 * '<S13>'  : 'Infinion/SimpleDrag'
 * '<S14>'  : 'Infinion/SimpleLift'
 * '<S15>'  : 'Infinion/WriteToFile'
 * '<S16>'  : 'Infinion/compute track'
 * '<S17>'  : 'Infinion/gravity'
 * '<S18>'  : 'Infinion/propulsion'
 * '<S19>'  : 'Infinion/6DOF (Euler Angles)/Calculate DCM & Euler Angles'
 * '<S20>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot'
 * '<S21>'  : 'Infinion/6DOF (Euler Angles)/Determine Force,  Mass & Inertia'
 * '<S22>'  : 'Infinion/6DOF (Euler Angles)/Vbxw'
 * '<S23>'  : 'Infinion/6DOF (Euler Angles)/Velocity Conversion'
 * '<S24>'  : 'Infinion/6DOF (Euler Angles)/Velocity Conversion1'
 * '<S25>'  : 'Infinion/6DOF (Euler Angles)/Velocity Conversion2'
 * '<S26>'  : 'Infinion/6DOF (Euler Angles)/transform to Inertial axes '
 * '<S27>'  : 'Infinion/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix'
 * '<S28>'  : 'Infinion/6DOF (Euler Angles)/Calculate DCM & Euler Angles/phidot thetadot psidot'
 * '<S29>'  : 'Infinion/6DOF (Euler Angles)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S30>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product'
 * '<S31>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/I x w'
 * '<S32>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/I x w1'
 * '<S33>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem'
 * '<S34>'  : 'Infinion/6DOF (Euler Angles)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
 * '<S35>'  : 'Infinion/6DOF (Euler Angles)/Vbxw/Subsystem'
 * '<S36>'  : 'Infinion/6DOF (Euler Angles)/Vbxw/Subsystem1'
 * '<S37>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A11'
 * '<S38>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A12'
 * '<S39>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A13'
 * '<S40>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A21'
 * '<S41>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A22'
 * '<S42>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A23'
 * '<S43>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A31'
 * '<S44>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A32'
 * '<S45>'  : 'Infinion/Direction Cosine Matrix Body to Wind/A33'
 * '<S46>'  : 'Infinion/Direction Cosine Matrix Body to Wind/Create Transformation Matrix'
 * '<S47>'  : 'Infinion/Dynamic Pressure/dot'
 * '<S48>'  : 'Infinion/Flat Earth to LLA/LatLong wrap'
 * '<S49>'  : 'Infinion/Flat Earth to LLA/LatLong wrap1'
 * '<S50>'  : 'Infinion/Flat Earth to LLA/LongLat_offset'
 * '<S51>'  : 'Infinion/Flat Earth to LLA/pos_deg'
 * '<S52>'  : 'Infinion/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
 * '<S53>'  : 'Infinion/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
 * '<S54>'  : 'Infinion/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S55>'  : 'Infinion/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S56>'  : 'Infinion/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S57>'  : 'Infinion/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S58>'  : 'Infinion/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
 * '<S59>'  : 'Infinion/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
 * '<S60>'  : 'Infinion/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
 * '<S61>'  : 'Infinion/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
 * '<S62>'  : 'Infinion/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S63>'  : 'Infinion/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
 * '<S64>'  : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
 * '<S65>'  : 'Infinion/Flat Earth to LLA/LongLat_offset/rotation_rad'
 * '<S66>'  : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
 * '<S67>'  : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
 * '<S68>'  : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
 * '<S69>'  : 'Infinion/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
 * '<S70>'  : 'Infinion/Ground model/Body2Inertial'
 * '<S71>'  : 'Infinion/Ground model/If Action Subsystem1'
 * '<S72>'  : 'Infinion/Ground model/If Action Subsystem2'
 * '<S73>'  : 'Infinion/Ground model/Inertial2Body'
 * '<S74>'  : 'Infinion/Incidence, Sideslip, & Airspeed/Subsystem'
 * '<S75>'  : 'Infinion/Incidence, Sideslip, & Airspeed/Subsystem1'
 * '<S76>'  : 'Infinion/Incidence, Sideslip, & Airspeed/dot'
 * '<S77>'  : 'Infinion/Mach Number/dot'
 */
#endif                                 /* RTW_HEADER_Infinion_h_ */
