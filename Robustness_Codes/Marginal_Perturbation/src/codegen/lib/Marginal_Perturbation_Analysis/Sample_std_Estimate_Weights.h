/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Sample_std_Estimate_Weights.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

#ifndef SAMPLE_STD_ESTIMATE_WEIGHTS_H
#define SAMPLE_STD_ESTIMATE_WEIGHTS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Marginal_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Sample_std_Estimate_Weights(double m, const emxArray_real_T *YA,
  const emxArray_real_T *YB, const emxArray_real_T *YCi, const emxArray_real_T
  *weight_A, const emxArray_real_T *weight_B, double i, double *sd_S, double
  *sd_T);

#endif

/*
 * File trailer for Sample_std_Estimate_Weights.h
 *
 * [EOF]
 */
