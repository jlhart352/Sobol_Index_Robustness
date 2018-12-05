/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Perturbed_Sobol_Indices.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

#ifndef PERTURBED_SOBOL_INDICES_H
#define PERTURBED_SOBOL_INDICES_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Joint_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Perturbed_Sobol_Indices(const emxArray_real_T *Sobol_Output_YA,
  const emxArray_real_T *Sobol_Output_YC, const emxArray_real_T *Phi_Data_phi_A,
  const emxArray_real_T *Phi_Data_phi_C, const emxArray_real_T
  *Phi_Data_phi_C_Cond_not_k, const emxArray_real_T *Phi_Data_phi_C_marg_not_k,
  const emxArray_real_T *Perturbed_PDF_Data_psi_A, const emxArray_real_T
  *Perturbed_PDF_Data_psi_C, const emxArray_real_T
  *c_Perturbed_PDF_Data_psi_C_marg, double Perturbed_PDF_Data_c, double h, const
  emxArray_real_T *sd_nom, double m, emxArray_real_T *T, emxArray_real_T *Est_sd);

#endif

/*
 * File trailer for Perturbed_Sobol_Indices.h
 *
 * [EOF]
 */
