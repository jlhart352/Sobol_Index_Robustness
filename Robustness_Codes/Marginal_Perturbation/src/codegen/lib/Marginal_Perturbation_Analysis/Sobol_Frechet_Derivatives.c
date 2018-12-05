/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Sobol_Frechet_Derivatives.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "Sobol_Frechet_Derivatives.h"
#include "sum.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"
#include "rdivide.h"
#include "power.h"
#include "eml_setop.h"
#include "abs.h"
#include "sign.h"

/* Function Definitions */

/*
 * Unpack data from computing Sobol' indices
 * Arguments    : const emxArray_real_T *Sobol_Output_S
 *                const emxArray_real_T *Sobol_Output_T
 *                const emxArray_real_T *Sobol_Output_A
 *                const emxArray_real_T *Sobol_Output_B
 *                const emxArray_real_T *Sobol_Output_YA
 *                const emxArray_real_T *Sobol_Output_YB
 *                const emxArray_real_T *Sobol_Output_YC
 *                double Sobol_Output_Var_Y
 *                double Sobol_Output_muYA
 *                double Sobol_Output_muYB
 *                const emxArray_real_T *Phi_Data_phi_A
 *                const emxArray_real_T *Phi_Data_phi_B
 *                const emxArray_real_T *psi_val
 *                const emxArray_real_T *I
 *                double k
 *                emxArray_real_T *a_S
 *                emxArray_real_T *a_T
 *                emxArray_real_T *weights_S
 *                emxArray_real_T *weights_T
 * Return Type  : void
 */
void Sobol_Frechet_Derivatives(const emxArray_real_T *Sobol_Output_S, const
  emxArray_real_T *Sobol_Output_T, const emxArray_real_T *Sobol_Output_A, const
  emxArray_real_T *Sobol_Output_B, const emxArray_real_T *Sobol_Output_YA, const
  emxArray_real_T *Sobol_Output_YB, const emxArray_real_T *Sobol_Output_YC,
  double Sobol_Output_Var_Y, double Sobol_Output_muYA, double Sobol_Output_muYB,
  const emxArray_real_T *Phi_Data_phi_A, const emxArray_real_T *Phi_Data_phi_B,
  const emxArray_real_T *psi_val, const emxArray_real_T *I, double k,
  emxArray_real_T *a_S, emxArray_real_T *a_T, emxArray_real_T *weights_S,
  emxArray_real_T *weights_T)
{
  int N;
  int L;
  int i2;
  int loop_ub;
  int i;
  emxArray_real_T *D_S;
  emxArray_real_T *D_T;
  emxArray_real_T *JA;
  emxArray_real_T *JB;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_int32_T *b_ii;
  emxArray_real_T *r6;
  emxArray_real_T *r7;
  emxArray_real_T *b_Sobol_Output_YB;
  emxArray_real_T *c_ii;
  emxArray_real_T *d_ii;
  int j;
  double DH;
  int nx;
  int idx;
  boolean_T exitg1;
  double DG;
  N = Sobol_Output_YA->size[0];

  /*  Preallocate arrays */
  L = I->size[0] - 1;
  i2 = weights_S->size[0];
  weights_S->size[0] = Sobol_Output_T->size[0];
  emxEnsureCapacity_real_T2(weights_S, i2);
  loop_ub = Sobol_Output_T->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    weights_S->data[i2] = 0.0;
  }

  i2 = weights_T->size[0];
  weights_T->size[0] = Sobol_Output_T->size[0];
  emxEnsureCapacity_real_T2(weights_T, i2);
  loop_ub = Sobol_Output_T->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    weights_T->data[i2] = 0.0;
  }

  i2 = a_S->size[0] * a_S->size[1];
  a_S->size[0] = I->size[0] - 1;
  a_S->size[1] = Sobol_Output_T->size[0];
  emxEnsureCapacity_real_T1(a_S, i2);
  i2 = a_T->size[0] * a_T->size[1];
  a_T->size[0] = I->size[0] - 1;
  a_T->size[1] = Sobol_Output_T->size[0];
  emxEnsureCapacity_real_T1(a_T, i2);
  i = 0;
  emxInit_real_T2(&D_S, 1);
  emxInit_real_T2(&D_T, 1);
  emxInit_real_T2(&JA, 1);
  emxInit_real_T2(&JB, 1);
  emxInit_boolean_T(&x, 1);
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&b_ii, 1);
  emxInit_real_T2(&r6, 1);
  emxInit_real_T2(&r7, 1);
  emxInit_real_T2(&b_Sobol_Output_YB, 1);
  emxInit_real_T2(&c_ii, 1);
  emxInit_real_T2(&d_ii, 1);
  while (i <= Sobol_Output_T->size[0] - 1) {
    /*  Construct the vector D elementwise */
    i2 = D_S->size[0];
    D_S->size[0] = L;
    emxEnsureCapacity_real_T2(D_S, i2);
    i2 = D_T->size[0];
    D_T->size[0] = L;
    emxEnsureCapacity_real_T2(D_T, i2);
    for (j = 0; j < L; j++) {
      loop_ub = Sobol_Output_A->size[0];
      DH = I->data[j + I->size[0] * i];
      i2 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(x, i2);
      for (i2 = 0; i2 < loop_ub; i2++) {
        x->data[i2] = (Sobol_Output_A->data[i2 + Sobol_Output_A->size[0] * i] >
                       DH);
      }

      nx = x->size[0];
      idx = 0;
      i2 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(ii, i2);
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
          i2 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity_int32_T(ii, i2);
        }
      } else {
        i2 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(ii, i2);
      }

      loop_ub = Sobol_Output_A->size[0];
      DH = I->data[(j + I->size[0] * i) + 1];
      i2 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(x, i2);
      for (i2 = 0; i2 < loop_ub; i2++) {
        x->data[i2] = (Sobol_Output_A->data[i2 + Sobol_Output_A->size[0] * i] <
                       DH);
      }

      nx = x->size[0];
      idx = 0;
      i2 = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(b_ii, i2);
      loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= nx)) {
        if (x->data[loop_ub - 1]) {
          idx++;
          b_ii->data[idx - 1] = loop_ub;
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
          i2 = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity_int32_T(b_ii, i2);
        }
      } else {
        i2 = b_ii->size[0];
        if (1 > idx) {
          b_ii->size[0] = 0;
        } else {
          b_ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(b_ii, i2);
      }

      i2 = c_ii->size[0];
      c_ii->size[0] = ii->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = ii->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = ii->data[i2];
      }

      i2 = d_ii->size[0];
      d_ii->size[0] = b_ii->size[0];
      emxEnsureCapacity_real_T2(d_ii, i2);
      loop_ub = b_ii->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        d_ii->data[i2] = b_ii->data[i2];
      }

      do_vectors(c_ii, d_ii, JA, ii, b_ii);
      loop_ub = Sobol_Output_B->size[0];
      DH = I->data[j + I->size[0] * i];
      i2 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(x, i2);
      for (i2 = 0; i2 < loop_ub; i2++) {
        x->data[i2] = (Sobol_Output_B->data[i2 + Sobol_Output_B->size[0] * i] >
                       DH);
      }

      nx = x->size[0];
      idx = 0;
      i2 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(ii, i2);
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
          i2 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity_int32_T(ii, i2);
        }
      } else {
        i2 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(ii, i2);
      }

      loop_ub = Sobol_Output_B->size[0];
      DH = I->data[(j + I->size[0] * i) + 1];
      i2 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(x, i2);
      for (i2 = 0; i2 < loop_ub; i2++) {
        x->data[i2] = (Sobol_Output_B->data[i2 + Sobol_Output_B->size[0] * i] <
                       DH);
      }

      nx = x->size[0];
      idx = 0;
      i2 = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(b_ii, i2);
      loop_ub = 1;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= nx)) {
        if (x->data[loop_ub - 1]) {
          idx++;
          b_ii->data[idx - 1] = loop_ub;
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
          i2 = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity_int32_T(b_ii, i2);
        }
      } else {
        i2 = b_ii->size[0];
        if (1 > idx) {
          b_ii->size[0] = 0;
        } else {
          b_ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(b_ii, i2);
      }

      i2 = c_ii->size[0];
      c_ii->size[0] = ii->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = ii->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = ii->data[i2];
      }

      i2 = d_ii->size[0];
      d_ii->size[0] = b_ii->size[0];
      emxEnsureCapacity_real_T2(d_ii, i2);
      loop_ub = b_ii->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        d_ii->data[i2] = b_ii->data[i2];
      }

      do_vectors(c_ii, d_ii, JB, ii, b_ii);
      i2 = c_ii->size[0];
      c_ii->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = JA->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Sobol_Output_YA->data[(int)JA->data[i2] - 1] -
          Sobol_Output_YC->data[((int)JA->data[i2] + Sobol_Output_YC->size[0] *
          ((int)k - 1)) - 1];
      }

      power(c_ii, r7);
      i2 = c_ii->size[0];
      c_ii->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = JA->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Phi_Data_phi_A->data[((int)JA->data[i2] +
          Phi_Data_phi_A->size[0] * i) - 1];
      }

      rdivide(c_ii, r6);
      i2 = b_Sobol_Output_YB->size[0];
      b_Sobol_Output_YB->size[0] = r7->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YB, i2);
      loop_ub = r7->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_Sobol_Output_YB->data[i2] = r7->data[i2] * r6->data[i2];
      }

      DG = psi_val->data[j + psi_val->size[0] * i] * sum(b_Sobol_Output_YB) /
        (double)N;
      if (1.0 + (double)i == k) {
        i2 = c_ii->size[0];
        c_ii->size[0] = JB->size[0];
        emxEnsureCapacity_real_T2(c_ii, i2);
        loop_ub = JB->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          c_ii->data[i2] = Sobol_Output_YA->data[(int)JB->data[i2] - 1] -
            Sobol_Output_YC->data[((int)JB->data[i2] + Sobol_Output_YC->size[0] *
            ((int)k - 1)) - 1];
        }

        power(c_ii, r7);
        i2 = c_ii->size[0];
        c_ii->size[0] = JB->size[0];
        emxEnsureCapacity_real_T2(c_ii, i2);
        loop_ub = JB->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          c_ii->data[i2] = Phi_Data_phi_B->data[((int)JB->data[i2] +
            Phi_Data_phi_B->size[0] * i) - 1];
        }

        rdivide(c_ii, r6);
        i2 = b_Sobol_Output_YB->size[0];
        b_Sobol_Output_YB->size[0] = r7->size[0];
        emxEnsureCapacity_real_T2(b_Sobol_Output_YB, i2);
        loop_ub = r7->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_Sobol_Output_YB->data[i2] = r7->data[i2] * r6->data[i2];
        }

        DG += psi_val->data[j + psi_val->size[0] * i] * sum(b_Sobol_Output_YB) /
          (double)N;
        i2 = c_ii->size[0];
        c_ii->size[0] = Sobol_Output_YA->size[0];
        emxEnsureCapacity_real_T2(c_ii, i2);
        loop_ub = Sobol_Output_YA->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          c_ii->data[i2] = Sobol_Output_YA->data[i2] - Sobol_Output_YC->data[i2
            + Sobol_Output_YC->size[0] * ((int)k - 1)];
        }

        power(c_ii, r7);
        DG -= psi_val->data[j + psi_val->size[0] * i] * (I->data[(j + I->size[0]
          * i) + 1] - I->data[j + I->size[0] * i]) * sum(r7) / (double)N;
      }

      DG *= 0.5;
      DH = 0.5 * (Sobol_Output_muYA + Sobol_Output_muYB);
      i2 = c_ii->size[0];
      c_ii->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = JA->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Sobol_Output_YA->data[(int)JA->data[i2] - 1];
      }

      power(c_ii, r7);
      i2 = c_ii->size[0];
      c_ii->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = JA->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Phi_Data_phi_A->data[((int)JA->data[i2] +
          Phi_Data_phi_A->size[0] * i) - 1];
      }

      rdivide(c_ii, r6);
      i2 = c_ii->size[0];
      c_ii->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = JA->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Phi_Data_phi_A->data[((int)JA->data[i2] +
          Phi_Data_phi_A->size[0] * i) - 1];
      }

      rdivide(c_ii, b_Sobol_Output_YB);
      i2 = d_ii->size[0];
      d_ii->size[0] = r7->size[0];
      emxEnsureCapacity_real_T2(d_ii, i2);
      loop_ub = r7->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        d_ii->data[i2] = r7->data[i2] * r6->data[i2];
      }

      i2 = c_ii->size[0];
      c_ii->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = JA->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Sobol_Output_YA->data[(int)JA->data[i2] - 1] *
          b_Sobol_Output_YB->data[i2];
      }

      DH = (psi_val->data[j + psi_val->size[0] * i] * sum(d_ii) / (double)N +
            psi_val->data[j + psi_val->size[0] * i] * (I->data[(j + I->size[0] *
              i) + 1] - I->data[j + I->size[0] * i]) * (DH * DH)) -
        psi_val->data[j + psi_val->size[0] * i] * 2.0 * 0.5 * (Sobol_Output_muYA
        + Sobol_Output_muYB) * sum(c_ii) / (double)N;
      i2 = c_ii->size[0];
      c_ii->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = JA->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Phi_Data_phi_A->data[((int)JA->data[i2] +
          Phi_Data_phi_A->size[0] * i) - 1];
      }

      rdivide(c_ii, r7);
      i2 = c_ii->size[0];
      c_ii->size[0] = JB->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = JB->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Phi_Data_phi_B->data[((int)JB->data[i2] +
          Phi_Data_phi_B->size[0] * i) - 1];
      }

      rdivide(c_ii, r6);
      i2 = b_Sobol_Output_YB->size[0];
      b_Sobol_Output_YB->size[0] = JA->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YB, i2);
      loop_ub = JA->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_Sobol_Output_YB->data[i2] = Sobol_Output_YB->data[(int)JA->data[i2] -
          1] * (Sobol_Output_YC->data[((int)JA->data[i2] + Sobol_Output_YC->
                 size[0] * ((int)k - 1)) - 1] - Sobol_Output_YA->data[(int)
                JA->data[i2] - 1]) * r7->data[i2];
      }

      i2 = d_ii->size[0];
      d_ii->size[0] = JB->size[0];
      emxEnsureCapacity_real_T2(d_ii, i2);
      loop_ub = JB->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        d_ii->data[i2] = Sobol_Output_YB->data[(int)JB->data[i2] - 1] *
          (Sobol_Output_YC->data[((int)JB->data[i2] + Sobol_Output_YC->size[0] *
            ((int)k - 1)) - 1] - Sobol_Output_YA->data[(int)JB->data[i2] - 1]) *
          r6->data[i2];
      }

      i2 = c_ii->size[0];
      c_ii->size[0] = Sobol_Output_YB->size[0];
      emxEnsureCapacity_real_T2(c_ii, i2);
      loop_ub = Sobol_Output_YB->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        c_ii->data[i2] = Sobol_Output_YB->data[i2] * (Sobol_Output_YC->data[i2 +
          Sobol_Output_YC->size[0] * ((int)k - 1)] - Sobol_Output_YA->data[i2]);
      }

      D_S->data[j] = ((psi_val->data[j + psi_val->size[0] * i] * sum
                       (b_Sobol_Output_YB) / (double)N + psi_val->data[j +
                       psi_val->size[0] * i] * sum(d_ii) / (double)N) -
                      psi_val->data[j + psi_val->size[0] * i] * (I->data[(j +
        I->size[0] * i) + 1] - I->data[j + I->size[0] * i]) * sum(c_ii) /
                      (double)N) / Sobol_Output_Var_Y - Sobol_Output_S->data
        [(int)k - 1] * DH / Sobol_Output_Var_Y;
      D_T->data[j] = DG / Sobol_Output_Var_Y - Sobol_Output_T->data[(int)k - 1] *
        DH / Sobol_Output_Var_Y;
    }

    i2 = r7->size[0];
    r7->size[0] = D_S->size[0];
    emxEnsureCapacity_real_T2(r7, i2);
    loop_ub = D_S->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      r7->data[i2] = D_S->data[i2];
    }

    b_sign(r7);
    loop_ub = r7->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      a_S->data[i2 + a_S->size[0] * i] = r7->data[i2];
    }

    i2 = r7->size[0];
    r7->size[0] = D_T->size[0];
    emxEnsureCapacity_real_T2(r7, i2);
    loop_ub = D_T->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      r7->data[i2] = D_T->data[i2];
    }

    b_sign(r7);
    loop_ub = r7->size[0];
    for (i2 = 0; i2 < loop_ub; i2++) {
      a_T->data[i2 + a_T->size[0] * i] = r7->data[i2];
    }

    b_abs(D_S, r7);
    weights_S->data[i] = sum(r7);
    b_abs(D_T, r7);
    weights_T->data[i] = sum(r7);
    i++;
  }

  emxFree_real_T(&d_ii);
  emxFree_real_T(&c_ii);
  emxFree_real_T(&b_Sobol_Output_YB);
  emxFree_real_T(&r7);
  emxFree_real_T(&r6);
  emxFree_int32_T(&b_ii);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&JB);
  emxFree_real_T(&JA);
  emxFree_real_T(&D_T);
  emxFree_real_T(&D_S);
  DH = sum(weights_S);
  i2 = weights_S->size[0];
  emxEnsureCapacity_real_T2(weights_S, i2);
  loop_ub = weights_S->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    weights_S->data[i2] /= DH;
  }

  DH = sum(weights_T);
  i2 = weights_T->size[0];
  emxEnsureCapacity_real_T2(weights_T, i2);
  loop_ub = weights_T->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    weights_T->data[i2] /= DH;
  }
}

/*
 * File trailer for Sobol_Frechet_Derivatives.c
 *
 * [EOF]
 */
