/*
 * norm.c
 *
 * Code generation for function 'norm'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hlblacklitterman.h"
#include "norm.h"

/* Function Definitions */
real_T norm(const real_T x[49])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  real_T s;
  int32_T i;
  y = 0.0;
  j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (j < 7)) {
    s = 0.0;
    for (i = 0; i < 7; i++) {
      s += muDoubleScalarAbs(x[i + 7 * j]);
    }

    if (muDoubleScalarIsNaN(s)) {
      y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

/* End of code generation (norm.c) */
