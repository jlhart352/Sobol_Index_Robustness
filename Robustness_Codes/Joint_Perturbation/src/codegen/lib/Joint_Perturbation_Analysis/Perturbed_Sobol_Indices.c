/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Perturbed_Sobol_Indices.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Perturbed_Sobol_Indices.h"
#include "Sample_std_Estimate_Weights.h"
#include "Joint_Perturbation_Analysis_emxutil.h"
#include "combineVectorElements.h"
#include "power.h"
#include "rdivide.h"
#include "Eval_Perturbed_PDF.h"

/* Function Definitions */

/*
 * Evaluate Sobol' indices with perturbed PDF via importance sampling
 * Arguments    : const emxArray_real_T *Sobol_Output_YA
 *                const emxArray_real_T *Sobol_Output_YC
 *                const emxArray_real_T *Phi_Data_phi_A
 *                const emxArray_real_T *Phi_Data_phi_C
 *                const emxArray_real_T *Phi_Data_phi_C_Cond_not_k
 *                const emxArray_real_T *Phi_Data_phi_C_marg_not_k
 *                const emxArray_real_T *Perturbed_PDF_Data_psi_A
 *                const emxArray_real_T *Perturbed_PDF_Data_psi_C
 *                const emxArray_real_T *c_Perturbed_PDF_Data_psi_C_marg
 *                double Perturbed_PDF_Data_c
 *                double h
 *                const emxArray_real_T *sd_nom
 *                double m
 *                emxArray_real_T *T
 *                emxArray_real_T *Est_sd
 * Return Type  : void
 */
void Perturbed_Sobol_Indices(const emxArray_real_T *Sobol_Output_YA, const
  emxArray_real_T *Sobol_Output_YC, const emxArray_real_T *Phi_Data_phi_A, const
  emxArray_real_T *Phi_Data_phi_C, const emxArray_real_T
  *Phi_Data_phi_C_Cond_not_k, const emxArray_real_T *Phi_Data_phi_C_marg_not_k,
  const emxArray_real_T *Perturbed_PDF_Data_psi_A, const emxArray_real_T
  *Perturbed_PDF_Data_psi_C, const emxArray_real_T
  *c_Perturbed_PDF_Data_psi_C_marg, double Perturbed_PDF_Data_c, double h, const
  emxArray_real_T *sd_nom, double m, emxArray_real_T *T, emxArray_real_T *Est_sd)
{
  emxArray_real_T *Perturbed_PDF_A;
  emxArray_real_T *weight_A;
  emxArray_real_T *x;
  int i7;
  int loop_ub;
  emxArray_real_T *b_Sobol_Output_YA;
  double muYA;
  double Var_Y;
  int k;
  emxArray_real_T *weight_Ck;
  emxArray_real_T *b_Perturbed_PDF_Data_psi_C;
  emxInit_real_T2(&Perturbed_PDF_A, 1);
  emxInit_real_T2(&weight_A, 1);
  emxInit_real_T2(&x, 1);

  /*  Unpack data */
  /*  Evaluate PDF and perturbed PDF */
  Eval_Perturbed_PDF(Phi_Data_phi_A, Perturbed_PDF_Data_psi_A, h,
                     Perturbed_PDF_Data_c, Perturbed_PDF_A);

  /*  Evaluate importance sampling weights */
  b_rdivide(Perturbed_PDF_A, Phi_Data_phi_A, weight_A);

  /*  Estimate mean and variance */
  i7 = x->size[0];
  x->size[0] = Sobol_Output_YA->size[0];
  emxEnsureCapacity_real_T2(x, i7);
  loop_ub = Sobol_Output_YA->size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    x->data[i7] = Sobol_Output_YA->data[i7] * weight_A->data[i7];
  }

  emxInit_real_T2(&b_Sobol_Output_YA, 1);
  muYA = combineVectorElements(x) / (double)x->size[0];
  i7 = b_Sobol_Output_YA->size[0];
  b_Sobol_Output_YA->size[0] = Sobol_Output_YA->size[0];
  emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i7);
  loop_ub = Sobol_Output_YA->size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    b_Sobol_Output_YA->data[i7] = Sobol_Output_YA->data[i7] - muYA;
  }

  power(b_Sobol_Output_YA, x);
  i7 = x->size[0];
  x->size[0] = weight_A->size[0];
  emxEnsureCapacity_real_T2(x, i7);
  loop_ub = weight_A->size[0];
  for (i7 = 0; i7 < loop_ub; i7++) {
    x->data[i7] *= weight_A->data[i7];
  }

  Var_Y = combineVectorElements(x) / (double)x->size[0];

  /*  Estimate total Sobol' indices */
  i7 = T->size[0];
  T->size[0] = Sobol_Output_YC->size[1];
  emxEnsureCapacity_real_T2(T, i7);
  i7 = Est_sd->size[0];
  Est_sd->size[0] = Sobol_Output_YC->size[1];
  emxEnsureCapacity_real_T2(Est_sd, i7);
  k = 0;
  emxInit_real_T2(&weight_Ck, 1);
  emxInit_real_T2(&b_Perturbed_PDF_Data_psi_C, 1);
  while (k <= Sobol_Output_YC->size[1] - 1) {
    /*  Evaluate the conditional perturbed PDF conditioned X_j, j not equal k, */
    /*  i.e. \frac{\phi(x) + h*\psi(x)}{1+h*int_\Omega \psi(x)dx} */
    /*  Evaluate int_{\Omega_k} \frac{\phi(x) + h*\psi(x)}{1+c} dx_k for each row in X */
    muYA = 1.0 / (1.0 + h * Perturbed_PDF_Data_c);
    loop_ub = Phi_Data_phi_C->size[0];
    i7 = b_Sobol_Output_YA->size[0];
    b_Sobol_Output_YA->size[0] = loop_ub;
    emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i7);
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_Sobol_Output_YA->data[i7] = Phi_Data_phi_C->data[i7 +
        Phi_Data_phi_C->size[0] * k];
    }

    loop_ub = Perturbed_PDF_Data_psi_C->size[0];
    i7 = b_Perturbed_PDF_Data_psi_C->size[0];
    b_Perturbed_PDF_Data_psi_C->size[0] = loop_ub;
    emxEnsureCapacity_real_T2(b_Perturbed_PDF_Data_psi_C, i7);
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_Perturbed_PDF_Data_psi_C->data[i7] = Perturbed_PDF_Data_psi_C->data[i7 +
        Perturbed_PDF_Data_psi_C->size[0] * k];
    }

    Eval_Perturbed_PDF(b_Sobol_Output_YA, b_Perturbed_PDF_Data_psi_C, h,
                       Perturbed_PDF_Data_c, x);
    loop_ub = Phi_Data_phi_C_marg_not_k->size[0];
    i7 = b_Sobol_Output_YA->size[0];
    b_Sobol_Output_YA->size[0] = loop_ub;
    emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i7);
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_Sobol_Output_YA->data[i7] = muYA * (Phi_Data_phi_C_marg_not_k->data[i7 +
        Phi_Data_phi_C_marg_not_k->size[0] * k] + h *
        c_Perturbed_PDF_Data_psi_C_marg->data[i7 +
        c_Perturbed_PDF_Data_psi_C_marg->size[0] * k]);
    }

    b_rdivide(x, b_Sobol_Output_YA, weight_Ck);
    i7 = b_Sobol_Output_YA->size[0];
    b_Sobol_Output_YA->size[0] = Perturbed_PDF_A->size[0];
    emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i7);
    loop_ub = Perturbed_PDF_A->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_Sobol_Output_YA->data[i7] = Perturbed_PDF_A->data[i7] * weight_Ck->
        data[i7];
    }

    i7 = b_Perturbed_PDF_Data_psi_C->size[0];
    b_Perturbed_PDF_Data_psi_C->size[0] = Phi_Data_phi_A->size[0];
    emxEnsureCapacity_real_T2(b_Perturbed_PDF_Data_psi_C, i7);
    loop_ub = Phi_Data_phi_A->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_Perturbed_PDF_Data_psi_C->data[i7] = Phi_Data_phi_A->data[i7] *
        Phi_Data_phi_C_Cond_not_k->data[i7 + Phi_Data_phi_C_Cond_not_k->size[0] *
        k];
    }

    b_rdivide(b_Sobol_Output_YA, b_Perturbed_PDF_Data_psi_C, weight_Ck);
    i7 = b_Sobol_Output_YA->size[0];
    b_Sobol_Output_YA->size[0] = Sobol_Output_YA->size[0];
    emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i7);
    loop_ub = Sobol_Output_YA->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_Sobol_Output_YA->data[i7] = Sobol_Output_YA->data[i7] -
        Sobol_Output_YC->data[i7 + Sobol_Output_YC->size[0] * k];
    }

    power(b_Sobol_Output_YA, x);
    i7 = x->size[0];
    emxEnsureCapacity_real_T2(x, i7);
    loop_ub = x->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      x->data[i7] *= weight_Ck->data[i7];
    }

    T->data[k] = 0.5 * (combineVectorElements(x) / (double)x->size[0]) / Var_Y;
    loop_ub = Sobol_Output_YC->size[0];
    i7 = b_Sobol_Output_YA->size[0];
    b_Sobol_Output_YA->size[0] = loop_ub;
    emxEnsureCapacity_real_T2(b_Sobol_Output_YA, i7);
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_Sobol_Output_YA->data[i7] = Sobol_Output_YC->data[i7 +
        Sobol_Output_YC->size[0] * k];
    }

    muYA = Sample_std_Estimate_Weights(m, Sobol_Output_YA, b_Sobol_Output_YA,
      weight_A, weight_Ck);
    Est_sd->data[k] = muYA / sd_nom->data[k];
    k++;
  }

  emxFree_real_T(&b_Perturbed_PDF_Data_psi_C);
  emxFree_real_T(&b_Sobol_Output_YA);
  emxFree_real_T(&x);
  emxFree_real_T(&weight_Ck);
  emxFree_real_T(&weight_A);
  emxFree_real_T(&Perturbed_PDF_A);
}

/*
 * File trailer for Perturbed_Sobol_Indices.c
 *
 * [EOF]
 */
