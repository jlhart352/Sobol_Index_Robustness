/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Marginal_Perturbation_Analysis_types.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

#ifndef MARGINAL_PERTURBATION_ANALYSIS_TYPES_H
#define MARGINAL_PERTURBATION_ANALYSIS_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  double Var_Y;
  double muYA;
  double muYB;
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
#endif

/*
 * File trailer for Marginal_Perturbation_Analysis_types.h
 *
 * [EOF]
 */
