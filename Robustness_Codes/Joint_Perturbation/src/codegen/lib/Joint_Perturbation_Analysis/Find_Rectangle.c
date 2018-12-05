/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Find_Rectangle.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Find_Rectangle.h"
#include "Joint_Perturbation_Analysis_emxutil.h"

/* Function Definitions */

/*
 * Input a Nxp matrix X of points and a cell R whose jth matrix is the bounds defining the jth rectangle
 *  Return a Nx1 vector whose jth entry identifies the rectangle containing X(j,:)
 * Arguments    : const emxArray_real_T *X
 *                const emxArray_real_T *R
 *                emxArray_real_T *I
 * Return Type  : void
 */
void Find_Rectangle(const emxArray_real_T *X, const emxArray_real_T *R,
                    emxArray_real_T *I)
{
  int idx;
  int loop_ub;
  int p;
  int k;
  emxArray_real_T *varargin_1;
  emxArray_real_T *b_R;
  unsigned int j;
  int b_loop_ub;
  double ex;
  boolean_T exitg1;
  idx = I->size[0];
  I->size[0] = X->size[0];
  emxEnsureCapacity_real_T2(I, idx);
  loop_ub = X->size[0];
  for (idx = 0; idx < loop_ub; idx++) {
    I->data[idx] = 0.0;
  }

  p = X->size[1];
  k = 0;
  emxInit_real_T(&varargin_1, 2);
  emxInit_real_T(&b_R, 2);
  while (k <= X->size[0] - 1) {
    j = 0U;
    while (I->data[k] == 0.0) {
      j++;
      loop_ub = X->size[1];
      b_loop_ub = R->size[1];
      idx = b_R->size[0] * b_R->size[1];
      b_R->size[0] = 1;
      b_R->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T(b_R, idx);
      for (idx = 0; idx < b_loop_ub; idx++) {
        b_R->data[b_R->size[0] * idx] = R->data[((int)j + R->size[0] * idx) - 1];
      }

      idx = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = 1;
      varargin_1->size[1] = loop_ub;
      emxEnsureCapacity_real_T(varargin_1, idx);
      for (idx = 0; idx < loop_ub; idx++) {
        varargin_1->data[varargin_1->size[0] * idx] = X->data[k + X->size[0] *
          idx] - b_R->data[idx];
      }

      if (varargin_1->size[1] <= 2) {
        if (varargin_1->size[1] == 1) {
          ex = varargin_1->data[0];
        } else if ((varargin_1->data[0] > varargin_1->data[1]) || (rtIsNaN
                    (varargin_1->data[0]) && (!rtIsNaN(varargin_1->data[1])))) {
          ex = varargin_1->data[1];
        } else {
          ex = varargin_1->data[0];
        }
      } else {
        if (!rtIsNaN(varargin_1->data[0])) {
          idx = 1;
        } else {
          idx = 0;
          loop_ub = 2;
          exitg1 = false;
          while ((!exitg1) && (loop_ub <= varargin_1->size[1])) {
            if (!rtIsNaN(varargin_1->data[loop_ub - 1])) {
              idx = loop_ub;
              exitg1 = true;
            } else {
              loop_ub++;
            }
          }
        }

        if (idx == 0) {
          ex = varargin_1->data[0];
        } else {
          ex = varargin_1->data[idx - 1];
          while (idx + 1 <= varargin_1->size[1]) {
            if (ex > varargin_1->data[idx]) {
              ex = varargin_1->data[idx];
            }

            idx++;
          }
        }
      }

      if (ex >= 0.0) {
        loop_ub = R->size[1];
        idx = b_R->size[0] * b_R->size[1];
        b_R->size[0] = 1;
        b_R->size[1] = loop_ub;
        emxEnsureCapacity_real_T(b_R, idx);
        for (idx = 0; idx < loop_ub; idx++) {
          b_R->data[b_R->size[0] * idx] = R->data[(((int)j + R->size[0] * idx) +
            R->size[0] * R->size[1]) - 1];
        }

        idx = varargin_1->size[0] * varargin_1->size[1];
        varargin_1->size[0] = 1;
        varargin_1->size[1] = p;
        emxEnsureCapacity_real_T(varargin_1, idx);
        for (idx = 0; idx < p; idx++) {
          varargin_1->data[varargin_1->size[0] * idx] = b_R->data[idx] - X->
            data[k + X->size[0] * idx];
        }

        if (varargin_1->size[1] <= 2) {
          if (varargin_1->size[1] == 1) {
            ex = varargin_1->data[0];
          } else if ((varargin_1->data[0] > varargin_1->data[1]) || (rtIsNaN
                      (varargin_1->data[0]) && (!rtIsNaN(varargin_1->data[1]))))
          {
            ex = varargin_1->data[1];
          } else {
            ex = varargin_1->data[0];
          }
        } else {
          if (!rtIsNaN(varargin_1->data[0])) {
            idx = 1;
          } else {
            idx = 0;
            loop_ub = 2;
            exitg1 = false;
            while ((!exitg1) && (loop_ub <= varargin_1->size[1])) {
              if (!rtIsNaN(varargin_1->data[loop_ub - 1])) {
                idx = loop_ub;
                exitg1 = true;
              } else {
                loop_ub++;
              }
            }
          }

          if (idx == 0) {
            ex = varargin_1->data[0];
          } else {
            ex = varargin_1->data[idx - 1];
            while (idx + 1 <= varargin_1->size[1]) {
              if (ex > varargin_1->data[idx]) {
                ex = varargin_1->data[idx];
              }

              idx++;
            }
          }
        }

        if (ex >= 0.0) {
          I->data[k] = j;
        }
      }
    }

    k++;
  }

  emxFree_real_T(&b_R);
  emxFree_real_T(&varargin_1);
}

/*
 * File trailer for Find_Rectangle.c
 *
 * [EOF]
 */
