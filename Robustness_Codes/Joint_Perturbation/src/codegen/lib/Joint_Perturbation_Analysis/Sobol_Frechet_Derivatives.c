/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Sobol_Frechet_Derivatives.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Sobol_Frechet_Derivatives.h"
#include "Find_Rectangle.h"
#include "Joint_Perturbation_Analysis_emxutil.h"
#include "sum.h"
#include "rdivide.h"
#include "power.h"
#include "is_in_sub_rec.h"
#include "sign.h"

/* Function Definitions */

/*
 * Unpack data from computing Sobol' indices
 * Arguments    : const emxArray_real_T *Sobol_Output_T
 *                const emxArray_real_T *Sobol_Output_A
 *                const emxArray_real_T *Sobol_Output_C
 *                const emxArray_real_T *Sobol_Output_YA
 *                const emxArray_real_T *Sobol_Output_YC
 *                double Sobol_Output_Var_Y
 *                double Sobol_Output_muYA
 *                const emxArray_real_T *Phi_Data_phi_A
 *                const emxArray_real_T *Phi_Data_phi_A_marg_not_k
 *                const emxArray_real_T *Phi_Data_phi_C
 *                const emxArray_real_T *R
 *                emxArray_real_T *a
 *                emxArray_real_T *a_normalized
 *                emxArray_real_T *Psi_Data_psi_A_val
 *                emxArray_real_T *Psi_Data_psi_C_val
 *                emxArray_real_T *Psi_Data_psi_val
 * Return Type  : void
 */
void Sobol_Frechet_Derivatives(const emxArray_real_T *Sobol_Output_T, const
  emxArray_real_T *Sobol_Output_A, const emxArray_real_T *Sobol_Output_C, const
  emxArray_real_T *Sobol_Output_YA, const emxArray_real_T *Sobol_Output_YC,
  double Sobol_Output_Var_Y, double Sobol_Output_muYA, const emxArray_real_T
  *Phi_Data_phi_A, const emxArray_real_T *Phi_Data_phi_A_marg_not_k, const
  emxArray_real_T *Phi_Data_phi_C, const emxArray_real_T *R, emxArray_real_T *a,
  emxArray_real_T *a_normalized, emxArray_real_T *Psi_Data_psi_A_val,
  emxArray_real_T *Psi_Data_psi_C_val, emxArray_real_T *Psi_Data_psi_val)
{
  int N;
  int p;
  int n;
  emxArray_real_T *IA;
  emxArray_real_T *IC;
  int i0;
  int k;
  emxArray_real_T *r1;
  emxArray_real_T *b_Sobol_Output_A;
  emxArray_real_T *b_Sobol_Output_C;
  int idx;
  emxArray_real_T *psi_val;
  int m;
  int c;
  int nx;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_boolean_T *x;
  emxArray_boolean_T *b_IC;
  emxArray_real_T *b_psi_val;
  unsigned int psi_val_idx_0;
  emxArray_real_T *psi_A_val;
  double S;
  boolean_T exitg1;
  boolean_T b_p;
  emxArray_int32_T *r4;
  emxArray_int32_T *ii;
  emxArray_real_T *D;
  emxArray_int32_T *JA;
  emxArray_real_T *J_Sub;
  emxArray_real_T *SD;
  emxArray_real_T *b_x;
  emxArray_real_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *r9;
  emxArray_real_T *r10;
  emxArray_real_T *b_Phi_Data_phi_C;
  emxArray_real_T *b_Sobol_Output_YA;
  emxArray_real_T *b_R;
  emxArray_real_T *c_R;
  double b_c;
  double b_Sobol_Output_T;
  N = Sobol_Output_A->size[0];
  p = Sobol_Output_A->size[1] - 1;

  /*  Preallocate arrays */
  n = R->size[0];
  if ((R->size[0] > 0) && ((R->size[1] == 0) || (R->size[1] > R->size[0]))) {
    n = R->size[1];
  }

  if ((n > 0) && (2 > n)) {
    n = 2;
  }

  emxInit_real_T2(&IA, 1);
  emxInit_real_T(&IC, 2);

  /*  determine psi values */
  Find_Rectangle(Sobol_Output_A, R, IA);
  i0 = IC->size[0] * IC->size[1];
  IC->size[0] = Sobol_Output_A->size[0];
  IC->size[1] = Sobol_Output_A->size[1];
  emxEnsureCapacity_real_T(IC, i0);
  k = 0;
  emxInit_real_T2(&r1, 1);
  emxInit_real_T(&b_Sobol_Output_A, 2);
  emxInit_real_T1(&b_Sobol_Output_C, 3);
  while (k <= p) {
    idx = Sobol_Output_C->size[1];
    m = Sobol_Output_C->size[2];
    i0 = b_Sobol_Output_C->size[0] * b_Sobol_Output_C->size[1] *
      b_Sobol_Output_C->size[2];
    b_Sobol_Output_C->size[0] = 1;
    b_Sobol_Output_C->size[1] = idx;
    b_Sobol_Output_C->size[2] = m;
    emxEnsureCapacity_real_T1(b_Sobol_Output_C, i0);
    for (i0 = 0; i0 < m; i0++) {
      for (nx = 0; nx < idx; nx++) {
        b_Sobol_Output_C->data[b_Sobol_Output_C->size[0] * nx +
          b_Sobol_Output_C->size[0] * b_Sobol_Output_C->size[1] * i0] =
          Sobol_Output_C->data[(k + Sobol_Output_C->size[0] * nx) +
          Sobol_Output_C->size[0] * Sobol_Output_C->size[1] * i0];
      }
    }

    i0 = b_Sobol_Output_A->size[0] * b_Sobol_Output_A->size[1];
    b_Sobol_Output_A->size[0] = N;
    b_Sobol_Output_A->size[1] = p + 1;
    emxEnsureCapacity_real_T(b_Sobol_Output_A, i0);
    idx = p + 1;
    for (i0 = 0; i0 < idx; i0++) {
      for (nx = 0; nx < N; nx++) {
        b_Sobol_Output_A->data[nx + b_Sobol_Output_A->size[0] * i0] =
          b_Sobol_Output_C->data[nx + N * i0];
      }
    }

    Find_Rectangle(b_Sobol_Output_A, R, r1);
    idx = r1->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      IC->data[i0 + IC->size[0] * k] = r1->data[i0];
    }

    k++;
  }

  emxFree_real_T(&b_Sobol_Output_C);
  emxInit_real_T(&psi_val, 2);
  i0 = psi_val->size[0] * psi_val->size[1];
  psi_val->size[0] = n;
  psi_val->size[1] = Sobol_Output_A->size[1] + 1;
  emxEnsureCapacity_real_T(psi_val, i0);
  idx = n * (Sobol_Output_A->size[1] + 1);
  for (i0 = 0; i0 < idx; i0++) {
    psi_val->data[i0] = 0.0;
  }

  c = 0;
  emxInit_int32_T(&r2, 1);
  emxInit_int32_T(&r3, 1);
  emxInit_boolean_T1(&x, 1);
  emxInit_boolean_T1(&b_IC, 1);
  while (c <= n - 1) {
    nx = IA->size[0] - 1;
    m = 0;
    for (idx = 0; idx <= nx; idx++) {
      if (IA->data[idx] == 1.0 + (double)c) {
        m++;
      }
    }

    i0 = r2->size[0];
    r2->size[0] = m;
    emxEnsureCapacity_int32_T1(r2, i0);
    m = 0;
    for (idx = 0; idx <= nx; idx++) {
      if (IA->data[idx] == 1.0 + (double)c) {
        r2->data[m] = idx + 1;
        m++;
      }
    }

    m = r2->size[0];
    if (r2->size[0] <= 2) {
      if (r2->size[0] == 1) {
        S = Phi_Data_phi_A->data[r2->data[0] - 1];
      } else if ((Phi_Data_phi_A->data[r2->data[0] - 1] > Phi_Data_phi_A->
                  data[r2->data[1] - 1]) || (rtIsNaN(Phi_Data_phi_A->data
                   [r2->data[0] - 1]) && (!rtIsNaN(Phi_Data_phi_A->data[r2->
                    data[1] - 1])))) {
        S = Phi_Data_phi_A->data[r2->data[1] - 1];
      } else {
        S = Phi_Data_phi_A->data[r2->data[0] - 1];
      }
    } else {
      if (!rtIsNaN(Phi_Data_phi_A->data[r2->data[0] - 1])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= r2->size[0])) {
          if (!rtIsNaN(Phi_Data_phi_A->data[r2->data[k - 1] - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        S = Phi_Data_phi_A->data[r2->data[0] - 1];
      } else {
        S = Phi_Data_phi_A->data[r2->data[idx - 1] - 1];
        while (idx + 1 <= m) {
          if (S > Phi_Data_phi_A->data[r2->data[idx] - 1]) {
            S = Phi_Data_phi_A->data[r2->data[idx] - 1];
          }

          idx++;
        }
      }
    }

    psi_val->data[c + psi_val->size[0] * (p + 1)] = S;
    for (k = 0; k <= p; k++) {
      idx = IC->size[0];
      i0 = b_IC->size[0];
      b_IC->size[0] = idx;
      emxEnsureCapacity_boolean_T1(b_IC, i0);
      for (i0 = 0; i0 < idx; i0++) {
        b_IC->data[i0] = (IC->data[i0 + IC->size[0] * k] == 1.0 + (double)c);
      }

      if (sum(b_IC) > 0.0) {
        idx = IC->size[0];
        i0 = x->size[0];
        x->size[0] = idx;
        emxEnsureCapacity_boolean_T1(x, i0);
        for (i0 = 0; i0 < idx; i0++) {
          x->data[i0] = (IC->data[i0 + IC->size[0] * k] == 1.0 + (double)c);
        }

        nx = x->size[0] - 1;
        m = 0;
        for (idx = 0; idx <= nx; idx++) {
          if (x->data[idx]) {
            m++;
          }
        }

        i0 = r3->size[0];
        r3->size[0] = m;
        emxEnsureCapacity_int32_T1(r3, i0);
        m = 0;
        for (idx = 0; idx <= nx; idx++) {
          if (x->data[idx]) {
            r3->data[m] = idx + 1;
            m++;
          }
        }

        m = r3->size[0];
        if (r3->size[0] <= 2) {
          if (r3->size[0] == 1) {
            S = Phi_Data_phi_C->data[(r3->data[0] + Phi_Data_phi_C->size[0] * k)
              - 1];
          } else if ((Phi_Data_phi_C->data[(r3->data[0] + Phi_Data_phi_C->size[0]
            * k) - 1] > Phi_Data_phi_C->data[(r3->data[1] + Phi_Data_phi_C->
                       size[0] * k) - 1]) || (rtIsNaN(Phi_Data_phi_C->data
                       [(r3->data[0] + Phi_Data_phi_C->size[0] * k) - 1]) &&
                      (!rtIsNaN(Phi_Data_phi_C->data[(r3->data[1] +
              Phi_Data_phi_C->size[0] * k) - 1])))) {
            S = Phi_Data_phi_C->data[(r3->data[1] + Phi_Data_phi_C->size[0] * k)
              - 1];
          } else {
            S = Phi_Data_phi_C->data[(r3->data[0] + Phi_Data_phi_C->size[0] * k)
              - 1];
          }
        } else {
          if (!rtIsNaN(Phi_Data_phi_C->data[(r3->data[0] + Phi_Data_phi_C->size
                [0] * k) - 1])) {
            idx = 1;
          } else {
            idx = 0;
            nx = 2;
            exitg1 = false;
            while ((!exitg1) && (nx <= r3->size[0])) {
              if (!rtIsNaN(Phi_Data_phi_C->data[(r3->data[nx - 1] +
                    Phi_Data_phi_C->size[0] * k) - 1])) {
                idx = nx;
                exitg1 = true;
              } else {
                nx++;
              }
            }
          }

          if (idx == 0) {
            S = Phi_Data_phi_C->data[(r3->data[0] + Phi_Data_phi_C->size[0] * k)
              - 1];
          } else {
            S = Phi_Data_phi_C->data[(r3->data[idx - 1] + Phi_Data_phi_C->size[0]
              * k) - 1];
            while (idx + 1 <= m) {
              if (S > Phi_Data_phi_C->data[(r3->data[idx] + Phi_Data_phi_C->
                   size[0] * k) - 1]) {
                S = Phi_Data_phi_C->data[(r3->data[idx] + Phi_Data_phi_C->size[0]
                  * k) - 1];
              }

              idx++;
            }
          }
        }

        psi_val->data[c + psi_val->size[0] * k] = S;
      } else {
        psi_val->data[c + psi_val->size[0] * k] = 0.0;
      }
    }

    c++;
  }

  emxFree_boolean_T(&b_IC);
  emxFree_int32_T(&r3);
  emxFree_int32_T(&r2);
  emxInit_real_T2(&b_psi_val, 1);
  m = psi_val->size[0];
  psi_val_idx_0 = (unsigned int)psi_val->size[0];
  i0 = b_psi_val->size[0];
  b_psi_val->size[0] = (int)psi_val_idx_0;
  emxEnsureCapacity_real_T2(b_psi_val, i0);
  if (psi_val->size[0] >= 1) {
    for (idx = 0; idx < m; idx++) {
      b_psi_val->data[idx] = psi_val->data[idx];
    }

    for (c = 1; c < psi_val->size[1]; c++) {
      for (idx = 0; idx < m; idx++) {
        b_p = ((!rtIsNaN(psi_val->data[idx + psi_val->size[0] * c])) && (rtIsNaN
                (b_psi_val->data[idx]) || (b_psi_val->data[idx] > psi_val->
                 data[idx + psi_val->size[0] * c])));
        if (b_p) {
          b_psi_val->data[idx] = psi_val->data[idx + psi_val->size[0] * c];
        }
      }
    }
  }

  emxInit_real_T2(&psi_A_val, 1);
  i0 = psi_A_val->size[0];
  psi_A_val->size[0] = Sobol_Output_A->size[0];
  emxEnsureCapacity_real_T2(psi_A_val, i0);
  idx = Sobol_Output_A->size[0];
  for (i0 = 0; i0 < idx; i0++) {
    psi_A_val->data[i0] = 0.0;
  }

  i0 = psi_val->size[0] * psi_val->size[1];
  psi_val->size[0] = Sobol_Output_A->size[0];
  psi_val->size[1] = Sobol_Output_A->size[1];
  emxEnsureCapacity_real_T(psi_val, i0);
  idx = Sobol_Output_A->size[0] * Sobol_Output_A->size[1];
  for (i0 = 0; i0 < idx; i0++) {
    psi_val->data[i0] = 0.0;
  }

  c = 0;
  emxInit_int32_T(&r4, 1);
  emxInit_int32_T(&ii, 1);
  while (c <= n - 1) {
    nx = IA->size[0] - 1;
    m = 0;
    for (idx = 0; idx <= nx; idx++) {
      if (IA->data[idx] == 1.0 + (double)c) {
        m++;
      }
    }

    i0 = ii->size[0];
    ii->size[0] = m;
    emxEnsureCapacity_int32_T1(ii, i0);
    m = 0;
    for (idx = 0; idx <= nx; idx++) {
      if (IA->data[idx] == 1.0 + (double)c) {
        ii->data[m] = idx + 1;
        m++;
      }
    }

    idx = ii->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      psi_A_val->data[ii->data[i0] - 1] = b_psi_val->data[c];
    }

    for (k = 0; k <= p; k++) {
      idx = IC->size[0];
      i0 = x->size[0];
      x->size[0] = idx;
      emxEnsureCapacity_boolean_T1(x, i0);
      for (i0 = 0; i0 < idx; i0++) {
        x->data[i0] = (IC->data[i0 + IC->size[0] * k] == 1.0 + (double)c);
      }

      nx = x->size[0] - 1;
      m = 0;
      for (idx = 0; idx <= nx; idx++) {
        if (x->data[idx]) {
          m++;
        }
      }

      i0 = r4->size[0];
      r4->size[0] = m;
      emxEnsureCapacity_int32_T1(r4, i0);
      m = 0;
      for (idx = 0; idx <= nx; idx++) {
        if (x->data[idx]) {
          r4->data[m] = idx + 1;
          m++;
        }
      }

      m = r4->size[0];
      for (i0 = 0; i0 < m; i0++) {
        psi_val->data[(r4->data[i0] + psi_val->size[0] * k) - 1] =
          b_psi_val->data[c];
      }
    }

    c++;
  }

  emxFree_int32_T(&r4);
  emxInit_real_T(&D, 2);

  /*  Loop over Sobol indices */
  i0 = D->size[0] * D->size[1];
  D->size[0] = n;
  D->size[1] = Sobol_Output_A->size[1];
  emxEnsureCapacity_real_T(D, i0);
  k = 0;
  emxInit_int32_T(&JA, 1);
  emxInit_real_T2(&J_Sub, 1);
  emxInit_real_T2(&SD, 1);
  emxInit_real_T(&b_x, 2);
  emxInit_real_T2(&r5, 1);
  emxInit_real_T2(&r6, 1);
  emxInit_real_T2(&r7, 1);
  emxInit_real_T2(&r8, 1);
  emxInit_real_T2(&r9, 1);
  emxInit_real_T2(&r10, 1);
  emxInit_real_T2(&b_Phi_Data_phi_C, 1);
  emxInit_real_T2(&b_Sobol_Output_YA, 1);
  emxInit_real_T(&b_R, 2);
  emxInit_real_T1(&c_R, 3);
  while (k <= p) {
    /*  Construct the vector d elementwise */
    for (c = 0; c < n; c++) {
      i0 = x->size[0];
      x->size[0] = IA->size[0];
      emxEnsureCapacity_boolean_T1(x, i0);
      idx = IA->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        x->data[i0] = (IA->data[i0] == 1.0 + (double)c);
      }

      nx = x->size[0];
      idx = 0;
      i0 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T1(ii, i0);
      m = 1;
      exitg1 = false;
      while ((!exitg1) && (m <= nx)) {
        if (x->data[m - 1]) {
          idx++;
          ii->data[idx - 1] = m;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            m++;
          }
        } else {
          m++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i0 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity_int32_T1(ii, i0);
        }
      } else {
        i0 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T1(ii, i0);
      }

      i0 = JA->size[0];
      JA->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T1(JA, i0);
      idx = ii->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        JA->data[i0] = ii->data[i0];
      }

      idx = IC->size[0];
      i0 = x->size[0];
      x->size[0] = idx;
      emxEnsureCapacity_boolean_T1(x, i0);
      for (i0 = 0; i0 < idx; i0++) {
        x->data[i0] = (IC->data[i0 + IC->size[0] * k] == 1.0 + (double)c);
      }

      nx = x->size[0];
      idx = 0;
      i0 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T1(ii, i0);
      m = 1;
      exitg1 = false;
      while ((!exitg1) && (m <= nx)) {
        if (x->data[m - 1]) {
          idx++;
          ii->data[idx - 1] = m;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            m++;
          }
        } else {
          m++;
        }
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i0 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity_int32_T1(ii, i0);
        }
      } else {
        i0 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T1(ii, i0);
      }

      i0 = SD->size[0];
      SD->size[0] = ii->size[0];
      emxEnsureCapacity_real_T2(SD, i0);
      idx = ii->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        SD->data[i0] = ii->data[i0];
      }

      idx = R->size[1];
      i0 = c_R->size[0] * c_R->size[1] * c_R->size[2];
      c_R->size[0] = 1;
      c_R->size[1] = idx;
      c_R->size[2] = 2;
      emxEnsureCapacity_real_T1(c_R, i0);
      for (i0 = 0; i0 < 2; i0++) {
        for (nx = 0; nx < idx; nx++) {
          c_R->data[c_R->size[0] * nx + c_R->size[0] * c_R->size[1] * i0] =
            R->data[(c + R->size[0] * nx) + R->size[0] * R->size[1] * i0];
        }
      }

      i0 = b_R->size[0] * b_R->size[1];
      b_R->size[0] = p + 1;
      b_R->size[1] = 2;
      emxEnsureCapacity_real_T(b_R, i0);
      idx = p + 1;
      for (i0 = 0; i0 < 2; i0++) {
        for (nx = 0; nx < idx; nx++) {
          b_R->data[nx + b_R->size[0] * i0] = c_R->data[nx + (p + 1) * i0];
        }
      }

      i0 = b_Sobol_Output_A->size[0] * b_Sobol_Output_A->size[1];
      b_Sobol_Output_A->size[0] = Sobol_Output_A->size[0];
      b_Sobol_Output_A->size[1] = Sobol_Output_A->size[1];
      emxEnsureCapacity_real_T(b_Sobol_Output_A, i0);
      idx = Sobol_Output_A->size[0] * Sobol_Output_A->size[1];
      for (i0 = 0; i0 < idx; i0++) {
        b_Sobol_Output_A->data[i0] = Sobol_Output_A->data[i0];
      }

      is_in_sub_rec(b_R, b_Sobol_Output_A, 1.0 + (double)k, J_Sub);
      idx = R->size[1];
      i0 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = idx;
      emxEnsureCapacity_real_T(b_x, i0);
      for (i0 = 0; i0 < idx; i0++) {
        b_x->data[b_x->size[0] * i0] = R->data[(c + R->size[0] * i0) + R->size[0]
          * R->size[1]] - R->data[c + R->size[0] * i0];
      }

      if (b_x->size[1] == 0) {
        S = 1.0;
      } else {
        S = b_x->data[0];
        for (nx = 2; nx <= b_x->size[1]; nx++) {
          S *= b_x->data[nx - 1];
        }
      }

      i0 = b_Sobol_Output_YA->size[0];
      b_Sobol_Output_YA->size[0] = SD->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i0);
      idx = SD->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Sobol_Output_YA->data[i0] = Sobol_Output_YA->data[(int)SD->data[i0] -
          1] - Sobol_Output_YC->data[((int)SD->data[i0] + Sobol_Output_YC->size
          [0] * k) - 1];
      }

      power(b_Sobol_Output_YA, r9);
      i0 = b_Phi_Data_phi_C->size[0];
      b_Phi_Data_phi_C->size[0] = SD->size[0];
      emxEnsureCapacity_real_T2(b_Phi_Data_phi_C, i0);
      idx = SD->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Phi_Data_phi_C->data[i0] = Phi_Data_phi_C->data[((int)SD->data[i0] +
          Phi_Data_phi_C->size[0] * k) - 1];
      }

      rdivide(b_Phi_Data_phi_C, r1);
      i0 = b_Sobol_Output_YA->size[0];
      b_Sobol_Output_YA->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i0);
      idx = JA->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Sobol_Output_YA->data[i0] = Sobol_Output_YA->data[JA->data[i0] - 1] -
          Sobol_Output_YC->data[(JA->data[i0] + Sobol_Output_YC->size[0] * k) -
          1];
      }

      power(b_Sobol_Output_YA, r5);
      i0 = b_Phi_Data_phi_C->size[0];
      b_Phi_Data_phi_C->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(b_Phi_Data_phi_C, i0);
      idx = JA->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Phi_Data_phi_C->data[i0] = Phi_Data_phi_A->data[JA->data[i0] - 1];
      }

      rdivide(b_Phi_Data_phi_C, r6);
      i0 = b_Sobol_Output_YA->size[0];
      b_Sobol_Output_YA->size[0] = J_Sub->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i0);
      idx = J_Sub->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Sobol_Output_YA->data[i0] = Sobol_Output_YA->data[(int)J_Sub->data[i0]
          - 1] - Sobol_Output_YC->data[((int)J_Sub->data[i0] +
          Sobol_Output_YC->size[0] * k) - 1];
      }

      power(b_Sobol_Output_YA, r7);
      i0 = b_Phi_Data_phi_C->size[0];
      b_Phi_Data_phi_C->size[0] = J_Sub->size[0];
      emxEnsureCapacity_real_T2(b_Phi_Data_phi_C, i0);
      idx = J_Sub->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Phi_Data_phi_C->data[i0] = Phi_Data_phi_A_marg_not_k->data[(int)
          J_Sub->data[i0] - 1];
      }

      rdivide(b_Phi_Data_phi_C, SD);
      i0 = b_Sobol_Output_YA->size[0];
      b_Sobol_Output_YA->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i0);
      idx = JA->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Sobol_Output_YA->data[i0] = Sobol_Output_YA->data[JA->data[i0] - 1];
      }

      power(b_Sobol_Output_YA, J_Sub);
      i0 = b_Phi_Data_phi_C->size[0];
      b_Phi_Data_phi_C->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(b_Phi_Data_phi_C, i0);
      idx = JA->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Phi_Data_phi_C->data[i0] = Phi_Data_phi_A->data[JA->data[i0] - 1];
      }

      rdivide(b_Phi_Data_phi_C, b_Sobol_Output_YA);
      i0 = b_Phi_Data_phi_C->size[0];
      b_Phi_Data_phi_C->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(b_Phi_Data_phi_C, i0);
      idx = JA->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Phi_Data_phi_C->data[i0] = Phi_Data_phi_A->data[JA->data[i0] - 1];
      }

      rdivide(b_Phi_Data_phi_C, r8);
      i0 = r10->size[0];
      r10->size[0] = r9->size[0];
      emxEnsureCapacity_real_T2(r10, i0);
      idx = r9->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        r10->data[i0] = r9->data[i0] * r1->data[i0];
      }

      i0 = r1->size[0];
      r1->size[0] = r5->size[0];
      emxEnsureCapacity_real_T2(r1, i0);
      idx = r5->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        r1->data[i0] = r5->data[i0] * r6->data[i0];
      }

      i0 = r5->size[0];
      r5->size[0] = r7->size[0];
      emxEnsureCapacity_real_T2(r5, i0);
      idx = r7->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        r5->data[i0] = r7->data[i0] * SD->data[i0];
      }

      i0 = b_Phi_Data_phi_C->size[0];
      b_Phi_Data_phi_C->size[0] = J_Sub->size[0];
      emxEnsureCapacity_real_T2(b_Phi_Data_phi_C, i0);
      idx = J_Sub->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Phi_Data_phi_C->data[i0] = J_Sub->data[i0] * b_Sobol_Output_YA->
          data[i0];
      }

      i0 = b_Sobol_Output_YA->size[0];
      b_Sobol_Output_YA->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i0);
      idx = JA->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        b_Sobol_Output_YA->data[i0] = Sobol_Output_YA->data[JA->data[i0] - 1] *
          r8->data[i0];
      }

      D->data[c + D->size[0] * k] = 0.5 * ((b_psi_val->data[c] * c_sum(r10) /
        (double)N + b_psi_val->data[c] * c_sum(r1) / (double)N) -
        b_psi_val->data[c] * (R->data[(c + R->size[0] * k) + R->size[0] *
        R->size[1]] - R->data[c + R->size[0] * k]) * c_sum(r5) / (double)N) /
        Sobol_Output_Var_Y - Sobol_Output_T->data[k] * ((b_psi_val->data[c] *
        c_sum(b_Phi_Data_phi_C) / (double)N - b_psi_val->data[c] * 2.0 *
        Sobol_Output_muYA * c_sum(b_Sobol_Output_YA) / (double)N) +
        b_psi_val->data[c] * S * (Sobol_Output_muYA * Sobol_Output_muYA)) /
        Sobol_Output_Var_Y;
    }

    k++;
  }

  emxFree_real_T(&c_R);
  emxFree_real_T(&b_Sobol_Output_A);
  emxFree_real_T(&b_R);
  emxFree_real_T(&b_Sobol_Output_YA);
  emxFree_real_T(&b_Phi_Data_phi_C);
  emxFree_real_T(&r10);
  emxFree_real_T(&r8);
  emxFree_real_T(&r7);
  emxFree_real_T(&r6);
  emxFree_real_T(&r5);
  emxFree_real_T(&r1);
  emxFree_real_T(&b_x);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&J_Sub);
  emxFree_int32_T(&JA);
  emxFree_real_T(&IC);
  emxFree_real_T(&IA);
  S = c_sum(Sobol_Output_T);
  b_sum(D, SD);
  i0 = a->size[0] * a->size[1];
  a->size[0] = n;
  a->size[1] = Sobol_Output_A->size[1];
  emxEnsureCapacity_real_T(a, i0);
  i0 = a_normalized->size[0] * a_normalized->size[1];
  a_normalized->size[0] = n;
  a_normalized->size[1] = Sobol_Output_A->size[1];
  emxEnsureCapacity_real_T(a_normalized, i0);
  for (k = 0; k <= p; k++) {
    idx = D->size[0];
    i0 = r9->size[0];
    r9->size[0] = idx;
    emxEnsureCapacity_real_T2(r9, i0);
    for (i0 = 0; i0 < idx; i0++) {
      r9->data[i0] = D->data[i0 + D->size[0] * k];
    }

    b_sign(r9);
    idx = r9->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      a->data[i0 + a->size[0] * k] = r9->data[i0];
    }

    b_c = S * S;
    idx = D->size[0];
    b_Sobol_Output_T = Sobol_Output_T->data[k];
    i0 = r9->size[0];
    r9->size[0] = idx;
    emxEnsureCapacity_real_T2(r9, i0);
    for (i0 = 0; i0 < idx; i0++) {
      r9->data[i0] = (S * D->data[i0 + D->size[0] * k] - b_Sobol_Output_T
                      * SD->data[i0]) / b_c;
    }

    b_sign(r9);
    idx = r9->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      a_normalized->data[i0 + a_normalized->size[0] * k] = r9->data[i0];
    }
  }

  emxFree_real_T(&r9);
  emxFree_real_T(&SD);
  emxFree_real_T(&D);
  i0 = Psi_Data_psi_A_val->size[0];
  Psi_Data_psi_A_val->size[0] = psi_A_val->size[0];
  emxEnsureCapacity_real_T2(Psi_Data_psi_A_val, i0);
  idx = psi_A_val->size[0];
  for (i0 = 0; i0 < idx; i0++) {
    Psi_Data_psi_A_val->data[i0] = psi_A_val->data[i0];
  }

  emxFree_real_T(&psi_A_val);
  i0 = Psi_Data_psi_C_val->size[0] * Psi_Data_psi_C_val->size[1];
  Psi_Data_psi_C_val->size[0] = psi_val->size[0];
  Psi_Data_psi_C_val->size[1] = psi_val->size[1];
  emxEnsureCapacity_real_T(Psi_Data_psi_C_val, i0);
  idx = psi_val->size[0] * psi_val->size[1];
  for (i0 = 0; i0 < idx; i0++) {
    Psi_Data_psi_C_val->data[i0] = psi_val->data[i0];
  }

  emxFree_real_T(&psi_val);
  i0 = Psi_Data_psi_val->size[0];
  Psi_Data_psi_val->size[0] = b_psi_val->size[0];
  emxEnsureCapacity_real_T2(Psi_Data_psi_val, i0);
  idx = b_psi_val->size[0];
  for (i0 = 0; i0 < idx; i0++) {
    Psi_Data_psi_val->data[i0] = b_psi_val->data[i0];
  }

  emxFree_real_T(&b_psi_val);
}

/*
 * File trailer for Sobol_Frechet_Derivatives.c
 *
 * [EOF]
 */
