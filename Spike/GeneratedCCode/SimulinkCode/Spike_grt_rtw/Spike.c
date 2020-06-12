/*
 * Spike.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "Spike".
 *
 * Model version              : 1.15
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Jun 11 22:59:49 2020
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

/* Block states (default storage) */
DW_Spike_T Spike_DW;

/* Real-time model */
RT_MODEL_Spike_T Spike_M_;
RT_MODEL_Spike_T *const Spike_M = &Spike_M_;

/* Forward declaration for local functions */
static void Spike_emxInit_char_T(emxArray_char_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static void Spike_emxInit_real_T(emxArray_real_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static int8_T Spike_filedata(void);
static int8_T Spike_cfopen(const char * cfilename, const char * cpermission);
static FILE * Spike_fileManager(real_T varargin_1);
static void Spike_emxInit_int32_T(emxArray_int32_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static void Spike_emxInit_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static void Spike_emxEnsureCapacity_uint8_T(emxArray_uint8_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_emxEnsureCapacity_int32_T(emxArray_int32_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_emxFree_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray);
static void Spike_emxFree_int32_T(emxArray_int32_T_Spike_T **pEmxArray);
static void Spike_fclose(real_T fileID);
static void Spike_emxEnsureCapacity_char_T(emxArray_char_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_readfile(emxArray_char_T_Spike_T *y);
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
static boolean_T Spike_copysign_d(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
static void Spike_readfloat_e(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *success);
static void Spike_readfloat(emxArray_char_T_Spike_T *s1, const
  emxArray_char_T_Spike_T *s, int32_T n, int32_T *idx, int32_T *k, boolean_T
  *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *success);
static void Spike_emxFree_real_T(emxArray_real_T_Spike_T **pEmxArray);
static void Spike_readfloat_ei(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *isimag,
  boolean_T *b_finite, real_T *nfv, boolean_T *success);
static void Spike_emxFree_char_T(emxArray_char_T_Spike_T **pEmxArray);
static real_T Spike_sscanfd_l(const emxArray_char_T_Spike_T *s);
static void Spike_sscanfd(const emxArray_char_T_Spike_T *s, real_T *out1, real_T
  *out2);
static int8_T Spike_filedata_n(void);
static int8_T Spike_cfopen_f(const char * cfilename, const char * cpermission);
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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
  fileid = Spike_cfopen("nums1.txt", "rb");
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static boolean_T Spike_copysign_d(emxArray_char_T_Spike_T *s1, int32_T *idx,
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Spike_readfloat_e(emxArray_char_T_Spike_T *s1, int32_T *idx, const
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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
        Spike_readfloat_e(s1, idx, s, k, n, &unusedU0, b_finite, nfv, success);
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Spike_readfloat_ei(emxArray_char_T_Spike_T *s1, int32_T *idx, const
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
        Spike_readfloat_e(s1, idx, s, k, n, &unusedU0, b_finite, nfv, success);
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T Spike_sscanfd_l(const emxArray_char_T_Spike_T *s)
{
  real_T out1;
  int32_T nread;
  nread = sscanf(&s->data[0], "%lf", &out1);
  if (nread != 1) {
    out1 = (rtNaN);
  }

  return out1;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static int8_T Spike_filedata_n(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Spike_DW.eml_openfiles_d[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static int8_T Spike_cfopen_f(const char * cfilename, const char * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_n();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      Spike_DW.eml_openfiles_d[j - 1] = filestar;
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

/* Model step function */
void Spike_step(void)
{
  emxArray_char_T_Spike_T *A;
  emxArray_char_T_Spike_T *s1;
  int32_T idx;
  int32_T ntoread;
  real_T v1;
  boolean_T success;
  real_T v2;
  boolean_T isimag1;
  boolean_T isfinite1;
  boolean_T isfinite2;
  boolean_T c_success;
  int8_T fileid;
  FILE * b_NULL;
  FILE * f;
  emxArray_real_T_Spike_T *tmp;
  int32_T loop_ub;
  real_T y_re;
  Spike_emxInit_char_T(&A, 2);
  Spike_emxInit_real_T(&tmp, 2);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  Spike_readfile(A);
  y_re = (rtNaN);
  ntoread = 0;
  idx = tmp->size[0] * tmp->size[1];
  tmp->size[0] = 1;
  tmp->size[1] = A->size[1] + 2;
  Spike_emxEnsureCapacity_real_T(tmp, idx);
  loop_ub = A->size[1] + 2;
  for (idx = 0; idx < loop_ub; idx++) {
    tmp->data[idx] = 0.0;
  }

  Spike_emxInit_char_T(&s1, 2);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  Spike_char(tmp, s1);
  Spike_readfloat(s1, A, A->size[1], &idx, &loop_ub, &isimag1, &isfinite1, &v1,
                  &success);
  Spike_emxFree_real_T(&tmp);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (isfinite1) {
    ntoread = 1;
  }

  if (success && (loop_ub <= A->size[1])) {
    s1->data[idx - 1] = ' ';
    idx++;
    Spike_readfloat_ei(s1, &idx, A, &loop_ub, A->size[1], &success, &isfinite2,
                       &v2, &c_success);
    if (isfinite2) {
      ntoread++;
    }

    if (c_success && (loop_ub > A->size[1]) && ((isimag1 ^ success) != 0)) {
      success = true;
    } else {
      success = false;
    }
  } else {
    v2 = 0.0;
  }

  Spike_emxFree_char_T(&A);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (success) {
    s1->data[idx - 1] = '\x00';
    if (ntoread == 2) {
      Spike_sscanfd(s1, &v1, &v2);
    } else {
      if (ntoread == 1) {
        y_re = Spike_sscanfd_l(s1);
        if (isfinite1) {
          v1 = y_re;
        } else {
          v2 = y_re;
        }
      }
    }

    if (isimag1) {
      y_re = v2;
    } else {
      y_re = v1;
    }
  }

  Spike_emxFree_char_T(&s1);

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  fileid = Spike_cfopen_f("results.txt", "wb");
  b_NULL = NULL;
  if ((fileid > 22) || (fileid < 0)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    f = Spike_DW.eml_openfiles_d[fileid - 3];
    isimag1 = Spike_DW.eml_autoflush[fileid - 3];
  } else if (fileid == 0) {
    f = stdin;
    isimag1 = true;
  } else if (fileid == 1) {
    f = stdout;
    isimag1 = true;
  } else if (fileid == 2) {
    f = stderr;
    isimag1 = true;
  } else {
    f = NULL;
    isimag1 = true;
  }

  if (!(f == b_NULL)) {
    fprintf(f, "%f\n", y_re);
    if (isimag1) {
      fflush(f);
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */
}

/* Model initialize function */
void Spike_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Spike_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Spike_DW, 0,
                sizeof(DW_Spike_T));

  {
    FILE * a;
    int32_T i;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles[i] = a;

      /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
      Spike_DW.eml_autoflush[i] = false;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Spike_DW.eml_openfiles_d[i] = a;
    }
  }
}

/* Model terminate function */
void Spike_terminate(void)
{
  /* (no terminate code required) */
}
