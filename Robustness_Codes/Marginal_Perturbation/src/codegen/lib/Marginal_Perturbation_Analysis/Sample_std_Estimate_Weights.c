/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Sample_std_Estimate_Weights.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "Sample_std_Estimate_Weights.h"
#include "rand.h"
#include "combineVectorElements.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"
#include "power.h"
#include "prod.h"
#include "sort1.h"
#include "mod.h"
#include "std.h"
#include "Marginal_Perturbation_Analysis_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double m
 *                const emxArray_real_T *YA
 *                const emxArray_real_T *YB
 *                const emxArray_real_T *YCi
 *                const emxArray_real_T *weight_A
 *                const emxArray_real_T *weight_B
 *                double i
 *                double *sd_S
 *                double *sd_T
 * Return Type  : void
 */
void Sample_std_Estimate_Weights(double m, const emxArray_real_T *YA, const
  emxArray_real_T *YB, const emxArray_real_T *YCi, const emxArray_real_T
  *weight_A, const emxArray_real_T *weight_B, double i, double *sd_S, double
  *sd_T)
{
  emxArray_real_T *samps_S;
  emxArray_real_T *samps_T;
  int varargin_1;
  int i8;
  int k;
  emxArray_real_T *I;
  emxArray_real_T *weight_A_tmp;
  emxArray_real_T *weight_B_tmp;
  emxArray_real_T *weight_A_tmp_prod;
  emxArray_real_T *hashTbl;
  emxArray_real_T *link;
  emxArray_real_T *val;
  emxArray_real_T *loc;
  emxArray_real_T *x;
  emxArray_real_T *b_x;
  emxArray_real_T *b_link;
  int c_x;
  int nleftm1;
  double t;
  int b_m;
  double selectedLoc;
  double j;
  double b_i;
  double newEntry;
  emxInit_real_T2(&samps_S, 1);
  emxInit_real_T2(&samps_T, 1);
  varargin_1 = YA->size[0];
  i8 = samps_S->size[0];
  samps_S->size[0] = (int)m;
  emxEnsureCapacity_real_T2(samps_S, i8);
  i8 = samps_T->size[0];
  samps_T->size[0] = (int)m;
  emxEnsureCapacity_real_T2(samps_T, i8);
  k = 0;
  emxInit_real_T(&I, 2);
  emxInit_real_T(&weight_A_tmp, 2);
  emxInit_real_T(&weight_B_tmp, 2);
  emxInit_real_T2(&weight_A_tmp_prod, 1);
  emxInit_real_T2(&hashTbl, 1);
  emxInit_real_T2(&link, 1);
  emxInit_real_T2(&val, 1);
  emxInit_real_T2(&loc, 1);
  emxInit_real_T2(&x, 1);
  emxInit_real_T2(&b_x, 1);
  emxInit_real_T2(&b_link, 1);
  while (k <= (int)m - 1) {
    c_x = (int)rt_roundd_snf(0.5 * (double)varargin_1);
    i8 = I->size[0] * I->size[1];
    I->size[0] = 1;
    I->size[1] = c_x;
    emxEnsureCapacity_real_T1(I, i8);
    for (i8 = 0; i8 < c_x; i8++) {
      I->data[i8] = 0.0;
    }

    if (c_x != 0) {
      if (c_x >= varargin_1) {
        I->data[0] = 1.0;
        for (nleftm1 = 0; nleftm1 <= varargin_1 - 2; nleftm1++) {
          selectedLoc = b_rand() * ((1.0 + (double)nleftm1) + 1.0);
          j = floor(selectedLoc);
          I->data[nleftm1 + 1] = I->data[(int)(j + 1.0) - 1];
          I->data[(int)(j + 1.0) - 1] = (1.0 + (double)nleftm1) + 1.0;
        }
      } else if (c_x >= (double)YA->size[0] / 4.0) {
        t = 0.0;
        for (b_m = 0; b_m < c_x; b_m++) {
          nleftm1 = c_x - b_m;
          selectedLoc = (double)varargin_1 - t;
          b_i = (double)nleftm1 / selectedLoc;
          newEntry = b_rand();
          while (newEntry > b_i) {
            t++;
            selectedLoc--;
            b_i += (1.0 - b_i) * ((double)nleftm1 / selectedLoc);
          }

          t++;
          selectedLoc = b_rand() * ((double)b_m + 1.0);
          j = floor(selectedLoc);
          I->data[b_m] = I->data[(int)(j + 1.0) - 1];
          I->data[(int)(j + 1.0) - 1] = t;
        }
      } else {
        i8 = hashTbl->size[0];
        hashTbl->size[0] = c_x;
        emxEnsureCapacity_real_T2(hashTbl, i8);
        for (i8 = 0; i8 < c_x; i8++) {
          hashTbl->data[i8] = 0.0;
        }

        i8 = link->size[0];
        link->size[0] = c_x;
        emxEnsureCapacity_real_T2(link, i8);
        for (i8 = 0; i8 < c_x; i8++) {
          link->data[i8] = 0.0;
        }

        i8 = val->size[0];
        val->size[0] = c_x;
        emxEnsureCapacity_real_T2(val, i8);
        for (i8 = 0; i8 < c_x; i8++) {
          val->data[i8] = 0.0;
        }

        i8 = loc->size[0];
        loc->size[0] = c_x;
        emxEnsureCapacity_real_T2(loc, i8);
        for (i8 = 0; i8 < c_x; i8++) {
          loc->data[i8] = 0.0;
        }

        newEntry = 1.0;
        for (b_m = 0; b_m < c_x; b_m++) {
          nleftm1 = (varargin_1 - b_m) - 1;
          selectedLoc = b_rand() * ((double)nleftm1 + 1.0);
          selectedLoc = floor(selectedLoc);
          b_i = 1.0 + b_mod(selectedLoc, c_x);
          j = hashTbl->data[(int)b_i - 1];
          while ((j > 0.0) && (loc->data[(int)j - 1] != selectedLoc)) {
            j = link->data[(int)j - 1];
          }

          if (j > 0.0) {
            I->data[b_m] = val->data[(int)j - 1] + 1.0;
          } else {
            I->data[b_m] = selectedLoc + 1.0;
            j = newEntry;
            newEntry++;
            loc->data[(int)j - 1] = selectedLoc;
            link->data[(int)j - 1] = hashTbl->data[(int)b_i - 1];
            hashTbl->data[(int)b_i - 1] = j;
          }

          if (1 + b_m < c_x) {
            selectedLoc = hashTbl->data[(int)(1.0 + b_mod(nleftm1, c_x)) - 1];
            while ((selectedLoc > 0.0) && (loc->data[(int)selectedLoc - 1] !=
                    nleftm1)) {
              selectedLoc = link->data[(int)selectedLoc - 1];
            }

            if (selectedLoc > 0.0) {
              b_i = val->data[(int)selectedLoc - 1];
            } else {
              b_i = nleftm1;
            }

            val->data[(int)j - 1] = b_i;
          }
        }
      }
    }

    sort(I);
    nleftm1 = weight_A->size[1];
    i8 = weight_A_tmp->size[0] * weight_A_tmp->size[1];
    weight_A_tmp->size[0] = I->size[1];
    weight_A_tmp->size[1] = nleftm1;
    emxEnsureCapacity_real_T1(weight_A_tmp, i8);
    for (i8 = 0; i8 < nleftm1; i8++) {
      b_m = I->size[1];
      for (c_x = 0; c_x < b_m; c_x++) {
        weight_A_tmp->data[c_x + weight_A_tmp->size[0] * i8] = weight_A->data
          [((int)I->data[I->size[0] * c_x] + weight_A->size[0] * i8) - 1];
      }
    }

    nleftm1 = weight_B->size[1];
    i8 = weight_B_tmp->size[0] * weight_B_tmp->size[1];
    weight_B_tmp->size[0] = I->size[1];
    weight_B_tmp->size[1] = nleftm1;
    emxEnsureCapacity_real_T1(weight_B_tmp, i8);
    for (i8 = 0; i8 < nleftm1; i8++) {
      b_m = I->size[1];
      for (c_x = 0; c_x < b_m; c_x++) {
        weight_B_tmp->data[c_x + weight_B_tmp->size[0] * i8] = weight_B->data
          [((int)I->data[I->size[0] * c_x] + weight_B->size[0] * i8) - 1];
      }
    }

    prod(weight_A_tmp, weight_A_tmp_prod);
    prod(weight_B_tmp, hashTbl);
    i8 = link->size[0];
    link->size[0] = I->size[1];
    emxEnsureCapacity_real_T2(link, i8);
    nleftm1 = I->size[1];
    for (i8 = 0; i8 < nleftm1; i8++) {
      link->data[i8] = YA->data[(int)I->data[I->size[0] * i8] - 1];
    }

    i8 = val->size[0];
    val->size[0] = I->size[1];
    emxEnsureCapacity_real_T2(val, i8);
    nleftm1 = I->size[1];
    for (i8 = 0; i8 < nleftm1; i8++) {
      val->data[i8] = YB->data[(int)I->data[I->size[0] * i8] - 1];
    }

    i8 = loc->size[0];
    loc->size[0] = I->size[1];
    emxEnsureCapacity_real_T2(loc, i8);
    nleftm1 = I->size[1];
    for (i8 = 0; i8 < nleftm1; i8++) {
      loc->data[i8] = YCi->data[(int)I->data[I->size[0] * i8] - 1];
    }

    /*  Estimate mean and variance */
    i8 = x->size[0];
    x->size[0] = link->size[0];
    emxEnsureCapacity_real_T2(x, i8);
    nleftm1 = link->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      x->data[i8] = link->data[i8] * weight_A_tmp_prod->data[i8];
    }

    selectedLoc = combineVectorElements(x) / (double)x->size[0];
    i8 = x->size[0];
    x->size[0] = val->size[0];
    emxEnsureCapacity_real_T2(x, i8);
    nleftm1 = val->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      x->data[i8] = val->data[i8] * hashTbl->data[i8];
    }

    b_i = combineVectorElements(x) / (double)x->size[0];
    i8 = b_link->size[0];
    b_link->size[0] = link->size[0];
    emxEnsureCapacity_real_T2(b_link, i8);
    nleftm1 = link->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      b_link->data[i8] = link->data[i8] - selectedLoc;
    }

    power(b_link, x);
    i8 = x->size[0];
    x->size[0] = weight_A_tmp_prod->size[0];
    emxEnsureCapacity_real_T2(x, i8);
    nleftm1 = weight_A_tmp_prod->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      x->data[i8] *= weight_A_tmp_prod->data[i8];
    }

    i8 = b_link->size[0];
    b_link->size[0] = val->size[0];
    emxEnsureCapacity_real_T2(b_link, i8);
    nleftm1 = val->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      b_link->data[i8] = val->data[i8] - b_i;
    }

    power(b_link, b_x);
    i8 = b_x->size[0];
    b_x->size[0] = hashTbl->size[0];
    emxEnsureCapacity_real_T2(b_x, i8);
    nleftm1 = hashTbl->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      b_x->data[i8] *= hashTbl->data[i8];
    }

    selectedLoc = 0.5 * (combineVectorElements(x) / (double)x->size[0] +
                         combineVectorElements(b_x) / (double)b_x->size[0]);
    i8 = val->size[0];
    emxEnsureCapacity_real_T2(val, i8);
    nleftm1 = val->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      val->data[i8] = val->data[i8] * (loc->data[i8] - link->data[i8]) *
        weight_A_tmp_prod->data[i8] * hashTbl->data[i8];
    }

    samps_S->data[k] = combineVectorElements(val) / (double)val->size[0] /
      selectedLoc;
    i8 = b_link->size[0];
    b_link->size[0] = link->size[0];
    emxEnsureCapacity_real_T2(b_link, i8);
    nleftm1 = link->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      b_link->data[i8] = link->data[i8] - loc->data[i8];
    }

    power(b_link, hashTbl);
    i8 = x->size[0];
    x->size[0] = hashTbl->size[0];
    emxEnsureCapacity_real_T2(x, i8);
    nleftm1 = hashTbl->size[0];
    for (i8 = 0; i8 < nleftm1; i8++) {
      x->data[i8] = hashTbl->data[i8] * (weight_A_tmp_prod->data[i8] *
        weight_B_tmp->data[i8 + weight_B_tmp->size[0] * ((int)i - 1)]);
    }

    samps_T->data[k] = 0.5 * (combineVectorElements(x) / (double)x->size[0]) /
      selectedLoc;
    k++;
  }

  emxFree_real_T(&b_link);
  emxFree_real_T(&b_x);
  emxFree_real_T(&x);
  emxFree_real_T(&loc);
  emxFree_real_T(&val);
  emxFree_real_T(&link);
  emxFree_real_T(&hashTbl);
  emxFree_real_T(&weight_A_tmp_prod);
  emxFree_real_T(&weight_B_tmp);
  emxFree_real_T(&weight_A_tmp);
  emxFree_real_T(&I);
  *sd_S = b_std(samps_S) / (combineVectorElements(samps_S) / (double)
    samps_S->size[0]);
  *sd_T = b_std(samps_T) / (combineVectorElements(samps_T) / (double)
    samps_T->size[0]);
  emxFree_real_T(&samps_T);
  emxFree_real_T(&samps_S);
}

/*
 * File trailer for Sample_std_Estimate_Weights.c
 *
 * [EOF]
 */
