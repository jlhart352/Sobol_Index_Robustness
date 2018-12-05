/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Sobol_Frechet_Derivatives.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

#ifndef SOBOL_FRECHET_DERIVATIVES_H
#define SOBOL_FRECHET_DERIVATIVES_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Joint_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Sobol_Frechet_Derivatives(const emxArray_real_T *Sobol_Output_T,
  const emxArray_real_T *Sobol_Output_A, const emxArray_real_T *Sobol_Output_C,
  const emxArray_real_T *Sobol_Output_YA, const emxArray_real_T *Sobol_Output_YC,
  double Sobol_Output_Var_Y, double Sobol_Output_muYA, const emxArray_real_T
  *Phi_Data_phi_A, const emxArray_real_T *Phi_Data_phi_A_marg_not_k, const
  emxArray_real_T *Phi_Data_phi_C, const emxArray_real_T *R, emxArray_real_T *a,
  emxArray_real_T *a_normalized, emxArray_real_T *Psi_Data_psi_A_val,
  emxArray_real_T *Psi_Data_psi_C_val, emxArray_real_T *Psi_Data_psi_val);

#endif

/*
 * File trailer for Sobol_Frechet_Derivatives.h
 *
 * [EOF]
 */
