/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Eval_Perturbed_PDF.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "Eval_Perturbed_PDF.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"

/* Function Definitions */

/*
 * Evaluate \frac{\phi(x) + delta*\psi(x)}{1+int delta*psi} for each row in X
 * Arguments    : const emxArray_real_T *phi_X
 *                const emxArray_real_T *psi_X
 *                double delta
 *                const emxArray_real_T *c
 *                const emxArray_real_T *delta_weights
 *                emxArray_real_T *Y
 * Return Type  : void
 */
void Eval_Perturbed_PDF(const emxArray_real_T *phi_X, const emxArray_real_T
  *psi_X, double delta, const emxArray_real_T *c, const emxArray_real_T
  *delta_weights, emxArray_real_T *Y)
{
  int i6;
  int k;
  double a;
  double B;
  int loop_ub;
  i6 = Y->size[0] * Y->size[1];
  Y->size[0] = phi_X->size[0];
  Y->size[1] = phi_X->size[1];
  emxEnsureCapacity_real_T1(Y, i6);
  for (k = 0; k < phi_X->size[1]; k++) {
    a = delta_weights->data[k] * delta;
    B = 1.0 + delta_weights->data[k] * delta * c->data[k];
    loop_ub = phi_X->size[0] - 1;
    for (i6 = 0; i6 <= loop_ub; i6++) {
      Y->data[i6 + Y->size[0] * k] = (phi_X->data[i6 + phi_X->size[0] * k] + a *
        psi_X->data[i6 + psi_X->size[0] * k]) / B;
    }
  }
}

/*
 * File trailer for Eval_Perturbed_PDF.c
 *
 * [EOF]
 */
