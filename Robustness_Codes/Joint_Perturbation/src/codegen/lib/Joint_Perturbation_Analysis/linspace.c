/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: linspace.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "linspace.h"
#include "Joint_Perturbation_Analysis_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : double n1
 *                emxArray_real_T *y
 * Return Type  : void
 */
void linspace(double n1, emxArray_real_T *y)
{
  int i3;
  double delta1;
  int k;
  if (n1 < 0.0) {
    n1 = 0.0;
  }

  i3 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)floor(n1);
  emxEnsureCapacity_real_T(y, i3);
  if (y->size[1] >= 1) {
    y->data[y->size[1] - 1] = 1.0;
    if (y->size[1] >= 2) {
      y->data[0] = -1.0;
      if (y->size[1] >= 3) {
        delta1 = 2.0 / ((double)y->size[1] - 1.0);
        i3 = y->size[1];
        for (k = 0; k <= i3 - 3; k++) {
          y->data[k + 1] = -1.0 + (1.0 + (double)k) * delta1;
        }
      }
    }
  }
}

/*
 * File trailer for linspace.c
 *
 * [EOF]
 */
