/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Marginal_Perturbation_Analysis_api.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 27-Nov-2018 14:33:55
 */

/* Include Files */
#include <string.h>
#include "tmwtypes.h"
#include "_coder_Marginal_Perturbation_Analysis_api.h"
#include "_coder_Marginal_Perturbation_Analysis_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "Marginal_Perturbation_Analysis",    /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Sobol_Output,
  const char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct2_T *u);
static void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel);
static void emxEnsureCapacity_real_T1(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel);
static void emxEnsureCapacity_real_T2(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel);
static void emxFreeStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct);
static void emxFreeStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct);
static void emxFreeStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct);
static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T1(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T2(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Phi_Data,
  const char_T *identifier, struct1_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *R, const
  char_T *identifier, emxArray_real_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sd_S_nom,
  const char_T *identifier, emxArray_real_T *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct0_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[10] = { "S", "T", "A", "B", "YA", "YB", "YC",
    "Var_Y", "muYA", "muYB" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 10, fieldNames, 0U, &dims);
  thisId.fIdentifier = "S";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "S")),
                     &thisId, y->S);
  thisId.fIdentifier = "T";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "T")),
                     &thisId, y->T);
  thisId.fIdentifier = "A";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "A")),
                     &thisId, y->A);
  thisId.fIdentifier = "B";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "B")),
                     &thisId, y->B);
  thisId.fIdentifier = "YA";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "YA")),
                     &thisId, y->YA);
  thisId.fIdentifier = "YB";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "YB")),
                     &thisId, y->YB);
  thisId.fIdentifier = "YC";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6, "YC")),
                     &thisId, y->YC);
  thisId.fIdentifier = "Var_Y";
  y->Var_Y = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "Var_Y")), &thisId);
  thisId.fIdentifier = "muYA";
  y->muYA = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "muYA")), &thisId);
  thisId.fIdentifier = "muYB";
  y->muYB = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "muYB")), &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  real_T *pData;
  int32_T i1;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m1 = emlrtCreateNumericArray(2, *(int32_T (*)[2])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m1);
  i1 = 0;
  for (i = 0; i < u->size[1]; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i1] = u->data[b_i + u->size[0] * i];
      i1++;
    }
  }

  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = o_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Sobol_Output
 *                const char_T *identifier
 *                struct0_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Sobol_Output,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Sobol_Output), &thisId, y);
  emlrtDestroyArray(&Sobol_Output);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const struct2_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct2_T *u)
{
  const mxArray *y;
  emxArray_real_T *b_u;
  static const char * sv0[11] = { "delta_val", "S_sd_pert", "S_pert",
    "T_sd_pert", "T_pert", "Acc_Rej_Bound", "R", "a", "delta_weights", "psi_val",
    "perturbation_marker" };

  int32_T i0;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m0;
  real_T *pData;
  emxArray_real_T *c_u;
  int32_T i;
  int32_T b_i;
  emxArray_real_T *d_u;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T2(sp, &b_u, 3, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 11, sv0));
  emlrtSetFieldR2017b(y, 0, "delta_val", b_emlrt_marshallOut(u->delta_val), 0);
  emlrtSetFieldR2017b(y, 0, "S_sd_pert", b_emlrt_marshallOut(u->S_sd_pert), 1);
  emlrtSetFieldR2017b(y, 0, "S_pert", b_emlrt_marshallOut(u->S_pert), 2);
  emlrtSetFieldR2017b(y, 0, "T_sd_pert", b_emlrt_marshallOut(u->T_sd_pert), 3);
  emlrtSetFieldR2017b(y, 0, "T_pert", b_emlrt_marshallOut(u->T_pert), 4);
  emlrtSetFieldR2017b(y, 0, "Acc_Rej_Bound", b_emlrt_marshallOut
                      (u->Acc_Rej_Bound), 5);
  emlrtSetFieldR2017b(y, 0, "R", b_emlrt_marshallOut(u->R), 6);
  i0 = b_u->size[0] * b_u->size[1] * b_u->size[2];
  b_u->size[0] = u->a->size[0];
  b_u->size[1] = u->a->size[1];
  b_u->size[2] = u->a->size[2];
  emxEnsureCapacity_real_T(sp, b_u, i0);
  loop_ub = u->a->size[0] * u->a->size[1] * u->a->size[2];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_u->data[i0] = u->a->data[i0];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(3, *(int32_T (*)[2])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  loop_ub = 0;
  emxFree_real_T(sp, &b_u);
  while (loop_ub < u->a->size[2]) {
    for (i = 0; i < u->a->size[1]; i++) {
      for (b_i = 0; b_i < u->a->size[0]; b_i++) {
        pData[i0] = u->a->data[(b_i + u->a->size[0] * i) + u->a->size[0] * u->
          a->size[1] * loop_ub];
        i0++;
      }
    }

    loop_ub++;
  }

  emxInit_real_T1(sp, &c_u, 2, true);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "a", b_y, 7);
  emlrtSetFieldR2017b(y, 0, "delta_weights", b_emlrt_marshallOut
                      (u->delta_weights), 8);
  i0 = c_u->size[0] * c_u->size[1];
  c_u->size[0] = u->psi_val->size[0];
  c_u->size[1] = u->psi_val->size[1];
  emxEnsureCapacity_real_T1(sp, c_u, i0);
  loop_ub = u->psi_val->size[0] * u->psi_val->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    c_u->data[i0] = u->psi_val->data[i0];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, *(int32_T (*)[2])c_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  loop_ub = 0;
  emxFree_real_T(sp, &c_u);
  while (loop_ub < u->psi_val->size[1]) {
    for (i = 0; i < u->psi_val->size[0]; i++) {
      pData[i0] = u->psi_val->data[i + u->psi_val->size[0] * loop_ub];
      i0++;
    }

    loop_ub++;
  }

  emxInit_real_T(sp, &d_u, 1, true);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "psi_val", b_y, 9);
  i0 = d_u->size[0];
  d_u->size[0] = u->perturbation_marker->size[0];
  emxEnsureCapacity_real_T2(sp, d_u, i0);
  loop_ub = u->perturbation_marker->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    d_u->data[i0] = u->perturbation_marker->data[i0];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[2])d_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  loop_ub = 0;
  emxFree_real_T(sp, &d_u);
  while (loop_ub < u->perturbation_marker->size[0]) {
    pData[i0] = u->perturbation_marker->data[loop_ub];
    i0++;
    loop_ub++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "perturbation_marker", b_y, 10);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex2018a(sp, (void *)emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T1(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex2018a(sp, (void *)emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T2(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex2018a(sp, (void *)emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct0_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->S);
  emxFree_real_T(sp, &pStruct->T);
  emxFree_real_T(sp, &pStruct->A);
  emxFree_real_T(sp, &pStruct->B);
  emxFree_real_T(sp, &pStruct->YA);
  emxFree_real_T(sp, &pStruct->YB);
  emxFree_real_T(sp, &pStruct->YC);
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct1_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->phi_A);
  emxFree_real_T(sp, &pStruct->phi_B);
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct2_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct)
{
  emxFree_real_T(sp, &pStruct->delta_val);
  emxFree_real_T(sp, &pStruct->S_sd_pert);
  emxFree_real_T(sp, &pStruct->S_pert);
  emxFree_real_T(sp, &pStruct->T_sd_pert);
  emxFree_real_T(sp, &pStruct->T_pert);
  emxFree_real_T(sp, &pStruct->Acc_Rej_Bound);
  emxFree_real_T(sp, &pStruct->R);
  emxFree_real_T(sp, &pStruct->a);
  emxFree_real_T(sp, &pStruct->delta_weights);
  emxFree_real_T(sp, &pStruct->psi_val);
  emxFree_real_T(sp, &pStruct->perturbation_marker);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex2018a(sp, (void *)(*pEmxArray)->data);
    }

    emlrtFreeMex2018a(sp, (void *)(*pEmxArray)->size);
    emlrtFreeMex2018a(sp, (void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct0_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->S, 1, doPush);
  emxInit_real_T(sp, &pStruct->T, 1, doPush);
  emxInit_real_T1(sp, &pStruct->A, 2, doPush);
  emxInit_real_T1(sp, &pStruct->B, 2, doPush);
  emxInit_real_T(sp, &pStruct->YA, 1, doPush);
  emxInit_real_T(sp, &pStruct->YB, 1, doPush);
  emxInit_real_T1(sp, &pStruct->YC, 2, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct1_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T1(sp, &pStruct->phi_A, 2, doPush);
  emxInit_real_T1(sp, &pStruct->phi_B, 2, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct2_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T1(sp, &pStruct->delta_val, 2, doPush);
  emxInit_real_T1(sp, &pStruct->S_sd_pert, 2, doPush);
  emxInit_real_T1(sp, &pStruct->S_pert, 2, doPush);
  emxInit_real_T1(sp, &pStruct->T_sd_pert, 2, doPush);
  emxInit_real_T1(sp, &pStruct->T_pert, 2, doPush);
  emxInit_real_T1(sp, &pStruct->Acc_Rej_Bound, 2, doPush);
  emxInit_real_T1(sp, &pStruct->R, 2, doPush);
  emxInit_real_T2(sp, &pStruct->a, 3, doPush);
  emxInit_real_T1(sp, &pStruct->delta_weights, 2, doPush);
  emxInit_real_T1(sp, &pStruct->psi_val, 2, doPush);
  emxInit_real_T(sp, &pStruct->perturbation_marker, 1, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2018a(sp, (void *)pEmxArray, (void (*)(const
      void *, void *))emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T1(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2018a(sp, (void *)pEmxArray, (void (*)(const
      void *, void *))emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T2(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2018a(sp, (void *)pEmxArray, (void (*)(const
      void *, void *))emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Phi_Data
 *                const char_T *identifier
 *                struct1_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Phi_Data,
  const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  g_emlrt_marshallIn(sp, emlrtAlias(Phi_Data), &thisId, y);
  emlrtDestroyArray(&Phi_Data);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct1_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "phi_A", "phi_B" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, &dims);
  thisId.fIdentifier = "phi_A";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "phi_A")),
                     &thisId, y->phi_A);
  thisId.fIdentifier = "phi_B";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "phi_B")),
                     &thisId, y->phi_B);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *r
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *r, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(r), &thisId);
  emlrtDestroyArray(&r);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *R
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *R, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(R), &thisId, y);
  emlrtDestroyArray(&R);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *sd_S_nom
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *sd_S_nom,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(sd_S_nom), &thisId, y);
  emlrtDestroyArray(&sd_S_nom);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv0[1] = { true };

  int32_T iv0[1];
  int32_T i2;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv0);
  i2 = ret->size[0];
  ret->size[0] = iv0[0];
  emxEnsureCapacity_real_T2(sp, ret, i2);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv1[2] = { true, true };

  int32_T iv1[2];
  int32_T i3;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv1);
  i3 = ret->size[0] * ret->size[1];
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  emxEnsureCapacity_real_T1(sp, ret, i3);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv2[2] = { true, true };

  int32_T iv2[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv2[0],
    iv2);
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv3[2] = { false, true };

  int32_T iv3[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv3[0],
    iv3);
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[7]
 *                int32_T nlhs
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void Marginal_Perturbation_Analysis_api(const mxArray * const prhs[7], int32_T
  nlhs, const mxArray *plhs[1])
{
  struct0_T Sobol_Output;
  struct1_T Phi_Data;
  emxArray_real_T *R;
  emxArray_real_T *sd_S_nom;
  emxArray_real_T *sd_T_nom;
  struct2_T Perturbation_Output;
  real_T r;
  real_T m;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct0_T(&st, &Sobol_Output, true);
  emxInitStruct_struct1_T(&st, &Phi_Data, true);
  emxInit_real_T1(&st, &R, 2, true);
  emxInit_real_T1(&st, &sd_S_nom, 2, true);
  emxInit_real_T1(&st, &sd_T_nom, 2, true);
  emxInitStruct_struct2_T(&st, &Perturbation_Output, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "Sobol_Output", &Sobol_Output);
  f_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Phi_Data", &Phi_Data);
  r = h_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "r");
  m = h_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "m");
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "R", R);
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "sd_S_nom", sd_S_nom);
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "sd_T_nom", sd_T_nom);

  /* Invoke the target function */
  Marginal_Perturbation_Analysis(&Sobol_Output, &Phi_Data, r, m, R, sd_S_nom,
    sd_T_nom, &Perturbation_Output);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, &Perturbation_Output);
  emxFreeStruct_struct2_T(&st, &Perturbation_Output);
  sd_T_nom->canFreeData = false;
  emxFree_real_T(&st, &sd_T_nom);
  sd_S_nom->canFreeData = false;
  emxFree_real_T(&st, &sd_S_nom);
  R->canFreeData = false;
  emxFree_real_T(&st, &R);
  emxFreeStruct_struct1_T(&st, &Phi_Data);
  emxFreeStruct_struct0_T(&st, &Sobol_Output);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Marginal_Perturbation_Analysis_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  Marginal_Perturbation_Analysis_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Marginal_Perturbation_Analysis_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Marginal_Perturbation_Analysis_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_Marginal_Perturbation_Analysis_api.c
 *
 * [EOF]
 */
