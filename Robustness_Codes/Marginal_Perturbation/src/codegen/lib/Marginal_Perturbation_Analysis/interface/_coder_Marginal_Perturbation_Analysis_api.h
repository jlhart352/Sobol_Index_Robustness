/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Marginal_Perturbation_Analysis_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

#ifndef _CODER_MARGINAL_PERTURBATION_ANALYSIS_API_H
#define _CODER_MARGINAL_PERTURBATION_ANALYSIS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_Marginal_Perturbation_Analysis_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  emxArray_real_T *S;
  emxArray_real_T *T;
  emxArray_real_T *A;
  emxArray_real_T *B;
  emxArray_real_T *YA;
  emxArray_real_T *YB;
  emxArray_real_T *YC;
  real_T Var_Y;
  real_T muYA;
  real_T muYB;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  emxArray_real_T *phi_A;
  emxArray_real_T *phi_B;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef struct_s8IUpfemj7ExS25il9u3anF_tag
#define struct_s8IUpfemj7ExS25il9u3anF_tag

struct s8IUpfemj7ExS25il9u3anF_tag
{
  emxArray_real_T *delta_val;
  emxArray_real_T *S_sd_pert;
  emxArray_real_T *S_pert;
  emxArray_real_T *T_sd_pert;
  emxArray_real_T *T_pert;
  emxArray_real_T *Acc_Rej_Bound;
  emxArray_real_T *R;
  emxArray_real_T *a;
  emxArray_real_T *delta_weights;
  emxArray_real_T *psi_val;
  emxArray_real_T *perturbation_marker;
};

#endif                                 /*struct_s8IUpfemj7ExS25il9u3anF_tag*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct s8IUpfemj7ExS25il9u3anF_tag struct2_T;

#endif                                 /*typedef_struct2_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void Marginal_Perturbation_Analysis(struct0_T *Sobol_Output, struct1_T
  *Phi_Data, real_T r, real_T m, emxArray_real_T *R, emxArray_real_T *sd_S_nom,
  emxArray_real_T *sd_T_nom, struct2_T *Perturbation_Output);
extern void Marginal_Perturbation_Analysis_api(const mxArray * const prhs[7],
  int32_T nlhs, const mxArray *plhs[1]);
extern void Marginal_Perturbation_Analysis_atexit(void);
extern void Marginal_Perturbation_Analysis_initialize(void);
extern void Marginal_Perturbation_Analysis_terminate(void);
extern void Marginal_Perturbation_Analysis_xil_terminate(void);

#endif

/*
 * File trailer for _coder_Marginal_Perturbation_Analysis_api.h
 *
 * [EOF]
 */
