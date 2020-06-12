/*
 * Spike.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "Spike".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Jun 12 11:24:53 2020
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
static void Spike_emxInit_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray,
  int32_T numDimensions);
static void Spike_emxInit_int32_T(emxArray_int32_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static int8_T Spike_filedata(void);
static int8_T Spike_cfopen(const char * cfilename, const char * cpermission);
static FILE * Spike_fileManager(real_T varargin_1);
static void Spike_emxInit_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static void Spike_emxEnsureCapacity_uint8_T(emxArray_uint8_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_emxFree_uint8_T(emxArray_uint8_T_Spike_T **pEmxArray);
static int32_T Spike_cfclose(real_T fid);
static void Spike_emxEnsureCapacity_char_T(emxArray_char_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_readfile(emxArray_char_T_Spike_T *y);
static void Spi_emxEnsureCapacity_boolean_T(emxArray_boolean_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_isstrprop(const emxArray_char_T_Spike_T *x,
  emxArray_boolean_T_Spike_T *y);
static void Spike_emxEnsureCapacity_int32_T(emxArray_int32_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_emxFree_boolean_T(emxArray_boolean_T_Spike_T **pEmxArray);
static void Spike_emxFree_int32_T(emxArray_int32_T_Spike_T **pEmxArray);
static void Spike_emxFree_char_T(emxArray_char_T_Spike_T **pEmxArray);
static void Spike_emxInit_real_T(emxArray_real_T_Spike_T **pEmxArray, int32_T
  numDimensions);
static void Spike_emxEnsureCapacity_real_T(emxArray_real_T_Spike_T *emxArray,
  int32_T oldNumel);
static void Spike_char(const emxArray_real_T_Spike_T *varargin_1,
  emxArray_char_T_Spike_T *y);
static void Spike_skipspaces(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n);
static void Spike_copysign(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *foundsign,
  boolean_T *success);
static boolean_T Spike_isUnitImag(const emxArray_char_T_Spike_T *s, int32_T k,
  int32_T n);
static void Spike_readNonFinite(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n, boolean_T *b_finite, real_T *fv);
static boolean_T Spike_copydigits(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowpoint);
static boolean_T Spike_copyexponent(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n);
static void Spike_skipspaces_d(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n);
static void Spike_readfloat(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowimag,
  boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign,
  boolean_T *success);
static void Spike_emxFree_real_T(emxArray_real_T_Spike_T **pEmxArray);
static real_T Spike_sscanfd_p(const emxArray_char_T_Spike_T *s);
static void Spike_sscanfd(const emxArray_char_T_Spike_T *s, real_T *out1, real_T
  *out2);
static creal_T Spike_str2double(const emxArray_char_T_Spike_T *s);
static int8_T Spike_filedata_k(void);
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static int32_T Spike_cfclose(real_T fid)
{
  int32_T st;
  int8_T fileid;
  int32_T cst;
  FILE * f;
  int8_T b_fileid;
  st = -1;
  fileid = (int8_T)rt_roundd_snf(fid);
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
  real_T position;
  long position_t;
  int wherefrom;
  FILE * b_filestar;
  emxArray_uint8_T_Spike_T *A;
  int8_T fileid;
  size_t nBytes;
  int32_T numRequested;
  int32_T bytesOut;
  int32_T numRead;
  char_T buf_data[1024];
  int32_T num2Read;
  int32_T c_numRead;
  size_t numReadSizeT;
  int16_T bdims_idx_0;
  int32_T i;
  boolean_T exitg1;
  fileid = Spike_cfopen("nums1.txt", "rb");
  wherefrom = SEEK_END;
  b_filestar = Spike_fileManager((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  b_filestar = Spike_fileManager((real_T)fileid);
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
      i = (int32_T)position;
    } else {
      i = MIN_int32_T;
    }
  } else {
    i = MAX_int32_T;
  }

  wherefrom = SEEK_SET;
  b_filestar = Spike_fileManager((real_T)fileid);
  if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
    b_filestar = NULL;
  }

  if (!(b_filestar == NULL)) {
    fseek(b_filestar, (long int)0.0, wherefrom);
  }

  memset(&Spike_B.buffer[0], 0, sizeof(uint8_T) << 16U);
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
      b_filestar = Spike_fileManager((real_T)fileid);
      if ((fileid == 0) || (fileid == 1) || (fileid == 2)) {
        b_filestar = NULL;
      }

      if (b_filestar == NULL) {
        A->size[0] = 0;
        bytesOut = 0;
      } else {
        numRead = A->size[0];
        A->size[0] = remaining;
        Spike_emxEnsureCapacity_uint8_T(A, numRead);
        if (remaining > 1024) {
          bdims_idx_0 = 1024;
        } else {
          bdims_idx_0 = (int16_T)remaining;
        }

        bytesOut = 0;
        numRead = 1;
        numRequested = bdims_idx_0;
        while ((bytesOut < remaining) && (numRead > 0)) {
          num2Read = numRequested;
          numRead = remaining - bytesOut;
          if (numRequested > numRead) {
            num2Read = numRead;
          }

          numRequested = bdims_idx_0;
          numRead = 0;
          c_numRead = 1;
          while ((numRead < num2Read) && (c_numRead > 0)) {
            numReadSizeT = fread(&buf_data[numRead], nBytes, num2Read - numRead,
                                 b_filestar);
            c_numRead = (int32_T)numReadSizeT;
            numRead += (int32_T)numReadSizeT;
          }

          for (num2Read = 0; num2Read < numRead; num2Read++) {
            A->data[num2Read + bytesOut] = (uint8_T)buf_data[num2Read];
          }

          bytesOut += numRead;
        }

        numRequested = A->size[0];
        for (numRead = bytesOut; numRead < numRequested; numRead++) {
          A->data[numRead] = 0U;
        }

        if (bytesOut < remaining) {
          numRead = A->size[0];
          if (1 > bytesOut) {
            A->size[0] = 0;
          } else {
            A->size[0] = bytesOut;
          }

          Spike_emxEnsureCapacity_uint8_T(A, numRead);
        }
      }

      position = (real_T)b_index + (real_T)bytesOut;
      if (position < 2.147483648E+9) {
        if (position >= -2.147483648E+9) {
          numRead = (int32_T)position;
        } else {
          numRead = MIN_int32_T;
        }
      } else {
        numRead = MAX_int32_T;
      }

      numRead -= 2;
      if (b_index > numRead + 1) {
        numRequested = -1;
        numRead = -1;
      } else {
        numRequested = b_index - 2;
      }

      num2Read = numRead - numRequested;
      for (numRead = 0; numRead < num2Read; numRead++) {
        Spike_B.buffer[(numRequested + numRead) + 1] = A->data[numRead];
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
  Spike_cfclose((real_T)fileid);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_index;
  Spike_emxEnsureCapacity_char_T(y, i);
  for (i = 0; i < b_index; i++) {
    y->data[i] = (int8_T)Spike_B.buffer[i];
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Spike_isstrprop(const emxArray_char_T_Spike_T *x,
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
    y->data[k] = b[(uint8_T)x->data[k] & 127];
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
static void Spike_skipspaces(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n)
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
  while ((*k <= n) && (b[(uint8_T)s->data[*k - 1] & 127] || (s->data[*k - 1] ==
           '\x00'))) {
    (*k)++;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Spike_copysign(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T *foundsign,
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
    } else if (!b[(uint8_T)s->data[*k - 1] & 127]) {
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static boolean_T Spike_isUnitImag(const emxArray_char_T_Spike_T *s, int32_T k,
  int32_T n)
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Spike_readNonFinite(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n, boolean_T *b_finite, real_T *fv)
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static boolean_T Spike_copydigits(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowpoint)
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static boolean_T Spike_copyexponent(emxArray_char_T_Spike_T *s1, int32_T *idx,
  const emxArray_char_T_Spike_T *s, int32_T *k, int32_T n)
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Spike_skipspaces_d(const emxArray_char_T_Spike_T *s, int32_T *k,
  int32_T n)
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

  while ((*k <= n) && (b[(uint8_T)s->data[*k - 1] & 127] || (s->data[*k - 1] ==
           '\x00') || (s->data[*k - 1] == ','))) {
    (*k)++;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Spike_readfloat(emxArray_char_T_Spike_T *s1, int32_T *idx, const
  emxArray_char_T_Spike_T *s, int32_T *k, int32_T n, boolean_T allowimag,
  boolean_T *isimag, boolean_T *b_finite, real_T *nfv, boolean_T *foundsign,
  boolean_T *success)
{
  int32_T b_idx;
  int32_T b_k;
  boolean_T unusedU1;
  boolean_T unusedU2;
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
        Spike_skipspaces_d(s, k, n);
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

      Spike_skipspaces_d(s, k, n);
      if ((*k <= n) && (s->data[*k - 1] == '*')) {
        (*k)++;
        Spike_skipspaces_d(s, k, n);
      }

      if ((*k <= n) && ((s->data[*k - 1] == 'i') || (s->data[*k - 1] == 'j'))) {
        (*k)++;
        *isimag = true;
      }
    }

    Spike_skipspaces_d(s, k, n);
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
static real_T Spike_sscanfd_p(const emxArray_char_T_Spike_T *s)
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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
  int32_T k;
  boolean_T isimag1;
  boolean_T isfinite1;
  boolean_T unusedU0;
  boolean_T foundsign;
  boolean_T c_success;
  emxArray_real_T_Spike_T *tmp;
  x.re = (rtNaN);
  x.im = 0.0;
  if (s->size[1] >= 1) {
    Spike_emxInit_real_T(&tmp, 2);
    ntoread = 0;
    k = tmp->size[0] * tmp->size[1];
    tmp->size[0] = 1;
    tmp->size[1] = s->size[1] + 2;
    Spike_emxEnsureCapacity_real_T(tmp, k);
    idx = s->size[1] + 2;
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

      if (c_success && (k > s->size[1]) && (((isimag1 ^ unusedU0) != 0) &&
           foundsign)) {
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
          a = Spike_sscanfd_p(s1);
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

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static int8_T Spike_filedata_k(void)
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

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static int8_T Spike_cfopen_f(const char * cfilename, const char * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = Spike_filedata_k();
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

/* Model step function */
void Spike_step(void)
{
  emxArray_char_T_Spike_T *A;
  emxArray_boolean_T_Spike_T *TF;
  emxArray_int32_T_Spike_T *ii;
  int32_T nx;
  int32_T idx;
  int32_T b_ii;
  FILE * b_NULL;
  int8_T fileid;
  FILE * f;
  boolean_T a;
  emxArray_char_T_Spike_T *A_0;
  creal_T tmp;
  boolean_T exitg1;
  Spike_emxInit_char_T(&A, 2);
  Spike_emxInit_boolean_T(&TF, 2);
  Spike_emxInit_int32_T(&ii, 2);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  Spike_readfile(A);
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

  Spike_emxFree_boolean_T(&TF);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (ii->data[ii->size[1] - 3] > A->size[1]) {
    nx = 0;
    idx = 0;
  } else {
    nx = ii->data[ii->size[1] - 3] - 1;
    idx = A->size[1];
  }

  Spike_emxFree_int32_T(&ii);
  Spike_emxInit_char_T(&A_0, 2);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  b_ii = A_0->size[0] * A_0->size[1];
  A_0->size[0] = 1;
  idx -= nx;
  A_0->size[1] = idx;
  Spike_emxEnsureCapacity_char_T(A_0, b_ii);
  for (b_ii = 0; b_ii < idx; b_ii++) {
    A_0->data[b_ii] = A->data[nx + b_ii];
  }

  Spike_emxFree_char_T(&A);

  /* MATLAB Function: '<Root>/MATLAB Function' */
  tmp = Spike_str2double(A_0);

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  fileid = Spike_cfopen_f("results.txt", "wb");
  b_NULL = NULL;
  Spike_emxFree_char_T(&A_0);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
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
    fprintf(f, "%f\n", tmp.re);
    if (a) {
      fflush(f);
    }
  }
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
      Spike_DW.eml_openfiles_c[i] = a;
    }
  }
}

/* Model terminate function */
void Spike_terminate(void)
{
  /* (no terminate code required) */
}
