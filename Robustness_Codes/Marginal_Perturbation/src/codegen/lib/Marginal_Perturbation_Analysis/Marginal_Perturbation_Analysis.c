/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Marginal_Perturbation_Analysis.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"
#include "Sobol_Frechet_Derivatives.h"
#include "Perturbed_Sobol_Indices.h"
#include "Sample_std_Estimate_Weights.h"
#include "unaryMinOrMax.h"
#include "Unique_Mats.h"
#include "Psi_Data_Generation.h"
#include "Marginal_Perturbation_Analysis_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const struct0_T *Sobol_Output
 *                const struct1_T *Phi_Data
 *                double r
 *                double m
 *                const emxArray_real_T *R
 *                const emxArray_real_T *sd_S_nom
 *                const emxArray_real_T *sd_T_nom
 *                struct2_T *Perturbation_Output
 * Return Type  : void
 */
void Marginal_Perturbation_Analysis(const struct0_T *Sobol_Output, const
  struct1_T *Phi_Data, double r, double m, const emxArray_real_T *R, const
  emxArray_real_T *sd_S_nom, const emxArray_real_T *sd_T_nom, struct2_T
  *Perturbation_Output)
{
  emxArray_real_T *psi_val;
  emxArray_real_T *a;
  int p;
  int i0;
  int loop_ub;
  emxArray_real_T *delta_weights;
  int k;
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  emxArray_int32_T *r3;
  emxArray_real_T *b_a;
  emxArray_real_T *perturbation_marker;
  emxArray_real_T *c_a;
  emxArray_real_T *b_delta_weights;
  int b_loop_ub;
  int idx;
  int i1;
  emxArray_real_T *maxval;
  double delta1;
  boolean_T exitg1;
  double max_weight_rec;
  double d;
  emxArray_real_T *delta;
  double delta2;
  emxArray_real_T *y;
  double cdiff;
  double absa;
  emxArray_int32_T *b_maxval;
  double absb;
  emxArray_real_T *b_delta;
  emxArray_real_T *S_pert;
  emxArray_real_T *S_sd_pert;
  emxArray_real_T *T_pert;
  emxArray_real_T *T_sd_pert;
  emxArray_real_T *Acc_Rej_Bound;
  emxArray_real_T *delta_val;
  emxArray_real_T *r4;
  emxArray_real_T *r5;
  emxInit_real_T(&psi_val, 2);
  emxInit_real_T1(&a, 3);
  p = Sobol_Output->YC->size[1];
  Psi_Data_Generation(Sobol_Output->A, Sobol_Output->B, Phi_Data->phi_A,
                      Phi_Data->phi_B, R, psi_val);
  i0 = a->size[0] * a->size[1] * a->size[2];
  a->size[0] = R->size[0] - 1;
  a->size[1] = Sobol_Output->YC->size[1];
  a->size[2] = (int)(2.0 * (double)Sobol_Output->YC->size[1]);
  emxEnsureCapacity_real_T(a, i0);
  loop_ub = (R->size[0] - 1) * Sobol_Output->YC->size[1] * (int)(2.0 * (double)
    Sobol_Output->YC->size[1]);
  for (i0 = 0; i0 < loop_ub; i0++) {
    a->data[i0] = 0.0;
  }

  emxInit_real_T(&delta_weights, 2);
  i0 = delta_weights->size[0] * delta_weights->size[1];
  delta_weights->size[0] = (int)(2.0 * (double)Sobol_Output->YC->size[1]);
  delta_weights->size[1] = Sobol_Output->YC->size[1];
  emxEnsureCapacity_real_T1(delta_weights, i0);
  loop_ub = (int)(2.0 * (double)Sobol_Output->YC->size[1]) * Sobol_Output->
    YC->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    delta_weights->data[i0] = 0.0;
  }

  k = 0;
  emxInit_real_T(&r0, 2);
  emxInit_real_T2(&r1, 1);
  emxInit_real_T2(&r2, 1);
  emxInit_int32_T(&r3, 1);
  emxInit_real_T(&b_a, 2);
  while (k <= p - 1) {
    Sobol_Frechet_Derivatives(Sobol_Output->S, Sobol_Output->T, Sobol_Output->A,
      Sobol_Output->B, Sobol_Output->YA, Sobol_Output->YB, Sobol_Output->YC,
      Sobol_Output->Var_Y, Sobol_Output->muYA, Sobol_Output->muYB,
      Phi_Data->phi_A, Phi_Data->phi_B, psi_val, R, 1.0 + (double)k, b_a, r0, r1,
      r2);
    loop_ub = b_a->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_loop_ub = b_a->size[0];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        a->data[(i1 + a->size[0] * i0) + a->size[0] * a->size[1] * k] =
          b_a->data[i1 + b_a->size[0] * i0];
      }
    }

    i0 = (int)((unsigned int)k + p);
    loop_ub = r0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = r0->size[0];
      for (idx = 0; idx < b_loop_ub; idx++) {
        a->data[(idx + a->size[0] * i1) + a->size[0] * a->size[1] * i0] =
          r0->data[idx + r0->size[0] * i1];
      }
    }

    loop_ub = delta_weights->size[1];
    i0 = r3->size[0];
    r3->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r3, i0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r3->data[i0] = i0;
    }

    idx = r3->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      delta_weights->data[k + delta_weights->size[0] * r3->data[i0]] = r1->
        data[i0];
    }

    i0 = (int)((unsigned int)k + p);
    loop_ub = delta_weights->size[1];
    i1 = r3->size[0];
    r3->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r3, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r3->data[i1] = i1;
    }

    idx = r3->size[0];
    for (i1 = 0; i1 < idx; i1++) {
      delta_weights->data[i0 + delta_weights->size[0] * r3->data[i1]] = r2->
        data[i1];
    }

    k++;
  }

  emxFree_real_T(&r0);
  emxInit_real_T2(&perturbation_marker, 1);
  emxInit_real_T1(&c_a, 3);
  emxInit_real_T(&b_delta_weights, 2);
  Unique_Mats(a, c_a, perturbation_marker);
  idx = delta_weights->size[1];
  i0 = b_delta_weights->size[0] * b_delta_weights->size[1];
  b_delta_weights->size[0] = perturbation_marker->size[0];
  b_delta_weights->size[1] = idx;
  emxEnsureCapacity_real_T1(b_delta_weights, i0);
  emxFree_real_T(&a);
  for (i0 = 0; i0 < idx; i0++) {
    loop_ub = perturbation_marker->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_delta_weights->data[i1 + b_delta_weights->size[0] * i0] =
        delta_weights->data[((int)perturbation_marker->data[i1] +
        delta_weights->size[0] * i0) - 1];
    }
  }

  i0 = delta_weights->size[0] * delta_weights->size[1];
  delta_weights->size[0] = b_delta_weights->size[0];
  delta_weights->size[1] = b_delta_weights->size[1];
  emxEnsureCapacity_real_T1(delta_weights, i0);
  loop_ub = b_delta_weights->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_loop_ub = b_delta_weights->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      delta_weights->data[i1 + delta_weights->size[0] * i0] =
        b_delta_weights->data[i1 + b_delta_weights->size[0] * i0];
    }
  }

  emxFree_real_T(&b_delta_weights);
  emxInit_real_T(&maxval, 2);
  minOrMax2DColumnMajorDim1(delta_weights, maxval);
  if (maxval->size[1] <= 2) {
    if (maxval->size[1] == 1) {
      delta1 = maxval->data[0];
    } else if ((maxval->data[0] < maxval->data[1]) || (rtIsNaN(maxval->data[0]) &&
                (!rtIsNaN(maxval->data[1])))) {
      delta1 = maxval->data[1];
    } else {
      delta1 = maxval->data[0];
    }
  } else {
    if (!rtIsNaN(maxval->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= maxval->size[1])) {
        if (!rtIsNaN(maxval->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      delta1 = maxval->data[0];
    } else {
      delta1 = maxval->data[idx - 1];
      while (idx + 1 <= maxval->size[1]) {
        if (delta1 < maxval->data[idx]) {
          delta1 = maxval->data[idx];
        }

        idx++;
      }
    }
  }

  max_weight_rec = 1.0 / delta1;
  d = rt_roundd_snf(r / 2.0);
  delta1 = 2.0 * d + 1.0;
  if (delta1 < 0.0) {
    delta1 = 0.0;
  }

  emxInit_real_T(&delta, 2);
  i0 = delta->size[0] * delta->size[1];
  delta->size[0] = 1;
  delta->size[1] = (int)delta1;
  emxEnsureCapacity_real_T1(delta, i0);
  if (delta->size[1] >= 1) {
    delta->data[delta->size[1] - 1] = max_weight_rec;
    if (delta->size[1] >= 2) {
      delta->data[0] = -max_weight_rec;
      if (delta->size[1] >= 3) {
        if (((-max_weight_rec < 0.0) != (max_weight_rec < 0.0)) && ((fabs
              (-max_weight_rec) > 8.9884656743115785E+307) || (fabs
              (max_weight_rec) > 8.9884656743115785E+307))) {
          delta1 = -max_weight_rec / ((double)delta->size[1] - 1.0);
          delta2 = max_weight_rec / ((double)delta->size[1] - 1.0);
          i0 = delta->size[1];
          for (k = 0; k <= i0 - 3; k++) {
            delta->data[k + 1] = (-max_weight_rec + delta2 * (1.0 + (double)k))
              - delta1 * (1.0 + (double)k);
          }
        } else {
          delta1 = (max_weight_rec - (-max_weight_rec)) / ((double)delta->size[1]
            - 1.0);
          i0 = delta->size[1];
          for (k = 0; k <= i0 - 3; k++) {
            delta->data[k + 1] = -max_weight_rec + (1.0 + (double)k) * delta1;
          }
        }
      }
    }
  }

  if (rtIsNaN(d)) {
    i0 = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = 1;
    emxEnsureCapacity_real_T1(maxval, i0);
    maxval->data[0] = rtNaN;
  } else if (d < 2.0) {
    i0 = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = 0;
    emxEnsureCapacity_real_T1(maxval, i0);
  } else if (rtIsInf(d) && (2.0 == d)) {
    i0 = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = 1;
    emxEnsureCapacity_real_T1(maxval, i0);
    maxval->data[0] = rtNaN;
  } else {
    i0 = maxval->size[0] * maxval->size[1];
    maxval->size[0] = 1;
    maxval->size[1] = (int)(d - 2.0) + 1;
    emxEnsureCapacity_real_T1(maxval, i0);
    loop_ub = (int)(d - 2.0);
    for (i0 = 0; i0 <= loop_ub; i0++) {
      maxval->data[maxval->size[0] * i0] = 2.0 + (double)i0;
    }
  }

  emxInit_real_T(&y, 2);
  delta1 = 2.0 * d;
  if (rtIsNaN(d + 2.0) || rtIsNaN(delta1)) {
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T1(y, i0);
    y->data[0] = rtNaN;
  } else if (delta1 < d + 2.0) {
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity_real_T1(y, i0);
  } else if ((rtIsInf(d + 2.0) || rtIsInf(delta1)) && (d + 2.0 == delta1)) {
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T1(y, i0);
    y->data[0] = rtNaN;
  } else if (d + 2.0 == d + 2.0) {
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)(delta1 - (d + 2.0)) + 1;
    emxEnsureCapacity_real_T1(y, i0);
    loop_ub = (int)(delta1 - (d + 2.0));
    for (i0 = 0; i0 <= loop_ub; i0++) {
      y->data[y->size[0] * i0] = (d + 2.0) + (double)i0;
    }
  } else {
    delta2 = floor((delta1 - (d + 2.0)) + 0.5);
    max_weight_rec = (d + 2.0) + delta2;
    cdiff = max_weight_rec - delta1;
    absa = fabs(d + 2.0);
    absb = fabs(delta1);
    if ((absa > absb) || rtIsNaN(absb)) {
      absb = absa;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
      delta2++;
      max_weight_rec = delta1;
    } else if (cdiff > 0.0) {
      max_weight_rec = (d + 2.0) + (delta2 - 1.0);
    } else {
      delta2++;
    }

    if (delta2 >= 0.0) {
      p = (int)delta2;
    } else {
      p = 0;
    }

    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = p;
    emxEnsureCapacity_real_T1(y, i0);
    if (p > 0) {
      y->data[0] = d + 2.0;
      if (p > 1) {
        y->data[p - 1] = max_weight_rec;
        idx = (p - 1) / 2;
        for (k = 1; k < idx; k++) {
          y->data[k] = (d + 2.0) + (double)k;
          y->data[(p - k) - 1] = max_weight_rec - (double)k;
        }

        if (idx << 1 == p - 1) {
          y->data[idx] = ((d + 2.0) + max_weight_rec) / 2.0;
        } else {
          y->data[idx] = (d + 2.0) + (double)idx;
          y->data[idx + 1] = max_weight_rec - (double)idx;
        }
      }
    }
  }

  emxInit_int32_T1(&b_maxval, 2);
  i0 = b_maxval->size[0] * b_maxval->size[1];
  b_maxval->size[0] = 1;
  b_maxval->size[1] = maxval->size[1] + y->size[1];
  emxEnsureCapacity_int32_T1(b_maxval, i0);
  loop_ub = maxval->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_maxval->data[b_maxval->size[0] * i0] = (int)maxval->data[maxval->size[0] *
      i0] - 1;
  }

  loop_ub = y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_maxval->data[b_maxval->size[0] * (i0 + maxval->size[1])] = (int)y->data
      [y->size[0] * i0] - 1;
  }

  emxInit_real_T(&b_delta, 2);
  i0 = b_delta->size[0] * b_delta->size[1];
  b_delta->size[0] = 1;
  b_delta->size[1] = maxval->size[1] + y->size[1];
  emxEnsureCapacity_real_T1(b_delta, i0);
  loop_ub = maxval->size[1] + y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_delta->data[b_delta->size[0] * i0] = delta->data[b_maxval->data
      [b_maxval->size[0] * i0]];
  }

  emxFree_int32_T(&b_maxval);
  i0 = delta->size[0] * delta->size[1];
  delta->size[0] = 1;
  delta->size[1] = b_delta->size[1];
  emxEnsureCapacity_real_T1(delta, i0);
  loop_ub = b_delta->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    delta->data[delta->size[0] * i0] = b_delta->data[b_delta->size[0] * i0];
  }

  emxFree_real_T(&b_delta);
  emxInit_real_T(&S_pert, 2);

  /*  Preallocate array */
  i0 = S_pert->size[0] * S_pert->size[1];
  S_pert->size[0] = (int)((double)c_a->size[2] * (double)delta->size[1]);
  S_pert->size[1] = Sobol_Output->YC->size[1];
  emxEnsureCapacity_real_T1(S_pert, i0);
  loop_ub = (int)((double)c_a->size[2] * (double)delta->size[1]) *
    Sobol_Output->YC->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    S_pert->data[i0] = 0.0;
  }

  emxInit_real_T(&S_sd_pert, 2);
  i0 = S_sd_pert->size[0] * S_sd_pert->size[1];
  S_sd_pert->size[0] = (int)((double)c_a->size[2] * (double)delta->size[1]);
  S_sd_pert->size[1] = Sobol_Output->YC->size[1];
  emxEnsureCapacity_real_T1(S_sd_pert, i0);
  loop_ub = (int)((double)c_a->size[2] * (double)delta->size[1]) *
    Sobol_Output->YC->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    S_sd_pert->data[i0] = 0.0;
  }

  emxInit_real_T(&T_pert, 2);
  i0 = T_pert->size[0] * T_pert->size[1];
  T_pert->size[0] = (int)((double)c_a->size[2] * (double)delta->size[1]);
  T_pert->size[1] = Sobol_Output->YC->size[1];
  emxEnsureCapacity_real_T1(T_pert, i0);
  loop_ub = (int)((double)c_a->size[2] * (double)delta->size[1]) *
    Sobol_Output->YC->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    T_pert->data[i0] = 0.0;
  }

  emxInit_real_T(&T_sd_pert, 2);
  i0 = T_sd_pert->size[0] * T_sd_pert->size[1];
  T_sd_pert->size[0] = (int)((double)c_a->size[2] * (double)delta->size[1]);
  T_sd_pert->size[1] = Sobol_Output->YC->size[1];
  emxEnsureCapacity_real_T1(T_sd_pert, i0);
  loop_ub = (int)((double)c_a->size[2] * (double)delta->size[1]) *
    Sobol_Output->YC->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    T_sd_pert->data[i0] = 0.0;
  }

  emxInit_real_T(&Acc_Rej_Bound, 2);
  i0 = Acc_Rej_Bound->size[0] * Acc_Rej_Bound->size[1];
  Acc_Rej_Bound->size[0] = (int)((double)c_a->size[2] * (double)delta->size[1]);
  Acc_Rej_Bound->size[1] = Sobol_Output->YC->size[1];
  emxEnsureCapacity_real_T1(Acc_Rej_Bound, i0);
  loop_ub = (int)((double)c_a->size[2] * (double)delta->size[1]) *
    Sobol_Output->YC->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Acc_Rej_Bound->data[i0] = 0.0;
  }

  emxInit_real_T(&delta_val, 2);
  delta1 = (double)c_a->size[2] * (double)delta->size[1];
  i0 = delta_val->size[0] * delta_val->size[1];
  delta_val->size[0] = (int)delta1;
  delta_val->size[1] = (int)delta1;
  emxEnsureCapacity_real_T1(delta_val, i0);
  loop_ub = (int)delta1 * (int)delta1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    delta_val->data[i0] = 0.0;
  }

  i0 = perturbation_marker->size[0];
  perturbation_marker->size[0] = (int)((double)c_a->size[2] * (double)
    delta->size[1]);
  emxEnsureCapacity_real_T2(perturbation_marker, i0);
  loop_ub = (int)((double)c_a->size[2] * (double)delta->size[1]);
  for (i0 = 0; i0 < loop_ub; i0++) {
    perturbation_marker->data[i0] = 0.0;
  }

  /*  Compute indices via importance sampling */
  k = 0;
  emxInit_real_T2(&r4, 1);
  emxInit_real_T2(&r5, 1);
  while (k <= c_a->size[2] - 1) {
    for (p = 0; p < delta->size[1]; p++) {
      delta1 = ((1.0 + (double)k) - 1.0) * (double)delta->size[1] + (1.0 +
        (double)p);
      delta_val->data[(int)delta1 - 1] = delta->data[p];
      perturbation_marker->data[(int)delta1 - 1] = 1.0 + (double)k;
      loop_ub = c_a->size[0];
      b_loop_ub = c_a->size[1];
      i0 = b_a->size[0] * b_a->size[1];
      b_a->size[0] = loop_ub;
      b_a->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T1(b_a, i0);
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_a->data[i1 + b_a->size[0] * i0] = c_a->data[(i1 + c_a->size[0] * i0)
            + c_a->size[0] * c_a->size[1] * k];
        }
      }

      loop_ub = delta_weights->size[1];
      i0 = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = loop_ub;
      emxEnsureCapacity_real_T1(y, i0);
      for (i0 = 0; i0 < loop_ub; i0++) {
        y->data[y->size[0] * i0] = delta_weights->data[k + delta_weights->size[0]
          * i0];
      }

      Perturbed_Sobol_Indices(b_a, y, Sobol_Output->A, Sobol_Output->B,
        Sobol_Output->YA, Sobol_Output->YB, Sobol_Output->YC, Phi_Data->phi_A,
        Phi_Data->phi_B, psi_val, R, delta->data[p], sd_S_nom, sd_T_nom, m, r1,
        r2, r4, r5, maxval);
      loop_ub = S_pert->size[1];
      i0 = r3->size[0];
      r3->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r3, i0);
      for (i0 = 0; i0 < loop_ub; i0++) {
        r3->data[i0] = i0;
      }

      idx = r3->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        S_pert->data[((int)delta1 + S_pert->size[0] * r3->data[i0]) - 1] =
          r1->data[i0];
      }

      loop_ub = S_sd_pert->size[1];
      i0 = r3->size[0];
      r3->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r3, i0);
      for (i0 = 0; i0 < loop_ub; i0++) {
        r3->data[i0] = i0;
      }

      idx = r3->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        S_sd_pert->data[((int)delta1 + S_sd_pert->size[0] * r3->data[i0]) - 1] =
          r2->data[i0];
      }

      loop_ub = T_pert->size[1];
      i0 = r3->size[0];
      r3->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r3, i0);
      for (i0 = 0; i0 < loop_ub; i0++) {
        r3->data[i0] = i0;
      }

      idx = r3->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        T_pert->data[((int)delta1 + T_pert->size[0] * r3->data[i0]) - 1] =
          r4->data[i0];
      }

      loop_ub = T_sd_pert->size[1];
      i0 = r3->size[0];
      r3->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r3, i0);
      for (i0 = 0; i0 < loop_ub; i0++) {
        r3->data[i0] = i0;
      }

      idx = r3->size[0];
      for (i0 = 0; i0 < idx; i0++) {
        T_sd_pert->data[((int)delta1 + T_sd_pert->size[0] * r3->data[i0]) - 1] =
          r5->data[i0];
      }

      loop_ub = maxval->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        Acc_Rej_Bound->data[((int)delta1 + Acc_Rej_Bound->size[0] * i0) - 1] =
          maxval->data[maxval->size[0] * i0];
      }
    }

    k++;
  }

  emxFree_real_T(&b_a);
  emxFree_real_T(&y);
  emxFree_real_T(&maxval);
  emxFree_int32_T(&r3);
  emxFree_real_T(&r5);
  emxFree_real_T(&r4);
  emxFree_real_T(&r2);
  emxFree_real_T(&r1);
  emxFree_real_T(&delta);
  i0 = Perturbation_Output->delta_val->size[0] * Perturbation_Output->
    delta_val->size[1];
  Perturbation_Output->delta_val->size[0] = delta_val->size[0];
  Perturbation_Output->delta_val->size[1] = delta_val->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->delta_val, i0);
  loop_ub = delta_val->size[0] * delta_val->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->delta_val->data[i0] = delta_val->data[i0];
  }

  emxFree_real_T(&delta_val);
  i0 = Perturbation_Output->S_sd_pert->size[0] * Perturbation_Output->
    S_sd_pert->size[1];
  Perturbation_Output->S_sd_pert->size[0] = S_sd_pert->size[0];
  Perturbation_Output->S_sd_pert->size[1] = S_sd_pert->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->S_sd_pert, i0);
  loop_ub = S_sd_pert->size[0] * S_sd_pert->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->S_sd_pert->data[i0] = S_sd_pert->data[i0];
  }

  emxFree_real_T(&S_sd_pert);
  i0 = Perturbation_Output->S_pert->size[0] * Perturbation_Output->S_pert->size
    [1];
  Perturbation_Output->S_pert->size[0] = S_pert->size[0];
  Perturbation_Output->S_pert->size[1] = S_pert->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->S_pert, i0);
  loop_ub = S_pert->size[0] * S_pert->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->S_pert->data[i0] = S_pert->data[i0];
  }

  emxFree_real_T(&S_pert);
  i0 = Perturbation_Output->T_sd_pert->size[0] * Perturbation_Output->
    T_sd_pert->size[1];
  Perturbation_Output->T_sd_pert->size[0] = T_sd_pert->size[0];
  Perturbation_Output->T_sd_pert->size[1] = T_sd_pert->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->T_sd_pert, i0);
  loop_ub = T_sd_pert->size[0] * T_sd_pert->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->T_sd_pert->data[i0] = T_sd_pert->data[i0];
  }

  emxFree_real_T(&T_sd_pert);
  i0 = Perturbation_Output->T_pert->size[0] * Perturbation_Output->T_pert->size
    [1];
  Perturbation_Output->T_pert->size[0] = T_pert->size[0];
  Perturbation_Output->T_pert->size[1] = T_pert->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->T_pert, i0);
  loop_ub = T_pert->size[0] * T_pert->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->T_pert->data[i0] = T_pert->data[i0];
  }

  emxFree_real_T(&T_pert);
  i0 = Perturbation_Output->Acc_Rej_Bound->size[0] *
    Perturbation_Output->Acc_Rej_Bound->size[1];
  Perturbation_Output->Acc_Rej_Bound->size[0] = Acc_Rej_Bound->size[0];
  Perturbation_Output->Acc_Rej_Bound->size[1] = Acc_Rej_Bound->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->Acc_Rej_Bound, i0);
  loop_ub = Acc_Rej_Bound->size[0] * Acc_Rej_Bound->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->Acc_Rej_Bound->data[i0] = Acc_Rej_Bound->data[i0];
  }

  emxFree_real_T(&Acc_Rej_Bound);
  i0 = Perturbation_Output->R->size[0] * Perturbation_Output->R->size[1];
  Perturbation_Output->R->size[0] = R->size[0];
  Perturbation_Output->R->size[1] = R->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->R, i0);
  loop_ub = R->size[0] * R->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->R->data[i0] = R->data[i0];
  }

  i0 = Perturbation_Output->a->size[0] * Perturbation_Output->a->size[1] *
    Perturbation_Output->a->size[2];
  Perturbation_Output->a->size[0] = c_a->size[0];
  Perturbation_Output->a->size[1] = c_a->size[1];
  Perturbation_Output->a->size[2] = c_a->size[2];
  emxEnsureCapacity_real_T(Perturbation_Output->a, i0);
  loop_ub = c_a->size[0] * c_a->size[1] * c_a->size[2];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->a->data[i0] = c_a->data[i0];
  }

  emxFree_real_T(&c_a);
  i0 = Perturbation_Output->delta_weights->size[0] *
    Perturbation_Output->delta_weights->size[1];
  Perturbation_Output->delta_weights->size[0] = delta_weights->size[0];
  Perturbation_Output->delta_weights->size[1] = delta_weights->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->delta_weights, i0);
  loop_ub = delta_weights->size[0] * delta_weights->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->delta_weights->data[i0] = delta_weights->data[i0];
  }

  emxFree_real_T(&delta_weights);
  i0 = Perturbation_Output->psi_val->size[0] * Perturbation_Output->
    psi_val->size[1];
  Perturbation_Output->psi_val->size[0] = psi_val->size[0];
  Perturbation_Output->psi_val->size[1] = psi_val->size[1];
  emxEnsureCapacity_real_T1(Perturbation_Output->psi_val, i0);
  loop_ub = psi_val->size[0] * psi_val->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->psi_val->data[i0] = psi_val->data[i0];
  }

  emxFree_real_T(&psi_val);
  i0 = Perturbation_Output->perturbation_marker->size[0];
  Perturbation_Output->perturbation_marker->size[0] = perturbation_marker->size
    [0];
  emxEnsureCapacity_real_T2(Perturbation_Output->perturbation_marker, i0);
  loop_ub = perturbation_marker->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Perturbation_Output->perturbation_marker->data[i0] =
      perturbation_marker->data[i0];
  }

  emxFree_real_T(&perturbation_marker);
}

/*
 * File trailer for Marginal_Perturbation_Analysis.c
 *
 * [EOF]
 */
