/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Psi_Data_Generation.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

#ifndef PSI_DATA_GENERATION_H
#define PSI_DATA_GENERATION_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Marginal_Perturbation_Analysis_types.h"

/* Function Declarations */
extern void Psi_Data_Generation(const emxArray_real_T *Sobol_Output_A, const
  emxArray_real_T *Sobol_Output_B, const emxArray_real_T *Phi_Data_phi_A, const
  emxArray_real_T *Phi_Data_phi_B, const emxArray_real_T *I, emxArray_real_T
  *psi_val);

#endif

/*
 * File trailer for Psi_Data_Generation.h
 *
 * [EOF]
 */
