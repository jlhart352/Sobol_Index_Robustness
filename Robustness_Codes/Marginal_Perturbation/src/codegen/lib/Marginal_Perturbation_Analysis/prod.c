/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: prod.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "prod.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void prod(const emxArray_real_T *x, emxArray_real_T *y)
{
  int vstride;
  int k;
  unsigned int sz[2];
  int j;
  int xoffset;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    for (k = 0; k < 2; k++) {
      sz[k] = (unsigned int)x->size[k];
    }

    k = y->size[0];
    y->size[0] = (int)sz[0];
    emxEnsureCapacity_real_T2(y, k);
    j = (int)sz[0];
    for (k = 0; k < j; k++) {
      y->data[k] = 1.0;
    }
  } else {
    vstride = x->size[0];
    k = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T2(y, k);
    for (j = 0; j < vstride; j++) {
      y->data[j] = x->data[j];
    }

    for (k = 2; k <= x->size[1]; k++) {
      xoffset = (k - 1) * vstride;
      for (j = 0; j < vstride; j++) {
        y->data[j] *= x->data[xoffset + j];
      }
    }
  }
}

/*
 * File trailer for prod.c
 *
 * [EOF]
 */
