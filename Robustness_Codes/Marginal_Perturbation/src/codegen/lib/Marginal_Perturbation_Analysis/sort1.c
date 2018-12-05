/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sort1.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "sort1.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"
#include "sortIdx.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void sort(emxArray_real_T *x)
{
  emxArray_int32_T *idx;
  int i;
  int ib;
  int n;
  int b_n;
  emxArray_int32_T *iwork;
  double x4[4];
  int idx4[4];
  emxArray_real_T *xwork;
  int nNaNs;
  int k;
  int wOffset;
  signed char perm[4];
  int nNonNaN;
  int i3;
  int i4;
  int nBlocks;
  int nPairs;
  int b_iwork[256];
  double b_xwork[256];
  int exitg1;
  emxInit_int32_T1(&idx, 2);
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T1(idx, i);
  ib = x->size[1];
  for (i = 0; i < ib; i++) {
    idx->data[i] = 0;
  }

  if (x->size[1] != 0) {
    n = x->size[1];
    b_n = x->size[1];
    for (i = 0; i < 4; i++) {
      x4[i] = 0.0;
      idx4[i] = 0;
    }

    emxInit_int32_T(&iwork, 1);
    ib = x->size[1];
    i = iwork->size[0];
    iwork->size[0] = ib;
    emxEnsureCapacity_int32_T(iwork, i);
    for (i = 0; i < ib; i++) {
      iwork->data[i] = 0;
    }

    emxInit_real_T2(&xwork, 1);
    ib = x->size[1];
    i = xwork->size[0];
    xwork->size[0] = ib;
    emxEnsureCapacity_real_T2(xwork, i);
    for (i = 0; i < ib; i++) {
      xwork->data[i] = 0.0;
    }

    nNaNs = 1;
    ib = 0;
    for (k = 0; k < b_n; k++) {
      if (rtIsNaN(x->data[k])) {
        idx->data[b_n - nNaNs] = k + 1;
        xwork->data[b_n - nNaNs] = x->data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib - 1] = k + 1;
        x4[ib - 1] = x->data[k];
        if (ib == 4) {
          i = k - nNaNs;
          if (x4[0] <= x4[1]) {
            ib = 1;
            wOffset = 2;
          } else {
            ib = 2;
            wOffset = 1;
          }

          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }

          if (x4[ib - 1] <= x4[i3 - 1]) {
            if (x4[wOffset - 1] <= x4[i3 - 1]) {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)wOffset;
              perm[2] = (signed char)i3;
              perm[3] = (signed char)i4;
            } else if (x4[wOffset - 1] <= x4[i4 - 1]) {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)wOffset;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)wOffset;
            }
          } else if (x4[ib - 1] <= x4[i4 - 1]) {
            if (x4[wOffset - 1] <= x4[i4 - 1]) {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)wOffset;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)wOffset;
            }
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i4;
            perm[2] = (signed char)ib;
            perm[3] = (signed char)wOffset;
          }

          idx->data[i - 2] = idx4[perm[0] - 1];
          idx->data[i - 1] = idx4[perm[1] - 1];
          idx->data[i] = idx4[perm[2] - 1];
          idx->data[i + 1] = idx4[perm[3] - 1];
          x->data[i - 2] = x4[perm[0] - 1];
          x->data[i - 1] = x4[perm[1] - 1];
          x->data[i] = x4[perm[2] - 1];
          x->data[i + 1] = x4[perm[3] - 1];
          ib = 0;
        }
      }
    }

    wOffset = b_n - nNaNs;
    if (ib > 0) {
      for (i = 0; i < 4; i++) {
        perm[i] = 0;
      }

      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }

      for (k = 1; k <= ib; k++) {
        idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
        x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
      }
    }

    i = ((nNaNs - 1) >> 1) + 1;
    for (k = 1; k < i; k++) {
      ib = idx->data[wOffset + k];
      idx->data[wOffset + k] = idx->data[b_n - k];
      idx->data[b_n - k] = ib;
      x->data[wOffset + k] = xwork->data[b_n - k];
      x->data[b_n - k] = xwork->data[wOffset + k];
    }

    if (((nNaNs - 1) & 1) != 0) {
      x->data[wOffset + i] = xwork->data[wOffset + i];
    }

    nNonNaN = (n - nNaNs) + 1;
    ib = 2;
    if (nNonNaN > 1) {
      if (n >= 256) {
        nBlocks = nNonNaN >> 8;
        if (nBlocks > 0) {
          for (i3 = 1; i3 <= nBlocks; i3++) {
            i4 = ((i3 - 1) << 8) - 1;
            for (nNaNs = 0; nNaNs < 6; nNaNs++) {
              b_n = 1 << (nNaNs + 2);
              n = b_n << 1;
              nPairs = 256 >> (nNaNs + 3);
              for (k = 1; k <= nPairs; k++) {
                ib = i4 + (k - 1) * n;
                for (i = 1; i <= n; i++) {
                  b_iwork[i - 1] = idx->data[ib + i];
                  b_xwork[i - 1] = x->data[ib + i];
                }

                wOffset = 0;
                i = b_n;
                do {
                  exitg1 = 0;
                  ib++;
                  if (b_xwork[wOffset] <= b_xwork[i]) {
                    idx->data[ib] = b_iwork[wOffset];
                    x->data[ib] = b_xwork[wOffset];
                    if (wOffset + 1 < b_n) {
                      wOffset++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx->data[ib] = b_iwork[i];
                    x->data[ib] = b_xwork[i];
                    if (i + 1 < n) {
                      i++;
                    } else {
                      i = ib - wOffset;
                      while (wOffset + 1 <= b_n) {
                        idx->data[(i + wOffset) + 1] = b_iwork[wOffset];
                        x->data[(i + wOffset) + 1] = b_xwork[wOffset];
                        wOffset++;
                      }

                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }

          ib = nBlocks << 8;
          i = nNonNaN - ib;
          if (i > 0) {
            merge_block(idx, x, ib, i, 2, iwork, xwork);
          }

          ib = 8;
        }
      }

      merge_block(idx, x, 0, nNonNaN, ib, iwork, xwork);
    }

    emxFree_real_T(&xwork);
    emxFree_int32_T(&iwork);
  }

  emxFree_int32_T(&idx);
}

/*
 * File trailer for sort1.c
 *
 * [EOF]
 */
