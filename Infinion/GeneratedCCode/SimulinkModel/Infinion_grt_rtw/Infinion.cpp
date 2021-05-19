/*
 * Infinion.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Infinion".
 *
 * Model version              : 3.30
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Wed May 19 19:08:54 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Infinion.h"
#include "Infinion_private.h"

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
  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       3,
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

    y = std::atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
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
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
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
  int32_T k;
  int8_T f;
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
int8_T InfinionModelClass::Infinion_cfopen(const char_T *cfilename, const char_T
  *cpermission)
{
  FILE * filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Infinion_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
real_T InfinionModelClass::Infinion_fileManager(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen("ActuatorCommands/aileron.txt", "rb");
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
FILE * InfinionModelClass::Infinion_fileManager_b(real_T varargin_1)
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

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_fseek(real_T fileID)
{
  FILE * filestar;
  int wherefrom;
  wherefrom = SEEK_END;
  filestar = Infinion_fileManager_b(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
real_T InfinionModelClass::Infinion_ftell(real_T fileID)
{
  FILE * filestar;
  long position_t;
  real_T position;
  filestar = Infinion_fileManager_b(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(filestar);
    position = (real_T)position_t;
  }

  return position;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_fseek_m(real_T fileID)
{
  FILE * filestar;
  int wherefrom;
  wherefrom = SEEK_SET;
  filestar = Infinion_fileManager_b(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
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

void InfinionModelClass::Infinion_emxInit_uint8_T1(emxArray_uint8_T_Infinion_T **
  pEmxArray, int32_T numDimensions)
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

void InfinionModelClass::Infi_emxEnsureCapacity_uint8_T1
  (emxArray_uint8_T_Infinion_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
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

void InfinionModelClass::Infin_emxEnsureCapacity_uint8_T
  (emxArray_uint8_T_Infinion_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
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

void InfinionModelClass::Infini_emxEnsureCapacity_real_T
  (emxArray_real_T_Infinion_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
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
void InfinionModelClass::Infinion_fread(real_T fileID, int32_T sizeA,
  emxArray_real_T_Infinion_T *A, real_T *count)
{
  FILE * filestar;
  size_t nBytes;
  size_t numReadSizeT;
  emxArray_uint8_T_Infinion_T *At;
  emxArray_uint8_T_Infinion_T *b_At;
  int32_T bdims_idx_0;
  int32_T buf_size_idx_0;
  int32_T bytesOut;
  int32_T c;
  int32_T c_numRead;
  int32_T d_numRead;
  int32_T num2Read;
  char_T buf_data[1024];
  boolean_T doEOF;
  if (sizeA >= MAX_int32_T) {
    c = 1024;
    doEOF = true;
  } else {
    c = sizeA;
    doEOF = false;
  }

  nBytes = sizeof(char_T);
  filestar = Infinion_fileManager_b(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  Infinion_emxInit_uint8_T(&At, 2);
  Infinion_emxInit_uint8_T1(&b_At, 1);
  if (!doEOF) {
    if (filestar == NULL) {
      A->size[0] = 0;
      bytesOut = 0;
    } else {
      num2Read = A->size[0];
      A->size[0] = sizeA;
      Infini_emxEnsureCapacity_real_T(A, num2Read);
      if (c > 1024) {
        bdims_idx_0 = 1024;
      } else {
        bdims_idx_0 = c;
      }

      bytesOut = 0;
      c_numRead = 1;
      buf_size_idx_0 = bdims_idx_0;
      while ((bytesOut < c) && (c_numRead > 0)) {
        num2Read = buf_size_idx_0;
        c_numRead = c - bytesOut;
        if (buf_size_idx_0 > c_numRead) {
          num2Read = c_numRead;
        }

        buf_size_idx_0 = static_cast<int16_T>(bdims_idx_0);
        c_numRead = 0;
        d_numRead = 1;
        while ((c_numRead < num2Read) && (d_numRead > 0)) {
          numReadSizeT = fread(&buf_data[c_numRead], nBytes, num2Read -
                               c_numRead, filestar);
          d_numRead = (int32_T)numReadSizeT;
          c_numRead += (int32_T)numReadSizeT;
        }

        for (num2Read = 0; num2Read < c_numRead; num2Read++) {
          A->data[num2Read + bytesOut] = static_cast<uint8_T>(buf_data[num2Read]);
        }

        bytesOut += c_numRead;
      }

      c = A->size[0];
      for (c_numRead = bytesOut; c_numRead < c; c_numRead++) {
        A->data[c_numRead] = 0.0;
      }

      if (bytesOut < sizeA) {
        if (1 > bytesOut) {
          A->size[0] = 0;
        } else {
          num2Read = A->size[0];
          A->size[0] = bytesOut;
          Infini_emxEnsureCapacity_real_T(A, num2Read);
        }
      }
    }
  } else {
    At->size[0] = 0;
    At->size[1] = 1;
    if (filestar == NULL) {
      bytesOut = 0;
    } else {
      c = 1;
      bytesOut = 0;
      while (c > 0) {
        c = 0;
        c_numRead = 1;
        while ((c < 1024) && (c_numRead > 0)) {
          numReadSizeT = fread(&buf_data[c], nBytes, 1024 - c, filestar);
          c_numRead = (int32_T)numReadSizeT;
          c += (int32_T)numReadSizeT;
        }

        if (1 > c) {
          c_numRead = -1;
        } else {
          c_numRead = c - 1;
        }

        num2Read = b_At->size[0];
        b_At->size[0] = (At->size[0] + c_numRead) + 1;
        Infi_emxEnsureCapacity_uint8_T1(b_At, num2Read);
        bdims_idx_0 = At->size[0];
        for (num2Read = 0; num2Read < bdims_idx_0; num2Read++) {
          b_At->data[num2Read] = At->data[num2Read];
        }

        for (num2Read = 0; num2Read <= c_numRead; num2Read++) {
          b_At->data[num2Read + At->size[0]] = static_cast<uint8_T>
            (buf_data[num2Read]);
        }

        num2Read = At->size[0] * At->size[1];
        At->size[0] = b_At->size[0];
        At->size[1] = 1;
        Infin_emxEnsureCapacity_uint8_T(At, num2Read);
        c_numRead = b_At->size[0] - 1;
        for (num2Read = 0; num2Read <= c_numRead; num2Read++) {
          At->data[num2Read] = b_At->data[num2Read];
        }

        bytesOut += c;
      }
    }

    num2Read = A->size[0];
    A->size[0] = At->size[0];
    Infini_emxEnsureCapacity_real_T(A, num2Read);
    c_numRead = At->size[0];
    for (num2Read = 0; num2Read < c_numRead; num2Read++) {
      A->data[num2Read] = At->data[num2Read];
    }
  }

  Infinion_emxFree_uint8_T(&b_At);
  Infinion_emxFree_uint8_T(&At);
  *count = bytesOut;
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
int32_T InfinionModelClass::Infinion_cfclose(real_T fid)
{
  FILE * f;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
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
  int32_T i;
  int32_T newNumel;
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
void InfinionModelClass::Infinion_char(const emxArray_uint8_T_Infinion_T
  *varargin_1, emxArray_char_T_Infinion_T *y)
{
  int32_T i;
  int32_T loop_ub;
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_1->size[1];
  Infini_emxEnsureCapacity_char_T(y, i);
  loop_ub = varargin_1->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    y->data[i] = static_cast<int8_T>(varargin_1->data[i]);
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_readfile(emxArray_char_T_Infinion_T *y)
{
  emxArray_real_T_Infinion_T *dataRead;
  emxArray_uint8_T_Infinion_T *buffer;
  real_T f;
  real_T nread;
  real_T tmp;
  int32_T b_index;
  int32_T i;
  int32_T n;
  int32_T qY;
  int32_T remaining;
  int32_T tmp_0;
  boolean_T exitg1;
  f = Infinion_fileManager();
  Infinion_fseek(f);
  tmp = rt_roundd_snf(Infinion_ftell(f));
  if (tmp < 2.147483648E+9) {
    if (tmp >= -2.147483648E+9) {
      i = static_cast<int32_T>(tmp);
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  Infinion_fseek_m(f);
  std::memset(&Infinion_B.buffer[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Infinion_emxInit_real_T(&dataRead, 1);
  exitg1 = false;
  while ((!exitg1) && (remaining > 0)) {
    if (b_index > MAX_int32_T - remaining) {
      n = MAX_int32_T;
    } else {
      n = remaining + b_index;
    }

    if (n > 65536) {
      printf("Attempt to read file which is bigger than internal buffer.\n");
      fflush(stdout);
      printf("Current buffer size is %d bytes and file size is %d bytes.\n",
             65536, i);
      fflush(stdout);
      exitg1 = true;
    } else {
      Infinion_fread(f, remaining, dataRead, &nread);
      tmp = rt_roundd_snf(static_cast<real_T>(b_index) + nread);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          n = static_cast<int32_T>(tmp);
        } else {
          n = MIN_int32_T;
        }
      } else {
        n = MAX_int32_T;
      }

      if (n < -2147483647) {
        qY = MIN_int32_T;
      } else {
        qY = n - 1;
      }

      if (b_index > qY) {
        n = -1;
        qY = 0;
      } else {
        n = b_index - 2;
      }

      tmp_0 = (qY - n) - 1;
      for (qY = 0; qY < tmp_0; qY++) {
        tmp = rt_roundd_snf(dataRead->data[qY]);
        if (tmp < 256.0) {
          if (tmp >= 0.0) {
            Infinion_B.buffer[(n + qY) + 1] = static_cast<uint8_T>(tmp);
          } else {
            Infinion_B.buffer[(n + qY) + 1] = 0U;
          }
        } else {
          Infinion_B.buffer[(n + qY) + 1] = MAX_uint8_T;
        }
      }

      tmp = rt_roundd_snf(nread);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          n = static_cast<int32_T>(tmp);
        } else {
          n = MIN_int32_T;
        }
      } else {
        n = MAX_int32_T;
      }

      if (n == 0) {
        exitg1 = true;
      } else if (n < 0) {
        printf("Could not read from file: %d.\n", n);
        fflush(stdout);
        exitg1 = true;
      } else {
        remaining -= n;
        if ((b_index < 0) && (n < MIN_int32_T - b_index)) {
          b_index = MIN_int32_T;
        } else if ((b_index > 0) && (n > MAX_int32_T - b_index)) {
          b_index = MAX_int32_T;
        } else {
          b_index += n;
        }
      }
    }
  }

  Infinion_emxFree_real_T(&dataRead);
  Infinion_emxInit_uint8_T(&buffer, 2);
  Infinion_cfclose(f);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  buffer->size[1] = b_index;
  Infin_emxEnsureCapacity_uint8_T(buffer, i);
  for (i = 0; i < b_index; i++) {
    buffer->data[i] = Infinion_B.buffer[i];
  }

  Infinion_char(buffer, y);
  Infinion_emxFree_uint8_T(&buffer);
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
  int32_T i;
  int32_T ncols;
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

  boolean_T exitg1;
  ncols = x->size[1] - 1;
  exitg1 = false;
  while ((!exitg1) && (ncols + 1 > 0)) {
    i = static_cast<uint8_T>(x->data[ncols]);
    if ((i != 0) && (!c[i & 127])) {
      exitg1 = true;
    } else {
      ncols--;
    }
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
  int32_T i;
  int32_T newNumel;
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
void InfinionModelClass::Infinion_extractAfter(const emxArray_char_T_Infinion_T *
  str, const real_T pos_data[], emxArray_char_T_Infinion_T *s)
{
  int32_T b;
  int32_T c;
  int32_T i;
  c = static_cast<int32_T>(pos_data[0]);
  if (c + 1 > str->size[1]) {
    c = 0;
    b = 0;
  } else {
    b = str->size[1];
  }

  i = s->size[0] * s->size[1];
  s->size[0] = 1;
  b -= c;
  s->size[1] = b;
  Infini_emxEnsureCapacity_char_T(s, i);
  for (i = 0; i < b; i++) {
    s->data[i] = str->data[c + i];
  }
}

void InfinionModelClass::Infinion_emxInit_real_T1(emxArray_real_T_Infinion_T
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

void InfinionModelClass::Infin_emxEnsureCapacity_real_T1
  (emxArray_real_T_Infinion_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
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
void InfinionModelClass::Infinion_char_b(const emxArray_real_T_Infinion_T
  *varargin_1, emxArray_char_T_Infinion_T *y)
{
  real_T u;
  int32_T loop_ub;
  int32_T u_tmp;
  u_tmp = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = varargin_1->size[1];
  Infini_emxEnsureCapacity_char_T(y, u_tmp);
  loop_ub = varargin_1->size[1] - 1;
  for (u_tmp = 0; u_tmp <= loop_ub; u_tmp++) {
    u = varargin_1->data[u_tmp];
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

    y->data[u_tmp] = static_cast<int8_T>(u < 0.0 ? static_cast<int32_T>(
      static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-u)))) :
      static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(u))));
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
int32_T InfinionModelClass::Infinion_skipspaces(const emxArray_char_T_Infinion_T
  *s, int32_T n)
{
  int32_T k;
  char_T tmp;
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
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k <= n)) {
    tmp = s->data[k - 1];
    if (b[static_cast<uint8_T>(tmp) & 127] || (tmp == '\x00')) {
      k++;
    } else {
      exitg1 = true;
    }
  }

  return k;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_copysign(emxArray_char_T_Infinion_T *s1,
  int32_T *idx, const emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n,
  boolean_T *foundsign, boolean_T *success)
{
  char_T tmp;
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
    tmp = s->data[*k - 1];
    if (tmp == '-') {
      isneg = !isneg;
      *foundsign = true;
      (*k)++;
    } else if (tmp == ',') {
      (*k)++;
    } else if (tmp == '+') {
      *foundsign = true;
      (*k)++;
    } else if (!b[static_cast<uint8_T>(tmp) & 127]) {
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
  int32_T b_k;
  char_T c_idx_0;
  char_T c_idx_1;
  char_T c_idx_2;
  boolean_T p;
  p = false;
  if (k <= n) {
    c_idx_0 = s->data[k - 1];
    if (c_idx_0 == 'j') {
      p = true;
    } else if (c_idx_0 == 'i') {
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
  char_T tmp;
  boolean_T exitg1;
  boolean_T haspoint;
  boolean_T success;
  success = (*k <= n);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (*k <= n))) {
    tmp = s->data[*k - 1];
    if ((tmp >= '0') && (tmp <= '9')) {
      s1->data[*idx - 1] = tmp;
      (*idx)++;
      (*k)++;
    } else if (tmp == '.') {
      success = (allowpoint && (!haspoint));
      if (success) {
        s1->data[*idx - 1] = '.';
        (*idx)++;
        haspoint = true;
      }

      (*k)++;
    } else if (tmp == ',') {
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
  int32_T b_k;
  int32_T kexp;
  char_T tmp;
  boolean_T b_success;
  boolean_T success;
  success = true;
  if (*k <= n) {
    tmp = s->data[*k - 1];
    if ((tmp == 'E') || (tmp == 'e')) {
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
        } else if (s->data[*k - 1] == '+') {
          (*k)++;
        }
      }

      kexp = *k;
      b_k = *k;
      b_success = Infinion_copydigits(s1, idx, s, &b_k, n, false);
      *k = b_k;
      success = (b_success && (b_k > kexp));
    }
  }

  return success;
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_skipspaces_k(const emxArray_char_T_Infinion_T *
  s, int32_T *k, int32_T n)
{
  char_T tmp;
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
  exitg1 = false;
  while ((!exitg1) && (*k <= n)) {
    tmp = s->data[*k - 1];
    if (b[static_cast<uint8_T>(tmp) & 127] || (tmp == '\x00') || (tmp == ',')) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }
}

/* Function for MATLAB Function: '<Root>/Read Aileron' */
void InfinionModelClass::Infinion_readfloat(emxArray_char_T_Infinion_T *s1,
  int32_T *idx, const emxArray_char_T_Infinion_T *s, int32_T *k, int32_T n,
  boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite, real_T *nfv,
  boolean_T *foundsign, boolean_T *success)
{
  int32_T b_idx;
  int32_T b_k;
  char_T tmp;
  boolean_T a__2;
  boolean_T a__3;
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
        Infinion_skipspaces_k(s, k, n);
        if ((*k <= n) && (s->data[*k - 1] == '*')) {
          (*k)++;
          Infinion_readfloat(s1, idx, s, k, n, false, &a__2, b_finite, nfv,
                             &a__3, success);
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
      } else if ((b_idx >= 2) && (s1->data[b_idx - 2] == '-')) {
        *idx = b_idx - 1;
        s1->data[b_idx - 2] = ' ';
        *nfv = -*nfv;
      }

      Infinion_skipspaces_k(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Infinion_skipspaces_k(s, k, n);
      }

      if (*k <= n) {
        tmp = s->data[*k - 1];
        if ((tmp == 'i') || (tmp == 'j')) {
          (*k)++;
          *isimag = true;
        }
      }
    }

    Infinion_skipspaces_k(s, k, n);
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
  emxArray_char_T_Infinion_T *s1;
  emxArray_real_T_Infinion_T *tmp;
  creal_T x;
  real_T b_scanned1;
  real_T scanned1;
  real_T scanned2;
  int32_T idx;
  int32_T k;
  int32_T ntoread;
  boolean_T a__1;
  boolean_T c_success;
  boolean_T foundsign;
  boolean_T isfinite1;
  boolean_T isimag1;
  boolean_T success;
  x.re = (rtNaN);
  x.im = 0.0;
  if (s->size[1] >= 1) {
    Infinion_emxInit_real_T1(&tmp, 2);
    ntoread = 0;
    idx = s->size[1] + 2;
    k = tmp->size[0] * tmp->size[1];
    tmp->size[0] = 1;
    tmp->size[1] = s->size[1] + 2;
    Infin_emxEnsureCapacity_real_T1(tmp, k);
    for (k = 0; k < idx; k++) {
      tmp->data[k] = 0.0;
    }

    Infinion_emxInit_char_T(&s1, 2);
    Infinion_char_b(tmp, s1);
    idx = 1;
    k = Infinion_skipspaces(s, s->size[1]);
    Infinion_readfloat(s1, &idx, s, &k, s->size[1], true, &isimag1, &isfinite1,
                       &scanned1, &a__1, &success);
    Infinion_emxFree_real_T(&tmp);
    if (isfinite1) {
      ntoread = 1;
    }

    if (success && (k <= s->size[1])) {
      s1->data[idx - 1] = ' ';
      idx++;
      Infinion_readfloat(s1, &idx, s, &k, s->size[1], true, &a__1, &success,
                         &scanned2, &foundsign, &c_success);
      if (success) {
        ntoread++;
      }

      if (c_success && (k > s->size[1]) && ((isimag1 != a__1) && foundsign)) {
        success = true;
      } else {
        success = false;
      }
    } else {
      scanned2 = 0.0;
    }

    if (success) {
      s1->data[idx - 1] = '\x00';
      if (ntoread == 2) {
        ntoread = sscanf(&s1->data[0], "%lf %lf", &scanned1, &scanned2);
        if (ntoread != 2) {
          scanned1 = (rtNaN);
          scanned2 = (rtNaN);
        }
      } else if (ntoread == 1) {
        ntoread = sscanf(&s1->data[0], "%lf", &b_scanned1);
        if (isfinite1) {
          if (ntoread == 1) {
            scanned1 = b_scanned1;
          } else {
            scanned1 = (rtNaN);
          }
        } else if (ntoread == 1) {
          scanned2 = b_scanned1;
        } else {
          scanned2 = (rtNaN);
        }
      }

      if (isimag1) {
        x.re = scanned2;
        x.im = scanned1;
      } else {
        x.re = scanned1;
        x.im = scanned2;
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
  emxArray_boolean_T_Infinion_T *tmp;
  emxArray_boolean_T_Infinion_T *x;
  emxArray_char_T_Infinion_T *s;
  emxArray_char_T_Infinion_T *tmp_1;
  creal_T tmp_0;
  real_T C;
  real_T ii_data_0;
  int32_T b_ii;
  int32_T idx;
  int32_T ii_data;
  int32_T k;
  boolean_T exitg1;
  Infinion_emxInit_char_T(&s, 2);
  Infinion_emxInit_boolean_T(&x, 2);
  Infinion_emxInit_boolean_T(&tmp, 2);
  Infinion_deblank(str, s);
  Infinion_isspace(s, tmp);
  b_ii = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = tmp->size[1];
  Inf_emxEnsureCapacity_boolean_T(x, b_ii);
  k = tmp->size[1];
  for (idx = 0; idx < k; idx++) {
    x->data[idx] = tmp->data[idx];
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

  Infinion_emxInit_char_T(&tmp_1, 2);
  Infinion_extractAfter(s, &ii_data_0, tmp_1);
  tmp_0 = Infinion_str2double(tmp_1);
  C = tmp_0.re;
  Infinion_emxFree_char_T(&tmp_1);
  Infinion_emxFree_char_T(&s);
  return C;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
int8_T InfinionModelClass::Infinion_filedata_d(void)
{
  int32_T k;
  int8_T f;
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

/* Function for MATLAB Function: '<Root>/Read Elevator' */
int8_T InfinionModelClass::Infinion_cfopen_l(const char_T *cfilename, const
  char_T *cpermission)
{
  FILE * filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Infinion_filedata_d();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles_m[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
real_T InfinionModelClass::Infinion_fileManager_bt(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_l("ActuatorCommands/elevator.txt", "rb");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
FILE * InfinionModelClass::Infinion_fileManager_btz(real_T varargin_1)
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

/* Function for MATLAB Function: '<Root>/Read Elevator' */
void InfinionModelClass::Infinion_fseek_o(real_T fileID)
{
  FILE * filestar;
  int wherefrom;
  wherefrom = SEEK_END;
  filestar = Infinion_fileManager_btz(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
real_T InfinionModelClass::Infinion_ftell_f(real_T fileID)
{
  FILE * filestar;
  long position_t;
  real_T position;
  filestar = Infinion_fileManager_btz(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(filestar);
    position = (real_T)position_t;
  }

  return position;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
void InfinionModelClass::Infinion_fseek_ox(real_T fileID)
{
  FILE * filestar;
  int wherefrom;
  wherefrom = SEEK_SET;
  filestar = Infinion_fileManager_btz(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
void InfinionModelClass::Infinion_fread_e(real_T fileID, int32_T sizeA,
  emxArray_real_T_Infinion_T *A, real_T *count)
{
  FILE * filestar;
  size_t nBytes;
  size_t numReadSizeT;
  emxArray_uint8_T_Infinion_T *At;
  emxArray_uint8_T_Infinion_T *b_At;
  int32_T bdims_idx_0;
  int32_T buf_size_idx_0;
  int32_T bytesOut;
  int32_T c;
  int32_T c_numRead;
  int32_T d_numRead;
  int32_T num2Read;
  char_T buf_data[1024];
  boolean_T doEOF;
  if (sizeA >= MAX_int32_T) {
    c = 1024;
    doEOF = true;
  } else {
    c = sizeA;
    doEOF = false;
  }

  nBytes = sizeof(char_T);
  filestar = Infinion_fileManager_btz(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  Infinion_emxInit_uint8_T(&At, 2);
  Infinion_emxInit_uint8_T1(&b_At, 1);
  if (!doEOF) {
    if (filestar == NULL) {
      A->size[0] = 0;
      bytesOut = 0;
    } else {
      num2Read = A->size[0];
      A->size[0] = sizeA;
      Infini_emxEnsureCapacity_real_T(A, num2Read);
      if (c > 1024) {
        bdims_idx_0 = 1024;
      } else {
        bdims_idx_0 = c;
      }

      bytesOut = 0;
      c_numRead = 1;
      buf_size_idx_0 = bdims_idx_0;
      while ((bytesOut < c) && (c_numRead > 0)) {
        num2Read = buf_size_idx_0;
        c_numRead = c - bytesOut;
        if (buf_size_idx_0 > c_numRead) {
          num2Read = c_numRead;
        }

        buf_size_idx_0 = static_cast<int16_T>(bdims_idx_0);
        c_numRead = 0;
        d_numRead = 1;
        while ((c_numRead < num2Read) && (d_numRead > 0)) {
          numReadSizeT = fread(&buf_data[c_numRead], nBytes, num2Read -
                               c_numRead, filestar);
          d_numRead = (int32_T)numReadSizeT;
          c_numRead += (int32_T)numReadSizeT;
        }

        for (num2Read = 0; num2Read < c_numRead; num2Read++) {
          A->data[num2Read + bytesOut] = static_cast<uint8_T>(buf_data[num2Read]);
        }

        bytesOut += c_numRead;
      }

      c = A->size[0];
      for (c_numRead = bytesOut; c_numRead < c; c_numRead++) {
        A->data[c_numRead] = 0.0;
      }

      if (bytesOut < sizeA) {
        if (1 > bytesOut) {
          A->size[0] = 0;
        } else {
          num2Read = A->size[0];
          A->size[0] = bytesOut;
          Infini_emxEnsureCapacity_real_T(A, num2Read);
        }
      }
    }
  } else {
    At->size[0] = 0;
    At->size[1] = 1;
    if (filestar == NULL) {
      bytesOut = 0;
    } else {
      c = 1;
      bytesOut = 0;
      while (c > 0) {
        c = 0;
        c_numRead = 1;
        while ((c < 1024) && (c_numRead > 0)) {
          numReadSizeT = fread(&buf_data[c], nBytes, 1024 - c, filestar);
          c_numRead = (int32_T)numReadSizeT;
          c += (int32_T)numReadSizeT;
        }

        if (1 > c) {
          c_numRead = -1;
        } else {
          c_numRead = c - 1;
        }

        num2Read = b_At->size[0];
        b_At->size[0] = (At->size[0] + c_numRead) + 1;
        Infi_emxEnsureCapacity_uint8_T1(b_At, num2Read);
        bdims_idx_0 = At->size[0];
        for (num2Read = 0; num2Read < bdims_idx_0; num2Read++) {
          b_At->data[num2Read] = At->data[num2Read];
        }

        for (num2Read = 0; num2Read <= c_numRead; num2Read++) {
          b_At->data[num2Read + At->size[0]] = static_cast<uint8_T>
            (buf_data[num2Read]);
        }

        num2Read = At->size[0] * At->size[1];
        At->size[0] = b_At->size[0];
        At->size[1] = 1;
        Infin_emxEnsureCapacity_uint8_T(At, num2Read);
        c_numRead = b_At->size[0] - 1;
        for (num2Read = 0; num2Read <= c_numRead; num2Read++) {
          At->data[num2Read] = b_At->data[num2Read];
        }

        bytesOut += c;
      }
    }

    num2Read = A->size[0];
    A->size[0] = At->size[0];
    Infini_emxEnsureCapacity_real_T(A, num2Read);
    c_numRead = At->size[0];
    for (num2Read = 0; num2Read < c_numRead; num2Read++) {
      A->data[num2Read] = At->data[num2Read];
    }
  }

  Infinion_emxFree_uint8_T(&b_At);
  Infinion_emxFree_uint8_T(&At);
  *count = bytesOut;
}

/* Function for MATLAB Function: '<Root>/Read Elevator' */
int32_T InfinionModelClass::Infinion_cfclose_k(real_T fid)
{
  FILE * f;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
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

/* Function for MATLAB Function: '<Root>/Read Elevator' */
void InfinionModelClass::Infinion_readfile_n(emxArray_char_T_Infinion_T *y)
{
  emxArray_real_T_Infinion_T *dataRead;
  emxArray_uint8_T_Infinion_T *buffer;
  real_T f;
  real_T nread;
  real_T tmp;
  int32_T b_index;
  int32_T i;
  int32_T n;
  int32_T qY;
  int32_T remaining;
  int32_T tmp_0;
  boolean_T exitg1;
  f = Infinion_fileManager_bt();
  Infinion_fseek_o(f);
  tmp = rt_roundd_snf(Infinion_ftell_f(f));
  if (tmp < 2.147483648E+9) {
    if (tmp >= -2.147483648E+9) {
      i = static_cast<int32_T>(tmp);
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  Infinion_fseek_ox(f);
  std::memset(&Infinion_B.buffer_m[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Infinion_emxInit_real_T(&dataRead, 1);
  exitg1 = false;
  while ((!exitg1) && (remaining > 0)) {
    if (b_index > MAX_int32_T - remaining) {
      n = MAX_int32_T;
    } else {
      n = remaining + b_index;
    }

    if (n > 65536) {
      printf("Attempt to read file which is bigger than internal buffer.\n");
      fflush(stdout);
      printf("Current buffer size is %d bytes and file size is %d bytes.\n",
             65536, i);
      fflush(stdout);
      exitg1 = true;
    } else {
      Infinion_fread_e(f, remaining, dataRead, &nread);
      tmp = rt_roundd_snf(static_cast<real_T>(b_index) + nread);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          n = static_cast<int32_T>(tmp);
        } else {
          n = MIN_int32_T;
        }
      } else {
        n = MAX_int32_T;
      }

      if (n < -2147483647) {
        qY = MIN_int32_T;
      } else {
        qY = n - 1;
      }

      if (b_index > qY) {
        n = -1;
        qY = 0;
      } else {
        n = b_index - 2;
      }

      tmp_0 = (qY - n) - 1;
      for (qY = 0; qY < tmp_0; qY++) {
        tmp = rt_roundd_snf(dataRead->data[qY]);
        if (tmp < 256.0) {
          if (tmp >= 0.0) {
            Infinion_B.buffer_m[(n + qY) + 1] = static_cast<uint8_T>(tmp);
          } else {
            Infinion_B.buffer_m[(n + qY) + 1] = 0U;
          }
        } else {
          Infinion_B.buffer_m[(n + qY) + 1] = MAX_uint8_T;
        }
      }

      tmp = rt_roundd_snf(nread);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          n = static_cast<int32_T>(tmp);
        } else {
          n = MIN_int32_T;
        }
      } else {
        n = MAX_int32_T;
      }

      if (n == 0) {
        exitg1 = true;
      } else if (n < 0) {
        printf("Could not read from file: %d.\n", n);
        fflush(stdout);
        exitg1 = true;
      } else {
        remaining -= n;
        if ((b_index < 0) && (n < MIN_int32_T - b_index)) {
          b_index = MIN_int32_T;
        } else if ((b_index > 0) && (n > MAX_int32_T - b_index)) {
          b_index = MAX_int32_T;
        } else {
          b_index += n;
        }
      }
    }
  }

  Infinion_emxFree_real_T(&dataRead);
  Infinion_emxInit_uint8_T(&buffer, 2);
  Infinion_cfclose_k(f);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  buffer->size[1] = b_index;
  Infin_emxEnsureCapacity_uint8_T(buffer, i);
  for (i = 0; i < b_index; i++) {
    buffer->data[i] = Infinion_B.buffer_m[i];
  }

  Infinion_char(buffer, y);
  Infinion_emxFree_uint8_T(&buffer);
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
int8_T InfinionModelClass::Infinion_filedata_c(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Infinion_DW.eml_openfiles_o[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
int8_T InfinionModelClass::Infinion_cfopen_b(const char_T *cfilename, const
  char_T *cpermission)
{
  FILE * filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Infinion_filedata_c();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles_o[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
real_T InfinionModelClass::Infinion_fileManager_p(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_b("ActuatorCommands/rudder.txt", "rb");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
FILE * InfinionModelClass::Infinion_fileManager_pw(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Infinion_DW.eml_openfiles_o[fileid - 3];
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
void InfinionModelClass::Infinion_fseek_k(real_T fileID)
{
  FILE * filestar;
  int wherefrom;
  wherefrom = SEEK_END;
  filestar = Infinion_fileManager_pw(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
real_T InfinionModelClass::Infinion_ftell_i(real_T fileID)
{
  FILE * filestar;
  long position_t;
  real_T position;
  filestar = Infinion_fileManager_pw(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(filestar);
    position = (real_T)position_t;
  }

  return position;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
void InfinionModelClass::Infinion_fseek_kz(real_T fileID)
{
  FILE * filestar;
  int wherefrom;
  wherefrom = SEEK_SET;
  filestar = Infinion_fileManager_pw(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
void InfinionModelClass::Infinion_fread_g(real_T fileID, int32_T sizeA,
  emxArray_real_T_Infinion_T *A, real_T *count)
{
  FILE * filestar;
  size_t nBytes;
  size_t numReadSizeT;
  emxArray_uint8_T_Infinion_T *At;
  emxArray_uint8_T_Infinion_T *b_At;
  int32_T bdims_idx_0;
  int32_T buf_size_idx_0;
  int32_T bytesOut;
  int32_T c;
  int32_T c_numRead;
  int32_T d_numRead;
  int32_T num2Read;
  char_T buf_data[1024];
  boolean_T doEOF;
  if (sizeA >= MAX_int32_T) {
    c = 1024;
    doEOF = true;
  } else {
    c = sizeA;
    doEOF = false;
  }

  nBytes = sizeof(char_T);
  filestar = Infinion_fileManager_pw(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  Infinion_emxInit_uint8_T(&At, 2);
  Infinion_emxInit_uint8_T1(&b_At, 1);
  if (!doEOF) {
    if (filestar == NULL) {
      A->size[0] = 0;
      bytesOut = 0;
    } else {
      num2Read = A->size[0];
      A->size[0] = sizeA;
      Infini_emxEnsureCapacity_real_T(A, num2Read);
      if (c > 1024) {
        bdims_idx_0 = 1024;
      } else {
        bdims_idx_0 = c;
      }

      bytesOut = 0;
      c_numRead = 1;
      buf_size_idx_0 = bdims_idx_0;
      while ((bytesOut < c) && (c_numRead > 0)) {
        num2Read = buf_size_idx_0;
        c_numRead = c - bytesOut;
        if (buf_size_idx_0 > c_numRead) {
          num2Read = c_numRead;
        }

        buf_size_idx_0 = static_cast<int16_T>(bdims_idx_0);
        c_numRead = 0;
        d_numRead = 1;
        while ((c_numRead < num2Read) && (d_numRead > 0)) {
          numReadSizeT = fread(&buf_data[c_numRead], nBytes, num2Read -
                               c_numRead, filestar);
          d_numRead = (int32_T)numReadSizeT;
          c_numRead += (int32_T)numReadSizeT;
        }

        for (num2Read = 0; num2Read < c_numRead; num2Read++) {
          A->data[num2Read + bytesOut] = static_cast<uint8_T>(buf_data[num2Read]);
        }

        bytesOut += c_numRead;
      }

      c = A->size[0];
      for (c_numRead = bytesOut; c_numRead < c; c_numRead++) {
        A->data[c_numRead] = 0.0;
      }

      if (bytesOut < sizeA) {
        if (1 > bytesOut) {
          A->size[0] = 0;
        } else {
          num2Read = A->size[0];
          A->size[0] = bytesOut;
          Infini_emxEnsureCapacity_real_T(A, num2Read);
        }
      }
    }
  } else {
    At->size[0] = 0;
    At->size[1] = 1;
    if (filestar == NULL) {
      bytesOut = 0;
    } else {
      c = 1;
      bytesOut = 0;
      while (c > 0) {
        c = 0;
        c_numRead = 1;
        while ((c < 1024) && (c_numRead > 0)) {
          numReadSizeT = fread(&buf_data[c], nBytes, 1024 - c, filestar);
          c_numRead = (int32_T)numReadSizeT;
          c += (int32_T)numReadSizeT;
        }

        if (1 > c) {
          c_numRead = -1;
        } else {
          c_numRead = c - 1;
        }

        num2Read = b_At->size[0];
        b_At->size[0] = (At->size[0] + c_numRead) + 1;
        Infi_emxEnsureCapacity_uint8_T1(b_At, num2Read);
        bdims_idx_0 = At->size[0];
        for (num2Read = 0; num2Read < bdims_idx_0; num2Read++) {
          b_At->data[num2Read] = At->data[num2Read];
        }

        for (num2Read = 0; num2Read <= c_numRead; num2Read++) {
          b_At->data[num2Read + At->size[0]] = static_cast<uint8_T>
            (buf_data[num2Read]);
        }

        num2Read = At->size[0] * At->size[1];
        At->size[0] = b_At->size[0];
        At->size[1] = 1;
        Infin_emxEnsureCapacity_uint8_T(At, num2Read);
        c_numRead = b_At->size[0] - 1;
        for (num2Read = 0; num2Read <= c_numRead; num2Read++) {
          At->data[num2Read] = b_At->data[num2Read];
        }

        bytesOut += c;
      }
    }

    num2Read = A->size[0];
    A->size[0] = At->size[0];
    Infini_emxEnsureCapacity_real_T(A, num2Read);
    c_numRead = At->size[0];
    for (num2Read = 0; num2Read < c_numRead; num2Read++) {
      A->data[num2Read] = At->data[num2Read];
    }
  }

  Infinion_emxFree_uint8_T(&b_At);
  Infinion_emxFree_uint8_T(&At);
  *count = bytesOut;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
int32_T InfinionModelClass::Infinion_cfclose_h(real_T fid)
{
  FILE * f;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
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
    f = Infinion_DW.eml_openfiles_o[b_fileid - 3];
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
      Infinion_DW.eml_openfiles_o[fileid - 3] = NULL;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<Root>/Read Rudder' */
void InfinionModelClass::Infinion_readfile_a(emxArray_char_T_Infinion_T *y)
{
  emxArray_real_T_Infinion_T *dataRead;
  emxArray_uint8_T_Infinion_T *buffer;
  real_T f;
  real_T nread;
  real_T tmp;
  int32_T b_index;
  int32_T i;
  int32_T n;
  int32_T qY;
  int32_T remaining;
  int32_T tmp_0;
  boolean_T exitg1;
  f = Infinion_fileManager_p();
  Infinion_fseek_k(f);
  tmp = rt_roundd_snf(Infinion_ftell_i(f));
  if (tmp < 2.147483648E+9) {
    if (tmp >= -2.147483648E+9) {
      i = static_cast<int32_T>(tmp);
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  Infinion_fseek_kz(f);
  std::memset(&Infinion_B.buffer_c[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Infinion_emxInit_real_T(&dataRead, 1);
  exitg1 = false;
  while ((!exitg1) && (remaining > 0)) {
    if (b_index > MAX_int32_T - remaining) {
      n = MAX_int32_T;
    } else {
      n = remaining + b_index;
    }

    if (n > 65536) {
      printf("Attempt to read file which is bigger than internal buffer.\n");
      fflush(stdout);
      printf("Current buffer size is %d bytes and file size is %d bytes.\n",
             65536, i);
      fflush(stdout);
      exitg1 = true;
    } else {
      Infinion_fread_g(f, remaining, dataRead, &nread);
      tmp = rt_roundd_snf(static_cast<real_T>(b_index) + nread);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          n = static_cast<int32_T>(tmp);
        } else {
          n = MIN_int32_T;
        }
      } else {
        n = MAX_int32_T;
      }

      if (n < -2147483647) {
        qY = MIN_int32_T;
      } else {
        qY = n - 1;
      }

      if (b_index > qY) {
        n = -1;
        qY = 0;
      } else {
        n = b_index - 2;
      }

      tmp_0 = (qY - n) - 1;
      for (qY = 0; qY < tmp_0; qY++) {
        tmp = rt_roundd_snf(dataRead->data[qY]);
        if (tmp < 256.0) {
          if (tmp >= 0.0) {
            Infinion_B.buffer_c[(n + qY) + 1] = static_cast<uint8_T>(tmp);
          } else {
            Infinion_B.buffer_c[(n + qY) + 1] = 0U;
          }
        } else {
          Infinion_B.buffer_c[(n + qY) + 1] = MAX_uint8_T;
        }
      }

      tmp = rt_roundd_snf(nread);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          n = static_cast<int32_T>(tmp);
        } else {
          n = MIN_int32_T;
        }
      } else {
        n = MAX_int32_T;
      }

      if (n == 0) {
        exitg1 = true;
      } else if (n < 0) {
        printf("Could not read from file: %d.\n", n);
        fflush(stdout);
        exitg1 = true;
      } else {
        remaining -= n;
        if ((b_index < 0) && (n < MIN_int32_T - b_index)) {
          b_index = MIN_int32_T;
        } else if ((b_index > 0) && (n > MAX_int32_T - b_index)) {
          b_index = MAX_int32_T;
        } else {
          b_index += n;
        }
      }
    }
  }

  Infinion_emxFree_real_T(&dataRead);
  Infinion_emxInit_uint8_T(&buffer, 2);
  Infinion_cfclose_h(f);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  buffer->size[1] = b_index;
  Infin_emxEnsureCapacity_uint8_T(buffer, i);
  for (i = 0; i < b_index; i++) {
    buffer->data[i] = Infinion_B.buffer_c[i];
  }

  Infinion_char(buffer, y);
  Infinion_emxFree_uint8_T(&buffer);
}

void rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(const real_T u0[3], const real_T u1[9],
  real_T y[3])
{
  real_T A[9];
  real_T a21;
  real_T maxval;
  int32_T r1;
  int32_T r2;
  int32_T r3;
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

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int8_T InfinionModelClass::Infinion_filedata_k(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Infinion_DW.eml_openfiles_h[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int8_T InfinionModelClass::Infinion_cfopen_k(const char_T *cfilename, const
  char_T *cpermission)
{
  FILE * filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Infinion_filedata_k();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles_h[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
real_T InfinionModelClass::Infinion_fileManager_e(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_k("ActuatorCommands/throttle.txt", "rb");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
FILE * InfinionModelClass::Infinion_fileManager_e4(real_T varargin_1)
{
  FILE * f;
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
  if ((fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Infinion_DW.eml_openfiles_h[fileid - 3];
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
void InfinionModelClass::Infinion_fseek_c(real_T fileID)
{
  FILE * filestar;
  int wherefrom;
  wherefrom = SEEK_END;
  filestar = Infinion_fileManager_e4(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
real_T InfinionModelClass::Infinion_ftell_b(real_T fileID)
{
  FILE * filestar;
  long position_t;
  real_T position;
  filestar = Infinion_fileManager_e4(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (filestar == NULL) {
    position = -1.0;
  } else {
    position_t = ftell(filestar);
    position = (real_T)position_t;
  }

  return position;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
void InfinionModelClass::Infinion_fseek_cn(real_T fileID)
{
  FILE * filestar;
  int wherefrom;
  wherefrom = SEEK_SET;
  filestar = Infinion_fileManager_e4(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  if (!(filestar == NULL)) {
    fseek(filestar, (long int)0.0, wherefrom);
  }
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
void InfinionModelClass::Infinion_fread_j(real_T fileID, int32_T sizeA,
  emxArray_real_T_Infinion_T *A, real_T *count)
{
  FILE * filestar;
  size_t nBytes;
  size_t numReadSizeT;
  emxArray_uint8_T_Infinion_T *At;
  emxArray_uint8_T_Infinion_T *b_At;
  int32_T bdims_idx_0;
  int32_T buf_size_idx_0;
  int32_T bytesOut;
  int32_T c;
  int32_T c_numRead;
  int32_T d_numRead;
  int32_T num2Read;
  char_T buf_data[1024];
  boolean_T doEOF;
  if (sizeA >= MAX_int32_T) {
    c = 1024;
    doEOF = true;
  } else {
    c = sizeA;
    doEOF = false;
  }

  nBytes = sizeof(char_T);
  filestar = Infinion_fileManager_e4(fileID);
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = NULL;
  }

  Infinion_emxInit_uint8_T(&At, 2);
  Infinion_emxInit_uint8_T1(&b_At, 1);
  if (!doEOF) {
    if (filestar == NULL) {
      A->size[0] = 0;
      bytesOut = 0;
    } else {
      num2Read = A->size[0];
      A->size[0] = sizeA;
      Infini_emxEnsureCapacity_real_T(A, num2Read);
      if (c > 1024) {
        bdims_idx_0 = 1024;
      } else {
        bdims_idx_0 = c;
      }

      bytesOut = 0;
      c_numRead = 1;
      buf_size_idx_0 = bdims_idx_0;
      while ((bytesOut < c) && (c_numRead > 0)) {
        num2Read = buf_size_idx_0;
        c_numRead = c - bytesOut;
        if (buf_size_idx_0 > c_numRead) {
          num2Read = c_numRead;
        }

        buf_size_idx_0 = static_cast<int16_T>(bdims_idx_0);
        c_numRead = 0;
        d_numRead = 1;
        while ((c_numRead < num2Read) && (d_numRead > 0)) {
          numReadSizeT = fread(&buf_data[c_numRead], nBytes, num2Read -
                               c_numRead, filestar);
          d_numRead = (int32_T)numReadSizeT;
          c_numRead += (int32_T)numReadSizeT;
        }

        for (num2Read = 0; num2Read < c_numRead; num2Read++) {
          A->data[num2Read + bytesOut] = static_cast<uint8_T>(buf_data[num2Read]);
        }

        bytesOut += c_numRead;
      }

      c = A->size[0];
      for (c_numRead = bytesOut; c_numRead < c; c_numRead++) {
        A->data[c_numRead] = 0.0;
      }

      if (bytesOut < sizeA) {
        if (1 > bytesOut) {
          A->size[0] = 0;
        } else {
          num2Read = A->size[0];
          A->size[0] = bytesOut;
          Infini_emxEnsureCapacity_real_T(A, num2Read);
        }
      }
    }
  } else {
    At->size[0] = 0;
    At->size[1] = 1;
    if (filestar == NULL) {
      bytesOut = 0;
    } else {
      c = 1;
      bytesOut = 0;
      while (c > 0) {
        c = 0;
        c_numRead = 1;
        while ((c < 1024) && (c_numRead > 0)) {
          numReadSizeT = fread(&buf_data[c], nBytes, 1024 - c, filestar);
          c_numRead = (int32_T)numReadSizeT;
          c += (int32_T)numReadSizeT;
        }

        if (1 > c) {
          c_numRead = -1;
        } else {
          c_numRead = c - 1;
        }

        num2Read = b_At->size[0];
        b_At->size[0] = (At->size[0] + c_numRead) + 1;
        Infi_emxEnsureCapacity_uint8_T1(b_At, num2Read);
        bdims_idx_0 = At->size[0];
        for (num2Read = 0; num2Read < bdims_idx_0; num2Read++) {
          b_At->data[num2Read] = At->data[num2Read];
        }

        for (num2Read = 0; num2Read <= c_numRead; num2Read++) {
          b_At->data[num2Read + At->size[0]] = static_cast<uint8_T>
            (buf_data[num2Read]);
        }

        num2Read = At->size[0] * At->size[1];
        At->size[0] = b_At->size[0];
        At->size[1] = 1;
        Infin_emxEnsureCapacity_uint8_T(At, num2Read);
        c_numRead = b_At->size[0] - 1;
        for (num2Read = 0; num2Read <= c_numRead; num2Read++) {
          At->data[num2Read] = b_At->data[num2Read];
        }

        bytesOut += c;
      }
    }

    num2Read = A->size[0];
    A->size[0] = At->size[0];
    Infini_emxEnsureCapacity_real_T(A, num2Read);
    c_numRead = At->size[0];
    for (num2Read = 0; num2Read < c_numRead; num2Read++) {
      A->data[num2Read] = At->data[num2Read];
    }
  }

  Infinion_emxFree_uint8_T(&b_At);
  Infinion_emxFree_uint8_T(&At);
  *count = bytesOut;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
int32_T InfinionModelClass::Infinion_cfclose_i(real_T fid)
{
  FILE * f;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
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
    f = Infinion_DW.eml_openfiles_h[b_fileid - 3];
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
      Infinion_DW.eml_openfiles_h[fileid - 3] = NULL;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<Root>/Read Throttle' */
void InfinionModelClass::Infinion_readfile_e(emxArray_char_T_Infinion_T *y)
{
  emxArray_real_T_Infinion_T *dataRead;
  emxArray_uint8_T_Infinion_T *buffer;
  real_T f;
  real_T nread;
  real_T tmp;
  int32_T b_index;
  int32_T i;
  int32_T n;
  int32_T qY;
  int32_T remaining;
  int32_T tmp_0;
  boolean_T exitg1;
  f = Infinion_fileManager_e();
  Infinion_fseek_c(f);
  tmp = rt_roundd_snf(Infinion_ftell_b(f));
  if (tmp < 2.147483648E+9) {
    if (tmp >= -2.147483648E+9) {
      i = static_cast<int32_T>(tmp);
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  Infinion_fseek_cn(f);
  std::memset(&Infinion_B.buffer_k[0], 0, sizeof(uint8_T) << 16U);
  remaining = i;
  b_index = 1;
  Infinion_emxInit_real_T(&dataRead, 1);
  exitg1 = false;
  while ((!exitg1) && (remaining > 0)) {
    if (b_index > MAX_int32_T - remaining) {
      n = MAX_int32_T;
    } else {
      n = remaining + b_index;
    }

    if (n > 65536) {
      printf("Attempt to read file which is bigger than internal buffer.\n");
      fflush(stdout);
      printf("Current buffer size is %d bytes and file size is %d bytes.\n",
             65536, i);
      fflush(stdout);
      exitg1 = true;
    } else {
      Infinion_fread_j(f, remaining, dataRead, &nread);
      tmp = rt_roundd_snf(static_cast<real_T>(b_index) + nread);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          n = static_cast<int32_T>(tmp);
        } else {
          n = MIN_int32_T;
        }
      } else {
        n = MAX_int32_T;
      }

      if (n < -2147483647) {
        qY = MIN_int32_T;
      } else {
        qY = n - 1;
      }

      if (b_index > qY) {
        n = -1;
        qY = 0;
      } else {
        n = b_index - 2;
      }

      tmp_0 = (qY - n) - 1;
      for (qY = 0; qY < tmp_0; qY++) {
        tmp = rt_roundd_snf(dataRead->data[qY]);
        if (tmp < 256.0) {
          if (tmp >= 0.0) {
            Infinion_B.buffer_k[(n + qY) + 1] = static_cast<uint8_T>(tmp);
          } else {
            Infinion_B.buffer_k[(n + qY) + 1] = 0U;
          }
        } else {
          Infinion_B.buffer_k[(n + qY) + 1] = MAX_uint8_T;
        }
      }

      tmp = rt_roundd_snf(nread);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          n = static_cast<int32_T>(tmp);
        } else {
          n = MIN_int32_T;
        }
      } else {
        n = MAX_int32_T;
      }

      if (n == 0) {
        exitg1 = true;
      } else if (n < 0) {
        printf("Could not read from file: %d.\n", n);
        fflush(stdout);
        exitg1 = true;
      } else {
        remaining -= n;
        if ((b_index < 0) && (n < MIN_int32_T - b_index)) {
          b_index = MIN_int32_T;
        } else if ((b_index > 0) && (n > MAX_int32_T - b_index)) {
          b_index = MAX_int32_T;
        } else {
          b_index += n;
        }
      }
    }
  }

  Infinion_emxFree_real_T(&dataRead);
  Infinion_emxInit_uint8_T(&buffer, 2);
  Infinion_cfclose_i(f);
  i = buffer->size[0] * buffer->size[1];
  buffer->size[0] = 1;
  buffer->size[1] = b_index;
  Infin_emxEnsureCapacity_uint8_T(buffer, i);
  for (i = 0; i < b_index; i++) {
    buffer->data[i] = Infinion_B.buffer_k[i];
  }

  Infinion_char(buffer, y);
  Infinion_emxFree_uint8_T(&buffer);
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int8_T InfinionModelClass::Infinion_filedata_m(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Infinion_DW.eml_openfiles_i[static_cast<int8_T>(k) - 1] == NULL) {
      f = static_cast<int8_T>(k);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int8_T InfinionModelClass::Infinion_cfopen_n(const char_T *cfilename, const
  char_T *cpermission)
{
  FILE * filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Infinion_filedata_m();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Infinion_DW.eml_openfiles_i[j - 1] = filestar;
      Infinion_DW.eml_autoflush[j - 1] = true;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = static_cast<int8_T>(tmp);
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_n(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/airspeed.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nv(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/angleOfAttack.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nvg(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/track.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nvg1(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/latitudeSpeed.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nvg1z(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/longitudeSpeed.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nvg1zl(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/rateOfClimb.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nvg1zlk(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/latitude.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nvg1zlk2(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/longitude.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nvg1zlk2m(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/altitude.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinion_fileManager_nvg1zlk2mj(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/roll.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infinio_fileManager_nvg1zlk2mjw(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/pitch.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infini_fileManager_nvg1zlk2mjw5(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/yaw.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infin_fileManager_nvg1zlk2mjw5f(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/rollRate.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Infi_fileManager_nvg1zlk2mjw5fc(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/pitchRate.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Inf_fileManager_nvg1zlk2mjw5fch(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/yawRate.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Inf_fileManager_k(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/accX.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Inf_fileManager_e(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/accY.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Inf_fileManager_f(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/accZ.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Inf_fileManager_o(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/gyrX.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Inf_fileManager_oy(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/gyrY.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
real_T InfinionModelClass::Inf_fileManager_p(void)
{
  int8_T fileid;
  fileid = Infinion_cfopen_n("SensorOutputs/gyrZ.txt", "ab");
  return fileid;
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
void InfinionModelClass::Inf_fileManager_n(real_T varargin_1, FILE * *f,
  boolean_T *a)
{
  int8_T fileid;
  fileid = static_cast<int8_T>(rt_roundd_snf(varargin_1));
  if ((fileid > 22) || (fileid < 0) || (varargin_1 != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    *f = Infinion_DW.eml_openfiles_i[fileid - 3];
    *a = Infinion_DW.eml_autoflush[fileid - 3];
  } else if (fileid == 0) {
    *f = stdin;
    *a = true;
  } else if (fileid == 1) {
    *f = stdout;
    *a = true;
  } else if (fileid == 2) {
    *f = stderr;
    *a = true;
  } else {
    *f = NULL;
    *a = true;
  }
}

/* Function for MATLAB Function: '<Root>/WriteToFile' */
int32_T InfinionModelClass::Inf_fileManager_el(void)
{
  int32_T cst;
  int32_T f;
  int32_T j;
  f = 0;
  for (j = 0; j < 20; j++) {
    if (Infinion_DW.eml_openfiles_i[j] != NULL) {
      cst = fclose(Infinion_DW.eml_openfiles_i[j]);
      if (cst == 0) {
        Infinion_DW.eml_openfiles_i[j] = NULL;
        Infinion_DW.eml_autoflush[j] = true;
      } else {
        f = -1;
      }
    }
  }

  return f;
}

/* Model step function */
void InfinionModelClass::step()
{
  FILE * b_NULL;
  FILE * filestar;
  emxArray_char_T_Infinion_T *s;
  real_T rtb_VectorConcatenate[18];
  real_T VectorConcatenate[9];
  real_T rtb_sincos_o1_b[3];
  real_T rtb_sincos_o2_a[3];
  real_T tmp[3];
  real_T Airspeed;
  real_T Gain;
  real_T TmpSignalConversionAtSFunctio_0;
  real_T TmpSignalConversionAtSFunctionI;
  real_T accXFile;
  real_T accYFile;
  real_T accZFile;
  real_T altitudeFile;
  real_T gyrXFile;
  real_T gyrYFile;
  real_T gyrZFile;
  real_T latFile;
  real_T latSpeedFile;
  real_T longFile;
  real_T longSpeedFile;
  real_T pitchFile;
  real_T pitchRateFile;
  real_T rateOfClimbFile;
  real_T rollFile;
  real_T rollRateFile;
  real_T rtb_Abs;
  real_T rtb_Abs1;
  real_T rtb_Sum_f_idx_0;
  real_T rtb_sincos_o1_g_tmp;
  real_T rtb_sincos_o1_g_tmp_0;
  real_T rtb_sincos_o2_b_tmp;
  real_T rtb_sqrt;
  real_T u0;
  real_T yawFile;
  real_T yawRateFile;
  int32_T i;
  int32_T rtb_VectorConcatenate_tmp;
  int32_T rtb_VectorConcatenate_tmp_0;
  int32_T rtb_VectorConcatenate_tmp_1;
  boolean_T rtb_Compare_f;
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

  /* Sqrt: '<S5>/Airspeed' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S71>/Product'
   *  Product: '<S71>/Product1'
   *  Product: '<S71>/Product2'
   *  Sum: '<S71>/Sum'
   */
  Airspeed = std::sqrt((Infinion_X.ubvbwb_CSTATE[0] * Infinion_X.ubvbwb_CSTATE[0]
                        + Infinion_X.ubvbwb_CSTATE[1] *
                        Infinion_X.ubvbwb_CSTATE[1]) + Infinion_X.ubvbwb_CSTATE
                       [2] * Infinion_X.ubvbwb_CSTATE[2]);

  /* Gain: '<Root>/Gain' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   *  Trigonometry: '<S5>/Incidence'
   */
  Gain = Infinion_P.Gain_Gain_h * rt_atan2d_snf(Infinion_X.ubvbwb_CSTATE[2],
    Infinion_X.ubvbwb_CSTATE[0]);
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* UnitConversion: '<S64>/Unit Conversion' incorporates:
     *  Constant: '<S4>/ref_rotation'
     */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_sqrt = 0.017453292519943295 * Infinion_P.FlatEarthtoLLA_psi;

    /* Trigonometry: '<S49>/SinCos' */
    Infinion_B.SinCos_o1 = std::sin(rtb_sqrt);

    /* Trigonometry: '<S49>/SinCos' */
    Infinion_B.SinCos_o2 = std::cos(rtb_sqrt);

    /* Sum: '<S67>/Sum' incorporates:
     *  Constant: '<S67>/Constant'
     *  Constant: '<S67>/f'
     */
    rtb_sqrt = Infinion_P.f_Value - Infinion_P.Constant_Value_j;

    /* Sqrt: '<S68>/sqrt' incorporates:
     *  Constant: '<S68>/Constant'
     *  Product: '<S68>/Product1'
     *  Sum: '<S68>/Sum1'
     */
    rtb_sqrt = std::sqrt(Infinion_P.Constant_Value_i - rtb_sqrt * rtb_sqrt);

    /* Switch: '<S60>/Switch' incorporates:
     *  Abs: '<S60>/Abs'
     *  Bias: '<S60>/Bias'
     *  Bias: '<S60>/Bias1'
     *  Constant: '<S4>/ref_position'
     *  Constant: '<S60>/Constant2'
     *  Constant: '<S61>/Constant'
     *  Math: '<S60>/Math Function1'
     *  RelationalOperator: '<S61>/Compare'
     */
    if (std::abs(Infinion_P.FlatEarthtoLLA_LL0[0]) >
        Infinion_P.CompareToConstant_const) {
      rtb_Sum_f_idx_0 = rt_modd_snf(Infinion_P.FlatEarthtoLLA_LL0[0] +
        Infinion_P.Bias_Bias_o, Infinion_P.Constant2_Value) +
        Infinion_P.Bias1_Bias_jw;
    } else {
      rtb_Sum_f_idx_0 = Infinion_P.FlatEarthtoLLA_LL0[0];
    }

    /* End of Switch: '<S60>/Switch' */

    /* Abs: '<S57>/Abs1' */
    rtb_Abs1 = std::abs(rtb_Sum_f_idx_0);

    /* RelationalOperator: '<S59>/Compare' incorporates:
     *  Constant: '<S59>/Constant'
     */
    rtb_Compare_f = (rtb_Abs1 > Infinion_P.CompareToConstant_const_n);

    /* Switch: '<S57>/Switch' */
    if (rtb_Compare_f) {
      /* Signum: '<S57>/Sign1' */
      if (rtb_Sum_f_idx_0 < 0.0) {
        rtb_Sum_f_idx_0 = -1.0;
      } else if (rtb_Sum_f_idx_0 > 0.0) {
        rtb_Sum_f_idx_0 = 1.0;
      } else if (rtb_Sum_f_idx_0 == 0.0) {
        rtb_Sum_f_idx_0 = 0.0;
      } else {
        rtb_Sum_f_idx_0 = (rtNaN);
      }

      /* End of Signum: '<S57>/Sign1' */

      /* Switch: '<S57>/Switch' incorporates:
       *  Bias: '<S57>/Bias'
       *  Bias: '<S57>/Bias1'
       *  Gain: '<S57>/Gain'
       *  Product: '<S57>/Divide1'
       */
      Infinion_B.Switch = ((rtb_Abs1 + Infinion_P.Bias_Bias_n) *
                           Infinion_P.Gain_Gain_g + Infinion_P.Bias1_Bias_a) *
        rtb_Sum_f_idx_0;
    } else {
      /* Switch: '<S57>/Switch' */
      Infinion_B.Switch = rtb_Sum_f_idx_0;
    }

    /* End of Switch: '<S57>/Switch' */

    /* UnitConversion: '<S65>/Unit Conversion' */
    /* Unit Conversion - from: deg to: rad
       Expression: output = (0.0174533*input) + (0) */
    rtb_Sum_f_idx_0 = 0.017453292519943295 * Infinion_B.Switch;

    /* Trigonometry: '<S66>/Trigonometric Function1' */
    rtb_Abs1 = std::sin(rtb_Sum_f_idx_0);

    /* Product: '<S66>/Product1' incorporates:
     *  Product: '<S63>/Product2'
     */
    TmpSignalConversionAtSFunctionI = rtb_sqrt * rtb_sqrt;

    /* Sum: '<S66>/Sum1' incorporates:
     *  Constant: '<S66>/Constant'
     *  Product: '<S66>/Product1'
     */
    rtb_Abs1 = Infinion_P.Constant_Value_l - TmpSignalConversionAtSFunctionI *
      rtb_Abs1 * rtb_Abs1;

    /* Product: '<S63>/Product1' incorporates:
     *  Constant: '<S63>/Constant1'
     *  Sqrt: '<S63>/sqrt'
     */
    rtb_Abs = Infinion_P.Constant1_Value_k / std::sqrt(rtb_Abs1);

    /* Trigonometry: '<S63>/Trigonometric Function1' incorporates:
     *  Constant: '<S63>/Constant'
     *  Constant: '<S63>/Constant2'
     *  Product: '<S63>/Product3'
     *  Sum: '<S63>/Sum1'
     */
    Infinion_B.TrigonometricFunction1 = rt_atan2d_snf
      (Infinion_P.Constant2_Value_d, (Infinion_P.Constant_Value_h -
        TmpSignalConversionAtSFunctionI) * rtb_Abs / rtb_Abs1);

    /* Trigonometry: '<S63>/Trigonometric Function2' incorporates:
     *  Constant: '<S63>/Constant3'
     *  Product: '<S63>/Product4'
     *  Trigonometry: '<S63>/Trigonometric Function'
     */
    Infinion_B.TrigonometricFunction2 = rt_atan2d_snf(Infinion_P.Constant3_Value,
      rtb_Abs * std::cos(rtb_Sum_f_idx_0));

    /* Switch: '<S48>/Switch1' incorporates:
     *  Constant: '<S48>/Constant'
     *  Constant: '<S48>/Constant1'
     */
    if (rtb_Compare_f) {
      rtb_Sum_f_idx_0 = Infinion_P.Constant_Value;
    } else {
      rtb_Sum_f_idx_0 = Infinion_P.Constant1_Value;
    }

    /* End of Switch: '<S48>/Switch1' */

    /* Sum: '<S48>/Sum' incorporates:
     *  Constant: '<S4>/ref_position'
     */
    rtb_sqrt = rtb_Sum_f_idx_0 + Infinion_P.FlatEarthtoLLA_LL0[1];

    /* Switch: '<S58>/Switch' incorporates:
     *  Abs: '<S58>/Abs'
     *  Constant: '<S62>/Constant'
     *  RelationalOperator: '<S62>/Compare'
     */
    if (std::abs(rtb_sqrt) > Infinion_P.CompareToConstant_const_c) {
      /* Switch: '<S58>/Switch' incorporates:
       *  Bias: '<S58>/Bias'
       *  Bias: '<S58>/Bias1'
       *  Constant: '<S58>/Constant2'
       *  Math: '<S58>/Math Function1'
       */
      Infinion_B.Switch_i = rt_modd_snf(rtb_sqrt + Infinion_P.Bias_Bias_f,
        Infinion_P.Constant2_Value_g) + Infinion_P.Bias1_Bias_b;
    } else {
      /* Switch: '<S58>/Switch' */
      Infinion_B.Switch_i = rtb_sqrt;
    }

    /* End of Switch: '<S58>/Switch' */
  }

  /* Sum: '<S4>/Sum' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   *  Product: '<S49>/rad lat'
   *  Product: '<S49>/x*cos'
   *  Product: '<S49>/y*sin'
   *  Sum: '<S49>/Sum'
   *  UnitConversion: '<S50>/Unit Conversion'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_Sum_f_idx_0 = (Infinion_X.xeyeze_CSTATE[0] * Infinion_B.SinCos_o2 -
                     Infinion_X.xeyeze_CSTATE[1] * Infinion_B.SinCos_o1) *
    Infinion_B.TrigonometricFunction1 * 57.295779513082323 + Infinion_B.Switch;

  /* Switch: '<S54>/Switch' incorporates:
   *  Abs: '<S54>/Abs'
   *  Bias: '<S54>/Bias'
   *  Bias: '<S54>/Bias1'
   *  Constant: '<S54>/Constant2'
   *  Constant: '<S55>/Constant'
   *  Math: '<S54>/Math Function1'
   *  RelationalOperator: '<S55>/Compare'
   */
  if (std::abs(rtb_Sum_f_idx_0) > Infinion_P.CompareToConstant_const_e) {
    rtb_Sum_f_idx_0 = rt_modd_snf(rtb_Sum_f_idx_0 + Infinion_P.Bias_Bias_m,
      Infinion_P.Constant2_Value_e) + Infinion_P.Bias1_Bias_j;
  }

  /* End of Switch: '<S54>/Switch' */

  /* Abs: '<S51>/Abs1' */
  rtb_sqrt = std::abs(rtb_Sum_f_idx_0);

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  rtb_Compare_f = (rtb_sqrt > Infinion_P.CompareToConstant_const_p);

  /* Switch: '<S51>/Switch' incorporates:
   *  Bias: '<S51>/Bias'
   *  Bias: '<S51>/Bias1'
   *  Gain: '<S51>/Gain'
   *  Product: '<S51>/Divide1'
   */
  if (rtb_Compare_f) {
    /* Signum: '<S51>/Sign1' */
    if (rtb_Sum_f_idx_0 < 0.0) {
      rtb_Sum_f_idx_0 = -1.0;
    } else if (rtb_Sum_f_idx_0 > 0.0) {
      rtb_Sum_f_idx_0 = 1.0;
    } else if (rtb_Sum_f_idx_0 == 0.0) {
      rtb_Sum_f_idx_0 = 0.0;
    } else {
      rtb_Sum_f_idx_0 = (rtNaN);
    }

    /* End of Signum: '<S51>/Sign1' */
    rtb_Sum_f_idx_0 *= (rtb_sqrt + Infinion_P.Bias_Bias) * Infinion_P.Gain_Gain
      + Infinion_P.Bias1_Bias;
  }

  /* End of Switch: '<S51>/Switch' */

  /* SignalConversion generated from: '<S14>/ SFunction ' incorporates:
   *  Constant: '<Root>/HNLLat'
   *  Sum: '<Root>/Sum'
   */
  TmpSignalConversionAtSFunctionI = Infinion_P.HNLLat_Value + rtb_Sum_f_idx_0;

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S47>/Constant1'
   */
  if (rtb_Compare_f) {
    rtb_Sum_f_idx_0 = Infinion_P.Constant_Value_o;
  } else {
    rtb_Sum_f_idx_0 = Infinion_P.Constant1_Value_d;
  }

  /* End of Switch: '<S47>/Switch1' */

  /* Sum: '<S47>/Sum' incorporates:
   *  Integrator: '<S1>/xe,ye,ze'
   *  Product: '<S49>/rad long '
   *  Product: '<S49>/x*sin'
   *  Product: '<S49>/y*cos'
   *  Sum: '<S49>/Sum1'
   *  Sum: '<S4>/Sum'
   *  UnitConversion: '<S50>/Unit Conversion'
   */
  rtb_Sum_f_idx_0 += (Infinion_X.xeyeze_CSTATE[0] * Infinion_B.SinCos_o1 +
                      Infinion_X.xeyeze_CSTATE[1] * Infinion_B.SinCos_o2) *
    Infinion_B.TrigonometricFunction2 * 57.295779513082323 + Infinion_B.Switch_i;

  /* Switch: '<S52>/Switch' incorporates:
   *  Abs: '<S52>/Abs'
   *  Bias: '<S52>/Bias'
   *  Bias: '<S52>/Bias1'
   *  Constant: '<S52>/Constant2'
   *  Constant: '<S56>/Constant'
   *  Math: '<S52>/Math Function1'
   *  RelationalOperator: '<S56>/Compare'
   */
  if (std::abs(rtb_Sum_f_idx_0) > Infinion_P.CompareToConstant_const_h) {
    rtb_Sum_f_idx_0 = rt_modd_snf(rtb_Sum_f_idx_0 + Infinion_P.Bias_Bias_k,
      Infinion_P.Constant2_Value_h) + Infinion_P.Bias1_Bias_g;
  }

  /* End of Switch: '<S52>/Switch' */
  Infinion_emxInit_char_T(&s, 2);
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* MATLAB Function: '<Root>/Read Aileron' */
    Infinion_readfile(s);
    rtb_sqrt = Infinion_lastStr2double(s);
    Infinion_B.aileron = rtb_sqrt * 0.2618 / 100.0;

    /* MATLAB Function: '<Root>/Read Elevator' */
    Infinion_readfile_n(s);
    rtb_sqrt = Infinion_lastStr2double(s);
    Infinion_B.elevator = rtb_sqrt * 0.2618 / 100.0;

    /* MATLAB Function: '<Root>/Read Rudder' */
    Infinion_readfile_a(s);
    rtb_sqrt = Infinion_lastStr2double(s);
    Infinion_B.rudder = rtb_sqrt * 0.2618 / 100.0;
  }

  /* Product: '<S5>/Product' incorporates:
   *  Integrator: '<S1>/ub,vb,wb'
   */
  u0 = Infinion_X.ubvbwb_CSTATE[1] / Airspeed;

  /* Trigonometry: '<S5>/Sideslip' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < -1.0) {
    u0 = -1.0;
  }

  rtb_sqrt = std::asin(u0);

  /* End of Trigonometry: '<S5>/Sideslip' */
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    for (i = 0; i < 3; i++) {
      /* Concatenate: '<S20>/Vector Concatenate' incorporates:
       *  Constant: '<S20>/Constant1'
       *  Constant: '<S20>/Constant2'
       *  Selector: '<S19>/Selector1'
       */
      rtb_VectorConcatenate[6 * i] = Infinion_P.uDOFEulerAngles_inertia[3 * i];
      rtb_VectorConcatenate_tmp = 6 * i + 3;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp] =
        Infinion_P.Constant2_Value_f[3 * i];

      /* Selector: '<S19>/Selector1' incorporates:
       *  Concatenate: '<S20>/Vector Concatenate'
       */
      Infinion_B.Selector1[3 * i] =
        rtb_VectorConcatenate[rtb_VectorConcatenate_tmp];

      /* Selector: '<S19>/Selector' incorporates:
       *  Concatenate: '<S20>/Vector Concatenate'
       */
      Infinion_B.Selector[3 * i] = rtb_VectorConcatenate[6 * i];

      /* Concatenate: '<S20>/Vector Concatenate' incorporates:
       *  Constant: '<S20>/Constant1'
       *  Constant: '<S20>/Constant2'
       *  Selector: '<S19>/Selector'
       *  Selector: '<S19>/Selector1'
       */
      rtb_VectorConcatenate_tmp = 3 * i + 1;
      rtb_VectorConcatenate_tmp_1 = 6 * i + 1;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp_1] =
        Infinion_P.uDOFEulerAngles_inertia[rtb_VectorConcatenate_tmp];
      rtb_VectorConcatenate_tmp_0 = 6 * i + 4;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp_0] =
        Infinion_P.Constant2_Value_f[rtb_VectorConcatenate_tmp];

      /* Selector: '<S19>/Selector1' incorporates:
       *  Concatenate: '<S20>/Vector Concatenate'
       */
      Infinion_B.Selector1[rtb_VectorConcatenate_tmp] =
        rtb_VectorConcatenate[rtb_VectorConcatenate_tmp_0];

      /* Selector: '<S19>/Selector' incorporates:
       *  Concatenate: '<S20>/Vector Concatenate'
       */
      Infinion_B.Selector[rtb_VectorConcatenate_tmp] =
        rtb_VectorConcatenate[rtb_VectorConcatenate_tmp_1];

      /* Concatenate: '<S20>/Vector Concatenate' incorporates:
       *  Constant: '<S20>/Constant1'
       *  Constant: '<S20>/Constant2'
       *  Selector: '<S19>/Selector'
       *  Selector: '<S19>/Selector1'
       */
      rtb_VectorConcatenate_tmp = 3 * i + 2;
      rtb_VectorConcatenate_tmp_1 = 6 * i + 2;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp_1] =
        Infinion_P.uDOFEulerAngles_inertia[rtb_VectorConcatenate_tmp];
      rtb_VectorConcatenate_tmp_0 = 6 * i + 5;
      rtb_VectorConcatenate[rtb_VectorConcatenate_tmp_0] =
        Infinion_P.Constant2_Value_f[rtb_VectorConcatenate_tmp];

      /* Selector: '<S19>/Selector1' incorporates:
       *  Concatenate: '<S20>/Vector Concatenate'
       */
      Infinion_B.Selector1[rtb_VectorConcatenate_tmp] =
        rtb_VectorConcatenate[rtb_VectorConcatenate_tmp_0];

      /* Selector: '<S19>/Selector' incorporates:
       *  Concatenate: '<S20>/Vector Concatenate'
       */
      Infinion_B.Selector[rtb_VectorConcatenate_tmp] =
        rtb_VectorConcatenate[rtb_VectorConcatenate_tmp_1];
    }
  }

  for (i = 0; i < 3; i++) {
    /* Product: '<S30>/Product' incorporates:
     *  Integrator: '<S1>/p,q,r '
     *  Selector: '<S19>/Selector'
     *  Trigonometry: '<S27>/sincos'
     */
    rtb_sincos_o1_b[i] = Infinion_B.Selector[i + 6] * Infinion_X.pqr_CSTATE[2] +
      (Infinion_B.Selector[i + 3] * Infinion_X.pqr_CSTATE[1] +
       Infinion_B.Selector[i] * Infinion_X.pqr_CSTATE[0]);

    /* Product: '<S31>/Product' incorporates:
     *  Integrator: '<S1>/p,q,r '
     *  Selector: '<S19>/Selector1'
     */
    tmp[i] = Infinion_B.Selector1[i + 6] * Infinion_X.pqr_CSTATE[2] +
      (Infinion_B.Selector1[i + 3] * Infinion_X.pqr_CSTATE[1] +
       Infinion_B.Selector1[i] * Infinion_X.pqr_CSTATE[0]);
  }

  /* Sum: '<S19>/Sum2' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  MATLAB Function: '<Root>/SimpleActuators'
   *  Product: '<S31>/Product'
   *  Product: '<S32>/j x k'
   *  Product: '<S33>/k x j'
   *  Sum: '<S29>/Sum'
   */
  rtb_sincos_o2_a[0] = (Infinion_B.aileron * 0.5 * 100.0 - tmp[0]) -
    (Infinion_X.pqr_CSTATE[1] * rtb_sincos_o1_b[2] - rtb_sincos_o1_b[1] *
     Infinion_X.pqr_CSTATE[2]);

  /* MATLAB Function: '<Root>/SimpleActuators' incorporates:
   *  Trigonometry: '<S2>/sincos'
   */
  rtb_Abs1 = std::cos(Gain);

  /* Sum: '<S19>/Sum2' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  MATLAB Function: '<Root>/SimpleActuators'
   *  Product: '<S31>/Product'
   *  Product: '<S32>/k x i'
   *  Product: '<S33>/i x k'
   *  Sum: '<S29>/Sum'
   */
  rtb_sincos_o2_a[1] = (Infinion_B.elevator * 0.5 * 100.0 * std::abs(rtb_Abs1) -
                        tmp[1]) - (rtb_sincos_o1_b[0] * Infinion_X.pqr_CSTATE[2]
    - Infinion_X.pqr_CSTATE[0] * rtb_sincos_o1_b[2]);

  /* MATLAB Function: '<Root>/SimpleActuators' incorporates:
   *  Trigonometry: '<S2>/sincos'
   */
  rtb_Abs = std::cos(rtb_sqrt);

  /* Sum: '<S19>/Sum2' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  MATLAB Function: '<Root>/SimpleActuators'
   *  Product: '<S31>/Product'
   *  Product: '<S32>/i x j'
   *  Product: '<S33>/j x i'
   *  Sum: '<S29>/Sum'
   */
  rtb_sincos_o2_a[2] = (Infinion_B.rudder * 0.5 * 100.0 * std::abs(rtb_Abs) -
                        tmp[2]) - (Infinion_X.pqr_CSTATE[0] * rtb_sincos_o1_b[1]
    - rtb_sincos_o1_b[0] * Infinion_X.pqr_CSTATE[1]);
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    for (i = 0; i < 3; i++) {
      /* Selector: '<S19>/Selector2' incorporates:
       *  Concatenate: '<S20>/Vector Concatenate'
       */
      Infinion_B.Selector2[3 * i] = rtb_VectorConcatenate[6 * i];
      Infinion_B.Selector2[3 * i + 1] = rtb_VectorConcatenate[6 * i + 1];
      Infinion_B.Selector2[3 * i + 2] = rtb_VectorConcatenate[6 * i + 2];
    }
  }

  /* Product: '<S19>/Product2' incorporates:
   *  Selector: '<S19>/Selector2'
   *  Trigonometry: '<S27>/sincos'
   */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(rtb_sincos_o2_a, Infinion_B.Selector2,
    Infinion_B.Product2);

  /* Trigonometry: '<S26>/sincos' incorporates:
   *  Integrator: '<S18>/phi theta psi'
   *  SignalConversion generated from: '<S26>/sincos'
   *  Trigonometry: '<S27>/sincos'
   */
  rtb_sincos_o2_a[0] = std::cos(Infinion_X.phithetapsi_CSTATE[2]);
  TmpSignalConversionAtSFunctio_0 = std::sin(Infinion_X.phithetapsi_CSTATE[2]);
  u0 = std::cos(Infinion_X.phithetapsi_CSTATE[1]);
  rtb_sincos_o1_g_tmp_0 = std::sin(Infinion_X.phithetapsi_CSTATE[1]);
  rtb_sincos_o2_b_tmp = std::cos(Infinion_X.phithetapsi_CSTATE[0]);
  rtb_sincos_o1_g_tmp = std::sin(Infinion_X.phithetapsi_CSTATE[0]);

  /* Fcn: '<S26>/Fcn11' incorporates:
   *  Trigonometry: '<S26>/sincos'
   */
  VectorConcatenate[0] = rtb_sincos_o2_a[0] * u0;

  /* Fcn: '<S26>/Fcn21' incorporates:
   *  Fcn: '<S26>/Fcn22'
   *  Trigonometry: '<S26>/sincos'
   */
  latSpeedFile = rtb_sincos_o1_g_tmp_0 * rtb_sincos_o1_g_tmp;
  VectorConcatenate[1] = latSpeedFile * rtb_sincos_o2_a[0] -
    TmpSignalConversionAtSFunctio_0 * rtb_sincos_o2_b_tmp;

  /* Fcn: '<S26>/Fcn31' incorporates:
   *  Fcn: '<S26>/Fcn32'
   *  Trigonometry: '<S26>/sincos'
   */
  longSpeedFile = rtb_sincos_o1_g_tmp_0 * rtb_sincos_o2_b_tmp;
  VectorConcatenate[2] = longSpeedFile * rtb_sincos_o2_a[0] +
    TmpSignalConversionAtSFunctio_0 * rtb_sincos_o1_g_tmp;

  /* Fcn: '<S26>/Fcn12' incorporates:
   *  Trigonometry: '<S26>/sincos'
   */
  VectorConcatenate[3] = TmpSignalConversionAtSFunctio_0 * u0;

  /* Fcn: '<S26>/Fcn22' incorporates:
   *  Trigonometry: '<S26>/sincos'
   */
  VectorConcatenate[4] = latSpeedFile * TmpSignalConversionAtSFunctio_0 +
    rtb_sincos_o2_a[0] * rtb_sincos_o2_b_tmp;

  /* Fcn: '<S26>/Fcn32' incorporates:
   *  Trigonometry: '<S26>/sincos'
   */
  VectorConcatenate[5] = longSpeedFile * TmpSignalConversionAtSFunctio_0 -
    rtb_sincos_o2_a[0] * rtb_sincos_o1_g_tmp;

  /* Fcn: '<S26>/Fcn13' incorporates:
   *  Trigonometry: '<S26>/sincos'
   */
  VectorConcatenate[6] = -rtb_sincos_o1_g_tmp_0;

  /* Fcn: '<S26>/Fcn23' incorporates:
   *  Trigonometry: '<S26>/sincos'
   */
  VectorConcatenate[7] = u0 * rtb_sincos_o1_g_tmp;

  /* Fcn: '<S26>/Fcn33' incorporates:
   *  Trigonometry: '<S26>/sincos'
   */
  VectorConcatenate[8] = u0 * rtb_sincos_o2_b_tmp;
  for (i = 0; i < 3; i++) {
    /* Product: '<S25>/Product' incorporates:
     *  Concatenate: '<S28>/Vector Concatenate'
     *  Integrator: '<S1>/ub,vb,wb'
     *  Math: '<S1>/Transpose'
     */
    Infinion_B.Product[i] = 0.0;
    Infinion_B.Product[i] += VectorConcatenate[3 * i] *
      Infinion_X.ubvbwb_CSTATE[0];
    Infinion_B.Product[i] += VectorConcatenate[3 * i + 1] *
      Infinion_X.ubvbwb_CSTATE[1];
    Infinion_B.Product[i] += VectorConcatenate[3 * i + 2] *
      Infinion_X.ubvbwb_CSTATE[2];
  }

  /* Trigonometry: '<S2>/sincos' incorporates:
   *  SignalConversion generated from: '<S2>/sincos'
   */
  TmpSignalConversionAtSFunctio_0 = std::sin(Gain);
  rtb_sqrt = std::sin(rtb_sqrt);

  /* Product: '<S36>/u(3)*u(4)' */
  Infinion_B.VectorConcatenate_b[0] = rtb_Abs1 * rtb_Abs;

  /* UnaryMinus: '<S39>/Unary Minus' incorporates:
   *  Product: '<S39>/u(2)*u(3)'
   */
  Infinion_B.VectorConcatenate_b[1] = -(rtb_Abs1 * rtb_sqrt);

  /* UnaryMinus: '<S42>/Unary Minus' */
  Infinion_B.VectorConcatenate_b[2] = -TmpSignalConversionAtSFunctio_0;

  /* SignalConversion generated from: '<S45>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_b[3] = rtb_sqrt;

  /* SignalConversion generated from: '<S45>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_b[4] = rtb_Abs;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* Constant: '<S43>/Constant' */
    Infinion_B.VectorConcatenate_b[5] = Infinion_P.Constant_Value_jt;
  }

  /* Product: '<S38>/u(1)*u(4)' */
  Infinion_B.VectorConcatenate_b[6] = TmpSignalConversionAtSFunctio_0 * rtb_Abs;

  /* UnaryMinus: '<S41>/Unary Minus' incorporates:
   *  Product: '<S41>/u(1)*u(2)'
   */
  Infinion_B.VectorConcatenate_b[7] = -(TmpSignalConversionAtSFunctio_0 *
    rtb_sqrt);

  /* SignalConversion generated from: '<S45>/Vector Concatenate' */
  Infinion_B.VectorConcatenate_b[8] = rtb_Abs1;
  if (rtmIsMajorTimeStep((&Infinion_M))) {
    /* MATLAB Function: '<Root>/Read Throttle' */
    Infinion_readfile_e(s);
    rtb_sqrt = Infinion_lastStr2double(s);

    /* MATLAB Function: '<Root>/propulsion' incorporates:
     *  MATLAB Function: '<Root>/Read Throttle'
     */
    Infinion_B.forces[0] = rtb_sqrt / 100.0 * 0.15 * 100.0;
    Infinion_B.forces[1] = 0.0;
    Infinion_B.forces[2] = 0.0;
  }

  Infinion_emxFree_char_T(&s);

  /* Sum: '<S21>/Sum' incorporates:
   *  Integrator: '<S1>/p,q,r '
   *  Integrator: '<S1>/ub,vb,wb'
   *  Product: '<S34>/i x j'
   *  Product: '<S34>/j x k'
   *  Product: '<S34>/k x i'
   *  Product: '<S35>/i x k'
   *  Product: '<S35>/j x i'
   *  Product: '<S35>/k x j'
   */
  rtb_sincos_o1_b[0] = Infinion_X.ubvbwb_CSTATE[1] * Infinion_X.pqr_CSTATE[2] -
    Infinion_X.pqr_CSTATE[1] * Infinion_X.ubvbwb_CSTATE[2];
  rtb_sincos_o1_b[1] = Infinion_X.pqr_CSTATE[0] * Infinion_X.ubvbwb_CSTATE[2] -
    Infinion_X.ubvbwb_CSTATE[0] * Infinion_X.pqr_CSTATE[2];
  rtb_sincos_o1_b[2] = Infinion_X.ubvbwb_CSTATE[0] * Infinion_X.pqr_CSTATE[1] -
    Infinion_X.pqr_CSTATE[0] * Infinion_X.ubvbwb_CSTATE[1];

  /* MATLAB Function: '<Root>/SimpleDrag' incorporates:
   *  MATLAB Function: '<Root>/SimpleLift'
   */
  rtb_sqrt = Airspeed * Airspeed;
  rtb_Abs1 = -rtb_sqrt * 0.04444;

  /* MATLAB Function: '<Root>/SimpleLift' */
  tmp[0] = 0.0;
  tmp[1] = 0.0;
  tmp[2] = (Gain + 0.08) * rtb_sqrt * 0.21222;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S1>/Sum' incorporates:
     *  Concatenate: '<S28>/Vector Concatenate'
     *  Concatenate: '<S45>/Vector Concatenate'
     *  Constant: '<S20>/Constant'
     *  MATLAB Function: '<Root>/SimpleDrag'
     *  MATLAB Function: '<Root>/gravity'
     *  Product: '<S1>/Product'
     *  Sum: '<Root>/Add'
     */
    Infinion_B.Sum[i] = (((((Infinion_B.VectorConcatenate_b[3 * i + 1] * 0.0 +
      Infinion_B.VectorConcatenate_b[3 * i] * rtb_Abs1) +
      Infinion_B.VectorConcatenate_b[3 * i + 2] * 0.0) + Infinion_B.forces[i]) +
                          (VectorConcatenate[i + 6] * -18.62 +
      (VectorConcatenate[i + 3] * 0.0 + VectorConcatenate[i] * 0.0))) + tmp[i]) /
      Infinion_P.uDOFEulerAngles_mass_0 + rtb_sincos_o1_b[i];
  }

  /* MATLAB Function: '<Root>/compute track' */
  rtb_sqrt = rt_atan2d_snf(Infinion_B.Product[1], Infinion_B.Product[0]);
  if (rtb_sqrt < 0.0) {
    rtb_sqrt += 6.2831853071795862;
  }

  /* SignalConversion generated from: '<S14>/ SFunction ' incorporates:
   *  Constant: '<Root>/HNLLong'
   *  MATLAB Function: '<Root>/WriteToFile'
   *  Sum: '<Root>/Sum1'
   */
  TmpSignalConversionAtSFunctio_0 = Infinion_P.HNLLong_Value + rtb_Sum_f_idx_0;

  /* MATLAB Function: '<Root>/WriteToFile' incorporates:
   *  Concatenate: '<S28>/Vector Concatenate'
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain3'
   *  Integrator: '<S18>/phi theta psi'
   *  Integrator: '<S1>/p,q,r '
   *  Integrator: '<S1>/xe,ye,ze'
   *  MATLAB Function: '<Root>/compute track'
   *  Sum: '<S4>/Sum1'
   *  UnaryMinus: '<S4>/Ze2height'
   */
  for (i = 0; i < 3; i++) {
    rtb_sincos_o1_b[i] = VectorConcatenate[i + 6] * -9.8 + (VectorConcatenate[i
      + 3] * 0.0 + VectorConcatenate[i] * 0.0);
  }

  rtb_Sum_f_idx_0 = Infinion_fileManager_n();
  rtb_Abs1 = Infinion_fileManager_nv();
  rtb_Abs = Infinion_fileManager_nvg();
  latSpeedFile = Infinion_fileManager_nvg1();
  longSpeedFile = Infinion_fileManager_nvg1z();
  rateOfClimbFile = Infinion_fileManager_nvg1zl();
  latFile = Infinion_fileManager_nvg1zlk();
  longFile = Infinion_fileManager_nvg1zlk2();
  altitudeFile = Infinion_fileManager_nvg1zlk2m();
  rollFile = Infinion_fileManager_nvg1zlk2mj();
  pitchFile = Infinio_fileManager_nvg1zlk2mjw();
  yawFile = Infini_fileManager_nvg1zlk2mjw5();
  rollRateFile = Infin_fileManager_nvg1zlk2mjw5f();
  pitchRateFile = Infi_fileManager_nvg1zlk2mjw5fc();
  yawRateFile = Inf_fileManager_nvg1zlk2mjw5fch();
  accXFile = Inf_fileManager_k();
  accYFile = Inf_fileManager_e();
  accZFile = Inf_fileManager_f();
  gyrXFile = Inf_fileManager_o();
  gyrYFile = Inf_fileManager_oy();
  gyrZFile = Inf_fileManager_p();
  b_NULL = NULL;
  Inf_fileManager_n(rtb_Sum_f_idx_0, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Airspeed);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(rtb_Abs1, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Gain);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(rtb_Abs, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", rtb_sqrt);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(latSpeedFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_B.Product[0]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(longSpeedFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_B.Product[1]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(rateOfClimbFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_B.Product[2]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(latFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", TmpSignalConversionAtSFunctionI);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(longFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", TmpSignalConversionAtSFunctio_0);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(altitudeFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_P.Gain3_Gain *
            (-Infinion_X.xeyeze_CSTATE[2] - Infinion_P.Constant_Value_m));
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(rollFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_X.phithetapsi_CSTATE[0]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(pitchFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_X.phithetapsi_CSTATE[1]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(yawFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_X.phithetapsi_CSTATE[2]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(rollRateFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_B.Product2[0]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(pitchRateFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_B.Product2[1]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(yawRateFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_B.Product2[2]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(accXFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", rtb_sincos_o1_b[0] + Infinion_B.Sum[0]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(accYFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", rtb_sincos_o1_b[1] + Infinion_B.Sum[1]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(accZFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", rtb_sincos_o1_b[2] + Infinion_B.Sum[2]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(gyrXFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_X.pqr_CSTATE[0]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(gyrYFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_X.pqr_CSTATE[1]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  b_NULL = NULL;
  Inf_fileManager_n(gyrZFile, &filestar, &rtb_Compare_f);
  if (!(filestar == b_NULL)) {
    fprintf(filestar, "%f\n", Infinion_X.pqr_CSTATE[2]);
    if (rtb_Compare_f) {
      fflush(filestar);
    }
  }

  Inf_fileManager_el();

  /* Fcn: '<S27>/phidot' incorporates:
   *  Fcn: '<S27>/psidot'
   *  Integrator: '<S1>/p,q,r '
   */
  Airspeed = Infinion_X.pqr_CSTATE[1] * rtb_sincos_o1_g_tmp +
    Infinion_X.pqr_CSTATE[2] * rtb_sincos_o2_b_tmp;

  /* SignalConversion generated from: '<S18>/phi theta psi' incorporates:
   *  Fcn: '<S27>/phidot'
   *  Fcn: '<S27>/psidot'
   *  Fcn: '<S27>/thetadot'
   *  Integrator: '<S1>/p,q,r '
   */
  Infinion_B.TmpSignalConversionAtphithetaps[0] = Airspeed *
    (rtb_sincos_o1_g_tmp_0 / u0) + Infinion_X.pqr_CSTATE[0];
  Infinion_B.TmpSignalConversionAtphithetaps[1] = rtb_sincos_o2_b_tmp *
    Infinion_X.pqr_CSTATE[1] - Infinion_X.pqr_CSTATE[2] * rtb_sincos_o1_g_tmp;
  Infinion_B.TmpSignalConversionAtphithetaps[2] = Airspeed / u0;
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

  /* Derivatives for Integrator: '<S18>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[0] = Infinion_B.TmpSignalConversionAtphithetaps[0];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[0] = Infinion_B.Product2[0];

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[1] = Infinion_B.Sum[1];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[1] = Infinion_B.Product[1];

  /* Derivatives for Integrator: '<S18>/phi theta psi' */
  _rtXdot->phithetapsi_CSTATE[1] = Infinion_B.TmpSignalConversionAtphithetaps[1];

  /* Derivatives for Integrator: '<S1>/p,q,r ' */
  _rtXdot->pqr_CSTATE[1] = Infinion_B.Product2[1];

  /* Derivatives for Integrator: '<S1>/ub,vb,wb' */
  _rtXdot->ubvbwb_CSTATE[2] = Infinion_B.Sum[2];

  /* Derivatives for Integrator: '<S1>/xe,ye,ze' */
  _rtXdot->xeyeze_CSTATE[2] = Infinion_B.Product[2];

  /* Derivatives for Integrator: '<S18>/phi theta psi' */
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

    /* InitializeConditions for Integrator: '<S18>/phi theta psi' */
    Infinion_X.phithetapsi_CSTATE[0] = Infinion_P.uDOFEulerAngles_eul_0[0];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Infinion_X.pqr_CSTATE[0] = Infinion_P.uDOFEulerAngles_pm_0[0];

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Infinion_X.ubvbwb_CSTATE[1] = Infinion_P.uDOFEulerAngles_Vm_0[1];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Infinion_X.xeyeze_CSTATE[1] = Infinion_P.uDOFEulerAngles_xme_0[1];

    /* InitializeConditions for Integrator: '<S18>/phi theta psi' */
    Infinion_X.phithetapsi_CSTATE[1] = Infinion_P.uDOFEulerAngles_eul_0[1];

    /* InitializeConditions for Integrator: '<S1>/p,q,r ' */
    Infinion_X.pqr_CSTATE[1] = Infinion_P.uDOFEulerAngles_pm_0[1];

    /* InitializeConditions for Integrator: '<S1>/ub,vb,wb' */
    Infinion_X.ubvbwb_CSTATE[2] = Infinion_P.uDOFEulerAngles_Vm_0[2];

    /* InitializeConditions for Integrator: '<S1>/xe,ye,ze' */
    Infinion_X.xeyeze_CSTATE[2] = Infinion_P.uDOFEulerAngles_xme_0[2];

    /* InitializeConditions for Integrator: '<S18>/phi theta psi' */
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
      Infinion_DW.eml_openfiles_m[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Elevator' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Rudder' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Infinion_DW.eml_openfiles_o[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Rudder' */

    /* SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Infinion_DW.eml_openfiles_h[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/Read Throttle' */

    /* SystemInitialize for MATLAB Function: '<Root>/WriteToFile' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Infinion_DW.eml_openfiles_i[i] = a;
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
InfinionModelClass::InfinionModelClass() :
  Infinion_B(),
  Infinion_DW(),
  Infinion_X(),
  Infinion_PeriodicIndX(),
  Infinion_PeriodicRngX(),
  Infinion_M()
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
