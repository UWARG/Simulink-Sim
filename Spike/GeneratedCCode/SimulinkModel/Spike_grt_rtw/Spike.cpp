/*
 * Spike.cpp
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

#include "Spike.h"
#include "Spike_private.h"

int32_T plook_s32dd_binxp(real_T u, const real_T bp[], uint32_T maxIndex, real_T
  *fraction, int32_T *prevIndex)
{
  int32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_s32d_prevIdx(u, bp, (uint32_T)*prevIndex, maxIndex);
    *fraction = (u - bp[(uint32_T)bpIndex]) / (bp[bpIndex + 1U] - bp[(uint32_T)
      bpIndex]);
  } else {
    bpIndex = (int32_T)(maxIndex - 1U);
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

real_T intrp3d_s32dl_pw(const int32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride[])
{
  real_T yL_2d;
  uint32_T offset_2d;
  real_T yL_1d;
  uint32_T offset_0d;

  /* Column-major Interpolation 3-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_2d = ((uint32_T)(bpIndex[2U] * (int32_T)stride[2U]) + bpIndex[1U] *
               (int32_T)stride[1U]) + bpIndex[0U];
  yL_1d = (table[offset_2d + 1U] - table[offset_2d]) * frac[0U] +
    table[offset_2d];
  offset_0d = offset_2d + stride[1U];
  yL_2d = (((table[offset_0d + 1U] - table[offset_0d]) * frac[0U] +
            table[offset_0d]) - yL_1d) * frac[1U] + yL_1d;
  offset_2d += stride[2U];
  yL_1d = (table[offset_2d + 1U] - table[offset_2d]) * frac[0U] +
    table[offset_2d];
  offset_0d = offset_2d + stride[1U];
  return (((((table[offset_0d + 1U] - table[offset_0d]) * frac[0U] +
             table[offset_0d]) - yL_1d) * frac[1U] + yL_1d) - yL_2d) * frac[2U]
    + yL_2d;
}

real_T intrp4d_s32dl_pw(const int32_T bpIndex[], const real_T frac[], const
  real_T table[], const uint32_T stride[])
{
  real_T yL_3d;
  uint32_T offset_3d;
  real_T yL_2d;
  real_T yL_1d;
  uint32_T offset_0d;
  uint32_T offset_1d;

  /* Column-major Interpolation 4-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_3d = (((uint32_T)(bpIndex[3U] * (int32_T)stride[3U]) + bpIndex[2U] *
                (int32_T)stride[2U]) + bpIndex[1U] * (int32_T)stride[1U]) +
    bpIndex[0U];
  yL_1d = (table[offset_3d + 1U] - table[offset_3d]) * frac[0U] +
    table[offset_3d];
  offset_0d = offset_3d + stride[1U];
  yL_2d = (((table[offset_0d + 1U] - table[offset_0d]) * frac[0U] +
            table[offset_0d]) - yL_1d) * frac[1U] + yL_1d;
  offset_1d = offset_3d + stride[2U];
  yL_1d = (table[offset_1d + 1U] - table[offset_1d]) * frac[0U] +
    table[offset_1d];
  offset_0d = offset_1d + stride[1U];
  yL_3d = (((((table[offset_0d + 1U] - table[offset_0d]) * frac[0U] +
              table[offset_0d]) - yL_1d) * frac[1U] + yL_1d) - yL_2d) * frac[2U]
    + yL_2d;
  offset_1d = offset_3d + stride[3U];
  yL_1d = (table[offset_1d + 1U] - table[offset_1d]) * frac[0U] +
    table[offset_1d];
  offset_0d = offset_1d + stride[1U];
  yL_2d = (((table[offset_0d + 1U] - table[offset_0d]) * frac[0U] +
            table[offset_0d]) - yL_1d) * frac[1U] + yL_1d;
  offset_1d += stride[2U];
  yL_1d = (table[offset_1d + 1U] - table[offset_1d]) * frac[0U] +
    table[offset_1d];
  offset_0d = offset_1d + stride[1U];
  return (((((((table[offset_0d + 1U] - table[offset_0d]) * frac[0U] +
               table[offset_0d]) - yL_1d) * frac[1U] + yL_1d) - yL_2d) * frac[2U]
           + yL_2d) - yL_3d) * frac[3U] + yL_3d;
}

int32_T binsearch_s32d_prevIdx(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;
  uint32_T found;

  /* Binary Search using Previous Index */
  bpIdx = startIndex;
  iLeft = 0U;
  iRght = maxIndex;
  found = 0U;
  while (found == 0U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx - 1U;
      bpIdx = (iRght + iLeft) >> 1U;
    } else if (u < bp[bpIdx + 1U]) {
      found = 1U;
    } else {
      iLeft = bpIdx + 1U;
      bpIdx = (iRght + iLeft) >> 1U;
    }
  }

  return (int32_T)bpIdx;
}

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) std::floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void SpikeModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
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
  this->step();
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
  this->step();
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

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void SpikeModelClass::Spike_emxInit_char_T(emxArray_char_T_Spike_T **pEmxArray,
  int32_T numDimensions)
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

void SpikeModelClass::Spike_emxInit_boolean_T(emxArray_boolean_T_Spike_T
  **pEmxArray, int32_T numDimensions)
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

void SpikeModelClass::Spike_emxInit_int32_T(emxArray_int32_T_Spike_T **pEmxArray,
  int32_T numDimensions)
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

/* Function for MATLAB Function: '<Root>/Read Aileron' */
int8_T SpikeModelClass::Spike_filedata(void)
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
int8_T SpikeModelClass::Spike_cfopen(const char * cfilename, const char
  * cpermission)
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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
FILE * SpikeModelClass::Spike_fileManager(real_T varargin_1)
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

void SpikeModelClass::Spike_emxInit_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray,
  int32_T numDimensions)
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

void SpikeModelClass::Spike_emxEnsureCapacity_uint8_T(emxArray_uint8_T_Spike_T
  *emxArray, int32_T oldNumel)
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

void SpikeModelClass::Spike_emxEnsureCapacity_int32_T(emxArray_int32_T_Spike_T
  *emxArray, int32_T oldNumel)
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

void SpikeModelClass::Spike_emxFree_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray)
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

void SpikeModelClass::Spike_emxFree_int32_T(emxArray_int32_T_Spike_T **pEmxArray)
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

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void SpikeModelClass::Spike_fclose(real_T fileID)
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

void SpikeModelClass::Spike_emxEnsureCapacity_char_T(emxArray_char_T_Spike_T
  *emxArray, int32_T oldNumel)
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

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void SpikeModelClass::Spike_readfile(emxArray_char_T_Spike_T *y)
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
  fileid = Spike_cfopen("ActuatorCommands/aileron.txt", "rb");
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

void SpikeModelClass::Spi_emxEnsureCapacity_boolean_T(emxArray_boolean_T_Spike_T
  *emxArray, int32_T oldNumel)
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
void SpikeModelClass::Spike_isstrprop(const emxArray_char_T_Spike_T *x,
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

void SpikeModelClass::Spike_emxInit_real_T(emxArray_real_T_Spike_T **pEmxArray,
  int32_T numDimensions)
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

void SpikeModelClass::Spike_emxEnsureCapacity_real_T(emxArray_real_T_Spike_T
  *emxArray, int32_T oldNumel)
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
void SpikeModelClass::Spike_char(const emxArray_real_T_Spike_T *varargin_1,
  emxArray_char_T_Spike_T *y)
{
  int32_T loop_ub;
  int32_T i;
  real_T u;
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_1->size[1];
  Spike_emxEnsureCapacity_char_T(y, i);
  loop_ub = varargin_1->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    u = varargin_1->data[i];
    if (u < 0.0) {
      u = std::ceil(u);
    } else {
      u = std::floor(u);
    }

    if (rtIsNaN(u) || rtIsInf(u)) {
      u = 0.0;
    } else {
      u = std::fmod(u, 256.0);
    }

    y->data[i] = (int8_T)(u < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-u :
                          (int32_T)(int8_T)(uint8_T)u);
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void SpikeModelClass::Spike_copysign(emxArray_char_T_Spike_T *s1, const
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
void SpikeModelClass::Spike_readNonFinite(const emxArray_char_T_Spike_T *s,
  int32_T *k, int32_T n, boolean_T *b_finite, real_T *fv)
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
boolean_T SpikeModelClass::Spike_copydigits(emxArray_char_T_Spike_T *s1, int32_T
  *idx, const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T
  allowpoint)
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
boolean_T SpikeModelClass::Spike_copyexponent(emxArray_char_T_Spike_T *s1,
  int32_T *idx, const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n)
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
void SpikeModelClass::Spike_skipspaces(const emxArray_char_T_Spike_T *s, int32_T
  *k, int32_T n)
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
boolean_T SpikeModelClass::Spike_copysign_d(emxArray_char_T_Spike_T *s1, int32_T
  *idx, const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n)
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
void SpikeModelClass::Spike_readfloat_j(emxArray_char_T_Spike_T *s1, int32_T
  *idx, const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *success)
{
  int32_T b_idx;
  int32_T b_k;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_idx = *idx;
  b_k = *k;
  *success = Spike_copysign_d(s1, &b_idx, s, &b_k, n);
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
void SpikeModelClass::Spike_readfloat(emxArray_char_T_Spike_T *s1, const
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
        Spike_readfloat_j(s1, idx, s, k, n, &unusedU0, b_finite, nfv, success);
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

void SpikeModelClass::Spike_emxFree_real_T(emxArray_real_T_Spike_T **pEmxArray)
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
void SpikeModelClass::Spike_readfloat_ju(emxArray_char_T_Spike_T *s1, int32_T
  *idx, const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *success)
{
  int32_T b_idx;
  int32_T b_k;
  boolean_T unusedU0;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_idx = *idx;
  b_k = *k;
  *success = Spike_copysign_d(s1, &b_idx, s, &b_k, n);
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
        Spike_readfloat_j(s1, idx, s, k, n, &unusedU0, b_finite, nfv, success);
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
real_T SpikeModelClass::Spike_sscanfd_o(const emxArray_char_T_Spike_T *s)
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
void SpikeModelClass::Spike_sscanfd(const emxArray_char_T_Spike_T *s, real_T
  *out1, real_T *out2)
{
  int32_T nread;
  nread = sscanf(&s->data[0], "%lf %lf", out1, out2);
  if (nread != 2) {
    *out1 = (rtNaN);
    *out2 = (rtNaN);
  }
}

void SpikeModelClass::Spike_emxFree_char_T(emxArray_char_T_Spike_T **pEmxArray)
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
creal_T SpikeModelClass::Spike_str2double(const emxArray_char_T_Spike_T *s)
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
      Spike_readfloat_ju(s1, &idx, s, &loop_ub, s->size[1], &success, &isfinite2,
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
          a = Spike_sscanfd_o(s1);
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

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void SpikeModelClass::Spike_fclose_g(void)
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
int8_T SpikeModelClass::Spike_filedata_p(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_p[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
int8_T SpikeModelClass::Spike_cfopen_j(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_p();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_p[j - 1] = filestar;
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
FILE * SpikeModelClass::Spike_fileManager_c(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = (int8_T)rt_roundd_snf(varargin_1);
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_p[fileid - 3];
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
void SpikeModelClass::Spike_fclose_f(real_T fileID)
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
    f = Spike_DW.eml_openfiles_p[b_fileid - 3];
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
      Spike_DW.eml_openfiles_p[fileid - 3] = NULL;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
void SpikeModelClass::Spike_readfile_e(emxArray_char_T_Spike_T *y)
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
  fileid = Spike_cfopen_j("ActuatorCommands/tailRight.txt", "rb");
  wherefrom = SEEK_END;
  filestar = Spike_fileManager_c((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  filestar = Spike_fileManager_c((real_T)fileid);
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
  filestar = Spike_fileManager_c((real_T)fileid);
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
      filestar = Spike_fileManager_c((real_T)fileid);
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
  Spike_fclose_f((real_T)fileid);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = (int8_T)Spike_B.buffer_c[i];
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
void SpikeModelClass::Spike_fclose_f0(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles_p[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles_p[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles_p[j] = NULL;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
int8_T SpikeModelClass::Spike_filedata_g(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_k[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
int8_T SpikeModelClass::Spike_cfopen_k(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_g();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_k[j - 1] = filestar;
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
FILE * SpikeModelClass::Spike_fileManager_p(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = (int8_T)rt_roundd_snf(varargin_1);
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_k[fileid - 3];
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
void SpikeModelClass::Spike_fclose_p(real_T fileID)
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
    f = Spike_DW.eml_openfiles_k[b_fileid - 3];
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
      Spike_DW.eml_openfiles_k[fileid - 3] = NULL;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
void SpikeModelClass::Spike_readfile_d(emxArray_char_T_Spike_T *y)
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
  fileid = Spike_cfopen_k("ActuatorCommands/tailLeft.txt", "rb");
  wherefrom = SEEK_END;
  filestar = Spike_fileManager_p((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }

  filestar = Spike_fileManager_p((real_T)fileid);
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
  filestar = Spike_fileManager_p((real_T)fileid);
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
      filestar = Spike_fileManager_p((real_T)fileid);
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
  Spike_fclose_p((real_T)fileid);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = (int8_T)Spike_B.buffer_m[i];
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
void SpikeModelClass::Spike_fclose_pn(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles_k[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles_k[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles_k[j] = NULL;
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int8_T SpikeModelClass::Spike_filedata_p2(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_b[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int8_T SpikeModelClass::Spike_cfopen_b(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_p2();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_b[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
FILE * SpikeModelClass::Spike_fileManager_h(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = (int8_T)rt_roundd_snf(varargin_1);
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_b[fileid - 3];
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

/* Function for MATLAB Function: '<Root>/Read Throttle' */
void SpikeModelClass::Spike_fclose_l(real_T fileID)
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
    f = Spike_DW.eml_openfiles_b[b_fileid - 3];
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
      Spike_DW.eml_openfiles_b[fileid - 3] = NULL;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
void SpikeModelClass::Spike_readfile_m(emxArray_char_T_Spike_T *y)
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
  fileid = Spike_cfopen_b("ActuatorCommands/throttle.txt", "rb");
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
  Spike_fclose_l((real_T)fileid);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = (int8_T)Spike_B.buffer_k[i];
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
void SpikeModelClass::Spike_fclose_lh(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles_b[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles_b[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles_b[j] = NULL;
      }
    }
  }
}

void SpikeModelClass::Spike_emxFree_boolean_T(emxArray_boolean_T_Spike_T
  **pEmxArray)
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

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int8_T SpikeModelClass::Spike_filedata_m(void)
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

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int8_T SpikeModelClass::Spike_cfopen_m(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_m();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_j[j - 1] = filestar;
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
void SpikeModelClass::Spike_fclose_d(void)
{
  int32_T cst;
  int32_T j;
  for (j = 0; j < 20; j++) {
    if (Spike_DW.eml_openfiles_j[j] != NULL) {
      cst = fclose(Spike_DW.eml_openfiles_j[j]);
      if (cst == 0) {
        Spike_DW.eml_openfiles_j[j] = NULL;
        Spike_DW.eml_autoflush[j] = true;
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
  maxval = std::abs(u1[0]);
  a21 = std::abs(u1[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (std::abs(u1[2]) > maxval) {
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
  if (std::abs(A[3 + r3]) > std::abs(A[3 + r2])) {
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
void SpikeModelClass::step()
{
  emxArray_char_T_Spike_T *A;
  emxArray_boolean_T_Spike_T *TF;
  real_T C;
  emxArray_int32_T_Spike_T *ii;
  int32_T nx;
  int32_T idx;
  real_T C_0;
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
  int8_T k_fileid;
  int8_T l_fileid;
  FILE * b_NULL;
  FILE * f;
  boolean_T a;
  int32_T rtb_idxm;
  real_T rtb_fm;
  int32_T rtb_idxh;
  real_T rtb_fh;
  int32_T rtb_idxa;
  real_T rtb_Gain;
  int32_T rtb_idxm_h;
  real_T rtb_fm_n;
  real_T rtb_referencearea;
  real_T rtb_referencearea_k;
  real_T rtb_ixk;
  real_T rtb_jxi;
  real_T rtb_Sideslip_c;
  real_T rtb_kxj;
  real_T frac[3];
  int32_T bpIndex[3];
  real_T frac_0[4];
  int32_T bpIndex_0[4];
  real_T frac_1[4];
  int32_T bpIndex_1[4];
  real_T frac_2[3];
  int32_T bpIndex_2[3];
  real_T frac_3[3];
  int32_T bpIndex_3[3];
  real_T frac_4[3];
  int32_T bpIndex_4[3];
  real_T frac_5[3];
  int32_T bpIndex_5[3];
  real_T frac_6[3];
  int32_T bpIndex_6[3];
  real_T frac_7[3];
  int32_T bpIndex_7[3];
  real_T frac_8[3];
  int32_T bpIndex_8[3];
  real_T frac_9[3];
  int32_T bpIndex_9[3];
  real_T frac_a[3];
  int32_T bpIndex_a[3];
  real_T rtb_VectorConcatenate[18];
  real_T Gain;
  real_T VectorConcatenate[9];
  emxArray_char_T_Spike_T *A_0;
  emxArray_char_T_Spike_T *A_1;
  emxArray_char_T_Spike_T *A_2;
  emxArray_char_T_Spike_T *A_3;
  int32_T i;
  real_T rtb_sincos_o2_idx_1;
  real_T rtb_Sum_d_idx_3;
  real_T rtb_Sum_d_idx_4;
  real_T rtb_Sum_d_idx_5;
  real_T rtb_sincos_o1_idx_0;
  real_T rtb_sincos_o1_idx_1;
  creal_T tmp;
  creal_T tmp_0;
  real_T Airspeed_tmp;
  real_T rtb_sincos_o2_idx_0;
  real_T C_tmp;
  real_T frac_tmp;
  real_T rtb_Sum1_idx_2_tmp;
  real_T rtb_Sum1_idx_1_tmp;
  real_T frac_tmp_0;
  int32_T rtb_VectorConcatenate_tmp;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* set solver stop time */
    if (!((&Spike_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&Spike_M)->solverInfo, (((&Spike_M)
        ->Timing.clockTickH0 + 1) * (&Spike_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&Spike_M)->solverInfo, (((&Spike_M)
        ->Timing.clockTick0 + 1) * (&Spike_M)->Timing.stepSize0 + (&Spike_M)
        ->Timing.clockTickH0 * (&Spike_M)->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Spike_M))) {
    (&Spike_M)->Timing.t[0] = rtsiGetT(&(&Spike_M)->solverInfo);
  }

  /* Sum: '<S101>/Sum' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S101>/Product'
   *  Product: '<S101>/Product1'
   *  Product: '<S101>/Product2'
   *  Sum: '<S98>/Sum'
   */
  rtb_referencearea_k = (Spike_X.ubvbwb_CSTATE[0] * Spike_X.ubvbwb_CSTATE[0] +
    Spike_X.ubvbwb_CSTATE[1] * Spike_X.ubvbwb_CSTATE[1]) +
    Spike_X.ubvbwb_CSTATE[2] * Spike_X.ubvbwb_CSTATE[2];

  /* Sqrt: '<S7>/Airspeed' incorporates:
   *  Sum: '<S101>/Sum'
   */
  Airspeed_tmp = std::sqrt(rtb_referencearea_k);

  /* Gain: '<Root>/Gain' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Trigonometry: '<S7>/Incidence'
   */
  Gain = Spike_P.Gain_Gain * rt_atan2d_snf(Spike_X.ubvbwb_CSTATE[2],
    Spike_X.ubvbwb_CSTATE[0]);

  /* Gain: '<S6>/1//2rhoV^2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Product: '<S6>/Product2'
   */
  rtb_referencearea_k = rtb_referencearea_k * Spike_P.Constant2_Value *
    Spike_P.u2rhoV2_Gain;

  /* Gain: '<S4>/reference area' */
  rtb_referencearea = Spike_P.AerodynamicForcesandMoments_S *
    rtb_referencearea_k;
  Spike_emxInit_char_T(&A, 2);
  Spike_emxInit_boolean_T(&TF, 2);
  Spike_emxInit_int32_T(&ii, 2);
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* MATLAB Function: '<Root>/Read Aileron' */
    Spike_readfile(A);
    Spike_isstrprop(A, TF);
    nx = TF->size[1];
    idx = 0;
    i = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = TF->size[1];
    Spike_emxEnsureCapacity_int32_T(ii, i);
    rtb_idxm_h = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_idxm_h <= nx - 1)) {
      if (TF->data[rtb_idxm_h]) {
        idx++;
        ii->data[idx - 1] = rtb_idxm_h + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          rtb_idxm_h++;
        }
      } else {
        rtb_idxm_h++;
      }
    }

    if (TF->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      i = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      Spike_emxEnsureCapacity_int32_T(ii, i);
    }

    nx = 1;
    if (ii->size[1] > 2) {
      nx = ii->data[ii->size[1] - 3];
    }

    if (nx > A->size[1]) {
      nx = 1;
      idx = 0;
    } else {
      idx = A->size[1];
    }

    Spike_emxInit_char_T(&A_3, 2);

    /* MATLAB Function: '<Root>/Read Aileron' */
    i = A_3->size[0] * A_3->size[1];
    A_3->size[0] = 1;
    idx -= nx;
    A_3->size[1] = idx + 1;
    Spike_emxEnsureCapacity_char_T(A_3, i);
    for (i = 0; i <= idx; i++) {
      A_3->data[i] = A->data[(nx + i) - 1];
    }

    tmp = Spike_str2double(A_3);
    Spike_fclose_g();

    /* PreLookup: '<S2>/(deltal)' incorporates:
     *  MATLAB Function: '<Root>/Read Aileron'
     *  UnitConversion: '<S40>/Unit Conversion'
     */
    /* Unit Conversion - from: rad to: deg
       Expression: output = (57.2958*input) + (0) */
    Spike_B.idxdelL = plook_s32dd_binxp(tmp.re * 0.2618 / 100.0 *
      57.295779513082323, Spike_P.deltal_BreakpointsData, 8U, &Spike_B.fdelL,
      &Spike_DW.deltal_DWORK1);
    Spike_emxFree_char_T(&A_3);
  }

  /* Product: '<S102>/Product1' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   */
  rtb_fh = Spike_X.ubvbwb_CSTATE[1] * Spike_X.ubvbwb_CSTATE[1];

  /* Product: '<S102>/Product2' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   */
  rtb_fm = Spike_X.ubvbwb_CSTATE[2] * Spike_X.ubvbwb_CSTATE[2];

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S102>/Product'
   *  Product: '<S102>/Product1'
   *  Product: '<S102>/Product2'
   *  Sqrt: '<S8>/vt'
   *  Sum: '<S102>/Sum'
   */
  rtb_fm_n = std::sqrt((Spike_X.ubvbwb_CSTATE[0] * Spike_X.ubvbwb_CSTATE[0] +
                        rtb_fh) + rtb_fm) / Spike_P.Constant1_Value_g;

  /* PreLookup: '<S2>/(Mach)' */
  rtb_idxm = plook_s32dd_binxp(rtb_fm_n, Spike_P.Mach_BreakpointsData, 2U,
    &rtb_fm, &Spike_DW.Mach_DWORK1);

  /* PreLookup: '<S2>/(altitude)' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   */
  rtb_idxh = plook_s32dd_binxp(Spike_X.xeyeze_CSTATE[2],
    Spike_P.altitude_BreakpointsData, 2U, &rtb_fh, &Spike_DW.altitude_DWORK1);

  /* Interpolation_n-D: '<S35>/clroll' */
  frac[0] = Spike_B.fdelL;
  frac[1] = rtb_fm;
  frac[2] = rtb_fh;
  bpIndex[0] = Spike_B.idxdelL;
  bpIndex[1] = rtb_idxm;
  bpIndex[2] = rtb_idxh;
  rtb_Sideslip_c = intrp3d_s32dl_pw(bpIndex, frac, Spike_P.clroll_Table,
    Spike_P.clroll_dimSize);

  /* UnitConversion: '<S38>/Unit Conversion' */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_Gain = 57.295779513082323 * Gain;

  /* PreLookup: '<S2>/(alpha)' */
  rtb_idxa = plook_s32dd_binxp(rtb_Gain, Spike_P.alpha_BreakpointsData, 11U,
    &rtb_Gain, &Spike_DW.alpha_DWORK1);

  /* Interpolation_n-D: '<S35>/CmYaw ' */
  frac_0[0] = rtb_Gain;
  frac_0[1] = Spike_B.fdelL;
  frac_0[2] = rtb_fm;
  frac_0[3] = rtb_fh;
  bpIndex_0[0] = rtb_idxa;
  bpIndex_0[1] = Spike_B.idxdelL;
  bpIndex_0[2] = rtb_idxm;
  bpIndex_0[3] = rtb_idxh;
  rtb_jxi = intrp4d_s32dl_pw(bpIndex_0, frac_0, Spike_P.CmYaw_Table,
    Spike_P.CmYaw_dimSize);
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* MATLAB Function: '<Root>/Read Tail right' */
    Spike_readfile_e(A);
    Spike_isstrprop(A, TF);
    nx = TF->size[1];
    idx = 0;
    i = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = TF->size[1];
    Spike_emxEnsureCapacity_int32_T(ii, i);
    rtb_idxm_h = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_idxm_h <= nx - 1)) {
      if (TF->data[rtb_idxm_h]) {
        idx++;
        ii->data[idx - 1] = rtb_idxm_h + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          rtb_idxm_h++;
        }
      } else {
        rtb_idxm_h++;
      }
    }

    if (TF->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      i = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      Spike_emxEnsureCapacity_int32_T(ii, i);
    }

    nx = 1;
    if (ii->size[1] > 2) {
      nx = ii->data[ii->size[1] - 3];
    }

    if (nx > A->size[1]) {
      nx = 1;
      idx = 0;
    } else {
      idx = A->size[1];
    }

    Spike_emxInit_char_T(&A_2, 2);

    /* MATLAB Function: '<Root>/Read Tail right' */
    i = A_2->size[0] * A_2->size[1];
    A_2->size[0] = 1;
    idx -= nx;
    A_2->size[1] = idx + 1;
    Spike_emxEnsureCapacity_char_T(A_2, i);
    for (i = 0; i <= idx; i++) {
      A_2->data[i] = A->data[(nx + i) - 1];
    }

    tmp = Spike_str2double(A_2);
    Spike_fclose_f0();

    /* MATLAB Function: '<Root>/Read Tail left' */
    Spike_readfile_d(A);
    Spike_isstrprop(A, TF);
    nx = TF->size[1];
    idx = 0;
    i = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = TF->size[1];
    Spike_emxEnsureCapacity_int32_T(ii, i);
    rtb_idxm_h = 0;
    Spike_emxFree_char_T(&A_2);
    exitg1 = false;
    while ((!exitg1) && (rtb_idxm_h <= nx - 1)) {
      if (TF->data[rtb_idxm_h]) {
        idx++;
        ii->data[idx - 1] = rtb_idxm_h + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          rtb_idxm_h++;
        }
      } else {
        rtb_idxm_h++;
      }
    }

    /* MATLAB Function: '<Root>/Read Tail left' */
    if (TF->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      i = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      Spike_emxEnsureCapacity_int32_T(ii, i);
    }

    nx = 1;
    if (ii->size[1] > 2) {
      nx = ii->data[ii->size[1] - 3];
    }

    if (nx > A->size[1]) {
      nx = 1;
      idx = 0;
    } else {
      idx = A->size[1];
    }

    Spike_emxInit_char_T(&A_1, 2);

    /* MATLAB Function: '<Root>/Read Tail left' */
    i = A_1->size[0] * A_1->size[1];
    A_1->size[0] = 1;
    idx -= nx;
    A_1->size[1] = idx + 1;
    Spike_emxEnsureCapacity_char_T(A_1, i);
    for (i = 0; i <= idx; i++) {
      A_1->data[i] = A->data[(nx + i) - 1];
    }

    tmp_0 = Spike_str2double(A_1);
    Spike_fclose_pn();

    /* PreLookup: '<S2>/(delta)' incorporates:
     *  Gain: '<S2>/Gain1'
     *  MATLAB Function: '<Root>/Read Tail left'
     *  MATLAB Function: '<Root>/Read Tail right'
     *  MATLAB Function: '<Root>/SeperateYawAndPitch'
     *  UnitConversion: '<S39>/Unit Conversion'
     */
    /* Unit Conversion - from: rad to: deg
       Expression: output = (57.2958*input) + (0) */
    Spike_B.idxde = plook_s32dd_binxp((tmp.re - tmp_0.re) / 1.4142135623730951 *
      0.436 / 100.0 * Spike_P.Gain1_Gain * 57.295779513082323,
      Spike_P.delta_BreakpointsData, 6U, &Spike_B.fde, &Spike_DW.delta_DWORK1);
    Spike_emxFree_char_T(&A_1);
  }

  /* Interpolation_n-D: '<S36>/DCDI' */
  frac_1[0] = rtb_Gain;
  frac_1[1] = rtb_fm;
  frac_1[2] = rtb_fh;
  frac_1[3] = Spike_B.fde;
  bpIndex_1[0] = rtb_idxa;
  bpIndex_1[1] = rtb_idxm;
  bpIndex_1[2] = rtb_idxh;
  bpIndex_1[3] = Spike_B.idxde;
  rtb_ixk = intrp4d_s32dl_pw(bpIndex_1, frac_1, Spike_P.DCDI_Table,
    Spike_P.DCDI_dimSize);

  /* Interpolation_n-D: '<S36>/DCL' */
  frac_2[0] = Spike_B.fde;
  frac_2[1] = rtb_fm;
  frac_2[2] = rtb_fh;
  bpIndex_2[0] = Spike_B.idxde;
  bpIndex_2[1] = rtb_idxm;
  bpIndex_2[2] = rtb_idxh;
  C = intrp3d_s32dl_pw(bpIndex_2, frac_2, Spike_P.DCL_Table, Spike_P.DCL_dimSize);

  /* Interpolation_n-D: '<S36>/DCm' */
  frac_3[0] = Spike_B.fde;
  frac_3[1] = rtb_fm;
  frac_3[2] = rtb_fh;
  bpIndex_3[0] = Spike_B.idxde;
  bpIndex_3[1] = rtb_idxm;
  bpIndex_3[2] = rtb_idxh;
  C_0 = intrp3d_s32dl_pw(bpIndex_3, frac_3, Spike_P.DCm_Table,
    Spike_P.DCm_dimSize);

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S37>/Constant1'
   */
  rtb_Sum_d_idx_3 = (rtb_Sideslip_c + Spike_P.Constant1_Value_l) +
    Spike_P.Constant1_Value_n;
  rtb_Sum_d_idx_4 = (Spike_P.Constant1_Value + C_0) + Spike_P.Constant1_Value_n;
  rtb_Sum_d_idx_5 = (rtb_jxi + Spike_P.Constant1_Value_l) +
    Spike_P.Constant1_Value_n;

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S4>/coefAdjust'
   *  Sum: '<S2>/Sum'
   */
  frac[0] = ((Spike_P.Constant1_Value + rtb_ixk) + Spike_P.Constant1_Value_n) *
    Spike_P.coefAdjust_Gain[0] * rtb_referencearea;
  frac[1] = ((Spike_P.Constant1_Value + Spike_P.Constant1_Value_l) +
             Spike_P.Constant1_Value_n) * Spike_P.coefAdjust_Gain[1] *
    rtb_referencearea;
  frac[2] = ((Spike_P.Constant1_Value + C) + Spike_P.Constant1_Value_n) *
    Spike_P.coefAdjust_Gain[2] * rtb_referencearea;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* MATLAB Function: '<Root>/Read Throttle' */
    Spike_readfile_m(A);
    Spike_isstrprop(A, TF);
    nx = TF->size[1];
    idx = 0;
    i = ii->size[0] * ii->size[1];
    ii->size[0] = 1;
    ii->size[1] = TF->size[1];
    Spike_emxEnsureCapacity_int32_T(ii, i);
    rtb_idxm_h = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_idxm_h <= nx - 1)) {
      if (TF->data[rtb_idxm_h]) {
        idx++;
        ii->data[idx - 1] = rtb_idxm_h + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          rtb_idxm_h++;
        }
      } else {
        rtb_idxm_h++;
      }
    }

    if (TF->size[1] == 1) {
      if (idx == 0) {
        ii->size[0] = 1;
        ii->size[1] = 0;
      }
    } else {
      i = ii->size[0] * ii->size[1];
      if (1 > idx) {
        ii->size[1] = 0;
      } else {
        ii->size[1] = idx;
      }

      Spike_emxEnsureCapacity_int32_T(ii, i);
    }

    nx = 1;
    if (ii->size[1] > 2) {
      nx = ii->data[ii->size[1] - 3];
    }

    if (nx > A->size[1]) {
      nx = 1;
      idx = 0;
    } else {
      idx = A->size[1];
    }

    Spike_emxInit_char_T(&A_0, 2);

    /* MATLAB Function: '<Root>/Read Throttle' */
    i = A_0->size[0] * A_0->size[1];
    A_0->size[0] = 1;
    idx -= nx;
    A_0->size[1] = idx + 1;
    Spike_emxEnsureCapacity_char_T(A_0, i);
    for (i = 0; i <= idx; i++) {
      A_0->data[i] = A->data[(nx + i) - 1];
    }

    tmp = Spike_str2double(A_0);
    Spike_fclose_lh();

    /* MATLAB Function: '<Root>/propulsion' incorporates:
     *  MATLAB Function: '<Root>/Read Throttle'
     */
    Spike_B.forces[0] = tmp.re / 100.0 * 2200.0;
    Spike_B.forces[1] = 0.0;
    Spike_B.forces[2] = 0.0;
    Spike_emxFree_char_T(&A_0);
  }

  Spike_emxFree_int32_T(&ii);
  Spike_emxFree_boolean_T(&TF);
  Spike_emxFree_char_T(&A);

  /* Trigonometry: '<S25>/sincos' incorporates:
   *  Integrator: '<S17>/phi theta psi'
   *  SignalConversion: '<S25>/TmpSignal ConversionAtsincosInport1'
   *  Trigonometry: '<S26>/sincos'
   */
  rtb_ixk = std::cos(Spike_X.phithetapsi_CSTATE[2]);
  frac_2[0] = std::sin(Spike_X.phithetapsi_CSTATE[2]);
  rtb_Sum1_idx_1_tmp = std::cos(Spike_X.phithetapsi_CSTATE[1]);
  frac_tmp_0 = std::sin(Spike_X.phithetapsi_CSTATE[1]);
  rtb_Sum1_idx_2_tmp = std::cos(Spike_X.phithetapsi_CSTATE[0]);
  frac_tmp = std::sin(Spike_X.phithetapsi_CSTATE[0]);

  /* Fcn: '<S25>/Fcn11' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[0] = rtb_Sum1_idx_1_tmp * rtb_ixk;

  /* Fcn: '<S25>/Fcn21' incorporates:
   *  Fcn: '<S25>/Fcn22'
   *  Trigonometry: '<S25>/sincos'
   */
  C_0 = frac_tmp * frac_tmp_0;
  VectorConcatenate[1] = C_0 * rtb_ixk - rtb_Sum1_idx_2_tmp * frac_2[0];

  /* Fcn: '<S25>/Fcn31' incorporates:
   *  Fcn: '<S25>/Fcn32'
   *  Trigonometry: '<S25>/sincos'
   */
  rtb_Sideslip_c = rtb_Sum1_idx_2_tmp * frac_tmp_0;
  VectorConcatenate[2] = rtb_Sideslip_c * rtb_ixk + frac_tmp * frac_2[0];

  /* Fcn: '<S25>/Fcn12' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[3] = rtb_Sum1_idx_1_tmp * frac_2[0];

  /* Fcn: '<S25>/Fcn22' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[4] = C_0 * frac_2[0] + rtb_Sum1_idx_2_tmp * rtb_ixk;

  /* Fcn: '<S25>/Fcn32' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[5] = rtb_Sideslip_c * frac_2[0] - frac_tmp * rtb_ixk;

  /* Fcn: '<S25>/Fcn13' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[6] = -frac_tmp_0;

  /* Fcn: '<S25>/Fcn23' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[7] = frac_tmp * rtb_Sum1_idx_1_tmp;

  /* Fcn: '<S25>/Fcn33' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[8] = rtb_Sum1_idx_2_tmp * rtb_Sum1_idx_1_tmp;

  /* Product: '<S63>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S48>/Product'
   *  Product: '<S76>/Product'
   *  Product: '<S76>/Product1'
   *  Product: '<S76>/Product2'
   *  Product: '<S78>/Product'
   *  Sqrt: '<S63>/Airspeed'
   *  Sum: '<S76>/Sum'
   */
  C_tmp = Spike_X.ubvbwb_CSTATE[1] / std::sqrt((Spike_X.ubvbwb_CSTATE[0] *
    Spike_X.ubvbwb_CSTATE[0] + Spike_X.ubvbwb_CSTATE[1] * Spike_X.ubvbwb_CSTATE
    [1]) + Spike_X.ubvbwb_CSTATE[2] * Spike_X.ubvbwb_CSTATE[2]);
  C = C_tmp;

  /* Trigonometry: '<S63>/Incidence' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   */
  rtb_sincos_o2_idx_0 = rt_atan2d_snf(Spike_X.ubvbwb_CSTATE[2],
    Spike_X.ubvbwb_CSTATE[0]);

  /* Trigonometry: '<S63>/Sideslip' incorporates:
   *  Product: '<S63>/Product'
   */
  if (C_tmp > 1.0) {
    C = 1.0;
  } else {
    if (C_tmp < -1.0) {
      C = -1.0;
    }
  }

  /* SignalConversion: '<S62>/TmpSignal ConversionAtsincosInport1' incorporates:
   *  Trigonometry: '<S63>/Sideslip'
   */
  rtb_sincos_o2_idx_1 = std::asin(C);

  /* Trigonometry: '<S62>/sincos' incorporates:
   *  Trigonometry: '<S63>/Incidence'
   */
  rtb_sincos_o1_idx_0 = std::cos(rtb_sincos_o2_idx_0);
  rtb_sincos_o2_idx_0 = std::sin(rtb_sincos_o2_idx_0);
  rtb_sincos_o1_idx_1 = std::cos(rtb_sincos_o2_idx_1);
  rtb_ixk = std::sin(rtb_sincos_o2_idx_1);

  /* Product: '<S64>/u(3)*u(4)' */
  Spike_B.VectorConcatenate_n[0] = rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_1;

  /* UnaryMinus: '<S67>/Unary Minus' incorporates:
   *  Product: '<S67>/u(2)*u(3)'
   */
  Spike_B.VectorConcatenate_n[1] = -(rtb_ixk * rtb_sincos_o1_idx_0);

  /* UnaryMinus: '<S70>/Unary Minus' */
  Spike_B.VectorConcatenate_n[2] = -rtb_sincos_o2_idx_0;

  /* SignalConversion: '<S73>/ConcatBufferAtVector ConcatenateIn4' */
  Spike_B.VectorConcatenate_n[3] = rtb_ixk;

  /* SignalConversion: '<S73>/ConcatBufferAtVector ConcatenateIn5' */
  Spike_B.VectorConcatenate_n[4] = rtb_sincos_o1_idx_1;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Constant: '<S71>/Constant' */
    Spike_B.VectorConcatenate_n[5] = Spike_P.Constant_Value;
  }

  /* Product: '<S66>/u(1)*u(4)' */
  Spike_B.VectorConcatenate_n[6] = rtb_sincos_o2_idx_0 * rtb_sincos_o1_idx_1;

  /* UnaryMinus: '<S69>/Unary Minus' incorporates:
   *  Product: '<S69>/u(1)*u(2)'
   */
  Spike_B.VectorConcatenate_n[7] = -(rtb_sincos_o2_idx_0 * rtb_ixk);

  /* SignalConversion: '<S73>/ConcatBufferAtVector ConcatenateIn9' */
  Spike_B.VectorConcatenate_n[8] = rtb_sincos_o1_idx_0;

  /* Gain: '<S3>/reference area' */
  rtb_referencearea_k *= Spike_P.AerodynamicForcesandMoments_S_g;

  /* UnitConversion: '<S5>/Unit Conversion' */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  C_0 = 57.295779513082323 * Gain;

  /* PreLookup: '<Root>/(alpha)' */
  idx = plook_s32dd_binxp(C_0, Spike_P.alpha_BreakpointsData_d, 11U, &C_0,
    &Spike_DW.alpha_DWORK1_n);

  /* PreLookup: '<Root>/(Mach)' */
  rtb_idxm_h = plook_s32dd_binxp(rtb_fm_n, Spike_P.Mach_BreakpointsData_e, 2U,
    &rtb_fm_n, &Spike_DW.Mach_DWORK1_m);

  /* PreLookup: '<Root>/(altitude)' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   */
  nx = plook_s32dd_binxp(Spike_X.xeyeze_CSTATE[2],
    Spike_P.altitude_BreakpointsData_i, 2U, &C, &Spike_DW.altitude_DWORK1_p);

  /* Interpolation_n-D: '<Root>/CD' */
  frac_4[0] = C_0;
  frac_4[1] = rtb_fm_n;
  frac_4[2] = C;
  bpIndex_4[0] = idx;
  bpIndex_4[1] = rtb_idxm_h;
  bpIndex_4[2] = nx;
  rtb_ixk = intrp3d_s32dl_pw(bpIndex_4, frac_4, Spike_P.CD_Table,
    Spike_P.CD_dimSize);

  /* Interpolation_n-D: '<Root>/CYb' */
  frac_5[0] = C_0;
  frac_5[1] = rtb_fm_n;
  frac_5[2] = C;
  bpIndex_5[0] = idx;
  bpIndex_5[1] = rtb_idxm_h;
  bpIndex_5[2] = nx;
  rtb_jxi = intrp3d_s32dl_pw(bpIndex_5, frac_5, Spike_P.CYb_Table,
    Spike_P.CYb_dimSize);

  /* Product: '<S7>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Sqrt: '<S7>/Airspeed'
   */
  rtb_sincos_o2_idx_0 = Spike_X.ubvbwb_CSTATE[1] / Airspeed_tmp;

  /* Trigonometry: '<S7>/Sideslip' incorporates:
   *  Product: '<S7>/Product'
   */
  if (rtb_sincos_o2_idx_0 > 1.0) {
    rtb_sincos_o2_idx_0 = 1.0;
  } else {
    if (rtb_sincos_o2_idx_0 < -1.0) {
      rtb_sincos_o2_idx_0 = -1.0;
    }
  }

  rtb_Sideslip_c = std::asin(rtb_sincos_o2_idx_0);

  /* End of Trigonometry: '<S7>/Sideslip' */

  /* Product: '<Root>/Product2' */
  rtb_jxi *= rtb_Sideslip_c;

  /* Interpolation_n-D: '<Root>/CL' */
  frac_6[0] = C_0;
  frac_6[1] = rtb_fm_n;
  frac_6[2] = C;
  bpIndex_6[0] = idx;
  bpIndex_6[1] = rtb_idxm_h;
  bpIndex_6[2] = nx;
  rtb_kxj = intrp3d_s32dl_pw(bpIndex_6, frac_6, Spike_P.CL_Table,
    Spike_P.CL_dimSize);

  /* Gain: '<Root>/Gain1' */
  rtb_kxj *= Spike_P.Gain1_Gain_e;

  /* Product: '<S3>/Product' incorporates:
   *  Gain: '<S3>/coefAdjust'
   */
  rtb_ixk = Spike_P.coefAdjust_Gain_h[0] * rtb_ixk * rtb_referencearea_k;
  rtb_jxi = Spike_P.coefAdjust_Gain_h[1] * rtb_jxi * rtb_referencearea_k;
  rtb_kxj = Spike_P.coefAdjust_Gain_h[2] * rtb_kxj * rtb_referencearea_k;

  /* Sum: '<S20>/Sum' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S33>/i x j'
   *  Product: '<S33>/j x k'
   *  Product: '<S33>/k x i'
   *  Product: '<S34>/i x k'
   *  Product: '<S34>/j x i'
   *  Product: '<S34>/k x j'
   */
  frac_2[0] = Spike_X.ubvbwb_CSTATE[1] * Spike_X.pqr_CSTATE[2] -
    Spike_X.ubvbwb_CSTATE[2] * Spike_X.pqr_CSTATE[1];
  frac_2[1] = Spike_X.ubvbwb_CSTATE[2] * Spike_X.pqr_CSTATE[0] -
    Spike_X.ubvbwb_CSTATE[0] * Spike_X.pqr_CSTATE[2];
  frac_2[2] = Spike_X.ubvbwb_CSTATE[0] * Spike_X.pqr_CSTATE[1] -
    Spike_X.ubvbwb_CSTATE[1] * Spike_X.pqr_CSTATE[0];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S19>/Constant'
     *  MATLAB Function: '<Root>/WriteToFile'
     *  MATLAB Function: '<Root>/gravity'
     *  Math: '<S43>/Transpose'
     *  Product: '<S1>/Product'
     *  Product: '<S43>/Product'
     *  Sum: '<Root>/Add'
     */
    rtb_sincos_o1_idx_0 = VectorConcatenate[i + 3] * 0.0;
    rtb_sincos_o2_idx_0 = VectorConcatenate[i + 6];
    Spike_B.Sum[i] = ((((rtb_sincos_o1_idx_0 + VectorConcatenate[i] * 0.0) +
                        rtb_sincos_o2_idx_0 * -7840.0000000000009) + (frac[i] +
      Spike_B.forces[i])) + (Spike_B.VectorConcatenate_n[3 * i + 2] * rtb_kxj +
      (Spike_B.VectorConcatenate_n[3 * i + 1] * rtb_jxi +
       Spike_B.VectorConcatenate_n[3 * i] * rtb_ixk))) /
      Spike_P.uDOFEulerAngles_mass_0 + frac_2[i];

    /* MATLAB Function: '<Root>/WriteToFile' */
    frac_4[i] = rtb_sincos_o2_idx_0 * -9.8 + (rtb_sincos_o1_idx_0 +
      VectorConcatenate[i] * 0.0);
  }

  /* MATLAB Function: '<Root>/WriteToFile' incorporates:
   *  Integrator: '<S17>/phi theta psi'
   *  Integrator: '<S1>/p,q,r '
   *  Integrator: '<S1>/xe,ye,ze'
   *  Sqrt: '<S7>/Airspeed'
   */
  fileid = Spike_cfopen_m("SensorOutputs/airspeed.txt", "ab");
  b_fileid = Spike_cfopen_m("SensorOutputs/angleOfAttack.txt", "ab");
  c_fileid = Spike_cfopen_m("SensorOutputs/altitude.txt", "ab");
  d_fileid = Spike_cfopen_m("SensorOutputs/roll.txt", "ab");
  e_fileid = Spike_cfopen_m("SensorOutputs/pitch.txt", "ab");
  f_fileid = Spike_cfopen_m("SensorOutputs/yaw.txt", "ab");
  g_fileid = Spike_cfopen_m("SensorOutputs/accX.txt", "ab");
  h_fileid = Spike_cfopen_m("SensorOutputs/accY.txt", "ab");
  i_fileid = Spike_cfopen_m("SensorOutputs/accZ.txt", "ab");
  j_fileid = Spike_cfopen_m("SensorOutputs/gyrX.txt", "ab");
  k_fileid = Spike_cfopen_m("SensorOutputs/gyrY.txt", "ab");
  l_fileid = Spike_cfopen_m("SensorOutputs/gyrZ.txt", "ab");
  b_NULL = NULL;
  if ((fileid > 22) || (fileid < 0)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[fileid - 3];
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
    fprintf(f, "%f\n", Airspeed_tmp);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((b_fileid > 22) || (b_fileid < 0)) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[b_fileid - 3];
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
    fprintf(f, "%f\n", Gain);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((c_fileid > 22) || (c_fileid < 0)) {
    c_fileid = -1;
  }

  if (c_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[c_fileid - 3];
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
    fprintf(f, "%f\n", Spike_X.xeyeze_CSTATE[2]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((d_fileid > 22) || (d_fileid < 0)) {
    d_fileid = -1;
  }

  if (d_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[d_fileid - 3];
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
    fprintf(f, "%f\n", Spike_X.phithetapsi_CSTATE[0]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((e_fileid > 22) || (e_fileid < 0)) {
    e_fileid = -1;
  }

  if (e_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[e_fileid - 3];
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
    fprintf(f, "%f\n", Spike_X.phithetapsi_CSTATE[1]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((f_fileid > 22) || (f_fileid < 0)) {
    f_fileid = -1;
  }

  if (f_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[f_fileid - 3];
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
    fprintf(f, "%f\n", Spike_X.phithetapsi_CSTATE[2]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((g_fileid > 22) || (g_fileid < 0)) {
    g_fileid = -1;
  }

  if (g_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[g_fileid - 3];
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
    fprintf(f, "%f\n", frac_4[0] + Spike_B.Sum[0]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((h_fileid > 22) || (h_fileid < 0)) {
    h_fileid = -1;
  }

  if (h_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[h_fileid - 3];
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
    fprintf(f, "%f\n", frac_4[1] + Spike_B.Sum[1]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((i_fileid > 22) || (i_fileid < 0)) {
    i_fileid = -1;
  }

  if (i_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[i_fileid - 3];
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
    fprintf(f, "%f\n", frac_4[2] + Spike_B.Sum[2]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((j_fileid > 22) || (j_fileid < 0)) {
    j_fileid = -1;
  }

  if (j_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[j_fileid - 3];
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
    fprintf(f, "%f\n", Spike_X.pqr_CSTATE[0]);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((k_fileid > 22) || (k_fileid < 0)) {
    k_fileid = -1;
  }

  if (k_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[k_fileid - 3];
    a = Spike_DW.eml_autoflush[k_fileid - 3];
  } else if (k_fileid == 0) {
    f = stdin;
    a = true;
  } else if (k_fileid == 1) {
    f = stdout;
    a = true;
  } else if (k_fileid == 2) {
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
  if ((l_fileid > 22) || (l_fileid < 0)) {
    l_fileid = -1;
  }

  if (l_fileid >= 3) {
    f = Spike_DW.eml_openfiles_j[l_fileid - 3];
    a = Spike_DW.eml_autoflush[l_fileid - 3];
  } else if (l_fileid == 0) {
    f = stdin;
    a = true;
  } else if (l_fileid == 1) {
    f = stdout;
    a = true;
  } else if (l_fileid == 2) {
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

  Spike_fclose_d();

  /* Fcn: '<S26>/phidot' incorporates:
   *  Fcn: '<S26>/psidot'
   *  Integrator: '<S1>/p,q,r '
   */
  Gain = Spike_X.pqr_CSTATE[1] * frac_tmp;

  /* SignalConversion: '<S17>/TmpSignal ConversionAtphi theta psiInport1' incorporates:
   *  Fcn: '<S26>/phidot'
   *  Fcn: '<S26>/psidot'
   *  Fcn: '<S26>/thetadot'
   *  Integrator: '<S1>/p,q,r '
   */
  Spike_B.TmpSignalConversionAtphithetaps[0] = (Gain + Spike_X.pqr_CSTATE[2] *
    rtb_Sum1_idx_2_tmp) * (frac_tmp_0 / rtb_Sum1_idx_1_tmp) +
    Spike_X.pqr_CSTATE[0];
  Spike_B.TmpSignalConversionAtphithetaps[1] = Spike_X.pqr_CSTATE[1] *
    rtb_Sum1_idx_2_tmp - Spike_X.pqr_CSTATE[2] * frac_tmp;
  Spike_B.TmpSignalConversionAtphithetaps[2] = (Gain + Spike_X.pqr_CSTATE[2] *
    rtb_Sum1_idx_2_tmp) / rtb_Sum1_idx_1_tmp;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    for (i = 0; i < 3; i++) {
      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       */
      rtb_VectorConcatenate[6 * i] = Spike_P.uDOFEulerAngles_inertia[3 * i];
      rtb_VectorConcatenate[3 + 6 * i] = Spike_P.Constant2_Value_f[3 * i];

      /* Selector: '<S18>/Selector' */
      Spike_B.Selector[3 * i] = rtb_VectorConcatenate[6 * i];

      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       */
      rtb_VectorConcatenate_tmp = 3 * i + 1;
      rtb_VectorConcatenate[1 + 6 * i] =
        Spike_P.uDOFEulerAngles_inertia[rtb_VectorConcatenate_tmp];
      rtb_VectorConcatenate[4 + 6 * i] =
        Spike_P.Constant2_Value_f[rtb_VectorConcatenate_tmp];

      /* Selector: '<S18>/Selector' */
      Spike_B.Selector[1 + 3 * i] = rtb_VectorConcatenate[6 * i + 1];

      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       */
      rtb_VectorConcatenate_tmp = 3 * i + 2;
      rtb_VectorConcatenate[2 + 6 * i] =
        Spike_P.uDOFEulerAngles_inertia[rtb_VectorConcatenate_tmp];
      rtb_VectorConcatenate[5 + 6 * i] =
        Spike_P.Constant2_Value_f[rtb_VectorConcatenate_tmp];

      /* Selector: '<S18>/Selector' */
      Spike_B.Selector[2 + 3 * i] = rtb_VectorConcatenate[6 * i + 2];
    }
  }

  /* Product: '<S29>/Product' incorporates:
   *  Integrator: '<S1>/p,q,r '
   */
  for (i = 0; i < 3; i++) {
    frac_3[i] = Spike_B.Selector[i + 6] * Spike_X.pqr_CSTATE[2] +
      (Spike_B.Selector[i + 3] * Spike_X.pqr_CSTATE[1] + Spike_B.Selector[i] *
       Spike_X.pqr_CSTATE[0]);
  }

  /* End of Product: '<S29>/Product' */

  /* Product: '<S31>/k x i' */
  Gain = frac_3[0];

  /* Product: '<S31>/i x j' */
  Airspeed_tmp = frac_3[1];

  /* Product: '<S32>/j x i' */
  rtb_Sum1_idx_1_tmp = frac_3[0];

  /* Sum: '<S28>/Sum' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  Product: '<S31>/i x j'
   *  Product: '<S31>/j x k'
   *  Product: '<S31>/k x i'
   *  Product: '<S32>/i x k'
   *  Product: '<S32>/j x i'
   *  Product: '<S32>/k x j'
   */
  frac_3[0] = Spike_X.pqr_CSTATE[1] * frac_3[2] - Spike_X.pqr_CSTATE[2] *
    frac_3[1];
  frac_3[1] = Spike_X.pqr_CSTATE[2] * Gain - Spike_X.pqr_CSTATE[0] * frac_3[2];
  frac_3[2] = Spike_X.pqr_CSTATE[0] * Airspeed_tmp - Spike_X.pqr_CSTATE[1] *
    rtb_Sum1_idx_1_tmp;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Selector: '<S18>/Selector1' */
    for (i = 0; i < 3; i++) {
      Spike_B.Selector1[3 * i] = rtb_VectorConcatenate[6 * i + 3];
      Spike_B.Selector1[1 + 3 * i] = rtb_VectorConcatenate[6 * i + 4];
      Spike_B.Selector1[2 + 3 * i] = rtb_VectorConcatenate[6 * i + 5];
    }

    /* End of Selector: '<S18>/Selector1' */
  }

  /* Interpolation_n-D: '<S2>/Xcp' */
  frac_7[0] = rtb_Gain;
  frac_7[1] = rtb_fm;
  frac_7[2] = rtb_fh;
  bpIndex_7[0] = rtb_idxa;
  bpIndex_7[1] = rtb_idxm;
  bpIndex_7[2] = rtb_idxh;
  rtb_Gain = intrp3d_s32dl_pw(bpIndex_7, frac_7, Spike_P.Xcp_Table,
    Spike_P.Xcp_dimSize);

  /* Gain: '<S2>/Gain' */
  rtb_Gain *= Spike_P.Gain_Gain_e;

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  frac_tmp_0 = Spike_P.AerodynamicForcesandMoments_b * rtb_referencearea;

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<S2>/zero1'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product3'
   *  Product: '<S96>/j x k'
   *  Product: '<S97>/k x j'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S92>/Sum'
   */
  frac_7[0] = ((0.0 - Spike_P.zero1_Value) * frac[1] - (0.0 -
    Spike_P.zero1_Value) * frac[2]) + frac_tmp_0 * rtb_Sum_d_idx_3;

  /* Product: '<S97>/i x k' incorporates:
   *  Constant: '<S2>/zero1'
   *  Product: '<S96>/i x j'
   *  Sum: '<S4>/Sum'
   */
  frac_tmp = (0.0 - Spike_P.zero1_Value) * frac[0];

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product3'
   *  Product: '<S96>/k x i'
   *  Product: '<S97>/i x k'
   *  Product: '<S97>/j x i'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S92>/Sum'
   */
  frac_7[1] = ((0.0 - rtb_Gain) * frac[2] - frac_tmp) +
    Spike_P.AerodynamicForcesandMoments_cba * rtb_referencearea *
    rtb_Sum_d_idx_4;
  frac_7[2] = (frac_tmp - (0.0 - rtb_Gain) * frac[1]) + frac_tmp_0 *
    rtb_Sum_d_idx_5;

  /* Trigonometry: '<S78>/Incidence' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   */
  rtb_sincos_o1_idx_0 = rt_atan2d_snf(Spike_X.ubvbwb_CSTATE[2],
    Spike_X.ubvbwb_CSTATE[0]);

  /* Trigonometry: '<S78>/Sideslip' */
  if (C_tmp > 1.0) {
    rtb_sincos_o2_idx_0 = 1.0;
  } else if (C_tmp < -1.0) {
    rtb_sincos_o2_idx_0 = -1.0;
  } else {
    rtb_sincos_o2_idx_0 = C_tmp;
  }

  /* SignalConversion: '<S77>/TmpSignal ConversionAtsincosInport1' incorporates:
   *  Trigonometry: '<S78>/Sideslip'
   */
  rtb_sincos_o1_idx_1 = std::asin(rtb_sincos_o2_idx_0);

  /* Trigonometry: '<S77>/sincos' incorporates:
   *  Trigonometry: '<S78>/Incidence'
   */
  rtb_sincos_o2_idx_0 = std::cos(rtb_sincos_o1_idx_0);
  rtb_sincos_o1_idx_0 = std::sin(rtb_sincos_o1_idx_0);
  rtb_sincos_o2_idx_1 = std::cos(rtb_sincos_o1_idx_1);
  Gain = std::sin(rtb_sincos_o1_idx_1);

  /* Product: '<S79>/u(3)*u(4)' */
  Spike_B.VectorConcatenate_i[0] = rtb_sincos_o2_idx_0 * rtb_sincos_o2_idx_1;

  /* UnaryMinus: '<S82>/Unary Minus' incorporates:
   *  Product: '<S82>/u(2)*u(3)'
   */
  Spike_B.VectorConcatenate_i[1] = -(Gain * rtb_sincos_o2_idx_0);

  /* UnaryMinus: '<S85>/Unary Minus' */
  Spike_B.VectorConcatenate_i[2] = -rtb_sincos_o1_idx_0;

  /* SignalConversion: '<S88>/ConcatBufferAtVector ConcatenateIn4' */
  Spike_B.VectorConcatenate_i[3] = Gain;

  /* SignalConversion: '<S88>/ConcatBufferAtVector ConcatenateIn5' */
  Spike_B.VectorConcatenate_i[4] = rtb_sincos_o2_idx_1;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Constant: '<S86>/Constant' */
    Spike_B.VectorConcatenate_i[5] = Spike_P.Constant_Value_l;
  }

  /* Product: '<S81>/u(1)*u(4)' */
  Spike_B.VectorConcatenate_i[6] = rtb_sincos_o1_idx_0 * rtb_sincos_o2_idx_1;

  /* UnaryMinus: '<S84>/Unary Minus' incorporates:
   *  Product: '<S84>/u(1)*u(2)'
   */
  Spike_B.VectorConcatenate_i[7] = -(rtb_sincos_o1_idx_0 * Gain);

  /* SignalConversion: '<S88>/ConcatBufferAtVector ConcatenateIn9' */
  Spike_B.VectorConcatenate_i[8] = rtb_sincos_o2_idx_0;

  /* Trigonometry: '<S48>/Incidence' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   */
  rtb_sincos_o1_idx_0 = rt_atan2d_snf(Spike_X.ubvbwb_CSTATE[2],
    Spike_X.ubvbwb_CSTATE[0]);

  /* Trigonometry: '<S48>/Sideslip' */
  if (C_tmp > 1.0) {
    C_tmp = 1.0;
  } else {
    if (C_tmp < -1.0) {
      C_tmp = -1.0;
    }
  }

  /* SignalConversion: '<S47>/TmpSignal ConversionAtsincosInport1' incorporates:
   *  Trigonometry: '<S48>/Sideslip'
   */
  rtb_sincos_o1_idx_1 = std::asin(C_tmp);

  /* Trigonometry: '<S47>/sincos' incorporates:
   *  Trigonometry: '<S48>/Incidence'
   */
  rtb_sincos_o2_idx_0 = std::cos(rtb_sincos_o1_idx_0);
  rtb_sincos_o1_idx_0 = std::sin(rtb_sincos_o1_idx_0);
  rtb_sincos_o2_idx_1 = std::cos(rtb_sincos_o1_idx_1);
  Gain = std::sin(rtb_sincos_o1_idx_1);

  /* Product: '<S49>/u(3)*u(4)' */
  Spike_B.VectorConcatenate_m[0] = rtb_sincos_o2_idx_0 * rtb_sincos_o2_idx_1;

  /* UnaryMinus: '<S52>/Unary Minus' incorporates:
   *  Product: '<S52>/u(2)*u(3)'
   */
  Spike_B.VectorConcatenate_m[1] = -(Gain * rtb_sincos_o2_idx_0);

  /* UnaryMinus: '<S55>/Unary Minus' */
  Spike_B.VectorConcatenate_m[2] = -rtb_sincos_o1_idx_0;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn4' */
  Spike_B.VectorConcatenate_m[3] = Gain;

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn5' */
  Spike_B.VectorConcatenate_m[4] = rtb_sincos_o2_idx_1;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Constant: '<S56>/Constant' */
    Spike_B.VectorConcatenate_m[5] = Spike_P.Constant_Value_e;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<Root>/zero3'
     */
    Spike_B.Sum_j[0] = Spike_P.zero3_Value[0] - Spike_P.zero3_Value[0];
    Spike_B.Sum_j[1] = Spike_P.zero3_Value[1] - Spike_P.zero3_Value[1];
    Spike_B.Sum_j[2] = Spike_P.zero3_Value[2] - Spike_P.zero3_Value[2];
  }

  /* Product: '<S51>/u(1)*u(4)' */
  Spike_B.VectorConcatenate_m[6] = rtb_sincos_o1_idx_0 * rtb_sincos_o2_idx_1;

  /* UnaryMinus: '<S54>/Unary Minus' incorporates:
   *  Product: '<S54>/u(1)*u(2)'
   */
  Spike_B.VectorConcatenate_m[7] = -(rtb_sincos_o1_idx_0 * Gain);

  /* SignalConversion: '<S58>/ConcatBufferAtVector ConcatenateIn9' */
  Spike_B.VectorConcatenate_m[8] = rtb_sincos_o2_idx_0;

  /* Product: '<S42>/Product' */
  for (i = 0; i < 3; i++) {
    frac[i] = Spike_B.VectorConcatenate_m[i + 6] * Spike_B.Sum_j[2] +
      (Spike_B.VectorConcatenate_m[i + 3] * Spike_B.Sum_j[1] +
       Spike_B.VectorConcatenate_m[i] * Spike_B.Sum_j[0]);
  }

  /* End of Product: '<S42>/Product' */

  /* Sum: '<S41>/Sum' incorporates:
   *  Product: '<S45>/i x j'
   *  Product: '<S46>/i x k'
   *  Product: '<S46>/j x i'
   */
  rtb_referencearea = rtb_ixk * frac[1];
  rtb_fh = rtb_ixk * frac[2];
  rtb_fm = rtb_jxi * frac[0];

  /* Interpolation_n-D: '<Root>/Clb' */
  frac_8[0] = C_0;
  frac_8[1] = rtb_fm_n;
  frac_8[2] = C;
  bpIndex_8[0] = idx;
  bpIndex_8[1] = rtb_idxm_h;
  bpIndex_8[2] = nx;
  rtb_ixk = intrp3d_s32dl_pw(bpIndex_8, frac_8, Spike_P.Clb_Table,
    Spike_P.Clb_dimSize);

  /* Product: '<Root>/Product1' */
  rtb_ixk *= rtb_Sideslip_c;

  /* Interpolation_n-D: '<Root>/Cm' */
  frac_9[0] = C_0;
  frac_9[1] = rtb_fm_n;
  frac_9[2] = C;
  bpIndex_9[0] = idx;
  bpIndex_9[1] = rtb_idxm_h;
  bpIndex_9[2] = nx;
  Gain = intrp3d_s32dl_pw(bpIndex_9, frac_9, Spike_P.Cm_Table,
    Spike_P.Cm_dimSize);

  /* Interpolation_n-D: '<Root>/Cnb' */
  frac_a[0] = C_0;
  frac_a[1] = rtb_fm_n;
  frac_a[2] = C;
  bpIndex_a[0] = idx;
  bpIndex_a[1] = rtb_idxm_h;
  bpIndex_a[2] = nx;
  C_0 = intrp3d_s32dl_pw(bpIndex_a, frac_a, Spike_P.Cnb_Table,
    Spike_P.Cnb_dimSize);

  /* Product: '<Root>/Product3' */
  C_0 *= rtb_Sideslip_c;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_fm_n = Spike_P.AerodynamicForcesandMoments_b_h * rtb_referencearea_k;

  /* Sum: '<S41>/Sum' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product3'
   *  Product: '<S45>/j x k'
   *  Product: '<S45>/k x i'
   *  Product: '<S46>/k x j'
   *  Sum: '<S3>/Sum1'
   */
  rtb_ixk = (rtb_jxi * frac[2] - rtb_kxj * frac[1]) + rtb_fm_n * rtb_ixk;
  rtb_jxi = (rtb_kxj * frac[0] - rtb_fh) +
    Spike_P.AerodynamicForcesandMoments_c_h * rtb_referencearea_k * Gain;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Product: '<S3>/Product3'
   *  Sum: '<S41>/Sum'
   */
  rtb_referencearea_k = rtb_fm_n * C_0 + (rtb_referencearea - rtb_fm);

  /* Product: '<S44>/Product' incorporates:
   *  Math: '<S44>/Transpose'
   */
  for (i = 0; i < 3; i++) {
    frac[i] = Spike_B.VectorConcatenate_i[3 * i + 2] * rtb_referencearea_k +
      (Spike_B.VectorConcatenate_i[3 * i + 1] * rtb_jxi +
       Spike_B.VectorConcatenate_i[3 * i] * rtb_ixk);
  }

  /* End of Product: '<S44>/Product' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Integrator: '<S1>/p,q,r '
   *  Product: '<S30>/Product'
   *  Sum: '<S18>/Sum2'
   */
  frac_2[0] = frac[0];
  frac_2[1] = Spike_P.Gain2_Gain * frac[1];
  frac_2[2] = frac[2];
  for (i = 0; i < 3; i++) {
    frac_7[i] = ((frac_7[i] + frac_2[i]) - (Spike_B.Selector1[i + 6] *
      Spike_X.pqr_CSTATE[2] + (Spike_B.Selector1[i + 3] * Spike_X.pqr_CSTATE[1]
      + Spike_B.Selector1[i] * Spike_X.pqr_CSTATE[0]))) - frac_3[i];
  }

  /* End of Sum: '<Root>/Add1' */
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Selector: '<S18>/Selector2' */
    for (i = 0; i < 3; i++) {
      Spike_B.Selector2[3 * i] = rtb_VectorConcatenate[6 * i];
      Spike_B.Selector2[1 + 3 * i] = rtb_VectorConcatenate[6 * i + 1];
      Spike_B.Selector2[2 + 3 * i] = rtb_VectorConcatenate[6 * i + 2];
    }

    /* End of Selector: '<S18>/Selector2' */
  }

  /* Product: '<S18>/Product2' */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(frac_7, Spike_B.Selector2, Spike_B.Product2);

  /* Product: '<S24>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Math: '<S1>/Transpose'
   */
  for (i = 0; i < 3; i++) {
    Spike_B.Product[i] = 0.0;
    Spike_B.Product[i] += VectorConcatenate[3 * i] * Spike_X.ubvbwb_CSTATE[0];
    Spike_B.Product[i] += VectorConcatenate[3 * i + 1] * Spike_X.ubvbwb_CSTATE[1];
    Spike_B.Product[i] += VectorConcatenate[3 * i + 2] * Spike_X.ubvbwb_CSTATE[2];
  }

  /* End of Product: '<S24>/Product' */
  if (rtmIsMajorTimeStep((&Spike_M))) {
    rt_ertODEUpdateContinuousStates(&(&Spike_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&Spike_M)->Timing.clockTick0)) {
      ++(&Spike_M)->Timing.clockTickH0;
    }

    (&Spike_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&Spike_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.02s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.02, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&Spike_M)->Timing.clockTick1++;
      if (!(&Spike_M)->Timing.clockTick1) {
        (&Spike_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SpikeModelClass::Spike_derivatives()
{
  XDot_Spike_T *_rtXdot;
  _rtXdot = ((XDot_Spike_T *) (&Spike_M)->derivs);

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[0] = Spike_B.Sum[0];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[0] = Spike_B.Product[0];

  /* Derivatives for Integrator: '<S17>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[0] = Spike_B.TmpSignalConversionAtphithetaps[0];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[0] = Spike_B.Product2[0];

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[1] = Spike_B.Sum[1];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[1] = Spike_B.Product[1];

  /* Derivatives for Integrator: '<S17>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[1] = Spike_B.TmpSignalConversionAtphithetaps[1];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[1] = Spike_B.Product2[1];

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[2] = Spike_B.Sum[2];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[2] = Spike_B.Product[2];

  /* Derivatives for Integrator: '<S17>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[2] = Spike_B.TmpSignalConversionAtphithetaps[2];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[2] = Spike_B.Product2[2];
}

/* Model initialize function */
void SpikeModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)(&Spike_M), 0,
                sizeof(RT_MODEL_Spike_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Spike_M)->solverInfo, &(&Spike_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&Spike_M)->solverInfo, &rtmGetTPtr((&Spike_M)));
    rtsiSetStepSizePtr(&(&Spike_M)->solverInfo, &(&Spike_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Spike_M)->solverInfo, &(&Spike_M)->derivs);
    rtsiSetContStatesPtr(&(&Spike_M)->solverInfo, (real_T **) &(&Spike_M)
                         ->contStates);
    rtsiSetNumContStatesPtr(&(&Spike_M)->solverInfo, &(&Spike_M)
      ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Spike_M)->solverInfo, &(&Spike_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Spike_M)->solverInfo, &(&Spike_M)
      ->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Spike_M)->solverInfo, &(&Spike_M)
      ->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Spike_M)->solverInfo, (&rtmGetErrorStatus((&Spike_M))));
    rtsiSetRTModelPtr(&(&Spike_M)->solverInfo, (&Spike_M));
  }

  rtsiSetSimTimeStep(&(&Spike_M)->solverInfo, MAJOR_TIME_STEP);
  (&Spike_M)->intgData.y = (&Spike_M)->odeY;
  (&Spike_M)->intgData.f[0] = (&Spike_M)->odeF[0];
  (&Spike_M)->intgData.f[1] = (&Spike_M)->odeF[1];
  (&Spike_M)->intgData.f[2] = (&Spike_M)->odeF[2];
  getRTM()->contStates = ((X_Spike_T *) &Spike_X);
  getRTM()->periodicContStateIndices = ((int_T*) Spike_PeriodicIndX);
  getRTM()->periodicContStateRanges = ((real_T*) Spike_PeriodicRngX);
  rtsiSetSolverData(&(&Spike_M)->solverInfo, (void *)&(&Spike_M)->intgData);
  rtsiSetSolverName(&(&Spike_M)->solverInfo,"ode3");
  rtmSetTPtr(getRTM(), &(&Spike_M)->Timing.tArray[0]);
  (&Spike_M)->Timing.stepSize0 = 0.02;

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

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Spike_X.xeyeze_CSTATE[0] = Spike_P.uDOFEulerAngles_xme_0[0];

    /* InitializeConditions for Integrator: '<S17>/phi theta psi' */
    Spike_X.phithetapsi_CSTATE[0] = Spike_P.uDOFEulerAngles_eul_0[0];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Spike_X.pqr_CSTATE[0] = Spike_P.uDOFEulerAngles_pm_0[0];

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Spike_X.ubvbwb_CSTATE[1] = Spike_P.uDOFEulerAngles_Vm_0[1];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Spike_X.xeyeze_CSTATE[1] = Spike_P.uDOFEulerAngles_xme_0[1];

    /* InitializeConditions for Integrator: '<S17>/phi theta psi' */
    Spike_X.phithetapsi_CSTATE[1] = Spike_P.uDOFEulerAngles_eul_0[1];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Spike_X.pqr_CSTATE[1] = Spike_P.uDOFEulerAngles_pm_0[1];

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Spike_X.ubvbwb_CSTATE[2] = Spike_P.uDOFEulerAngles_Vm_0[2];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Spike_X.xeyeze_CSTATE[2] = Spike_P.uDOFEulerAngles_xme_0[2];

    /* InitializeConditions for Integrator: '<S17>/phi theta psi' */
    Spike_X.phithetapsi_CSTATE[2] = Spike_P.uDOFEulerAngles_eul_0[2];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Spike_X.pqr_CSTATE[2] = Spike_P.uDOFEulerAngles_pm_0[2];

    /* SystemInitialize for MATLAB Function: '<Root>/Read Aileron' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Aileron' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Tail right' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_p[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Tail right' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Tail left' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_k[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Tail left' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_b[i] = a;

      /* SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */
      Spike_DW.eml_autoflush[i] = false;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */

    /* SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_j[i] = a;
    }

    /* InitializeConditions for root-level periodic continuous states */
    {
      int_T rootPeriodicContStateIndices[3] = { 6, 7, 8 };

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
void SpikeModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
SpikeModelClass::SpikeModelClass()
{
  static const P_Spike_T Spike_P_temp = {
    16.2,
    16.2,

    { 50.0, 0.0, 0.0 },
    10.8,
    10.8,
    1.32,
    1.32,

    { 0.0, 0.0, 0.0 },

    { 1541.0, 0.0, 0.0, 0.0, 1898.0, 0.0, 0.0, 0.0, 3199.0 },
    800.0,

    { 0.0, 0.0, 0.0 },

    { 0.0, 0.0, 150.0 },
    -1.0,
    3.1415926535897931,
    -3.1415926535897931,
    1.2754,
    0.5,
    0.0,

    { -15.0, -10.0, -5.0, -2.5, 0.0, 2.5, 5.0, 10.0, 15.0 },
    343.0,

    { 0.02, 0.16, 0.3 },

    { 50.0, 150.0, 250.0 },

    { -0.076081, -0.051903, -0.025952, -0.012976, 0.0, 0.012976, 0.025952,
      0.051903, 0.076081, -0.076748, -0.052358, -0.026179, -0.01309, 0.0,
      0.01309, 0.026179, 0.052358, 0.076748, -0.07695, -0.052496, -0.026248,
      -0.013124, 0.0, 0.013124, 0.026248, 0.052496, 0.07695, -0.076078,
      -0.051901, -0.025951, -0.012975, 0.0, 0.012975, 0.025951, 0.051901,
      0.076078, -0.076745, -0.052356, -0.026178, -0.013089, 0.0, 0.013089,
      0.026178, 0.052356, 0.076745, -0.076947, -0.052494, -0.026247, -0.013124,
      0.0, 0.013124, 0.026247, 0.052494, 0.076947, -0.076075, -0.0519, -0.02595,
      -0.012975, 0.0, 0.012975, 0.02595, 0.0519, 0.076075, -0.076742, -0.052354,
      -0.026177, -0.013089, 0.0, 0.013089, 0.026177, 0.052354, 0.076742,
      -0.076944, -0.052492, -0.026246, -0.013123, 0.0, 0.013123, 0.026246,
      0.052492, 0.076944 },

    { -16.0, -12.0, -8.0, -4.0, -2.0, 0.0, 2.0, 4.0, 8.0, 12.0, 16.0, 20.0 },

    { -0.009808, -0.006878, -0.003949, -0.0012, 7.673E-5, 0.001363, 0.00272,
      0.004135, 0.007089, 0.01001, 0.0119, 0.01238, -0.006691, -0.004692,
      -0.002694, -0.0008185, 5.234E-5, 0.00093, 0.001856, 0.002821, 0.004836,
      0.006826, 0.008115, 0.008448, -0.003345, -0.002346, -0.001347, -0.0004092,
      2.617E-5, 0.000465, 0.0009278, 0.001411, 0.002418, 0.003413, 0.004058,
      0.004224, -0.001673, -0.001173, -0.0006735, -0.0002046, 1.309E-5,
      0.0002325, 0.0004639, 0.0007053, 0.001209, 0.001706, 0.002029, 0.002112,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001673,
      0.001173, 0.0006735, 0.0002046, -1.309E-5, -0.0002325, -0.0004639,
      -0.0007053, -0.001209, -0.001706, -0.002029, -0.002112, 0.003345, 0.002346,
      0.001347, 0.0004092, -2.617E-5, -0.000465, -0.0009278, -0.001411,
      -0.002418, -0.003413, -0.004058, -0.004224, 0.006691, 0.004692, 0.002694,
      0.0008185, -5.234E-5, -0.00093, -0.001856, -0.002821, -0.004836, -0.006826,
      -0.008115, -0.008448, 0.009808, 0.006878, 0.003949, 0.0012, -7.673E-5,
      -0.001363, -0.00272, -0.004135, -0.007089, -0.01001, -0.0119, -0.01238,
      -0.009928, -0.006976, -0.004008, -0.001218, 7.794E-5, 0.001384, 0.002761,
      0.004196, 0.00719, 0.01013, 0.01203, 0.01242, -0.006773, -0.004759,
      -0.002734, -0.0008311, 5.317E-5, 0.0009443, 0.001884, 0.002863, 0.004905,
      0.006909, 0.008204, 0.008476, -0.003386, -0.00238, -0.001367, -0.0004156,
      2.658E-5, 0.0004722, 0.0009418, 0.001431, 0.002453, 0.003454, 0.004102,
      0.004238, -0.001693, -0.00119, -0.0006835, -0.0002078, 1.329E-5, 0.0002361,
      0.0004709, 0.0007157, 0.001226, 0.001727, 0.002051, 0.002119, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001693, 0.00119,
      0.0006835, 0.0002078, -1.329E-5, -0.0002361, -0.0004709, -0.0007157,
      -0.001226, -0.001727, -0.002051, -0.002119, 0.003386, 0.00238, 0.001367,
      0.0004156, -2.658E-5, -0.0004722, -0.0009418, -0.001431, -0.002453,
      -0.003454, -0.004102, -0.004238, 0.006773, 0.004759, 0.002734, 0.0008311,
      -5.317E-5, -0.0009443, -0.001884, -0.002863, -0.004905, -0.006909,
      -0.008204, -0.008476, 0.009928, 0.006976, 0.004008, 0.001218, -7.794E-5,
      -0.001384, -0.002761, -0.004196, -0.00719, -0.01013, -0.01203, -0.01242,
      -0.00947, -0.00698, -0.004045, -0.001241, 7.977E-5, 0.00141, 0.002798,
      0.004233, 0.007191, 0.009641, 0.01098, 0.006949, -0.006461, -0.004762,
      -0.002759, -0.0008468, 5.442E-5, 0.0009616, 0.001909, 0.002888, 0.004906,
      0.006577, 0.00749, 0.004741, -0.00323, -0.002381, -0.00138, -0.0004234,
      2.721E-5, 0.0004808, 0.0009544, 0.001444, 0.002453, 0.003288, 0.003745,
      0.00237, -0.001615, -0.001191, -0.0006899, -0.0002117, 1.36E-5, 0.0002404,
      0.0004772, 0.0007219, 0.001226, 0.001644, 0.001872, 0.001185, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001615, 0.001191,
      0.0006899, 0.0002117, -1.36E-5, -0.0002404, -0.0004772, -0.0007219,
      -0.001226, -0.001644, -0.001872, -0.001185, 0.00323, 0.002381, 0.00138,
      0.0004234, -2.721E-5, -0.0004808, -0.0009544, -0.001444, -0.002453,
      -0.003288, -0.003745, -0.00237, 0.006461, 0.004762, 0.002759, 0.0008468,
      -5.442E-5, -0.0009616, -0.001909, -0.002888, -0.004906, -0.006577,
      -0.00749, -0.004741, 0.00947, 0.00698, 0.004045, 0.001241, -7.977E-5,
      -0.00141, -0.002798, -0.004233, -0.007191, -0.009641, -0.01098, -0.006949,
      -0.009807, -0.006878, -0.003949, -0.0012, 7.672E-5, 0.001363, 0.00272,
      0.004135, 0.007089, 0.01001, 0.0119, 0.01238, -0.00669, -0.004692,
      -0.002694, -0.0008184, 5.234E-5, 0.0009299, 0.001856, 0.002821, 0.004836,
      0.006826, 0.008115, 0.008448, -0.003345, -0.002346, -0.001347, -0.0004092,
      2.617E-5, 0.000465, 0.0009278, 0.00141, 0.002418, 0.003413, 0.004057,
      0.004224, -0.001673, -0.001173, -0.0006735, -0.0002046, 1.309E-5,
      0.0002325, 0.0004639, 0.0007052, 0.001209, 0.001706, 0.002029, 0.002112,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001673,
      0.001173, 0.0006735, 0.0002046, -1.309E-5, -0.0002325, -0.0004639,
      -0.0007052, -0.001209, -0.001706, -0.002029, -0.002112, 0.003345, 0.002346,
      0.001347, 0.0004092, -2.617E-5, -0.000465, -0.0009278, -0.00141, -0.002418,
      -0.003413, -0.004057, -0.004224, 0.00669, 0.004692, 0.002694, 0.0008184,
      -5.234E-5, -0.0009299, -0.001856, -0.002821, -0.004836, -0.006826,
      -0.008115, -0.008448, 0.009807, 0.006878, 0.003949, 0.0012, -7.672E-5,
      -0.001363, -0.00272, -0.004135, -0.007089, -0.01001, -0.0119, -0.01238,
      -0.009927, -0.006976, -0.004008, -0.001218, 7.793E-5, 0.001384, 0.002761,
      0.004196, 0.00719, 0.01013, 0.01203, 0.01242, -0.006772, -0.004759,
      -0.002734, -0.0008311, 5.317E-5, 0.0009443, 0.001884, 0.002863, 0.004905,
      0.006909, 0.008204, 0.008476, -0.003386, -0.002379, -0.001367, -0.0004156,
      2.658E-5, 0.0004721, 0.0009418, 0.001431, 0.002452, 0.003454, 0.004102,
      0.004238, -0.001693, -0.00119, -0.0006835, -0.0002078, 1.329E-5, 0.0002361,
      0.0004709, 0.0007157, 0.001226, 0.001727, 0.002051, 0.002119, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001693, 0.00119,
      0.0006835, 0.0002078, -1.329E-5, -0.0002361, -0.0004709, -0.0007157,
      -0.001226, -0.001727, -0.002051, -0.002119, 0.003386, 0.002379, 0.001367,
      0.0004156, -2.658E-5, -0.0004721, -0.0009418, -0.001431, -0.002452,
      -0.003454, -0.004102, -0.004238, 0.006772, 0.004759, 0.002734, 0.0008311,
      -5.317E-5, -0.0009443, -0.001884, -0.002863, -0.004905, -0.006909,
      -0.008204, -0.008476, 0.009927, 0.006976, 0.004008, 0.001218, -7.793E-5,
      -0.001384, -0.002761, -0.004196, -0.00719, -0.01013, -0.01203, -0.01242,
      -0.00947, -0.00698, -0.004045, -0.001241, 7.976E-5, 0.001409, 0.002798,
      0.004233, 0.007191, 0.00964, 0.01098, 0.006949, -0.00646, -0.004762,
      -0.002759, -0.0008468, 5.441E-5, 0.0009615, 0.001909, 0.002888, 0.004906,
      0.006577, 0.007489, 0.00474, -0.00323, -0.002381, -0.00138, -0.0004234,
      2.721E-5, 0.0004808, 0.0009543, 0.001444, 0.002453, 0.003288, 0.003745,
      0.00237, -0.001615, -0.00119, -0.0006898, -0.0002117, 1.36E-5, 0.0002404,
      0.0004772, 0.0007219, 0.001226, 0.001644, 0.001872, 0.001185, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001615, 0.00119,
      0.0006898, 0.0002117, -1.36E-5, -0.0002404, -0.0004772, -0.0007219,
      -0.001226, -0.001644, -0.001872, -0.001185, 0.00323, 0.002381, 0.00138,
      0.0004234, -2.721E-5, -0.0004808, -0.0009543, -0.001444, -0.002453,
      -0.003288, -0.003745, -0.00237, 0.00646, 0.004762, 0.002759, 0.0008468,
      -5.441E-5, -0.0009615, -0.001909, -0.002888, -0.004906, -0.006577,
      -0.007489, -0.00474, 0.00947, 0.00698, 0.004045, 0.001241, -7.976E-5,
      -0.001409, -0.002798, -0.004233, -0.007191, -0.00964, -0.01098, -0.006949,
      -0.009807, -0.006878, -0.003949, -0.0012, 7.672E-5, 0.001363, 0.00272,
      0.004135, 0.007089, 0.01, 0.01189, 0.01238, -0.00669, -0.004692, -0.002694,
      -0.0008184, 5.234E-5, 0.0009299, 0.001855, 0.002821, 0.004836, 0.006825,
      0.008114, 0.008448, -0.003345, -0.002346, -0.001347, -0.0004092, 2.617E-5,
      0.000465, 0.0009277, 0.00141, 0.002418, 0.003413, 0.004057, 0.004224,
      -0.001673, -0.001173, -0.0006735, -0.0002046, 1.308E-5, 0.0002325,
      0.0004639, 0.0007052, 0.001209, 0.001706, 0.002029, 0.002112, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001673, 0.001173,
      0.0006735, 0.0002046, -1.308E-5, -0.0002325, -0.0004639, -0.0007052,
      -0.001209, -0.001706, -0.002029, -0.002112, 0.003345, 0.002346, 0.001347,
      0.0004092, -2.617E-5, -0.000465, -0.0009277, -0.00141, -0.002418,
      -0.003413, -0.004057, -0.004224, 0.00669, 0.004692, 0.002694, 0.0008184,
      -5.234E-5, -0.0009299, -0.001855, -0.002821, -0.004836, -0.006825,
      -0.008114, -0.008448, 0.009807, 0.006878, 0.003949, 0.0012, -7.672E-5,
      -0.001363, -0.00272, -0.004135, -0.007089, -0.01, -0.01189, -0.01238,
      -0.009927, -0.006976, -0.004007, -0.001218, 7.793E-5, 0.001384, 0.002761,
      0.004196, 0.00719, 0.01013, 0.01202, 0.01242, -0.006772, -0.004759,
      -0.002734, -0.0008311, 5.316E-5, 0.0009443, 0.001883, 0.002863, 0.004905,
      0.006908, 0.008203, 0.008475, -0.003386, -0.002379, -0.001367, -0.0004155,
      2.658E-5, 0.0004721, 0.0009417, 0.001431, 0.002452, 0.003454, 0.004102,
      0.004238, -0.001693, -0.00119, -0.0006835, -0.0002078, 1.329E-5, 0.0002361,
      0.0004709, 0.0007156, 0.001226, 0.001727, 0.002051, 0.002119, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001693, 0.00119,
      0.0006835, 0.0002078, -1.329E-5, -0.0002361, -0.0004709, -0.0007156,
      -0.001226, -0.001727, -0.002051, -0.002119, 0.003386, 0.002379, 0.001367,
      0.0004155, -2.658E-5, -0.0004721, -0.0009417, -0.001431, -0.002452,
      -0.003454, -0.004102, -0.004238, 0.006772, 0.004759, 0.002734, 0.0008311,
      -5.316E-5, -0.0009443, -0.001883, -0.002863, -0.004905, -0.006908,
      -0.008203, -0.008475, 0.009927, 0.006976, 0.004007, 0.001218, -7.793E-5,
      -0.001384, -0.002761, -0.004196, -0.00719, -0.01013, -0.01202, -0.01242,
      -0.00947, -0.00698, -0.004045, -0.001241, 7.976E-5, 0.001409, 0.002798,
      0.004233, 0.007191, 0.00964, 0.01098, 0.006949, -0.00646, -0.004762,
      -0.002759, -0.0008468, 5.441E-5, 0.0009615, 0.001909, 0.002887, 0.004905,
      0.006576, 0.007489, 0.00474, -0.00323, -0.002381, -0.00138, -0.0004234,
      2.721E-5, 0.0004807, 0.0009543, 0.001444, 0.002453, 0.003288, 0.003745,
      0.00237, -0.001615, -0.00119, -0.0006898, -0.0002117, 1.36E-5, 0.0002404,
      0.0004772, 0.0007219, 0.001226, 0.001644, 0.001872, 0.001185, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001615, 0.00119,
      0.0006898, 0.0002117, -1.36E-5, -0.0002404, -0.0004772, -0.0007219,
      -0.001226, -0.001644, -0.001872, -0.001185, 0.00323, 0.002381, 0.00138,
      0.0004234, -2.721E-5, -0.0004807, -0.0009543, -0.001444, -0.002453,
      -0.003288, -0.003745, -0.00237, 0.00646, 0.004762, 0.002759, 0.0008468,
      -5.441E-5, -0.0009615, -0.001909, -0.002887, -0.004905, -0.006576,
      -0.007489, -0.00474, 0.00947, 0.00698, 0.004045, 0.001241, -7.976E-5,
      -0.001409, -0.002798, -0.004233, -0.007191, -0.00964, -0.01098, -0.006949
    },
    -1.0,

    { -25.0, -16.0, -8.0, 0.0, 8.0, 16.0, 25.0 },

    { 0.017, 0.0148, 0.0125, 0.00992, 0.00856, 0.00718, 0.00578, 0.00439,
      0.00154, -0.00153, -0.00522, -0.00976, 0.0187, 0.0163, 0.0138, 0.0111,
      0.00961, 0.00814, 0.00665, 0.00516, 0.00211, -0.00119, -0.00515, -0.0101,
      0.0192, 0.0165, 0.0139, 0.0112, 0.00969, 0.0082, 0.0067, 0.00518, 0.00203,
      -0.00156, -0.00602, -0.0129, 0.017, 0.0148, 0.0124, 0.00991, 0.00855,
      0.00717, 0.00578, 0.00439, 0.00153, -0.00154, -0.00522, -0.00976, 0.0186,
      0.0162, 0.0138, 0.0111, 0.0096, 0.00813, 0.00664, 0.00515, 0.0021,
      -0.00119, -0.00515, -0.0101, 0.0192, 0.0165, 0.0139, 0.0112, 0.00968,
      0.00819, 0.00669, 0.00517, 0.00202, -0.00156, -0.00602, -0.0129, 0.017,
      0.0147, 0.0124, 0.0099, 0.00854, 0.00716, 0.00577, 0.00438, 0.00153,
      -0.00154, -0.00522, -0.00975, 0.0186, 0.0162, 0.0138, 0.011, 0.00959,
      0.00812, 0.00663, 0.00515, 0.0021, -0.00119, -0.00516, -0.0101, 0.0192,
      0.0164, 0.0139, 0.0111, 0.00967, 0.00818, 0.00668, 0.00516, 0.00202,
      -0.00156, -0.00602, -0.0129, 0.0155, 0.0134, 0.0112, 0.00887, 0.00759,
      0.0063, 0.005, 0.0037, 0.00103, -0.00184, -0.0053, -0.00954, 0.017, 0.0147,
      0.0124, 0.00989, 0.00852, 0.00714, 0.00575, 0.00436, 0.00151, -0.00158,
      -0.00529, -0.00987, 0.0175, 0.0149, 0.0126, 0.00997, 0.0086, 0.0072,
      0.00579, 0.00437, 0.00143, -0.00192, -0.0061, -0.0125, 0.0155, 0.0134,
      0.0112, 0.00886, 0.00758, 0.00629, 0.00499, 0.00369, 0.00103, -0.00185,
      -0.00529, -0.00953, 0.017, 0.0147, 0.0124, 0.00988, 0.00851, 0.00713,
      0.00574, 0.00435, 0.0015, -0.00158, -0.00529, -0.00987, 0.0175, 0.0149,
      0.0125, 0.00996, 0.00859, 0.00719, 0.00579, 0.00437, 0.00142, -0.00193,
      -0.0061, -0.0125, 0.0155, 0.0134, 0.0112, 0.00885, 0.00757, 0.00628,
      0.00499, 0.00369, 0.00102, -0.00185, -0.00529, -0.00953, 0.0169, 0.0147,
      0.0124, 0.00986, 0.0085, 0.00713, 0.00574, 0.00435, 0.0015, -0.00158,
      -0.00529, -0.00986, 0.0175, 0.0149, 0.0125, 0.00995, 0.00858, 0.00719,
      0.00578, 0.00436, 0.00142, -0.00193, -0.0061, -0.0125, 0.00691, 0.00578,
      0.00461, 0.00332, 0.00264, 0.00194, 0.00123, 0.00053, -0.000913, -0.00247,
      -0.00433, -0.00662, 0.00751, 0.0063, 0.00505, 0.00367, 0.00294, 0.00219,
      0.00144, 0.000687, -0.000856, -0.00252, -0.00453, -0.00701, 0.00778,
      0.00639, 0.0051, 0.00371, 0.00297, 0.00221, 0.00145, 0.000684, -0.000908,
      -0.00272, -0.00498, -0.00844, 0.0069, 0.00577, 0.0046, 0.00332, 0.00263,
      0.00193, 0.00123, 0.000529, -0.000913, -0.00246, -0.00433, -0.00662,
      0.0075, 0.00629, 0.00504, 0.00367, 0.00293, 0.00219, 0.00144, 0.000686,
      -0.000857, -0.00252, -0.00453, -0.007, 0.00777, 0.00639, 0.0051, 0.00371,
      0.00296, 0.00221, 0.00145, 0.000683, -0.000908, -0.00272, -0.00498,
      -0.00844, 0.00689, 0.00577, 0.0046, 0.00332, 0.00263, 0.00193, 0.00123,
      0.000527, -0.000913, -0.00246, -0.00433, -0.00662, 0.00749, 0.00629,
      0.00504, 0.00367, 0.00293, 0.00219, 0.00144, 0.000684, -0.000857, -0.00252,
      -0.00452, -0.007, 0.00777, 0.00638, 0.0051, 0.0037, 0.00296, 0.00221,
      0.00145, 0.000681, -0.000908, -0.00272, -0.00497, -0.00843, -6.47E-6,
      -5.06E-6, -3.6E-6, -1.99E-6, -1.13E-6, -2.58E-7, 6.21E-7, 1.5E-6, 3.3E-6,
      5.24E-6, 7.57E-6, 1.04E-5, -6.92E-6, -5.41E-6, -3.85E-6, -2.13E-6,
      -1.21E-6, -2.8E-7, 6.6E-7, 1.6E-6, 3.53E-6, 5.61E-6, 8.12E-6, 1.12E-5,
      -7.25E-6, -5.52E-6, -3.91E-6, -2.16E-6, -1.24E-6, -2.93E-7, 6.6E-7,
      1.62E-6, 3.61E-6, 5.87E-6, 8.7E-6, 1.3E-5, -6.47E-6, -5.06E-6, -3.6E-6,
      -1.99E-6, -1.13E-6, -2.58E-7, 6.21E-7, 1.5E-6, 3.3E-6, 5.24E-6, 7.57E-6,
      1.04E-5, -6.92E-6, -5.41E-6, -3.84E-6, -2.13E-6, -1.21E-6, -2.8E-7,
      6.59E-7, 1.6E-6, 3.53E-6, 5.61E-6, 8.11E-6, 1.12E-5, -7.24E-6, -5.51E-6,
      -3.9E-6, -2.16E-6, -1.23E-6, -2.93E-7, 6.59E-7, 1.62E-6, 3.61E-6, 5.87E-6,
      8.69E-6, 1.3E-5, -6.46E-6, -5.05E-6, -3.59E-6, -1.99E-6, -1.13E-6,
      -2.57E-7, 6.2E-7, 1.5E-6, 3.3E-6, 5.24E-6, 7.56E-6, 1.04E-5, -6.91E-6,
      -5.4E-6, -3.84E-6, -2.13E-6, -1.21E-6, -2.79E-7, 6.59E-7, 1.6E-6, 3.52E-6,
      5.6E-6, 8.11E-6, 1.12E-5, -7.24E-6, -5.51E-6, -3.9E-6, -2.16E-6, -1.23E-6,
      -2.93E-7, 6.59E-7, 1.62E-6, 3.6E-6, 5.86E-6, 8.68E-6, 1.3E-5, -0.00345,
      -0.00232, -0.00115, 0.000132, 0.000821, 0.00152, 0.00222, 0.00293, 0.00437,
      0.00592, 0.00779, 0.0101, -0.00358, -0.00237, -0.00112, 0.000255, 0.000992,
      0.00174, 0.00249, 0.00324, 0.00479, 0.00645, 0.00846, 0.0109, -0.00383,
      -0.00244, -0.00115, 0.000242, 0.000985, 0.00174, 0.0025, 0.00327, 0.00486,
      0.00667, 0.00893, 0.0124, -0.00345, -0.00232, -0.00115, 0.000131, 0.000819,
      0.00152, 0.00222, 0.00292, 0.00436, 0.00592, 0.00778, 0.0101, -0.00358,
      -0.00237, -0.00112, 0.000254, 0.00099, 0.00174, 0.00249, 0.00324, 0.00478,
      0.00645, 0.00845, 0.0109, -0.00382, -0.00244, -0.00115, 0.000241, 0.000984,
      0.00174, 0.0025, 0.00326, 0.00486, 0.00667, 0.00892, 0.0124, -0.00345,
      -0.00232, -0.00115, 0.00013, 0.000818, 0.00152, 0.00222, 0.00292, 0.00436,
      0.00591, 0.00777, 0.0101, -0.00357, -0.00237, -0.00112, 0.000253, 0.000988,
      0.00173, 0.00248, 0.00323, 0.00478, 0.00644, 0.00844, 0.0109, -0.00382,
      -0.00244, -0.00115, 0.00024, 0.000982, 0.00173, 0.0025, 0.00326, 0.00485,
      0.00666, 0.00892, 0.0124, -0.00367, -0.00158, 0.000586, 0.00296, 0.00424,
      0.00553, 0.00683, 0.00813, 0.0108, 0.0137, 0.0171, 0.0214, -0.00353,
      -0.00129, 0.00102, 0.00356, 0.00492, 0.00631, 0.0077, 0.00909, 0.0119,
      0.015, 0.0187, 0.0233, -0.00397, -0.0014, 0.000977, 0.00356, 0.00493,
      0.00633, 0.00774, 0.00915, 0.0121, 0.0155, 0.0196, 0.026, -0.00367,
      -0.00158, 0.000582, 0.00296, 0.00423, 0.00552, 0.00682, 0.00812, 0.0108,
      0.0137, 0.0171, 0.0213, -0.00353, -0.00129, 0.00102, 0.00356, 0.00492,
      0.0063, 0.00769, 0.00908, 0.0119, 0.015, 0.0187, 0.0233, -0.00397,
      -0.00141, 0.000973, 0.00355, 0.00492, 0.00632, 0.00773, 0.00914, 0.0121,
      0.0154, 0.0196, 0.026, -0.00367, -0.00158, 0.000579, 0.00295, 0.00422,
      0.00551, 0.00681, 0.00811, 0.0108, 0.0136, 0.0171, 0.0213, -0.00353,
      -0.0013, 0.00102, 0.00355, 0.00491, 0.00629, 0.00768, 0.00907, 0.0119,
      0.015, 0.0187, 0.0233, -0.00397, -0.00141, 0.000969, 0.00354, 0.00492,
      0.00631, 0.00772, 0.00914, 0.0121, 0.0154, 0.0196, 0.026, -0.00348,
      -0.00125, 0.00107, 0.00361, 0.00497, 0.00635, 0.00774, 0.00913, 0.012,
      0.0151, 0.0188, 0.0233, -0.00327, -0.000881, 0.00159, 0.00431, 0.00576,
      0.00724, 0.00873, 0.0102, 0.0133, 0.0166, 0.0205, 0.0254, -0.00374, -0.001,
      0.00155, 0.0043, 0.00577, 0.00727, 0.00877, 0.0103, 0.0134, 0.017, 0.0215,
      0.0283, -0.00348, -0.00125, 0.00106, 0.0036, 0.00496, 0.00634, 0.00773,
      0.00912, 0.012, 0.015, 0.0187, 0.0233, -0.00328, -0.000885, 0.00159,
      0.0043, 0.00576, 0.00723, 0.00872, 0.0102, 0.0133, 0.0165, 0.0205, 0.0254,
      -0.00375, -0.001, 0.00154, 0.0043, 0.00577, 0.00726, 0.00876, 0.0103,
      0.0134, 0.017, 0.0215, 0.0283, -0.00349, -0.00126, 0.00106, 0.00359,
      0.00495, 0.00633, 0.00772, 0.00911, 0.012, 0.015, 0.0187, 0.0232, -0.00328,
      -0.000888, 0.00158, 0.00429, 0.00575, 0.00722, 0.00871, 0.0102, 0.0132,
      0.0165, 0.0205, 0.0254, -0.00375, -0.00101, 0.00154, 0.00429, 0.00576,
      0.00725, 0.00875, 0.0103, 0.0134, 0.017, 0.0215, 0.0283 },
    0.0,

    { -0.015, -0.014, -0.008, 0.0, 0.008, 0.014, 0.015, -0.016, -0.015, -0.008,
      0.0, 0.008, 0.015, 0.016, -0.015, -0.014, -0.008, 0.0, 0.008, 0.014, 0.015,
      -0.015, -0.014, -0.008, 0.0, 0.008, 0.014, 0.015, -0.016, -0.015, -0.008,
      0.0, 0.008, 0.015, 0.016, -0.015, -0.014, -0.008, 0.0, 0.008, 0.014, 0.015,
      -0.015, -0.014, -0.008, 0.0, 0.008, 0.014, 0.015, -0.016, -0.015, -0.008,
      0.0, 0.008, 0.015, 0.016, -0.015, -0.014, -0.008, 0.0, 0.008, 0.014, 0.015
    },

    { 0.364, 0.3354, 0.1811, -0.0002, -0.1811, -0.3354, -0.3657, 0.3859, 0.356,
      0.1922, -0.0002, -0.1922, -0.356, -0.3875, 0.3865, 0.3567, 0.1925, -0.0002,
      -0.1925, -0.3567, -0.3882, 0.3566, 0.3287, 0.1774, -0.0002, -0.1774,
      -0.3287, -0.3583, 0.3715, 0.3426, 0.1849, -0.0002, -0.1849, -0.3426,
      -0.3732, 0.3596, 0.3314, 0.1789, -0.0002, -0.1789, -0.3314, -0.3613, 0.32,
      0.2943, 0.1588, -0.0002, -0.1588, -0.2943, -0.3217, 0.3253, 0.2992, 0.1614,
      -0.0002, -0.1614, -0.2992, -0.3269, 0.2861, 0.2626, 0.1416, -0.0002,
      -0.1416, -0.2626, -0.2878 },
    0.0,

    { 1.0, 1.0, 1.0 },
    0.0,

    { -16.0, -12.0, -8.0, -4.0, -2.0, 0.0, 2.0, 4.0, 8.0, 12.0, 16.0, 20.0 },

    { 0.02, 0.16, 0.3 },

    { 50.0, 150.0, 250.0 },

    { 0.146, 0.098, 0.065, 0.047, 0.043, 0.043, 0.046, 0.053, 0.08, 0.123, 0.166,
      0.197, 0.132, 0.085, 0.051, 0.034, 0.03, 0.03, 0.033, 0.04, 0.067, 0.109,
      0.152, 0.181, 0.122, 0.081, 0.048, 0.03, 0.026, 0.026, 0.03, 0.037, 0.063,
      0.099, 0.133, 0.106, 0.146, 0.098, 0.065, 0.047, 0.043, 0.043, 0.046,
      0.053, 0.08, 0.123, 0.166, 0.197, 0.132, 0.085, 0.051, 0.034, 0.03, 0.03,
      0.033, 0.04, 0.067, 0.109, 0.152, 0.181, 0.122, 0.081, 0.048, 0.03, 0.026,
      0.026, 0.03, 0.037, 0.063, 0.099, 0.133, 0.106, 0.146, 0.098, 0.065, 0.047,
      0.043, 0.043, 0.046, 0.053, 0.08, 0.123, 0.166, 0.197, 0.132, 0.085, 0.052,
      0.034, 0.03, 0.03, 0.033, 0.04, 0.067, 0.109, 0.152, 0.181, 0.122, 0.081,
      0.048, 0.03, 0.026, 0.026, 0.03, 0.037, 0.063, 0.099, 0.133, 0.106 },

    { -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01326, -0.01326, -0.01326, -0.01326,
      -0.01326, -0.01326, -0.01326, -0.01326, -0.01326, -0.01326, -0.01326,
      -0.01326, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01325, -0.01326, -0.01326, -0.01326,
      -0.01326, -0.01326, -0.01326, -0.01326, -0.01326, -0.01326, -0.01326,
      -0.01326, -0.01326, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01325,
      -0.01325, -0.01325, -0.01325, -0.01325, -0.01325, -0.01326, -0.01326,
      -0.01326, -0.01326, -0.01326, -0.01326, -0.01326, -0.01326, -0.01326,
      -0.01326, -0.01326, -0.01326 },

    { -1.405, -1.011, -0.613, -0.233, -0.053, 0.127, 0.315, 0.51, 0.918, 1.325,
      1.625, 1.764, -1.411, -1.017, -0.617, -0.234, -0.053, 0.128, 0.317, 0.514,
      0.924, 1.331, 1.63, 1.758, -1.353, -1.014, -0.621, -0.237, -0.054, 0.13,
      0.32, 0.517, 0.923, 1.275, 1.51, 1.126, -1.405, -1.011, -0.613, -0.233,
      -0.053, 0.127, 0.315, 0.51, 0.918, 1.325, 1.625, 1.764, -1.411, -1.017,
      -0.617, -0.234, -0.053, 0.128, 0.317, 0.514, 0.924, 1.331, 1.63, 1.758,
      -1.353, -1.014, -0.621, -0.237, -0.054, 0.13, 0.32, 0.517, 0.923, 1.275,
      1.51, 1.126, -1.405, -1.011, -0.613, -0.233, -0.053, 0.127, 0.315, 0.51,
      0.918, 1.325, 1.625, 1.764, -1.411, -1.017, -0.617, -0.234, -0.053, 0.128,
      0.317, 0.514, 0.924, 1.331, 1.63, 1.758, -1.353, -1.014, -0.621, -0.237,
      -0.054, 0.13, 0.32, 0.517, 0.923, 1.275, 1.51, 1.126 },
    -1.0,

    { -1.0, -1.0, -1.0 },

    { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { -0.149, -0.207, -0.296, -0.54, -1.648, 0.371, -0.002, -0.106, -0.201,
      -0.265, -0.342, -0.342, -0.146, -0.204, -0.29, -0.529, -1.61, 0.351, -0.01,
      -0.11, -0.203, -0.267, -0.344, -0.344, -0.164, -0.208, -0.291, -0.526,
      -1.608, 0.347, -0.011, -0.112, -0.207, -0.286, -0.286, -0.286, -0.149,
      -0.207, -0.296, -0.54, -1.649, 0.371, -0.002, -0.106, -0.201, -0.265,
      -0.342, -0.342, -0.146, -0.204, -0.29, -0.529, -1.611, 0.351, -0.01, -0.11,
      -0.203, -0.267, -0.344, -0.344, -0.164, -0.208, -0.292, -0.526, -1.608,
      0.347, -0.011, -0.112, -0.207, -0.286, -0.286, -0.286, -0.149, -0.207,
      -0.296, -0.54, -1.649, 0.371, -0.002, -0.106, -0.201, -0.265, -0.342,
      -0.342, -0.146, -0.204, -0.29, -0.529, -1.611, 0.351, -0.009, -0.11,
      -0.203, -0.267, -0.344, -0.344, -0.164, -0.208, -0.292, -0.526, -1.609,
      0.347, -0.011, -0.112, -0.207, -0.286, -0.286, -0.286 },
    1.32,
    0.0,
    0.0,
    0.0,

    { 0.0, 0.0, 0.0 },

    { -0.002887, -0.003014, -0.00316, -0.003306, -0.003373, -0.00344, -0.00351,
      -0.003583, -0.003737, -0.003881, -0.003961, -0.003964, -0.002889,
      -0.003016, -0.003163, -0.00331, -0.003378, -0.003446, -0.003516, -0.00359,
      -0.003745, -0.003889, -0.003969, -0.003969, -0.002928, -0.003031,
      -0.003173, -0.003318, -0.003387, -0.003454, -0.003525, -0.003598,
      -0.003749, -0.003868, -0.003919, -0.003715, -0.002887, -0.003014, -0.00316,
      -0.003306, -0.003373, -0.00344, -0.00351, -0.003583, -0.003737, -0.003881,
      -0.003961, -0.003964, -0.002889, -0.003016, -0.003163, -0.00331, -0.003378,
      -0.003446, -0.003516, -0.00359, -0.003745, -0.003889, -0.003969, -0.003969,
      -0.002928, -0.003031, -0.003173, -0.003318, -0.003387, -0.003454,
      -0.003525, -0.003598, -0.003749, -0.003868, -0.003919, -0.003715,
      -0.002887, -0.003014, -0.00316, -0.003306, -0.003373, -0.00344, -0.00351,
      -0.003583, -0.003737, -0.003881, -0.003961, -0.003964, -0.002889,
      -0.003016, -0.003163, -0.00331, -0.003378, -0.003446, -0.003516, -0.00359,
      -0.003745, -0.003889, -0.003969, -0.003969, -0.002928, -0.003031,
      -0.003173, -0.003318, -0.003387, -0.003454, -0.003525, -0.003598,
      -0.003749, -0.003868, -0.003919, -0.003715 },

    { 0.2065, 0.2095, 0.1822, 0.1272, 0.0894, 0.0472, -0.0008, -0.0545, -0.1847,
      -0.3509, -0.5504, -0.5504, 0.203, 0.2063, 0.1797, 0.1249, 0.0872, 0.045,
      -0.003, -0.0568, -0.1873, -0.3536, -0.5532, -0.5532, 0.219, 0.21, 0.1813,
      0.1256, 0.0877, 0.0451, -0.0035, -0.0582, -0.1912, -0.3622, -0.3622,
      -0.3622, 0.2066, 0.2095, 0.1823, 0.1272, 0.0894, 0.0472, -0.0007, -0.0544,
      -0.1847, -0.3509, -0.5504, -0.5504, 0.203, 0.2063, 0.1797, 0.1249, 0.0872,
      0.045, -0.003, -0.0568, -0.1873, -0.3536, -0.5532, -0.5532, 0.2191, 0.21,
      0.1813, 0.1256, 0.0877, 0.0451, -0.0035, -0.0582, -0.1912, -0.3622,
      -0.3622, -0.3622, 0.2066, 0.2095, 0.1823, 0.1272, 0.0894, 0.0472, -0.0007,
      -0.0544, -0.1847, -0.3509, -0.5504, -0.5504, 0.203, 0.2063, 0.1797, 0.1249,
      0.0872, 0.045, -0.003, -0.0568, -0.1873, -0.3536, -0.5532, -0.5532, 0.2191,
      0.21, 0.1813, 0.1256, 0.0877, 0.0451, -0.0035, -0.0581, -0.1912, -0.3622,
      -0.3622, -0.3622 },

    { -1.015E-5, -1.015E-5, -1.015E-5, -1.015E-5, -1.015E-5, -1.015E-5,
      -1.015E-5, -1.015E-5, -1.015E-5, -1.015E-5, -1.015E-5, -1.015E-5,
      -0.0002036, -0.0002036, -0.0002036, -0.0002036, -0.0002036, -0.0002036,
      -0.0002036, -0.0002036, -0.0002036, -0.0002036, -0.0002036, -0.0002036,
      -0.0002596, -0.0002596, -0.0002596, -0.0002596, -0.0002596, -0.0002596,
      -0.0002596, -0.0002596, -0.0002596, -0.0002596, -0.0002596, -0.0002596,
      -9.31E-6, -9.31E-6, -9.31E-6, -9.31E-6, -9.31E-6, -9.31E-6, -9.31E-6,
      -9.31E-6, -9.31E-6, -9.31E-6, -9.31E-6, -9.31E-6, -0.0002028, -0.0002028,
      -0.0002028, -0.0002028, -0.0002028, -0.0002028, -0.0002028, -0.0002028,
      -0.0002028, -0.0002028, -0.0002028, -0.0002028, -0.0002588, -0.0002588,
      -0.0002588, -0.0002588, -0.0002588, -0.0002588, -0.0002588, -0.0002588,
      -0.0002588, -0.0002588, -0.0002588, -0.0002588, -8.468E-6, -8.468E-6,
      -8.468E-6, -8.468E-6, -8.468E-6, -8.468E-6, -8.468E-6, -8.468E-6,
      -8.468E-6, -8.468E-6, -8.468E-6, -8.468E-6, -0.0002019, -0.0002019,
      -0.0002019, -0.0002019, -0.0002019, -0.0002019, -0.0002019, -0.0002019,
      -0.0002019, -0.0002019, -0.0002019, -0.0002019, -0.0002579, -0.0002579,
      -0.0002579, -0.0002579, -0.0002579, -0.0002579, -0.0002579, -0.0002579,
      -0.0002579, -0.0002579, -0.0002579, -0.0002579 },
    -1.0,

    { 1U, 9U, 27U },

    { 1U, 12U, 108U, 324U },

    { 1U, 12U, 36U, 108U },

    { 1U, 7U, 21U },

    { 1U, 7U, 21U },

    { 1U, 12U, 36U },

    { 1U, 12U, 36U },

    { 1U, 12U, 36U },

    { 1U, 12U, 36U },

    { 1U, 12U, 36U },

    { 1U, 12U, 36U },

    { 1U, 12U, 36U }
  };                                   /* Modifiable parameters */

  /* Initialize tunable parameters */
  Spike_P = Spike_P_temp;
}

/* Destructor */
SpikeModelClass::~SpikeModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Spike_T * SpikeModelClass::getRTM()
{
  return (&Spike_M);
}
