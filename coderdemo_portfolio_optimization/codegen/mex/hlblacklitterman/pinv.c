/*
 * pinv.c
 *
 * Code generation for function 'pinv'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hlblacklitterman.h"
#include "pinv.h"
#include "sqrt.h"
#include "hlblacklitterman_mexutil.h"
#include "hlblacklitterman_data.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = { 51, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo rb_emlrtRSI = { 18, "pinv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/pinv.m" };

static emlrtRSInfo sb_emlrtRSI = { 40, "pinv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/pinv.m" };

static emlrtRSInfo tb_emlrtRSI = { 63, "pinv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/pinv.m" };

static emlrtRSInfo ub_emlrtRSI = { 64, "pinv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/pinv.m" };

static emlrtRSInfo vb_emlrtRSI = { 67, "pinv",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/pinv.m" };

static emlrtRSInfo wb_emlrtRSI = { 14, "svd",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/svd.m" };

static emlrtRSInfo xb_emlrtRSI = { 58, "svd",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/matfun/svd.m" };

static emlrtRSInfo ac_emlrtRSI = { 19, "eml_xgesvd",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"
};

static emlrtRSInfo bc_emlrtRSI = { 9, "eml_lapack_xgesvd",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"
};

static emlrtRSInfo cc_emlrtRSI = { 261, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo dc_emlrtRSI = { 274, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo fc_emlrtRSI = { 358, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo gc_emlrtRSI = { 371, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo hc_emlrtRSI = { 380, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo kc_emlrtRSI = { 343, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo lc_emlrtRSI = { 345, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo mc_emlrtRSI = { 324, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo oc_emlrtRSI = { 417, "eml_matlab_zsvdc",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo pc_emlrtRSI = { 16, "max",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/datafun/max.m" };

static emlrtRSInfo qc_emlrtRSI = { 18, "eml_min_or_max",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo rc_emlrtRSI = { 88, "eml_min_or_max",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo sc_emlrtRSI = { 192, "eml_min_or_max",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo tc_emlrtRSI = { 219, "eml_min_or_max",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo vc_emlrtRSI = { 18, "eml_xrotg",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"
};

static emlrtRSInfo xc_emlrtRSI = { 13, "eml_blas_xrotg",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo ad_emlrtRSI = { 47, "eml_blas_xrotg",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo bd_emlrtRSI = { 50, "eml_blas_xrotg",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo cd_emlrtRSI = { 53, "eml_blas_xrotg",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo dd_emlrtRSI = { 56, "eml_blas_xrotg",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo ed_emlrtRSI = { 59, "eml_blas_xrotg",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo fd_emlrtRSI = { 28, "eml_xscal",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"
};

static emlrtRSInfo gd_emlrtRSI = { 14, "eml_blas_xscal",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m"
};

static emlrtRSInfo hd_emlrtRSI = { 17, "eml_refblas_xscal",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m"
};

static emlrtRSInfo id_emlrtRSI = { 54, "eml_xgemm",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"
};

static emlrtRSInfo jd_emlrtRSI = { 20, "eml_blas_xgemm",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

static emlrtRSInfo kd_emlrtRSI = { 63, "eml_refblas_xgemm",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"
};

static emlrtRSInfo ld_emlrtRSI = { 126, "eml_refblas_xgemm",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"
};

static emlrtRSInfo md_emlrtRSI = { 134, "eml_refblas_xgemm",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"
};

static emlrtMCInfo e_emlrtMCI = { 52, 9, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo f_emlrtMCI = { 51, 15, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

/* Function Declarations */
static void b_eml_error(void);
static real_T eml_div(real_T x, real_T y);
static void eml_error(void);
static void eml_xgesvd(const real_T A[7], real_T U[7], real_T *S, real_T *V);
static real_T eml_xnrm2(const real_T x[7]);
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void eml_xscal(real_T a, real_T x[7]);
static void error(const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static void b_eml_error(void)
{
  emlrtPushRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &emlrtRTEI,
    "Coder:MATLAB:svd_NoConvergence", 0);
  emlrtPopRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
}

static real_T eml_div(real_T x, real_T y)
{
  return x / y;
}

static void eml_error(void)
{
  emlrtPushRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &emlrtRTEI,
    "Coder:MATLAB:svd_matrixWithNaNInf", 0);
  emlrtPopRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
}

static void eml_xgesvd(const real_T A[7], real_T U[7], real_T *S, real_T *V)
{
  real_T b_A[7];
  int32_T i;
  real_T nrm;
  int32_T m;
  real_T e;
  real_T r;
  int32_T iter;
  boolean_T exitg1;
  int32_T ix;
  int32_T k;
  real_T emm1;
  real_T b;
  real_T varargin_1[5];
  boolean_T exitg2;
  real_T sm;
  emlrtPushRtStackR2012b(&ac_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&bc_emlrtRSI, emlrtRootTLSGlobal);
  for (i = 0; i < 7; i++) {
    b_A[i] = A[i];
  }

  nrm = eml_xnrm2(A);
  if (nrm > 0.0) {
    if (A[0] < 0.0) {
      *S = -nrm;
    } else {
      *S = nrm;
    }

    eml_xscal(eml_div(1.0, *S), b_A);
    b_A[0]++;
    *S = -*S;
  } else {
    *S = 0.0;
  }

  for (i = 0; i < 7; i++) {
    U[i] = b_A[i];
  }

  m = 1;
  e = 0.0;
  if (*S != 0.0) {
    for (i = 0; i < 7; i++) {
      U[i] = -U[i];
    }

    U[0]++;
  } else {
    for (i = 0; i < 7; i++) {
      U[i] = 0.0;
    }

    U[0] = 1.0;
  }

  *V = 1.0;
  if (*S != 0.0) {
    nrm = muDoubleScalarAbs(*S);
    r = eml_div(*S, nrm);
    *S = nrm;
    eml_xscal(r, U);
  }

  iter = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (m > 0)) {
    if (iter >= 75) {
      emlrtPushRtStackR2012b(&cc_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&cc_emlrtRSI, emlrtRootTLSGlobal);
      exitg1 = TRUE;
    } else {
      emlrtPushRtStackR2012b(&dc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&dc_emlrtRSI, emlrtRootTLSGlobal);
      i = 1;
      if (*S < 0.0) {
        *S = -*S;
        emlrtPushRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&fd_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&gd_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&hd_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&hd_emlrtRSI, emlrtRootTLSGlobal);
        *V = -*V;
        emlrtPopRtStackR2012b(&gd_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&fd_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      }

      iter = 2;
      while ((i < 1) && (*S < *S)) {
        ix = 7 * (i - 1);
        i *= 7;
        for (k = 0; k < 7; k++) {
          nrm = U[ix];
          U[ix] = U[i];
          U[i] = nrm;
          ix++;
          i++;
        }

        i = iter;
        iter++;
      }

      iter = 0;
      m = 0;
    }
  }

  emlrtPopRtStackR2012b(&bc_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ac_emlrtRSI, emlrtRootTLSGlobal);
}

static real_T eml_xnrm2(const real_T x[7])
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 7; k++) {
    absxk = muDoubleScalarAbs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T b_b;
  real_T b_a;
  double * a_t;
  double * b_t;
  double * c_t;
  double * s_t;
  emlrtPushRtStackR2012b(&vc_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&xc_emlrtRSI, emlrtRootTLSGlobal);
  b_b = *b;
  b_a = *a;
  *c = 0.0;
  *s = 0.0;
  emlrtPushRtStackR2012b(&ad_emlrtRSI, emlrtRootTLSGlobal);
  a_t = (double *)(&b_a);
  emlrtPopRtStackR2012b(&ad_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&bd_emlrtRSI, emlrtRootTLSGlobal);
  b_t = (double *)(&b_b);
  emlrtPopRtStackR2012b(&bd_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&cd_emlrtRSI, emlrtRootTLSGlobal);
  c_t = (double *)(c);
  emlrtPopRtStackR2012b(&cd_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&dd_emlrtRSI, emlrtRootTLSGlobal);
  s_t = (double *)(s);
  emlrtPopRtStackR2012b(&dd_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&ed_emlrtRSI, emlrtRootTLSGlobal);
  drotg(a_t, b_t, c_t, s_t);
  emlrtPopRtStackR2012b(&ed_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&xc_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&vc_emlrtRSI, emlrtRootTLSGlobal);
  *a = b_a;
  *b = b_b;
}

static void eml_xscal(real_T a, real_T x[7])
{
  int32_T k;
  for (k = 0; k < 7; k++) {
    x[k] *= a;
  }
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", TRUE,
                        location);
}

void check_forloop_overflow_error(boolean_T overflow)
{
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 34 };

  const mxArray *m4;
  char_T cv8[34];
  int32_T i;
  static const char_T cv9[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *b_y;
  static const int32_T iv6[2] = { 1, 23 };

  char_T cv10[23];
  static const char_T cv11[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't',
    'e', 'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  if (!overflow) {
  } else {
    emlrtPushRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
    y = NULL;
    m4 = mxCreateCharArray(2, iv5);
    for (i = 0; i < 34; i++) {
      cv8[i] = cv9[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 34, m4, cv8);
    emlrtAssign(&y, m4);
    b_y = NULL;
    m4 = mxCreateCharArray(2, iv6);
    for (i = 0; i < 23; i++) {
      cv10[i] = cv11[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 23, m4, cv10);
    emlrtAssign(&b_y, m4);
    error(b_message(y, b_y, &e_emlrtMCI), &f_emlrtMCI);
    emlrtPopRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
  }
}

void pinv(const real_T A[7], real_T X[7])
{
  real_T b_X[7];
  int32_T r;
  real_T V;
  real_T s;
  real_T U[7];
  int32_T ic;
  int32_T br;
  int32_T ib;
  emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
  for (r = 0; r < 7; r++) {
    b_X[r] = 0.0;
  }

  emlrtPushRtStackR2012b(&sb_emlrtRSI, emlrtRootTLSGlobal);
  for (r = 0; r < 7; r++) {
    if (!((!muDoubleScalarIsInf(A[r])) && (!muDoubleScalarIsNaN(A[r])))) {
      emlrtPushRtStackR2012b(&wb_emlrtRSI, emlrtRootTLSGlobal);
      eml_error();
      emlrtPopRtStackR2012b(&wb_emlrtRSI, emlrtRootTLSGlobal);
    }
  }

  emlrtPushRtStackR2012b(&xb_emlrtRSI, emlrtRootTLSGlobal);
  eml_xgesvd(A, U, &s, &V);
  emlrtPopRtStackR2012b(&xb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&sb_emlrtRSI, emlrtRootTLSGlobal);
  r = 0;
  if (!(s > 7.0 * s * 2.2204460492503131E-16)) {
  } else {
    r = 1;
  }

  if (r > 0) {
    emlrtPushRtStackR2012b(&tb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&tb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ub_emlrtRSI, emlrtRootTLSGlobal);
    s = 1.0 / s;
    emlrtPushRtStackR2012b(&fd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&gd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&hd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&hd_emlrtRSI, emlrtRootTLSGlobal);
    r = 1;
    while (r <= 1) {
      V *= s;
      r = 2;
    }

    emlrtPopRtStackR2012b(&gd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&fd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ub_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&vb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&id_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&jd_emlrtRSI, emlrtRootTLSGlobal);
    for (r = 0; r < 7; r++) {
      emlrtPushRtStackR2012b(&kd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&kd_emlrtRSI, emlrtRootTLSGlobal);
      for (ic = r; ic + 1 <= r + 1; ic++) {
        b_X[ic] = 0.0;
      }
    }

    br = 0;
    for (r = 0; r < 7; r++) {
      br++;
      emlrtPushRtStackR2012b(&ld_emlrtRSI, emlrtRootTLSGlobal);
      if (br > 2147483640) {
        emlrtPushRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error(TRUE);
        emlrtPopRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ld_emlrtRSI, emlrtRootTLSGlobal);
      for (ib = br; ib <= br; ib += 7) {
        if (U[ib - 1] != 0.0) {
          emlrtPushRtStackR2012b(&md_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&md_emlrtRSI, emlrtRootTLSGlobal);
          for (ic = r; ic + 1 <= r + 1; ic++) {
            b_X[ic] += U[ib - 1] * V;
          }
        }
      }
    }

    emlrtPopRtStackR2012b(&jd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&id_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&vb_emlrtRSI, emlrtRootTLSGlobal);
  }

  for (r = 0; r < 7; r++) {
    X[r] = b_X[r];
  }

  emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
}

/* End of code generation (pinv.c) */
