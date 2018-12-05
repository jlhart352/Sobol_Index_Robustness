/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Sample_std_Estimate_Weights.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Sample_std_Estimate_Weights.h"
#include "combineVectorElements.h"
#include "Joint_Perturbation_Analysis_emxutil.h"
#include "power.h"
#include "sort1.h"
#include "rand.h"
#include "Joint_Perturbation_Analysis_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double m
 *                const emxArray_real_T *YA
 *                const emxArray_real_T *YCk
 *                const emxArray_real_T *weight_A
 *                const emxArray_real_T *weight_Ck
 * Return Type  : double
 */
double Sample_std_Estimate_Weights(double m, const emxArray_real_T *YA, const
  emxArray_real_T *YCk, const emxArray_real_T *weight_A, const emxArray_real_T
  *weight_Ck)
{
  double sd;
  emxArray_real_T *samps;
  int varargin_1;
  int i;
  int k;
  emxArray_real_T *absdiff;
  emxArray_real_T *rp;
  emxArray_boolean_T *selected;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_real_T *x;
  emxArray_real_T *b_x;
  emxArray_real_T *r13;
  emxArray_real_T *b_YA;
  int c_x;
  int n;
  double xbar;
  int nsel;
  int b_rp[2];
  double scale;
  int j;
  double absxk;
  int i2;
  double t;
  int pEnd;
  int p;
  int q;
  int qEnd;
  int kEnd;
  emxInit_real_T2(&samps, 1);
  varargin_1 = YA->size[0];
  i = samps->size[0];
  samps->size[0] = (int)m;
  emxEnsureCapacity_real_T2(samps, i);
  k = 0;
  emxInit_real_T2(&absdiff, 1);
  emxInit_real_T(&rp, 2);
  emxInit_boolean_T(&selected, 2);
  emxInit_int32_T1(&idx, 2);
  emxInit_int32_T(&iwork, 1);
  emxInit_real_T2(&x, 1);
  emxInit_real_T2(&b_x, 1);
  emxInit_real_T2(&r13, 1);
  emxInit_real_T2(&b_YA, 1);
  while (k <= (int)m - 1) {
    c_x = (int)rt_roundd_snf(0.5 * (double)varargin_1);
    i = absdiff->size[0];
    absdiff->size[0] = c_x;
    emxEnsureCapacity_real_T2(absdiff, i);
    if ((c_x << 2) > varargin_1) {
      b_rand(varargin_1, rp);
      n = rp->size[1] + 1;
      i = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = rp->size[1];
      emxEnsureCapacity_int32_T(idx, i);
      nsel = rp->size[1];
      for (i = 0; i < nsel; i++) {
        idx->data[i] = 0;
      }

      if (rp->size[1] != 0) {
        nsel = rp->size[1];
        i = iwork->size[0];
        iwork->size[0] = nsel;
        emxEnsureCapacity_int32_T1(iwork, i);
        for (nsel = 1; nsel <= n - 2; nsel += 2) {
          if ((rp->data[nsel - 1] <= rp->data[nsel]) || rtIsNaN(rp->data[nsel]))
          {
            idx->data[nsel - 1] = nsel;
            idx->data[nsel] = nsel + 1;
          } else {
            idx->data[nsel - 1] = nsel + 1;
            idx->data[nsel] = nsel;
          }
        }

        if ((rp->size[1] & 1) != 0) {
          idx->data[rp->size[1] - 1] = rp->size[1];
        }

        i = 2;
        while (i < n - 1) {
          i2 = i << 1;
          j = 1;
          for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
            p = j;
            q = pEnd - 1;
            qEnd = j + i2;
            if (qEnd > n) {
              qEnd = n;
            }

            nsel = 0;
            kEnd = qEnd - j;
            while (nsel + 1 <= kEnd) {
              if ((rp->data[idx->data[p - 1] - 1] <= rp->data[idx->data[q] - 1])
                  || rtIsNaN(rp->data[idx->data[q] - 1])) {
                iwork->data[nsel] = idx->data[p - 1];
                p++;
                if (p == pEnd) {
                  while (q + 1 < qEnd) {
                    nsel++;
                    iwork->data[nsel] = idx->data[q];
                    q++;
                  }
                }
              } else {
                iwork->data[nsel] = idx->data[q];
                q++;
                if (q + 1 == qEnd) {
                  while (p < pEnd) {
                    nsel++;
                    iwork->data[nsel] = idx->data[p - 1];
                    p++;
                  }
                }
              }

              nsel++;
            }

            for (nsel = 0; nsel < kEnd; nsel++) {
              idx->data[(j + nsel) - 1] = iwork->data[nsel];
            }

            j = qEnd;
          }

          i = i2;
        }
      }

      for (i = 0; i < 2; i++) {
        b_rp[i] = rp->size[i];
      }

      i = rp->size[0] * rp->size[1];
      rp->size[0] = 1;
      rp->size[1] = b_rp[1];
      emxEnsureCapacity_real_T(rp, i);
      nsel = b_rp[1];
      for (i = 0; i < nsel; i++) {
        rp->data[rp->size[0] * i] = idx->data[b_rp[0] * i];
      }

      for (j = 0; j < c_x; j++) {
        absdiff->data[j] = (int)rp->data[j];
      }
    } else {
      i = selected->size[0] * selected->size[1];
      selected->size[0] = 1;
      selected->size[1] = varargin_1;
      emxEnsureCapacity_boolean_T(selected, i);
      for (i = 0; i < varargin_1; i++) {
        selected->data[i] = false;
      }

      nsel = 0;
      while (nsel < c_x) {
        xbar = c_rand();
        xbar = floor(xbar * (double)varargin_1);
        if (!selected->data[(int)(1.0 + xbar) - 1]) {
          selected->data[(int)(1.0 + xbar) - 1] = true;
          nsel++;
          absdiff->data[nsel - 1] = 1.0 + xbar;
        }
      }
    }

    sort(absdiff);
    i = x->size[0];
    x->size[0] = absdiff->size[0];
    emxEnsureCapacity_real_T2(x, i);
    nsel = absdiff->size[0];
    for (i = 0; i < nsel; i++) {
      x->data[i] = weight_A->data[(int)absdiff->data[i] - 1] * YA->data[(int)
        absdiff->data[i] - 1];
    }

    xbar = combineVectorElements(x) / (double)x->size[0];
    i = b_YA->size[0];
    b_YA->size[0] = absdiff->size[0];
    emxEnsureCapacity_real_T2(b_YA, i);
    nsel = absdiff->size[0];
    for (i = 0; i < nsel; i++) {
      b_YA->data[i] = YA->data[(int)absdiff->data[i] - 1] - xbar;
    }

    power(b_YA, r13);
    i = x->size[0];
    x->size[0] = absdiff->size[0];
    emxEnsureCapacity_real_T2(x, i);
    nsel = absdiff->size[0];
    for (i = 0; i < nsel; i++) {
      x->data[i] = weight_A->data[(int)absdiff->data[i] - 1] * r13->data[i];
    }

    i = b_YA->size[0];
    b_YA->size[0] = absdiff->size[0];
    emxEnsureCapacity_real_T2(b_YA, i);
    nsel = absdiff->size[0];
    for (i = 0; i < nsel; i++) {
      b_YA->data[i] = YA->data[(int)absdiff->data[i] - 1] - YCk->data[(int)
        absdiff->data[i] - 1];
    }

    power(b_YA, r13);
    i = b_x->size[0];
    b_x->size[0] = absdiff->size[0];
    emxEnsureCapacity_real_T2(b_x, i);
    nsel = absdiff->size[0];
    for (i = 0; i < nsel; i++) {
      b_x->data[i] = weight_Ck->data[(int)absdiff->data[i] - 1] * r13->data[i];
    }

    samps->data[k] = 0.5 * (combineVectorElements(b_x) / (double)b_x->size[0]) /
      (combineVectorElements(x) / (double)x->size[0]);
    k++;
  }

  emxFree_real_T(&b_YA);
  emxFree_real_T(&r13);
  emxFree_real_T(&b_x);
  emxFree_real_T(&x);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emxFree_boolean_T(&selected);
  emxFree_real_T(&rp);
  n = samps->size[0];
  if (samps->size[0] == 0) {
    xbar = rtNaN;
  } else if (samps->size[0] == 1) {
    if ((!rtIsInf(samps->data[0])) && (!rtIsNaN(samps->data[0]))) {
      xbar = 0.0;
    } else {
      xbar = rtNaN;
    }
  } else {
    xbar = samps->data[0];
    for (k = 2; k <= n; k++) {
      xbar += samps->data[k - 1];
    }

    xbar /= (double)samps->size[0];
    i = absdiff->size[0];
    absdiff->size[0] = samps->size[0];
    emxEnsureCapacity_real_T2(absdiff, i);
    for (k = 0; k < n; k++) {
      absdiff->data[k] = fabs(samps->data[k] - xbar);
    }

    xbar = 0.0;
    scale = 3.3121686421112381E-170;
    for (k = 1; k <= samps->size[0]; k++) {
      absxk = absdiff->data[k - 1];
      if (absxk > scale) {
        t = scale / absxk;
        xbar = 1.0 + xbar * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        xbar += t * t;
      }
    }

    xbar = scale * sqrt(xbar);
    xbar /= sqrt((double)samps->size[0] - 1.0);
  }

  emxFree_real_T(&absdiff);
  sd = xbar / (combineVectorElements(samps) / (double)samps->size[0]);
  emxFree_real_T(&samps);
  return sd;
}

/*
 * File trailer for Sample_std_Estimate_Weights.c
 *
 * [EOF]
 */
