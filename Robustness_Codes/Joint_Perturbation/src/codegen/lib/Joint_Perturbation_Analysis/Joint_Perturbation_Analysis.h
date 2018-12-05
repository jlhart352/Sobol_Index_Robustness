/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Joint_Perturbation_Analysis.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

#ifndef JOINT_PERTURBATION_ANALYSIS_H
#define JOINT_PERTURBATION_ANALYSIS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Joint_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Joint_Perturbation_Analysis(const struct0_T *Sobol_Output, const
  struct1_T *Phi_Data, const emxArray_real_T *sd_nom, const emxArray_real_T *R,
  double r, double tau, double m, emxArray_real_T *T_pert);

#endif

/*
 * File trailer for Joint_Perturbation_Analysis.h
 *
 * [EOF]
 */
