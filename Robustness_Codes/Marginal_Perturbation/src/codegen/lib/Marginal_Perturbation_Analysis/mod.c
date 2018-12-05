/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mod.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Marginal_Perturbation_Analysis.h"
#include "mod.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double y
 * Return Type  : double
 */
double b_mod(double x, double y)
{
  double r;
  if ((!rtIsInf(x)) && (!rtIsNaN(x)) && ((!rtIsInf(y)) && (!rtIsNaN(y)))) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = fmod(x, y);
      if (r == 0.0) {
        r = 0.0;
      } else {
        if (x < 0.0) {
          r += y;
        }
      }
    }
  } else {
    r = rtNaN;
  }

  return r;
}

/*
 * File trailer for mod.c
 *
 * [EOF]
 */
