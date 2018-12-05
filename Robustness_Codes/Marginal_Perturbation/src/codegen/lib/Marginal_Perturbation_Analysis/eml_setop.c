/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_setop.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "eml_setop.h"
#include "Marginal_Perturbation_Analysis_emxutil.h"

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
  boolean_T p;
  xk = x->data[*k - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < x->size[0])) {
    absxk = fabs(xk / 2.0);
    if (absxk <= 2.2250738585072014E-308) {
      absxk = 4.94065645841247E-324;
    } else {
      frexp(absxk, &exponent);
      absxk = ldexp(1.0, exponent - 53);
    }

    p = (fabs(xk - x->data[*k]) < absxk);
    if (p) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }

  return xk;
}

/*
 * Arguments    : const emxArray_real_T *a
 *                const emxArray_real_T *b
 *                emxArray_real_T *c
 *                emxArray_int32_T *ia
 *                emxArray_int32_T *ib
 * Return Type  : void
 */
void do_vectors(const emxArray_real_T *a, const emxArray_real_T *b,
                emxArray_real_T *c, emxArray_int32_T *ia, emxArray_int32_T *ib)
{
  int iafirst;
  int ncmax;
  int ialast;
  int nc;
  int ibfirst;
  int iblast;
  emxArray_int32_T *b_ia;
  int b_ialast;
  double ak;
  int b_iblast;
  double bk;
  double absxk;
  emxArray_real_T *b_c;
  int exponent;
  iafirst = a->size[0];
  ncmax = b->size[0];
  if (iafirst < ncmax) {
    ncmax = iafirst;
  }

  ialast = c->size[0];
  c->size[0] = ncmax;
  emxEnsureCapacity_real_T2(c, ialast);
  ialast = ia->size[0];
  ia->size[0] = ncmax;
  emxEnsureCapacity_int32_T(ia, ialast);
  ialast = ib->size[0];
  ib->size[0] = ncmax;
  emxEnsureCapacity_int32_T(ib, ialast);
  nc = 0;
  iafirst = 0;
  ialast = 1;
  ibfirst = 0;
  iblast = 1;
  while ((ialast <= a->size[0]) && (iblast <= b->size[0])) {
    b_ialast = ialast;
    ak = skip_to_last_equal_value(&b_ialast, a);
    ialast = b_ialast;
    b_iblast = iblast;
    bk = skip_to_last_equal_value(&b_iblast, b);
    iblast = b_iblast;
    absxk = fabs(bk / 2.0);
    if (absxk <= 2.2250738585072014E-308) {
      absxk = 4.94065645841247E-324;
    } else {
      frexp(absxk, &exponent);
      absxk = ldexp(1.0, exponent - 53);
    }

    if (fabs(bk - ak) < absxk) {
      nc++;
      c->data[nc - 1] = ak;
      ia->data[nc - 1] = iafirst + 1;
      ib->data[nc - 1] = ibfirst + 1;
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
    } else {
      iblast = b_iblast + 1;
      ibfirst = b_iblast;
    }
  }

  emxInit_int32_T(&b_ia, 1);
  if (ncmax > 0) {
    if (1 > nc) {
      iafirst = 0;
    } else {
      iafirst = nc;
    }

    ialast = b_ia->size[0];
    b_ia->size[0] = iafirst;
    emxEnsureCapacity_int32_T(b_ia, ialast);
    for (ialast = 0; ialast < iafirst; ialast++) {
      b_ia->data[ialast] = ia->data[ialast];
    }

    ialast = ia->size[0];
    ia->size[0] = b_ia->size[0];
    emxEnsureCapacity_int32_T(ia, ialast);
    iafirst = b_ia->size[0];
    for (ialast = 0; ialast < iafirst; ialast++) {
      ia->data[ialast] = b_ia->data[ialast];
    }

    if (1 > nc) {
      iafirst = 0;
    } else {
      iafirst = nc;
    }

    ialast = b_ia->size[0];
    b_ia->size[0] = iafirst;
    emxEnsureCapacity_int32_T(b_ia, ialast);
    for (ialast = 0; ialast < iafirst; ialast++) {
      b_ia->data[ialast] = ib->data[ialast];
    }

    ialast = ib->size[0];
    ib->size[0] = b_ia->size[0];
    emxEnsureCapacity_int32_T(ib, ialast);
    iafirst = b_ia->size[0];
    for (ialast = 0; ialast < iafirst; ialast++) {
      ib->data[ialast] = b_ia->data[ialast];
    }
  }

  emxFree_int32_T(&b_ia);
  if (ncmax > 0) {
    if (1 > nc) {
      iafirst = 0;
    } else {
      iafirst = nc;
    }

    emxInit_real_T2(&b_c, 1);
    ialast = b_c->size[0];
    b_c->size[0] = iafirst;
    emxEnsureCapacity_real_T2(b_c, ialast);
    for (ialast = 0; ialast < iafirst; ialast++) {
      b_c->data[ialast] = c->data[ialast];
    }

    ialast = c->size[0];
    c->size[0] = b_c->size[0];
    emxEnsureCapacity_real_T2(c, ialast);
    iafirst = b_c->size[0];
    for (ialast = 0; ialast < iafirst; ialast++) {
      c->data[ialast] = b_c->data[ialast];
    }

    emxFree_real_T(&b_c);
  }
}

/*
 * File trailer for eml_setop.c
 *
 * [EOF]
 */
