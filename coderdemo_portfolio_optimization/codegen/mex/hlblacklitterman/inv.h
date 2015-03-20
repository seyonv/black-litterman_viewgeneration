/*
 * inv.h
 *
 * Code generation for function 'inv'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

#ifndef __INV_H__
#define __INV_H__
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
extern void b_inv(const real_T x[49], real_T y[49]);
extern real_T inv(real_T x);
#ifdef __WATCOMC__
#pragma aux inv value [8087];
#endif
#endif
/* End of code generation (inv.h) */
