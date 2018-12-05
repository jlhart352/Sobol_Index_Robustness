/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Joint_Perturbation_Analysis_initialize.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Joint_Perturbation_Analysis_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void Joint_Perturbation_Analysis_initialize(void)
{
  rt_InitInfAndNaN(8U);
  c_eml_rand_mt19937ar_stateful_i();
}

/*
 * File trailer for Joint_Perturbation_Analysis_initialize.c
 *
 * [EOF]
 */
