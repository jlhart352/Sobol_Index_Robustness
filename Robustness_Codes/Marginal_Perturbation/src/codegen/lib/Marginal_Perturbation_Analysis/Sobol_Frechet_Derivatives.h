/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Sobol_Frechet_Derivatives.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

#ifndef SOBOL_FRECHET_DERIVATIVES_H
#define SOBOL_FRECHET_DERIVATIVES_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Marginal_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Sobol_Frechet_Derivatives(const emxArray_real_T *Sobol_Output_S,
  const emxArray_real_T *Sobol_Output_T, const emxArray_real_T *Sobol_Output_A,
  const emxArray_real_T *Sobol_Output_B, const emxArray_real_T *Sobol_Output_YA,
  const emxArray_real_T *Sobol_Output_YB, const emxArray_real_T *Sobol_Output_YC,
  double Sobol_Output_Var_Y, double Sobol_Output_muYA, double Sobol_Output_muYB,
  const emxArray_real_T *Phi_Data_phi_A, const emxArray_real_T *Phi_Data_phi_B,
  const emxArray_real_T *psi_val, const emxArray_real_T *I, double k,
  emxArray_real_T *a_S, emxArray_real_T *a_T, emxArray_real_T *weights_S,
  emxArray_real_T *weights_T);

#endif

/*
 * File trailer for Sobol_Frechet_Derivatives.h
 *
 * [EOF]
 */
