/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_setop.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "eml_setop.h"
#include "Joint_Perturbation_Analysis_emxutil.h"

/* Function Declarations */
static double skip_to_last_equal_value(int *k, const emxArray_real_T *x);

/* Function Definitions */

/*
 * Arguments    : int *k
 *                const emxArray_real_T *x
 * Return Type  : double
 */
static double skip_to_last_equal_value(int *k, const emxArray_real_T *x)
{
  double xk;
  boolean_T exitg1;
  double absxk;
  int exponent;
  xk = x->data[*k - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < x->size[1])) {
    absxk = fabs(xk / 2.0);
    if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if ((fabs(xk - x->data[*k]) < absxk) || (rtIsInf(x->data[*k]) && rtIsInf(xk)
         && ((x->data[*k] > 0.0) == (xk > 0.0)))) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return xk;
}

/*
 * Arguments    : const emxArray_real_T *a
 *                double b
 *                emxArray_real_T *c
 *                emxArray_int32_T *ia
 *                int ib_size[1]
 * Return Type  : void
 */
void do_vectors(const emxArray_real_T *a, double b, emxArray_real_T *c,
                emxArray_int32_T *ia, int ib_size[1])
{
  int na;
  unsigned int unnamed_idx_1;
  int iblast;
  int nc;
  int nia;
  int iafirst;
  int ialast;
  int b_ialast;
  double ak;
  double absxk;
  emxArray_int32_T *b_ia;
  int exponent;
  boolean_T b0;
  na = a->size[1];
  unnamed_idx_1 = (unsigned int)a->size[1];
  iblast = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = (int)unnamed_idx_1;
  emxEnsureCapacity_real_T(c, iblast);
  iblast = ia->size[0];
  ia->size[0] = a->size[1];
  emxEnsureCapacity_int32_T1(ia, iblast);
  ib_size[0] = 0;
  nc = 0;
  nia = 0;
  iafirst = 0;
  ialast = 1;
  iblast = 1;
  while ((ialast <= na) && (iblast <= 1)) {
    b_ialast = ialast;
    ak = skip_to_last_equal_value(&b_ialast, a);
    ialast = b_ialast;
    absxk = fabs(b / 2.0);
    if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if ((fabs(b - ak) < absxk) || (rtIsInf(ak) && rtIsInf(b) && ((ak > 0.0) ==
          (b > 0.0)))) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = 2;
    } else {
      if (rtIsNaN(b)) {
        b0 = !rtIsNaN(ak);
      } else {
        b0 = ((!rtIsNaN(ak)) && (ak < b));
      }

      if (b0) {
        nc++;
        nia++;
        c->data[nc - 1] = ak;
        ia->data[nia - 1] = iafirst + 1;
        ialast = b_ialast + 1;
        iafirst = b_ialast;
      } else {
        iblast = 2;
      }
    }
  }

  while (ialast <= na) {
    iafirst = ialast;
    ak = skip_to_last_equal_value(&iafirst, a);
    nc++;
    nia++;
    c->data[nc - 1] = ak;
    ia->data[nia - 1] = ialast;
    ialast = iafirst + 1;
  }

  if (a->size[1] > 0) {
    if (1 > nia) {
      iafirst = 0;
    } else {
      iafirst = nia;
    }

    emxInit_int32_T(&b_ia, 1);
    iblast = b_ia->size[0];
    b_ia->size[0] = iafirst;
    emxEnsureCapacity_int32_T1(b_ia, iblast);
    for (iblast = 0; iblast < iafirst; iblast++) {
      b_ia->data[iblast] = ia->data[iblast];
    }

    iblast = ia->size[0];
    ia->size[0] = b_ia->size[0];
    emxEnsureCapacity_int32_T1(ia, iblast);
    iafirst = b_ia->size[0];
    for (iblast = 0; iblast < iafirst; iblast++) {
      ia->data[iblast] = b_ia->data[iblast];
    }

    emxFree_int32_T(&b_ia);
    iblast = c->size[0] * c->size[1];
    if (1 > nc) {
      c->size[1] = 0;
    } else {
      c->size[1] = nc;
    }

    emxEnsureCapacity_real_T(c, iblast);
  }
}

/*
 * File trailer for eml_setop.c
 *
 * [EOF]
 */
