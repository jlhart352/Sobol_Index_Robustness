/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Perturbed_Sobol_Indices_Preprocess.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

#ifndef PERTURBED_SOBOL_INDICES_PREPROCESS_H
#define PERTURBED_SOBOL_INDICES_PREPROCESS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Joint_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void c_Perturbed_Sobol_Indices_Prepr(const emxArray_real_T
  *Sobol_Output_A, const emxArray_real_T *Sobol_Output_C, const emxArray_real_T *
  Phi_Data_phi_A, const emxArray_real_T *Psi_Data_psi_A_val, const
  emxArray_real_T *Psi_Data_psi_C_val, const emxArray_real_T *Psi_Data_psi_val,
  const emxArray_real_T *a, const emxArray_real_T *R, emxArray_real_T
  *Perturbed_PDF_Data_psi_A, emxArray_real_T *Perturbed_PDF_Data_psi_C,
  emxArray_real_T *c_Perturbed_PDF_Data_psi_C_marg, double *Perturbed_PDF_Data_c);

#endif

/*
 * File trailer for Perturbed_Sobol_Indices_Preprocess.h
 *
 * [EOF]
 */
