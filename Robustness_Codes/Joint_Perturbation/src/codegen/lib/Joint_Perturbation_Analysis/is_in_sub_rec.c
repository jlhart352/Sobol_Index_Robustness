/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: is_in_sub_rec.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "is_in_sub_rec.h"
#include "Joint_Perturbation_Analysis_emxutil.h"
#include "sum.h"
#include "eml_setop.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *B
 *                emxArray_real_T *A
 *                double k
 *                emxArray_real_T *J_Sub
 * Return Type  : void
 */
void is_in_sub_rec(emxArray_real_T *B, emxArray_real_T *A, double k,
                   emxArray_real_T *J_Sub)
{
  emxArray_int8_T *J1;
  int p;
  int i1;
  int loop_ub;
  emxArray_int8_T *J2;
  emxArray_real_T *y;
  int idx;
  emxArray_real_T *c;
  emxArray_int32_T *ii;
  emxArray_real_T *b_A;
  int ib_size[1];
  int c_A;
  int nx;
  emxArray_real_T *b_B;
  emxArray_real_T *b_J1;
  double c_B;
  emxArray_boolean_T *x;
  emxArray_real_T *r11;
  boolean_T exitg1;
  emxInit_int8_T(&J1, 2);
  p = A->size[1];
  i1 = J1->size[0] * J1->size[1];
  J1->size[0] = A->size[0];
  J1->size[1] = A->size[1] - 1;
  emxEnsureCapacity_int8_T(J1, i1);
  loop_ub = A->size[0] * (A->size[1] - 1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    J1->data[i1] = 0;
  }

  emxInit_int8_T(&J2, 2);
  i1 = J2->size[0] * J2->size[1];
  J2->size[0] = A->size[0];
  J2->size[1] = A->size[1] - 1;
  emxEnsureCapacity_int8_T(J2, i1);
  loop_ub = A->size[0] * (A->size[1] - 1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    J2->data[i1] = 0;
  }

  emxInit_real_T(&y, 2);
  if (A->size[1] < 1) {
    i1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity_real_T(y, i1);
  } else {
    i1 = A->size[1];
    idx = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)((double)i1 - 1.0) + 1;
    emxEnsureCapacity_real_T(y, idx);
    loop_ub = (int)((double)i1 - 1.0);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      y->data[y->size[0] * i1] = 1.0 + (double)i1;
    }
  }

  emxInit_real_T(&c, 2);
  emxInit_int32_T(&ii, 1);
  emxInit_real_T(&b_A, 2);
  do_vectors(y, k, c, ii, ib_size);
  c_A = A->size[0];
  i1 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = c_A;
  b_A->size[1] = c->size[1];
  emxEnsureCapacity_real_T(b_A, i1);
  loop_ub = c->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (idx = 0; idx < c_A; idx++) {
      b_A->data[idx + b_A->size[0] * i1] = A->data[idx + A->size[0] * ((int)
        c->data[c->size[0] * i1] - 1)];
    }
  }

  i1 = A->size[0] * A->size[1];
  A->size[0] = b_A->size[0];
  A->size[1] = b_A->size[1];
  emxEnsureCapacity_real_T(A, i1);
  loop_ub = b_A->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    nx = b_A->size[0];
    for (idx = 0; idx < nx; idx++) {
      A->data[idx + A->size[0] * i1] = b_A->data[idx + b_A->size[0] * i1];
    }
  }

  emxFree_real_T(&b_A);
  if (p < 1) {
    i1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity_real_T(y, i1);
  } else {
    i1 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = p;
    emxEnsureCapacity_real_T(y, i1);
    loop_ub = p - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      y->data[y->size[0] * i1] = 1.0 + (double)i1;
    }
  }

  emxInit_real_T(&b_B, 2);
  do_vectors(y, k, c, ii, ib_size);
  i1 = b_B->size[0] * b_B->size[1];
  b_B->size[0] = c->size[1];
  b_B->size[1] = 2;
  emxEnsureCapacity_real_T(b_B, i1);
  emxFree_real_T(&y);
  for (i1 = 0; i1 < 2; i1++) {
    loop_ub = c->size[1];
    for (idx = 0; idx < loop_ub; idx++) {
      b_B->data[idx + b_B->size[0] * i1] = B->data[((int)c->data[c->size[0] *
        idx] + B->size[0] * i1) - 1];
    }
  }

  emxFree_real_T(&c);
  i1 = B->size[0] * B->size[1];
  B->size[0] = b_B->size[0];
  B->size[1] = 2;
  emxEnsureCapacity_real_T(B, i1);
  for (i1 = 0; i1 < 2; i1++) {
    loop_ub = b_B->size[0];
    for (idx = 0; idx < loop_ub; idx++) {
      B->data[idx + B->size[0] * i1] = b_B->data[idx + b_B->size[0] * i1];
    }
  }

  emxFree_real_T(&b_B);
  for (c_A = 0; c_A <= p - 2; c_A++) {
    c_B = B->data[c_A];
    loop_ub = A->size[0] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      J1->data[i1 + J1->size[0] * c_A] = (signed char)(c_B <= A->data[i1 +
        A->size[0] * c_A]);
    }

    c_B = B->data[c_A + B->size[0]];
    loop_ub = A->size[0] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      J2->data[i1 + J2->size[0] * c_A] = (signed char)(c_B >= A->data[i1 +
        A->size[0] * c_A]);
    }
  }

  emxInit_real_T(&b_J1, 2);
  i1 = b_J1->size[0] * b_J1->size[1];
  b_J1->size[0] = J1->size[0];
  b_J1->size[1] = J1->size[1];
  emxEnsureCapacity_real_T(b_J1, i1);
  loop_ub = J1->size[0] * J1->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_J1->data[i1] = (signed char)(J1->data[i1] * J2->data[i1]);
  }

  emxFree_int8_T(&J2);
  emxFree_int8_T(&J1);
  emxInit_boolean_T1(&x, 1);
  emxInit_real_T2(&r11, 1);
  b_sum(b_J1, r11);
  i1 = x->size[0];
  x->size[0] = r11->size[0];
  emxEnsureCapacity_boolean_T1(x, i1);
  loop_ub = r11->size[0];
  emxFree_real_T(&b_J1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    x->data[i1] = (r11->data[i1] == (double)p - 1.0);
  }

  emxFree_real_T(&r11);
  nx = x->size[0];
  idx = 0;
  i1 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity_int32_T1(ii, i1);
  c_A = 1;
  exitg1 = false;
  while ((!exitg1) && (c_A <= nx)) {
    if (x->data[c_A - 1]) {
      idx++;
      ii->data[idx - 1] = c_A;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        c_A++;
      }
    } else {
      c_A++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i1 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity_int32_T1(ii, i1);
    }
  } else {
    i1 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T1(ii, i1);
  }

  emxFree_boolean_T(&x);
  i1 = J_Sub->size[0];
  J_Sub->size[0] = ii->size[0];
  emxEnsureCapacity_real_T2(J_Sub, i1);
  loop_ub = ii->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    J_Sub->data[i1] = ii->data[i1];
  }

  emxFree_int32_T(&ii);
}

/*
 * File trailer for is_in_sub_rec.c
 *
 * [EOF]
 */
