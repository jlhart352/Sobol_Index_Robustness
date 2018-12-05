/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Joint_Perturbation_Analysis.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "Joint_Perturbation_Analysis_emxutil.h"
#include "Perturbed_Sobol_Indices.h"
#include "Perturbed_Sobol_Indices_Preprocess.h"
#include "sortLE.h"
#include "linspace.h"
#include "Sample_std_Estimate_Weights.h"
#include "Sobol_Frechet_Derivatives.h"
#include "Joint_Perturbation_Analysis_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const struct0_T *Sobol_Output
 *                const struct1_T *Phi_Data
 *                const emxArray_real_T *sd_nom
 *                const emxArray_real_T *R
 *                double r
 *                double tau
 *                double m
 *                emxArray_real_T *T_pert
 * Return Type  : void
 */
void Joint_Perturbation_Analysis(const struct0_T *Sobol_Output, const struct1_T *
  Phi_Data, const emxArray_real_T *sd_nom, const emxArray_real_T *R, double r,
  double tau, double m, emxArray_real_T *T_pert)
{
  emxArray_real_T *h;
  emxArray_real_T *C;
  emxArray_real_T *a_normalized;
  emxArray_real_T *Psi_Data_psi_A_val;
  emxArray_real_T *Psi_Data_psi_C_val;
  emxArray_real_T *Psi_Data_psi_val;
  emxArray_real_T *y;
  double d;
  int qEnd;
  int pEnd;
  emxArray_real_T *b_y;
  double b_d;
  double ndbl;
  double apnd;
  double cdiff;
  double absa;
  emxArray_int32_T *c_y;
  double absb;
  int n;
  emxArray_real_T *b_h;
  int nm1d2;
  int k;
  boolean_T empty_non_axis_sizes;
  int p;
  emxArray_real_T *A;
  int q;
  emxArray_int32_T *idx;
  emxArray_real_T *ycol;
  emxArray_real_T *T_a;
  emxArray_real_T *sd_a;
  emxArray_int32_T *iwork;
  unsigned int count;
  int i;
  int j;
  emxArray_real_T *Perturbed_PDF_Data_psi_A;
  emxArray_real_T *r0;
  int exitg1;
  int kEnd;
  boolean_T exitg2;
  unsigned int sz[3];
  int exponent;
  emxArray_boolean_T *x;
  unsigned int b_sz[2];
  emxInit_real_T(&h, 2);
  emxInit_real_T(&C, 2);
  emxInit_real_T(&a_normalized, 2);
  emxInit_real_T2(&Psi_Data_psi_A_val, 1);
  emxInit_real_T(&Psi_Data_psi_C_val, 2);
  emxInit_real_T2(&Psi_Data_psi_val, 1);
  emxInit_real_T(&y, 2);

  /*  Compute paritition and Frechet derivatives */
  Sobol_Frechet_Derivatives(Sobol_Output->T, Sobol_Output->A, Sobol_Output->C,
    Sobol_Output->YA, Sobol_Output->YC, Sobol_Output->Var_Y, Sobol_Output->muYA,
    Phi_Data->phi_A, Phi_Data->phi_A_marg_not_k, Phi_Data->phi_C, R, C,
    a_normalized, Psi_Data_psi_A_val, Psi_Data_psi_C_val, Psi_Data_psi_val);
  d = rt_roundd_snf(r / 2.0);
  linspace(2.0 * d + 1.0, h);
  if (rtIsNaN(d)) {
    qEnd = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, qEnd);
    y->data[0] = rtNaN;
  } else if (d < 2.0) {
    qEnd = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity_real_T(y, qEnd);
  } else if (rtIsInf(d) && (2.0 == d)) {
    qEnd = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, qEnd);
    y->data[0] = rtNaN;
  } else {
    qEnd = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)(d - 2.0) + 1;
    emxEnsureCapacity_real_T(y, qEnd);
    pEnd = (int)(d - 2.0);
    for (qEnd = 0; qEnd <= pEnd; qEnd++) {
      y->data[y->size[0] * qEnd] = 2.0 + (double)qEnd;
    }
  }

  emxInit_real_T(&b_y, 2);
  b_d = 2.0 * d;
  if (rtIsNaN(d + 2.0) || rtIsNaN(b_d)) {
    qEnd = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, qEnd);
    b_y->data[0] = rtNaN;
  } else if (b_d < d + 2.0) {
    qEnd = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 0;
    emxEnsureCapacity_real_T(b_y, qEnd);
  } else if ((rtIsInf(d + 2.0) || rtIsInf(b_d)) && (d + 2.0 == b_d)) {
    qEnd = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, qEnd);
    b_y->data[0] = rtNaN;
  } else if (d + 2.0 == d + 2.0) {
    qEnd = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = (int)(b_d - (d + 2.0)) + 1;
    emxEnsureCapacity_real_T(b_y, qEnd);
    pEnd = (int)(b_d - (d + 2.0));
    for (qEnd = 0; qEnd <= pEnd; qEnd++) {
      b_y->data[b_y->size[0] * qEnd] = (d + 2.0) + (double)qEnd;
    }
  } else {
    ndbl = floor((b_d - (d + 2.0)) + 0.5);
    apnd = (d + 2.0) + ndbl;
    cdiff = apnd - b_d;
    absa = fabs(d + 2.0);
    absb = fabs(b_d);
    if ((absa > absb) || rtIsNaN(absb)) {
      absb = absa;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
      ndbl++;
      apnd = b_d;
    } else if (cdiff > 0.0) {
      apnd = (d + 2.0) + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    qEnd = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = n;
    emxEnsureCapacity_real_T(b_y, qEnd);
    if (n > 0) {
      b_y->data[0] = d + 2.0;
      if (n > 1) {
        b_y->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 1; k < nm1d2; k++) {
          b_y->data[k] = (d + 2.0) + (double)k;
          b_y->data[(n - k) - 1] = apnd - (double)k;
        }

        if (nm1d2 << 1 == n - 1) {
          b_y->data[nm1d2] = ((d + 2.0) + apnd) / 2.0;
        } else {
          b_y->data[nm1d2] = (d + 2.0) + (double)nm1d2;
          b_y->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }
  }

  emxInit_int32_T1(&c_y, 2);
  qEnd = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = y->size[1] + b_y->size[1];
  emxEnsureCapacity_int32_T(c_y, qEnd);
  pEnd = y->size[1];
  for (qEnd = 0; qEnd < pEnd; qEnd++) {
    c_y->data[c_y->size[0] * qEnd] = (int)y->data[y->size[0] * qEnd] - 1;
  }

  pEnd = b_y->size[1];
  for (qEnd = 0; qEnd < pEnd; qEnd++) {
    c_y->data[c_y->size[0] * (qEnd + y->size[1])] = (int)b_y->data[b_y->size[0] *
      qEnd] - 1;
  }

  emxInit_real_T(&b_h, 2);
  qEnd = b_h->size[0] * b_h->size[1];
  b_h->size[0] = 1;
  b_h->size[1] = y->size[1] + b_y->size[1];
  emxEnsureCapacity_real_T(b_h, qEnd);
  pEnd = y->size[1] + b_y->size[1];
  emxFree_real_T(&b_y);
  for (qEnd = 0; qEnd < pEnd; qEnd++) {
    b_h->data[b_h->size[0] * qEnd] = h->data[c_y->data[c_y->size[0] * qEnd]];
  }

  qEnd = h->size[0] * h->size[1];
  h->size[0] = 1;
  h->size[1] = b_h->size[1];
  emxEnsureCapacity_real_T(h, qEnd);
  pEnd = b_h->size[1];
  for (qEnd = 0; qEnd < pEnd; qEnd++) {
    h->data[h->size[0] * qEnd] = b_h->data[b_h->size[0] * qEnd];
  }

  emxFree_real_T(&b_h);

  /*  Find unique rows to avoid excess computation */
  if (!((C->size[0] == 0) || (C->size[1] == 0))) {
    nm1d2 = C->size[0];
  } else if (!((a_normalized->size[0] == 0) || (a_normalized->size[1] == 0))) {
    nm1d2 = a_normalized->size[0];
  } else {
    nm1d2 = C->size[0];
    if (!(nm1d2 > 0)) {
      nm1d2 = 0;
    }

    if (a_normalized->size[0] > nm1d2) {
      nm1d2 = a_normalized->size[0];
    }
  }

  empty_non_axis_sizes = (nm1d2 == 0);
  if (empty_non_axis_sizes || (!((C->size[0] == 0) || (C->size[1] == 0)))) {
    pEnd = C->size[1];
  } else {
    pEnd = 0;
  }

  if (empty_non_axis_sizes || (!((a_normalized->size[0] == 0) ||
        (a_normalized->size[1] == 0)))) {
    p = a_normalized->size[1];
  } else {
    p = 0;
  }

  emxInit_real_T(&A, 2);
  qEnd = A->size[0] * A->size[1];
  A->size[0] = pEnd + p;
  A->size[1] = nm1d2;
  emxEnsureCapacity_real_T(A, qEnd);
  for (qEnd = 0; qEnd < nm1d2; qEnd++) {
    for (q = 0; q < pEnd; q++) {
      A->data[q + A->size[0] * qEnd] = C->data[qEnd + nm1d2 * q];
    }
  }

  for (qEnd = 0; qEnd < nm1d2; qEnd++) {
    for (q = 0; q < p; q++) {
      A->data[(q + pEnd) + A->size[0] * qEnd] = a_normalized->data[qEnd + nm1d2 *
        q];
    }
  }

  emxInit_int32_T(&idx, 1);
  emxInit_real_T2(&ycol, 1);
  if (A->size[0] == 0) {
    qEnd = a_normalized->size[0] * a_normalized->size[1];
    a_normalized->size[0] = A->size[0];
    a_normalized->size[1] = A->size[1];
    emxEnsureCapacity_real_T(a_normalized, qEnd);
    pEnd = A->size[0] * A->size[1];
    for (qEnd = 0; qEnd < pEnd; qEnd++) {
      a_normalized->data[qEnd] = A->data[qEnd];
    }
  } else {
    qEnd = a_normalized->size[0] * a_normalized->size[1];
    a_normalized->size[0] = A->size[0];
    a_normalized->size[1] = A->size[1];
    emxEnsureCapacity_real_T(a_normalized, qEnd);
    pEnd = A->size[0] * A->size[1];
    for (qEnd = 0; qEnd < pEnd; qEnd++) {
      a_normalized->data[qEnd] = A->data[qEnd];
    }

    qEnd = c_y->size[0] * c_y->size[1];
    c_y->size[0] = 1;
    c_y->size[1] = A->size[1];
    emxEnsureCapacity_int32_T(c_y, qEnd);
    for (k = 1; k <= A->size[1]; k++) {
      c_y->data[k - 1] = k;
    }

    n = A->size[0];
    qEnd = idx->size[0];
    idx->size[0] = A->size[0];
    emxEnsureCapacity_int32_T1(idx, qEnd);
    pEnd = A->size[0];
    for (qEnd = 0; qEnd < pEnd; qEnd++) {
      idx->data[qEnd] = 0;
    }

    if (A->size[1] == 0) {
      for (k = 1; k <= n; k++) {
        idx->data[k - 1] = k;
      }
    } else {
      emxInit_int32_T(&iwork, 1);
      qEnd = iwork->size[0];
      iwork->size[0] = A->size[0];
      emxEnsureCapacity_int32_T1(iwork, qEnd);
      for (k = 1; k <= n - 1; k += 2) {
        if (sortLE(A, c_y, k, k + 1)) {
          idx->data[k - 1] = k;
          idx->data[k] = k + 1;
        } else {
          idx->data[k - 1] = k + 1;
          idx->data[k] = k;
        }
      }

      if ((A->size[0] & 1) != 0) {
        idx->data[A->size[0] - 1] = A->size[0];
      }

      i = 2;
      while (i < n) {
        nm1d2 = i << 1;
        j = 1;
        for (pEnd = 1 + i; pEnd < n + 1; pEnd = qEnd + i) {
          p = j;
          q = pEnd;
          qEnd = j + nm1d2;
          if (qEnd > n + 1) {
            qEnd = n + 1;
          }

          k = 0;
          kEnd = qEnd - j;
          while (k + 1 <= kEnd) {
            if (sortLE(A, c_y, idx->data[p - 1], idx->data[q - 1])) {
              iwork->data[k] = idx->data[p - 1];
              p++;
              if (p == pEnd) {
                while (q < qEnd) {
                  k++;
                  iwork->data[k] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[k] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < pEnd) {
                  k++;
                  iwork->data[k] = idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            idx->data[(j + k) - 1] = iwork->data[k];
          }

          j = qEnd;
        }

        i = nm1d2;
      }

      emxFree_int32_T(&iwork);
    }

    nm1d2 = A->size[0];
    count = (unsigned int)A->size[0];
    qEnd = ycol->size[0];
    ycol->size[0] = (int)count;
    emxEnsureCapacity_real_T2(ycol, qEnd);
    for (j = 0; j < A->size[1]; j++) {
      for (i = 0; i < nm1d2; i++) {
        ycol->data[i] = a_normalized->data[(idx->data[i] + a_normalized->size[0]
          * j) - 1];
      }

      for (i = 0; i < nm1d2; i++) {
        a_normalized->data[i + a_normalized->size[0] * j] = ycol->data[i];
      }
    }

    nm1d2 = 0;
    pEnd = A->size[0];
    k = 0;
    while (k + 1 <= pEnd) {
      p = k;
      do {
        exitg1 = 0;
        k++;
        if (k + 1 > pEnd) {
          exitg1 = 1;
        } else {
          empty_non_axis_sizes = false;
          j = 0;
          exitg2 = false;
          while ((!exitg2) && (j <= a_normalized->size[1] - 1)) {
            d = fabs(a_normalized->data[k + a_normalized->size[0] * j] / 2.0);
            if ((!rtIsInf(d)) && (!rtIsNaN(d))) {
              if (d <= 2.2250738585072014E-308) {
                d = 4.94065645841247E-324;
              } else {
                frexp(d, &exponent);
                d = ldexp(1.0, exponent - 53);
              }
            } else {
              d = rtNaN;
            }

            if ((fabs(a_normalized->data[k + a_normalized->size[0] * j] -
                      a_normalized->data[p + a_normalized->size[0] * j]) < d) ||
                (rtIsInf(a_normalized->data[p + a_normalized->size[0] * j]) &&
                 rtIsInf(a_normalized->data[k + a_normalized->size[0] * j]) &&
                 ((a_normalized->data[p + a_normalized->size[0] * j] > 0.0) ==
                  (a_normalized->data[k + a_normalized->size[0] * j] > 0.0)))) {
              j++;
            } else {
              empty_non_axis_sizes = true;
              exitg2 = true;
            }
          }

          if (empty_non_axis_sizes) {
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);

      nm1d2++;
      qEnd = a_normalized->size[1];
      for (j = 0; j < qEnd; j++) {
        a_normalized->data[(nm1d2 + a_normalized->size[0] * j) - 1] =
          a_normalized->data[p + a_normalized->size[0] * j];
      }
    }

    if (1 > nm1d2) {
      pEnd = 0;
    } else {
      pEnd = nm1d2;
    }

    nm1d2 = a_normalized->size[1];
    qEnd = A->size[0] * A->size[1];
    A->size[0] = pEnd;
    A->size[1] = nm1d2;
    emxEnsureCapacity_real_T(A, qEnd);
    for (qEnd = 0; qEnd < nm1d2; qEnd++) {
      for (q = 0; q < pEnd; q++) {
        A->data[q + A->size[0] * qEnd] = a_normalized->data[q +
          a_normalized->size[0] * qEnd];
      }
    }

    qEnd = a_normalized->size[0] * a_normalized->size[1];
    a_normalized->size[0] = A->size[0];
    a_normalized->size[1] = A->size[1];
    emxEnsureCapacity_real_T(a_normalized, qEnd);
    pEnd = A->size[1];
    for (qEnd = 0; qEnd < pEnd; qEnd++) {
      nm1d2 = A->size[0];
      for (q = 0; q < nm1d2; q++) {
        a_normalized->data[q + a_normalized->size[0] * qEnd] = A->data[q +
          A->size[0] * qEnd];
      }
    }
  }

  emxFree_int32_T(&c_y);
  qEnd = C->size[0] * C->size[1];
  C->size[0] = a_normalized->size[1];
  C->size[1] = a_normalized->size[0];
  emxEnsureCapacity_real_T(C, qEnd);
  pEnd = a_normalized->size[0];
  for (qEnd = 0; qEnd < pEnd; qEnd++) {
    nm1d2 = a_normalized->size[1];
    for (q = 0; q < nm1d2; q++) {
      C->data[q + C->size[0] * qEnd] = a_normalized->data[qEnd +
        a_normalized->size[0] * q];
    }
  }

  emxInit_real_T1(&T_a, 3);
  emxInit_real_T1(&sd_a, 3);

  /*  Preallocate array */
  /*  Compute indices via weighted sampling */
  qEnd = T_a->size[0] * T_a->size[1] * T_a->size[2];
  T_a->size[0] = Sobol_Output->T->size[0];
  T_a->size[1] = C->size[1];
  T_a->size[2] = h->size[1];
  emxEnsureCapacity_real_T1(T_a, qEnd);
  qEnd = sd_a->size[0] * sd_a->size[1] * sd_a->size[2];
  sd_a->size[0] = C->size[1];
  sd_a->size[1] = h->size[1];
  sd_a->size[2] = Sobol_Output->T->size[0];
  emxEnsureCapacity_real_T1(sd_a, qEnd);
  k = 0;
  emxInit_real_T2(&Perturbed_PDF_Data_psi_A, 1);
  emxInit_real_T2(&r0, 1);
  while (k <= C->size[1] - 1) {
    pEnd = C->size[0];
    qEnd = ycol->size[0];
    ycol->size[0] = pEnd;
    emxEnsureCapacity_real_T2(ycol, qEnd);
    for (qEnd = 0; qEnd < pEnd; qEnd++) {
      ycol->data[qEnd] = C->data[qEnd + C->size[0] * k];
    }

    c_Perturbed_Sobol_Indices_Prepr(Sobol_Output->A, Sobol_Output->C,
      Phi_Data->phi_A, Psi_Data_psi_A_val, Psi_Data_psi_C_val, Psi_Data_psi_val,
      ycol, R, Perturbed_PDF_Data_psi_A, A, a_normalized, &d);
    for (j = 0; j < h->size[1]; j++) {
      Perturbed_Sobol_Indices(Sobol_Output->YA, Sobol_Output->YC,
        Phi_Data->phi_A, Phi_Data->phi_C, Phi_Data->phi_C_Cond_not_k,
        Phi_Data->phi_C_marg_not_k, Perturbed_PDF_Data_psi_A, A, a_normalized, d,
        h->data[j], sd_nom, m, ycol, r0);
      pEnd = ycol->size[0];
      for (qEnd = 0; qEnd < pEnd; qEnd++) {
        T_a->data[(qEnd + T_a->size[0] * k) + T_a->size[0] * T_a->size[1] * j] =
          ycol->data[qEnd];
      }

      pEnd = sd_a->size[2];
      qEnd = idx->size[0];
      idx->size[0] = pEnd;
      emxEnsureCapacity_int32_T1(idx, qEnd);
      for (qEnd = 0; qEnd < pEnd; qEnd++) {
        idx->data[qEnd] = qEnd;
      }

      nm1d2 = idx->size[0];
      for (qEnd = 0; qEnd < nm1d2; qEnd++) {
        sd_a->data[(k + sd_a->size[0] * j) + sd_a->size[0] * sd_a->size[1] *
          idx->data[qEnd]] = r0->data[qEnd];
      }
    }

    k++;
  }

  emxFree_real_T(&ycol);
  emxFree_int32_T(&idx);
  emxFree_real_T(&r0);
  emxFree_real_T(&Psi_Data_psi_val);
  emxFree_real_T(&Psi_Data_psi_C_val);
  emxFree_real_T(&Psi_Data_psi_A_val);
  emxFree_real_T(&a_normalized);
  emxFree_real_T(&Perturbed_PDF_Data_psi_A);
  emxFree_real_T(&A);
  emxFree_real_T(&h);
  for (qEnd = 0; qEnd < 3; qEnd++) {
    sz[qEnd] = (unsigned int)sd_a->size[qEnd];
  }

  qEnd = C->size[0] * C->size[1];
  C->size[0] = (int)sz[0];
  C->size[1] = (int)sz[1];
  emxEnsureCapacity_real_T(C, qEnd);
  if ((sd_a->size[0] == 0) || (sd_a->size[1] == 0)) {
    qEnd = C->size[0] * C->size[1];
    emxEnsureCapacity_real_T(C, qEnd);
    pEnd = C->size[1];
    for (qEnd = 0; qEnd < pEnd; qEnd++) {
      nm1d2 = C->size[0];
      for (q = 0; q < nm1d2; q++) {
        C->data[q + C->size[0] * qEnd] = rtNaN;
      }
    }
  } else {
    k = 3;
    if (sd_a->size[2] == 1) {
      k = 2;
    }

    if (3 > k) {
      pEnd = sd_a->size[0] * sd_a->size[1] * sd_a->size[2];
    } else {
      pEnd = 1;
      for (k = 0; k < 2; k++) {
        pEnd *= sd_a->size[k];
      }
    }

    for (j = 0; j < pEnd; j++) {
      C->data[j] = sd_a->data[j];
    }

    for (i = 2; i <= sd_a->size[2]; i++) {
      nm1d2 = (i - 1) * pEnd;
      for (j = 0; j < pEnd; j++) {
        empty_non_axis_sizes = ((!rtIsNaN(sd_a->data[nm1d2 + j])) && (rtIsNaN
          (C->data[j]) || (C->data[j] < sd_a->data[nm1d2 + j])));
        if (empty_non_axis_sizes) {
          C->data[j] = sd_a->data[nm1d2 + j];
        }
      }
    }
  }

  emxFree_real_T(&sd_a);
  emxInit_boolean_T(&x, 2);
  qEnd = x->size[0] * x->size[1];
  x->size[0] = C->size[0];
  x->size[1] = C->size[1];
  emxEnsureCapacity_boolean_T(x, qEnd);
  pEnd = C->size[0] * C->size[1];
  for (qEnd = 0; qEnd < pEnd; qEnd++) {
    x->data[qEnd] = (C->data[qEnd] < tau);
  }

  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    for (qEnd = 0; qEnd < 2; qEnd++) {
      b_sz[qEnd] = (unsigned int)x->size[qEnd];
    }

    qEnd = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)b_sz[1];
    emxEnsureCapacity_real_T(y, qEnd);
    pEnd = (int)b_sz[1];
    for (qEnd = 0; qEnd < pEnd; qEnd++) {
      y->data[qEnd] = 0.0;
    }
  } else {
    qEnd = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, qEnd);
    for (i = 0; i < x->size[1]; i++) {
      nm1d2 = i * x->size[0];
      y->data[i] = x->data[nm1d2];
      for (k = 2; k <= x->size[0]; k++) {
        y->data[i] += (double)x->data[(nm1d2 + k) - 1];
      }
    }
  }

  emxFree_boolean_T(&x);
  if (y->size[1] == 0) {
    d = 0.0;
  } else {
    d = y->data[0];
    for (k = 2; k <= y->size[1]; k++) {
      d += y->data[k - 1];
    }
  }

  emxFree_real_T(&y);
  qEnd = T_pert->size[0] * T_pert->size[1];
  T_pert->size[0] = Sobol_Output->T->size[0];
  T_pert->size[1] = (int)d;
  emxEnsureCapacity_real_T(T_pert, qEnd);
  pEnd = Sobol_Output->T->size[0] * (int)d;
  for (qEnd = 0; qEnd < pEnd; qEnd++) {
    T_pert->data[qEnd] = 0.0;
  }

  count = 1U;
  for (i = 0; i < C->size[0]; i++) {
    for (j = 0; j < C->size[1]; j++) {
      if (C->data[i + C->size[0] * j] < tau) {
        pEnd = T_a->size[0] - 1;
        for (qEnd = 0; qEnd <= pEnd; qEnd++) {
          T_pert->data[qEnd + T_pert->size[0] * ((int)count - 1)] = T_a->data
            [(qEnd + T_a->size[0] * i) + T_a->size[0] * T_a->size[1] * j];
        }

        count++;
      }
    }
  }

  emxFree_real_T(&T_a);
  emxFree_real_T(&C);
}

/*
 * File trailer for Joint_Perturbation_Analysis.c
 *
 * [EOF]
 */
