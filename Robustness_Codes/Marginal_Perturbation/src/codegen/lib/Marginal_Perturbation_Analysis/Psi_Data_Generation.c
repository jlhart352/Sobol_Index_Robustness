/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Psi_Data_Generation.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "Psi_Data_Generation.h"
#include "eml_setop.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"

/* Function Definitions */

/*
 * Unpack data from computing Sobol' indices
 * Arguments    : const emxArray_real_T *Sobol_Output_A
 *                const emxArray_real_T *Sobol_Output_B
 *                const emxArray_real_T *Phi_Data_phi_A
 *                const emxArray_real_T *Phi_Data_phi_B
 *                const emxArray_real_T *I
 *                emxArray_real_T *psi_val
 * Return Type  : void
 */
void Psi_Data_Generation(const emxArray_real_T *Sobol_Output_A, const
  emxArray_real_T *Sobol_Output_B, const emxArray_real_T *Phi_Data_phi_A, const
  emxArray_real_T *Phi_Data_phi_B, const emxArray_real_T *I, emxArray_real_T
  *psi_val)
{
  int k;
  int b_k;
  emxArray_real_T *IA;
  emxArray_real_T *IB;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_int32_T *b_ii;
  emxArray_real_T *c_ii;
  emxArray_real_T *d_ii;
  int i;
  int n;
  double b_I;
  int nx;
  int idx;
  boolean_T exitg1;
  double ex;

  /*  Preallocate arrays */
  k = psi_val->size[0] * psi_val->size[1];
  psi_val->size[0] = I->size[0] - 1;
  psi_val->size[1] = Sobol_Output_A->size[1];
  emxEnsureCapacity_real_T1(psi_val, k);
  b_k = 0;
  emxInit_real_T2(&IA, 1);
  emxInit_real_T2(&IB, 1);
  emxInit_boolean_T(&x, 1);
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&b_ii, 1);
  emxInit_real_T2(&c_ii, 1);
  emxInit_real_T2(&d_ii, 1);
  while (b_k <= I->size[0] - 2) {
    for (i = 0; i < Sobol_Output_A->size[1]; i++) {
      n = Sobol_Output_A->size[0];
      b_I = I->data[b_k + I->size[0] * i];
      k = x->size[0];
      x->size[0] = n;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < n; k++) {
        x->data[k] = (Sobol_Output_A->data[k + Sobol_Output_A->size[0] * i] >
                      b_I);
      }

      nx = x->size[0];
      idx = 0;
      k = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(ii, k);
      n = 1;
      exitg1 = false;
      while ((!exitg1) && (n <= nx)) {
        if (x->data[n - 1]) {
          idx++;
          ii->data[idx - 1] = n;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            n++;
          }
        } else {
          n++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          k = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity_int32_T(ii, k);
        }
      } else {
        k = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(ii, k);
      }

      n = Sobol_Output_A->size[0];
      b_I = I->data[(b_k + I->size[0] * i) + 1];
      k = x->size[0];
      x->size[0] = n;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < n; k++) {
        x->data[k] = (Sobol_Output_A->data[k + Sobol_Output_A->size[0] * i] <
                      b_I);
      }

      nx = x->size[0];
      idx = 0;
      k = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(b_ii, k);
      n = 1;
      exitg1 = false;
      while ((!exitg1) && (n <= nx)) {
        if (x->data[n - 1]) {
          idx++;
          b_ii->data[idx - 1] = n;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            n++;
          }
        } else {
          n++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          k = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity_int32_T(b_ii, k);
        }
      } else {
        k = b_ii->size[0];
        if (1 > idx) {
          b_ii->size[0] = 0;
        } else {
          b_ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(b_ii, k);
      }

      k = c_ii->size[0];
      c_ii->size[0] = ii->size[0];
      emxEnsureCapacity_real_T2(c_ii, k);
      n = ii->size[0];
      for (k = 0; k < n; k++) {
        c_ii->data[k] = ii->data[k];
      }

      k = d_ii->size[0];
      d_ii->size[0] = b_ii->size[0];
      emxEnsureCapacity_real_T2(d_ii, k);
      n = b_ii->size[0];
      for (k = 0; k < n; k++) {
        d_ii->data[k] = b_ii->data[k];
      }

      do_vectors(c_ii, d_ii, IA, ii, b_ii);
      n = Sobol_Output_B->size[0];
      b_I = I->data[b_k + I->size[0] * i];
      k = x->size[0];
      x->size[0] = n;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < n; k++) {
        x->data[k] = (Sobol_Output_B->data[k + Sobol_Output_B->size[0] * i] >
                      b_I);
      }

      nx = x->size[0];
      idx = 0;
      k = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(ii, k);
      n = 1;
      exitg1 = false;
      while ((!exitg1) && (n <= nx)) {
        if (x->data[n - 1]) {
          idx++;
          ii->data[idx - 1] = n;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            n++;
          }
        } else {
          n++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          k = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity_int32_T(ii, k);
        }
      } else {
        k = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(ii, k);
      }

      n = Sobol_Output_B->size[0];
      b_I = I->data[(b_k + I->size[0] * i) + 1];
      k = x->size[0];
      x->size[0] = n;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < n; k++) {
        x->data[k] = (Sobol_Output_B->data[k + Sobol_Output_B->size[0] * i] <
                      b_I);
      }

      nx = x->size[0];
      idx = 0;
      k = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(b_ii, k);
      n = 1;
      exitg1 = false;
      while ((!exitg1) && (n <= nx)) {
        if (x->data[n - 1]) {
          idx++;
          b_ii->data[idx - 1] = n;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            n++;
          }
        } else {
          n++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          k = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity_int32_T(b_ii, k);
        }
      } else {
        k = b_ii->size[0];
        if (1 > idx) {
          b_ii->size[0] = 0;
        } else {
          b_ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(b_ii, k);
      }

      k = c_ii->size[0];
      c_ii->size[0] = ii->size[0];
      emxEnsureCapacity_real_T2(c_ii, k);
      n = ii->size[0];
      for (k = 0; k < n; k++) {
        c_ii->data[k] = ii->data[k];
      }

      k = d_ii->size[0];
      d_ii->size[0] = b_ii->size[0];
      emxEnsureCapacity_real_T2(d_ii, k);
      n = b_ii->size[0];
      for (k = 0; k < n; k++) {
        d_ii->data[k] = b_ii->data[k];
      }

      do_vectors(c_ii, d_ii, IB, ii, b_ii);
      n = IA->size[0];
      if (IA->size[0] <= 2) {
        if (IA->size[0] == 1) {
          b_I = Phi_Data_phi_A->data[((int)IA->data[0] + Phi_Data_phi_A->size[0]
            * i) - 1];
        } else if ((Phi_Data_phi_A->data[((int)IA->data[0] +
                     Phi_Data_phi_A->size[0] * i) - 1] > Phi_Data_phi_A->data
                    [((int)IA->data[1] + Phi_Data_phi_A->size[0] * i) - 1]) ||
                   (rtIsNaN(Phi_Data_phi_A->data[((int)IA->data[0] +
                      Phi_Data_phi_A->size[0] * i) - 1]) && (!rtIsNaN
                     (Phi_Data_phi_A->data[((int)IA->data[1] +
            Phi_Data_phi_A->size[0] * i) - 1])))) {
          b_I = Phi_Data_phi_A->data[((int)IA->data[1] + Phi_Data_phi_A->size[0]
            * i) - 1];
        } else {
          b_I = Phi_Data_phi_A->data[((int)IA->data[0] + Phi_Data_phi_A->size[0]
            * i) - 1];
        }
      } else {
        if (!rtIsNaN(Phi_Data_phi_A->data[((int)IA->data[0] +
              Phi_Data_phi_A->size[0] * i) - 1])) {
          idx = 1;
        } else {
          idx = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= IA->size[0])) {
            if (!rtIsNaN(Phi_Data_phi_A->data[((int)IA->data[k - 1] +
                  Phi_Data_phi_A->size[0] * i) - 1])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }

        if (idx == 0) {
          b_I = Phi_Data_phi_A->data[((int)IA->data[0] + Phi_Data_phi_A->size[0]
            * i) - 1];
        } else {
          b_I = Phi_Data_phi_A->data[((int)IA->data[idx - 1] +
            Phi_Data_phi_A->size[0] * i) - 1];
          while (idx + 1 <= n) {
            if (b_I > Phi_Data_phi_A->data[((int)IA->data[idx] +
                 Phi_Data_phi_A->size[0] * i) - 1]) {
              b_I = Phi_Data_phi_A->data[((int)IA->data[idx] +
                Phi_Data_phi_A->size[0] * i) - 1];
            }

            idx++;
          }
        }
      }

      n = IB->size[0];
      if (IB->size[0] <= 2) {
        if (IB->size[0] == 1) {
          ex = Phi_Data_phi_B->data[((int)IB->data[0] + Phi_Data_phi_B->size[0] *
            i) - 1];
        } else if ((Phi_Data_phi_B->data[((int)IB->data[0] +
                     Phi_Data_phi_B->size[0] * i) - 1] > Phi_Data_phi_B->data
                    [((int)IB->data[1] + Phi_Data_phi_B->size[0] * i) - 1]) ||
                   (rtIsNaN(Phi_Data_phi_B->data[((int)IB->data[0] +
                      Phi_Data_phi_B->size[0] * i) - 1]) && (!rtIsNaN
                     (Phi_Data_phi_B->data[((int)IB->data[1] +
            Phi_Data_phi_B->size[0] * i) - 1])))) {
          ex = Phi_Data_phi_B->data[((int)IB->data[1] + Phi_Data_phi_B->size[0] *
            i) - 1];
        } else {
          ex = Phi_Data_phi_B->data[((int)IB->data[0] + Phi_Data_phi_B->size[0] *
            i) - 1];
        }
      } else {
        if (!rtIsNaN(Phi_Data_phi_B->data[((int)IB->data[0] +
              Phi_Data_phi_B->size[0] * i) - 1])) {
          idx = 1;
        } else {
          idx = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= IB->size[0])) {
            if (!rtIsNaN(Phi_Data_phi_B->data[((int)IB->data[k - 1] +
                  Phi_Data_phi_B->size[0] * i) - 1])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }

        if (idx == 0) {
          ex = Phi_Data_phi_B->data[((int)IB->data[0] + Phi_Data_phi_B->size[0] *
            i) - 1];
        } else {
          ex = Phi_Data_phi_B->data[((int)IB->data[idx - 1] +
            Phi_Data_phi_B->size[0] * i) - 1];
          while (idx + 1 <= n) {
            if (ex > Phi_Data_phi_B->data[((int)IB->data[idx] +
                 Phi_Data_phi_B->size[0] * i) - 1]) {
              ex = Phi_Data_phi_B->data[((int)IB->data[idx] +
                Phi_Data_phi_B->size[0] * i) - 1];
            }

            idx++;
          }
        }
      }

      if ((b_I < ex) || rtIsNaN(ex)) {
        psi_val->data[b_k + psi_val->size[0] * i] = b_I;
      } else {
        psi_val->data[b_k + psi_val->size[0] * i] = ex;
      }
    }

    b_k++;
  }

  emxFree_real_T(&d_ii);
  emxFree_real_T(&c_ii);
  emxFree_int32_T(&b_ii);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&IB);
  emxFree_real_T(&IA);
}

/*
 * File trailer for Psi_Data_Generation.c
 *
 * [EOF]
 */
