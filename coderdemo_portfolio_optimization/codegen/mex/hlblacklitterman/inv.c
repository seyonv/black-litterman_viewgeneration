/*
 * inv.c
 *
 * Code generation for function 'inv'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hlblacklitterman.h"
#include "inv.h"
#include "pinv.h"
#include "norm.h"
#include "hlblacklitterman_mexutil.h"
#include "hlblacklitterman_data.h"

/* Variable Definitions */
static emlrtRSInfo m_emlrtRSI = { 21, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo n_emlrtRSI = { 40, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo o_emlrtRSI = { 44, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo p_emlrtRSI = { 16, "eml_warning",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtRSInfo q_emlrtRSI = { 29, "eml_flt2str",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

static emlrtRSInfo r_emlrtRSI = { 17, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo s_emlrtRSI = { 18, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo t_emlrtRSI = { 170, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo u_emlrtRSI = { 177, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo v_emlrtRSI = { 180, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo w_emlrtRSI = { 187, "inv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo x_emlrtRSI = { 8, "eml_xgetrf",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"
};

static emlrtRSInfo y_emlrtRSI = { 8, "eml_lapack_xgetrf",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"
};

static emlrtRSInfo ab_emlrtRSI = { 36, "eml_matlab_zgetrf",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo bb_emlrtRSI = { 50, "eml_matlab_zgetrf",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo cb_emlrtRSI = { 58, "eml_matlab_zgetrf",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo db_emlrtRSI = { 20, "eml_ixamax",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"
};

static emlrtRSInfo eb_emlrtRSI = { 18, "eml_blas_ixamax",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m"
};

static emlrtRSInfo fb_emlrtRSI = { 23, "eml_refblas_ixamax",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m"
};

static emlrtRSInfo ib_emlrtRSI = { 42, "eml_xgeru",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"
};

static emlrtRSInfo jb_emlrtRSI = { 37, "eml_xger",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/eml_xger.m" };

static emlrtRSInfo kb_emlrtRSI = { 18, "eml_blas_xger",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"
};

static emlrtRSInfo lb_emlrtRSI = { 14, "eml_refblas_xger",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m"
};

static emlrtRSInfo mb_emlrtRSI = { 40, "eml_refblas_xgerx",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"
};

static emlrtRSInfo nb_emlrtRSI = { 53, "eml_refblas_xgerx",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m"
};

static emlrtRSInfo ob_emlrtRSI = { 54, "eml_xtrsm",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"
};

static emlrtRSInfo pb_emlrtRSI = { 20, "eml_blas_xtrsm",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo qb_emlrtRSI = { 57, "eml_refblas_xtrsm",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m"
};

static emlrtMCInfo emlrtMCI = { 16, 13, "eml_warning",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtMCInfo b_emlrtMCI = { 16, 5, "eml_warning",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtMCInfo c_emlrtMCI = { 29, 23, "eml_flt2str",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

static emlrtMCInfo d_emlrtMCI = { 29, 15, "eml_flt2str",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

/* Function Declarations */
static void b_eml_warning(const char_T varargin_2[14]);
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[14]);
static const mxArray *b_sprintf(const mxArray *b, const mxArray *c, const
  mxArray *d, emlrtMCInfo *location);
static const mxArray *c_sprintf(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location);
static void eml_warning(void);
static void emlrt_marshallIn(const mxArray *d_sprintf, const char_T *identifier,
  char_T y[14]);
static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[14]);
static void invNxN(const real_T x[49], real_T y[49]);
static const mxArray *message(const mxArray *b, emlrtMCInfo *location);
static void warning(const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static void b_eml_warning(const char_T varargin_2[14])
{
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 33 };

  const mxArray *m2;
  char_T cv4[33];
  int32_T i;
  static const char_T cv5[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i', 'o',
    'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 14 };

  char_T b_varargin_2[14];
  emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  y = NULL;
  m2 = mxCreateCharArray(2, iv2);
  for (i = 0; i < 33; i++) {
    cv4[i] = cv5[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 33, m2, cv4);
  emlrtAssign(&y, m2);
  b_y = NULL;
  m2 = mxCreateCharArray(2, iv3);
  for (i = 0; i < 14; i++) {
    b_varargin_2[i] = varargin_2[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 14, m2, b_varargin_2);
  emlrtAssign(&b_y, m2);
  warning(b_message(y, b_y, &emlrtMCI), &b_emlrtMCI);
  emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
}

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[14])
{
  i_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const mxArray *b, const mxArray *c, const
  mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m11;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m11, 3, pArrays,
    "sprintf", TRUE, location);
}

static const mxArray *c_sprintf(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[2];
  const mxArray *m12;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m12, 2, pArrays,
    "sprintf", TRUE, location);
}

static void eml_warning(void)
{
  const mxArray *y;
  static const int32_T iv1[2] = { 1, 27 };

  const mxArray *m1;
  char_T cv2[27];
  int32_T i;
  static const char_T cv3[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  y = NULL;
  m1 = mxCreateCharArray(2, iv1);
  for (i = 0; i < 27; i++) {
    cv2[i] = cv3[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 27, m1, cv2);
  emlrtAssign(&y, m1);
  warning(message(y, &emlrtMCI), &b_emlrtMCI);
  emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
}

static void emlrt_marshallIn(const mxArray *d_sprintf, const char_T *identifier,
  char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(emlrtAlias(d_sprintf), &thisId, y);
  emlrtDestroyArray(&d_sprintf);
}

static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[14])
{
  int32_T iv14[2];
  int32_T i3;
  for (i3 = 0; i3 < 2; i3++) {
    iv14[i3] = 1 + 13 * i3;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", FALSE, 2U,
    iv14);
  emlrtImportCharArray(src, ret, 14);
  emlrtDestroyArray(&src);
}

static void invNxN(const real_T x[49], real_T y[49])
{
  real_T A[49];
  int8_T ipiv[7];
  int32_T pipk;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T smax;
  int32_T k;
  real_T s;
  int32_T b;
  int32_T jy;
  boolean_T b_pipk;
  int32_T ijA;
  int8_T p[7];
  memset(&y[0], 0, 49U * sizeof(real_T));
  emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
  memcpy(&A[0], &x[0], 49U * sizeof(real_T));
  for (pipk = 0; pipk < 7; pipk++) {
    ipiv[pipk] = (int8_T)(1 + pipk);
  }

  for (j = 0; j < 6; j++) {
    c = j << 3;
    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
    pipk = 0;
    ix = c;
    smax = muDoubleScalarAbs(A[c]);
    emlrtPushRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
    for (k = 2; k <= 7 - j; k++) {
      ix++;
      s = muDoubleScalarAbs(A[ix]);
      if (s > smax) {
        pipk = k - 1;
        smax = s;
      }
    }

    emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    if (A[c + pipk] != 0.0) {
      if (pipk != 0) {
        ipiv[j] = (int8_T)((j + pipk) + 1);
        ix = j;
        pipk += j;
        for (k = 0; k < 7; k++) {
          smax = A[ix];
          A[ix] = A[pipk];
          A[pipk] = smax;
          ix += 7;
          pipk += 7;
        }
      }

      b = (c - j) + 7;
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      for (jy = c + 1; jy + 1 <= b; jy++) {
        A[jy] /= A[c];
      }
    }

    emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
    pipk = c;
    jy = c + 7;
    emlrtPushRtStackR2012b(&mb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&mb_emlrtRSI, emlrtRootTLSGlobal);
    for (k = 1; k <= 6 - j; k++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = c + 1;
        b = (pipk - j) + 14;
        emlrtPushRtStackR2012b(&nb_emlrtRSI, emlrtRootTLSGlobal);
        if (pipk + 9 > b) {
          b_pipk = FALSE;
        } else {
          b_pipk = (b > 2147483646);
        }

        if (b_pipk) {
          emlrtPushRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
          check_forloop_overflow_error(TRUE);
          emlrtPopRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&nb_emlrtRSI, emlrtRootTLSGlobal);
        for (ijA = pipk + 8; ijA + 1 <= b; ijA++) {
          A[ijA] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 7;
      pipk += 7;
    }

    emlrtPopRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  for (pipk = 0; pipk < 7; pipk++) {
    p[pipk] = (int8_T)(1 + pipk);
  }

  for (k = 0; k < 6; k++) {
    if (ipiv[k] > 1 + k) {
      pipk = p[ipiv[k] - 1];
      p[ipiv[k] - 1] = p[k];
      p[k] = (int8_T)pipk;
    }
  }

  for (k = 0; k < 7; k++) {
    y[k + 7 * (p[k] - 1)] = 1.0;
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    for (j = k; j + 1 < 8; j++) {
      if (y[j + 7 * (p[k] - 1)] != 0.0) {
        emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
        for (jy = j + 1; jy + 1 < 8; jy++) {
          y[jy + 7 * (p[k] - 1)] -= y[j + 7 * (p[k] - 1)] * A[jy + 7 * j];
        }
      }
    }
  }

  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&ob_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&pb_emlrtRSI, emlrtRootTLSGlobal);
  for (j = 0; j < 7; j++) {
    c = 7 * j;
    for (k = 6; k > -1; k += -1) {
      pipk = 7 * k;
      if (y[k + c] != 0.0) {
        y[k + c] /= A[k + pipk];
        emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
        for (jy = 0; jy + 1 <= k; jy++) {
          y[jy + c] -= y[k + c] * A[jy + pipk];
        }
      }
    }
  }

  emlrtPopRtStackR2012b(&pb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ob_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
}

static const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m10;
  pArray = b;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m10, 1, &pArray,
    "message", TRUE, location);
}

static void warning(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "warning", TRUE,
                        location);
}

void b_inv(const real_T x[49], real_T y[49])
{
  real_T n1x;
  real_T n1xinv;
  real_T rc;
  const mxArray *b_y;
  static const int32_T iv4[2] = { 1, 8 };

  const mxArray *m3;
  char_T cv6[8];
  int32_T i;
  static const char_T cv7[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T str[14];
  emlrtPushRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
  invNxN(x, y);
  emlrtPopRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
  n1x = norm(x);
  n1xinv = norm(y);
  rc = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (rc == 0.0)) {
    emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
    eml_warning();
    emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      b_y = NULL;
      m3 = mxCreateCharArray(2, iv4);
      for (i = 0; i < 8; i++) {
        cv6[i] = cv7[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m3, cv6);
      emlrtAssign(&b_y, m3);
      emlrt_marshallIn(c_sprintf(b_sprintf(b_y, emlrt_marshallOut(14.0),
        emlrt_marshallOut(6.0), &c_emlrtMCI), emlrt_marshallOut(rc), &d_emlrtMCI),
                       "sprintf", str);
      emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_warning(str);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
    }
  }

  emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
}

real_T inv(real_T x)
{
  real_T y;
  real_T n1x;
  real_T n1xinv;
  real_T rc;
  const mxArray *b_y;
  static const int32_T iv0[2] = { 1, 8 };

  const mxArray *m0;
  char_T cv0[8];
  int32_T i;
  static const char_T cv1[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T str[14];
  y = 1.0 / x;
  emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
  n1x = muDoubleScalarAbs(x);
  n1xinv = muDoubleScalarAbs(y);
  rc = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (rc == 0.0)) {
    emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
    eml_warning();
    emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      b_y = NULL;
      m0 = mxCreateCharArray(2, iv0);
      for (i = 0; i < 8; i++) {
        cv0[i] = cv1[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m0, cv0);
      emlrtAssign(&b_y, m0);
      emlrt_marshallIn(c_sprintf(b_sprintf(b_y, emlrt_marshallOut(14.0),
        emlrt_marshallOut(6.0), &c_emlrtMCI), emlrt_marshallOut(rc), &d_emlrtMCI),
                       "sprintf", str);
      emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_warning(str);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
    }
  }

  emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
  return y;
}

/* End of code generation (inv.c) */
