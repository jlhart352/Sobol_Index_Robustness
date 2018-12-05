/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Marginal_Perturbation_Analysis_mex.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include "_coder_Marginal_Perturbation_Analysis_api.h"
#include "_coder_Marginal_Perturbation_Analysis_mex.h"

/* Function Declarations */
static void c_Marginal_Perturbation_Analysi(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[7]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[7]
 * Return Type  : void
 */
static void c_Marginal_Perturbation_Analysi(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[7])
{
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        30, "Marginal_Perturbation_Analysis");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 30,
                        "Marginal_Perturbation_Analysis");
  }

  /* Call the function. */
  Marginal_Perturbation_Analysis_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  Marginal_Perturbation_Analysis_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Marginal_Perturbation_Analysis_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  Marginal_Perturbation_Analysis_initialize();

  /* Dispatch the entry-point. */
  c_Marginal_Perturbation_Analysi(nlhs, plhs, nrhs, prhs);
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_Marginal_Perturbation_Analysis_mex.c
 *
 * [EOF]
 */
