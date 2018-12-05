/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: unaryMinOrMax.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "unaryMinOrMax.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *ex
 * Return Type  : void
 */
void minOrMax2DColumnMajorDim1(const emxArray_real_T *x, emxArray_real_T *ex)
{
  unsigned int unnamed_idx_1;
  int j;
  int i;
  boolean_T p;
  unnamed_idx_1 = (unsigned int)x->size[1];
  j = ex->size[0] * ex->size[1];
  ex->size[0] = 1;
  ex->size[1] = (int)unnamed_idx_1;
  emxEnsureCapacity_real_T1(ex, j);
  if (x->size[1] >= 1) {
    for (j = 0; j < x->size[1]; j++) {
      ex->data[ex->size[0] * j] = x->data[x->size[0] * j];
      for (i = 1; i < x->size[0]; i++) {
        p = ((!rtIsNaN(x->data[i + x->size[0] * j])) && (rtIsNaN(ex->data
               [ex->size[0] * j]) || (ex->data[ex->size[0] * j] < x->data[i +
               x->size[0] * j])));
        if (p) {
          ex->data[ex->size[0] * j] = x->data[i + x->size[0] * j];
        }
      }
    }
  }
}

/*
 * File trailer for unaryMinOrMax.c
 *
 * [EOF]
 */
