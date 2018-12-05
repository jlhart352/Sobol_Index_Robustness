/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortLE.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "sortLE.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *v
 *                const emxArray_int32_T *dir
 *                int idx1
 *                int idx2
 * Return Type  : boolean_T
 */
boolean_T sortLE(const emxArray_real_T *v, const emxArray_int32_T *dir, int idx1,
                 int idx2)
{
  boolean_T p;
  int k;
  boolean_T exitg1;
  int abscolk;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k + 1 <= dir->size[1])) {
    if (dir->data[k] < 0) {
      abscolk = -dir->data[k] - 1;
    } else {
      abscolk = dir->data[k] - 1;
    }

    if ((v->data[(idx1 + v->size[0] * abscolk) - 1] == v->data[(idx2 + v->size[0]
          * abscolk) - 1]) || (rtIsNaN(v->data[(idx1 + v->size[0] * abscolk) - 1])
         && rtIsNaN(v->data[(idx2 + v->size[0] * abscolk) - 1]))) {
      k++;
    } else {
      if (dir->data[k] < 0) {
        if ((v->data[(idx1 + v->size[0] * abscolk) - 1] >= v->data[(idx2 +
              v->size[0] * abscolk) - 1]) || rtIsNaN(v->data[(idx1 + v->size[0] *
              abscolk) - 1])) {
          p = true;
        } else {
          p = false;
        }
      } else if ((v->data[(idx1 + v->size[0] * abscolk) - 1] <= v->data[(idx2 +
                   v->size[0] * abscolk) - 1]) || rtIsNaN(v->data[(idx2 +
                   v->size[0] * abscolk) - 1])) {
        p = true;
      } else {
        p = false;
      }

      exitg1 = true;
    }
  }

  return p;
}

/*
 * File trailer for sortLE.c
 *
 * [EOF]
 */
