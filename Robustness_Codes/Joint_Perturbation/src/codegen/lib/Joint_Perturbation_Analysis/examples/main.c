/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 10:41:35
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "Joint_Perturbation_Analysis.h"
#include "main.h"
#include "Joint_Perturbation_Analysis_terminate.h"
#include "Joint_Perturbation_Analysis_emxAPI.h"
#include "Joint_Perturbation_Analysis_initialize.h"

/* Function Declarations */
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static double argInit_real_T(void);
static struct0_T argInit_struct0_T(void);
static struct1_T argInit_struct1_T(void);
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);
static emxArray_real_T *c_argInit_UnboundedxUnboundedx2(void);
static emxArray_real_T *c_argInit_UnboundedxUnboundedxU(void);
static void main_Joint_Perturbation_Analysis(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  static int iv3[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv3);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  static int iv0[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv0);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : struct0_T
 */
static struct0_T argInit_struct0_T(void)
{
  struct0_T result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.T = argInit_Unboundedx1_real_T();
  result.A = c_argInit_UnboundedxUnbounded_r();
  result.C = c_argInit_UnboundedxUnboundedxU();
  result.YA = argInit_Unboundedx1_real_T();
  result.YC = c_argInit_UnboundedxUnbounded_r();
  result.Var_Y = argInit_real_T();
  result.muYA = argInit_real_T();
  return result;
}

/*
 * Arguments    : void
 * Return Type  : struct1_T
 */
static struct1_T argInit_struct1_T(void)
{
  struct1_T result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.phi_A = argInit_Unboundedx1_real_T();
  result.phi_A_marg_not_k = c_argInit_UnboundedxUnbounded_r();
  result.phi_C = c_argInit_UnboundedxUnbounded_r();
  result.phi_C_Cond_not_k = c_argInit_UnboundedxUnbounded_r();
  result.phi_C_marg_not_k = c_argInit_UnboundedxUnbounded_r();
  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  static int iv1[2] = { 2, 2 };

  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv1);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnboundedx2(void)
{
  emxArray_real_T *result;
  static int iv4[3] = { 2, 2, 2 };

  int idx0;
  int idx1;
  int idx2;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(3, iv4);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      for (idx2 = 0; idx2 < 2; idx2++) {
        /* Set the value of the array element.
           Change this value to the value that the application requires. */
        result->data[(idx0 + result->size[0] * idx1) + result->size[0] *
          result->size[1] * idx2] = argInit_real_T();
      }
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnboundedxU(void)
{
  emxArray_real_T *result;
  static int iv2[3] = { 2, 2, 2 };

  int idx0;
  int idx1;
  int idx2;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(3, iv2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      for (idx2 = 0; idx2 < result->size[2U]; idx2++) {
        /* Set the value of the array element.
           Change this value to the value that the application requires. */
        result->data[(idx0 + result->size[0] * idx1) + result->size[0] *
          result->size[1] * idx2] = argInit_real_T();
      }
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_Joint_Perturbation_Analysis(void)
{
  emxArray_real_T *T_pert;
  struct0_T Sobol_Output;
  struct1_T Phi_Data;
  emxArray_real_T *sd_nom;
  emxArray_real_T *R;
  emxInitArray_real_T(&T_pert, 2);

  /* Initialize function 'Joint_Perturbation_Analysis' input arguments. */
  /* Initialize function input argument 'Sobol_Output'. */
  Sobol_Output = argInit_struct0_T();

  /* Initialize function input argument 'Phi_Data'. */
  Phi_Data = argInit_struct1_T();

  /* Initialize function input argument 'sd_nom'. */
  sd_nom = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'R'. */
  R = c_argInit_UnboundedxUnboundedx2();

  /* Call the entry-point 'Joint_Perturbation_Analysis'. */
  Joint_Perturbation_Analysis(&Sobol_Output, &Phi_Data, sd_nom, R,
    argInit_real_T(), argInit_real_T(), argInit_real_T(), T_pert);
  emxDestroyArray_real_T(T_pert);
  emxDestroyArray_real_T(R);
  emxDestroyArray_real_T(sd_nom);
  emxDestroy_struct1_T(Phi_Data);
  emxDestroy_struct0_T(Sobol_Output);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  Joint_Perturbation_Analysis_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_Joint_Perturbation_Analysis();

  /* Terminate the application.
     You do not need to do this more than one time. */
  Joint_Perturbation_Analysis_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
