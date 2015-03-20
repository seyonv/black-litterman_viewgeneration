/*
 * hlblacklitterman_initialize.c
 *
 * Code generation for function 'hlblacklitterman_initialize'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hlblacklitterman.h"
#include "hlblacklitterman_initialize.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar;

/* Function Definitions */
void hlblacklitterman_initialize(emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (hlblacklitterman_initialize.c) */
