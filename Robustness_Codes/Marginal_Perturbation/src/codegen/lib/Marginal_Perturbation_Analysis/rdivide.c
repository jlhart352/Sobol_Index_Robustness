/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rdivide.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "rdivide.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"

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
  int i7;
  int loop_ub;
  i7 = z->size[0] * z->size[1];
  z->size[0] = x->size[0];
  z->size[1] = x->size[1];
  emxEnsureCapacity_real_T1(z, i7);
  loop_ub = x->size[0] * x->size[1];
  for (i7 = 0; i7 < loop_ub; i7++) {
    z->data[i7] = x->data[i7] / y->data[i7];
  }
}

/*
 * Arguments    : const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void rdivide(const emxArray_real_T *y, emxArray_real_T *z)
{
  int i3;
  int loop_ub;
  i3 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity_real_T2(z, i3);
  loop_ub = y->size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    z->data[i3] = 1.0 / y->data[i3];
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
