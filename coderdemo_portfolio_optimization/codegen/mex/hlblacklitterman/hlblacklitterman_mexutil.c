/*
 * hlblacklitterman_mexutil.c
 *
 * Code generation for function 'hlblacklitterman_mexutil'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hlblacklitterman.h"
#include "hlblacklitterman_mexutil.h"

/* Function Definitions */
const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location)
{
  const mxArray *pArrays[2];
  const mxArray *m13;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m13, 2, pArrays,
    "message", TRUE, location);
}

const mxArray *emlrt_marshallOut(real_T u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = mxCreateDoubleScalar(u);
  emlrtAssign(&y, m5);
  return y;
}

/* End of code generation (hlblacklitterman_mexutil.c) */
