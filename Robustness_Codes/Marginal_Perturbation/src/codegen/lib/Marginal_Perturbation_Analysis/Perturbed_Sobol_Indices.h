/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Perturbed_Sobol_Indices.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

#ifndef PERTURBED_SOBOL_INDICES_H
#define PERTURBED_SOBOL_INDICES_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Marginal_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Perturbed_Sobol_Indices(const emxArray_real_T *a, const
  emxArray_real_T *delta_weights, const emxArray_real_T *Sobol_Output_A, const
  emxArray_real_T *Sobol_Output_B, const emxArray_real_T *Sobol_Output_YA, const
  emxArray_real_T *Sobol_Output_YB, const emxArray_real_T *Sobol_Output_YC,
  const emxArray_real_T *Phi_Data_phi_A, const emxArray_real_T *Phi_Data_phi_B,
  const emxArray_real_T *psi_val, const emxArray_real_T *I, double delta, const
  emxArray_real_T *sd_S_nom, const emxArray_real_T *sd_T_nom, double m,
  emxArray_real_T *S, emxArray_real_T *Est_sd_S, emxArray_real_T *T,
  emxArray_real_T *Est_sd_T, emxArray_real_T *Acc_Rej_Bound);

#endif

/*
 * File trailer for Perturbed_Sobol_Indices.h
 *
 * [EOF]
 */
