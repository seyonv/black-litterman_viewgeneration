/*
 * hlblacklitterman.c
 *
 * Code generation for function 'hlblacklitterman'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "hlblacklitterman.h"
#include "pinv.h"
#include "inv.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 29, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo b_emlrtRSI = { 31, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo c_emlrtRSI = { 32, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo d_emlrtRSI = { 33, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo e_emlrtRSI = { 34, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo f_emlrtRSI = { 37, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo g_emlrtRSI = { 42, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo h_emlrtRSI = { 43, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo i_emlrtRSI = { 45, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo j_emlrtRSI = { 48, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo k_emlrtRSI = { 50, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

static emlrtRSInfo l_emlrtRSI = { 54, "hlblacklitterman",
  "/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m"
};

/* Function Definitions */
void hlblacklitterman(real_T delta, const real_T weq[7], const real_T sigma[49],
                      real_T tau, const real_T P[7], real_T Q, real_T Omega,
                      real_T er[7], real_T ps[49], real_T w[7], real_T pw[7],
                      real_T *lambda, real_T theta[3])
{
  real_T b_weq[7];
  real_T pi[7];
  int32_T i0;
  int32_T k;
  real_T ts[49];
  real_T y;
  real_T b[7];
  real_T b_b;
  real_T b_ts[7];
  real_T a[49];
  real_T b_a[49];
  real_T unusedExpr[49];
  real_T b_unusedExpr[49];
  real_T c_unusedExpr[7];
  int32_T i1;
  real_T posteriorSigma[49];

  /*  hlblacklitterman */
  /*    This function performs the Black-Litterman blending of the prior */
  /*    and the views into a new posterior estimate of the returns as */
  /*    described in the paper by He and Litterman. */
  /*  Inputs */
  /*    delta  - Risk tolerance from the equilibrium portfolio */
  /*    weq    - Weights of the assets in the equilibrium portfolio */
  /*    sigma  - Prior covariance matrix */
  /*    tau    - Coefficiet of uncertainty in the prior estimate of the mean (pi) */
  /*    P      - Pick matrix for the view(s) */
  /*    Q      - Vector of view returns */
  /*    Omega  - Matrix of variance of the views (diagonal) */
  /*  Outputs */
  /*    Er     - Posterior estimate of the mean returns */
  /*    w      - Unconstrained weights computed given the Posterior estimates */
  /*             of the mean and covariance of returns. */
  /*    lambda - A measure of the impact of each view on the posterior estimates. */
  /*    theta  - A measure of the share of the prior and sample information in the */
  /*             posterior precision. */
  /*  Reverse optimize and back out the equilibrium returns */
  /*  This is formula (12) page 6. */
  for (i0 = 0; i0 < 7; i0++) {
    b_weq[i0] = 0.0;
    for (k = 0; k < 7; k++) {
      b_weq[i0] += weq[k] * sigma[k + 7 * i0];
    }

    pi[i0] = b_weq[i0] * delta;
  }

  /*  We use tau * sigma many places so just compute it once */
  for (i0 = 0; i0 < 49; i0++) {
    ts[i0] = tau * sigma[i0];
  }

  /*  Compute posterior estimate of the mean */
  /*  This is a simplified version of formula (8) on page 4. */
  emlrtPushRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
  y = 0.0;
  for (i0 = 0; i0 < 7; i0++) {
    b[i0] = 0.0;
    for (k = 0; k < 7; k++) {
      b[i0] += P[k] * ts[k + 7 * i0];
    }

    y += b[i0] * P[i0];
  }

  b_b = inv(y + Omega);
  y = 0.0;
  for (k = 0; k < 7; k++) {
    y += P[k] * pi[k];
    b_ts[k] = 0.0;
    for (i0 = 0; i0 < 7; i0++) {
      b_ts[k] += ts[k + 7 * i0] * P[i0];
    }
  }

  y = Q - y;
  for (i0 = 0; i0 < 7; i0++) {
    er[i0] = pi[i0] + b_ts[i0] * b_b * y;
  }

  emlrtPopRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);

  /*  We can also do it the long way to illustrate that d1 + d2 = I */
  emlrtPushRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
  b_b = inv(Omega);
  b_inv(ts, a);
  for (i0 = 0; i0 < 7; i0++) {
    for (k = 0; k < 7; k++) {
      b_a[i0 + 7 * k] = a[i0 + 7 * k] + P[i0] * b_b * P[k];
    }
  }

  b_inv(b_a, unusedExpr);
  emlrtPopRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  b_inv(ts, b_unusedExpr);
  emlrtPopRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  inv(Omega);
  emlrtPopRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
  pinv(P, c_unusedExpr);
  emlrtPopRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);

  /*  Compute posterior estimate of the uncertainty in the mean */
  /*  This is a simplified and combined version of formulas (9) and (15) */
  emlrtPushRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
  y = 0.0;
  for (i0 = 0; i0 < 7; i0++) {
    b[i0] = 0.0;
    for (k = 0; k < 7; k++) {
      b[i0] += P[k] * ts[k + 7 * i0];
    }

    y += b[i0] * P[i0];
  }

  b_b = inv(y + Omega);
  for (i0 = 0; i0 < 7; i0++) {
    b_ts[i0] = 0.0;
    for (k = 0; k < 7; k++) {
      b_ts[i0] += ts[i0 + 7 * k] * P[k];
    }

    b_weq[i0] = b_ts[i0] * b_b;
    for (k = 0; k < 7; k++) {
      b_a[i0 + 7 * k] = b_weq[i0] * P[k];
    }
  }

  for (i0 = 0; i0 < 7; i0++) {
    for (k = 0; k < 7; k++) {
      y = 0.0;
      for (i1 = 0; i1 < 7; i1++) {
        y += b_a[i0 + 7 * i1] * ts[i1 + 7 * k];
      }

      ps[i0 + 7 * k] = ts[i0 + 7 * k] - y;
    }
  }

  emlrtPopRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < 49; i0++) {
    posteriorSigma[i0] = sigma[i0] + ps[i0];
  }

  /*  Compute the share of the posterior precision from prior and views, */
  /*  then for each individual view so we can compare it with lambda */
  emlrtPushRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
  b_inv(ts, a);
  y = 0.0;
  for (i0 = 0; i0 < 7; i0++) {
    for (k = 0; k < 7; k++) {
      ts[i0 + 7 * k] = 0.0;
      for (i1 = 0; i1 < 7; i1++) {
        ts[i0 + 7 * k] += a[i0 + 7 * i1] * ps[i1 + 7 * k];
      }
    }

    y += ts[i0 + 7 * i0];
  }

  theta[0] = y / 7.0;
  emlrtPopRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
  b_b = inv(Omega);
  y = 0.0;
  for (i0 = 0; i0 < 7; i0++) {
    for (k = 0; k < 7; k++) {
      b_a[i0 + 7 * k] = P[i0] * b_b * P[k];
    }

    for (k = 0; k < 7; k++) {
      ts[i0 + 7 * k] = 0.0;
      for (i1 = 0; i1 < 7; i1++) {
        ts[i0 + 7 * k] += b_a[i0 + 7 * i1] * ps[i1 + 7 * k];
      }
    }

    y += ts[i0 + 7 * i0];
  }

  theta[1] = y / 7.0;
  emlrtPopRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
  b_b = inv(Omega);
  y = 0.0;
  for (i0 = 0; i0 < 7; i0++) {
    for (k = 0; k < 7; k++) {
      b_a[i0 + 7 * k] = P[i0] * b_b * P[k];
    }

    for (k = 0; k < 7; k++) {
      ts[i0 + 7 * k] = 0.0;
      for (i1 = 0; i1 < 7; i1++) {
        ts[i0 + 7 * k] += b_a[i0 + 7 * i1] * ps[i1 + 7 * k];
      }
    }

    y += ts[i0 + 7 * i0];
  }

  theta[2] = y / 7.0;
  emlrtPopRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);

  /*  Compute posterior weights based solely on changed covariance */
  emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < 49; i0++) {
    b_a[i0] = delta * posteriorSigma[i0];
  }

  b_inv(b_a, ts);
  for (i0 = 0; i0 < 7; i0++) {
    b_weq[i0] = 0.0;
    for (k = 0; k < 7; k++) {
      b_weq[i0] += er[k] * ts[k + 7 * i0];
    }

    w[i0] = b_weq[i0];
  }

  emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);

  /*  Compute posterior weights based on uncertainty in mean and covariance */
  emlrtPushRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < 49; i0++) {
    b_a[i0] = delta * posteriorSigma[i0];
  }

  b_inv(b_a, a);
  for (i0 = 0; i0 < 7; i0++) {
    b_weq[i0] = 0.0;
    for (k = 0; k < 7; k++) {
      b_weq[i0] += pi[k] * a[k + 7 * i0];
    }

    pw[i0] = b_weq[i0];
  }

  emlrtPopRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);

  /*  Compute lambda value */
  /*  We solve for lambda from formula (17) page 7, rather than formula (18) */
  /*  just because it is less to type, and we've already computed w*. */
  emlrtPushRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
  pinv(P, b);
  *lambda = 0.0;
  for (i0 = 0; i0 < 7; i0++) {
    pi[i0] = b[i0];
    b_weq[i0] = 0.0;
    for (k = 0; k < 7; k++) {
      b_weq[i0] += er[k] * ts[k + 7 * i0];
    }

    b[i0] = b_weq[i0] * (1.0 + tau) - weq[i0];
    *lambda += pi[i0] * b[i0];
  }

  emlrtPopRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);

  /*  Black-Litterman example code for MatLab (hlblacklitterman.m) */
  /*  Copyright (c) Jay Walters, blacklitterman.org, 2008. */
  /*  */
  /*  Redistribution and use in source and binary forms,  */
  /*  with or without modification, are permitted provided  */
  /*  that the following conditions are met: */
  /*  */
  /*  Redistributions of source code must retain the above  */
  /*  copyright notice, this list of conditions and the following  */
  /*  disclaimer. */
  /*   */
  /*  Redistributions in binary form must reproduce the above  */
  /*  copyright notice, this list of conditions and the following  */
  /*  disclaimer in the documentation and/or other materials  */
  /*  provided with the distribution. */
  /*    */
  /*  Neither the name of blacklitterman.org nor the names of its */
  /*  contributors may be used to endorse or promote products  */
  /*  derived from this software without specific prior written */
  /*  permission. */
  /*    */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND  */
  /*  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,  */
  /*  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  */
  /*  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  */
  /*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  */
  /*  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  */
  /*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  */
  /*  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  */
  /*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  */
  /*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  */
  /*  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  */
  /*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  */
  /*  DAMAGE. */
  /*  */
  /*  This program uses the examples from the paper "The Intuition  */
  /*  Behind Black-Litterman Model  Portfolios", by He and Litterman, */
  /*  1999.  You can find a copy of this  paper at the following url. */
  /*      http:%papers.ssrn.com/sol3/papers.cfm?abstract_id=334304 */
  /*  */
  /*  For more details on the Black-Litterman model you can also view */
  /*  "The BlackLitterman Model: A Detailed Exploration", by this author */
  /*  at the following url. */
  /*      http:%www.blacklitterman.org/Black-Litterman.pdf */
  /*  */
}

/* End of code generation (hlblacklitterman.c) */
