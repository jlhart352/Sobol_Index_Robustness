/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sum.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "sum.h"
#include "combineVectorElements.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double sum(const emxArray_real_T *x)
{
  return combineVectorElements(x);
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
