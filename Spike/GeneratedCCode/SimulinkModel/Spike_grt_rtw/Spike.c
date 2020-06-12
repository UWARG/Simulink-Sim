/*
 * Spike.c
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

/* Block signals (default storage) */
B_Spike_T Spike_B;

/* Continuous states */
X_Spike_T Spike_X;

/* Periodic continuous states */
PeriodicIndX_Spike_T Spike_PeriodicIndX;
PeriodicRngX_Spike_T Spike_PeriodicRngX;

/* Block states (default storage) */
DW_Spike_T Spike_DW;

/* Real-time model */
RT_MODEL_Spike_T Spike_M_;
RT_MODEL_Spike_T *const Spike_M = &Spike_M_;

/* Forward declaration for local functions */
static int8_T Spike_filedata_f(void);
static int8_T Spike_cfopen_p(const char * cfilename, const char * cpermission);
static void Spike_fclose_er(void);
static void Spike_emxInit_char_T(emxArray_char_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static void Spike_emxInit_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray,
  int32_T numDimensions);
static void Spike_emxInit_int32_T(emxArray_int32_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static int8_T Spike_filedata_o(void);
static int8_T Spike_cfopen_g0(const char * cfilename, const char * cpermission);
static FILE * Spike_fileManager_l(real_T varargin_1);
static void Spike_emxInit_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static void Spike_emxEnsureCapacity_uint8_T(emxArray_uint8_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_emxEnsureCapacity_int32_T(emxArray_int32_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_emxFree_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray);
static void Spike_emxFree_int32_T(emxArray_int32_T_Spike_T **pEmxArray);
static void Spike_fclose_g(real_T fileID);
static void Spike_emxEnsureCapacity_char_T(emxArray_char_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_readfile_e(emxArray_char_T_Spike_T *y);
static void Spi_emxEnsureCapacity_boolean_T(emxArray_boolean_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_isstrprop(const emxArray_char_T_Spike_T *x,
  emxArray_boolean_T_Spike_T *y);
static boolean_T Spike_ifWhileCond(const boolean_T x[2]);
static void Spike_emxInit_real_T(emxArray_real_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static void Spike_emxEnsureCapacity_real_T(emxArray_real_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_char(const emxArray_real_T_Spike_T *varargin_1,
  emxArray_char_T_Spike_T *y);
static void Spike_copysign(emxArray_char_T_Spike_T *s1, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, int32_T *idx, boolean_T
  *success);
static void Spike_readNonFinite(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n, boolean_T *b_finite, real_T *fv);
static boolean_T Spike_copydigits(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowpoint);
static boolean_T Spike_copyexponent(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
static void Spike_skipspaces(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n);
static boolean_T Spike_copysign_k(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
static void Spike_readfloat_p(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *success);
static void Spike_readfloat(emxArray_char_T_Spike_T *s1, const
  emxArray_char_T_Spike_T *s, int32_T n, int32_T *idx, int32_T *k, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *success);
static void Spike_emxFree_real_T(emxArray_real_T_Spike_T **pEmxArray);
static void Spike_readfloat_pk(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *success);
static real_T Spike_sscanfd_d(const emxArray_char_T_Spike_T *s);
static void Spike_sscanfd(const emxArray_char_T_Spike_T *s, real_T *out1, real_T
  *out2);
static void Spike_emxFree_char_T(emxArray_char_T_Spike_T **pEmxArray);
static creal_T Spike_str2double(const emxArray_char_T_Spike_T *s);
static void Spike_fclose_gy(void);
static int8_T Spike_filedata(void);
static int8_T Spike_cfopen(const char * cfilename, const char * cpermission);
static FILE * Spike_fileManager(real_T varargin_1);
static void Spike_fclose(real_T fileID);
static void Spike_readfile(emxArray_char_T_Spike_T *y);
static void Spike_fclose_e(void);
static int8_T Spike_filedata_e(void);
static int8_T Spike_cfopen_m(const char * cfilename, const char * cpermission);
static FILE * Spike_fileManager_hw(real_T varargin_1);
static void Spike_fclose_m(real_T fileID);
static void Spike_readfile_f(emxArray_char_T_Spike_T *y);
static void Spike_fclose_m2(void);
static int8_T Spike_filedata_i(void);
static int8_T Spike_cfopen_g(const char * cfilename, const char * cpermission);
static FILE * Spike_fileManager_h(real_T varargin_1);
static void Spike_fclose_d(real_T fileID);
static void Spike_readfile_m(emxArray_char_T_Spike_T *y);
static void Spike_emxFree_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray);
static void Spike_fclose_dh(void);

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Spike_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Spike_step();
  Spike_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Spike_step();
  Spike_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  local_stateReduction(x, rtsiGetPeriodicContStateIndices(si), 3,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
static int8_T Spike_filedata_f(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_c[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
static int8_T Spike_cfopen_p(const char * cfilename, const char * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_f();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_c[j - 1] = filestar;
      Spike_DW.eml_autoflush[j - 1] = true;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
static void Spike_fclose_er(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles_c[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles_c[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles_c[j] = NULL;
        Spike_DW.eml_autoflush[j] = true;
      }
    }
  }
}

static void Spike_emxInit_char_T(emxArray_char_T_Spike_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_char_T_Spike_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Spike_T *)malloc(sizeof(emxArray_char_T_Spike_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Spike_emxInit_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_boolean_T_Spike_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_Spike_T *)malloc(sizeof
    (emxArray_boolean_T_Spike_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Spike_emxInit_int32_T(emxArray_int32_T_Spike_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_int32_T_Spike_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T_Spike_T *)malloc(sizeof
    (emxArray_int32_T_Spike_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
static int8_T Spike_filedata_o(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_e[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
static int8_T Spike_cfopen_g0(const char * cfilename, const char * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_o();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_e[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
static FILE * Spike_fileManager_l(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = (int8_T)rt_roundd_snf(varargin_1);
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_e[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else if (fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  return f;
}

static void Spike_emxInit_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_uint8_T_Spike_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_uint8_T_Spike_T *)malloc(sizeof
    (emxArray_uint8_T_Spike_T));
  emxArray = *pEmxArray;
  emxArray->data = (uint8_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Spike_emxEnsureCapacity_uint8_T(emxArray_uint8_T_Spike_T *emxArray,
  int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(uint8_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(uint8_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (uint8_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void Spike_emxEnsureCapacity_int32_T(emxArray_int32_T_Spike_T *emxArray,
  int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void Spike_emxFree_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T_Spike_T *)NULL) {
    if (((*pEmxArray)->data != (uint8_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T_Spike_T *)NULL;
  }
}

static void Spike_emxFree_int32_T(emxArray_int32_T_Spike_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T_Spike_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T_Spike_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
static void Spike_fclose_g(real_T fileID)
{
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  fileid = (int8_T)rt_roundd_snf(fileID);
  if ((fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Spike_DW.eml_openfiles_e[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  if ((f != NULL) && (fileid >= 3)) {
    cst = fclose(f);
    if (cst == 0) {
      Spike_DW.eml_openfiles_e[fileid - 3] = NULL;
    }
  }
}

static void Spike_emxEnsureCapacity_char_T(emxArray_char_T_Spike_T *emxArray,
  int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
static void Spike_readfile_e(emxArray_char_T_Spike_T *y)
{
  int32_T remaining;
  int32_T b_index;
  emxArray_int32_T_Spike_T *e;
  int8_T fileid;
  int wherefrom;
  FILE * filestar;
  real_T position;
  long position_t;
  emxArray_uint8_T_Spike_T *A;
  size_t nBytes;
  int32_T numRequested;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T c_numRead;
  size_t numReadSizeT;
  int32_T buf_size_idx_0;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Spike_cfopen_g0("throttle.txt", "rb");
  wherefrom = SEEK_END;
  filestar = Spike_fileManager_l((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  filestar = Spike_fileManager_l((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(filestar);
    position = (real_T)position_t;
  }

  position = rt_roundd_snf(position);
  if (position < 2.147483648E+9) {
    if (position >= -2.147483648E+9) {
      i = (int32_T)position;
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  filestar = Spike_fileManager_l((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  memset(&Spike_B.buffer_k[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Spike_emxInit_int32_T(&e, 2);
  Spike_emxInit_uint8_T(&A, 1);
  exitg1 = false;
  while ((!exitg1) && (remaining > 0)) {
    if (b_index > MAX_int32_T - remaining) {
      bytesOut = MAX_int32_T;
    } else {
      bytesOut = remaining + b_index;
    }

    if (bytesOut > 65536) {
      printf("Attempt to read file which is bigger than internal buffer.\n");
      fflush(stdout);
      printf("Current buffer size is %d bytes and file size is %d bytes.\n",
             65536, i);
      fflush(stdout);
      exitg1 = true;
    } else {
      nBytes = sizeof(char_T);
      filestar = Spike_fileManager_l((real_T)fileid);
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        filestar = NULL;
      }

      if (filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = (int16_T)remaining;
        }

        bytesOut = 0;
        numRead = 1;
        buf_size_idx_0 = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          numRequested = buf_size_idx_0;
          numRead = remaining - bytesOut;
          if (buf_size_idx_0 > numRead) {
            numRequested = numRead;
          }

          buf_size_idx_0 = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < numRequested) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, numRequested -
                                 numRead, filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (numRequested = 0; numRequested < numRead; numRequested++) {
            A->data[numRequested + bytesOut] = (uint8_T)buf_data[numRequested];
          }

          bytesOut += numRead;
        }

        numRequested = A->size[0];
        for (numRead = bytesOut; numRead < numRequested; numRead++) {
          A->data[numRead] = 0U;
        }

        if (bytesOut < remaining) {
          buf_size_idx_0 = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        }
      }

      position = (real_T)b_index + (real_T)bytesOut;
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          numRequested = (int32_T)position;
        } else {
          numRequested = MIN_int32_T;
        }
      } else {
        numRequested = MAX_int32_T;
      }

      if (b_index > numRequested - 1) {
        numRead = 1;
        numRequested = 1;
      } else {
        numRead = b_index;
      }

      buf_size_idx_0 = e->size[0] * e->size[1];
      e->size[0] = 1;
      numRequested -= numRead;
      e->size[1] = numRequested;
      Spike_emxEnsureCapacity_int32_T(e, buf_size_idx_0);
      for (buf_size_idx_0 = 0; buf_size_idx_0 < numRequested; buf_size_idx_0++)
      {
        e->data[buf_size_idx_0] = (numRead + buf_size_idx_0) - 1;
      }

      numRequested = e->size[0] * e->size[1];
      for (buf_size_idx_0 = 0; buf_size_idx_0 < numRequested; buf_size_idx_0++)
      {
        Spike_B.buffer_k[e->data[buf_size_idx_0]] = A->data[buf_size_idx_0];
      }

      if (bytesOut == 0) {
        exitg1 = true;
      } else if (bytesOut < 0) {
        printf("Could not read from file: %d.\n", bytesOut);
        fflush(stdout);
        exitg1 = true;
      } else {
        remaining -= bytesOut;
        if ((b_index < 0) && (bytesOut < MIN_int32_T - b_index)) {
          b_index = MIN_int32_T;
        } else if ((b_index > 0) && (bytesOut > MAX_int32_T - b_index)) {
          b_index = MAX_int32_T;
        } else {
          b_index += bytesOut;
        }
      }
    }
  }

  Spike_emxFree_uint8_T(&A);
  Spike_emxFree_int32_T(&e);
  Spike_fclose_g((real_T)fileid);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = (int8_T)Spike_B.buffer_k[i];
  }
}

static void Spi_emxEnsureCapacity_boolean_T(emxArray_boolean_T_Spike_T *emxArray,
  int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_isstrprop(const emxArray_char_T_Spike_T *x,
  emxArray_boolean_T_Spike_T *y)
{
  int32_T k;
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  Spi_emxEnsureCapacity_boolean_T(y, k);
  for (k = 0; k < x->size[1]; k++) {
    y->data[k] = b[(uint8_T)x->data[k] & 127];
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static boolean_T Spike_ifWhileCond(const boolean_T x[2])
{
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

static void Spike_emxInit_real_T(emxArray_real_T_Spike_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_real_T_Spike_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_Spike_T *)malloc(sizeof(emxArray_real_T_Spike_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Spike_emxEnsureCapacity_real_T(emxArray_real_T_Spike_T *emxArray,
  int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_char(const emxArray_real_T_Spike_T *varargin_1,
  emxArray_char_T_Spike_T *y)
{
  int32_T loop_ub;
  int32_T i;
  real_T tmp;
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_1->size[1];
  Spike_emxEnsureCapacity_char_T(y, i);
  loop_ub = varargin_1->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    tmp = trunc(varargin_1->data[i]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    y->data[i] = (int8_T)(tmp < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-tmp :
                          (int32_T)(int8_T)(uint8_T)tmp);
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_copysign(emxArray_char_T_Spike_T *s1, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, int32_T *idx, boolean_T
  *success)
{
  boolean_T isneg;
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  *k = 1;
  *idx = 1;
  isneg = false;
  while ((*k <= n) && ((s->data[*k - 1] == '+') || (s->data[*k - 1] == '-') ||
                       b[(uint8_T)s->data[*k - 1] & 127])) {
    if (s->data[*k - 1] == '-') {
      isneg = !isneg;
    }

    (*k)++;
  }

  *success = (*k <= n);
  if ((*success) && isneg) {
    s1->data[0] = '-';
    *idx = 2;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_readNonFinite(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n, boolean_T *b_finite, real_T *fv)
{
  *b_finite = true;
  *fv = 0.0;
  if (*k + 2 <= n) {
    if (((s->data[*k - 1] == 'I') || (s->data[*k - 1] == 'i')) && ((s->data[*k] ==
          'N') || (s->data[*k] == 'n')) && ((s->data[*k + 1] == 'F') || (s->
          data[*k + 1] == 'f'))) {
      *b_finite = false;
      *fv = (rtInf);
      *k += 3;
    } else {
      if (((s->data[*k - 1] == 'N') || (s->data[*k - 1] == 'n')) && ((s->data[*k]
            == 'A') || (s->data[*k] == 'a')) && ((s->data[*k + 1] == 'N') ||
           (s->data[*k + 1] == 'n'))) {
        *b_finite = false;
        *fv = (rtNaN);
        *k += 3;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static boolean_T Spike_copydigits(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowpoint)
{
  boolean_T success;
  boolean_T haspoint;
  boolean_T exitg1;
  success = (*k <= n);
  haspoint = !allowpoint;
  exitg1 = false;
  while ((!exitg1) && (*k <= n)) {
    if ((s->data[*k - 1] >= '0') && (s->data[*k - 1] <= '9')) {
      s1->data[*idx - 1] = s->data[*k - 1];
      (*idx)++;
      (*k)++;
    } else if (s->data[*k - 1] == '.') {
      if (haspoint) {
        success = false;
        exitg1 = true;
      } else {
        s1->data[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
        (*k)++;
      }
    } else if (s->data[*k - 1] != ',') {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static boolean_T Spike_copyexponent(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n)
{
  boolean_T success;
  success = true;
  if ((*k <= n) && ((s->data[*k - 1] == 'E') || (s->data[*k - 1] == 'e'))) {
    s1->data[*idx - 1] = 'e';
    (*idx)++;
    (*k)++;
    if (*k <= n) {
      if (s->data[*k - 1] == '-') {
        s1->data[*idx - 1] = '-';
        (*idx)++;
        (*k)++;
      } else {
        if (s->data[*k - 1] == '+') {
          (*k)++;
        }
      }
    }

    success = Spike_copydigits(s1, idx, s, k, n, false);
  }

  return success;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_skipspaces(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n)
{
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  while ((*k <= n) && b[(uint8_T)s->data[*k - 1] & 127]) {
    (*k)++;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static boolean_T Spike_copysign_k(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n)
{
  boolean_T success;
  boolean_T isneg;
  static const boolean_T b[128] = { true, false, false, false, false, false,
    false, false, false, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false };

  isneg = false;
  while ((*k <= n) && ((s->data[*k - 1] == '+') || (s->data[*k - 1] == '-') ||
                       b[(uint8_T)s->data[*k - 1] & 127])) {
    if (s->data[*k - 1] == '-') {
      isneg = !isneg;
    }

    (*k)++;
  }

  success = (*k <= n);
  if (success && isneg) {
    if ((*idx >= 2) && (s1->data[*idx - 2] == '-')) {
      s1->data[*idx - 2] = ' ';
    } else {
      s1->data[*idx - 1] = '-';
      (*idx)++;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_readfloat_p(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *success)
{
  int32_T b_idx;
  int32_T b_k;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_idx = *idx;
  b_k = *k;
  *success = Spike_copysign_k(s1, &b_idx, s, &b_k, n);
  *idx = b_idx;
  *k = b_k;
  if (*success) {
    if ((b_k <= n) && ((s->data[b_k - 1] == 'j') || ((s->data[b_k - 1] == 'i') &&
          ((b_k == n) || ((s->data[b_k] != 'n') && (s->data[b_k] != 'N')))))) {
      *success = false;
    } else {
      Spike_readNonFinite(s, &b_k, n, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = Spike_copydigits(s1, &b_idx, s, &b_k, n, true);
        *idx = b_idx;
        *k = b_k;
        if (*success) {
          *success = Spike_copyexponent(s1, idx, s, k, n);
        }
      } else {
        if ((b_idx >= 2) && (s1->data[b_idx - 2] == '-')) {
          *idx = b_idx - 1;
          s1->data[b_idx - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      Spike_skipspaces(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Spike_skipspaces(s, k, n);
      }

      if ((*k <= n) && ((s->data[*k - 1] == 'i') || (s->data[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    Spike_skipspaces(s, k, n);
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_readfloat(emxArray_char_T_Spike_T *s1, const
  emxArray_char_T_Spike_T *s, int32_T n, int32_T *idx, int32_T *k, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *success)
{
  boolean_T unusedU0;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  *k = 1;
  Spike_copysign(s1, s, k, n, idx, success);
  if (*success) {
    if ((*k <= n) && ((s->data[*k - 1] == 'j') || ((s->data[*k - 1] == 'i') &&
          ((*k == n) || ((s->data[*k] != 'n') && (s->data[*k] != 'N')))))) {
      *isimag = true;
      (*k)++;
      Spike_skipspaces(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Spike_readfloat_p(s1, idx, s, k, n, &unusedU0, b_finite, nfv, success);
      } else {
        s1->data[*idx - 1] = '1';
        (*idx)++;
      }
    } else {
      Spike_readNonFinite(s, k, n, b_finite, nfv);
      if (*b_finite) {
        *success = Spike_copydigits(s1, idx, s, k, n, true);
        if (*success) {
          *success = Spike_copyexponent(s1, idx, s, k, n);
        }
      } else {
        if ((*idx >= 2) && (s1->data[0] == '-')) {
          *idx = 1;
          s1->data[0] = ' ';
          *nfv = -*nfv;
        }
      }

      Spike_skipspaces(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Spike_skipspaces(s, k, n);
      }

      if ((*k <= n) && ((s->data[*k - 1] == 'i') || (s->data[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    Spike_skipspaces(s, k, n);
  }
}

static void Spike_emxFree_real_T(emxArray_real_T_Spike_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_Spike_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Spike_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_readfloat_pk(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *success)
{
  int32_T b_idx;
  int32_T b_k;
  boolean_T unusedU0;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_idx = *idx;
  b_k = *k;
  *success = Spike_copysign_k(s1, &b_idx, s, &b_k, n);
  *idx = b_idx;
  *k = b_k;
  if (*success) {
    if ((b_k <= n) && ((s->data[b_k - 1] == 'j') || ((s->data[b_k - 1] == 'i') &&
          ((b_k == n) || ((s->data[b_k] != 'n') && (s->data[b_k] != 'N')))))) {
      *isimag = true;
      *k = b_k + 1;
      Spike_skipspaces(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Spike_readfloat_p(s1, idx, s, k, n, &unusedU0, b_finite, nfv, success);
      } else {
        s1->data[b_idx - 1] = '1';
        *idx = b_idx + 1;
      }
    } else {
      Spike_readNonFinite(s, &b_k, n, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = Spike_copydigits(s1, &b_idx, s, &b_k, n, true);
        *idx = b_idx;
        *k = b_k;
        if (*success) {
          *success = Spike_copyexponent(s1, idx, s, k, n);
        }
      } else {
        if ((b_idx >= 2) && (s1->data[b_idx - 2] == '-')) {
          *idx = b_idx - 1;
          s1->data[b_idx - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      Spike_skipspaces(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Spike_skipspaces(s, k, n);
      }

      if ((*k <= n) && ((s->data[*k - 1] == 'i') || (s->data[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    Spike_skipspaces(s, k, n);
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static real_T Spike_sscanfd_d(const emxArray_char_T_Spike_T *s)
{
  real_T out1;
  int32_T nread;
  nread = sscanf(&s->data[0], "%lf", &out1);
  if (nread != 1) {
    out1 = (rtNaN);
  }

  return out1;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_sscanfd(const emxArray_char_T_Spike_T *s, real_T *out1, real_T
  *out2)
{
  int32_T nread;
  nread = sscanf(&s->data[0], "%lf %lf", out1, out2);
  if (nread != 2) {
    *out1 = (rtNaN);
    *out2 = (rtNaN);
  }
}

static void Spike_emxFree_char_T(emxArray_char_T_Spike_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Spike_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Spike_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static creal_T Spike_str2double(const emxArray_char_T_Spike_T *s)
{
  creal_T x;
  emxArray_char_T_Spike_T *s1;
  int32_T idx;
  int32_T ntoread;
  real_T v1;
  boolean_T success;
  real_T v2;
  real_T a;
  boolean_T isimag1;
  boolean_T isfinite1;
  boolean_T isfinite2;
  boolean_T c_success;
  emxArray_real_T_Spike_T *tmp;
  int32_T loop_ub;
  x.re = (rtNaN);
  x.im = 0.0;
  if (s->size[1] >= 1) {
    Spike_emxInit_real_T(&tmp, 2);
    ntoread = 0;
    idx = tmp->size[0] * tmp->size[1];
    tmp->size[0] = 1;
    tmp->size[1] = s->size[1] + 2;
    Spike_emxEnsureCapacity_real_T(tmp, idx);
    loop_ub = s->size[1] + 2;
    for (idx = 0; idx < loop_ub; idx++) {
      tmp->data[idx] = 0.0;
    }

    Spike_emxInit_char_T(&s1, 2);
    Spike_char(tmp, s1);
    Spike_readfloat(s1, s, s->size[1], &idx, &loop_ub, &isimag1, &isfinite1, &v1,
                    &success);
    Spike_emxFree_real_T(&tmp);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success && (loop_ub <= s->size[1])) {
      s1->data[idx - 1] = ' ';
      idx++;
      Spike_readfloat_pk(s1, &idx, s, &loop_ub, s->size[1], &success, &isfinite2,
                         &v2, &c_success);
      if (isfinite2) {
        ntoread++;
      }

      if (c_success && (loop_ub > s->size[1]) && ((isimag1 ^ success) != 0)) {
        success = true;
      } else {
        success = false;
      }
    } else {
      v2 = 0.0;
    }

    if (success) {
      s1->data[idx - 1] = '\x00';
      if (ntoread == 2) {
        Spike_sscanfd(s1, &v1, &v2);
      } else {
        if (ntoread == 1) {
          a = Spike_sscanfd_d(s1);
          if (isfinite1) {
            v1 = a;
          } else {
            v2 = a;
          }
        }
      }

      if (isimag1) {
        x.re = v2;
        x.im = v1;
      } else {
        x.re = v1;
        x.im = v2;
      }
    }

    Spike_emxFree_char_T(&s1);
  }

  return x;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
static void Spike_fclose_gy(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles_e[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles_e[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles_e[j] = NULL;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static int8_T Spike_filedata(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static int8_T Spike_cfopen(const char * cfilename, const char * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static FILE * Spike_fileManager(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = (int8_T)rt_roundd_snf(varargin_1);
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else if (fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_fclose(real_T fileID)
{
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  fileid = (int8_T)rt_roundd_snf(fileID);
  if ((fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Spike_DW.eml_openfiles[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  if ((f != NULL) && (fileid >= 3)) {
    cst = fclose(f);
    if (cst == 0) {
      Spike_DW.eml_openfiles[fileid - 3] = NULL;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_readfile(emxArray_char_T_Spike_T *y)
{
  int32_T remaining;
  int32_T b_index;
  emxArray_int32_T_Spike_T *e;
  int8_T fileid;
  int wherefrom;
  FILE * filestar;
  real_T position;
  long position_t;
  emxArray_uint8_T_Spike_T *A;
  size_t nBytes;
  int32_T numRequested;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T c_numRead;
  size_t numReadSizeT;
  int32_T buf_size_idx_0;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Spike_cfopen("aileron.txt", "rb");
  wherefrom = SEEK_END;
  filestar = Spike_fileManager((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  filestar = Spike_fileManager((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(filestar);
    position = (real_T)position_t;
  }

  position = rt_roundd_snf(position);
  if (position < 2.147483648E+9) {
    if (position >= -2.147483648E+9) {
      i = (int32_T)position;
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  filestar = Spike_fileManager((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  memset(&Spike_B.buffer[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Spike_emxInit_int32_T(&e, 2);
  Spike_emxInit_uint8_T(&A, 1);
  exitg1 = false;
  while ((!exitg1) && (remaining > 0)) {
    if (b_index > MAX_int32_T - remaining) {
      bytesOut = MAX_int32_T;
    } else {
      bytesOut = remaining + b_index;
    }

    if (bytesOut > 65536) {
      printf("Attempt to read file which is bigger than internal buffer.\n");
      fflush(stdout);
      printf("Current buffer size is %d bytes and file size is %d bytes.\n",
             65536, i);
      fflush(stdout);
      exitg1 = true;
    } else {
      nBytes = sizeof(char_T);
      filestar = Spike_fileManager((real_T)fileid);
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        filestar = NULL;
      }

      if (filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = (int16_T)remaining;
        }

        bytesOut = 0;
        numRead = 1;
        buf_size_idx_0 = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          numRequested = buf_size_idx_0;
          numRead = remaining - bytesOut;
          if (buf_size_idx_0 > numRead) {
            numRequested = numRead;
          }

          buf_size_idx_0 = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < numRequested) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, numRequested -
                                 numRead, filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (numRequested = 0; numRequested < numRead; numRequested++) {
            A->data[numRequested + bytesOut] = (uint8_T)buf_data[numRequested];
          }

          bytesOut += numRead;
        }

        numRequested = A->size[0];
        for (numRead = bytesOut; numRead < numRequested; numRead++) {
          A->data[numRead] = 0U;
        }

        if (bytesOut < remaining) {
          buf_size_idx_0 = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        }
      }

      position = (real_T)b_index + (real_T)bytesOut;
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          numRequested = (int32_T)position;
        } else {
          numRequested = MIN_int32_T;
        }
      } else {
        numRequested = MAX_int32_T;
      }

      if (b_index > numRequested - 1) {
        numRead = 1;
        numRequested = 1;
      } else {
        numRead = b_index;
      }

      buf_size_idx_0 = e->size[0] * e->size[1];
      e->size[0] = 1;
      numRequested -= numRead;
      e->size[1] = numRequested;
      Spike_emxEnsureCapacity_int32_T(e, buf_size_idx_0);
      for (buf_size_idx_0 = 0; buf_size_idx_0 < numRequested; buf_size_idx_0++)
      {
        e->data[buf_size_idx_0] = (numRead + buf_size_idx_0) - 1;
      }

      numRequested = e->size[0] * e->size[1];
      for (buf_size_idx_0 = 0; buf_size_idx_0 < numRequested; buf_size_idx_0++)
      {
        Spike_B.buffer[e->data[buf_size_idx_0]] = A->data[buf_size_idx_0];
      }

      if (bytesOut == 0) {
        exitg1 = true;
      } else if (bytesOut < 0) {
        printf("Could not read from file: %d.\n", bytesOut);
        fflush(stdout);
        exitg1 = true;
      } else {
        remaining -= bytesOut;
        if ((b_index < 0) && (bytesOut < MIN_int32_T - b_index)) {
          b_index = MIN_int32_T;
        } else if ((b_index > 0) && (bytesOut > MAX_int32_T - b_index)) {
          b_index = MAX_int32_T;
        } else {
          b_index += bytesOut;
        }
      }
    }
  }

  Spike_emxFree_uint8_T(&A);
  Spike_emxFree_int32_T(&e);
  Spike_fclose((real_T)fileid);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = (int8_T)Spike_B.buffer[i];
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
static void Spike_fclose_e(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles[j] = NULL;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
static int8_T Spike_filedata_e(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_l[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
static int8_T Spike_cfopen_m(const char * cfilename, const char * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_e();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_l[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
static FILE * Spike_fileManager_hw(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = (int8_T)rt_roundd_snf(varargin_1);
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_l[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else if (fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
static void Spike_fclose_m(real_T fileID)
{
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  fileid = (int8_T)rt_roundd_snf(fileID);
  if ((fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Spike_DW.eml_openfiles_l[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  if ((f != NULL) && (fileid >= 3)) {
    cst = fclose(f);
    if (cst == 0) {
      Spike_DW.eml_openfiles_l[fileid - 3] = NULL;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
static void Spike_readfile_f(emxArray_char_T_Spike_T *y)
{
  int32_T remaining;
  int32_T b_index;
  emxArray_int32_T_Spike_T *e;
  int8_T fileid;
  int wherefrom;
  FILE * filestar;
  real_T position;
  long position_t;
  emxArray_uint8_T_Spike_T *A;
  size_t nBytes;
  int32_T numRequested;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T c_numRead;
  size_t numReadSizeT;
  int32_T buf_size_idx_0;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Spike_cfopen_m("tailRight.txt", "rb");
  wherefrom = SEEK_END;
  filestar = Spike_fileManager_hw((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  filestar = Spike_fileManager_hw((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(filestar);
    position = (real_T)position_t;
  }

  position = rt_roundd_snf(position);
  if (position < 2.147483648E+9) {
    if (position >= -2.147483648E+9) {
      i = (int32_T)position;
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  filestar = Spike_fileManager_hw((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  memset(&Spike_B.buffer_c[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Spike_emxInit_int32_T(&e, 2);
  Spike_emxInit_uint8_T(&A, 1);
  exitg1 = false;
  while ((!exitg1) && (remaining > 0)) {
    if (b_index > MAX_int32_T - remaining) {
      bytesOut = MAX_int32_T;
    } else {
      bytesOut = remaining + b_index;
    }

    if (bytesOut > 65536) {
      printf("Attempt to read file which is bigger than internal buffer.\n");
      fflush(stdout);
      printf("Current buffer size is %d bytes and file size is %d bytes.\n",
             65536, i);
      fflush(stdout);
      exitg1 = true;
    } else {
      nBytes = sizeof(char_T);
      filestar = Spike_fileManager_hw((real_T)fileid);
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        filestar = NULL;
      }

      if (filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = (int16_T)remaining;
        }

        bytesOut = 0;
        numRead = 1;
        buf_size_idx_0 = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          numRequested = buf_size_idx_0;
          numRead = remaining - bytesOut;
          if (buf_size_idx_0 > numRead) {
            numRequested = numRead;
          }

          buf_size_idx_0 = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < numRequested) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, numRequested -
                                 numRead, filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (numRequested = 0; numRequested < numRead; numRequested++) {
            A->data[numRequested + bytesOut] = (uint8_T)buf_data[numRequested];
          }

          bytesOut += numRead;
        }

        numRequested = A->size[0];
        for (numRead = bytesOut; numRead < numRequested; numRead++) {
          A->data[numRead] = 0U;
        }

        if (bytesOut < remaining) {
          buf_size_idx_0 = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        }
      }

      position = (real_T)b_index + (real_T)bytesOut;
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          numRequested = (int32_T)position;
        } else {
          numRequested = MIN_int32_T;
        }
      } else {
        numRequested = MAX_int32_T;
      }

      if (b_index > numRequested - 1) {
        numRead = 1;
        numRequested = 1;
      } else {
        numRead = b_index;
      }

      buf_size_idx_0 = e->size[0] * e->size[1];
      e->size[0] = 1;
      numRequested -= numRead;
      e->size[1] = numRequested;
      Spike_emxEnsureCapacity_int32_T(e, buf_size_idx_0);
      for (buf_size_idx_0 = 0; buf_size_idx_0 < numRequested; buf_size_idx_0++)
      {
        e->data[buf_size_idx_0] = (numRead + buf_size_idx_0) - 1;
      }

      numRequested = e->size[0] * e->size[1];
      for (buf_size_idx_0 = 0; buf_size_idx_0 < numRequested; buf_size_idx_0++)
      {
        Spike_B.buffer_c[e->data[buf_size_idx_0]] = A->data[buf_size_idx_0];
      }

      if (bytesOut == 0) {
        exitg1 = true;
      } else if (bytesOut < 0) {
        printf("Could not read from file: %d.\n", bytesOut);
        fflush(stdout);
        exitg1 = true;
      } else {
        remaining -= bytesOut;
        if ((b_index < 0) && (bytesOut < MIN_int32_T - b_index)) {
          b_index = MIN_int32_T;
        } else if ((b_index > 0) && (bytesOut > MAX_int32_T - b_index)) {
          b_index = MAX_int32_T;
        } else {
          b_index += bytesOut;
        }
      }
    }
  }

  Spike_emxFree_uint8_T(&A);
  Spike_emxFree_int32_T(&e);
  Spike_fclose_m((real_T)fileid);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = (int8_T)Spike_B.buffer_c[i];
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
static void Spike_fclose_m2(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles_l[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles_l[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles_l[j] = NULL;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
static int8_T Spike_filedata_i(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_j[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
static int8_T Spike_cfopen_g(const char * cfilename, const char * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_i();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_j[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
static FILE * Spike_fileManager_h(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = (int8_T)rt_roundd_snf(varargin_1);
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else if (fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
static void Spike_fclose_d(real_T fileID)
{
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  fileid = (int8_T)rt_roundd_snf(fileID);
  if ((fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  if ((f != NULL) && (fileid >= 3)) {
    cst = fclose(f);
    if (cst == 0) {
      Spike_DW.eml_openfiles_j[fileid - 3] = NULL;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
static void Spike_readfile_m(emxArray_char_T_Spike_T *y)
{
  int32_T remaining;
  int32_T b_index;
  emxArray_int32_T_Spike_T *e;
  int8_T fileid;
  int wherefrom;
  FILE * filestar;
  real_T position;
  long position_t;
  emxArray_uint8_T_Spike_T *A;
  size_t nBytes;
  int32_T numRequested;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T c_numRead;
  size_t numReadSizeT;
  int32_T buf_size_idx_0;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Spike_cfopen_g("tailLeft.txt", "rb");
  wherefrom = SEEK_END;
  filestar = Spike_fileManager_h((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  filestar = Spike_fileManager_h((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(filestar);
    position = (real_T)position_t;
  }

  position = rt_roundd_snf(position);
  if (position < 2.147483648E+9) {
    if (position >= -2.147483648E+9) {
      i = (int32_T)position;
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  filestar = Spike_fileManager_h((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  memset(&Spike_B.buffer_m[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Spike_emxInit_int32_T(&e, 2);
  Spike_emxInit_uint8_T(&A, 1);
  exitg1 = false;
  while ((!exitg1) && (remaining > 0)) {
    if (b_index > MAX_int32_T - remaining) {
      bytesOut = MAX_int32_T;
    } else {
      bytesOut = remaining + b_index;
    }

    if (bytesOut > 65536) {
      printf("Attempt to read file which is bigger than internal buffer.\n");
      fflush(stdout);
      printf("Current buffer size is %d bytes and file size is %d bytes.\n",
             65536, i);
      fflush(stdout);
      exitg1 = true;
    } else {
      nBytes = sizeof(char_T);
      filestar = Spike_fileManager_h((real_T)fileid);
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        filestar = NULL;
      }

      if (filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = (int16_T)remaining;
        }

        bytesOut = 0;
        numRead = 1;
        buf_size_idx_0 = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          numRequested = buf_size_idx_0;
          numRead = remaining - bytesOut;
          if (buf_size_idx_0 > numRead) {
            numRequested = numRead;
          }

          buf_size_idx_0 = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < numRequested) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, numRequested -
                                 numRead, filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (numRequested = 0; numRequested < numRead; numRequested++) {
            A->data[numRequested + bytesOut] = (uint8_T)buf_data[numRequested];
          }

          bytesOut += numRead;
        }

        numRequested = A->size[0];
        for (numRead = bytesOut; numRead < numRequested; numRead++) {
          A->data[numRead] = 0U;
        }

        if (bytesOut < remaining) {
          buf_size_idx_0 = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        }
      }

      position = (real_T)b_index + (real_T)bytesOut;
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          numRequested = (int32_T)position;
        } else {
          numRequested = MIN_int32_T;
        }
      } else {
        numRequested = MAX_int32_T;
      }

      if (b_index > numRequested - 1) {
        numRead = 1;
        numRequested = 1;
      } else {
        numRead = b_index;
      }

      buf_size_idx_0 = e->size[0] * e->size[1];
      e->size[0] = 1;
      numRequested -= numRead;
      e->size[1] = numRequested;
      Spike_emxEnsureCapacity_int32_T(e, buf_size_idx_0);
      for (buf_size_idx_0 = 0; buf_size_idx_0 < numRequested; buf_size_idx_0++)
      {
        e->data[buf_size_idx_0] = (numRead + buf_size_idx_0) - 1;
      }

      numRequested = e->size[0] * e->size[1];
      for (buf_size_idx_0 = 0; buf_size_idx_0 < numRequested; buf_size_idx_0++)
      {
        Spike_B.buffer_m[e->data[buf_size_idx_0]] = A->data[buf_size_idx_0];
      }

      if (bytesOut == 0) {
        exitg1 = true;
      } else if (bytesOut < 0) {
        printf("Could not read from file: %d.\n", bytesOut);
        fflush(stdout);
        exitg1 = true;
      } else {
        remaining -= bytesOut;
        if ((b_index < 0) && (bytesOut < MIN_int32_T - b_index)) {
          b_index = MIN_int32_T;
        } else if ((b_index > 0) && (bytesOut > MAX_int32_T - b_index)) {
          b_index = MAX_int32_T;
        } else {
          b_index += bytesOut;
        }
      }
    }
  }

  Spike_emxFree_uint8_T(&A);
  Spike_emxFree_int32_T(&e);
  Spike_fclose_d((real_T)fileid);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = (int8_T)Spike_B.buffer_m[i];
  }
}

static void Spike_emxFree_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T_Spike_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T_Spike_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
static void Spike_fclose_dh(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles_j[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles_j[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles_j[j] = NULL;
      }
    }
  }
}

void rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(const real_T u0[3], const real_T u1[9],
  real_T y[3])
{
  real_T A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  memcpy(&A[0], &u1[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(u1[0]);
  a21 = fabs(u1[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(u1[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] = u1[r2] / u1[r1];
  A[r3] /= A[r1];
  A[3 + r2] -= A[3 + r1] * A[r2];
  A[3 + r3] -= A[3 + r1] * A[r3];
  A[6 + r2] -= A[6 + r1] * A[r2];
  A[6 + r3] -= A[6 + r1] * A[r3];
  if (fabs(A[3 + r3]) > fabs(A[3 + r2])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  A[3 + r3] /= A[3 + r2];
  A[6 + r3] -= A[3 + r3] * A[6 + r2];
  y[r1] = u0[0] / A[r1];
  y[r2] = u0[1] - A[3 + r1] * y[r1];
  y[r3] = u0[2] - A[6 + r1] * y[r1];
  y[r2] /= A[3 + r2];
  y[r3] -= A[6 + r2] * y[r2];
  y[r3] /= A[6 + r3];
  y[r2] -= A[3 + r3] * y[r3];
  y[r1] -= y[r3] * A[r3];
  y[r1] -= y[r2] * A[r2];
}

/* Model step function */
void Spike_step(void)
{
  real_T gravityBody[3];
  int8_T fileid;
  int8_T b_fileid;
  int8_T c_fileid;
  int8_T d_fileid;
  int8_T e_fileid;
  int8_T f_fileid;
  int8_T g_fileid;
  int8_T h_fileid;
  int8_T i_fileid;
  int8_T j_fileid;
  FILE * b_NULL;
  FILE * f;
  boolean_T a;
  emxArray_char_T_Spike_T *A;
  emxArray_boolean_T_Spike_T *TF;
  emxArray_int32_T_Spike_T *ii;
  int32_T nx;
  int32_T idx;
  int32_T b_ii;
  real_T rtb_Sum_f[3];
  real_T rtb_torques[3];
  real_T rtb_VectorConcatenate[18];
  real_T VectorConcatenate[9];
  real_T gravityBody_tmp[9];
  emxArray_char_T_Spike_T *A_0;
  emxArray_char_T_Spike_T *A_1;
  emxArray_char_T_Spike_T *A_2;
  emxArray_char_T_Spike_T *A_3;
  boolean_T ii_0[2];
  real_T tmp[3];
  real_T tmp_0[3];
  real_T rtb_Sum2_idx_0;
  creal_T tmp_1;
  creal_T tmp_2;
  real_T VectorConcatenate_tmp;
  real_T VectorConcatenate_tmp_0;
  real_T rtb_Sum2_tmp;
  real_T rtb_Sum_o_tmp;
  real_T rtb_Sum2_idx_1_tmp;
  real_T rtb_Sum_o_tmp_0;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(Spike_M)) {
    /* set solver stop time */
    if (!(Spike_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Spike_M->solverInfo, ((Spike_M->Timing.clockTickH0
        + 1) * Spike_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Spike_M->solverInfo, ((Spike_M->Timing.clockTick0 +
        1) * Spike_M->Timing.stepSize0 + Spike_M->Timing.clockTickH0 *
        Spike_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Spike_M)) {
    Spike_M->Timing.t[0] = rtsiGetT(&Spike_M->solverInfo);
  }

  /* Trigonometry: '<S18>/sincos' incorporates:
   *  Integrator: '<S10>/phi theta psi'
   *  SignalConversion: '<S18>/TmpSignal ConversionAtsincosInport1'
   *  Trigonometry: '<S19>/sincos'
   */
  rtb_Sum_f[0] = cos(Spike_X.phithetapsi_CSTATE[2]);
  rtb_Sum2_idx_0 = sin(Spike_X.phithetapsi_CSTATE[2]);
  rtb_Sum_o_tmp_0 = cos(Spike_X.phithetapsi_CSTATE[1]);
  rtb_Sum2_idx_1_tmp = sin(Spike_X.phithetapsi_CSTATE[1]);
  rtb_Sum_o_tmp = cos(Spike_X.phithetapsi_CSTATE[0]);
  rtb_Sum2_tmp = sin(Spike_X.phithetapsi_CSTATE[0]);

  /* Fcn: '<S18>/Fcn11' incorporates:
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate[0] = rtb_Sum_o_tmp_0 * rtb_Sum_f[0];

  /* Fcn: '<S18>/Fcn21' incorporates:
   *  Fcn: '<S18>/Fcn22'
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate_tmp = rtb_Sum2_tmp * rtb_Sum2_idx_1_tmp;
  VectorConcatenate[1] = VectorConcatenate_tmp * rtb_Sum_f[0] - rtb_Sum_o_tmp *
    rtb_Sum2_idx_0;

  /* Fcn: '<S18>/Fcn31' incorporates:
   *  Fcn: '<S18>/Fcn32'
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate_tmp_0 = rtb_Sum_o_tmp * rtb_Sum2_idx_1_tmp;
  VectorConcatenate[2] = VectorConcatenate_tmp_0 * rtb_Sum_f[0] + rtb_Sum2_tmp *
    rtb_Sum2_idx_0;

  /* Fcn: '<S18>/Fcn12' incorporates:
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate[3] = rtb_Sum_o_tmp_0 * rtb_Sum2_idx_0;

  /* Fcn: '<S18>/Fcn22' incorporates:
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate[4] = VectorConcatenate_tmp * rtb_Sum2_idx_0 + rtb_Sum_o_tmp *
    rtb_Sum_f[0];

  /* Fcn: '<S18>/Fcn32' incorporates:
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate[5] = VectorConcatenate_tmp_0 * rtb_Sum2_idx_0 - rtb_Sum2_tmp
    * rtb_Sum_f[0];

  /* Fcn: '<S18>/Fcn13' incorporates:
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate[6] = -rtb_Sum2_idx_1_tmp;

  /* Fcn: '<S18>/Fcn23' incorporates:
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate[7] = rtb_Sum2_tmp * rtb_Sum_o_tmp_0;

  /* Fcn: '<S18>/Fcn33' incorporates:
   *  Trigonometry: '<S18>/sincos'
   */
  VectorConcatenate[8] = rtb_Sum_o_tmp * rtb_Sum_o_tmp_0;
  for (b_ii = 0; b_ii < 3; b_ii++) {
    /* MATLAB Function: '<Root>/WriteToFile' incorporates:
     *  MATLAB Function: '<Root>/External Forces and torques '
     *  Math: '<S1>/Transpose'
     */
    gravityBody_tmp[3 * b_ii] = VectorConcatenate[b_ii];
    gravityBody_tmp[1 + 3 * b_ii] = VectorConcatenate[b_ii + 3];
    gravityBody_tmp[2 + 3 * b_ii] = VectorConcatenate[b_ii + 6];
  }

  /* MATLAB Function: '<Root>/WriteToFile' incorporates:
   *  Integrator: '<S10>/phi theta psi'
   *  Integrator: '<S1>/p,q,r '
   *  Integrator: '<S1>/ub,vb,wb'
   */
  for (b_ii = 0; b_ii < 3; b_ii++) {
    gravityBody[b_ii] = gravityBody_tmp[b_ii + 6] * -9.8 + (gravityBody_tmp[b_ii
      + 3] * 0.0 + gravityBody_tmp[b_ii] * 0.0);
  }

  fileid = Spike_cfopen_p("airspeed.txt", "ab");
  b_fileid = Spike_cfopen_p("roll.txt", "ab");
  c_fileid = Spike_cfopen_p("pitch.txt", "ab");
  d_fileid = Spike_cfopen_p("yaw.txt", "ab");
  e_fileid = Spike_cfopen_p("accX.txt", "ab");
  f_fileid = Spike_cfopen_p("accY.txt", "ab");
  g_fileid = Spike_cfopen_p("accZ.txt", "ab");
  h_fileid = Spike_cfopen_p("gyrX.txt", "ab");
  i_fileid = Spike_cfopen_p("gyrY.txt", "ab");
  j_fileid = Spike_cfopen_p("gyrZ.txt", "ab");
  b_NULL = NULL;
  if ((fileid > 22) || (fileid < 0)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[fileid - 3];
    a = Spike_DW.eml_autoflush[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
    a = true;
  } else if (fileid == 1) {
    f = stdout;
    a = true;
  } else if (fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Spike_X.ubvbwb_CSTATE[0]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((b_fileid > 22) || (b_fileid < 0)) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[b_fileid - 3];
    a = Spike_DW.eml_autoflush[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
    a = true;
  } else if (b_fileid == 1) {
    f = stdout;
    a = true;
  } else if (b_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Spike_X.phithetapsi_CSTATE[0]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((c_fileid > 22) || (c_fileid < 0)) {
    c_fileid = -1;
  }

  if (c_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[c_fileid - 3];
    a = Spike_DW.eml_autoflush[c_fileid - 3];
  } else if (c_fileid == 0) {
    f = stdin;
    a = true;
  } else if (c_fileid == 1) {
    f = stdout;
    a = true;
  } else if (c_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Spike_X.phithetapsi_CSTATE[1]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((d_fileid > 22) || (d_fileid < 0)) {
    d_fileid = -1;
  }

  if (d_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[d_fileid - 3];
    a = Spike_DW.eml_autoflush[d_fileid - 3];
  } else if (d_fileid == 0) {
    f = stdin;
    a = true;
  } else if (d_fileid == 1) {
    f = stdout;
    a = true;
  } else if (d_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Spike_X.phithetapsi_CSTATE[2]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((e_fileid > 22) || (e_fileid < 0)) {
    e_fileid = -1;
  }

  if (e_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[e_fileid - 3];
    a = Spike_DW.eml_autoflush[e_fileid - 3];
  } else if (e_fileid == 0) {
    f = stdin;
    a = true;
  } else if (e_fileid == 1) {
    f = stdout;
    a = true;
  } else if (e_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", gravityBody[0]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((f_fileid > 22) || (f_fileid < 0)) {
    f_fileid = -1;
  }

  if (f_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[f_fileid - 3];
    a = Spike_DW.eml_autoflush[f_fileid - 3];
  } else if (f_fileid == 0) {
    f = stdin;
    a = true;
  } else if (f_fileid == 1) {
    f = stdout;
    a = true;
  } else if (f_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", gravityBody[1]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((g_fileid > 22) || (g_fileid < 0)) {
    g_fileid = -1;
  }

  if (g_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[g_fileid - 3];
    a = Spike_DW.eml_autoflush[g_fileid - 3];
  } else if (g_fileid == 0) {
    f = stdin;
    a = true;
  } else if (g_fileid == 1) {
    f = stdout;
    a = true;
  } else if (g_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", gravityBody[2]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((h_fileid > 22) || (h_fileid < 0)) {
    h_fileid = -1;
  }

  if (h_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[h_fileid - 3];
    a = Spike_DW.eml_autoflush[h_fileid - 3];
  } else if (h_fileid == 0) {
    f = stdin;
    a = true;
  } else if (h_fileid == 1) {
    f = stdout;
    a = true;
  } else if (h_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Spike_X.pqr_CSTATE[0]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((i_fileid > 22) || (i_fileid < 0)) {
    i_fileid = -1;
  }

  if (i_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[i_fileid - 3];
    a = Spike_DW.eml_autoflush[i_fileid - 3];
  } else if (i_fileid == 0) {
    f = stdin;
    a = true;
  } else if (i_fileid == 1) {
    f = stdout;
    a = true;
  } else if (i_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Spike_X.pqr_CSTATE[1]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((j_fileid > 22) || (j_fileid < 0)) {
    j_fileid = -1;
  }

  if (j_fileid >= 3) {
    f = Spike_DW.eml_openfiles_c[j_fileid - 3];
    a = Spike_DW.eml_autoflush[j_fileid - 3];
  } else if (j_fileid == 0) {
    f = stdin;
    a = true;
  } else if (j_fileid == 1) {
    f = stdout;
    a = true;
  } else if (j_fileid == 2) {
    f = stderr;
    a = true;
  } else {
    f = NULL;
    a = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Spike_X.pqr_CSTATE[2]);
    if (a) {
      fflush(f);
    }
  }

  Spike_fclose_er();

  /* SignalConversion: '<S10>/TmpSignal ConversionAtphi theta psiInport1' incorporates:
   *  Fcn: '<S19>/phidot'
   *  Fcn: '<S19>/psidot'
   *  Fcn: '<S19>/thetadot'
   *  Integrator: '<S1>/p,q,r '
   */
  Spike_B.TmpSignalConversionAtphithetaps[0] = (Spike_X.pqr_CSTATE[1] *
    rtb_Sum2_tmp + Spike_X.pqr_CSTATE[2] * rtb_Sum_o_tmp) * (rtb_Sum2_idx_1_tmp /
    rtb_Sum_o_tmp_0) + Spike_X.pqr_CSTATE[0];
  Spike_B.TmpSignalConversionAtphithetaps[1] = Spike_X.pqr_CSTATE[1] *
    rtb_Sum_o_tmp - Spike_X.pqr_CSTATE[2] * rtb_Sum2_tmp;
  Spike_B.TmpSignalConversionAtphithetaps[2] = (Spike_X.pqr_CSTATE[1] *
    rtb_Sum2_tmp + Spike_X.pqr_CSTATE[2] * rtb_Sum_o_tmp) / rtb_Sum_o_tmp_0;
  if (rtmIsMajorTimeStep(Spike_M)) {
    for (b_ii = 0; b_ii < 3; b_ii++) {
      /* Concatenate: '<S12>/Vector Concatenate' incorporates:
       *  Constant: '<S12>/Constant1'
       *  Constant: '<S12>/Constant2'
       */
      rtb_VectorConcatenate[6 * b_ii] = Spike_P.uDOFEulerAngles_inertia[3 * b_ii];
      rtb_VectorConcatenate[3 + 6 * b_ii] = Spike_P.Constant2_Value[3 * b_ii];

      /* Selector: '<S11>/Selector' */
      Spike_B.Selector[3 * b_ii] = rtb_VectorConcatenate[6 * b_ii];

      /* Concatenate: '<S12>/Vector Concatenate' incorporates:
       *  Constant: '<S12>/Constant1'
       *  Constant: '<S12>/Constant2'
       */
      nx = 3 * b_ii + 1;
      rtb_VectorConcatenate[1 + 6 * b_ii] = Spike_P.uDOFEulerAngles_inertia[nx];
      rtb_VectorConcatenate[4 + 6 * b_ii] = Spike_P.Constant2_Value[nx];

      /* Selector: '<S11>/Selector' */
      Spike_B.Selector[1 + 3 * b_ii] = rtb_VectorConcatenate[6 * b_ii + 1];

      /* Concatenate: '<S12>/Vector Concatenate' incorporates:
       *  Constant: '<S12>/Constant1'
       *  Constant: '<S12>/Constant2'
       */
      nx = 3 * b_ii + 2;
      rtb_VectorConcatenate[2 + 6 * b_ii] = Spike_P.uDOFEulerAngles_inertia[nx];
      rtb_VectorConcatenate[5 + 6 * b_ii] = Spike_P.Constant2_Value[nx];

      /* Selector: '<S11>/Selector' */
      Spike_B.Selector[2 + 3 * b_ii] = rtb_VectorConcatenate[6 * b_ii + 2];
    }
  }

  /* Product: '<S22>/Product' incorporates:
   *  Integrator: '<S1>/p,q,r '
   */
  for (b_ii = 0; b_ii < 3; b_ii++) {
    rtb_Sum_f[b_ii] = Spike_B.Selector[b_ii + 6] * Spike_X.pqr_CSTATE[2] +
      (Spike_B.Selector[b_ii + 3] * Spike_X.pqr_CSTATE[1] +
       Spike_B.Selector[b_ii] * Spike_X.pqr_CSTATE[0]);
  }

  /* End of Product: '<S22>/Product' */
  if (rtmIsMajorTimeStep(Spike_M)) {
    /* Selector: '<S11>/Selector1' */
    for (b_ii = 0; b_ii < 3; b_ii++) {
      Spike_B.Selector1[3 * b_ii] = rtb_VectorConcatenate[6 * b_ii + 3];
      Spike_B.Selector1[1 + 3 * b_ii] = rtb_VectorConcatenate[6 * b_ii + 4];
      Spike_B.Selector1[2 + 3 * b_ii] = rtb_VectorConcatenate[6 * b_ii + 5];
    }

    /* End of Selector: '<S11>/Selector1' */
    Spike_emxInit_char_T(&A, 2);
    Spike_emxInit_boolean_T(&TF, 2);
    Spike_emxInit_int32_T(&ii, 2);

    /* MATLAB Function: '<Root>/Read Throttle' */
    Spike_readfile_e(A);
    Spike_isstrprop(A, TF);
    nx = TF->size[1];
    idx = 0;
    b_ii = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = TF->size[1];
    Spike_emxEnsureCapacity_int32_T(ii, b_ii);
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx - 1)) {
      if (TF->data[b_ii]) {
        idx++;
        ii->data[idx - 1] = b_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }

    if (TF->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      b_ii = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      Spike_emxEnsureCapacity_int32_T(ii, b_ii);
    }

    nx = 0;
    ii_0[0] = (ii->size[0] != 0);
    ii_0[1] = (ii->size[1] != 0);
    if (Spike_ifWhileCond(ii_0)) {
      nx = ii->data[ii->size[1] - 3];
    }

    if (nx > A->size[1]) {
      nx = 1;
      idx = 0;
    } else {
      idx = A->size[1];
    }

    Spike_emxInit_char_T(&A_3, 2);

    /* MATLAB Function: '<Root>/Read Throttle' */
    b_ii = A_3->size[0] * A_3->size[1];
    A_3->size[0] = 1;
    idx -= nx;
    A_3->size[1] = idx + 1;
    Spike_emxEnsureCapacity_char_T(A_3, b_ii);
    for (b_ii = 0; b_ii <= idx; b_ii++) {
      A_3->data[b_ii] = A->data[(nx + b_ii) - 1];
    }

    tmp_1 = Spike_str2double(A_3);
    Spike_B.throttle = tmp_1.re;
    Spike_fclose_gy();

    /* MATLAB Function: '<Root>/Read Aileron' */
    Spike_readfile(A);
    Spike_isstrprop(A, TF);
    nx = TF->size[1];
    idx = 0;
    b_ii = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = TF->size[1];
    Spike_emxEnsureCapacity_int32_T(ii, b_ii);
    b_ii = 0;
    Spike_emxFree_char_T(&A_3);
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx - 1)) {
      if (TF->data[b_ii]) {
        idx++;
        ii->data[idx - 1] = b_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }

    /* MATLAB Function: '<Root>/Read Aileron' */
    if (TF->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      b_ii = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      Spike_emxEnsureCapacity_int32_T(ii, b_ii);
    }

    nx = 0;
    ii_0[0] = (ii->size[0] != 0);
    ii_0[1] = (ii->size[1] != 0);
    if (Spike_ifWhileCond(ii_0)) {
      nx = ii->data[ii->size[1] - 3];
    }

    if (nx > A->size[1]) {
      nx = 1;
      idx = 0;
    } else {
      idx = A->size[1];
    }

    Spike_emxInit_char_T(&A_2, 2);

    /* MATLAB Function: '<Root>/Read Aileron' */
    b_ii = A_2->size[0] * A_2->size[1];
    A_2->size[0] = 1;
    idx -= nx;
    A_2->size[1] = idx + 1;
    Spike_emxEnsureCapacity_char_T(A_2, b_ii);
    for (b_ii = 0; b_ii <= idx; b_ii++) {
      A_2->data[b_ii] = A->data[(nx + b_ii) - 1];
    }

    tmp_1 = Spike_str2double(A_2);
    Spike_B.aileron = tmp_1.re;
    Spike_fclose_e();

    /* MATLAB Function: '<Root>/Read Tail right' */
    Spike_readfile_f(A);
    Spike_isstrprop(A, TF);
    nx = TF->size[1];
    idx = 0;
    b_ii = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = TF->size[1];
    Spike_emxEnsureCapacity_int32_T(ii, b_ii);
    b_ii = 0;
    Spike_emxFree_char_T(&A_2);
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx - 1)) {
      if (TF->data[b_ii]) {
        idx++;
        ii->data[idx - 1] = b_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }

    /* MATLAB Function: '<Root>/Read Tail right' */
    if (TF->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      b_ii = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      Spike_emxEnsureCapacity_int32_T(ii, b_ii);
    }

    nx = 0;
    ii_0[0] = (ii->size[0] != 0);
    ii_0[1] = (ii->size[1] != 0);
    if (Spike_ifWhileCond(ii_0)) {
      nx = ii->data[ii->size[1] - 3];
    }

    if (nx > A->size[1]) {
      nx = 1;
      idx = 0;
    } else {
      idx = A->size[1];
    }

    Spike_emxInit_char_T(&A_1, 2);

    /* MATLAB Function: '<Root>/Read Tail right' */
    b_ii = A_1->size[0] * A_1->size[1];
    A_1->size[0] = 1;
    idx -= nx;
    A_1->size[1] = idx + 1;
    Spike_emxEnsureCapacity_char_T(A_1, b_ii);
    for (b_ii = 0; b_ii <= idx; b_ii++) {
      A_1->data[b_ii] = A->data[(nx + b_ii) - 1];
    }

    tmp_1 = Spike_str2double(A_1);
    Spike_fclose_m2();

    /* MATLAB Function: '<Root>/Read Tail left' */
    Spike_readfile_m(A);
    Spike_isstrprop(A, TF);
    nx = TF->size[1];
    idx = 0;
    b_ii = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = TF->size[1];
    Spike_emxEnsureCapacity_int32_T(ii, b_ii);
    b_ii = 0;
    Spike_emxFree_char_T(&A_1);
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx - 1)) {
      if (TF->data[b_ii]) {
        idx++;
        ii->data[idx - 1] = b_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }

    /* MATLAB Function: '<Root>/Read Tail left' */
    if (TF->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      b_ii = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      Spike_emxEnsureCapacity_int32_T(ii, b_ii);
    }

    Spike_emxFree_boolean_T(&TF);

    /* MATLAB Function: '<Root>/Read Tail left' */
    nx = 0;
    ii_0[0] = (ii->size[0] != 0);
    ii_0[1] = (ii->size[1] != 0);
    if (Spike_ifWhileCond(ii_0)) {
      nx = ii->data[ii->size[1] - 3];
    }

    Spike_emxFree_int32_T(&ii);

    /* MATLAB Function: '<Root>/Read Tail left' */
    if (nx > A->size[1]) {
      nx = 1;
      idx = 0;
    } else {
      idx = A->size[1];
    }

    Spike_emxInit_char_T(&A_0, 2);

    /* MATLAB Function: '<Root>/Read Tail left' */
    b_ii = A_0->size[0] * A_0->size[1];
    A_0->size[0] = 1;
    idx -= nx;
    A_0->size[1] = idx + 1;
    Spike_emxEnsureCapacity_char_T(A_0, b_ii);
    for (b_ii = 0; b_ii <= idx; b_ii++) {
      A_0->data[b_ii] = A->data[(nx + b_ii) - 1];
    }

    Spike_emxFree_char_T(&A);

    /* MATLAB Function: '<Root>/Read Tail left' */
    tmp_2 = Spike_str2double(A_0);
    Spike_fclose_dh();

    /* MATLAB Function: '<Root>/SeperateYawAndPitch' incorporates:
     *  MATLAB Function: '<Root>/Read Tail left'
     *  MATLAB Function: '<Root>/Read Tail right'
     */
    Spike_B.elevator = (tmp_1.re - tmp_2.re) / 1.4142135623730951;
    Spike_B.rudder = (tmp_1.re + tmp_2.re) / 1.4142135623730949;
    Spike_emxFree_char_T(&A_0);
  }

  /* MATLAB Function: '<Root>/External Forces and torques ' */
  gravityBody[1] = 0.0;
  gravityBody[2] = 0.0;

  /* MATLAB Function: '<Root>/Forces and torques due to commands' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   */
  rtb_torques[0] = Spike_B.aileron / 100.0 * (Spike_X.ubvbwb_CSTATE[0] * 0.2);
  rtb_torques[1] = Spike_B.elevator / 100.0 * (Spike_X.ubvbwb_CSTATE[0] * 0.2);
  rtb_torques[2] = Spike_B.rudder / 100.0 * (Spike_X.ubvbwb_CSTATE[0] * 0.2);

  /* MATLAB Function: '<Root>/External Forces and torques ' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   */
  gravityBody[0] = 0.0 - 0.2 * Spike_X.ubvbwb_CSTATE[0];
  for (b_ii = 0; b_ii < 3; b_ii++) {
    gravityBody[b_ii] += (gravityBody_tmp[b_ii + 3] * 0.0 + gravityBody_tmp[b_ii]
                          * 0.0) + gravityBody_tmp[b_ii + 6] *
      -29.400000000000002;
  }

  if (rtmIsMajorTimeStep(Spike_M)) {
    /* Selector: '<S11>/Selector2' */
    for (b_ii = 0; b_ii < 3; b_ii++) {
      Spike_B.Selector2[3 * b_ii] = rtb_VectorConcatenate[6 * b_ii];
      Spike_B.Selector2[1 + 3 * b_ii] = rtb_VectorConcatenate[6 * b_ii + 1];
      Spike_B.Selector2[2 + 3 * b_ii] = rtb_VectorConcatenate[6 * b_ii + 2];
    }

    /* End of Selector: '<S11>/Selector2' */
  }

  /* Sum: '<S21>/Sum' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  Product: '<S24>/i x j'
   *  Product: '<S24>/j x k'
   *  Product: '<S24>/k x i'
   *  Product: '<S25>/i x k'
   *  Product: '<S25>/j x i'
   *  Product: '<S25>/k x j'
   */
  tmp[0] = Spike_X.pqr_CSTATE[1] * rtb_Sum_f[2];
  tmp[1] = Spike_X.pqr_CSTATE[2] * rtb_Sum_f[0];
  tmp[2] = Spike_X.pqr_CSTATE[0] * rtb_Sum_f[1];
  tmp_0[0] = Spike_X.pqr_CSTATE[2] * rtb_Sum_f[1];
  tmp_0[1] = Spike_X.pqr_CSTATE[0] * rtb_Sum_f[2];
  tmp_0[2] = Spike_X.pqr_CSTATE[1] * rtb_Sum_f[0];
  for (b_ii = 0; b_ii < 3; b_ii++) {
    /* Sum: '<S11>/Sum2' incorporates:
     *  Integrator: '<S1>/p,q,r '
     *  Product: '<S23>/Product'
     *  Sum: '<Root>/Sum1'
     *  Sum: '<S21>/Sum'
     */
    rtb_Sum_f[b_ii] = (rtb_torques[b_ii] - (Spike_B.Selector1[b_ii + 6] *
      Spike_X.pqr_CSTATE[2] + (Spike_B.Selector1[b_ii + 3] * Spike_X.pqr_CSTATE
      [1] + Spike_B.Selector1[b_ii] * Spike_X.pqr_CSTATE[0]))) - (tmp[b_ii] -
      tmp_0[b_ii]);

    /* Product: '<S17>/Product' incorporates:
     *  Integrator: '<S1>/ub,vb,wb'
     *  Math: '<S1>/Transpose'
     */
    Spike_B.Product[b_ii] = 0.0;
    Spike_B.Product[b_ii] += gravityBody_tmp[b_ii] * Spike_X.ubvbwb_CSTATE[0];
    Spike_B.Product[b_ii] += gravityBody_tmp[b_ii + 3] * Spike_X.ubvbwb_CSTATE[1];
    Spike_B.Product[b_ii] += gravityBody_tmp[b_ii + 6] * Spike_X.ubvbwb_CSTATE[2];
  }

  /* Product: '<S11>/Product2' */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(rtb_Sum_f, Spike_B.Selector2, Spike_B.Product2);

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S12>/Constant'
   *  Integrator: '<S1>/p,q,r '
   *  Integrator: '<S1>/ub,vb,wb'
   *  MATLAB Function: '<Root>/Forces and torques due to commands'
   *  Product: '<S1>/Product'
   *  Product: '<S26>/i x j'
   *  Product: '<S26>/j x k'
   *  Product: '<S26>/k x i'
   *  Product: '<S27>/i x k'
   *  Product: '<S27>/j x i'
   *  Product: '<S27>/k x j'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S13>/Sum'
   */
  Spike_B.Sum[0] = ((Spike_B.throttle / 100.0 * 30.0 - ((Spike_B.aileron / 100.0
    * (Spike_X.ubvbwb_CSTATE[0] * 0.01) + Spike_B.elevator / 100.0 *
    (Spike_X.ubvbwb_CSTATE[0] * 0.01)) + Spike_B.rudder / 100.0 *
    (Spike_X.ubvbwb_CSTATE[0] * 0.01))) + gravityBody[0]) /
    Spike_P.uDOFEulerAngles_mass_0 + (Spike_X.ubvbwb_CSTATE[1] *
    Spike_X.pqr_CSTATE[2] - Spike_X.ubvbwb_CSTATE[2] * Spike_X.pqr_CSTATE[1]);
  Spike_B.Sum[1] = (Spike_X.ubvbwb_CSTATE[2] * Spike_X.pqr_CSTATE[0] -
                    Spike_X.ubvbwb_CSTATE[0] * Spike_X.pqr_CSTATE[2]) +
    gravityBody[1] / Spike_P.uDOFEulerAngles_mass_0;
  Spike_B.Sum[2] = (Spike_X.ubvbwb_CSTATE[0] * Spike_X.pqr_CSTATE[1] -
                    Spike_X.ubvbwb_CSTATE[1] * Spike_X.pqr_CSTATE[0]) +
    gravityBody[2] / Spike_P.uDOFEulerAngles_mass_0;
  if (rtmIsMajorTimeStep(Spike_M)) {
    rt_ertODEUpdateContinuousStates(&Spike_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Spike_M->Timing.clockTick0)) {
      ++Spike_M->Timing.clockTickH0;
    }

    Spike_M->Timing.t[0] = rtsiGetSolverStopTime(&Spike_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Spike_M->Timing.clockTick1++;
      if (!Spike_M->Timing.clockTick1) {
        Spike_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Spike_derivatives(void)
{
  XDot_Spike_T *_rtXdot;
  _rtXdot = ((XDot_Spike_T *) Spike_M->derivs);

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[0] = Spike_B.Sum[0];

  /* Derivatives for Integrator: '<S10>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[0] = Spike_B.TmpSignalConversionAtphithetaps[0];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[0] = Spike_B.Product2[0];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[0] = Spike_B.Product[0];

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[1] = Spike_B.Sum[1];

  /* Derivatives for Integrator: '<S10>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[1] = Spike_B.TmpSignalConversionAtphithetaps[1];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[1] = Spike_B.Product2[1];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[1] = Spike_B.Product[1];

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[2] = Spike_B.Sum[2];

  /* Derivatives for Integrator: '<S10>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[2] = Spike_B.TmpSignalConversionAtphithetaps[2];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[2] = Spike_B.Product2[2];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[2] = Spike_B.Product[2];
}

/* Model initialize function */
void Spike_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Spike_M, 0,
                sizeof(RT_MODEL_Spike_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Spike_M->solverInfo, &Spike_M->Timing.simTimeStep);
    rtsiSetTPtr(&Spike_M->solverInfo, &rtmGetTPtr(Spike_M));
    rtsiSetStepSizePtr(&Spike_M->solverInfo, &Spike_M->Timing.stepSize0);
    rtsiSetdXPtr(&Spike_M->solverInfo, &Spike_M->derivs);
    rtsiSetContStatesPtr(&Spike_M->solverInfo, (real_T **) &Spike_M->contStates);
    rtsiSetNumContStatesPtr(&Spike_M->solverInfo, &Spike_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Spike_M->solverInfo,
      &Spike_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Spike_M->solverInfo,
      &Spike_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Spike_M->solverInfo,
      &Spike_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Spike_M->solverInfo, (&rtmGetErrorStatus(Spike_M)));
    rtsiSetRTModelPtr(&Spike_M->solverInfo, Spike_M);
  }

  rtsiSetSimTimeStep(&Spike_M->solverInfo, MAJOR_TIME_STEP);
  Spike_M->intgData.y = Spike_M->odeY;
  Spike_M->intgData.f[0] = Spike_M->odeF[0];
  Spike_M->intgData.f[1] = Spike_M->odeF[1];
  Spike_M->intgData.f[2] = Spike_M->odeF[2];
  Spike_M->contStates = ((X_Spike_T *) &Spike_X);
  Spike_M->periodicContStateIndices = ((int_T*) Spike_PeriodicIndX);
  Spike_M->periodicContStateRanges = ((real_T*) Spike_PeriodicRngX);
  rtsiSetSolverData(&Spike_M->solverInfo, (void *)&Spike_M->intgData);
  rtsiSetSolverName(&Spike_M->solverInfo,"ode3");
  rtmSetTPtr(Spike_M, &Spike_M->Timing.tArray[0]);
  Spike_M->Timing.stepSize0 = 0.2;

  /* block I/O */
  (void) memset(((void *) &Spike_B), 0,
                sizeof(B_Spike_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Spike_X, 0,
                  sizeof(X_Spike_T));
  }

  /* Periodic continuous states */
  {
    (void) memset((void*) Spike_PeriodicIndX, 0,
                  3*sizeof(int_T));
    (void) memset((void*) Spike_PeriodicRngX, 0,
                  6*sizeof(real_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Spike_DW, 0,
                sizeof(DW_Spike_T));

  {
    FILE * a;
    int32_T i;

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Spike_X.ubvbwb_CSTATE[0] = Spike_P.uDOFEulerAngles_Vm_0[0];

    /* InitializeConditions for Integrator: '<S10>/phi theta psi' */
    Spike_X.phithetapsi_CSTATE[0] = Spike_P.uDOFEulerAngles_eul_0[0];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Spike_X.pqr_CSTATE[0] = Spike_P.uDOFEulerAngles_pm_0[0];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Spike_X.xeyeze_CSTATE[0] = Spike_P.uDOFEulerAngles_xme_0[0];

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Spike_X.ubvbwb_CSTATE[1] = Spike_P.uDOFEulerAngles_Vm_0[1];

    /* InitializeConditions for Integrator: '<S10>/phi theta psi' */
    Spike_X.phithetapsi_CSTATE[1] = Spike_P.uDOFEulerAngles_eul_0[1];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Spike_X.pqr_CSTATE[1] = Spike_P.uDOFEulerAngles_pm_0[1];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Spike_X.xeyeze_CSTATE[1] = Spike_P.uDOFEulerAngles_xme_0[1];

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Spike_X.ubvbwb_CSTATE[2] = Spike_P.uDOFEulerAngles_Vm_0[2];

    /* InitializeConditions for Integrator: '<S10>/phi theta psi' */
    Spike_X.phithetapsi_CSTATE[2] = Spike_P.uDOFEulerAngles_eul_0[2];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Spike_X.pqr_CSTATE[2] = Spike_P.uDOFEulerAngles_pm_0[2];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Spike_X.xeyeze_CSTATE[2] = Spike_P.uDOFEulerAngles_xme_0[2];

    /* SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_autoflush[i] = false;
      Spike_DW.eml_openfiles_c[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_e[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Aileron' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Aileron' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Tail right' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_l[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Tail right' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Tail left' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_j[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Tail left' */

    /* InitializeConditions for root-level periodic continuous states */
    {
      int_T rootPeriodicContStateIndices[3] = { 3, 4, 5 };

      real_T rootPeriodicContStateRanges[6] = { -3.1415926535897931,
        3.1415926535897931, -3.1415926535897931, 3.1415926535897931,
        -3.1415926535897931, 3.1415926535897931 };

      (void) memcpy((void*)Spike_PeriodicIndX, rootPeriodicContStateIndices,
                    3*sizeof(int_T));
      (void) memcpy((void*)Spike_PeriodicRngX, rootPeriodicContStateRanges,
                    6*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void Spike_terminate(void)
{
  /* (no terminate code required) */
}
