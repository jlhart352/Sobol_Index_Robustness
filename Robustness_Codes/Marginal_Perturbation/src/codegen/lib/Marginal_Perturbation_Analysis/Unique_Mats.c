/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Unique_Mats.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "Unique_Mats.h"
#include "svd.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *B
 *                emxArray_real_T *idx
 * Return Type  : void
 */
void Unique_Mats(const emxArray_real_T *A, emxArray_real_T *B, emxArray_real_T
                 *idx)
{
  emxArray_real_T *I;
  int p;
  boolean_T is_new;
  int j;
  int loop_ub;
  int k;
  emxArray_real_T *x;
  emxArray_real_T *r8;
  int b_j;
  double l;
  int b_loop_ub;
  int i4;
  double y;
  unsigned int count;
  double absxk;
  double t;
  emxInit_real_T2(&I, 1);
  p = A->size[1] - 1;
  is_new = true;
  j = I->size[0];
  I->size[0] = A->size[1];
  emxEnsureCapacity_real_T2(I, j);
  loop_ub = A->size[1];
  for (j = 0; j < loop_ub; j++) {
    I->data[j] = 0.0;
  }

  I->data[0] = 1.0;
  k = 0;
  emxInit_real_T(&x, 2);
  emxInit_real_T2(&r8, 1);
  while (k <= p - 1) {
    for (b_j = 0; b_j <= k; b_j++) {
      loop_ub = A->size[0];
      b_loop_ub = A->size[1];
      j = x->size[0] * x->size[1];
      x->size[0] = loop_ub;
      x->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T1(x, j);
      for (j = 0; j < b_loop_ub; j++) {
        for (i4 = 0; i4 < loop_ub; i4++) {
          x->data[i4 + x->size[0] * j] = A->data[(i4 + A->size[0] * j) + A->
            size[0] * A->size[1] * (k + 1)] - A->data[(i4 + A->size[0] * j) +
            A->size[0] * A->size[1] * b_j];
        }
      }

      if ((x->size[0] == 0) || (x->size[1] == 0)) {
        y = 0.0;
      } else if ((x->size[0] == 1) || (x->size[1] == 1)) {
        j = x->size[0] * x->size[1];
        y = 0.0;
        if (!(j < 1)) {
          if (j == 1) {
            y = fabs(x->data[0]);
          } else {
            l = 3.3121686421112381E-170;
            for (loop_ub = 1; loop_ub <= j; loop_ub++) {
              absxk = fabs(x->data[loop_ub - 1]);
              if (absxk > l) {
                t = l / absxk;
                y = 1.0 + y * t * t;
                l = absxk;
              } else {
                t = absxk / l;
                y += t * t;
              }
            }

            y = l * sqrt(y);
          }
        }
      } else {
        y = 0.0;
        for (j = 1; j <= x->size[1]; j++) {
          for (loop_ub = 1; loop_ub <= x->size[0]; loop_ub++) {
            l = fabs(x->data[(loop_ub + x->size[0] * (j - 1)) - 1]);
            if (rtIsNaN(l) || (l > y)) {
              y = l;
            }
          }
        }

        if ((!rtIsInf(y)) && (!rtIsNaN(y))) {
          svd(x, r8);
          y = r8->data[0];
        }
      }

      if (y == 0.0) {
        is_new = false;
      }
    }

    if (is_new) {
      I->data[k + 1] = 1.0;
    }

    is_new = true;
    k++;
  }

  emxFree_real_T(&r8);
  emxFree_real_T(&x);
  l = sum(I);
  j = B->size[0] * B->size[1] * B->size[2];
  B->size[0] = A->size[0];
  B->size[1] = A->size[1];
  B->size[2] = (int)l;
  emxEnsureCapacity_real_T(B, j);
  loop_ub = A->size[0] * A->size[1] * (int)l;
  for (j = 0; j < loop_ub; j++) {
    B->data[j] = 0.0;
  }

  j = idx->size[0];
  idx->size[0] = (int)l;
  emxEnsureCapacity_real_T2(idx, j);
  loop_ub = (int)l;
  for (j = 0; j < loop_ub; j++) {
    idx->data[j] = 0.0;
  }

  count = 1U;
  for (k = 0; k <= p; k++) {
    if (I->data[k] == 1.0) {
      loop_ub = A->size[0] - 1;
      b_loop_ub = A->size[1] - 1;
      for (j = 0; j <= b_loop_ub; j++) {
        for (i4 = 0; i4 <= loop_ub; i4++) {
          B->data[(i4 + B->size[0] * j) + B->size[0] * B->size[1] * ((int)count
            - 1)] = A->data[(i4 + A->size[0] * j) + A->size[0] * A->size[1] * k];
        }
      }

      idx->data[(int)count - 1] = 1.0 + (double)k;
      count++;
    }
  }

  emxFree_real_T(&I);
}

/*
 * File trailer for Unique_Mats.c
 *
 * [EOF]
 */
