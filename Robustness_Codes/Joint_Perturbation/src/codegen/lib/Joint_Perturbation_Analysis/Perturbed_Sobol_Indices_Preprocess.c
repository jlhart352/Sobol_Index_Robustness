/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Perturbed_Sobol_Indices_Preprocess.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Perturbed_Sobol_Indices_Preprocess.h"
#include "Eval_Int_Psi_xk.h"
#include "Eval_Psi_Sign.h"
#include "Joint_Perturbation_Analysis_emxutil.h"
#include "combineVectorElements.h"
#include "rdivide.h"

/* Function Definitions */

/*
 * Evaluate Sobol' indices with perturbed PDF via importance sampling
 * Arguments    : const emxArray_real_T *Sobol_Output_A
 *                const emxArray_real_T *Sobol_Output_C
 *                const emxArray_real_T *Phi_Data_phi_A
 *                const emxArray_real_T *Psi_Data_psi_A_val
 *                const emxArray_real_T *Psi_Data_psi_C_val
 *                const emxArray_real_T *Psi_Data_psi_val
 *                const emxArray_real_T *a
 *                const emxArray_real_T *R
 *                emxArray_real_T *Perturbed_PDF_Data_psi_A
 *                emxArray_real_T *Perturbed_PDF_Data_psi_C
 *                emxArray_real_T *c_Perturbed_PDF_Data_psi_C_marg
 *                double *Perturbed_PDF_Data_c
 * Return Type  : void
 */
void c_Perturbed_Sobol_Indices_Prepr(const emxArray_real_T *Sobol_Output_A,
  const emxArray_real_T *Sobol_Output_C, const emxArray_real_T *Phi_Data_phi_A,
  const emxArray_real_T *Psi_Data_psi_A_val, const emxArray_real_T
  *Psi_Data_psi_C_val, const emxArray_real_T *Psi_Data_psi_val, const
  emxArray_real_T *a, const emxArray_real_T *R, emxArray_real_T
  *Perturbed_PDF_Data_psi_A, emxArray_real_T *Perturbed_PDF_Data_psi_C,
  emxArray_real_T *c_Perturbed_PDF_Data_psi_C_marg, double *Perturbed_PDF_Data_c)
{
  emxArray_real_T *psi_A;
  int N;
  int p;
  int i4;
  int loop_ub;
  emxArray_real_T *psi_C;
  emxArray_real_T *psi_C_marg_not_k;
  emxArray_real_T *x;
  int k;
  emxArray_real_T *r12;
  emxArray_real_T *b_x;
  int b_loop_ub;
  int b_N[2];
  int i5;
  emxArray_real_T c_x;
  int c_N[2];
  emxInit_real_T2(&psi_A, 1);

  /*  Unpack data */
  N = Sobol_Output_A->size[0];
  p = Sobol_Output_A->size[1];

  /*  Evaluate PDF */
  Eval_Psi_Sign(Sobol_Output_A, R, a, psi_A);
  i4 = psi_A->size[0];
  emxEnsureCapacity_real_T2(psi_A, i4);
  loop_ub = psi_A->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    psi_A->data[i4] *= Psi_Data_psi_A_val->data[i4];
  }

  emxInit_real_T(&psi_C, 2);
  emxInit_real_T(&psi_C_marg_not_k, 2);
  emxInit_real_T2(&x, 1);
  b_rdivide(psi_A, Phi_Data_phi_A, x);
  i4 = psi_C->size[0] * psi_C->size[1];
  psi_C->size[0] = Sobol_Output_A->size[0];
  psi_C->size[1] = Sobol_Output_A->size[1];
  emxEnsureCapacity_real_T(psi_C, i4);
  i4 = psi_C_marg_not_k->size[0] * psi_C_marg_not_k->size[1];
  psi_C_marg_not_k->size[0] = Sobol_Output_A->size[0];
  psi_C_marg_not_k->size[1] = Sobol_Output_A->size[1];
  emxEnsureCapacity_real_T(psi_C_marg_not_k, i4);
  k = 0;
  emxInit_real_T2(&r12, 1);
  emxInit_real_T1(&b_x, 3);
  while (k <= p - 1) {
    loop_ub = Sobol_Output_C->size[1];
    b_loop_ub = Sobol_Output_C->size[2];
    i4 = b_x->size[0] * b_x->size[1] * b_x->size[2];
    b_x->size[0] = 1;
    b_x->size[1] = loop_ub;
    b_x->size[2] = b_loop_ub;
    emxEnsureCapacity_real_T1(b_x, i4);
    for (i4 = 0; i4 < b_loop_ub; i4++) {
      for (i5 = 0; i5 < loop_ub; i5++) {
        b_x->data[b_x->size[0] * i5 + b_x->size[0] * b_x->size[1] * i4] =
          Sobol_Output_C->data[(k + Sobol_Output_C->size[0] * i5) +
          Sobol_Output_C->size[0] * Sobol_Output_C->size[1] * i4];
      }
    }

    b_N[0] = N;
    b_N[1] = p;
    c_x = *b_x;
    c_x.size = (int *)&b_N;
    c_x.numDimensions = 1;
    Eval_Psi_Sign(&c_x, R, a, r12);
    loop_ub = r12->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      psi_C->data[i4 + psi_C->size[0] * k] = r12->data[i4] *
        Psi_Data_psi_C_val->data[i4 + Psi_Data_psi_C_val->size[0] * k];
    }

    c_N[0] = N;
    c_N[1] = p;
    c_x = *b_x;
    c_x.size = (int *)&c_N;
    c_x.numDimensions = 1;
    Eval_Int_Psi_xk(&c_x, 1.0 + (double)k, R, a, Psi_Data_psi_val, r12);
    loop_ub = r12->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      psi_C_marg_not_k->data[i4 + psi_C_marg_not_k->size[0] * k] = r12->data[i4];
    }

    k++;
  }

  emxFree_real_T(&b_x);
  emxFree_real_T(&r12);
  i4 = Perturbed_PDF_Data_psi_A->size[0];
  Perturbed_PDF_Data_psi_A->size[0] = psi_A->size[0];
  emxEnsureCapacity_real_T2(Perturbed_PDF_Data_psi_A, i4);
  loop_ub = psi_A->size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    Perturbed_PDF_Data_psi_A->data[i4] = psi_A->data[i4];
  }

  emxFree_real_T(&psi_A);
  i4 = Perturbed_PDF_Data_psi_C->size[0] * Perturbed_PDF_Data_psi_C->size[1];
  Perturbed_PDF_Data_psi_C->size[0] = psi_C->size[0];
  Perturbed_PDF_Data_psi_C->size[1] = psi_C->size[1];
  emxEnsureCapacity_real_T(Perturbed_PDF_Data_psi_C, i4);
  loop_ub = psi_C->size[0] * psi_C->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    Perturbed_PDF_Data_psi_C->data[i4] = psi_C->data[i4];
  }

  emxFree_real_T(&psi_C);
  i4 = c_Perturbed_PDF_Data_psi_C_marg->size[0] *
    c_Perturbed_PDF_Data_psi_C_marg->size[1];
  c_Perturbed_PDF_Data_psi_C_marg->size[0] = psi_C_marg_not_k->size[0];
  c_Perturbed_PDF_Data_psi_C_marg->size[1] = psi_C_marg_not_k->size[1];
  emxEnsureCapacity_real_T(c_Perturbed_PDF_Data_psi_C_marg, i4);
  loop_ub = psi_C_marg_not_k->size[0] * psi_C_marg_not_k->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    c_Perturbed_PDF_Data_psi_C_marg->data[i4] = psi_C_marg_not_k->data[i4];
  }

  emxFree_real_T(&psi_C_marg_not_k);
  *Perturbed_PDF_Data_c = combineVectorElements(x) / (double)x->size[0];
  emxFree_real_T(&x);
}

/*
 * File trailer for Perturbed_Sobol_Indices_Preprocess.c
 *
 * [EOF]
 */
