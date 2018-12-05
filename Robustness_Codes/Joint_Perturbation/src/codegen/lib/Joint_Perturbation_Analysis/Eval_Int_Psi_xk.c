/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Eval_Int_Psi_xk.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Eval_Int_Psi_xk.h"
#include "Joint_Perturbation_Analysis_emxutil.h"
#include "eml_setop.h"

/* Function Definitions */

/*
 * Evaluate int_{\Omega_k} \psi(x) dx_k for each row in X
 * Arguments    : const emxArray_real_T *X
 *                double k
 *                const emxArray_real_T *R
 *                const emxArray_real_T *a
 *                const emxArray_real_T *psi_val
 *                emxArray_real_T *Psi_k
 * Return Type  : void
 */
void Eval_Int_Psi_xk(const emxArray_real_T *X, double k, const emxArray_real_T
                     *R, const emxArray_real_T *a, const emxArray_real_T
                     *psi_val, emxArray_real_T *Psi_k)
{
  emxArray_real_T *y;
  int b_k;
  int idx;
  emxArray_real_T *u;
  emxArray_int32_T *ia;
  int ib_size[1];
  int n;
  double c;
  int i;
  emxArray_real_T *x;
  int j;
  double ex;
  boolean_T exitg1;
  emxInit_real_T(&y, 2);
  if (X->size[1] < 1) {
    b_k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity_real_T(y, b_k);
  } else {
    b_k = X->size[1];
    idx = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)((double)b_k - 1.0) + 1;
    emxEnsureCapacity_real_T(y, idx);
    idx = (int)((double)b_k - 1.0);
    for (b_k = 0; b_k <= idx; b_k++) {
      y->data[y->size[0] * b_k] = 1.0 + (double)b_k;
    }
  }

  emxInit_real_T(&u, 2);
  emxInit_int32_T(&ia, 1);
  do_vectors(y, k, u, ia, ib_size);
  n = R->size[0];
  emxFree_int32_T(&ia);
  if ((R->size[0] > 0) && ((R->size[1] == 0) || (R->size[1] > R->size[0]))) {
    n = R->size[1];
  }

  if ((n > 0) && (2 > n)) {
    n = 2;
  }

  c = 0.0;
  b_k = Psi_k->size[0];
  Psi_k->size[0] = X->size[0];
  emxEnsureCapacity_real_T2(Psi_k, b_k);
  i = 0;
  emxInit_real_T(&x, 2);
  while (i <= X->size[0] - 1) {
    for (j = 0; j < n; j++) {
      b_k = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = u->size[1];
      emxEnsureCapacity_real_T(y, b_k);
      idx = u->size[1];
      for (b_k = 0; b_k < idx; b_k++) {
        y->data[y->size[0] * b_k] = X->data[i + X->size[0] * ((int)u->data
          [u->size[0] * b_k] - 1)];
      }

      b_k = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = u->size[1];
      emxEnsureCapacity_real_T(x, b_k);
      idx = u->size[1];
      for (b_k = 0; b_k < idx; b_k++) {
        x->data[x->size[0] * b_k] = R->data[j + R->size[0] * ((int)u->data
          [u->size[0] * b_k] - 1)];
      }

      idx = y->size[0] * y->size[1] - 1;
      b_k = y->size[0] * y->size[1];
      y->size[0] = 1;
      emxEnsureCapacity_real_T(y, b_k);
      for (b_k = 0; b_k <= idx; b_k++) {
        y->data[b_k] -= x->data[b_k];
      }

      if (y->size[1] <= 2) {
        if (y->size[1] == 1) {
          ex = y->data[0];
        } else if ((y->data[0] > y->data[1]) || (rtIsNaN(y->data[0]) &&
                    (!rtIsNaN(y->data[1])))) {
          ex = y->data[1];
        } else {
          ex = y->data[0];
        }
      } else {
        if (!rtIsNaN(y->data[0])) {
          idx = 1;
        } else {
          idx = 0;
          b_k = 2;
          exitg1 = false;
          while ((!exitg1) && (b_k <= y->size[1])) {
            if (!rtIsNaN(y->data[b_k - 1])) {
              idx = b_k;
              exitg1 = true;
            } else {
              b_k++;
            }
          }
        }

        if (idx == 0) {
          ex = y->data[0];
        } else {
          ex = y->data[idx - 1];
          while (idx + 1 <= y->size[1]) {
            if (ex > y->data[idx]) {
              ex = y->data[idx];
            }

            idx++;
          }
        }
      }

      if (ex >= 0.0) {
        b_k = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = u->size[1];
        emxEnsureCapacity_real_T(x, b_k);
        idx = u->size[1];
        for (b_k = 0; b_k < idx; b_k++) {
          x->data[x->size[0] * b_k] = R->data[(j + R->size[0] * ((int)u->data
            [u->size[0] * b_k] - 1)) + R->size[0] * R->size[1]];
        }

        b_k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = u->size[1];
        emxEnsureCapacity_real_T(y, b_k);
        idx = u->size[1];
        for (b_k = 0; b_k < idx; b_k++) {
          y->data[y->size[0] * b_k] = X->data[i + X->size[0] * ((int)u->data
            [u->size[0] * b_k] - 1)];
        }

        idx = u->size[1];
        b_k = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = idx;
        emxEnsureCapacity_real_T(x, b_k);
        for (b_k = 0; b_k < idx; b_k++) {
          x->data[x->size[0] * b_k] = x->data[b_k] - y->data[y->size[0] * b_k];
        }

        if (x->size[1] <= 2) {
          if (x->size[1] == 1) {
            ex = x->data[0];
          } else if ((x->data[0] > x->data[1]) || (rtIsNaN(x->data[0]) &&
                      (!rtIsNaN(x->data[1])))) {
            ex = x->data[1];
          } else {
            ex = x->data[0];
          }
        } else {
          if (!rtIsNaN(x->data[0])) {
            idx = 1;
          } else {
            idx = 0;
            b_k = 2;
            exitg1 = false;
            while ((!exitg1) && (b_k <= x->size[1])) {
              if (!rtIsNaN(x->data[b_k - 1])) {
                idx = b_k;
                exitg1 = true;
              } else {
                b_k++;
              }
            }
          }

          if (idx == 0) {
            ex = x->data[0];
          } else {
            ex = x->data[idx - 1];
            while (idx + 1 <= x->size[1]) {
              if (ex > x->data[idx]) {
                ex = x->data[idx];
              }

              idx++;
            }
          }
        }

        if (ex >= 0.0) {
          c += psi_val->data[j] * a->data[j] * (R->data[(j + R->size[0] * ((int)
            k - 1)) + R->size[0] * R->size[1]] - R->data[j + R->size[0] * ((int)
            k - 1)]);
        }
      }
    }

    Psi_k->data[i] = c;
    c = 0.0;
    i++;
  }

  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emxFree_real_T(&u);
}

/*
 * File trailer for Eval_Int_Psi_xk.c
 *
 * [EOF]
 */
