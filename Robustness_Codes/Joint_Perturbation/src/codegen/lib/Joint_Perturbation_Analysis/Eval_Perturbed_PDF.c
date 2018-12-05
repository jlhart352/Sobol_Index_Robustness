/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Eval_Perturbed_PDF.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Eval_Perturbed_PDF.h"
#include "Joint_Perturbation_Analysis_emxutil.h"

/* Function Definitions */

/*
 * Evaluate \frac{\phi(x) + h*\psi(x)}{1+c} for each row in X
 * Arguments    : const emxArray_real_T *phi_X
 *                const emxArray_real_T *psi_X
 *                double h
 *                double c
 *                emxArray_real_T *Y
 * Return Type  : void
 */
void Eval_Perturbed_PDF(const emxArray_real_T *phi_X, const emxArray_real_T
  *psi_X, double h, double c, emxArray_real_T *Y)
{
  double B;
  int i8;
  int loop_ub;
  B = 1.0 + h * c;
  i8 = Y->size[0];
  Y->size[0] = phi_X->size[0];
  emxEnsureCapacity_real_T2(Y, i8);
  loop_ub = phi_X->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    Y->data[i8] = (phi_X->data[i8] + h * psi_X->data[i8]) / B;
  }
}

/*
 * File trailer for Eval_Perturbed_PDF.c
 *
 * [EOF]
 */
