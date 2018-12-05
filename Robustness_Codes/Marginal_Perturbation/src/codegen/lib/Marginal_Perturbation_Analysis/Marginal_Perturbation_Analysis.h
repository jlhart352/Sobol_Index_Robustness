/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Marginal_Perturbation_Analysis.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

#ifndef MARGINAL_PERTURBATION_ANALYSIS_H
#define MARGINAL_PERTURBATION_ANALYSIS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Marginal_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Marginal_Perturbation_Analysis(const struct0_T *Sobol_Output, const
  struct1_T *Phi_Data, double r, double m, const emxArray_real_T *R, const
  emxArray_real_T *sd_S_nom, const emxArray_real_T *sd_T_nom, struct2_T
  *Perturbation_Output);

#endif

/*
 * File trailer for Marginal_Perturbation_Analysis.h
 *
 * [EOF]
 */
