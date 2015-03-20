/*
 * pinv.h
 *
 * Code generation for function 'pinv'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

#ifndef __PINV_H__
#define __PINV_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "hlblacklitterman_types.h"

/* Function Declarations */
extern void check_forloop_overflow_error(boolean_T overflow);
extern void pinv(const real_T A[7], real_T X[7]);
#endif
/* End of code generation (pinv.h) */
