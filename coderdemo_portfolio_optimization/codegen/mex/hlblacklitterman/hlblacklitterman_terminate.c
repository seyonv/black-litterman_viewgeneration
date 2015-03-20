/*
 * hlblacklitterman_terminate.c
 *
 * Code generation for function 'hlblacklitterman_terminate'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hlblacklitterman.h"
#include "hlblacklitterman_terminate.h"

/* Function Definitions */
void hlblacklitterman_atexit(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void hlblacklitterman_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (hlblacklitterman_terminate.c) */
