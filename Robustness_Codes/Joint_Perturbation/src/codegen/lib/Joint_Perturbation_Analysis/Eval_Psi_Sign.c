/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Eval_Psi_Sign.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Eval_Psi_Sign.h"
#include "Joint_Perturbation_Analysis_emxutil.h"
#include "Find_Rectangle.h"

/* Function Definitions */

/*
 * Evaluate \psi(x) for each row in X
 * Arguments    : const emxArray_real_T *X
 *                const emxArray_real_T *R
 *                const emxArray_real_T *a
 *                emxArray_real_T *Psi
 * Return Type  : void
 */
void Eval_Psi_Sign(const emxArray_real_T *X, const emxArray_real_T *R, const
                   emxArray_real_T *a, emxArray_real_T *Psi)
{
  int end;
  int loop_ub;
  emxArray_real_T *I;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  emxArray_int32_T *J;
  end = Psi->size[0];
  Psi->size[0] = X->size[0];
  emxEnsureCapacity_real_T2(Psi, end);
  loop_ub = X->size[0];
  for (end = 0; end < loop_ub; end++) {
    Psi->data[end] = 1.0;
  }

  emxInit_real_T2(&I, 1);
  emxInit_boolean_T1(&x, 1);
  Find_Rectangle(X, R, I);
  end = x->size[0];
  x->size[0] = a->size[0];
  emxEnsureCapacity_boolean_T1(x, end);
  loop_ub = a->size[0];
  for (end = 0; end < loop_ub; end++) {
    x->data[end] = (a->data[end] == -1.0);
  }

  emxInit_int32_T(&ii, 1);
  nx = x->size[0];
  idx = 0;
  end = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity_int32_T1(ii, end);
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= nx)) {
    if (x->data[loop_ub - 1]) {
      idx++;
      ii->data[idx - 1] = loop_ub;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        loop_ub++;
      }
    } else {
      loop_ub++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      end = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity_int32_T1(ii, end);
    }
  } else {
    end = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T1(ii, end);
  }

  emxFree_boolean_T(&x);
  emxInit_int32_T(&J, 1);
  end = J->size[0];
  J->size[0] = ii->size[0];
  emxEnsureCapacity_int32_T1(J, end);
  loop_ub = ii->size[0];
  for (end = 0; end < loop_ub; end++) {
    J->data[end] = ii->data[end];
  }

  emxFree_int32_T(&ii);
  for (loop_ub = 0; loop_ub < J->size[0]; loop_ub++) {
    end = I->size[0];
    for (nx = 0; nx < end; nx++) {
      if (I->data[nx] == J->data[loop_ub]) {
        Psi->data[nx] = -1.0;
      }
    }
  }

  emxFree_int32_T(&J);
  emxFree_real_T(&I);
}

/*
 * File trailer for Eval_Psi_Sign.c
 *
 * [EOF]
 */
