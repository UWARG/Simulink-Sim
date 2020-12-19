/*
 * Infinion.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Infinion".
 *
 * Model version              : 1.234
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Fri Dec 18 19:45:28 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Infinion.h"
#include "Infinion_private.h"

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
    bpIndex = binsearch_s32d_prevIdx(u, bp, static_cast<uint32_T>(*prevIndex),
      maxIndex);
    *fraction = (u - bp[static_cast<uint32_T>(bpIndex)]) / (bp[bpIndex + 1U] -
      bp[static_cast<uint32_T>(bpIndex)]);
  } else {
    bpIndex = static_cast<int32_T>(maxIndex - 1U);
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
  offset_2d = (static_cast<uint32_T>(bpIndex[2U] * static_cast<int32_T>(stride
    [2U])) + bpIndex[1U] * static_cast<int32_T>(stride[1U])) + bpIndex[0U];
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
  offset_3d = ((static_cast<uint32_T>(bpIndex[3U] * static_cast<int32_T>(stride
    [3U])) + bpIndex[2U] * static_cast<int32_T>(stride[2U])) + bpIndex[1U] *
               static_cast<int32_T>(stride[1U])) + bpIndex[0U];
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

  return static_cast<int32_T>(bpIdx);
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
void InfinionModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
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
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Infinion_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Infinion_derivatives();

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
  Infinion_derivatives();

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

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
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

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = std::fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > std::floor(u1))) {
      q = std::abs(u0 / u1);
      yEq = !(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

void InfinionModelClass::Infinion_emxInit_char_T(emxArray_char_T_Infinion_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Infinion_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Infinion_T *)std::malloc(sizeof
    (emxArray_char_T_Infinion_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
int8_T InfinionModelClass::Infinion_filedata(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Infinion_DW.eml_openfiles[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
int8_T InfinionModelClass::Infinion_cfopen(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Infinion_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
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
FILE * InfinionModelClass::Infinion_fileManager(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Infinion_DW.eml_openfiles[fileid - 3];
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

void InfinionModelClass::Infinion_emxInit_uint8_T(emxArray_uint8_T_Infinion_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_uint8_T_Infinion_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_uint8_T_Infinion_T *)std::malloc(sizeof
    (emxArray_uint8_T_Infinion_T));
  emxArray = *pEmxArray;
  emxArray->data = (uint8_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void InfinionModelClass::Infin_emxEnsureCapacity_uint8_T
  (emxArray_uint8_T_Infinion_T *emxArray, int32_T oldNumel)
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

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(uint8_T));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(uint8_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (uint8_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void InfinionModelClass::Infinion_emxFree_uint8_T(emxArray_uint8_T_Infinion_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T_Infinion_T *)NULL) {
    if (((*pEmxArray)->data != (uint8_T *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T_Infinion_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
int32_T InfinionModelClass::Infinion_cfclose(real_T fid)
{
  int32_T st;
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  st = -1;
  fileid = static_cast<int8_T>(rt_roundd_snf(fid));
  if ((fileid < 0) || (fid != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Infinion_DW.eml_openfiles[b_fileid - 3];
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
      st = 0;
      Infinion_DW.eml_openfiles[fileid - 3] = NULL;
    }
  }

  return st;
}

void InfinionModelClass::Infini_emxEnsureCapacity_char_T
  (emxArray_char_T_Infinion_T *emxArray, int32_T oldNumel)
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

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(char_T));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(char_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_readfile(emxArray_char_T_Infinion_T *y)
{
  int32_T remaining;
  int32_T b_index;
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Infinion_T *A;
  int8_T fileid;
  size_t nBytes;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T num2Read;
  int32_T c_numRead;
  size_t numReadSizeT;
  int32_T buf_size_idx_0;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Infinion_cfopen("ActuatorCommands/aileron.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Infinion_fileManager(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Infinion_fileManager(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (b_filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(b_filestar);
    position = (real_T)position_t;
  }

  position = rt_roundd_snf(position);
  if (position < 2.147483648E+9) {
    if (position >= -2.147483648E+9) {
      i = static_cast<int32_T>(position);
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  b_filestar = Infinion_fileManager(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  std::memset(&Infinion_B.buffer[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Infinion_emxInit_uint8_T(&A, 1);
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
      b_filestar = Infinion_fileManager(static_cast<real_T>(fileid));
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Infin_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = static_cast<int16_T>(remaining);
        }

        bytesOut = 0;
        numRead = 1;
        buf_size_idx_0 = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          num2Read = buf_size_idx_0;
          numRead = remaining - bytesOut;
          if (buf_size_idx_0 > numRead) {
            num2Read = numRead;
          }

          buf_size_idx_0 = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < num2Read) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, num2Read - numRead,
                                 b_filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (num2Read = 0; num2Read < numRead; num2Read++) {
            A->data[num2Read + bytesOut] = static_cast<uint8_T>
              (buf_data[num2Read]);
          }

          bytesOut += numRead;
        }

        numRead = A->size[0];
        for (num2Read = bytesOut; num2Read < numRead; num2Read++) {
          A->data[num2Read] = 0U;
        }

        if (bytesOut < remaining) {
          buf_size_idx_0 = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Infin_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        }
      }

      position = static_cast<real_T>(b_index) + static_cast<real_T>(bytesOut);
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          buf_size_idx_0 = static_cast<int32_T>(position);
        } else {
          buf_size_idx_0 = MIN_int32_T;
        }
      } else {
        buf_size_idx_0 = MAX_int32_T;
      }

      num2Read = buf_size_idx_0 - 2;
      if (b_index > num2Read + 1) {
        numRead = -1;
        num2Read = -1;
      } else {
        numRead = b_index - 2;
      }

      num2Read -= numRead;
      for (buf_size_idx_0 = 0; buf_size_idx_0 < num2Read; buf_size_idx_0++) {
        Infinion_B.buffer[(numRead + buf_size_idx_0) + 1] = A->
          data[buf_size_idx_0];
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

  Infinion_emxFree_uint8_T(&A);
  Infinion_cfclose(static_cast<real_T>(fileid));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Infini_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = static_cast<int8_T>(Infinion_B.buffer[i]);
  }
}

void InfinionModelClass::Infinion_emxInit_boolean_T
  (emxArray_boolean_T_Infinion_T **pEmxArray, int32_T numDimensions)
{
  emxArray_boolean_T_Infinion_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_Infinion_T *)std::malloc(sizeof
    (emxArray_boolean_T_Infinion_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_deblank(const emxArray_char_T_Infinion_T *x,
  emxArray_char_T_Infinion_T *y)
{
  int32_T ncols;
  int32_T i;
  static const boolean_T c[128] = { false, false, false, false, false, false,
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

  ncols = x->size[1] - 1;
  while ((ncols + 1 > 0) && (!((static_cast<uint8_T>(x->data[ncols]) != 0) &&
           (!c[static_cast<uint8_T>(x->data[ncols]) & 127])))) {
    ncols--;
  }

  if (1 > ncols + 1) {
    ncols = -1;
  }

  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ncols + 1;
  Infini_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i <= ncols; i++) {
    y->data[i] = x->data[i];
  }
}

void InfinionModelClass::Inf_emxEnsureCapacity_boolean_T
  (emxArray_boolean_T_Infinion_T *emxArray, int32_T oldNumel)
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

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(boolean_T));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_isspace(const emxArray_char_T_Infinion_T *x,
  emxArray_boolean_T_Infinion_T *y)
{
  int32_T k;
  static const boolean_T b[128] = { false, false, false, false, false, false,
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
  Inf_emxEnsureCapacity_boolean_T(y, k);
  for (k = 0; k < x->size[1]; k++) {
    y->data[k] = b[static_cast<uint8_T>(x->data[k]) & 127];
  }
}

void InfinionModelClass::Infinion_emxFree_boolean_T
  (emxArray_boolean_T_Infinion_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T_Infinion_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T_Infinion_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_string_extractAfter(const
  emxArray_char_T_Infinion_T *obj_Value, const real_T startStr_data[],
  emxArray_char_T_Infinion_T *extracted_Value)
{
  int32_T b;
  int32_T c;
  int32_T i;
  c = static_cast<int32_T>(startStr_data[0]);
  if (c + 1 > obj_Value->size[1]) {
    c = 0;
    b = 0;
  } else {
    b = obj_Value->size[1];
  }

  i = extracted_Value->size[0] * extracted_Value->size[1];
  extracted_Value->size[0] = 1;
  b -= c;
  extracted_Value->size[1] = b;
  Infini_emxEnsureCapacity_char_T(extracted_Value, i);
  for (i = 0; i < b; i++) {
    extracted_Value->data[i] = obj_Value->data[c + i];
  }
}

void InfinionModelClass::Infinion_emxInit_real_T(emxArray_real_T_Infinion_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_Infinion_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_Infinion_T *)std::malloc(sizeof
    (emxArray_real_T_Infinion_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)std::malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void InfinionModelClass::Infini_emxEnsureCapacity_real_T
  (emxArray_real_T_Infinion_T *emxArray, int32_T oldNumel)
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

    newData = std::calloc(static_cast<uint32_T>(i), sizeof(real_T));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_char(const emxArray_real_T_Infinion_T
  *varargin_1, emxArray_char_T_Infinion_T *y)
{
  int32_T loop_ub;
  int32_T i;
  real_T u;
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_1->size[1];
  Infini_emxEnsureCapacity_char_T(y, i);
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

    y->data[i] = static_cast<int8_T>(u < 0.0 ? static_cast<int32_T>(static_cast<
      int8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-u)))) :
      static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(u))));
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_skipspaces(const emxArray_char_T_Infinion_T *s,
  int32_T *k, int32_T n)
{
  static const boolean_T b[128] = { false, false, false, false, false, false,
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
  while ((*k <= n) && (b[static_cast<uint8_T>(s->data[*k - 1]) & 127] ||
                       (s->data[*k - 1] == '\x00'))) {
    (*k)++;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_copysign(emxArray_char_T_Infinion_T *s1,
  int32_T *idx, const emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n,
  boolean_T *foundsign, boolean_T *success)
{
  boolean_T isneg;
  static const boolean_T b[128] = { false, false, false, false, false, false,
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

  boolean_T exitg1;
  isneg = false;
  *foundsign = false;
  exitg1 = false;
  while ((!exitg1) && (*k <= n)) {
    if (s->data[*k - 1] == '-') {
      isneg = !isneg;
      *foundsign = true;
      (*k)++;
    } else if (s->data[*k - 1] == ',') {
      (*k)++;
    } else if (s->data[*k - 1] == '+') {
      *foundsign = true;
      (*k)++;
    } else if (!b[static_cast<uint8_T>(s->data[*k - 1]) & 127]) {
      exitg1 = true;
    } else {
      (*k)++;
    }
  }

  *success = (*k <= n);
  if ((*success) && isneg) {
    if ((*idx >= 2) && (s1->data[*idx - 2] == '-')) {
      s1->data[*idx - 2] = ' ';
    } else {
      s1->data[*idx - 1] = '-';
      (*idx)++;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
boolean_T InfinionModelClass::Infinion_isUnitImag(const
  emxArray_char_T_Infinion_T *s, int32_T k, int32_T n)
{
  boolean_T p;
  int32_T b_k;
  char_T c_idx_0;
  char_T c_idx_1;
  char_T c_idx_2;
  p = false;
  if (k <= n) {
    if (s->data[k - 1] == 'j') {
      p = true;
    } else {
      if (s->data[k - 1] == 'i') {
        if (k >= n - 1) {
          p = true;
        } else {
          b_k = k;
          c_idx_0 = '\x00';
          while ((b_k <= n) && (s->data[b_k - 1] == ',')) {
            b_k++;
          }

          if (b_k <= n) {
            c_idx_0 = s->data[b_k - 1];
          }

          b_k++;
          c_idx_1 = '\x00';
          while ((b_k <= n) && (s->data[b_k - 1] == ',')) {
            b_k++;
          }

          if (b_k <= n) {
            c_idx_1 = s->data[b_k - 1];
          }

          b_k++;
          c_idx_2 = '\x00';
          while ((b_k <= n) && (s->data[b_k - 1] == ',')) {
            b_k++;
          }

          if (b_k <= n) {
            c_idx_2 = s->data[b_k - 1];
          }

          if ((((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') ||
                (c_idx_1 == 'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) ||
              (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
                (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n')))) {
          } else {
            p = true;
          }
        }
      }
    }
  }

  return p;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_readNonFinite(const emxArray_char_T_Infinion_T
  *s, int32_T *k, int32_T n, boolean_T *b_finite, real_T *fv)
{
  int32_T ksaved;
  char_T c_idx_0;
  char_T c_idx_1;
  char_T c_idx_2;
  ksaved = *k;
  c_idx_0 = '\x00';
  while ((*k <= n) && (s->data[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= n) {
    c_idx_0 = s->data[*k - 1];
  }

  (*k)++;
  c_idx_1 = '\x00';
  while ((*k <= n) && (s->data[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= n) {
    c_idx_1 = s->data[*k - 1];
  }

  (*k)++;
  c_idx_2 = '\x00';
  while ((*k <= n) && (s->data[*k - 1] == ',')) {
    (*k)++;
  }

  if (*k <= n) {
    c_idx_2 = s->data[*k - 1];
  }

  (*k)++;
  if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) && ((c_idx_1 == 'N') || (c_idx_1 ==
        'n')) && ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
    *b_finite = false;
    *fv = (rtInf);
  } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) && ((c_idx_1 == 'A') ||
              (c_idx_1 == 'a')) && ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
    *b_finite = false;
    *fv = (rtNaN);
  } else {
    *b_finite = true;
    *fv = 0.0;
    *k = ksaved;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
boolean_T InfinionModelClass::Infinion_copydigits(emxArray_char_T_Infinion_T *s1,
  int32_T *idx, const emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n,
  boolean_T allowpoint)
{
  boolean_T success;
  boolean_T haspoint;
  boolean_T exitg1;
  success = (*k <= n);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= n))) {
    if ((s->data[*k - 1] >= '0') && (s->data[*k - 1] <= '9')) {
      s1->data[*idx - 1] = s->data[*k - 1];
      (*idx)++;
      (*k)++;
    } else if (s->data[*k - 1] == '.') {
      success = (allowpoint && (!haspoint));
      if (success) {
        s1->data[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }

      (*k)++;
    } else if (s->data[*k - 1] == ',') {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return success;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
boolean_T InfinionModelClass::Infinion_copyexponent(emxArray_char_T_Infinion_T
  *s1, int32_T *idx, const emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n)
{
  boolean_T success;
  int32_T kexp;
  int32_T b_k;
  boolean_T b_success;
  success = true;
  if ((*k <= n) && ((s->data[*k - 1] == 'E') || (s->data[*k - 1] == 'e'))) {
    s1->data[*idx - 1] = 'e';
    (*idx)++;
    (*k)++;
    while ((*k <= n) && (s->data[*k - 1] == ',')) {
      (*k)++;
    }

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

    kexp = *k;
    b_k = *k;
    b_success = Infinion_copydigits(s1, idx, s, &b_k, n, false);
    *k = b_k;
    success = (b_success && (b_k > kexp));
  }

  return success;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_skipspaces_a(const emxArray_char_T_Infinion_T *
  s, int32_T *k, int32_T n)
{
  static const boolean_T b[128] = { false, false, false, false, false, false,
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

  while ((*k <= n) && (b[static_cast<uint8_T>(s->data[*k - 1]) & 127] ||
                       (s->data[*k - 1] == '\x00') || (s->data[*k - 1] == ',')))
  {
    (*k)++;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_readfloat(emxArray_char_T_Infinion_T *s1,
  int32_T *idx, const emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n,
  boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
  boolean_T *foundsign, boolean_T *success)
{
  boolean_T unusedU1;
  boolean_T unusedU2;
  int32_T b_idx;
  int32_T b_k;
  *isimag = false;
  *b_finite = true;
  *nfv = 0.0;
  b_idx = *idx;
  b_k = *k;
  Infinion_copysign(s1, &b_idx, s, &b_k, n, foundsign, success);
  *idx = b_idx;
  *k = b_k;
  if (*success) {
    if (Infinion_isUnitImag(s, b_k, n)) {
      if (allowimag) {
        *isimag = true;
        *k = b_k + 1;
        Infinion_skipspaces_a(s, k, n);
        if ((*k <= n) && (s->data[*k - 1] == '*')) {
          (*k)++;
          Infinion_readfloat(s1, idx, s, k, n, false, &unusedU1, b_finite, nfv,
                             &unusedU2, success);
        } else {
          s1->data[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
      }
    } else {
      Infinion_readNonFinite(s, &b_k, n, b_finite, nfv);
      *k = b_k;
      if (*b_finite) {
        *success = Infinion_copydigits(s1, &b_idx, s, &b_k, n, true);
        *idx = b_idx;
        *k = b_k;
        if (*success) {
          *success = Infinion_copyexponent(s1, idx, s, k, n);
        }
      } else {
        if ((b_idx >= 2) && (s1->data[b_idx - 2] == '-')) {
          *idx = b_idx - 1;
          s1->data[b_idx - 2] = ' ';
          *nfv = -*nfv;
        }
      }

      Infinion_skipspaces_a(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Infinion_skipspaces_a(s, k, n);
      }

      if ((*k <= n) && ((s->data[*k - 1] == 'i') || (s->data[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    Infinion_skipspaces_a(s, k, n);
  }
}

void InfinionModelClass::Infinion_emxFree_real_T(emxArray_real_T_Infinion_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_Infinion_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Infinion_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
real_T InfinionModelClass::Infinion_sscanfd_k(const emxArray_char_T_Infinion_T
  *s)
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
void InfinionModelClass::Infinion_sscanfd(const emxArray_char_T_Infinion_T *s,
  real_T *out1, real_T *out2)
{
  int32_T nread;
  nread = sscanf(&s->data[0], "%lf %lf", out1, out2);
  if (nread != 2) {
    *out1 = (rtNaN);
    *out2 = (rtNaN);
  }
}

void InfinionModelClass::Infinion_emxFree_char_T(emxArray_char_T_Infinion_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Infinion_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Infinion_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
creal_T InfinionModelClass::Infinion_str2double(const emxArray_char_T_Infinion_T
  *s)
{
  creal_T x;
  emxArray_char_T_Infinion_T *s1;
  int32_T idx;
  int32_T ntoread;
  real_T v1;
  boolean_T unusedU0;
  boolean_T success;
  real_T v2;
  real_T a;
  int32_T k;
  boolean_T isimag1;
  boolean_T isfinite1;
  boolean_T foundsign;
  boolean_T c_success;
  emxArray_real_T_Infinion_T *tmp;
  x.re = (rtNaN);
  x.im = 0.0;
  if (s->size[1] >= 1) {
    Infinion_emxInit_real_T(&tmp, 2);
    ntoread = 0;
    idx = s->size[1] + 2;
    k = tmp->size[0] * tmp->size[1];
    tmp->size[0] = 1;
    tmp->size[1] = idx;
    Infini_emxEnsureCapacity_real_T(tmp, k);
    for (k = 0; k < idx; k++) {
      tmp->data[k] = 0.0;
    }

    Infinion_emxInit_char_T(&s1, 2);
    Infinion_char(tmp, s1);
    k = 1;
    Infinion_skipspaces(s, &k, s->size[1]);
    idx = 1;
    Infinion_readfloat(s1, &idx, s, &k, s->size[1], true, &isimag1, &isfinite1,
                       &v1, &unusedU0, &success);
    Infinion_emxFree_real_T(&tmp);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success && (k <= s->size[1])) {
      s1->data[idx - 1] = ' ';
      idx++;
      Infinion_readfloat(s1, &idx, s, &k, s->size[1], true, &unusedU0, &success,
                         &v2, &foundsign, &c_success);
      if (success) {
        ntoread++;
      }

      if (c_success && (k > s->size[1]) && ((isimag1 != unusedU0) && foundsign))
      {
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
        Infinion_sscanfd(s1, &v1, &v2);
      } else {
        if (ntoread == 1) {
          a = Infinion_sscanfd_k(s1);
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

    Infinion_emxFree_char_T(&s1);
  }

  return x;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
real_T InfinionModelClass::Infinion_lastStr2double(const
  emxArray_char_T_Infinion_T *str)
{
  real_T C;
  emxArray_char_T_Infinion_T *s;
  emxArray_boolean_T_Infinion_T *x;
  int32_T ii_data;
  int32_T k;
  int32_T idx;
  int32_T b_ii;
  emxArray_boolean_T_Infinion_T *tmp;
  real_T ii_data_0;
  emxArray_char_T_Infinion_T *tmp_0;
  creal_T tmp_1;
  boolean_T exitg1;
  Infinion_emxInit_char_T(&s, 2);
  Infinion_emxInit_boolean_T(&x, 2);
  Infinion_emxInit_boolean_T(&tmp, 2);
  Infinion_deblank(str, s);
  Infinion_isspace(s, tmp);
  k = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = tmp->size[1];
  Inf_emxEnsureCapacity_boolean_T(x, k);
  idx = tmp->size[0] * tmp->size[1];
  for (k = 0; k < idx; k++) {
    x->data[k] = tmp->data[k];
  }

  Infinion_emxFree_boolean_T(&tmp);
  k = (1 <= x->size[1]);
  idx = 0;
  b_ii = x->size[1];
  exitg1 = false;
  while ((!exitg1) && (b_ii > 0)) {
    if (x->data[b_ii - 1]) {
      idx = 1;
      ii_data = b_ii;
      exitg1 = true;
    } else {
      b_ii--;
    }
  }

  Infinion_emxFree_boolean_T(&x);
  if (k == 1) {
    if (idx == 0) {
      k = 0;
    }
  } else {
    k = (1 <= idx);
  }

  if (0 <= k - 1) {
    ii_data_0 = ii_data;
  }

  Infinion_emxInit_char_T(&tmp_0, 2);
  Infinion_string_extractAfter(s, &ii_data_0, tmp_0);
  tmp_1 = Infinion_str2double(tmp_0);
  C = tmp_1.re;
  Infinion_emxFree_char_T(&tmp_0);
  Infinion_emxFree_char_T(&s);
  return C;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
int8_T InfinionModelClass::Infinion_filedata_f(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Infinion_DW.eml_openfiles_l[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
int8_T InfinionModelClass::Infinion_cfopen_b(const char * cfilename, const char *
  cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Infinion_filedata_f();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles_l[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
FILE * InfinionModelClass::Infinion_fileManager_o(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Infinion_DW.eml_openfiles_l[fileid - 3];
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

/* Function for MATLAB Function: '<Root>/Read Elevator' */
int32_T InfinionModelClass::Infinion_cfclose_a(real_T fid)
{
  int32_T st;
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  st = -1;
  fileid = static_cast<int8_T>(rt_roundd_snf(fid));
  if ((fileid < 0) || (fid != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_l[b_fileid - 3];
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
      st = 0;
      Infinion_DW.eml_openfiles_l[fileid - 3] = NULL;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
void InfinionModelClass::Infinion_readfile_b(emxArray_char_T_Infinion_T *y)
{
  int32_T remaining;
  int32_T b_index;
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Infinion_T *A;
  int8_T fileid;
  size_t nBytes;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T num2Read;
  int32_T c_numRead;
  size_t numReadSizeT;
  int32_T buf_size_idx_0;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Infinion_cfopen_b("ActuatorCommands/elevator.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Infinion_fileManager_o(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Infinion_fileManager_o(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (b_filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(b_filestar);
    position = (real_T)position_t;
  }

  position = rt_roundd_snf(position);
  if (position < 2.147483648E+9) {
    if (position >= -2.147483648E+9) {
      i = static_cast<int32_T>(position);
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  b_filestar = Infinion_fileManager_o(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  std::memset(&Infinion_B.buffer_m[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Infinion_emxInit_uint8_T(&A, 1);
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
      b_filestar = Infinion_fileManager_o(static_cast<real_T>(fileid));
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Infin_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = static_cast<int16_T>(remaining);
        }

        bytesOut = 0;
        numRead = 1;
        buf_size_idx_0 = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          num2Read = buf_size_idx_0;
          numRead = remaining - bytesOut;
          if (buf_size_idx_0 > numRead) {
            num2Read = numRead;
          }

          buf_size_idx_0 = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < num2Read) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, num2Read - numRead,
                                 b_filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (num2Read = 0; num2Read < numRead; num2Read++) {
            A->data[num2Read + bytesOut] = static_cast<uint8_T>
              (buf_data[num2Read]);
          }

          bytesOut += numRead;
        }

        numRead = A->size[0];
        for (num2Read = bytesOut; num2Read < numRead; num2Read++) {
          A->data[num2Read] = 0U;
        }

        if (bytesOut < remaining) {
          buf_size_idx_0 = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Infin_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        }
      }

      position = static_cast<real_T>(b_index) + static_cast<real_T>(bytesOut);
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          buf_size_idx_0 = static_cast<int32_T>(position);
        } else {
          buf_size_idx_0 = MIN_int32_T;
        }
      } else {
        buf_size_idx_0 = MAX_int32_T;
      }

      num2Read = buf_size_idx_0 - 2;
      if (b_index > num2Read + 1) {
        numRead = -1;
        num2Read = -1;
      } else {
        numRead = b_index - 2;
      }

      num2Read -= numRead;
      for (buf_size_idx_0 = 0; buf_size_idx_0 < num2Read; buf_size_idx_0++) {
        Infinion_B.buffer_m[(numRead + buf_size_idx_0) + 1] = A->
          data[buf_size_idx_0];
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

  Infinion_emxFree_uint8_T(&A);
  Infinion_cfclose_a(static_cast<real_T>(fileid));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Infini_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = static_cast<int8_T>(Infinion_B.buffer_m[i]);
  }
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
int8_T InfinionModelClass::Infinion_filedata_d(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Infinion_DW.eml_openfiles_j[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
int8_T InfinionModelClass::Infinion_cfopen_a(const char * cfilename, const char *
  cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Infinion_filedata_d();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles_j[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
FILE * InfinionModelClass::Infinion_fileManager_c(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Infinion_DW.eml_openfiles_j[fileid - 3];
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

/* Function for MATLAB Function: '<Root>/Read Rudder' */
int32_T InfinionModelClass::Infinion_cfclose_p(real_T fid)
{
  int32_T st;
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  st = -1;
  fileid = static_cast<int8_T>(rt_roundd_snf(fid));
  if ((fileid < 0) || (fid != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_j[b_fileid - 3];
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
      st = 0;
      Infinion_DW.eml_openfiles_j[fileid - 3] = NULL;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
void InfinionModelClass::Infinion_readfile_e(emxArray_char_T_Infinion_T *y)
{
  int32_T remaining;
  int32_T b_index;
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Infinion_T *A;
  int8_T fileid;
  size_t nBytes;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T num2Read;
  int32_T c_numRead;
  size_t numReadSizeT;
  int32_T buf_size_idx_0;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Infinion_cfopen_a("ActuatorCommands/rudder.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Infinion_fileManager_c(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Infinion_fileManager_c(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (b_filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(b_filestar);
    position = (real_T)position_t;
  }

  position = rt_roundd_snf(position);
  if (position < 2.147483648E+9) {
    if (position >= -2.147483648E+9) {
      i = static_cast<int32_T>(position);
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  b_filestar = Infinion_fileManager_c(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  std::memset(&Infinion_B.buffer_c[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Infinion_emxInit_uint8_T(&A, 1);
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
      b_filestar = Infinion_fileManager_c(static_cast<real_T>(fileid));
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Infin_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = static_cast<int16_T>(remaining);
        }

        bytesOut = 0;
        numRead = 1;
        buf_size_idx_0 = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          num2Read = buf_size_idx_0;
          numRead = remaining - bytesOut;
          if (buf_size_idx_0 > numRead) {
            num2Read = numRead;
          }

          buf_size_idx_0 = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < num2Read) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, num2Read - numRead,
                                 b_filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (num2Read = 0; num2Read < numRead; num2Read++) {
            A->data[num2Read + bytesOut] = static_cast<uint8_T>
              (buf_data[num2Read]);
          }

          bytesOut += numRead;
        }

        numRead = A->size[0];
        for (num2Read = bytesOut; num2Read < numRead; num2Read++) {
          A->data[num2Read] = 0U;
        }

        if (bytesOut < remaining) {
          buf_size_idx_0 = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Infin_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        }
      }

      position = static_cast<real_T>(b_index) + static_cast<real_T>(bytesOut);
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          buf_size_idx_0 = static_cast<int32_T>(position);
        } else {
          buf_size_idx_0 = MIN_int32_T;
        }
      } else {
        buf_size_idx_0 = MAX_int32_T;
      }

      num2Read = buf_size_idx_0 - 2;
      if (b_index > num2Read + 1) {
        numRead = -1;
        num2Read = -1;
      } else {
        numRead = b_index - 2;
      }

      num2Read -= numRead;
      for (buf_size_idx_0 = 0; buf_size_idx_0 < num2Read; buf_size_idx_0++) {
        Infinion_B.buffer_c[(numRead + buf_size_idx_0) + 1] = A->
          data[buf_size_idx_0];
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

  Infinion_emxFree_uint8_T(&A);
  Infinion_cfclose_p(static_cast<real_T>(fileid));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Infini_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = static_cast<int8_T>(Infinion_B.buffer_c[i]);
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int8_T InfinionModelClass::Infinion_filedata_dy(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Infinion_DW.eml_openfiles_m[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int8_T InfinionModelClass::Infinion_cfopen_i(const char * cfilename, const char *
  cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Infinion_filedata_dy();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles_m[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
FILE * InfinionModelClass::Infinion_fileManager_l(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Infinion_DW.eml_openfiles_m[fileid - 3];
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
int32_T InfinionModelClass::Infinion_cfclose_o(real_T fid)
{
  int32_T st;
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  st = -1;
  fileid = static_cast<int8_T>(rt_roundd_snf(fid));
  if ((fileid < 0) || (fid != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_m[b_fileid - 3];
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
      st = 0;
      Infinion_DW.eml_openfiles_m[fileid - 3] = NULL;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
void InfinionModelClass::Infinion_readfile_a(emxArray_char_T_Infinion_T *y)
{
  int32_T remaining;
  int32_T b_index;
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Infinion_T *A;
  int8_T fileid;
  size_t nBytes;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T num2Read;
  int32_T c_numRead;
  size_t numReadSizeT;
  int32_T buf_size_idx_0;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Infinion_cfopen_i("ActuatorCommands/throttle.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Infinion_fileManager_l(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Infinion_fileManager_l(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (b_filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(b_filestar);
    position = (real_T)position_t;
  }

  position = rt_roundd_snf(position);
  if (position < 2.147483648E+9) {
    if (position >= -2.147483648E+9) {
      i = static_cast<int32_T>(position);
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  b_filestar = Infinion_fileManager_l(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  std::memset(&Infinion_B.buffer_k[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Infinion_emxInit_uint8_T(&A, 1);
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
      b_filestar = Infinion_fileManager_l(static_cast<real_T>(fileid));
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Infin_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = static_cast<int16_T>(remaining);
        }

        bytesOut = 0;
        numRead = 1;
        buf_size_idx_0 = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          num2Read = buf_size_idx_0;
          numRead = remaining - bytesOut;
          if (buf_size_idx_0 > numRead) {
            num2Read = numRead;
          }

          buf_size_idx_0 = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < num2Read) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, num2Read - numRead,
                                 b_filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (num2Read = 0; num2Read < numRead; num2Read++) {
            A->data[num2Read + bytesOut] = static_cast<uint8_T>
              (buf_data[num2Read]);
          }

          bytesOut += numRead;
        }

        numRead = A->size[0];
        for (num2Read = bytesOut; num2Read < numRead; num2Read++) {
          A->data[num2Read] = 0U;
        }

        if (bytesOut < remaining) {
          buf_size_idx_0 = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Infin_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
        }
      }

      position = static_cast<real_T>(b_index) + static_cast<real_T>(bytesOut);
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          buf_size_idx_0 = static_cast<int32_T>(position);
        } else {
          buf_size_idx_0 = MIN_int32_T;
        }
      } else {
        buf_size_idx_0 = MAX_int32_T;
      }

      num2Read = buf_size_idx_0 - 2;
      if (b_index > num2Read + 1) {
        numRead = -1;
        num2Read = -1;
      } else {
        numRead = b_index - 2;
      }

      num2Read -= numRead;
      for (buf_size_idx_0 = 0; buf_size_idx_0 < num2Read; buf_size_idx_0++) {
        Infinion_B.buffer_k[(numRead + buf_size_idx_0) + 1] = A->
          data[buf_size_idx_0];
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

  Infinion_emxFree_uint8_T(&A);
  Infinion_cfclose_o(static_cast<real_T>(fileid));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Infini_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = static_cast<int8_T>(Infinion_B.buffer_k[i]);
  }
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int8_T InfinionModelClass::Infinion_filedata_o(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Infinion_DW.eml_openfiles_g[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int8_T InfinionModelClass::Infinion_cfopen_e(const char * cfilename, const char *
  cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Infinion_filedata_o();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles_g[j - 1] = filestar;
      Infinion_DW.eml_autoflush[j - 1] = true;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
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
  std::memcpy(&A[0], &u1[0], 9U * sizeof(real_T));
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
  A[r2 + 3] -= A[r1 + 3] * A[r2];
  A[r3 + 3] -= A[r1 + 3] * A[r3];
  A[r2 + 6] -= A[r1 + 6] * A[r2];
  A[r3 + 6] -= A[r1 + 6] * A[r3];
  if (std::abs(A[r3 + 3]) > std::abs(A[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  y[r1] = u0[0] / A[r1];
  y[r2] = u0[1] - A[r1 + 3] * y[r1];
  y[r3] = u0[2] - A[r1 + 6] * y[r1];
  y[r2] /= A[r2 + 3];
  y[r3] -= A[r2 + 6] * y[r2];
  y[r3] /= A[r3 + 6];
  y[r2] -= A[r3 + 3] * y[r3];
  y[r1] -= y[r3] * A[r3];
  y[r1] -= y[r2] * A[r2];
}

/* Model step function */
void InfinionModelClass::step()
{
  emxArray_char_T_Infinion_T *s;
  real_T latestData;
  FILE * b_NULL;
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
  int8_T m_fileid;
  int8_T n_fileid;
  FILE * f;
  int32_T cst;
  int32_T iU;
  real_T rtb_referencearea;
  real_T rtb_UnitConversion_a;
  real_T rtb_fh;
  real_T rtb_fm;
  int32_T rtb_idxm;
  int32_T rtb_idxh;
  int32_T rtb_idxa;
  real_T rtb_jxi;
  real_T rtb_kxj_o;
  int32_T rtb_idxa_n;
  int32_T rtb_idxm_h;
  int32_T rtb_idxh_p;
  real_T rtb_ixk;
  real_T rtb_kxj;
  real_T rtb_Gain2;
  boolean_T rtb_Compare_f;
  real_T rtb_Switch;
  real_T rtb_Abs1;
  real_T rtb_Sum_bf;
  real_T rtb_Sum1_ek;
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
  real_T tmp;
  real_T VectorConcatenate_0;
  real_T rtb_Sum_d_idx_3;
  real_T rtb_Sum_d_idx_4;
  real_T rtb_Sum_f_idx_0;
  real_T rtb_Sum1_n_idx_0;
  real_T frac_b;
  real_T frac_tmp;
  real_T rtb_Sum1_n_idx_2_tmp;
  real_T rtb_Sum1_n_idx_1_tmp;
  real_T frac_tmp_0;
  int32_T rtb_VectorConcatenate_tmp;
  real_T rtb_Cmpitchingmomentcoefficie_0;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* set solver stop time */
    if (!((&Infinion_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&Infinion_M)->solverInfo, (((&Infinion_M)
        ->Timing.clockTickH0 + 1) * (&Infinion_M)->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&Infinion_M)->solverInfo, (((&Infinion_M)
        ->Timing.clockTick0 + 1) * (&Infinion_M)->Timing.stepSize0 +
        (&Infinion_M)->Timing.clockTickH0 * (&Infinion_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Infinion_M))) {
    (&Infinion_M)->Timing.t[0] = rtsiGetT(&(&Infinion_M)->solverInfo);
  }

  /* Product: '<S124>/Product1' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S125>/Product1'
   */
  rtb_fh = Infinion_X.ubvbwb_CSTATE[1] * Infinion_X.ubvbwb_CSTATE[1];

  /* Product: '<S124>/Product2' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S125>/Product2'
   */
  rtb_fm = Infinion_X.ubvbwb_CSTATE[2] * Infinion_X.ubvbwb_CSTATE[2];

  /* Sum: '<S124>/Sum' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S124>/Product'
   *  Product: '<S124>/Product1'
   *  Product: '<S124>/Product2'
   *  Sum: '<S99>/Sum'
   */
  rtb_referencearea = (Infinion_X.ubvbwb_CSTATE[0] * Infinion_X.ubvbwb_CSTATE[0]
                       + rtb_fh) + rtb_fm;

  /* Sqrt: '<S8>/Airspeed' incorporates:
   *  Sqrt: '<S64>/Airspeed'
   *  Sum: '<S124>/Sum'
   */
  rtb_Gain2 = std::sqrt(rtb_referencearea);

  /* Trigonometry: '<S8>/Incidence' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Trigonometry: '<S79>/Incidence'
   */
  rtb_Cmpitchingmomentcoefficie_0 = rt_atan2d_snf(Infinion_X.ubvbwb_CSTATE[2],
    Infinion_X.ubvbwb_CSTATE[0]);

  /* Gain: '<Root>/Gain' incorporates:
   *  Trigonometry: '<S8>/Incidence'
   */
  Gain = Infinion_P.Gain_Gain_h * rtb_Cmpitchingmomentcoefficie_0;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* UnitConversion: '<S117>/Unit Conversion' incorporates:
     *  Constant: '<S7>/ref_rotation'
     */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_Sum_f_idx_0 = 0.017453292519943295 * Infinion_P.FlatEarthtoLLA_psi;

    /* Trigonometry: '<S102>/SinCos' */
    Infinion_B.SinCos_o1 = std::sin(rtb_Sum_f_idx_0);
    Infinion_B.SinCos_o2 = std::cos(rtb_Sum_f_idx_0);

    /* Sum: '<S120>/Sum' incorporates:
     *  Constant: '<S120>/Constant'
     *  Constant: '<S120>/f'
     */
    rtb_Sum_f_idx_0 = Infinion_P.f_Value - Infinion_P.Constant_Value_j;

    /* Sqrt: '<S121>/sqrt' incorporates:
     *  Constant: '<S121>/Constant'
     *  Product: '<S121>/Product1'
     *  Sum: '<S121>/Sum1'
     */
    rtb_Sum_f_idx_0 = std::sqrt(Infinion_P.Constant_Value_i - rtb_Sum_f_idx_0 *
      rtb_Sum_f_idx_0);

    /* Switch: '<S113>/Switch' incorporates:
     *  Abs: '<S113>/Abs'
     *  Bias: '<S113>/Bias'
     *  Bias: '<S113>/Bias1'
     *  Constant: '<S113>/Constant2'
     *  Constant: '<S114>/Constant'
     *  Constant: '<S7>/ref_position'
     *  Math: '<S113>/Math Function1'
     *  RelationalOperator: '<S114>/Compare'
     */
    if (std::abs(Infinion_P.FlatEarthtoLLA_LL0[0]) >
        Infinion_P.CompareToConstant_const) {
      rtb_Switch = rt_modd_snf(Infinion_P.FlatEarthtoLLA_LL0[0] +
        Infinion_P.Bias_Bias_o, Infinion_P.Constant2_Value) +
        Infinion_P.Bias1_Bias_jw;
    } else {
      rtb_Switch = Infinion_P.FlatEarthtoLLA_LL0[0];
    }

    /* End of Switch: '<S113>/Switch' */

    /* Abs: '<S110>/Abs1' */
    rtb_Abs1 = std::abs(rtb_Switch);

    /* RelationalOperator: '<S112>/Compare' incorporates:
     *  Constant: '<S112>/Constant'
     */
    rtb_Compare_f = (rtb_Abs1 > Infinion_P.CompareToConstant_const_n);

    /* Switch: '<S110>/Switch' incorporates:
     *  Bias: '<S110>/Bias'
     *  Bias: '<S110>/Bias1'
     *  Gain: '<S110>/Gain'
     *  Product: '<S110>/Divide1'
     */
    if (rtb_Compare_f) {
      /* Signum: '<S110>/Sign1' */
      if (rtb_Switch < 0.0) {
        rtb_Switch = -1.0;
      } else if (rtb_Switch > 0.0) {
        rtb_Switch = 1.0;
      } else if (rtb_Switch == 0.0) {
        rtb_Switch = 0.0;
      } else {
        rtb_Switch = (rtNaN);
      }

      /* End of Signum: '<S110>/Sign1' */
      Infinion_B.Switch = ((rtb_Abs1 + Infinion_P.Bias_Bias_n) *
                           Infinion_P.Gain_Gain_g + Infinion_P.Bias1_Bias_a) *
        rtb_Switch;
    } else {
      Infinion_B.Switch = rtb_Switch;
    }

    /* End of Switch: '<S110>/Switch' */

    /* UnitConversion: '<S118>/Unit Conversion' */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_Switch = 0.017453292519943295 * Infinion_B.Switch;

    /* Trigonometry: '<S119>/Trigonometric Function1' */
    rtb_Abs1 = std::sin(rtb_Switch);

    /* Sum: '<S119>/Sum1' incorporates:
     *  Constant: '<S119>/Constant'
     *  Product: '<S119>/Product1'
     */
    rtb_Abs1 = Infinion_P.Constant_Value_l - rtb_Sum_f_idx_0 * rtb_Sum_f_idx_0 *
      rtb_Abs1 * rtb_Abs1;

    /* Product: '<S116>/Product1' incorporates:
     *  Constant: '<S116>/Constant1'
     *  Sqrt: '<S116>/sqrt'
     */
    rtb_UnitConversion_a = Infinion_P.Constant1_Value_k / std::sqrt(rtb_Abs1);

    /* Trigonometry: '<S116>/Trigonometric Function1' incorporates:
     *  Constant: '<S116>/Constant'
     *  Constant: '<S116>/Constant2'
     *  Product: '<S116>/Product2'
     *  Product: '<S116>/Product3'
     *  Sum: '<S116>/Sum1'
     */
    Infinion_B.TrigonometricFunction1 = rt_atan2d_snf
      (Infinion_P.Constant2_Value_d, (Infinion_P.Constant_Value_h -
        rtb_Sum_f_idx_0 * rtb_Sum_f_idx_0) * rtb_UnitConversion_a / rtb_Abs1);

    /* Trigonometry: '<S116>/Trigonometric Function2' incorporates:
     *  Constant: '<S116>/Constant3'
     *  Product: '<S116>/Product4'
     *  Trigonometry: '<S116>/Trigonometric Function'
     */
    Infinion_B.TrigonometricFunction2 = rt_atan2d_snf(Infinion_P.Constant3_Value,
      rtb_UnitConversion_a * std::cos(rtb_Switch));

    /* Switch: '<S101>/Switch1' incorporates:
     *  Constant: '<S101>/Constant'
     *  Constant: '<S101>/Constant1'
     */
    if (rtb_Compare_f) {
      rtb_Sum_d_idx_3 = Infinion_P.Constant_Value;
    } else {
      rtb_Sum_d_idx_3 = Infinion_P.Constant1_Value;
    }

    /* End of Switch: '<S101>/Switch1' */

    /* Sum: '<S101>/Sum' incorporates:
     *  Constant: '<S7>/ref_position'
     */
    rtb_Sum_f_idx_0 = rtb_Sum_d_idx_3 + Infinion_P.FlatEarthtoLLA_LL0[1];

    /* Switch: '<S111>/Switch' incorporates:
     *  Abs: '<S111>/Abs'
     *  Bias: '<S111>/Bias'
     *  Bias: '<S111>/Bias1'
     *  Constant: '<S111>/Constant2'
     *  Constant: '<S115>/Constant'
     *  Math: '<S111>/Math Function1'
     *  RelationalOperator: '<S115>/Compare'
     */
    if (std::abs(rtb_Sum_f_idx_0) > Infinion_P.CompareToConstant_const_c) {
      Infinion_B.Switch_i = rt_modd_snf(rtb_Sum_f_idx_0 + Infinion_P.Bias_Bias_f,
        Infinion_P.Constant2_Value_g) + Infinion_P.Bias1_Bias_b;
    } else {
      Infinion_B.Switch_i = rtb_Sum_f_idx_0;
    }

    /* End of Switch: '<S111>/Switch' */
  }

  /* Sum: '<S7>/Sum' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   *  Product: '<S102>/rad lat'
   *  Product: '<S102>/x*cos'
   *  Product: '<S102>/y*sin'
   *  Sum: '<S102>/Sum'
   *  UnitConversion: '<S103>/Unit Conversion'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_Sum_f_idx_0 = (Infinion_X.xeyeze_CSTATE[0] * Infinion_B.SinCos_o2 -
                     Infinion_X.xeyeze_CSTATE[1] * Infinion_B.SinCos_o1) *
    Infinion_B.TrigonometricFunction1 * 57.295779513082323 + Infinion_B.Switch;

  /* Switch: '<S107>/Switch' incorporates:
   *  Abs: '<S107>/Abs'
   *  Bias: '<S107>/Bias'
   *  Bias: '<S107>/Bias1'
   *  Constant: '<S107>/Constant2'
   *  Constant: '<S108>/Constant'
   *  Math: '<S107>/Math Function1'
   *  RelationalOperator: '<S108>/Compare'
   */
  if (std::abs(rtb_Sum_f_idx_0) > Infinion_P.CompareToConstant_const_e) {
    rtb_Sum_f_idx_0 = rt_modd_snf(rtb_Sum_f_idx_0 + Infinion_P.Bias_Bias_m,
      Infinion_P.Constant2_Value_e) + Infinion_P.Bias1_Bias_j;
  }

  /* End of Switch: '<S107>/Switch' */

  /* Abs: '<S104>/Abs1' */
  rtb_Switch = std::abs(rtb_Sum_f_idx_0);

  /* RelationalOperator: '<S106>/Compare' incorporates:
   *  Constant: '<S106>/Constant'
   */
  rtb_Compare_f = (rtb_Switch > Infinion_P.CompareToConstant_const_p);

  /* Switch: '<S104>/Switch' incorporates:
   *  Bias: '<S104>/Bias'
   *  Bias: '<S104>/Bias1'
   *  Constant: '<S100>/Constant'
   *  Constant: '<S100>/Constant1'
   *  Gain: '<S104>/Gain'
   *  Product: '<S104>/Divide1'
   *  Switch: '<S100>/Switch1'
   */
  if (rtb_Compare_f) {
    /* Signum: '<S104>/Sign1' */
    if (rtb_Sum_f_idx_0 < 0.0) {
      rtb_Sum_d_idx_3 = -1.0;
    } else if (rtb_Sum_f_idx_0 > 0.0) {
      rtb_Sum_d_idx_3 = 1.0;
    } else if (rtb_Sum_f_idx_0 == 0.0) {
      rtb_Sum_d_idx_3 = 0.0;
    } else {
      rtb_Sum_d_idx_3 = (rtNaN);
    }

    /* End of Signum: '<S104>/Sign1' */
    rtb_Sum_f_idx_0 = ((rtb_Switch + Infinion_P.Bias_Bias) *
                       Infinion_P.Gain_Gain + Infinion_P.Bias1_Bias) *
      rtb_Sum_d_idx_3;
    rtb_Sum_d_idx_3 = Infinion_P.Constant_Value_o;
  } else {
    rtb_Sum_d_idx_3 = Infinion_P.Constant1_Value_d;
  }

  /* End of Switch: '<S104>/Switch' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/HNLLat'
   */
  rtb_Sum_bf = Infinion_P.HNLLat_Value + rtb_Sum_f_idx_0;

  /* Sum: '<S100>/Sum' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   *  Product: '<S102>/rad long '
   *  Product: '<S102>/x*sin'
   *  Product: '<S102>/y*cos'
   *  Sum: '<S102>/Sum1'
   *  Sum: '<S7>/Sum'
   *  UnitConversion: '<S103>/Unit Conversion'
   */
  rtb_Sum_f_idx_0 = ((Infinion_X.xeyeze_CSTATE[0] * Infinion_B.SinCos_o1 +
                      Infinion_X.xeyeze_CSTATE[1] * Infinion_B.SinCos_o2) *
                     Infinion_B.TrigonometricFunction2 * 57.295779513082323 +
                     Infinion_B.Switch_i) + rtb_Sum_d_idx_3;

  /* Switch: '<S105>/Switch' incorporates:
   *  Abs: '<S105>/Abs'
   *  Bias: '<S105>/Bias'
   *  Bias: '<S105>/Bias1'
   *  Constant: '<S105>/Constant2'
   *  Constant: '<S109>/Constant'
   *  Math: '<S105>/Math Function1'
   *  RelationalOperator: '<S109>/Compare'
   */
  if (std::abs(rtb_Sum_f_idx_0) > Infinion_P.CompareToConstant_const_h) {
    rtb_Sum_f_idx_0 = rt_modd_snf(rtb_Sum_f_idx_0 + Infinion_P.Bias_Bias_k,
      Infinion_P.Constant2_Value_h) + Infinion_P.Bias1_Bias_g;
  }

  /* End of Switch: '<S105>/Switch' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/HNLLong'
   */
  rtb_Sum1_ek = Infinion_P.HNLLong_Value + rtb_Sum_f_idx_0;

  /* Gain: '<S6>/1//2rhoV^2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Product: '<S6>/Product2'
   */
  rtb_Sum_f_idx_0 = rtb_referencearea * Infinion_P.Constant2_Value_n *
    Infinion_P.u2rhoV2_Gain;

  /* Gain: '<S4>/reference area' */
  rtb_referencearea = Infinion_P.AerodynamicForcesandMoments_S * rtb_Sum_f_idx_0;
  Infinion_emxInit_char_T(&s, 2);
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* MATLAB Function: '<Root>/Read Aileron' */
    Infinion_readfile(s);
    latestData = Infinion_lastStr2double(s);

    /* PreLookup: '<S2>/(deltal)' incorporates:
     *  MATLAB Function: '<Root>/Read Aileron'
     *  UnitConversion: '<S40>/Unit Conversion'
     */
    /* Unit Conversion - from: rad to: deg
       Expression: output = (57.2958*input) + (0) */
    Infinion_B.idxdelL = plook_s32dd_binxp(latestData * 0.2618 / 100.0 *
      57.295779513082323, Infinion_P.deltal_BreakpointsData, 8U,
      &Infinion_B.fdelL, &Infinion_DW.deltal_DWORK1);
  }

  /* Product: '<S9>/Product1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S125>/Product'
   *  Sqrt: '<S9>/vt'
   *  Sum: '<S125>/Sum'
   */
  rtb_Switch = std::sqrt((Infinion_X.ubvbwb_CSTATE[0] *
    Infinion_X.ubvbwb_CSTATE[0] + rtb_fh) + rtb_fm) /
    Infinion_P.Constant1_Value_g;

  /* PreLookup: '<S2>/(Mach)' */
  rtb_idxm = plook_s32dd_binxp(rtb_Switch, Infinion_P.Mach_BreakpointsData, 2U,
    &rtb_fm, &Infinion_DW.Mach_DWORK1);

  /* PreLookup: '<S2>/(altitude)' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   */
  rtb_idxh = plook_s32dd_binxp(Infinion_X.xeyeze_CSTATE[2],
    Infinion_P.altitude_BreakpointsData, 2U, &rtb_fh,
    &Infinion_DW.altitude_DWORK1);

  /* Interpolation_n-D: '<S35>/clroll' */
  frac[0] = Infinion_B.fdelL;
  frac[1] = rtb_fm;
  frac[2] = rtb_fh;
  bpIndex[0] = Infinion_B.idxdelL;
  bpIndex[1] = rtb_idxm;
  bpIndex[2] = rtb_idxh;
  rtb_kxj = intrp3d_s32dl_pw(bpIndex, frac, Infinion_P.clroll_Table,
    Infinion_P.clroll_dimSize);

  /* UnitConversion: '<S38>/Unit Conversion' */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_jxi = 57.295779513082323 * Gain;

  /* PreLookup: '<S2>/(alpha)' */
  rtb_idxa = plook_s32dd_binxp(rtb_jxi, Infinion_P.alpha_BreakpointsData, 11U,
    &rtb_jxi, &Infinion_DW.alpha_DWORK1);

  /* Interpolation_n-D: '<S35>/CmYaw ' */
  frac_0[0] = rtb_jxi;
  frac_0[1] = Infinion_B.fdelL;
  frac_0[2] = rtb_fm;
  frac_0[3] = rtb_fh;
  bpIndex_0[0] = rtb_idxa;
  bpIndex_0[1] = Infinion_B.idxdelL;
  bpIndex_0[2] = rtb_idxm;
  bpIndex_0[3] = rtb_idxh;
  rtb_ixk = intrp4d_s32dl_pw(bpIndex_0, frac_0, Infinion_P.CmYaw_Table,
    Infinion_P.CmYaw_dimSize);
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* MATLAB Function: '<Root>/Read Elevator' */
    Infinion_readfile_b(s);
    latestData = Infinion_lastStr2double(s);

    /* PreLookup: '<S2>/(delta)' incorporates:
     *  Gain: '<S2>/Gain1'
     *  MATLAB Function: '<Root>/Read Elevator'
     *  UnitConversion: '<S39>/Unit Conversion'
     */
    /* Unit Conversion - from: rad to: deg
       Expression: output = (57.2958*input) + (0) */
    Infinion_B.idxde = plook_s32dd_binxp(latestData * 0.2618 / 100.0 *
      Infinion_P.Gain1_Gain * 57.295779513082323,
      Infinion_P.delta_BreakpointsData, 6U, &Infinion_B.fde,
      &Infinion_DW.delta_DWORK1);
  }

  /* Interpolation_n-D: '<S36>/DCDI' */
  frac_1[0] = rtb_jxi;
  frac_1[1] = rtb_fm;
  frac_1[2] = rtb_fh;
  frac_1[3] = Infinion_B.fde;
  bpIndex_1[0] = rtb_idxa;
  bpIndex_1[1] = rtb_idxm;
  bpIndex_1[2] = rtb_idxh;
  bpIndex_1[3] = Infinion_B.idxde;
  rtb_Abs1 = intrp4d_s32dl_pw(bpIndex_1, frac_1, Infinion_P.DCDI_Table,
    Infinion_P.DCDI_dimSize);

  /* Interpolation_n-D: '<S36>/DCL' */
  frac_2[0] = Infinion_B.fde;
  frac_2[1] = rtb_fm;
  frac_2[2] = rtb_fh;
  bpIndex_2[0] = Infinion_B.idxde;
  bpIndex_2[1] = rtb_idxm;
  bpIndex_2[2] = rtb_idxh;
  rtb_kxj_o = intrp3d_s32dl_pw(bpIndex_2, frac_2, Infinion_P.DCL_Table,
    Infinion_P.DCL_dimSize);

  /* Interpolation_n-D: '<S36>/DCm' */
  frac_3[0] = Infinion_B.fde;
  frac_3[1] = rtb_fm;
  frac_3[2] = rtb_fh;
  bpIndex_3[0] = Infinion_B.idxde;
  bpIndex_3[1] = rtb_idxm;
  bpIndex_3[2] = rtb_idxh;
  rtb_UnitConversion_a = intrp3d_s32dl_pw(bpIndex_3, frac_3,
    Infinion_P.DCm_Table, Infinion_P.DCm_dimSize);
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* MATLAB Function: '<Root>/Read Rudder' */
    Infinion_readfile_e(s);
    latestData = Infinion_lastStr2double(s);

    /* PreLookup: '<S2>/(deltaR)' incorporates:
     *  Gain: '<S2>/Gain2'
     *  MATLAB Function: '<Root>/Read Rudder'
     *  UnitConversion: '<S41>/Unit Conversion'
     */
    /* Unit Conversion - from: rad to: deg
       Expression: output = (57.2958*input) + (0) */
    Infinion_B.idxdelR = plook_s32dd_binxp(latestData * 0.2618 / 100.0 *
      Infinion_P.Gain2_Gain * 57.295779513082323,
      Infinion_P.deltaR_BreakpointsData, 4U, &Infinion_B.fdelR,
      &Infinion_DW.deltaR_DWORK1);
  }

  /* Interpolation_n-D: '<S37>/DCm (rudder)' */
  frac_4[0] = Infinion_B.fdelR;
  frac_4[1] = rtb_fm;
  frac_4[2] = rtb_fh;
  bpIndex_4[0] = Infinion_B.idxdelR;
  bpIndex_4[1] = rtb_idxm;
  bpIndex_4[2] = rtb_idxh;
  latestData = intrp3d_s32dl_pw(bpIndex_4, frac_4, Infinion_P.DCmrudder_Table,
    Infinion_P.DCmrudder_dimSize);

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S37>/Constant1'
   */
  rtb_Sum_d_idx_3 = (rtb_kxj + Infinion_P.Constant1_Value_l) +
    Infinion_P.Constant1_Value_j;
  rtb_Sum_d_idx_4 = (Infinion_P.Constant1_Value_p + rtb_UnitConversion_a) +
    Infinion_P.Constant1_Value_j;
  rtb_ixk = (rtb_ixk + Infinion_P.Constant1_Value_l) + latestData;

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S4>/coefAdjust'
   *  Sum: '<S2>/Sum'
   */
  frac[0] = ((Infinion_P.Constant1_Value_p + rtb_Abs1) +
             Infinion_P.Constant1_Value_j) * Infinion_P.coefAdjust_Gain[0] *
    rtb_referencearea;
  frac[1] = ((Infinion_P.Constant1_Value_p + Infinion_P.Constant1_Value_l) +
             Infinion_P.Constant1_Value_j) * Infinion_P.coefAdjust_Gain[1] *
    rtb_referencearea;
  frac[2] = ((Infinion_P.Constant1_Value_p + rtb_kxj_o) +
             Infinion_P.Constant1_Value_j) * Infinion_P.coefAdjust_Gain[2] *
    rtb_referencearea;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* MATLAB Function: '<Root>/Read Throttle' */
    Infinion_readfile_a(s);
    latestData = Infinion_lastStr2double(s);

    /* MATLAB Function: '<Root>/propulsion' incorporates:
     *  MATLAB Function: '<Root>/Read Throttle'
     */
    Infinion_B.forces[0] = latestData / 100.0 * 0.077 * 100.0 + 1.018;
    Infinion_B.forces[1] = 0.0;
    Infinion_B.forces[2] = 0.0;
  }

  Infinion_emxFree_char_T(&s);

  /* Trigonometry: '<S25>/sincos' incorporates:
   *  Integrator: '<S17>/phi theta psi'
   *  SignalConversion generated from: '<S25>/sincos'
   *  Trigonometry: '<S26>/sincos'
   */
  rtb_Sum1_n_idx_0 = std::cos(Infinion_X.phithetapsi_CSTATE[2]);
  frac_2[0] = std::sin(Infinion_X.phithetapsi_CSTATE[2]);
  rtb_Sum1_n_idx_1_tmp = std::cos(Infinion_X.phithetapsi_CSTATE[1]);
  frac_tmp_0 = std::sin(Infinion_X.phithetapsi_CSTATE[1]);
  rtb_Sum1_n_idx_2_tmp = std::cos(Infinion_X.phithetapsi_CSTATE[0]);
  frac_tmp = std::sin(Infinion_X.phithetapsi_CSTATE[0]);

  /* Fcn: '<S25>/Fcn11' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[0] = rtb_Sum1_n_idx_1_tmp * rtb_Sum1_n_idx_0;

  /* Fcn: '<S25>/Fcn21' incorporates:
   *  Fcn: '<S25>/Fcn22'
   *  Trigonometry: '<S25>/sincos'
   */
  rtb_UnitConversion_a = frac_tmp * frac_tmp_0;
  VectorConcatenate[1] = rtb_UnitConversion_a * rtb_Sum1_n_idx_0 -
    rtb_Sum1_n_idx_2_tmp * frac_2[0];

  /* Fcn: '<S25>/Fcn31' incorporates:
   *  Fcn: '<S25>/Fcn32'
   *  Trigonometry: '<S25>/sincos'
   */
  latestData = rtb_Sum1_n_idx_2_tmp * frac_tmp_0;
  VectorConcatenate[2] = latestData * rtb_Sum1_n_idx_0 + frac_tmp * frac_2[0];

  /* Fcn: '<S25>/Fcn12' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[3] = rtb_Sum1_n_idx_1_tmp * frac_2[0];

  /* Fcn: '<S25>/Fcn22' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[4] = rtb_UnitConversion_a * frac_2[0] + rtb_Sum1_n_idx_2_tmp
    * rtb_Sum1_n_idx_0;

  /* Fcn: '<S25>/Fcn32' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[5] = latestData * frac_2[0] - frac_tmp * rtb_Sum1_n_idx_0;

  /* Fcn: '<S25>/Fcn13' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[6] = -frac_tmp_0;

  /* Fcn: '<S25>/Fcn23' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[7] = frac_tmp * rtb_Sum1_n_idx_1_tmp;

  /* Fcn: '<S25>/Fcn33' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[8] = rtb_Sum1_n_idx_2_tmp * rtb_Sum1_n_idx_1_tmp;

  /* Product: '<S64>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S8>/Product'
   */
  rtb_Sum1_n_idx_0 = Infinion_X.ubvbwb_CSTATE[1] / rtb_Gain2;
  rtb_UnitConversion_a = rtb_Sum1_n_idx_0;

  /* Trigonometry: '<S64>/Sideslip' incorporates:
   *  Product: '<S64>/Product'
   */
  if (rtb_Sum1_n_idx_0 > 1.0) {
    rtb_UnitConversion_a = 1.0;
  } else {
    if (rtb_Sum1_n_idx_0 < -1.0) {
      rtb_UnitConversion_a = -1.0;
    }
  }

  /* SignalConversion generated from: '<S63>/sincos' incorporates:
   *  Trigonometry: '<S64>/Sideslip'
   */
  rtb_kxj_o = std::asin(rtb_UnitConversion_a);

  /* Trigonometry: '<S63>/sincos' incorporates:
   *  Trigonometry: '<S8>/Incidence'
   */
  rtb_UnitConversion_a = std::cos(rtb_Cmpitchingmomentcoefficie_0);
  latestData = std::sin(rtb_Cmpitchingmomentcoefficie_0);
  rtb_Abs1 = std::cos(rtb_kxj_o);
  rtb_kxj_o = std::sin(rtb_kxj_o);

  /* Product: '<S65>/u(3)*u(4)' */
  Infinion_B.VectorConcatenate_n[0] = rtb_UnitConversion_a * rtb_Abs1;

  /* UnaryMinus: '<S68>/Unary Minus' incorporates:
   *  Product: '<S68>/u(2)*u(3)'
   */
  Infinion_B.VectorConcatenate_n[1] = -(rtb_kxj_o * rtb_UnitConversion_a);

  /* UnaryMinus: '<S71>/Unary Minus' */
  Infinion_B.VectorConcatenate_n[2] = -latestData;

  /* SignalConversion generated from: '<S74>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_n[3] = rtb_kxj_o;

  /* SignalConversion generated from: '<S74>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_n[4] = rtb_Abs1;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* Constant: '<S72>/Constant' */
    Infinion_B.VectorConcatenate_n[5] = Infinion_P.Constant_Value_lm;
  }

  /* Product: '<S67>/u(1)*u(4)' */
  Infinion_B.VectorConcatenate_n[6] = latestData * rtb_Abs1;

  /* UnaryMinus: '<S70>/Unary Minus' incorporates:
   *  Product: '<S70>/u(1)*u(2)'
   */
  Infinion_B.VectorConcatenate_n[7] = -(latestData * rtb_kxj_o);

  /* SignalConversion generated from: '<S74>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_n[8] = rtb_UnitConversion_a;

  /* Gain: '<S3>/reference area' */
  rtb_Sum_f_idx_0 *= Infinion_P.AerodynamicForcesandMoments_S_g;

  /* UnitConversion: '<S5>/Unit Conversion' */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  latestData = 57.295779513082323 * Gain;

  /* PreLookup: '<Root>/(alpha)' */
  rtb_idxa_n = plook_s32dd_binxp(latestData, Infinion_P.alpha_BreakpointsData_d,
    11U, &latestData, &Infinion_DW.alpha_DWORK1_n);

  /* PreLookup: '<Root>/(Mach)' */
  rtb_idxm_h = plook_s32dd_binxp(rtb_Switch, Infinion_P.Mach_BreakpointsData_e,
    2U, &rtb_Switch, &Infinion_DW.Mach_DWORK1_m);

  /* PreLookup: '<Root>/(altitude)' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   */
  rtb_idxh_p = plook_s32dd_binxp(Infinion_X.xeyeze_CSTATE[2],
    Infinion_P.altitude_BreakpointsData_i, 2U, &rtb_UnitConversion_a,
    &Infinion_DW.altitude_DWORK1_p);

  /* Interpolation_n-D: '<Root>/CD (coefficient of drag)' */
  frac_5[0] = latestData;
  frac_5[1] = rtb_Switch;
  frac_5[2] = rtb_UnitConversion_a;
  bpIndex_5[0] = rtb_idxa_n;
  bpIndex_5[1] = rtb_idxm_h;
  bpIndex_5[2] = rtb_idxh_p;
  rtb_kxj_o = intrp3d_s32dl_pw(bpIndex_5, frac_5,
    Infinion_P.CDcoefficientofdrag_Table, Infinion_P.CDcoefficientofdrag_dimSize);

  /* Trigonometry: '<S8>/Sideslip' */
  if (rtb_Sum1_n_idx_0 > 1.0) {
    rtb_Sum1_n_idx_0 = 1.0;
  } else {
    if (rtb_Sum1_n_idx_0 < -1.0) {
      rtb_Sum1_n_idx_0 = -1.0;
    }
  }

  rtb_Abs1 = std::asin(rtb_Sum1_n_idx_0);

  /* End of Trigonometry: '<S8>/Sideslip' */

  /* Interpolation_n-D: '<Root>/CL (coeffcient of lift)' */
  frac_6[0] = latestData;
  frac_6[1] = rtb_Switch;
  frac_6[2] = rtb_UnitConversion_a;
  bpIndex_6[0] = rtb_idxa_n;
  bpIndex_6[1] = rtb_idxm_h;
  bpIndex_6[2] = rtb_idxh_p;
  rtb_kxj = intrp3d_s32dl_pw(bpIndex_6, frac_6,
    Infinion_P.CLcoeffcientoflift_Table, Infinion_P.CLcoeffcientoflift_dimSize);

  /* Gain: '<Root>/Gain1' */
  rtb_kxj *= Infinion_P.Gain1_Gain_e;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Gain: '<S3>/coefAdjust'
   *  Product: '<Root>/Product2'
   */
  rtb_Sum1_n_idx_0 = Infinion_P.coefAdjust_Gain_h[0] * rtb_kxj_o *
    rtb_Sum_f_idx_0;
  rtb_kxj_o = Infinion_P.Constant5_Value * rtb_Abs1 *
    Infinion_P.coefAdjust_Gain_h[1] * rtb_Sum_f_idx_0;
  rtb_kxj = Infinion_P.coefAdjust_Gain_h[2] * rtb_kxj * rtb_Sum_f_idx_0;

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
  frac_2[0] = Infinion_X.ubvbwb_CSTATE[1] * Infinion_X.pqr_CSTATE[2] -
    Infinion_X.ubvbwb_CSTATE[2] * Infinion_X.pqr_CSTATE[1];
  frac_2[1] = Infinion_X.ubvbwb_CSTATE[2] * Infinion_X.pqr_CSTATE[0] -
    Infinion_X.ubvbwb_CSTATE[0] * Infinion_X.pqr_CSTATE[2];
  frac_2[2] = Infinion_X.ubvbwb_CSTATE[0] * Infinion_X.pqr_CSTATE[1] -
    Infinion_X.ubvbwb_CSTATE[1] * Infinion_X.pqr_CSTATE[0];
  for (iU = 0; iU < 3; iU++) {
    /* Sum: '<S1>/Sum' incorporates:
     *  MATLAB Function: '<Root>/gravity'
     */
    VectorConcatenate_0 = VectorConcatenate[iU + 3];
    tmp = VectorConcatenate[iU] * 0.0 + VectorConcatenate_0 * 0.0;

    /* MATLAB Function: '<Root>/WriteToFile' incorporates:
     *  MATLAB Function: '<Root>/gravity'
     *  Sum: '<S1>/Sum'
     */
    frac_b = VectorConcatenate_0 * 0.0 + VectorConcatenate[iU] * 0.0;

    /* Sum: '<S1>/Sum' incorporates:
     *  MATLAB Function: '<Root>/gravity'
     */
    VectorConcatenate_0 = VectorConcatenate[iU + 6];
    tmp += VectorConcatenate_0 * -18.62;

    /* MATLAB Function: '<Root>/WriteToFile' */
    frac_b += VectorConcatenate_0 * -9.8;

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S19>/Constant'
     *  MATLAB Function: '<Root>/gravity'
     *  Math: '<S44>/Transpose'
     *  Product: '<S1>/Product'
     *  Product: '<S44>/Product'
     *  Sum: '<Root>/Add'
     */
    Infinion_B.Sum[iU] = (((frac[iU] + Infinion_B.forces[iU]) + tmp) +
                          (Infinion_B.VectorConcatenate_n[3 * iU + 2] * rtb_kxj
      + (Infinion_B.VectorConcatenate_n[3 * iU + 1] * rtb_kxj_o +
         Infinion_B.VectorConcatenate_n[3 * iU] * rtb_Sum1_n_idx_0))) /
      Infinion_P.uDOFEulerAngles_mass_0 + frac_2[iU];

    /* MATLAB Function: '<Root>/WriteToFile' */
    frac_6[iU] = frac_b;
  }

  /* MATLAB Function: '<Root>/WriteToFile' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain3'
   *  Integrator: '<S17>/phi theta psi'
   *  Integrator: '<S1>/p,q,r '
   *  Integrator: '<S1>/xe,ye,ze'
   *  SignalConversion generated from: '<S14>/ SFunction '
   *  Sqrt: '<S8>/Airspeed'
   *  Sum: '<S7>/Sum1'
   *  UnaryMinus: '<S7>/Ze2height'
   */
  fileid = Infinion_cfopen_e("SensorOutputs/airspeed.txt", "ab");
  b_fileid = Infinion_cfopen_e("SensorOutputs/angleOfAttack.txt", "ab");
  c_fileid = Infinion_cfopen_e("SensorOutputs/latitude.txt", "ab");
  d_fileid = Infinion_cfopen_e("SensorOutputs/longitude.txt", "ab");
  e_fileid = Infinion_cfopen_e("SensorOutputs/altitude.txt", "ab");
  f_fileid = Infinion_cfopen_e("SensorOutputs/roll.txt", "ab");
  g_fileid = Infinion_cfopen_e("SensorOutputs/pitch.txt", "ab");
  h_fileid = Infinion_cfopen_e("SensorOutputs/yaw.txt", "ab");
  i_fileid = Infinion_cfopen_e("SensorOutputs/accX.txt", "ab");
  j_fileid = Infinion_cfopen_e("SensorOutputs/accY.txt", "ab");
  k_fileid = Infinion_cfopen_e("SensorOutputs/accZ.txt", "ab");
  l_fileid = Infinion_cfopen_e("SensorOutputs/gyrX.txt", "ab");
  m_fileid = Infinion_cfopen_e("SensorOutputs/gyrY.txt", "ab");
  n_fileid = Infinion_cfopen_e("SensorOutputs/gyrZ.txt", "ab");
  b_NULL = NULL;
  if ((fileid > 22) || (fileid < 0)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", rtb_Gain2);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((b_fileid > 22) || (b_fileid < 0)) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[b_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (b_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (b_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Gain);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((c_fileid > 22) || (c_fileid < 0)) {
    c_fileid = -1;
  }

  if (c_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[c_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[c_fileid - 3];
  } else if (c_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (c_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (c_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", rtb_Sum_bf);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((d_fileid > 22) || (d_fileid < 0)) {
    d_fileid = -1;
  }

  if (d_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[d_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[d_fileid - 3];
  } else if (d_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (d_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (d_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", rtb_Sum1_ek);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((e_fileid > 22) || (e_fileid < 0)) {
    e_fileid = -1;
  }

  if (e_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[e_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[e_fileid - 3];
  } else if (e_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (e_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (e_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Infinion_P.Gain3_Gain * (-Infinion_X.xeyeze_CSTATE[2] -
             Infinion_P.Constant_Value_m));
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((f_fileid > 22) || (f_fileid < 0)) {
    f_fileid = -1;
  }

  if (f_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[f_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[f_fileid - 3];
  } else if (f_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (f_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (f_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Infinion_X.phithetapsi_CSTATE[0]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((g_fileid > 22) || (g_fileid < 0)) {
    g_fileid = -1;
  }

  if (g_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[g_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[g_fileid - 3];
  } else if (g_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (g_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (g_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Infinion_X.phithetapsi_CSTATE[1]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((h_fileid > 22) || (h_fileid < 0)) {
    h_fileid = -1;
  }

  if (h_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[h_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[h_fileid - 3];
  } else if (h_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (h_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (h_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Infinion_X.phithetapsi_CSTATE[2]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((i_fileid > 22) || (i_fileid < 0)) {
    i_fileid = -1;
  }

  if (i_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[i_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[i_fileid - 3];
  } else if (i_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (i_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (i_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", frac_6[0] + Infinion_B.Sum[0]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((j_fileid > 22) || (j_fileid < 0)) {
    j_fileid = -1;
  }

  if (j_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[j_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[j_fileid - 3];
  } else if (j_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (j_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (j_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", frac_6[1] + Infinion_B.Sum[1]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((k_fileid > 22) || (k_fileid < 0)) {
    k_fileid = -1;
  }

  if (k_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[k_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[k_fileid - 3];
  } else if (k_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (k_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (k_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", frac_6[2] + Infinion_B.Sum[2]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((l_fileid > 22) || (l_fileid < 0)) {
    l_fileid = -1;
  }

  if (l_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[l_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[l_fileid - 3];
  } else if (l_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (l_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (l_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Infinion_X.pqr_CSTATE[0]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((m_fileid > 22) || (m_fileid < 0)) {
    m_fileid = -1;
  }

  if (m_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[m_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[m_fileid - 3];
  } else if (m_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (m_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (m_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Infinion_X.pqr_CSTATE[1]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((n_fileid > 22) || (n_fileid < 0)) {
    n_fileid = -1;
  }

  if (n_fileid >= 3) {
    f = Infinion_DW.eml_openfiles_g[n_fileid - 3];
    rtb_Compare_f = Infinion_DW.eml_autoflush[n_fileid - 3];
  } else if (n_fileid == 0) {
    f = stdin;
    rtb_Compare_f = true;
  } else if (n_fileid == 1) {
    f = stdout;
    rtb_Compare_f = true;
  } else if (n_fileid == 2) {
    f = stderr;
    rtb_Compare_f = true;
  } else {
    f = NULL;
    rtb_Compare_f = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", Infinion_X.pqr_CSTATE[2]);
    if (rtb_Compare_f) {
      fflush(f);
    }
  }

  for (iU = 0; iU < 20; iU++) {
    if (Infinion_DW.eml_openfiles_g[iU] != NULL) {
      cst = fclose(Infinion_DW.eml_openfiles_g[iU]);
      if (cst == 0) {
        Infinion_DW.eml_openfiles_g[iU] = NULL;
        Infinion_DW.eml_autoflush[iU] = true;
      }
    }
  }

  /* Fcn: '<S26>/phidot' incorporates:
   *  Fcn: '<S26>/psidot'
   *  Integrator: '<S1>/p,q,r '
   */
  rtb_Gain2 = Infinion_X.pqr_CSTATE[1] * frac_tmp;

  /* SignalConversion generated from: '<S17>/phi theta psi' incorporates:
   *  Fcn: '<S26>/phidot'
   *  Fcn: '<S26>/psidot'
   *  Fcn: '<S26>/thetadot'
   *  Integrator: '<S1>/p,q,r '
   */
  Infinion_B.TmpSignalConversionAtphithetaps[0] = (rtb_Gain2 +
    Infinion_X.pqr_CSTATE[2] * rtb_Sum1_n_idx_2_tmp) * (frac_tmp_0 /
    rtb_Sum1_n_idx_1_tmp) + Infinion_X.pqr_CSTATE[0];
  Infinion_B.TmpSignalConversionAtphithetaps[1] = Infinion_X.pqr_CSTATE[1] *
    rtb_Sum1_n_idx_2_tmp - Infinion_X.pqr_CSTATE[2] * frac_tmp;
  Infinion_B.TmpSignalConversionAtphithetaps[2] = (rtb_Gain2 +
    Infinion_X.pqr_CSTATE[2] * rtb_Sum1_n_idx_2_tmp) / rtb_Sum1_n_idx_1_tmp;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    for (iU = 0; iU < 3; iU++) {
      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       */
      rtb_VectorConcatenate[6 * iU] = Infinion_P.uDOFEulerAngles_inertia[3 * iU];
      rtb_VectorConcatenate[6 * iU + 3] = Infinion_P.Constant2_Value_f[3 * iU];

      /* Selector: '<S18>/Selector' */
      Infinion_B.Selector[3 * iU] = rtb_VectorConcatenate[6 * iU];

      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       *  Selector: '<S18>/Selector'
       */
      cst = 3 * iU + 1;
      rtb_VectorConcatenate_tmp = 6 * iU + 1;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp] =
        Infinion_P.uDOFEulerAngles_inertia[cst];
      rtb_VectorConcatenate[6 * iU + 4] = Infinion_P.Constant2_Value_f[cst];

      /* Selector: '<S18>/Selector' */
      Infinion_B.Selector[cst] = rtb_VectorConcatenate[rtb_VectorConcatenate_tmp];

      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       *  Selector: '<S18>/Selector'
       */
      cst = 3 * iU + 2;
      rtb_VectorConcatenate_tmp = 6 * iU + 2;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp] =
        Infinion_P.uDOFEulerAngles_inertia[cst];
      rtb_VectorConcatenate[6 * iU + 5] = Infinion_P.Constant2_Value_f[cst];

      /* Selector: '<S18>/Selector' */
      Infinion_B.Selector[cst] = rtb_VectorConcatenate[rtb_VectorConcatenate_tmp];
    }
  }

  /* Product: '<S29>/Product' incorporates:
   *  Integrator: '<S1>/p,q,r '
   */
  for (iU = 0; iU < 3; iU++) {
    frac_2[iU] = Infinion_B.Selector[iU + 6] * Infinion_X.pqr_CSTATE[2] +
      (Infinion_B.Selector[iU + 3] * Infinion_X.pqr_CSTATE[1] +
       Infinion_B.Selector[iU] * Infinion_X.pqr_CSTATE[0]);
  }

  /* End of Product: '<S29>/Product' */

  /* Product: '<S31>/j x k' */
  tmp = frac_2[2];

  /* Product: '<S31>/k x i' */
  rtb_Gain2 = frac_2[0];

  /* Product: '<S31>/i x j' */
  Gain = frac_2[1];

  /* Product: '<S32>/k x j' */
  rtb_Sum_bf = frac_2[1];

  /* Product: '<S32>/i x k' */
  rtb_Sum1_ek = frac_2[2];

  /* Product: '<S32>/j x i' */
  rtb_Sum1_n_idx_1_tmp = frac_2[0];

  /* Sum: '<S28>/Sum' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  Product: '<S31>/i x j'
   *  Product: '<S31>/j x k'
   *  Product: '<S31>/k x i'
   *  Product: '<S32>/i x k'
   *  Product: '<S32>/j x i'
   *  Product: '<S32>/k x j'
   */
  frac_2[0] = Infinion_X.pqr_CSTATE[1] * tmp - Infinion_X.pqr_CSTATE[2] *
    rtb_Sum_bf;
  frac_2[1] = Infinion_X.pqr_CSTATE[2] * rtb_Gain2 - Infinion_X.pqr_CSTATE[0] *
    rtb_Sum1_ek;
  frac_2[2] = Infinion_X.pqr_CSTATE[0] * Gain - Infinion_X.pqr_CSTATE[1] *
    rtb_Sum1_n_idx_1_tmp;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* Selector: '<S18>/Selector1' */
    for (iU = 0; iU < 3; iU++) {
      Infinion_B.Selector1[3 * iU] = rtb_VectorConcatenate[6 * iU + 3];
      Infinion_B.Selector1[3 * iU + 1] = rtb_VectorConcatenate[6 * iU + 4];
      Infinion_B.Selector1[3 * iU + 2] = rtb_VectorConcatenate[6 * iU + 5];
    }

    /* End of Selector: '<S18>/Selector1' */
  }

  /* Interpolation_n-D: '<S2>/Xcp' */
  frac_7[0] = rtb_jxi;
  frac_7[1] = rtb_fm;
  frac_7[2] = rtb_fh;
  bpIndex_7[0] = rtb_idxa;
  bpIndex_7[1] = rtb_idxm;
  bpIndex_7[2] = rtb_idxh;
  rtb_jxi = intrp3d_s32dl_pw(bpIndex_7, frac_7, Infinion_P.Xcp_Table,
    Infinion_P.Xcp_dimSize);

  /* Gain: '<S2>/Gain' */
  rtb_jxi *= Infinion_P.Gain_Gain_e;

  /* Sum: '<S93>/Sum' incorporates:
   *  Constant: '<S2>/zero1'
   *  Product: '<S97>/j x k'
   *  Product: '<S97>/k x i'
   *  Sum: '<S4>/Sum'
   */
  rtb_fh = (0.0 - Infinion_P.zero1_Value) * frac[1];
  rtb_fm = (0.0 - rtb_jxi) * frac[2];

  /* Product: '<S97>/i x j' incorporates:
   *  Constant: '<S2>/zero1'
   *  Product: '<S98>/i x k'
   *  Sum: '<S4>/Sum'
   */
  Gain = (0.0 - Infinion_P.zero1_Value) * frac[0];

  /* Sum: '<S93>/Sum' incorporates:
   *  Constant: '<S2>/zero1'
   *  Product: '<S98>/j x i'
   *  Product: '<S98>/k x j'
   *  Sum: '<S4>/Sum'
   */
  rtb_Sum_bf = (0.0 - Infinion_P.zero1_Value) * frac[2];
  rtb_jxi = (0.0 - rtb_jxi) * frac[1];

  /* Product: '<S79>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S92>/Product'
   *  Product: '<S92>/Product1'
   *  Product: '<S92>/Product2'
   *  Sqrt: '<S79>/Airspeed'
   *  Sum: '<S92>/Sum'
   */
  rtb_Gain2 = Infinion_X.ubvbwb_CSTATE[1] / std::sqrt((Infinion_X.ubvbwb_CSTATE
    [0] * Infinion_X.ubvbwb_CSTATE[0] + Infinion_X.ubvbwb_CSTATE[1] *
    Infinion_X.ubvbwb_CSTATE[1]) + Infinion_X.ubvbwb_CSTATE[2] *
    Infinion_X.ubvbwb_CSTATE[2]);

  /* Trigonometry: '<S79>/Sideslip' */
  if (rtb_Gain2 > 1.0) {
    rtb_Gain2 = 1.0;
  } else {
    if (rtb_Gain2 < -1.0) {
      rtb_Gain2 = -1.0;
    }
  }

  /* SignalConversion generated from: '<S78>/sincos' incorporates:
   *  SignalConversion generated from: '<S48>/sincos'
   *  Trigonometry: '<S79>/Sideslip'
   */
  rtb_Sum1_ek = std::asin(rtb_Gain2);

  /* Trigonometry: '<S78>/sincos' incorporates:
   *  SignalConversion generated from: '<S78>/sincos'
   *  Trigonometry: '<S48>/sincos'
   */
  rtb_Gain2 = std::cos(rtb_Cmpitchingmomentcoefficie_0);
  rtb_Cmpitchingmomentcoefficie_0 = std::sin(rtb_Cmpitchingmomentcoefficie_0);
  rtb_Sum1_n_idx_1_tmp = std::cos(rtb_Sum1_ek);
  rtb_Sum1_ek = std::sin(rtb_Sum1_ek);

  /* Product: '<S80>/u(3)*u(4)' incorporates:
   *  Trigonometry: '<S78>/sincos'
   */
  Infinion_B.VectorConcatenate_i[0] = rtb_Gain2 * rtb_Sum1_n_idx_1_tmp;

  /* UnaryMinus: '<S83>/Unary Minus' incorporates:
   *  Product: '<S83>/u(2)*u(3)'
   *  Trigonometry: '<S78>/sincos'
   */
  Infinion_B.VectorConcatenate_i[1] = -(rtb_Sum1_ek * rtb_Gain2);

  /* UnaryMinus: '<S86>/Unary Minus' incorporates:
   *  Trigonometry: '<S78>/sincos'
   */
  Infinion_B.VectorConcatenate_i[2] = -rtb_Cmpitchingmomentcoefficie_0;

  /* SignalConversion generated from: '<S89>/Vector Concatenate' incorporates:
   *  Trigonometry: '<S78>/sincos'
   */
  Infinion_B.VectorConcatenate_i[3] = rtb_Sum1_ek;

  /* SignalConversion generated from: '<S89>/Vector Concatenate' incorporates:
   *  Trigonometry: '<S78>/sincos'
   */
  Infinion_B.VectorConcatenate_i[4] = rtb_Sum1_n_idx_1_tmp;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* Constant: '<S87>/Constant' */
    Infinion_B.VectorConcatenate_i[5] = Infinion_P.Constant_Value_lx;
  }

  /* Product: '<S82>/u(1)*u(4)' incorporates:
   *  Trigonometry: '<S78>/sincos'
   */
  Infinion_B.VectorConcatenate_i[6] = rtb_Cmpitchingmomentcoefficie_0 *
    rtb_Sum1_n_idx_1_tmp;

  /* UnaryMinus: '<S85>/Unary Minus' incorporates:
   *  Product: '<S85>/u(1)*u(2)'
   *  Trigonometry: '<S78>/sincos'
   */
  Infinion_B.VectorConcatenate_i[7] = -(rtb_Cmpitchingmomentcoefficie_0 *
    rtb_Sum1_ek);

  /* SignalConversion generated from: '<S89>/Vector Concatenate' incorporates:
   *  Trigonometry: '<S78>/sincos'
   */
  Infinion_B.VectorConcatenate_i[8] = rtb_Gain2;

  /* Product: '<S50>/u(3)*u(4)' */
  Infinion_B.VectorConcatenate_m[0] = rtb_Gain2 * rtb_Sum1_n_idx_1_tmp;

  /* UnaryMinus: '<S53>/Unary Minus' incorporates:
   *  Product: '<S53>/u(2)*u(3)'
   */
  Infinion_B.VectorConcatenate_m[1] = -(rtb_Sum1_ek * rtb_Gain2);

  /* UnaryMinus: '<S56>/Unary Minus' */
  Infinion_B.VectorConcatenate_m[2] = -rtb_Cmpitchingmomentcoefficie_0;

  /* SignalConversion generated from: '<S59>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_m[3] = rtb_Sum1_ek;

  /* SignalConversion generated from: '<S59>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_m[4] = rtb_Sum1_n_idx_1_tmp;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* Constant: '<S57>/Constant' */
    Infinion_B.VectorConcatenate_m[5] = Infinion_P.Constant_Value_e;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<Root>/zero3'
     */
    Infinion_B.Sum_j[0] = Infinion_P.zero3_Value[0] - Infinion_P.zero3_Value[0];
    Infinion_B.Sum_j[1] = Infinion_P.zero3_Value[1] - Infinion_P.zero3_Value[1];
    Infinion_B.Sum_j[2] = Infinion_P.zero3_Value[2] - Infinion_P.zero3_Value[2];
  }

  /* Product: '<S52>/u(1)*u(4)' */
  Infinion_B.VectorConcatenate_m[6] = rtb_Cmpitchingmomentcoefficie_0 *
    rtb_Sum1_n_idx_1_tmp;

  /* UnaryMinus: '<S55>/Unary Minus' incorporates:
   *  Product: '<S55>/u(1)*u(2)'
   */
  Infinion_B.VectorConcatenate_m[7] = -(rtb_Cmpitchingmomentcoefficie_0 *
    rtb_Sum1_ek);

  /* SignalConversion generated from: '<S59>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_m[8] = rtb_Gain2;

  /* Product: '<S43>/Product' */
  for (iU = 0; iU < 3; iU++) {
    frac[iU] = Infinion_B.VectorConcatenate_m[iU + 6] * Infinion_B.Sum_j[2] +
      (Infinion_B.VectorConcatenate_m[iU + 3] * Infinion_B.Sum_j[1] +
       Infinion_B.VectorConcatenate_m[iU] * Infinion_B.Sum_j[0]);
  }

  /* End of Product: '<S43>/Product' */

  /* Sum: '<S42>/Sum' incorporates:
   *  Product: '<S46>/i x j'
   *  Product: '<S46>/j x k'
   *  Product: '<S46>/k x i'
   *  Product: '<S47>/i x k'
   *  Product: '<S47>/j x i'
   *  Product: '<S47>/k x j'
   */
  rtb_Cmpitchingmomentcoefficie_0 = rtb_kxj_o * frac[2];
  rtb_Sum1_ek = rtb_kxj * frac[0];
  rtb_Sum1_n_idx_1_tmp = rtb_Sum1_n_idx_0 * frac[1];
  rtb_kxj *= frac[1];
  frac_tmp_0 = rtb_Sum1_n_idx_0 * frac[2];
  rtb_Sum1_n_idx_2_tmp = rtb_kxj_o * frac[0];

  /* Interpolation_n-D: '<Root>/Clb (derivative of rolling moment coefficient)' */
  frac_8[0] = latestData;
  frac_8[1] = rtb_Switch;
  frac_8[2] = rtb_UnitConversion_a;
  bpIndex_8[0] = rtb_idxa_n;
  bpIndex_8[1] = rtb_idxm_h;
  bpIndex_8[2] = rtb_idxh_p;
  rtb_Gain2 = intrp3d_s32dl_pw(bpIndex_8, frac_8,
    Infinion_P.Clbderivativeofrollingmomentcoe,
    Infinion_P.Clbderivativeofrollingmomentc_p);

  /* Product: '<Root>/Product1' */
  rtb_Gain2 *= rtb_Abs1;

  /* Interpolation_n-D: '<Root>/Cm (pitching moment coefficient)' */
  frac_9[0] = latestData;
  frac_9[1] = rtb_Switch;
  frac_9[2] = rtb_UnitConversion_a;
  bpIndex_9[0] = rtb_idxa_n;
  bpIndex_9[1] = rtb_idxm_h;
  bpIndex_9[2] = rtb_idxh_p;
  rtb_kxj_o = intrp3d_s32dl_pw(bpIndex_9, frac_9,
    Infinion_P.Cmpitchingmomentcoefficient_Tab,
    Infinion_P.Cmpitchingmomentcoefficient_dim);

  /* Interpolation_n-D: '<Root>/Cnb (derivative of yawing moment coefficient)' */
  frac_a[0] = latestData;
  frac_a[1] = rtb_Switch;
  frac_a[2] = rtb_UnitConversion_a;
  bpIndex_a[0] = rtb_idxa_n;
  bpIndex_a[1] = rtb_idxm_h;
  bpIndex_a[2] = rtb_idxh_p;
  latestData = intrp3d_s32dl_pw(bpIndex_a, frac_a,
    Infinion_P.Cnbderivativeofyawingmomentcoef,
    Infinion_P.Cnbderivativeofyawingmomentco_p);

  /* Product: '<Root>/Product3' */
  latestData *= rtb_Abs1;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_Switch = Infinion_P.AerodynamicForcesandMoments_b_h * rtb_Sum_f_idx_0;

  /* Sum: '<S42>/Sum' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product3'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Sum1_n_idx_0 = rtb_Switch * rtb_Gain2 + (rtb_Cmpitchingmomentcoefficie_0 -
    rtb_kxj);
  rtb_kxj_o = Infinion_P.AerodynamicForcesandMoments_c_h * rtb_Sum_f_idx_0 *
    rtb_kxj_o + (rtb_Sum1_ek - frac_tmp_0);

  /* Sum: '<S3>/Sum1' incorporates:
   *  Product: '<S3>/Product3'
   *  Sum: '<S42>/Sum'
   */
  rtb_Switch = rtb_Switch * latestData + (rtb_Sum1_n_idx_1_tmp -
    rtb_Sum1_n_idx_2_tmp);

  /* Product: '<S45>/Product' incorporates:
   *  Math: '<S45>/Transpose'
   */
  for (iU = 0; iU < 3; iU++) {
    frac[iU] = Infinion_B.VectorConcatenate_i[3 * iU + 2] * rtb_Switch +
      (Infinion_B.VectorConcatenate_i[3 * iU + 1] * rtb_kxj_o +
       Infinion_B.VectorConcatenate_i[3 * iU] * rtb_Sum1_n_idx_0);
  }

  /* End of Product: '<S45>/Product' */

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Switch = Infinion_P.AerodynamicForcesandMoments_b * rtb_referencearea;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<Root>/Gain2'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product3'
   *  Product: '<S97>/i x j'
   *  Sum: '<S4>/Sum1'
   *  Sum: '<S93>/Sum'
   */
  frac_3[0] = (rtb_Switch * rtb_Sum_d_idx_3 + (rtb_fh - rtb_Sum_bf)) + frac[0];
  frac_3[1] = (Infinion_P.AerodynamicForcesandMoments_cba * rtb_referencearea *
               rtb_Sum_d_idx_4 + (rtb_fm - Gain)) + Infinion_P.Gain2_Gain_d *
    frac[1];
  frac_3[2] = (rtb_Switch * rtb_ixk + (Gain - rtb_jxi)) + frac[2];
  for (iU = 0; iU < 3; iU++) {
    /* Sum: '<S18>/Sum2' incorporates:
     *  Integrator: '<S1>/p,q,r '
     *  Product: '<S30>/Product'
     */
    frac_3[iU] = (frac_3[iU] - (Infinion_B.Selector1[iU + 6] *
      Infinion_X.pqr_CSTATE[2] + (Infinion_B.Selector1[iU + 3] *
      Infinion_X.pqr_CSTATE[1] + Infinion_B.Selector1[iU] *
      Infinion_X.pqr_CSTATE[0]))) - frac_2[iU];
  }

  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* Selector: '<S18>/Selector2' */
    for (iU = 0; iU < 3; iU++) {
      Infinion_B.Selector2[3 * iU] = rtb_VectorConcatenate[6 * iU];
      Infinion_B.Selector2[3 * iU + 1] = rtb_VectorConcatenate[6 * iU + 1];
      Infinion_B.Selector2[3 * iU + 2] = rtb_VectorConcatenate[6 * iU + 2];
    }

    /* End of Selector: '<S18>/Selector2' */
  }

  /* Product: '<S18>/Product2' */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(frac_3, Infinion_B.Selector2,
    Infinion_B.Product2);

  /* Product: '<S24>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Math: '<S1>/Transpose'
   */
  for (iU = 0; iU < 3; iU++) {
    Infinion_B.Product[iU] = 0.0;
    Infinion_B.Product[iU] += VectorConcatenate[3 * iU] *
      Infinion_X.ubvbwb_CSTATE[0];
    Infinion_B.Product[iU] += VectorConcatenate[3 * iU + 1] *
      Infinion_X.ubvbwb_CSTATE[1];
    Infinion_B.Product[iU] += VectorConcatenate[3 * iU + 2] *
      Infinion_X.ubvbwb_CSTATE[2];
  }

  /* End of Product: '<S24>/Product' */
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    rt_ertODEUpdateContinuousStates(&(&Infinion_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&Infinion_M)->Timing.clockTick0)) {
      ++(&Infinion_M)->Timing.clockTickH0;
    }

    (&Infinion_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&Infinion_M)
      ->solverInfo);

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
      (&Infinion_M)->Timing.clockTick1++;
      if (!(&Infinion_M)->Timing.clockTick1) {
        (&Infinion_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void InfinionModelClass::Infinion_derivatives()
{
  XDot_Infinion_T *_rtXdot;
  _rtXdot = ((XDot_Infinion_T *) (&Infinion_M)->derivs);

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[0] = Infinion_B.Sum[0];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[0] = Infinion_B.Product[0];

  /* Derivatives for Integrator: '<S17>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[0] = Infinion_B.TmpSignalConversionAtphithetaps[0];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[0] = Infinion_B.Product2[0];

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[1] = Infinion_B.Sum[1];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[1] = Infinion_B.Product[1];

  /* Derivatives for Integrator: '<S17>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[1] = Infinion_B.TmpSignalConversionAtphithetaps[1];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[1] = Infinion_B.Product2[1];

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[2] = Infinion_B.Sum[2];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[2] = Infinion_B.Product[2];

  /* Derivatives for Integrator: '<S17>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[2] = Infinion_B.TmpSignalConversionAtphithetaps[2];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[2] = Infinion_B.Product2[2];
}

/* Model initialize function */
void InfinionModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Infinion_M)->solverInfo, &(&Infinion_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&Infinion_M)->solverInfo, &rtmGetTPtr((&Infinion_M)));
    rtsiSetStepSizePtr(&(&Infinion_M)->solverInfo, &(&Infinion_M)
                       ->Timing.stepSize0);
    rtsiSetdXPtr(&(&Infinion_M)->solverInfo, &(&Infinion_M)->derivs);
    rtsiSetContStatesPtr(&(&Infinion_M)->solverInfo, (real_T **) &(&Infinion_M
                         )->contStates);
    rtsiSetNumContStatesPtr(&(&Infinion_M)->solverInfo, &(&Infinion_M)
      ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Infinion_M)->solverInfo, &(&Infinion_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Infinion_M)->solverInfo, &(&Infinion_M)
      ->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Infinion_M)->solverInfo, &(&Infinion_M
      )->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Infinion_M)->solverInfo, (&rtmGetErrorStatus
      ((&Infinion_M))));
    rtsiSetRTModelPtr(&(&Infinion_M)->solverInfo, (&Infinion_M));
  }

  rtsiSetSimTimeStep(&(&Infinion_M)->solverInfo, MAJOR_TIME_STEP);
  (&Infinion_M)->intgData.y = (&Infinion_M)->odeY;
  (&Infinion_M)->intgData.f[0] = (&Infinion_M)->odeF[0];
  (&Infinion_M)->intgData.f[1] = (&Infinion_M)->odeF[1];
  (&Infinion_M)->intgData.f[2] = (&Infinion_M)->odeF[2];
  (&Infinion_M)->contStates = ((X_Infinion_T *) &Infinion_X);
  (&Infinion_M)->periodicContStateIndices = ((int_T*) Infinion_PeriodicIndX);
  (&Infinion_M)->periodicContStateRanges = ((real_T*) Infinion_PeriodicRngX);
  rtsiSetSolverData(&(&Infinion_M)->solverInfo, static_cast<void *>
                    (&(&Infinion_M)->intgData));
  rtsiSetSolverName(&(&Infinion_M)->solverInfo,"ode3");
  rtmSetTPtr((&Infinion_M), &(&Infinion_M)->Timing.tArray[0]);
  (&Infinion_M)->Timing.stepSize0 = 0.02;

  {
    FILE * a;
    int32_T i;

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Infinion_X.ubvbwb_CSTATE[0] = Infinion_P.uDOFEulerAngles_Vm_0[0];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Infinion_X.xeyeze_CSTATE[0] = Infinion_P.uDOFEulerAngles_xme_0[0];

    /* InitializeConditions for Integrator: '<S17>/phi theta psi' */
    Infinion_X.phithetapsi_CSTATE[0] = Infinion_P.uDOFEulerAngles_eul_0[0];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Infinion_X.pqr_CSTATE[0] = Infinion_P.uDOFEulerAngles_pm_0[0];

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Infinion_X.ubvbwb_CSTATE[1] = Infinion_P.uDOFEulerAngles_Vm_0[1];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Infinion_X.xeyeze_CSTATE[1] = Infinion_P.uDOFEulerAngles_xme_0[1];

    /* InitializeConditions for Integrator: '<S17>/phi theta psi' */
    Infinion_X.phithetapsi_CSTATE[1] = Infinion_P.uDOFEulerAngles_eul_0[1];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Infinion_X.pqr_CSTATE[1] = Infinion_P.uDOFEulerAngles_pm_0[1];

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Infinion_X.ubvbwb_CSTATE[2] = Infinion_P.uDOFEulerAngles_Vm_0[2];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Infinion_X.xeyeze_CSTATE[2] = Infinion_P.uDOFEulerAngles_xme_0[2];

    /* InitializeConditions for Integrator: '<S17>/phi theta psi' */
    Infinion_X.phithetapsi_CSTATE[2] = Infinion_P.uDOFEulerAngles_eul_0[2];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Infinion_X.pqr_CSTATE[2] = Infinion_P.uDOFEulerAngles_pm_0[2];

    /* SystemInitialize for MATLAB Function: '<Root>/Read Aileron' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Infinion_DW.eml_openfiles[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Aileron' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Elevator' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Infinion_DW.eml_openfiles_l[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Elevator' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Rudder' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Infinion_DW.eml_openfiles_j[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Rudder' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Infinion_DW.eml_openfiles_m[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */

    /* SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Infinion_DW.eml_openfiles_g[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */

    /* InitializeConditions for root-level periodic continuous states */
    {
      int_T rootPeriodicContStateIndices[3] = { 6, 7, 8 };

      real_T rootPeriodicContStateRanges[6] = { -3.1415926535897931,
        3.1415926535897931, -3.1415926535897931, 3.1415926535897931,
        -3.1415926535897931, 3.1415926535897931 };

      (void) std::memcpy((void*)Infinion_PeriodicIndX,
                         rootPeriodicContStateIndices,
                         3*sizeof(int_T));
      (void) std::memcpy((void*)Infinion_PeriodicRngX,
                         rootPeriodicContStateRanges,
                         6*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void InfinionModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
InfinionModelClass::InfinionModelClass():
  Infinion_B()
  ,Infinion_DW()
  ,Infinion_X()
  ,Infinion_PeriodicIndX()
  ,Infinion_PeriodicRngX()
  ,Infinion_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
InfinionModelClass::~InfinionModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Infinion_T * InfinionModelClass::getRTM()
{
  return (&Infinion_M);
}
