/*
 * Spike.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Spike".
 *
 * Model version              : 1.162
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Sun Oct 25 15:00:48 2020
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

void SpikeModelClass::Spike_emxInit_char_T(emxArray_char_T_Spike_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_char_T_Spike_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Spike_T *)std::malloc(sizeof
    (emxArray_char_T_Spike_T));
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
int8_T SpikeModelClass::Spike_filedata(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
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
FILE * SpikeModelClass::Spike_fileManager(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
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
  *pEmxArray = (emxArray_uint8_T_Spike_T *)std::malloc(sizeof
    (emxArray_uint8_T_Spike_T));
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

void SpikeModelClass::Spike_emxFree_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T_Spike_T *)NULL) {
    if (((*pEmxArray)->data != (uint8_T *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T_Spike_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
int32_T SpikeModelClass::Spike_cfclose(real_T fid)
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
      st = 0;
      Spike_DW.eml_openfiles[fileid - 3] = NULL;
    }
  }

  return st;
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
void SpikeModelClass::Spike_readfile(emxArray_char_T_Spike_T *y)
{
  int32_T remaining;
  int32_T b_index;
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Spike_T *A;
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
  fileid = Spike_cfopen("ActuatorCommands/aileron.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Spike_fileManager(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Spike_fileManager(static_cast<real_T>(fileid));
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
  b_filestar = Spike_fileManager(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  std::memset(&Spike_B.buffer[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
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
      b_filestar = Spike_fileManager(static_cast<real_T>(fileid));
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
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

          Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
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
        Spike_B.buffer[(numRead + buf_size_idx_0) + 1] = A->data[buf_size_idx_0];
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
  Spike_cfclose(static_cast<real_T>(fileid));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = static_cast<int8_T>(Spike_B.buffer[i]);
  }
}

void SpikeModelClass::Spike_emxInit_boolean_T(emxArray_boolean_T_Spike_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_boolean_T_Spike_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_Spike_T *)std::malloc(sizeof
    (emxArray_boolean_T_Spike_T));
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
void SpikeModelClass::Spike_deblank(const emxArray_char_T_Spike_T *x,
  emxArray_char_T_Spike_T *y)
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
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i <= ncols; i++) {
    y->data[i] = x->data[i];
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
void SpikeModelClass::Spike_isspace(const emxArray_char_T_Spike_T *x,
  emxArray_boolean_T_Spike_T *y)
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
  Spi_emxEnsureCapacity_boolean_T(y, k);
  for (k = 0; k < x->size[1]; k++) {
    y->data[k] = b[static_cast<uint8_T>(x->data[k]) & 127];
  }
}

void SpikeModelClass::Spike_emxFree_boolean_T(emxArray_boolean_T_Spike_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T_Spike_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T_Spike_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void SpikeModelClass::Spike_string_extractAfter(const emxArray_char_T_Spike_T
  *obj_Value, const real_T startStr_data[], emxArray_char_T_Spike_T
  *extracted_Value)
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
  Spike_emxEnsureCapacity_char_T(extracted_Value, i);
  for (i = 0; i < b; i++) {
    extracted_Value->data[i] = obj_Value->data[c + i];
  }
}

void SpikeModelClass::Spike_emxInit_real_T(emxArray_real_T_Spike_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_real_T_Spike_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_Spike_T *)std::malloc(sizeof
    (emxArray_real_T_Spike_T));
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

    y->data[i] = static_cast<int8_T>(u < 0.0 ? static_cast<int32_T>(static_cast<
      int8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-u)))) :
      static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(u))));
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void SpikeModelClass::Spike_skipspaces(const emxArray_char_T_Spike_T *s, int32_T
  *k, int32_T n)
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
void SpikeModelClass::Spike_copysign(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *foundsign,
  boolean_T *success)
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
boolean_T SpikeModelClass::Spike_isUnitImag(const emxArray_char_T_Spike_T *s,
  int32_T k, int32_T n)
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
void SpikeModelClass::Spike_readNonFinite(const emxArray_char_T_Spike_T *s,
  int32_T *k, int32_T n, boolean_T *b_finite, real_T *fv)
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
boolean_T SpikeModelClass::Spike_copydigits(emxArray_char_T_Spike_T *s1, int32_T
  *idx, const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T
  allowpoint)
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
boolean_T SpikeModelClass::Spike_copyexponent(emxArray_char_T_Spike_T *s1,
  int32_T *idx, const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n)
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
    b_success = Spike_copydigits(s1, idx, s, &b_k, n, false);
    *k = b_k;
    success = (b_success && (b_k > kexp));
  }

  return success;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void SpikeModelClass::Spike_skipspaces_a(const emxArray_char_T_Spike_T *s,
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

  while ((*k <= n) && (b[static_cast<uint8_T>(s->data[*k - 1]) & 127] ||
                       (s->data[*k - 1] == '\x00') || (s->data[*k - 1] == ',')))
  {
    (*k)++;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void SpikeModelClass::Spike_readfloat(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowimag,
  boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign,
  boolean_T *success)
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
  Spike_copysign(s1, &b_idx, s, &b_k, n, foundsign, success);
  *idx = b_idx;
  *k = b_k;
  if (*success) {
    if (Spike_isUnitImag(s, b_k, n)) {
      if (allowimag) {
        *isimag = true;
        *k = b_k + 1;
        Spike_skipspaces_a(s, k, n);
        if ((*k <= n) && (s->data[*k - 1] == '*')) {
          (*k)++;
          Spike_readfloat(s1, idx, s, k, n, false, &unusedU1, b_finite, nfv,
                          &unusedU2, success);
        } else {
          s1->data[b_idx - 1] = '1';
          *idx = b_idx + 1;
        }
      } else {
        *success = false;
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

      Spike_skipspaces_a(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Spike_skipspaces_a(s, k, n);
      }

      if ((*k <= n) && ((s->data[*k - 1] == 'i') || (s->data[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    Spike_skipspaces_a(s, k, n);
  }
}

void SpikeModelClass::Spike_emxFree_real_T(emxArray_real_T_Spike_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_Spike_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Spike_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
real_T SpikeModelClass::Spike_sscanfd_k(const emxArray_char_T_Spike_T *s)
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
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
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
  boolean_T unusedU0;
  boolean_T success;
  real_T v2;
  real_T a;
  int32_T k;
  boolean_T isimag1;
  boolean_T isfinite1;
  boolean_T foundsign;
  boolean_T c_success;
  emxArray_real_T_Spike_T *tmp;
  x.re = (rtNaN);
  x.im = 0.0;
  if (s->size[1] >= 1) {
    Spike_emxInit_real_T(&tmp, 2);
    ntoread = 0;
    idx = s->size[1] + 2;
    k = tmp->size[0] * tmp->size[1];
    tmp->size[0] = 1;
    tmp->size[1] = idx;
    Spike_emxEnsureCapacity_real_T(tmp, k);
    for (k = 0; k < idx; k++) {
      tmp->data[k] = 0.0;
    }

    Spike_emxInit_char_T(&s1, 2);
    Spike_char(tmp, s1);
    k = 1;
    Spike_skipspaces(s, &k, s->size[1]);
    idx = 1;
    Spike_readfloat(s1, &idx, s, &k, s->size[1], true, &isimag1, &isfinite1, &v1,
                    &unusedU0, &success);
    Spike_emxFree_real_T(&tmp);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success && (k <= s->size[1])) {
      s1->data[idx - 1] = ' ';
      idx++;
      Spike_readfloat(s1, &idx, s, &k, s->size[1], true, &unusedU0, &success,
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
        Spike_sscanfd(s1, &v1, &v2);
      } else {
        if (ntoread == 1) {
          a = Spike_sscanfd_k(s1);
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
real_T SpikeModelClass::Spike_lastStr2double(const emxArray_char_T_Spike_T *str)
{
  real_T C;
  emxArray_char_T_Spike_T *s;
  emxArray_boolean_T_Spike_T *x;
  int32_T ii_data;
  int32_T k;
  int32_T idx;
  int32_T b_ii;
  emxArray_boolean_T_Spike_T *tmp;
  real_T ii_data_0;
  emxArray_char_T_Spike_T *tmp_0;
  creal_T tmp_1;
  boolean_T exitg1;
  Spike_emxInit_char_T(&s, 2);
  Spike_emxInit_boolean_T(&x, 2);
  Spike_emxInit_boolean_T(&tmp, 2);
  Spike_deblank(str, s);
  Spike_isspace(s, tmp);
  k = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = tmp->size[1];
  Spi_emxEnsureCapacity_boolean_T(x, k);
  idx = tmp->size[0] * tmp->size[1];
  for (k = 0; k < idx; k++) {
    x->data[k] = tmp->data[k];
  }

  Spike_emxFree_boolean_T(&tmp);
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

  Spike_emxFree_boolean_T(&x);
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

  Spike_emxInit_char_T(&tmp_0, 2);
  Spike_string_extractAfter(s, &ii_data_0, tmp_0);
  tmp_1 = Spike_str2double(tmp_0);
  C = tmp_1.re;
  Spike_emxFree_char_T(&tmp_0);
  Spike_emxFree_char_T(&s);
  return C;
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
int8_T SpikeModelClass::Spike_filedata_f(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_l[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
int8_T SpikeModelClass::Spike_cfopen_b(const char * cfilename, const char
  * cpermission)
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
      Spike_DW.eml_openfiles_l[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
FILE * SpikeModelClass::Spike_fileManager_o(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
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
int32_T SpikeModelClass::Spike_cfclose_a(real_T fid)
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
      st = 0;
      Spike_DW.eml_openfiles_l[fileid - 3] = NULL;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<Root>/Read Tail right' */
void SpikeModelClass::Spike_readfile_b(emxArray_char_T_Spike_T *y)
{
  int32_T remaining;
  int32_T b_index;
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Spike_T *A;
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
  fileid = Spike_cfopen_b("ActuatorCommands/tailRight.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Spike_fileManager_o(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Spike_fileManager_o(static_cast<real_T>(fileid));
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
  b_filestar = Spike_fileManager_o(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  std::memset(&Spike_B.buffer_c[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
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
      b_filestar = Spike_fileManager_o(static_cast<real_T>(fileid));
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
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

          Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
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
        Spike_B.buffer_c[(numRead + buf_size_idx_0) + 1] = A->
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

  Spike_emxFree_uint8_T(&A);
  Spike_cfclose_a(static_cast<real_T>(fileid));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = static_cast<int8_T>(Spike_B.buffer_c[i]);
  }
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
int8_T SpikeModelClass::Spike_filedata_d(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_j[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
int8_T SpikeModelClass::Spike_cfopen_a(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_d();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_j[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
FILE * SpikeModelClass::Spike_fileManager_c(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
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
int32_T SpikeModelClass::Spike_cfclose_p(real_T fid)
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
      st = 0;
      Spike_DW.eml_openfiles_j[fileid - 3] = NULL;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<Root>/Read Tail left' */
void SpikeModelClass::Spike_readfile_e(emxArray_char_T_Spike_T *y)
{
  int32_T remaining;
  int32_T b_index;
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Spike_T *A;
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
  fileid = Spike_cfopen_a("ActuatorCommands/tailLeft.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Spike_fileManager_c(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Spike_fileManager_c(static_cast<real_T>(fileid));
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
  b_filestar = Spike_fileManager_c(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  std::memset(&Spike_B.buffer_m[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
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
      b_filestar = Spike_fileManager_c(static_cast<real_T>(fileid));
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
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

          Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
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
        Spike_B.buffer_m[(numRead + buf_size_idx_0) + 1] = A->
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

  Spike_emxFree_uint8_T(&A);
  Spike_cfclose_p(static_cast<real_T>(fileid));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = static_cast<int8_T>(Spike_B.buffer_m[i]);
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int8_T SpikeModelClass::Spike_filedata_dy(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_m[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int8_T SpikeModelClass::Spike_cfopen_i(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_dy();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_m[j - 1] = filestar;
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
FILE * SpikeModelClass::Spike_fileManager_l(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_m[fileid - 3];
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
int32_T SpikeModelClass::Spike_cfclose_o(real_T fid)
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
    f = Spike_DW.eml_openfiles_m[b_fileid - 3];
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
      Spike_DW.eml_openfiles_m[fileid - 3] = NULL;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
void SpikeModelClass::Spike_readfile_a(emxArray_char_T_Spike_T *y)
{
  int32_T remaining;
  int32_T b_index;
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Spike_T *A;
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
  fileid = Spike_cfopen_i("ActuatorCommands/throttle.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Spike_fileManager_l(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Spike_fileManager_l(static_cast<real_T>(fileid));
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
  b_filestar = Spike_fileManager_l(static_cast<real_T>(fileid));
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  std::memset(&Spike_B.buffer_k[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
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
      b_filestar = Spike_fileManager_l(static_cast<real_T>(fileid));
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        buf_size_idx_0 = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
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

          Spike_emxEnsureCapacity_uint8_T(A, buf_size_idx_0);
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
        Spike_B.buffer_k[(numRead + buf_size_idx_0) + 1] = A->
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

  Spike_emxFree_uint8_T(&A);
  Spike_cfclose_o(static_cast<real_T>(fileid));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = static_cast<int8_T>(Spike_B.buffer_k[i]);
  }
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int8_T SpikeModelClass::Spike_filedata_o(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_g[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int8_T SpikeModelClass::Spike_cfopen_e(const char * cfilename, const char
  * cpermission)
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
      Spike_DW.eml_openfiles_g[j - 1] = filestar;
      Spike_DW.eml_autoflush[j - 1] = true;
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
void SpikeModelClass::step()
{
  emxArray_char_T_Spike_T *s;
  real_T latestData;
  emxArray_char_T_Spike_T *b_s;
  emxArray_boolean_T_Spike_T *x;
  int32_T ii_data;
  int32_T k;
  int32_T idx;
  real_T latestData_0;
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
  FILE * f;
  boolean_T a;
  int32_T iU;
  real_T rtb_fm_n;
  real_T rtb_referencearea;
  real_T rtb_referencearea_k;
  real_T rtb_fh;
  real_T rtb_fm;
  int32_T rtb_idxm;
  int32_T rtb_idxh;
  int32_T rtb_idxa;
  real_T rtb_Gain;
  real_T rtb_ixk;
  real_T rtb_jxi;
  int32_T rtb_idxh_p;
  real_T rtb_Sideslip_c;
  real_T rtb_kxj;
  real_T rtb_Gain2;
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
  emxArray_boolean_T_Spike_T *tmp;
  emxArray_char_T_Spike_T *tmp_0;
  emxArray_boolean_T_Spike_T *tmp_1;
  emxArray_char_T_Spike_T *tmp_2;
  real_T VectorConcatenate_0;
  real_T rtb_Sum_d_idx_3;
  real_T rtb_Sum_d_idx_4;
  real_T rtb_Sum_d_idx_5;
  real_T rtb_Sum1_idx_0;
  creal_T tmp_3;
  creal_T tmp_4;
  real_T frac_b;
  real_T frac_tmp;
  real_T rtb_Sum1_idx_2_tmp;
  real_T rtb_Sum1_idx_1_tmp;
  real_T frac_tmp_0;
  int32_T rtb_VectorConcatenate_tmp;
  real_T rtb_kxj_tmp;
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

  /* Product: '<S101>/Product1' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S102>/Product1'
   */
  rtb_fh = Spike_X.ubvbwb_CSTATE[1] * Spike_X.ubvbwb_CSTATE[1];

  /* Product: '<S101>/Product2' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S102>/Product2'
   */
  rtb_fm = Spike_X.ubvbwb_CSTATE[2] * Spike_X.ubvbwb_CSTATE[2];

  /* Sum: '<S101>/Sum' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S101>/Product'
   *  Product: '<S101>/Product1'
   *  Product: '<S101>/Product2'
   *  Sum: '<S98>/Sum'
   */
  rtb_referencearea = (Spike_X.ubvbwb_CSTATE[0] * Spike_X.ubvbwb_CSTATE[0] +
                       rtb_fh) + rtb_fm;

  /* Sqrt: '<S7>/Airspeed' incorporates:
   *  Sqrt: '<S63>/Airspeed'
   *  Sum: '<S101>/Sum'
   */
  rtb_Gain2 = std::sqrt(rtb_referencearea);

  /* Trigonometry: '<S7>/Incidence' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Trigonometry: '<S78>/Incidence'
   */
  rtb_kxj_tmp = rt_atan2d_snf(Spike_X.ubvbwb_CSTATE[2], Spike_X.ubvbwb_CSTATE[0]);

  /* Gain: '<Root>/Gain' incorporates:
   *  Trigonometry: '<S7>/Incidence'
   */
  Gain = Spike_P.Gain_Gain * rtb_kxj_tmp;

  /* Gain: '<S6>/1//2rhoV^2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Product: '<S6>/Product2'
   */
  rtb_referencearea_k = rtb_referencearea * Spike_P.Constant2_Value *
    Spike_P.u2rhoV2_Gain;

  /* Gain: '<S4>/reference area' */
  rtb_referencearea = Spike_P.AerodynamicForcesandMoments_S *
    rtb_referencearea_k;
  Spike_emxInit_char_T(&s, 2);
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* MATLAB Function: '<Root>/Read Aileron' */
    Spike_readfile(s);
    latestData = Spike_lastStr2double(s);

    /* PreLookup: '<S2>/(deltal)' incorporates:
     *  MATLAB Function: '<Root>/Read Aileron'
     *  UnitConversion: '<S40>/Unit Conversion'
     */
    /* Unit Conversion - from: rad to: deg
       Expression: output = (57.2958*input) + (0) */
    Spike_B.idxdelL = plook_s32dd_binxp(latestData * 0.2618 / 100.0 *
      57.295779513082323, Spike_P.deltal_BreakpointsData, 8U, &Spike_B.fdelL,
      &Spike_DW.deltal_DWORK1);
  }

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S102>/Product'
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
    Spike_emxInit_char_T(&b_s, 2);
    Spike_emxInit_boolean_T(&x, 2);
    Spike_emxInit_boolean_T(&tmp, 2);

    /* MATLAB Function: '<Root>/Read Tail right' */
    Spike_readfile_b(s);
    Spike_deblank(s, b_s);
    Spike_isspace(b_s, tmp);
    iU = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = tmp->size[1];
    Spi_emxEnsureCapacity_boolean_T(x, iU);
    k = tmp->size[0] * tmp->size[1];
    for (iU = 0; iU < k; iU++) {
      x->data[iU] = tmp->data[iU];
    }

    Spike_emxFree_boolean_T(&tmp);

    /* MATLAB Function: '<Root>/Read Tail right' */
    k = (1 <= x->size[1]);
    idx = 0;
    rtb_idxh_p = x->size[1];
    exitg1 = false;
    while ((!exitg1) && (rtb_idxh_p > 0)) {
      if (x->data[rtb_idxh_p - 1]) {
        idx = 1;
        ii_data = rtb_idxh_p;
        exitg1 = true;
      } else {
        rtb_idxh_p--;
      }
    }

    if (k == 1) {
      if (idx == 0) {
        k = 0;
      }
    } else {
      k = (1 <= idx);
    }

    if (0 <= k - 1) {
      rtb_ixk = ii_data;
    }

    Spike_emxInit_char_T(&tmp_0, 2);
    Spike_emxInit_boolean_T(&tmp_1, 2);

    /* MATLAB Function: '<Root>/Read Tail right' */
    Spike_string_extractAfter(b_s, &rtb_ixk, tmp_0);
    tmp_3 = Spike_str2double(tmp_0);

    /* MATLAB Function: '<Root>/Read Tail left' */
    Spike_readfile_e(s);
    Spike_deblank(s, b_s);
    Spike_isspace(b_s, tmp_1);
    iU = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = tmp_1->size[1];
    Spi_emxEnsureCapacity_boolean_T(x, iU);
    k = tmp_1->size[0] * tmp_1->size[1];
    Spike_emxFree_char_T(&tmp_0);

    /* MATLAB Function: '<Root>/Read Tail left' */
    for (iU = 0; iU < k; iU++) {
      x->data[iU] = tmp_1->data[iU];
    }

    Spike_emxFree_boolean_T(&tmp_1);

    /* MATLAB Function: '<Root>/Read Tail left' */
    k = (1 <= x->size[1]);
    idx = 0;
    rtb_idxh_p = x->size[1];
    exitg1 = false;
    while ((!exitg1) && (rtb_idxh_p > 0)) {
      if (x->data[rtb_idxh_p - 1]) {
        idx = 1;
        ii_data = rtb_idxh_p;
        exitg1 = true;
      } else {
        rtb_idxh_p--;
      }
    }

    Spike_emxFree_boolean_T(&x);

    /* MATLAB Function: '<Root>/Read Tail left' */
    if (k == 1) {
      if (idx == 0) {
        k = 0;
      }
    } else {
      k = (1 <= idx);
    }

    if (0 <= k - 1) {
      rtb_ixk = ii_data;
    }

    Spike_emxInit_char_T(&tmp_2, 2);

    /* MATLAB Function: '<Root>/Read Tail left' */
    Spike_string_extractAfter(b_s, &rtb_ixk, tmp_2);
    tmp_4 = Spike_str2double(tmp_2);

    /* PreLookup: '<S2>/(delta)' incorporates:
     *  Gain: '<S2>/Gain1'
     *  MATLAB Function: '<Root>/Read Tail left'
     *  MATLAB Function: '<Root>/Read Tail right'
     *  MATLAB Function: '<Root>/SeperateYawAndPitch'
     *  UnitConversion: '<S39>/Unit Conversion'
     */
    /* Unit Conversion - from: rad to: deg
       Expression: output = (57.2958*input) + (0) */
    Spike_B.idxde = plook_s32dd_binxp((tmp_3.re - tmp_4.re) / 1.4142135623730951
      * 0.436 / 100.0 * Spike_P.Gain1_Gain * 57.295779513082323,
      Spike_P.delta_BreakpointsData, 6U, &Spike_B.fde, &Spike_DW.delta_DWORK1);
    Spike_emxFree_char_T(&tmp_2);
    Spike_emxFree_char_T(&b_s);
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
  latestData = intrp3d_s32dl_pw(bpIndex_2, frac_2, Spike_P.DCL_Table,
    Spike_P.DCL_dimSize);

  /* Interpolation_n-D: '<S36>/DCm' */
  frac_3[0] = Spike_B.fde;
  frac_3[1] = rtb_fm;
  frac_3[2] = rtb_fh;
  bpIndex_3[0] = Spike_B.idxde;
  bpIndex_3[1] = rtb_idxm;
  bpIndex_3[2] = rtb_idxh;
  latestData_0 = intrp3d_s32dl_pw(bpIndex_3, frac_3, Spike_P.DCm_Table,
    Spike_P.DCm_dimSize);

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S37>/Constant1'
   */
  rtb_Sum_d_idx_3 = (rtb_Sideslip_c + Spike_P.Constant1_Value_l) +
    Spike_P.Constant1_Value_n;
  rtb_Sum_d_idx_4 = (Spike_P.Constant1_Value + latestData_0) +
    Spike_P.Constant1_Value_n;
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
  frac[2] = ((Spike_P.Constant1_Value + latestData) + Spike_P.Constant1_Value_n)
    * Spike_P.coefAdjust_Gain[2] * rtb_referencearea;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* MATLAB Function: '<Root>/Read Throttle' */
    Spike_readfile_a(s);
    latestData = Spike_lastStr2double(s);

    /* MATLAB Function: '<Root>/propulsion' incorporates:
     *  MATLAB Function: '<Root>/Read Throttle'
     */
    Spike_B.forces[0] = latestData / 100.0 * 2200.0;
    Spike_B.forces[1] = 0.0;
    Spike_B.forces[2] = 0.0;
  }

  Spike_emxFree_char_T(&s);

  /* Trigonometry: '<S25>/sincos' incorporates:
   *  Integrator: '<S17>/phi theta psi'
   *  SignalConversion generated from: '<S25>/sincos'
   *  Trigonometry: '<S26>/sincos'
   */
  rtb_Sum1_idx_0 = std::cos(Spike_X.phithetapsi_CSTATE[2]);
  frac_2[0] = std::sin(Spike_X.phithetapsi_CSTATE[2]);
  rtb_Sum1_idx_1_tmp = std::cos(Spike_X.phithetapsi_CSTATE[1]);
  frac_tmp_0 = std::sin(Spike_X.phithetapsi_CSTATE[1]);
  rtb_Sum1_idx_2_tmp = std::cos(Spike_X.phithetapsi_CSTATE[0]);
  frac_tmp = std::sin(Spike_X.phithetapsi_CSTATE[0]);

  /* Fcn: '<S25>/Fcn11' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[0] = rtb_Sum1_idx_1_tmp * rtb_Sum1_idx_0;

  /* Fcn: '<S25>/Fcn21' incorporates:
   *  Fcn: '<S25>/Fcn22'
   *  Trigonometry: '<S25>/sincos'
   */
  latestData_0 = frac_tmp * frac_tmp_0;
  VectorConcatenate[1] = latestData_0 * rtb_Sum1_idx_0 - rtb_Sum1_idx_2_tmp *
    frac_2[0];

  /* Fcn: '<S25>/Fcn31' incorporates:
   *  Fcn: '<S25>/Fcn32'
   *  Trigonometry: '<S25>/sincos'
   */
  latestData = rtb_Sum1_idx_2_tmp * frac_tmp_0;
  VectorConcatenate[2] = latestData * rtb_Sum1_idx_0 + frac_tmp * frac_2[0];

  /* Fcn: '<S25>/Fcn12' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[3] = rtb_Sum1_idx_1_tmp * frac_2[0];

  /* Fcn: '<S25>/Fcn22' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[4] = latestData_0 * frac_2[0] + rtb_Sum1_idx_2_tmp *
    rtb_Sum1_idx_0;

  /* Fcn: '<S25>/Fcn32' incorporates:
   *  Trigonometry: '<S25>/sincos'
   */
  VectorConcatenate[5] = latestData * frac_2[0] - frac_tmp * rtb_Sum1_idx_0;

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
   *  Product: '<S7>/Product'
   */
  rtb_Sum1_idx_0 = Spike_X.ubvbwb_CSTATE[1] / rtb_Gain2;
  latestData = rtb_Sum1_idx_0;

  /* Trigonometry: '<S63>/Sideslip' incorporates:
   *  Product: '<S63>/Product'
   */
  if (rtb_Sum1_idx_0 > 1.0) {
    latestData = 1.0;
  } else {
    if (rtb_Sum1_idx_0 < -1.0) {
      latestData = -1.0;
    }
  }

  /* SignalConversion generated from: '<S62>/sincos' incorporates:
   *  Trigonometry: '<S63>/Sideslip'
   */
  rtb_jxi = std::asin(latestData);

  /* Trigonometry: '<S62>/sincos' incorporates:
   *  Trigonometry: '<S7>/Incidence'
   */
  latestData_0 = std::cos(rtb_kxj_tmp);
  latestData = std::sin(rtb_kxj_tmp);
  rtb_Sideslip_c = std::cos(rtb_jxi);
  rtb_jxi = std::sin(rtb_jxi);

  /* Product: '<S64>/u(3)*u(4)' */
  Spike_B.VectorConcatenate_n[0] = latestData_0 * rtb_Sideslip_c;

  /* UnaryMinus: '<S67>/Unary Minus' incorporates:
   *  Product: '<S67>/u(2)*u(3)'
   */
  Spike_B.VectorConcatenate_n[1] = -(rtb_jxi * latestData_0);

  /* UnaryMinus: '<S70>/Unary Minus' */
  Spike_B.VectorConcatenate_n[2] = -latestData;

  /* SignalConversion generated from: '<S73>/Vector Concatenate' */
  Spike_B.VectorConcatenate_n[3] = rtb_jxi;

  /* SignalConversion generated from: '<S73>/Vector Concatenate' */
  Spike_B.VectorConcatenate_n[4] = rtb_Sideslip_c;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Constant: '<S71>/Constant' */
    Spike_B.VectorConcatenate_n[5] = Spike_P.Constant_Value;
  }

  /* Product: '<S66>/u(1)*u(4)' */
  Spike_B.VectorConcatenate_n[6] = latestData * rtb_Sideslip_c;

  /* UnaryMinus: '<S69>/Unary Minus' incorporates:
   *  Product: '<S69>/u(1)*u(2)'
   */
  Spike_B.VectorConcatenate_n[7] = -(latestData * rtb_jxi);

  /* SignalConversion generated from: '<S73>/Vector Concatenate' */
  Spike_B.VectorConcatenate_n[8] = latestData_0;

  /* Gain: '<S3>/reference area' */
  rtb_referencearea_k *= Spike_P.AerodynamicForcesandMoments_S_g;

  /* UnitConversion: '<S5>/Unit Conversion' */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  latestData_0 = 57.295779513082323 * Gain;

  /* PreLookup: '<Root>/(alpha)' */
  k = plook_s32dd_binxp(latestData_0, Spike_P.alpha_BreakpointsData_d, 11U,
                        &latestData_0, &Spike_DW.alpha_DWORK1_n);

  /* PreLookup: '<Root>/(Mach)' */
  idx = plook_s32dd_binxp(rtb_fm_n, Spike_P.Mach_BreakpointsData_e, 2U,
    &rtb_fm_n, &Spike_DW.Mach_DWORK1_m);

  /* PreLookup: '<Root>/(altitude)' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   */
  rtb_idxh_p = plook_s32dd_binxp(Spike_X.xeyeze_CSTATE[2],
    Spike_P.altitude_BreakpointsData_i, 2U, &latestData,
    &Spike_DW.altitude_DWORK1_p);

  /* Interpolation_n-D: '<Root>/CD' */
  frac_4[0] = latestData_0;
  frac_4[1] = rtb_fm_n;
  frac_4[2] = latestData;
  bpIndex_4[0] = k;
  bpIndex_4[1] = idx;
  bpIndex_4[2] = rtb_idxh_p;
  rtb_ixk = intrp3d_s32dl_pw(bpIndex_4, frac_4, Spike_P.CD_Table,
    Spike_P.CD_dimSize);

  /* Interpolation_n-D: '<Root>/CYb' */
  frac_5[0] = latestData_0;
  frac_5[1] = rtb_fm_n;
  frac_5[2] = latestData;
  bpIndex_5[0] = k;
  bpIndex_5[1] = idx;
  bpIndex_5[2] = rtb_idxh_p;
  rtb_jxi = intrp3d_s32dl_pw(bpIndex_5, frac_5, Spike_P.CYb_Table,
    Spike_P.CYb_dimSize);

  /* Trigonometry: '<S7>/Sideslip' */
  if (rtb_Sum1_idx_0 > 1.0) {
    rtb_Sum1_idx_0 = 1.0;
  } else {
    if (rtb_Sum1_idx_0 < -1.0) {
      rtb_Sum1_idx_0 = -1.0;
    }
  }

  rtb_Sideslip_c = std::asin(rtb_Sum1_idx_0);

  /* End of Trigonometry: '<S7>/Sideslip' */

  /* Product: '<Root>/Product2' */
  rtb_jxi *= rtb_Sideslip_c;

  /* Interpolation_n-D: '<Root>/CL' */
  frac_6[0] = latestData_0;
  frac_6[1] = rtb_fm_n;
  frac_6[2] = latestData;
  bpIndex_6[0] = k;
  bpIndex_6[1] = idx;
  bpIndex_6[2] = rtb_idxh_p;
  rtb_kxj = intrp3d_s32dl_pw(bpIndex_6, frac_6, Spike_P.CL_Table,
    Spike_P.CL_dimSize);

  /* Gain: '<Root>/Gain1' */
  rtb_kxj *= Spike_P.Gain1_Gain_e;

  /* Product: '<S3>/Product' incorporates:
   *  Gain: '<S3>/coefAdjust'
   */
  rtb_Sum1_idx_0 = Spike_P.coefAdjust_Gain_h[0] * rtb_ixk * rtb_referencearea_k;
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
  for (iU = 0; iU < 3; iU++) {
    /* Sum: '<S1>/Sum' incorporates:
     *  MATLAB Function: '<Root>/gravity'
     */
    VectorConcatenate_0 = VectorConcatenate[iU + 3];
    rtb_ixk = VectorConcatenate[iU] * 0.0 + VectorConcatenate_0 * 0.0;

    /* MATLAB Function: '<Root>/WriteToFile' incorporates:
     *  MATLAB Function: '<Root>/gravity'
     *  Sum: '<S1>/Sum'
     */
    frac_b = VectorConcatenate_0 * 0.0 + VectorConcatenate[iU] * 0.0;

    /* Sum: '<S1>/Sum' incorporates:
     *  MATLAB Function: '<Root>/gravity'
     */
    VectorConcatenate_0 = VectorConcatenate[iU + 6];
    rtb_ixk += VectorConcatenate_0 * -7840.0000000000009;

    /* MATLAB Function: '<Root>/WriteToFile' */
    frac_b += VectorConcatenate_0 * -9.8;

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S19>/Constant'
     *  MATLAB Function: '<Root>/gravity'
     *  Math: '<S43>/Transpose'
     *  Product: '<S1>/Product'
     *  Product: '<S43>/Product'
     *  Sum: '<Root>/Add'
     */
    Spike_B.Sum[iU] = (((frac[iU] + Spike_B.forces[iU]) + rtb_ixk) +
                       (Spike_B.VectorConcatenate_n[3 * iU + 2] * rtb_kxj +
                        (Spike_B.VectorConcatenate_n[3 * iU + 1] * rtb_jxi +
                         Spike_B.VectorConcatenate_n[3 * iU] * rtb_Sum1_idx_0)))
      / Spike_P.uDOFEulerAngles_mass_0 + frac_2[iU];

    /* MATLAB Function: '<Root>/WriteToFile' */
    frac_4[iU] = frac_b;
  }

  /* MATLAB Function: '<Root>/WriteToFile' incorporates:
   *  Integrator: '<S17>/phi theta psi'
   *  Integrator: '<S1>/p,q,r '
   *  Integrator: '<S1>/xe,ye,ze'
   *  Sqrt: '<S7>/Airspeed'
   */
  fileid = Spike_cfopen_e("SensorOutputs/airspeed.txt", "ab");
  b_fileid = Spike_cfopen_e("SensorOutputs/angleOfAttack.txt", "ab");
  c_fileid = Spike_cfopen_e("SensorOutputs/altitude.txt", "ab");
  d_fileid = Spike_cfopen_e("SensorOutputs/roll.txt", "ab");
  e_fileid = Spike_cfopen_e("SensorOutputs/pitch.txt", "ab");
  f_fileid = Spike_cfopen_e("SensorOutputs/yaw.txt", "ab");
  g_fileid = Spike_cfopen_e("SensorOutputs/accX.txt", "ab");
  h_fileid = Spike_cfopen_e("SensorOutputs/accY.txt", "ab");
  i_fileid = Spike_cfopen_e("SensorOutputs/accZ.txt", "ab");
  j_fileid = Spike_cfopen_e("SensorOutputs/gyrX.txt", "ab");
  k_fileid = Spike_cfopen_e("SensorOutputs/gyrY.txt", "ab");
  l_fileid = Spike_cfopen_e("SensorOutputs/gyrZ.txt", "ab");
  b_NULL = NULL;
  if ((fileid > 22) || (fileid < 0)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_g[fileid - 3];
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
    fprintf(f, "%f\n", rtb_Gain2);
    if (a) {
      fflush(f);
    }
  }

  b_NULL = NULL;
  if ((b_fileid > 22) || (b_fileid < 0)) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = Spike_DW.eml_openfiles_g[b_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[c_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[d_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[e_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[f_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[g_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[h_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[i_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[j_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[k_fileid - 3];
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
    f = Spike_DW.eml_openfiles_g[l_fileid - 3];
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

  for (iU = 0; iU < 20; iU++) {
    if (Spike_DW.eml_openfiles_g[iU] != NULL) {
      ii_data = fclose(Spike_DW.eml_openfiles_g[iU]);
      if (ii_data == 0) {
        Spike_DW.eml_openfiles_g[iU] = NULL;
        Spike_DW.eml_autoflush[iU] = true;
      }
    }
  }

  /* Fcn: '<S26>/phidot' incorporates:
   *  Fcn: '<S26>/psidot'
   *  Integrator: '<S1>/p,q,r '
   */
  rtb_Gain2 = Spike_X.pqr_CSTATE[1] * frac_tmp;

  /* SignalConversion generated from: '<S17>/phi theta psi' incorporates:
   *  Fcn: '<S26>/phidot'
   *  Fcn: '<S26>/psidot'
   *  Fcn: '<S26>/thetadot'
   *  Integrator: '<S1>/p,q,r '
   */
  Spike_B.TmpSignalConversionAtphithetaps[0] = (rtb_Gain2 + Spike_X.pqr_CSTATE[2]
    * rtb_Sum1_idx_2_tmp) * (frac_tmp_0 / rtb_Sum1_idx_1_tmp) +
    Spike_X.pqr_CSTATE[0];
  Spike_B.TmpSignalConversionAtphithetaps[1] = Spike_X.pqr_CSTATE[1] *
    rtb_Sum1_idx_2_tmp - Spike_X.pqr_CSTATE[2] * frac_tmp;
  Spike_B.TmpSignalConversionAtphithetaps[2] = (rtb_Gain2 + Spike_X.pqr_CSTATE[2]
    * rtb_Sum1_idx_2_tmp) / rtb_Sum1_idx_1_tmp;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    for (iU = 0; iU < 3; iU++) {
      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       */
      rtb_VectorConcatenate[6 * iU] = Spike_P.uDOFEulerAngles_inertia[3 * iU];
      rtb_VectorConcatenate[6 * iU + 3] = Spike_P.Constant2_Value_f[3 * iU];

      /* Selector: '<S18>/Selector' */
      Spike_B.Selector[3 * iU] = rtb_VectorConcatenate[6 * iU];

      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       *  Selector: '<S18>/Selector'
       */
      ii_data = 3 * iU + 1;
      rtb_VectorConcatenate_tmp = 6 * iU + 1;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp] =
        Spike_P.uDOFEulerAngles_inertia[ii_data];
      rtb_VectorConcatenate[6 * iU + 4] = Spike_P.Constant2_Value_f[ii_data];

      /* Selector: '<S18>/Selector' */
      Spike_B.Selector[ii_data] =
        rtb_VectorConcatenate[rtb_VectorConcatenate_tmp];

      /* Concatenate: '<S19>/Vector Concatenate' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Constant: '<S19>/Constant2'
       *  Selector: '<S18>/Selector'
       */
      ii_data = 3 * iU + 2;
      rtb_VectorConcatenate_tmp = 6 * iU + 2;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp] =
        Spike_P.uDOFEulerAngles_inertia[ii_data];
      rtb_VectorConcatenate[6 * iU + 5] = Spike_P.Constant2_Value_f[ii_data];

      /* Selector: '<S18>/Selector' */
      Spike_B.Selector[ii_data] =
        rtb_VectorConcatenate[rtb_VectorConcatenate_tmp];
    }
  }

  /* Product: '<S29>/Product' incorporates:
   *  Integrator: '<S1>/p,q,r '
   */
  for (iU = 0; iU < 3; iU++) {
    frac_2[iU] = Spike_B.Selector[iU + 6] * Spike_X.pqr_CSTATE[2] +
      (Spike_B.Selector[iU + 3] * Spike_X.pqr_CSTATE[1] + Spike_B.Selector[iU] *
       Spike_X.pqr_CSTATE[0]);
  }

  /* End of Product: '<S29>/Product' */

  /* Product: '<S31>/j x k' */
  rtb_ixk = frac_2[2];

  /* Product: '<S31>/k x i' */
  rtb_Gain2 = frac_2[0];

  /* Product: '<S31>/i x j' */
  Gain = frac_2[1];

  /* Product: '<S32>/k x j' */
  frac_tmp_0 = frac_2[1];

  /* Product: '<S32>/i x k' */
  rtb_Sum1_idx_1_tmp = frac_2[2];

  /* Product: '<S32>/j x i' */
  rtb_Sum1_idx_2_tmp = frac_2[0];

  /* Sum: '<S28>/Sum' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  Product: '<S31>/i x j'
   *  Product: '<S31>/j x k'
   *  Product: '<S31>/k x i'
   *  Product: '<S32>/i x k'
   *  Product: '<S32>/j x i'
   *  Product: '<S32>/k x j'
   */
  frac_2[0] = Spike_X.pqr_CSTATE[1] * rtb_ixk - Spike_X.pqr_CSTATE[2] *
    frac_tmp_0;
  frac_2[1] = Spike_X.pqr_CSTATE[2] * rtb_Gain2 - Spike_X.pqr_CSTATE[0] *
    rtb_Sum1_idx_1_tmp;
  frac_2[2] = Spike_X.pqr_CSTATE[0] * Gain - Spike_X.pqr_CSTATE[1] *
    rtb_Sum1_idx_2_tmp;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Selector: '<S18>/Selector1' */
    for (iU = 0; iU < 3; iU++) {
      Spike_B.Selector1[3 * iU] = rtb_VectorConcatenate[6 * iU + 3];
      Spike_B.Selector1[3 * iU + 1] = rtb_VectorConcatenate[6 * iU + 4];
      Spike_B.Selector1[3 * iU + 2] = rtb_VectorConcatenate[6 * iU + 5];
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

  /* Sum: '<S92>/Sum' incorporates:
   *  Constant: '<S2>/zero1'
   *  Product: '<S96>/j x k'
   *  Product: '<S96>/k x i'
   *  Sum: '<S4>/Sum'
   */
  rtb_fh = (0.0 - Spike_P.zero1_Value) * frac[1];
  rtb_fm = (0.0 - rtb_Gain) * frac[2];

  /* Product: '<S96>/i x j' incorporates:
   *  Constant: '<S2>/zero1'
   *  Product: '<S97>/i x k'
   *  Sum: '<S4>/Sum'
   */
  rtb_Sum1_idx_1_tmp = (0.0 - Spike_P.zero1_Value) * frac[0];

  /* Sum: '<S92>/Sum' incorporates:
   *  Constant: '<S2>/zero1'
   *  Product: '<S97>/j x i'
   *  Product: '<S97>/k x j'
   *  Sum: '<S4>/Sum'
   */
  rtb_Sum1_idx_2_tmp = (0.0 - Spike_P.zero1_Value) * frac[2];
  rtb_Gain = (0.0 - rtb_Gain) * frac[1];

  /* Product: '<S78>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S91>/Product'
   *  Product: '<S91>/Product1'
   *  Product: '<S91>/Product2'
   *  Sqrt: '<S78>/Airspeed'
   *  Sum: '<S91>/Sum'
   */
  rtb_Gain2 = Spike_X.ubvbwb_CSTATE[1] / std::sqrt((Spike_X.ubvbwb_CSTATE[0] *
    Spike_X.ubvbwb_CSTATE[0] + Spike_X.ubvbwb_CSTATE[1] * Spike_X.ubvbwb_CSTATE
    [1]) + Spike_X.ubvbwb_CSTATE[2] * Spike_X.ubvbwb_CSTATE[2]);

  /* Trigonometry: '<S78>/Sideslip' */
  if (rtb_Gain2 > 1.0) {
    rtb_Gain2 = 1.0;
  } else {
    if (rtb_Gain2 < -1.0) {
      rtb_Gain2 = -1.0;
    }
  }

  /* SignalConversion generated from: '<S77>/sincos' incorporates:
   *  SignalConversion generated from: '<S47>/sincos'
   *  Trigonometry: '<S78>/Sideslip'
   */
  Gain = std::asin(rtb_Gain2);

  /* Trigonometry: '<S77>/sincos' incorporates:
   *  SignalConversion generated from: '<S77>/sincos'
   *  Trigonometry: '<S47>/sincos'
   */
  rtb_Gain2 = std::cos(rtb_kxj_tmp);
  rtb_kxj_tmp = std::sin(rtb_kxj_tmp);
  frac_tmp_0 = std::cos(Gain);
  Gain = std::sin(Gain);

  /* Product: '<S79>/u(3)*u(4)' incorporates:
   *  Trigonometry: '<S77>/sincos'
   */
  Spike_B.VectorConcatenate_i[0] = rtb_Gain2 * frac_tmp_0;

  /* UnaryMinus: '<S82>/Unary Minus' incorporates:
   *  Product: '<S82>/u(2)*u(3)'
   *  Trigonometry: '<S77>/sincos'
   */
  Spike_B.VectorConcatenate_i[1] = -(Gain * rtb_Gain2);

  /* UnaryMinus: '<S85>/Unary Minus' incorporates:
   *  Trigonometry: '<S77>/sincos'
   */
  Spike_B.VectorConcatenate_i[2] = -rtb_kxj_tmp;

  /* SignalConversion generated from: '<S88>/Vector Concatenate' incorporates:
   *  Trigonometry: '<S77>/sincos'
   */
  Spike_B.VectorConcatenate_i[3] = Gain;

  /* SignalConversion generated from: '<S88>/Vector Concatenate' incorporates:
   *  Trigonometry: '<S77>/sincos'
   */
  Spike_B.VectorConcatenate_i[4] = frac_tmp_0;
  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Constant: '<S86>/Constant' */
    Spike_B.VectorConcatenate_i[5] = Spike_P.Constant_Value_l;
  }

  /* Product: '<S81>/u(1)*u(4)' incorporates:
   *  Trigonometry: '<S77>/sincos'
   */
  Spike_B.VectorConcatenate_i[6] = rtb_kxj_tmp * frac_tmp_0;

  /* UnaryMinus: '<S84>/Unary Minus' incorporates:
   *  Product: '<S84>/u(1)*u(2)'
   *  Trigonometry: '<S77>/sincos'
   */
  Spike_B.VectorConcatenate_i[7] = -(rtb_kxj_tmp * Gain);

  /* SignalConversion generated from: '<S88>/Vector Concatenate' incorporates:
   *  Trigonometry: '<S77>/sincos'
   */
  Spike_B.VectorConcatenate_i[8] = rtb_Gain2;

  /* Product: '<S49>/u(3)*u(4)' */
  Spike_B.VectorConcatenate_m[0] = rtb_Gain2 * frac_tmp_0;

  /* UnaryMinus: '<S52>/Unary Minus' incorporates:
   *  Product: '<S52>/u(2)*u(3)'
   */
  Spike_B.VectorConcatenate_m[1] = -(Gain * rtb_Gain2);

  /* UnaryMinus: '<S55>/Unary Minus' */
  Spike_B.VectorConcatenate_m[2] = -rtb_kxj_tmp;

  /* SignalConversion generated from: '<S58>/Vector Concatenate' */
  Spike_B.VectorConcatenate_m[3] = Gain;

  /* SignalConversion generated from: '<S58>/Vector Concatenate' */
  Spike_B.VectorConcatenate_m[4] = frac_tmp_0;
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
  Spike_B.VectorConcatenate_m[6] = rtb_kxj_tmp * frac_tmp_0;

  /* UnaryMinus: '<S54>/Unary Minus' incorporates:
   *  Product: '<S54>/u(1)*u(2)'
   */
  Spike_B.VectorConcatenate_m[7] = -(rtb_kxj_tmp * Gain);

  /* SignalConversion generated from: '<S58>/Vector Concatenate' */
  Spike_B.VectorConcatenate_m[8] = rtb_Gain2;

  /* Product: '<S42>/Product' */
  for (iU = 0; iU < 3; iU++) {
    frac[iU] = Spike_B.VectorConcatenate_m[iU + 6] * Spike_B.Sum_j[2] +
      (Spike_B.VectorConcatenate_m[iU + 3] * Spike_B.Sum_j[1] +
       Spike_B.VectorConcatenate_m[iU] * Spike_B.Sum_j[0]);
  }

  /* End of Product: '<S42>/Product' */

  /* Sum: '<S41>/Sum' incorporates:
   *  Product: '<S45>/i x j'
   *  Product: '<S45>/j x k'
   *  Product: '<S45>/k x i'
   *  Product: '<S46>/i x k'
   *  Product: '<S46>/j x i'
   *  Product: '<S46>/k x j'
   */
  rtb_kxj_tmp = rtb_jxi * frac[2];
  frac_tmp_0 = rtb_kxj * frac[0];
  frac_tmp = rtb_Sum1_idx_0 * frac[1];
  rtb_kxj *= frac[1];
  rtb_ixk = rtb_Sum1_idx_0 * frac[2];
  VectorConcatenate_0 = rtb_jxi * frac[0];

  /* Interpolation_n-D: '<Root>/Clb' */
  frac_8[0] = latestData_0;
  frac_8[1] = rtb_fm_n;
  frac_8[2] = latestData;
  bpIndex_8[0] = k;
  bpIndex_8[1] = idx;
  bpIndex_8[2] = rtb_idxh_p;
  rtb_Gain2 = intrp3d_s32dl_pw(bpIndex_8, frac_8, Spike_P.Clb_Table,
    Spike_P.Clb_dimSize);

  /* Product: '<Root>/Product1' */
  rtb_Gain2 *= rtb_Sideslip_c;

  /* Interpolation_n-D: '<Root>/Cm' */
  frac_9[0] = latestData_0;
  frac_9[1] = rtb_fm_n;
  frac_9[2] = latestData;
  bpIndex_9[0] = k;
  bpIndex_9[1] = idx;
  bpIndex_9[2] = rtb_idxh_p;
  Gain = intrp3d_s32dl_pw(bpIndex_9, frac_9, Spike_P.Cm_Table,
    Spike_P.Cm_dimSize);

  /* Interpolation_n-D: '<Root>/Cnb' */
  frac_a[0] = latestData_0;
  frac_a[1] = rtb_fm_n;
  frac_a[2] = latestData;
  bpIndex_a[0] = k;
  bpIndex_a[1] = idx;
  bpIndex_a[2] = rtb_idxh_p;
  latestData_0 = intrp3d_s32dl_pw(bpIndex_a, frac_a, Spike_P.Cnb_Table,
    Spike_P.Cnb_dimSize);

  /* Product: '<Root>/Product3' */
  latestData_0 *= rtb_Sideslip_c;

  /* Product: '<S3>/Product1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_fm_n = Spike_P.AerodynamicForcesandMoments_b_h * rtb_referencearea_k;

  /* Sum: '<S41>/Sum' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product3'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Sum1_idx_0 = rtb_fm_n * rtb_Gain2 + (rtb_kxj_tmp - rtb_kxj);
  rtb_jxi = Spike_P.AerodynamicForcesandMoments_c_h * rtb_referencearea_k * Gain
    + (frac_tmp_0 - rtb_ixk);

  /* Sum: '<S3>/Sum1' incorporates:
   *  Product: '<S3>/Product3'
   *  Sum: '<S41>/Sum'
   */
  rtb_referencearea_k = rtb_fm_n * latestData_0 + (frac_tmp -
    VectorConcatenate_0);

  /* Product: '<S44>/Product' incorporates:
   *  Math: '<S44>/Transpose'
   */
  for (iU = 0; iU < 3; iU++) {
    frac[iU] = Spike_B.VectorConcatenate_i[3 * iU + 2] * rtb_referencearea_k +
      (Spike_B.VectorConcatenate_i[3 * iU + 1] * rtb_jxi +
       Spike_B.VectorConcatenate_i[3 * iU] * rtb_Sum1_idx_0);
  }

  /* End of Product: '<S44>/Product' */

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  frac_tmp_0 = Spike_P.AerodynamicForcesandMoments_b * rtb_referencearea;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Gain: '<Root>/Gain2'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product3'
   *  Product: '<S96>/i x j'
   *  Sum: '<S4>/Sum1'
   *  Sum: '<S92>/Sum'
   */
  frac_7[0] = (frac_tmp_0 * rtb_Sum_d_idx_3 + (rtb_fh - rtb_Sum1_idx_2_tmp)) +
    frac[0];
  frac_7[1] = (Spike_P.AerodynamicForcesandMoments_cba * rtb_referencearea *
               rtb_Sum_d_idx_4 + (rtb_fm - rtb_Sum1_idx_1_tmp)) +
    Spike_P.Gain2_Gain * frac[1];
  frac_7[2] = (frac_tmp_0 * rtb_Sum_d_idx_5 + (rtb_Sum1_idx_1_tmp - rtb_Gain)) +
    frac[2];
  for (iU = 0; iU < 3; iU++) {
    /* Sum: '<S18>/Sum2' incorporates:
     *  Integrator: '<S1>/p,q,r '
     *  Product: '<S30>/Product'
     */
    frac_7[iU] = (frac_7[iU] - (Spike_B.Selector1[iU + 6] * Spike_X.pqr_CSTATE[2]
      + (Spike_B.Selector1[iU + 3] * Spike_X.pqr_CSTATE[1] +
         Spike_B.Selector1[iU] * Spike_X.pqr_CSTATE[0]))) - frac_2[iU];
  }

  if (rtmIsMajorTimeStep((&Spike_M))) {
    /* Selector: '<S18>/Selector2' */
    for (iU = 0; iU < 3; iU++) {
      Spike_B.Selector2[3 * iU] = rtb_VectorConcatenate[6 * iU];
      Spike_B.Selector2[3 * iU + 1] = rtb_VectorConcatenate[6 * iU + 1];
      Spike_B.Selector2[3 * iU + 2] = rtb_VectorConcatenate[6 * iU + 2];
    }

    /* End of Selector: '<S18>/Selector2' */
  }

  /* Product: '<S18>/Product2' */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(frac_7, Spike_B.Selector2, Spike_B.Product2);

  /* Product: '<S24>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Math: '<S1>/Transpose'
   */
  for (iU = 0; iU < 3; iU++) {
    Spike_B.Product[iU] = 0.0;
    Spike_B.Product[iU] += VectorConcatenate[3 * iU] * Spike_X.ubvbwb_CSTATE[0];
    Spike_B.Product[iU] += VectorConcatenate[3 * iU + 1] *
      Spike_X.ubvbwb_CSTATE[1];
    Spike_B.Product[iU] += VectorConcatenate[3 * iU + 2] *
      Spike_X.ubvbwb_CSTATE[2];
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
  (&Spike_M)->contStates = ((X_Spike_T *) &Spike_X);
  (&Spike_M)->periodicContStateIndices = ((int_T*) Spike_PeriodicIndX);
  (&Spike_M)->periodicContStateRanges = ((real_T*) Spike_PeriodicRngX);
  rtsiSetSolverData(&(&Spike_M)->solverInfo, static_cast<void *>(&(&Spike_M)
    ->intgData));
  rtsiSetSolverName(&(&Spike_M)->solverInfo,"ode3");
  rtmSetTPtr((&Spike_M), &(&Spike_M)->Timing.tArray[0]);
  (&Spike_M)->Timing.stepSize0 = 0.02;

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
      Spike_DW.eml_openfiles_l[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Tail right' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Tail left' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_j[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Tail left' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_m[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */

    /* SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_g[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */

    /* InitializeConditions for root-level periodic continuous states */
    {
      int_T rootPeriodicContStateIndices[3] = { 6, 7, 8 };

      real_T rootPeriodicContStateRanges[6] = { -3.1415926535897931,
        3.1415926535897931, -3.1415926535897931, 3.1415926535897931,
        -3.1415926535897931, 3.1415926535897931 };

      (void) std::memcpy((void*)Spike_PeriodicIndX, rootPeriodicContStateIndices,
                         3*sizeof(int_T));
      (void) std::memcpy((void*)Spike_PeriodicRngX, rootPeriodicContStateRanges,
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
SpikeModelClass::SpikeModelClass():
  Spike_B()
  ,Spike_DW()
  ,Spike_X()
  ,Spike_PeriodicIndX()
  ,Spike_PeriodicRngX()
  ,Spike_M()
{
  /* Currently there is no constructor body generated.*/
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
