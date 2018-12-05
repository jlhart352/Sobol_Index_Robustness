/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Eval_Perturbed_PDF.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

#ifndef EVAL_PERTURBED_PDF_H
#define EVAL_PERTURBED_PDF_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Marginal_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Eval_Perturbed_PDF(const emxArray_real_T *phi_X, const
  emxArray_real_T *psi_X, double delta, const emxArray_real_T *c, const
  emxArray_real_T *delta_weights, emxArray_real_T *Y);

#endif

/*
 * File trailer for Eval_Perturbed_PDF.h
 *
 * [EOF]
 */
