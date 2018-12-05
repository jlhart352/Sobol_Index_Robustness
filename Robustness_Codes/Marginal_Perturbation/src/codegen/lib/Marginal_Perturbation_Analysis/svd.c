/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: svd.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "svd.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"
#include "xrotg.h"
#include "sqrt.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *U
 * Return Type  : void
 */
void svd(const emxArray_real_T *A, emxArray_real_T *U)
{
  emxArray_real_T *b_A;
  int m;
  int ns;
  int n;
  int p;
  int qs;
  int minnp;
  emxArray_real_T *s;
  emxArray_real_T *e;
  emxArray_real_T *work;
  int nrt;
  int nct;
  int q;
  int iter;
  int mm;
  boolean_T apply_transform;
  double ztest0;
  double ztest;
  double snorm;
  boolean_T exitg1;
  double f;
  double scale;
  double sqds;
  double b;
  emxInit_real_T(&b_A, 2);
  m = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T1(b_A, m);
  ns = A->size[0] * A->size[1];
  for (m = 0; m < ns; m++) {
    b_A->data[m] = A->data[m];
  }

  n = A->size[0];
  p = A->size[1];
  qs = A->size[0] + 1;
  ns = A->size[1];
  if (qs < ns) {
    ns = qs;
  }

  qs = A->size[0];
  minnp = A->size[1];
  if (qs < minnp) {
    minnp = qs;
  }

  emxInit_real_T2(&s, 1);
  m = s->size[0];
  s->size[0] = ns;
  emxEnsureCapacity_real_T2(s, m);
  for (m = 0; m < ns; m++) {
    s->data[m] = 0.0;
  }

  emxInit_real_T2(&e, 1);
  ns = A->size[1];
  m = e->size[0];
  e->size[0] = ns;
  emxEnsureCapacity_real_T2(e, m);
  for (m = 0; m < ns; m++) {
    e->data[m] = 0.0;
  }

  emxInit_real_T2(&work, 1);
  ns = A->size[0];
  m = work->size[0];
  work->size[0] = ns;
  emxEnsureCapacity_real_T2(work, m);
  for (m = 0; m < ns; m++) {
    work->data[m] = 0.0;
  }

  if (!((A->size[0] == 0) || (A->size[1] == 0))) {
    if (A->size[1] > 2) {
      ns = A->size[1] - 2;
    } else {
      ns = 0;
    }

    nrt = A->size[0];
    if (ns < nrt) {
      nrt = ns;
    }

    if (A->size[0] > 1) {
      ns = A->size[0] - 1;
    } else {
      ns = 0;
    }

    nct = A->size[1];
    if (ns < nct) {
      nct = ns;
    }

    if (nct > nrt) {
      m = nct;
    } else {
      m = nrt;
    }

    for (q = 0; q < m; q++) {
      iter = q + n * q;
      mm = n - q;
      apply_transform = false;
      if (q + 1 <= nct) {
        ztest0 = xnrm2(mm, b_A, iter + 1);
        if (ztest0 > 0.0) {
          apply_transform = true;
          if (b_A->data[iter] < 0.0) {
            ztest0 = -ztest0;
          }

          s->data[q] = ztest0;
          if (fabs(s->data[q]) >= 1.0020841800044864E-292) {
            ztest0 = 1.0 / s->data[q];
            ns = iter + mm;
            for (qs = iter; qs < ns; qs++) {
              b_A->data[qs] *= ztest0;
            }
          } else {
            ns = iter + mm;
            for (qs = iter; qs < ns; qs++) {
              b_A->data[qs] /= s->data[q];
            }
          }

          b_A->data[iter]++;
          s->data[q] = -s->data[q];
        } else {
          s->data[q] = 0.0;
        }
      }

      for (ns = q + 1; ns < p; ns++) {
        qs = q + n * ns;
        if (apply_transform) {
          ztest0 = -(xdotc(mm, b_A, iter + 1, b_A, qs + 1) / b_A->data[q +
                     b_A->size[0] * q]);
          xaxpy(mm, ztest0, iter + 1, b_A, qs + 1);
        }

        e->data[ns] = b_A->data[qs];
      }

      if (q + 1 <= nrt) {
        ns = p - q;
        ztest0 = b_xnrm2(ns - 1, e, q + 2);
        if (ztest0 == 0.0) {
          e->data[q] = 0.0;
        } else {
          if (e->data[q + 1] < 0.0) {
            ztest0 = -ztest0;
          }

          e->data[q] = ztest0;
          ztest0 = e->data[q];
          if (fabs(e->data[q]) >= 1.0020841800044864E-292) {
            ztest0 = 1.0 / e->data[q];
            ns += q;
            for (qs = q + 1; qs < ns; qs++) {
              e->data[qs] *= ztest0;
            }
          } else {
            ns += q;
            for (qs = q + 1; qs < ns; qs++) {
              e->data[qs] /= ztest0;
            }
          }

          e->data[q + 1]++;
          e->data[q] = -e->data[q];
          if (q + 2 <= n) {
            for (ns = q + 1; ns < n; ns++) {
              work->data[ns] = 0.0;
            }

            for (ns = q + 1; ns < p; ns++) {
              b_xaxpy(mm - 1, e->data[ns], b_A, (q + n * ns) + 2, work, q + 2);
            }

            for (ns = q + 1; ns < p; ns++) {
              c_xaxpy(mm - 1, -e->data[ns] / e->data[q + 1], work, q + 2, b_A,
                      (q + n * ns) + 2);
            }
          }
        }
      }
    }

    qs = A->size[1];
    m = A->size[0] + 1;
    if (qs < m) {
      m = qs;
    }

    if (nct < A->size[1]) {
      s->data[nct] = b_A->data[nct + b_A->size[0] * nct];
    }

    if (A->size[0] < m) {
      s->data[m - 1] = 0.0;
    }

    if (nrt + 1 < m) {
      e->data[nrt] = b_A->data[nrt + b_A->size[0] * (m - 1)];
    }

    e->data[m - 1] = 0.0;
    for (q = 0; q < m; q++) {
      if (s->data[q] != 0.0) {
        ztest = fabs(s->data[q]);
        ztest0 = s->data[q] / ztest;
        s->data[q] = ztest;
        if (q + 1 < m) {
          e->data[q] /= ztest0;
        }
      }

      if ((q + 1 < m) && (e->data[q] != 0.0)) {
        ztest = fabs(e->data[q]);
        ztest0 = e->data[q];
        e->data[q] = ztest;
        s->data[q + 1] *= ztest / ztest0;
      }
    }

    mm = m;
    iter = 0;
    snorm = 0.0;
    for (ns = 0; ns < m; ns++) {
      ztest0 = fabs(s->data[ns]);
      ztest = fabs(e->data[ns]);
      if ((ztest0 > ztest) || rtIsNaN(ztest)) {
      } else {
        ztest0 = ztest;
      }

      if (!((snorm > ztest0) || rtIsNaN(ztest0))) {
        snorm = ztest0;
      }
    }

    while ((m > 0) && (!(iter >= 75))) {
      q = m - 1;
      exitg1 = false;
      while (!(exitg1 || (q == 0))) {
        ztest0 = fabs(e->data[q - 1]);
        if ((ztest0 <= 2.2204460492503131E-16 * (fabs(s->data[q - 1]) + fabs
              (s->data[q]))) || (ztest0 <= 1.0020841800044864E-292) || ((iter >
              20) && (ztest0 <= 2.2204460492503131E-16 * snorm))) {
          e->data[q - 1] = 0.0;
          exitg1 = true;
        } else {
          q--;
        }
      }

      if (q == m - 1) {
        ns = 4;
      } else {
        qs = m;
        ns = m;
        exitg1 = false;
        while ((!exitg1) && (ns >= q)) {
          qs = ns;
          if (ns == q) {
            exitg1 = true;
          } else {
            ztest0 = 0.0;
            if (ns < m) {
              ztest0 = fabs(e->data[ns - 1]);
            }

            if (ns > q + 1) {
              ztest0 += fabs(e->data[ns - 2]);
            }

            ztest = fabs(s->data[ns - 1]);
            if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
                 1.0020841800044864E-292)) {
              s->data[ns - 1] = 0.0;
              exitg1 = true;
            } else {
              ns--;
            }
          }
        }

        if (qs == q) {
          ns = 3;
        } else if (qs == m) {
          ns = 1;
        } else {
          ns = 2;
          q = qs;
        }
      }

      switch (ns) {
       case 1:
        f = e->data[m - 2];
        e->data[m - 2] = 0.0;
        for (qs = m - 3; qs + 2 >= q + 1; qs--) {
          xrotg(&s->data[qs + 1], &f, &ztest0, &ztest);
          if (qs + 2 > q + 1) {
            f = -ztest * e->data[qs];
            e->data[qs] *= ztest0;
          }
        }
        break;

       case 2:
        f = e->data[q - 1];
        e->data[q - 1] = 0.0;
        while (q + 1 <= m) {
          xrotg(&s->data[q], &f, &ztest0, &ztest);
          f = -ztest * e->data[q];
          e->data[q] *= ztest0;
          q++;
        }
        break;

       case 3:
        scale = fabs(s->data[m - 1]);
        ztest = fabs(s->data[m - 2]);
        if (!((scale > ztest) || rtIsNaN(ztest))) {
          scale = ztest;
        }

        ztest = fabs(e->data[m - 2]);
        if (!((scale > ztest) || rtIsNaN(ztest))) {
          scale = ztest;
        }

        ztest = fabs(s->data[q]);
        if (!((scale > ztest) || rtIsNaN(ztest))) {
          scale = ztest;
        }

        ztest = fabs(e->data[q]);
        if (!((scale > ztest) || rtIsNaN(ztest))) {
          scale = ztest;
        }

        f = s->data[m - 1] / scale;
        ztest0 = s->data[m - 2] / scale;
        ztest = e->data[m - 2] / scale;
        sqds = s->data[q] / scale;
        b = ((ztest0 + f) * (ztest0 - f) + ztest * ztest) / 2.0;
        ztest0 = f * ztest;
        ztest0 *= ztest0;
        if ((b != 0.0) || (ztest0 != 0.0)) {
          ztest = b * b + ztest0;
          b_sqrt(&ztest);
          if (b < 0.0) {
            ztest = -ztest;
          }

          ztest = ztest0 / (b + ztest);
        } else {
          ztest = 0.0;
        }

        f = (sqds + f) * (sqds - f) + ztest;
        b = sqds * (e->data[q] / scale);
        for (qs = q + 1; qs < m; qs++) {
          xrotg(&f, &b, &ztest0, &ztest);
          if (qs > q + 1) {
            e->data[qs - 2] = f;
          }

          f = ztest0 * s->data[qs - 1] + ztest * e->data[qs - 1];
          e->data[qs - 1] = ztest0 * e->data[qs - 1] - ztest * s->data[qs - 1];
          b = ztest * s->data[qs];
          s->data[qs] *= ztest0;
          s->data[qs - 1] = f;
          xrotg(&s->data[qs - 1], &b, &ztest0, &ztest);
          f = ztest0 * e->data[qs - 1] + ztest * s->data[qs];
          s->data[qs] = -ztest * e->data[qs - 1] + ztest0 * s->data[qs];
          b = ztest * e->data[qs];
          e->data[qs] *= ztest0;
        }

        e->data[m - 2] = f;
        iter++;
        break;

       default:
        if (s->data[q] < 0.0) {
          s->data[q] = -s->data[q];
        }

        ns = q + 1;
        while ((q + 1 < mm) && (s->data[q] < s->data[ns])) {
          ztest = s->data[q];
          s->data[q] = s->data[ns];
          s->data[ns] = ztest;
          q = ns;
          ns++;
        }

        iter = 0;
        m--;
        break;
      }
    }
  }

  emxFree_real_T(&work);
  emxFree_real_T(&e);
  emxFree_real_T(&b_A);
  m = U->size[0];
  U->size[0] = minnp;
  emxEnsureCapacity_real_T2(U, m);
  for (qs = 0; qs < minnp; qs++) {
    U->data[qs] = s->data[qs];
  }

  emxFree_real_T(&s);
}

/*
 * File trailer for svd.c
 *
 * [EOF]
 */
