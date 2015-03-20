/*
 * hlblacklitterman.h
 *
 * Code generation for function 'hlblacklitterman'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

#ifndef __HLBLACKLITTERMAN_H__
#define __HLBLACKLITTERMAN_H__
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
extern void hlblacklitterman(real_T delta, const real_T weq[7], const real_T sigma[49], real_T tau, const real_T P[7], real_T Q, real_T Omega, real_T er[7], real_T ps[49], real_T w[7], real_T pw[7], real_T *lambda, real_T theta[3]);
#endif
/* End of code generation (hlblacklitterman.h) */
