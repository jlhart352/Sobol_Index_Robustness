/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Perturbed_Sobol_Indices.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "Perturbed_Sobol_Indices.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"
#include "eml_setop.h"
#include "Sample_std_Estimate_Weights.h"
#include "combineVectorElements.h"
#include "power.h"
#include "unaryMinOrMax.h"
#include "prod.h"
#include "rdivide.h"
#include "Eval_Perturbed_PDF.h"

/* Function Definitions */

/*
 * Evaluate Sobol' indices with perturbed PDF via importance sampling
 * Arguments    : const emxArray_real_T *a
 *                const emxArray_real_T *delta_weights
 *                const emxArray_real_T *Sobol_Output_A
 *                const emxArray_real_T *Sobol_Output_B
 *                const emxArray_real_T *Sobol_Output_YA
 *                const emxArray_real_T *Sobol_Output_YB
 *                const emxArray_real_T *Sobol_Output_YC
 *                const emxArray_real_T *Phi_Data_phi_A
 *                const emxArray_real_T *Phi_Data_phi_B
 *                const emxArray_real_T *psi_val
 *                const emxArray_real_T *I
 *                double delta
 *                const emxArray_real_T *sd_S_nom
 *                const emxArray_real_T *sd_T_nom
 *                double m
 *                emxArray_real_T *S
 *                emxArray_real_T *Est_sd_S
 *                emxArray_real_T *T
 *                emxArray_real_T *Est_sd_T
 *                emxArray_real_T *Acc_Rej_Bound
 * Return Type  : void
 */
void Perturbed_Sobol_Indices(const emxArray_real_T *a, const emxArray_real_T
  *delta_weights, const emxArray_real_T *Sobol_Output_A, const emxArray_real_T
  *Sobol_Output_B, const emxArray_real_T *Sobol_Output_YA, const emxArray_real_T
  *Sobol_Output_YB, const emxArray_real_T *Sobol_Output_YC, const
  emxArray_real_T *Phi_Data_phi_A, const emxArray_real_T *Phi_Data_phi_B, const
  emxArray_real_T *psi_val, const emxArray_real_T *I, double delta, const
  emxArray_real_T *sd_S_nom, const emxArray_real_T *sd_T_nom, double m,
  emxArray_real_T *S, emxArray_real_T *Est_sd_S, emxArray_real_T *T,
  emxArray_real_T *Est_sd_T, emxArray_real_T *Acc_Rej_Bound)
{
  int p;
  int i5;
  emxArray_real_T *psi_A;
  unsigned int uv0[2];
  int loop_ub;
  emxArray_real_T *psi_B;
  emxArray_real_T *c;
  int k;
  emxArray_real_T *weight_A_prod;
  emxArray_real_T *weight_B_prod;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_int32_T *b_ii;
  emxArray_int32_T *ib;
  emxArray_real_T *b_Sobol_Output_YA;
  emxArray_real_T *c_ii;
  int i;
  double muYA;
  emxArray_real_T *Perturbed_PDF_A;
  emxArray_real_T *Perturbed_PDF_B;
  emxArray_real_T *b_x;
  int nx;
  int idx;
  boolean_T exitg1;
  double muYB;
  emxArray_real_T *result;
  emxArray_real_T *r9;
  emxArray_real_T *r10;
  unsigned int unnamed_idx_1;
  double A;
  boolean_T b_p;

  /*  Unpack data */
  p = Sobol_Output_YC->size[1] - 1;
  for (i5 = 0; i5 < 2; i5++) {
    uv0[i5] = (unsigned int)Phi_Data_phi_A->size[i5];
  }

  emxInit_real_T(&psi_A, 2);
  i5 = psi_A->size[0] * psi_A->size[1];
  psi_A->size[0] = (int)uv0[0];
  psi_A->size[1] = (int)uv0[1];
  emxEnsureCapacity_real_T1(psi_A, i5);
  loop_ub = (int)uv0[0] * (int)uv0[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    psi_A->data[i5] = 0.0;
  }

  for (i5 = 0; i5 < 2; i5++) {
    uv0[i5] = (unsigned int)Phi_Data_phi_B->size[i5];
  }

  emxInit_real_T(&psi_B, 2);
  i5 = psi_B->size[0] * psi_B->size[1];
  psi_B->size[0] = (int)uv0[0];
  psi_B->size[1] = (int)uv0[1];
  emxEnsureCapacity_real_T1(psi_B, i5);
  loop_ub = (int)uv0[0] * (int)uv0[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    psi_B->data[i5] = 0.0;
  }

  emxInit_real_T2(&c, 1);
  i5 = c->size[0];
  c->size[0] = Sobol_Output_YC->size[1];
  emxEnsureCapacity_real_T2(c, i5);
  loop_ub = Sobol_Output_YC->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    c->data[i5] = 0.0;
  }

  k = 0;
  emxInit_real_T2(&weight_A_prod, 1);
  emxInit_real_T2(&weight_B_prod, 1);
  emxInit_boolean_T(&x, 1);
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&b_ii, 1);
  emxInit_int32_T(&ib, 1);
  emxInit_real_T2(&b_Sobol_Output_YA, 1);
  emxInit_real_T2(&c_ii, 1);
  while (k <= p) {
    for (i = 0; i <= I->size[0] - 2; i++) {
      loop_ub = Sobol_Output_A->size[0];
      muYA = I->data[i + I->size[0] * k];
      i5 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(x, i5);
      for (i5 = 0; i5 < loop_ub; i5++) {
        x->data[i5] = (Sobol_Output_A->data[i5 + Sobol_Output_A->size[0] * k] >
                       muYA);
      }

      nx = x->size[0];
      idx = 0;
      i5 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(ii, i5);
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
          i5 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity_int32_T(ii, i5);
        }
      } else {
        i5 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(ii, i5);
      }

      loop_ub = Sobol_Output_A->size[0];
      muYA = I->data[(i + I->size[0] * k) + 1];
      i5 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(x, i5);
      for (i5 = 0; i5 < loop_ub; i5++) {
        x->data[i5] = (Sobol_Output_A->data[i5 + Sobol_Output_A->size[0] * k] <
                       muYA);
      }

      nx = x->size[0];
      idx = 0;
      i5 = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(b_ii, i5);
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
          i5 = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity_int32_T(b_ii, i5);
        }
      } else {
        i5 = b_ii->size[0];
        if (1 > idx) {
          b_ii->size[0] = 0;
        } else {
          b_ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(b_ii, i5);
      }

      i5 = b_Sobol_Output_YA->size[0];
      b_Sobol_Output_YA->size[0] = ii->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i5);
      loop_ub = ii->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        b_Sobol_Output_YA->data[i5] = ii->data[i5];
      }

      i5 = c_ii->size[0];
      c_ii->size[0] = b_ii->size[0];
      emxEnsureCapacity_real_T2(c_ii, i5);
      loop_ub = b_ii->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        c_ii->data[i5] = b_ii->data[i5];
      }

      do_vectors(b_Sobol_Output_YA, c_ii, weight_A_prod, b_ii, ib);
      loop_ub = Sobol_Output_B->size[0];
      muYA = I->data[i + I->size[0] * k];
      i5 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(x, i5);
      for (i5 = 0; i5 < loop_ub; i5++) {
        x->data[i5] = (Sobol_Output_B->data[i5 + Sobol_Output_B->size[0] * k] >
                       muYA);
      }

      nx = x->size[0];
      idx = 0;
      i5 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(ii, i5);
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
          i5 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity_int32_T(ii, i5);
        }
      } else {
        i5 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(ii, i5);
      }

      loop_ub = Sobol_Output_B->size[0];
      muYA = I->data[(i + I->size[0] * k) + 1];
      i5 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(x, i5);
      for (i5 = 0; i5 < loop_ub; i5++) {
        x->data[i5] = (Sobol_Output_B->data[i5 + Sobol_Output_B->size[0] * k] <
                       muYA);
      }

      nx = x->size[0];
      idx = 0;
      i5 = b_ii->size[0];
      b_ii->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(b_ii, i5);
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
          i5 = b_ii->size[0];
          b_ii->size[0] = 0;
          emxEnsureCapacity_int32_T(b_ii, i5);
        }
      } else {
        i5 = b_ii->size[0];
        if (1 > idx) {
          b_ii->size[0] = 0;
        } else {
          b_ii->size[0] = idx;
        }

        emxEnsureCapacity_int32_T(b_ii, i5);
      }

      i5 = b_Sobol_Output_YA->size[0];
      b_Sobol_Output_YA->size[0] = ii->size[0];
      emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i5);
      loop_ub = ii->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        b_Sobol_Output_YA->data[i5] = ii->data[i5];
      }

      i5 = c_ii->size[0];
      c_ii->size[0] = b_ii->size[0];
      emxEnsureCapacity_real_T2(c_ii, i5);
      loop_ub = b_ii->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        c_ii->data[i5] = b_ii->data[i5];
      }

      do_vectors(b_Sobol_Output_YA, c_ii, weight_B_prod, b_ii, ib);
      i5 = ii->size[0];
      ii->size[0] = weight_A_prod->size[0];
      emxEnsureCapacity_int32_T(ii, i5);
      loop_ub = weight_A_prod->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        ii->data[i5] = (int)weight_A_prod->data[i5];
      }

      loop_ub = ii->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        psi_A->data[(ii->data[i5] + psi_A->size[0] * k) - 1] = a->data[i +
          a->size[0] * k] * psi_val->data[i + psi_val->size[0] * k];
      }

      i5 = ii->size[0];
      ii->size[0] = weight_B_prod->size[0];
      emxEnsureCapacity_int32_T(ii, i5);
      loop_ub = weight_B_prod->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        ii->data[i5] = (int)weight_B_prod->data[i5];
      }

      loop_ub = ii->size[0];
      for (i5 = 0; i5 < loop_ub; i5++) {
        psi_B->data[(ii->data[i5] + psi_B->size[0] * k) - 1] = a->data[i +
          a->size[0] * k] * psi_val->data[i + psi_val->size[0] * k];
      }

      c->data[k] += (I->data[(i + I->size[0] * k) + 1] - I->data[i + I->size[0] *
                     k]) * a->data[i + a->size[0] * k] * psi_val->data[i +
        psi_val->size[0] * k];
    }

    k++;
  }

  emxFree_real_T(&c_ii);
  emxFree_int32_T(&ib);
  emxFree_int32_T(&b_ii);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxInit_real_T(&Perturbed_PDF_A, 2);
  emxInit_real_T(&Perturbed_PDF_B, 2);
  emxInit_real_T2(&b_x, 1);

  /*  Evaluate PDF and perturbed PDF */
  Eval_Perturbed_PDF(Phi_Data_phi_A, psi_A, delta, c, delta_weights,
                     Perturbed_PDF_A);
  Eval_Perturbed_PDF(Phi_Data_phi_B, psi_B, delta, c, delta_weights,
                     Perturbed_PDF_B);

  /*  Evaluate importance sampling weights */
  b_rdivide(Perturbed_PDF_A, Phi_Data_phi_A, psi_B);
  b_rdivide(Perturbed_PDF_B, Phi_Data_phi_B, psi_A);
  prod(psi_B, weight_A_prod);
  prod(psi_A, weight_B_prod);

  /*  Estimate mean and variance */
  i5 = b_x->size[0];
  b_x->size[0] = Sobol_Output_YA->size[0];
  emxEnsureCapacity_real_T2(b_x, i5);
  loop_ub = Sobol_Output_YA->size[0];
  emxFree_real_T(&Perturbed_PDF_B);
  emxFree_real_T(&Perturbed_PDF_A);
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_x->data[i5] = Sobol_Output_YA->data[i5] * weight_A_prod->data[i5];
  }

  muYA = combineVectorElements(b_x) / (double)b_x->size[0];
  i5 = b_x->size[0];
  b_x->size[0] = Sobol_Output_YB->size[0];
  emxEnsureCapacity_real_T2(b_x, i5);
  loop_ub = Sobol_Output_YB->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_x->data[i5] = Sobol_Output_YB->data[i5] * weight_B_prod->data[i5];
  }

  muYB = combineVectorElements(b_x) / (double)b_x->size[0];
  i5 = b_Sobol_Output_YA->size[0];
  b_Sobol_Output_YA->size[0] = Sobol_Output_YA->size[0];
  emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i5);
  loop_ub = Sobol_Output_YA->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_Sobol_Output_YA->data[i5] = Sobol_Output_YA->data[i5] - muYA;
  }

  power(b_Sobol_Output_YA, b_x);
  i5 = b_x->size[0];
  b_x->size[0] = weight_A_prod->size[0];
  emxEnsureCapacity_real_T2(b_x, i5);
  loop_ub = weight_A_prod->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_x->data[i5] *= weight_A_prod->data[i5];
  }

  i5 = b_Sobol_Output_YA->size[0];
  b_Sobol_Output_YA->size[0] = Sobol_Output_YB->size[0];
  emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i5);
  loop_ub = Sobol_Output_YB->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_Sobol_Output_YA->data[i5] = Sobol_Output_YB->data[i5] - muYB;
  }

  power(b_Sobol_Output_YA, c);
  i5 = c->size[0];
  c->size[0] = weight_B_prod->size[0];
  emxEnsureCapacity_real_T2(c, i5);
  loop_ub = weight_B_prod->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    c->data[i5] *= weight_B_prod->data[i5];
  }

  muYA = 0.5 * (combineVectorElements(b_x) / (double)b_x->size[0] +
                combineVectorElements(c) / (double)c->size[0]);

  /*  Estimate Sobol' indices */
  i5 = S->size[0];
  S->size[0] = Sobol_Output_YC->size[1];
  emxEnsureCapacity_real_T2(S, i5);
  i5 = T->size[0];
  T->size[0] = Sobol_Output_YC->size[1];
  emxEnsureCapacity_real_T2(T, i5);
  i5 = Est_sd_S->size[0];
  Est_sd_S->size[0] = Sobol_Output_YC->size[1];
  emxEnsureCapacity_real_T2(Est_sd_S, i5);
  i5 = Est_sd_T->size[0];
  Est_sd_T->size[0] = Sobol_Output_YC->size[1];
  emxEnsureCapacity_real_T2(Est_sd_T, i5);
  for (k = 0; k <= p; k++) {
    i5 = b_x->size[0];
    b_x->size[0] = Sobol_Output_YB->size[0];
    emxEnsureCapacity_real_T2(b_x, i5);
    loop_ub = Sobol_Output_YB->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_x->data[i5] = Sobol_Output_YB->data[i5] * (Sobol_Output_YC->data[i5 +
        Sobol_Output_YC->size[0] * k] - Sobol_Output_YA->data[i5]) *
        weight_A_prod->data[i5] * weight_B_prod->data[i5];
    }

    S->data[k] = combineVectorElements(b_x) / (double)b_x->size[0] / muYA;
    i5 = b_Sobol_Output_YA->size[0];
    b_Sobol_Output_YA->size[0] = Sobol_Output_YA->size[0];
    emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i5);
    loop_ub = Sobol_Output_YA->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_Sobol_Output_YA->data[i5] = Sobol_Output_YA->data[i5] -
        Sobol_Output_YC->data[i5 + Sobol_Output_YC->size[0] * k];
    }

    power(b_Sobol_Output_YA, c);
    i5 = b_x->size[0];
    b_x->size[0] = c->size[0];
    emxEnsureCapacity_real_T2(b_x, i5);
    loop_ub = c->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_x->data[i5] = c->data[i5] * (weight_A_prod->data[i5] * psi_A->data[i5 +
        psi_A->size[0] * k]);
    }

    T->data[k] = 0.5 * (combineVectorElements(b_x) / (double)b_x->size[0]) /
      muYA;
    loop_ub = Sobol_Output_YC->size[0];
    i5 = b_Sobol_Output_YA->size[0];
    b_Sobol_Output_YA->size[0] = loop_ub;
    emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i5);
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_Sobol_Output_YA->data[i5] = Sobol_Output_YC->data[i5 +
        Sobol_Output_YC->size[0] * k];
    }

    Sample_std_Estimate_Weights(m, Sobol_Output_YA, Sobol_Output_YB,
      b_Sobol_Output_YA, psi_B, psi_A, 1.0 + (double)k, &muYB, &A);
    Est_sd_S->data[k] = muYB / sd_S_nom->data[k];
    Est_sd_T->data[k] = A / sd_T_nom->data[k];
  }

  emxFree_real_T(&b_Sobol_Output_YA);
  emxFree_real_T(&b_x);
  emxFree_real_T(&weight_B_prod);
  emxFree_real_T(&weight_A_prod);
  emxFree_real_T(&c);
  emxInit_real_T(&result, 2);
  emxInit_real_T(&r9, 2);
  emxInit_real_T(&r10, 2);
  minOrMax2DColumnMajorDim1(psi_B, r9);
  minOrMax2DColumnMajorDim1(psi_A, r10);
  i5 = result->size[0] * result->size[1];
  result->size[0] = 2;
  result->size[1] = r9->size[1];
  emxEnsureCapacity_real_T1(result, i5);
  loop_ub = r9->size[1];
  emxFree_real_T(&psi_B);
  emxFree_real_T(&psi_A);
  for (i5 = 0; i5 < loop_ub; i5++) {
    result->data[result->size[0] * i5] = r9->data[r9->size[0] * i5];
  }

  emxFree_real_T(&r9);
  loop_ub = r10->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    result->data[1 + result->size[0] * i5] = r10->data[r10->size[0] * i5];
  }

  emxFree_real_T(&r10);
  unnamed_idx_1 = (unsigned int)result->size[1];
  i5 = Acc_Rej_Bound->size[0] * Acc_Rej_Bound->size[1];
  Acc_Rej_Bound->size[0] = 1;
  Acc_Rej_Bound->size[1] = (int)unnamed_idx_1;
  emxEnsureCapacity_real_T1(Acc_Rej_Bound, i5);
  if (result->size[1] >= 1) {
    for (loop_ub = 0; loop_ub < result->size[1]; loop_ub++) {
      Acc_Rej_Bound->data[Acc_Rej_Bound->size[0] * loop_ub] = result->
        data[result->size[0] * loop_ub];
      b_p = ((!rtIsNaN(result->data[1 + result->size[0] * loop_ub])) && (rtIsNaN
              (Acc_Rej_Bound->data[Acc_Rej_Bound->size[0] * loop_ub]) ||
              (Acc_Rej_Bound->data[Acc_Rej_Bound->size[0] * loop_ub] <
               result->data[1 + result->size[0] * loop_ub])));
      if (b_p) {
        Acc_Rej_Bound->data[Acc_Rej_Bound->size[0] * loop_ub] = result->data[1 +
          result->size[0] * loop_ub];
      }
    }
  }

  emxFree_real_T(&result);
}

/*
 * File trailer for Perturbed_Sobol_Indices.c
 *
 * [EOF]
 */
