/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hlblacklitterman.h"
#include "sqrt.h"
#include "hlblacklitterman_data.h"

/* Variable Definitions */
static emlrtRSInfo uc_emlrtRSI = { 14, "sqrt",
  "/Applications/MATLAB_R2013a.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };

/* Function Declarations */
static void c_eml_error(void);

/* Function Definitions */
static void c_eml_error(void)
{
  static char_T cv12[4][1] = { { 's' }, { 'q' }, { 'r' }, { 't' } };

  emlrtPushRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, cv12);
  emlrtPopRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
}

void b_sqrt(real_T *x)
{
  if (*x < 0.0) {
    emlrtPushRtStackR2012b(&uc_emlrtRSI, emlrtRootTLSGlobal);
    c_eml_error();
    emlrtPopRtStackR2012b(&uc_emlrtRSI, emlrtRootTLSGlobal);
  }

  *x = muDoubleScalarSqrt(*x);
}

/* End of code generation (sqrt.c) */
