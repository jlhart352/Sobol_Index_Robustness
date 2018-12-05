/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rdivide.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "rdivide.h"
#include "Joint_Perturbation_Analysis_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void b_rdivide(const emxArray_real_T *x, const emxArray_real_T *y,
               emxArray_real_T *z)
{
  int i6;
  int loop_ub;
  i6 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity_real_T2(z, i6);
  loop_ub = x->size[0];
  for (i6 = 0; i6 < loop_ub; i6++) {
    z->data[i6] = x->data[i6] / y->data[i6];
  }
}

/*
 * Arguments    : const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void rdivide(const emxArray_real_T *y, emxArray_real_T *z)
{
  int i2;
  int loop_ub;
  i2 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity_real_T2(z, i2);
  loop_ub = y->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    z->data[i2] = 1.0 / y->data[i2];
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
