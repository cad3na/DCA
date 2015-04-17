/*
 * SlotineAdaptableMotor.c
 *
 * Real-Time Workshop code generation for Simulink model "SlotineAdaptableMotor.mdl".
 *
 * Model Version              : 1.22
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Apr 16 11:46:18 2015
 */

#include "SlotineAdaptableMotor.h"
#include "SlotineAdaptableMotor_private.h"
#include <stdio.h>
#include "SlotineAdaptableMotor_dt.h"

/* Block signals (auto storage) */
BlockIO_SlotineAdaptableMotor SlotineAdaptableMotor_B;

/* Continuous states */
ContinuousStates_SlotineAdaptableMotor SlotineAdaptableMotor_X;

/* Block states (auto storage) */
D_Work_SlotineAdaptableMotor SlotineAdaptableMotor_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_SlotineAdaptableMotor SlotineAdaptableMotor_PrevZCSigState;

/* Real-time model */
RT_MODEL_SlotineAdaptableMotor SlotineAdaptableMotor_M_;
RT_MODEL_SlotineAdaptableMotor *SlotineAdaptableMotor_M =
  &SlotineAdaptableMotor_M_;

/* This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  SlotineAdaptableMotor_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void SlotineAdaptableMotor_output(int_T tid)
{
  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SlotineAdaptableMotor_M)) {
    SlotineAdaptableMotor_M->Timing.t[0] = rtsiGetT
      (&SlotineAdaptableMotor_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(SlotineAdaptableMotor_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&SlotineAdaptableMotor_M->solverInfo,
                          ((SlotineAdaptableMotor_M->Timing.clockTick0+1)*
      SlotineAdaptableMotor_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Integrator Block: '<S2>/Integrator1'
   */
  SlotineAdaptableMotor_B.Integrator1 =
    SlotineAdaptableMotor_X.Integrator1_CSTATE;

  /* Signum: '<Root>/Sign' */
  SlotineAdaptableMotor_B.Sign = rt_SGN(SlotineAdaptableMotor_B.Integrator1);

  /* Integrator Block: '<Root>/Integrator'
   */
  if (rtmIsMajorTimeStep(SlotineAdaptableMotor_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &SlotineAdaptableMotor_PrevZCSigState.Integrator_ZCE,
                       SlotineAdaptableMotor_B.Sign);

    /* evaluate zero-crossings */
    if (zcEvent) {
      SlotineAdaptableMotor_X.Integrator_CSTATE =
        SlotineAdaptableMotor_P.Integrator_IC;
    }
  }

  SlotineAdaptableMotor_B.Integrator = SlotineAdaptableMotor_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(SlotineAdaptableMotor_M) &&
      SlotineAdaptableMotor_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* Level1 S-Function Block: '<S7>/Int Decod' (stgenc) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[0];
      real_T *sfcnU = ssGetU(rts);
      real_T *sfcnX = ssGetContStates(rts);
      real_T *sfcnY = &(SlotineAdaptableMotor_B.IntDecod[0]);
      sfcnOutputsLevel1(sfcnY, sfcnX, sfcnU, rts, 1);
    }

    /* Gain: '<S4>/Gain' */
    SlotineAdaptableMotor_B.Gain = SlotineAdaptableMotor_P.Gain_Gain *
      SlotineAdaptableMotor_B.IntDecod[0];
  }

  /* Sum: '<Root>/Sum1' */
  SlotineAdaptableMotor_B.Sum1 = SlotineAdaptableMotor_B.Integrator1 -
    SlotineAdaptableMotor_B.Gain;

  /* Sum: '<S1>/Sum' */
  SlotineAdaptableMotor_B.Sum = SlotineAdaptableMotor_B.Gain -
    SlotineAdaptableMotor_B.Integrator1;

  /* Gain: '<S1>/Gain' */
  SlotineAdaptableMotor_B.Gain_c = SlotineAdaptableMotor_P.Gain_Gain_j *
    SlotineAdaptableMotor_B.Sum;

  /* Integrator Block: '<S2>/Integrator'
   */
  SlotineAdaptableMotor_B.Integrator_a =
    SlotineAdaptableMotor_X.Integrator_CSTATE_f;

  /* Sum: '<S1>/Sum2' */
  SlotineAdaptableMotor_B.Sum2 = SlotineAdaptableMotor_B.Integrator_a -
    SlotineAdaptableMotor_B.Gain_c;

  /* Integrator Block: '<S3>/Integrator'
   */
  SlotineAdaptableMotor_B.Integrator_f[0] =
    SlotineAdaptableMotor_X.Integrator_CSTATE_b[0];
  SlotineAdaptableMotor_B.Integrator_f[1] =
    SlotineAdaptableMotor_X.Integrator_CSTATE_b[1];

  /* Product: '<S3>/Product1' */
  SlotineAdaptableMotor_B.Product1 = SlotineAdaptableMotor_B.Sum2 *
    SlotineAdaptableMotor_B.Integrator_f[0];

  /* TransferFcn Block: '<Root>/Filtro' */
  SlotineAdaptableMotor_B.Filtro = SlotineAdaptableMotor_P.Filtro_C*
    SlotineAdaptableMotor_X.Filtro_CSTATE;

  /* Sum: '<S1>/Sum1' */
  SlotineAdaptableMotor_B.Sum1_k = SlotineAdaptableMotor_B.Filtro -
    SlotineAdaptableMotor_B.Integrator_a;

  /* Gain: '<S1>/Gain1' */
  SlotineAdaptableMotor_B.Gain1 = SlotineAdaptableMotor_P.Gain1_Gain *
    SlotineAdaptableMotor_B.Sum1_k;

  /* Gain: '<S2>/g2' */
  SlotineAdaptableMotor_B.g2 = SlotineAdaptableMotor_P.g2_Gain *
    SlotineAdaptableMotor_B.Integrator_a;

  /* TransferFcn Block: '<S2>/Transfer Fcn' */
  SlotineAdaptableMotor_B.TransferFcn = SlotineAdaptableMotor_P.TransferFcn_C*
    SlotineAdaptableMotor_X.TransferFcn_CSTATE;

  /* Sum: '<S2>/Sum' */
  SlotineAdaptableMotor_B.Sum_n = SlotineAdaptableMotor_B.TransferFcn -
    SlotineAdaptableMotor_B.Integrator1;

  /* Gain: '<S2>/g1' */
  SlotineAdaptableMotor_B.g1 = SlotineAdaptableMotor_P.g1_Gain *
    SlotineAdaptableMotor_B.Sum_n;

  /* Sum: '<S2>/Sum1' */
  SlotineAdaptableMotor_B.Sum1_e = SlotineAdaptableMotor_B.g1 -
    SlotineAdaptableMotor_B.g2;

  /* Sum: '<S1>/Sum3' */
  SlotineAdaptableMotor_B.Sum3 = SlotineAdaptableMotor_B.Sum1_e -
    SlotineAdaptableMotor_B.Gain1;

  /* Product: '<S3>/Product2' */
  SlotineAdaptableMotor_B.Product2 = SlotineAdaptableMotor_B.Integrator_f[1] *
    SlotineAdaptableMotor_B.Sum3;

  /* Sum: '<S1>/Sum4' */
  SlotineAdaptableMotor_B.Sum4 = SlotineAdaptableMotor_B.Filtro -
    SlotineAdaptableMotor_B.Sum2;

  /* Gain: '<Root>/Gain' */
  SlotineAdaptableMotor_B.Gain_p = SlotineAdaptableMotor_P.Gain_Gain_m *
    SlotineAdaptableMotor_B.Sum4;

  /* Sum: '<Root>/Sum' */
  SlotineAdaptableMotor_B.Sum_a = (SlotineAdaptableMotor_B.Product1 +
    SlotineAdaptableMotor_B.Product2) - SlotineAdaptableMotor_B.Gain_p;

  /* Gain: '<Root>/Gain1' */
  SlotineAdaptableMotor_B.Gain1_c = SlotineAdaptableMotor_P.Gain1_Gain_g *
    SlotineAdaptableMotor_B.Sum1;

  /* Math: '<S3>/Math Function' */
  SlotineAdaptableMotor_B.MathFunction = exp
    (SlotineAdaptableMotor_B.Integrator_f[1]);

  /* Product: '<S3>/Product3' */
  SlotineAdaptableMotor_B.Product3 = SlotineAdaptableMotor_B.MathFunction *
    SlotineAdaptableMotor_B.Integrator_f[0];

  {
    real_T tmp;
    real_T tmp_0;

    /* Gain: '<S3>/Gain' */
    tmp = SlotineAdaptableMotor_B.Sum2;
    tmp_0 = SlotineAdaptableMotor_B.Sum3;
    SlotineAdaptableMotor_B.Gain_i[0] = SlotineAdaptableMotor_P.Gain_Gain_f[0] *
      tmp;
    SlotineAdaptableMotor_B.Gain_i[1] = SlotineAdaptableMotor_P.Gain_Gain_f[1] *
      tmp_0;

    /* Product: '<S3>/Product' */
    SlotineAdaptableMotor_B.Product[0] = SlotineAdaptableMotor_B.Gain_i[0] *
      SlotineAdaptableMotor_B.Sum4;
    SlotineAdaptableMotor_B.Product[1] = SlotineAdaptableMotor_B.Gain_i[1] *
      SlotineAdaptableMotor_B.Sum4;

    /* Math: '<Root>/Math Function' */
    SlotineAdaptableMotor_B.MathFunction_o = SlotineAdaptableMotor_B.Gain1_c *
      SlotineAdaptableMotor_B.Gain1_c;
  }

  if (rtmIsMajorTimeStep(SlotineAdaptableMotor_M) &&
      SlotineAdaptableMotor_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* Level1 S-Function Block: '<S5>/Int AD' (stgad) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[1];
      real_T *sfcnU = ssGetU(rts);
      real_T *sfcnX = ssGetContStates(rts);
      real_T *sfcnY = &(SlotineAdaptableMotor_B.IntAD[0]);
      sfcnOutputsLevel1(sfcnY, sfcnX, sfcnU, rts, 1);
    }

    /* Gain: '<S4>/Gain1' */
    SlotineAdaptableMotor_B.Gain1_e = SlotineAdaptableMotor_P.Gain1_Gain_p *
      SlotineAdaptableMotor_B.IntAD[0];

    /* Level1 S-Function Block: '<S6>/Int AD' (stgda) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[2];
      real_T *sfcnU = ssGetU(rts);
      real_T *sfcnX = ssGetContStates(rts);
      sfcnOutputsLevel1(NULL, sfcnX, sfcnU, rts, 1);
    }
  }

  /* SignalGenerator Block: '<Root>/Signal Generator'
   */
  {
    real_T sin2PiFT = sin(6.2831853071795862E+000*
                          SlotineAdaptableMotor_P.SignalGenerator_Frequency*
                          SlotineAdaptableMotor_M->Timing.t[0]);
    SlotineAdaptableMotor_B.SignalGenerator =
      SlotineAdaptableMotor_P.SignalGenerator_Amplitude*sin2PiFT;
  }

  {
    real_T currentTime;

    /* Step: '<Root>/Step' */
    currentTime = SlotineAdaptableMotor_M->Timing.t[0];
    if (currentTime < SlotineAdaptableMotor_P.Step_Time) {
      SlotineAdaptableMotor_B.Step = SlotineAdaptableMotor_P.Step_Y0;
    } else {
      SlotineAdaptableMotor_B.Step = SlotineAdaptableMotor_P.Step_YFinal;
    }
  }

  if (rtmIsMajorTimeStep(SlotineAdaptableMotor_M) &&
      SlotineAdaptableMotor_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* Stop Block: '<Root>/Stop Simulation'
     */
    if (SlotineAdaptableMotor_B.Step != 0.0) {
      rtmSetStopRequested(SlotineAdaptableMotor_M, 1);
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void SlotineAdaptableMotor_update(int_T tid)
{
  if (rtmIsMajorTimeStep(SlotineAdaptableMotor_M) &&
      SlotineAdaptableMotor_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* Level1 S-Function Block: '<S7>/Int Decod' (stgenc) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[0];
      real_T *sfcnU = ssGetU(rts);
      real_T *sfcnX = ssGetContStates(rts);
      sfcnUpdateLevel1(sfcnX, sfcnU, rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* Level1 S-Function Block: '<S5>/Int AD' (stgad) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[1];
      real_T *sfcnU = ssGetU(rts);
      real_T *sfcnX = ssGetContStates(rts);
      sfcnUpdateLevel1(sfcnX, sfcnU, rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* Level1 S-Function Block: '<S6>/Int AD' (stgda) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[2];
      real_T *sfcnU = ssGetU(rts);
      real_T *sfcnX = ssGetContStates(rts);
      sfcnUpdateLevel1(sfcnX, sfcnU, rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }
  }

  if (rtmIsMajorTimeStep(SlotineAdaptableMotor_M)) {
    rt_ertODEUpdateContinuousStates(&SlotineAdaptableMotor_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++SlotineAdaptableMotor_M->Timing.clockTick0))
    ++SlotineAdaptableMotor_M->Timing.clockTickH0;
  SlotineAdaptableMotor_M->Timing.t[0] =
    SlotineAdaptableMotor_M->Timing.clockTick0 *
    SlotineAdaptableMotor_M->Timing.stepSize0 +
    SlotineAdaptableMotor_M->Timing.clockTickH0 *
    SlotineAdaptableMotor_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(SlotineAdaptableMotor_M) &&
      SlotineAdaptableMotor_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++SlotineAdaptableMotor_M->Timing.clockTick1))
      ++SlotineAdaptableMotor_M->Timing.clockTickH1;
    SlotineAdaptableMotor_M->Timing.t[1] =
      SlotineAdaptableMotor_M->Timing.clockTick1 *
      SlotineAdaptableMotor_M->Timing.stepSize1 +
      SlotineAdaptableMotor_M->Timing.clockTickH1 *
      SlotineAdaptableMotor_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void SlotineAdaptableMotor_derivatives(void)
{
  /* Integrator Block: '<S2>/Integrator1' */
  {
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->Integrator1_CSTATE =
      SlotineAdaptableMotor_B.Integrator_a;
  }

  /* Integrator Block: '<Root>/Integrator' */
  {
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->Integrator_CSTATE =
      SlotineAdaptableMotor_B.MathFunction_o;
  }

  /* Integrator Block: '<S2>/Integrator' */
  {
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->Integrator_CSTATE_f =
      SlotineAdaptableMotor_B.Sum1_e;
  }

  /* Integrator Block: '<S3>/Integrator' */
  {
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->Integrator_CSTATE_b[0] =
      SlotineAdaptableMotor_B.Product[0];
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->Integrator_CSTATE_b[1] =
      SlotineAdaptableMotor_B.Product[1];
  }

  /* TransferFcn Block: '<Root>/Filtro' */
  {
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->Filtro_CSTATE =
      SlotineAdaptableMotor_B.Gain1_e;
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->Filtro_CSTATE +=
      (SlotineAdaptableMotor_P.Filtro_A)*SlotineAdaptableMotor_X.Filtro_CSTATE;
  }

  /* TransferFcn Block: '<S2>/Transfer Fcn' */
  {
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->TransferFcn_CSTATE =
      SlotineAdaptableMotor_B.SignalGenerator;
    ((StateDerivatives_SlotineAdaptableMotor *)
      SlotineAdaptableMotor_M->ModelData.derivs)->TransferFcn_CSTATE +=
      (SlotineAdaptableMotor_P.TransferFcn_A)*
      SlotineAdaptableMotor_X.TransferFcn_CSTATE;
  }
}

/* Model initialize function */
void SlotineAdaptableMotor_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)SlotineAdaptableMotor_M,0,
                sizeof(RT_MODEL_SlotineAdaptableMotor));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SlotineAdaptableMotor_M->solverInfo,
                          &SlotineAdaptableMotor_M->Timing.simTimeStep);
    rtsiSetTPtr(&SlotineAdaptableMotor_M->solverInfo, &rtmGetTPtr
                (SlotineAdaptableMotor_M));
    rtsiSetStepSizePtr(&SlotineAdaptableMotor_M->solverInfo,
                       &SlotineAdaptableMotor_M->Timing.stepSize0);
    rtsiSetdXPtr(&SlotineAdaptableMotor_M->solverInfo,
                 &SlotineAdaptableMotor_M->ModelData.derivs);
    rtsiSetContStatesPtr(&SlotineAdaptableMotor_M->solverInfo,
                         &SlotineAdaptableMotor_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&SlotineAdaptableMotor_M->solverInfo,
      &SlotineAdaptableMotor_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&SlotineAdaptableMotor_M->solverInfo,
                          (&rtmGetErrorStatus(SlotineAdaptableMotor_M)));
    rtsiSetRTModelPtr(&SlotineAdaptableMotor_M->solverInfo,
                      SlotineAdaptableMotor_M);
  }

  rtsiSetSimTimeStep(&SlotineAdaptableMotor_M->solverInfo, MAJOR_TIME_STEP);
  SlotineAdaptableMotor_M->ModelData.intgData.f[0] =
    SlotineAdaptableMotor_M->ModelData.odeF[0];
  SlotineAdaptableMotor_M->ModelData.contStates = ((real_T *)
    &SlotineAdaptableMotor_X);
  rtsiSetSolverData(&SlotineAdaptableMotor_M->solverInfo, (void *)
                    &SlotineAdaptableMotor_M->ModelData.intgData);
  rtsiSetSolverName(&SlotineAdaptableMotor_M->solverInfo,"ode1");
  SlotineAdaptableMotor_M->solverInfoPtr = (&SlotineAdaptableMotor_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = SlotineAdaptableMotor_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    SlotineAdaptableMotor_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SlotineAdaptableMotor_M->Timing.sampleTimes =
      (&SlotineAdaptableMotor_M->Timing.sampleTimesArray[0]);
    SlotineAdaptableMotor_M->Timing.offsetTimes =
      (&SlotineAdaptableMotor_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SlotineAdaptableMotor_M->Timing.sampleTimes[0] = (0.0);
    SlotineAdaptableMotor_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    SlotineAdaptableMotor_M->Timing.offsetTimes[0] = (0.0);
    SlotineAdaptableMotor_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(SlotineAdaptableMotor_M, &SlotineAdaptableMotor_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = SlotineAdaptableMotor_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    SlotineAdaptableMotor_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SlotineAdaptableMotor_M, 10.0);
  SlotineAdaptableMotor_M->Timing.stepSize0 = 0.001;
  SlotineAdaptableMotor_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  SlotineAdaptableMotor_M->Sizes.checksums[0] = (4251550148U);
  SlotineAdaptableMotor_M->Sizes.checksums[1] = (1075484270U);
  SlotineAdaptableMotor_M->Sizes.checksums[2] = (2047355761U);
  SlotineAdaptableMotor_M->Sizes.checksums[3] = (3372331732U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    SlotineAdaptableMotor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &SlotineAdaptableMotor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo,
                        SlotineAdaptableMotor_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(SlotineAdaptableMotor_M));
  }

  SlotineAdaptableMotor_M->solverInfoPtr = (&SlotineAdaptableMotor_M->solverInfo);
  SlotineAdaptableMotor_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&SlotineAdaptableMotor_M->solverInfo, 0.001);
  rtsiSetSolverMode(&SlotineAdaptableMotor_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  SlotineAdaptableMotor_M->ModelData.blockIO = ((void *)
    &SlotineAdaptableMotor_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&SlotineAdaptableMotor_B.Integrator1);
    for (i = 0; i < 52; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  SlotineAdaptableMotor_M->ModelData.defaultParam = ((real_T *)
    &SlotineAdaptableMotor_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &SlotineAdaptableMotor_X;
    SlotineAdaptableMotor_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_SlotineAdaptableMotor));
  }

  /* states (dwork) */
  SlotineAdaptableMotor_M->Work.dwork = ((void *) &SlotineAdaptableMotor_DWork);
  (void) memset((char_T *) &SlotineAdaptableMotor_DWork,0,
                sizeof(D_Work_SlotineAdaptableMotor));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    SlotineAdaptableMotor_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &SlotineAdaptableMotor_M->NonInlinedSFcns.sfcnInfo;
    SlotineAdaptableMotor_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(SlotineAdaptableMotor_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &SlotineAdaptableMotor_M->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(SlotineAdaptableMotor_M));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(SlotineAdaptableMotor_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (SlotineAdaptableMotor_M));
    rtssSetStepSizePtr(sfcnInfo, &SlotineAdaptableMotor_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (SlotineAdaptableMotor_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &SlotineAdaptableMotor_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &SlotineAdaptableMotor_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &SlotineAdaptableMotor_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &SlotineAdaptableMotor_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &SlotineAdaptableMotor_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &SlotineAdaptableMotor_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &SlotineAdaptableMotor_M->solverInfoPtr);
  }

  SlotineAdaptableMotor_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)
                  &SlotineAdaptableMotor_M->NonInlinedSFcns.childSFunctions[0],0,
                  3*sizeof(SimStruct));
    SlotineAdaptableMotor_M->childSfunctions =
      (&SlotineAdaptableMotor_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    SlotineAdaptableMotor_M->childSfunctions[0] =
      (&SlotineAdaptableMotor_M->NonInlinedSFcns.childSFunctions[0]);
    SlotineAdaptableMotor_M->childSfunctions[1] =
      (&SlotineAdaptableMotor_M->NonInlinedSFcns.childSFunctions[1]);
    SlotineAdaptableMotor_M->childSfunctions[2] =
      (&SlotineAdaptableMotor_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level1 S-Function Block: SlotineAdaptableMotor/<S7>/Int Decod (stgenc) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &SlotineAdaptableMotor_M->NonInlinedSFcns.blkInfo2
                         [0]);
        ssSetRTWSfcnInfo(rts, SlotineAdaptableMotor_M->sfcnInfo);
      }

      /* outputs */
      ssSetY(rts, ((real_T *) SlotineAdaptableMotor_B.IntDecod));

      /* path info */
      ssSetModelName(rts, "Int Decod");
      ssSetPath(rts, "SlotineAdaptableMotor/Servo/Interfaz Encoders/Int Decod");
      ssSetRTModel(rts,SlotineAdaptableMotor_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL1);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &SlotineAdaptableMotor_P.IntDecod_P1_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &SlotineAdaptableMotor_DWork.IntDecod_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn0.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SlotineAdaptableMotor_DWork.IntDecod_IWORK);
      }

      /* registration */
      stgenc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);
    }

    /* Level1 S-Function Block: SlotineAdaptableMotor/<S5>/Int AD (stgad) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &SlotineAdaptableMotor_M->NonInlinedSFcns.blkInfo2
                         [1]);
        ssSetRTWSfcnInfo(rts, SlotineAdaptableMotor_M->sfcnInfo);
      }

      /* outputs */
      ssSetY(rts, ((real_T *) SlotineAdaptableMotor_B.IntAD));

      /* path info */
      ssSetModelName(rts, "Int AD");
      ssSetPath(rts, "SlotineAdaptableMotor/Servo/Interfaz AD/Int AD");
      ssSetRTModel(rts,SlotineAdaptableMotor_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL1);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&SlotineAdaptableMotor_P.IntAD_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&SlotineAdaptableMotor_P.IntAD_P2_Size
                       [0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &SlotineAdaptableMotor_DWork.IntAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SlotineAdaptableMotor_DWork.IntAD_IWORK[0]);
      }

      /* registration */
      stgad(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);
    }

    /* Level1 S-Function Block: SlotineAdaptableMotor/<S6>/Int AD (stgda) */
    {
      SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &SlotineAdaptableMotor_M->NonInlinedSFcns.blkInfo2
                         [2]);
        ssSetRTWSfcnInfo(rts, SlotineAdaptableMotor_M->sfcnInfo);
      }

      /* inputs */
      ssSetU(rts, (void *)&SlotineAdaptableMotor_B.Sum_a);

      /* path info */
      ssSetModelName(rts, "Int AD");
      ssSetPath(rts, "SlotineAdaptableMotor/Servo/Interfaz DA /Int AD");
      ssSetRTModel(rts,SlotineAdaptableMotor_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL1);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &SlotineAdaptableMotor_P.IntAD_P1_Size_a[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &SlotineAdaptableMotor_P.IntAD_P2_Size_h[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&SlotineAdaptableMotor_P.IntAD_P3_Size
                       [0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &SlotineAdaptableMotor_DWork.IntAD_IWORK_n);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SlotineAdaptableMotor_M->NonInlinedSFcns.Sfcn2.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SlotineAdaptableMotor_DWork.IntAD_IWORK_n);
      }

      /* registration */
      stgda(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);
    }
  }

  SlotineAdaptableMotor_PrevZCSigState.Integrator_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void SlotineAdaptableMotor_terminate(void)
{
  /* Level1 S-Function Block: '<S7>/Int Decod' (stgenc) */
  {
    SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level1 S-Function Block: '<S5>/Int AD' (stgad) */
  {
    SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level1 S-Function Block: '<S6>/Int AD' (stgda) */
  {
    SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* S-Function Block: <Root>/Servo (multiqtb) */
  {
    MQ_tbSetTimerPeriod(0x320, 0, 0.0);
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  SlotineAdaptableMotor_output(tid);
}

void MdlUpdate(int_T tid)
{
  SlotineAdaptableMotor_update(tid);
}

void MdlInitializeSizes(void)
{
  SlotineAdaptableMotor_M->Sizes.numContStates = (7);/* Number of continuous states */
  SlotineAdaptableMotor_M->Sizes.numY = (0);/* Number of model outputs */
  SlotineAdaptableMotor_M->Sizes.numU = (0);/* Number of model inputs */
  SlotineAdaptableMotor_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  SlotineAdaptableMotor_M->Sizes.numSampTimes = (2);/* Number of sample times */
  SlotineAdaptableMotor_M->Sizes.numBlocks = (48);/* Number of blocks */
  SlotineAdaptableMotor_M->Sizes.numBlockIO = (35);/* Number of block outputs */
  SlotineAdaptableMotor_M->Sizes.numBlockPrms = (41);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Integrator Block: '<S2>/Integrator1' */
  SlotineAdaptableMotor_X.Integrator1_CSTATE =
    SlotineAdaptableMotor_P.Integrator1_IC;

  /* Integrator Block: '<Root>/Integrator' */
  SlotineAdaptableMotor_X.Integrator_CSTATE =
    SlotineAdaptableMotor_P.Integrator_IC;

  /* Level1 S-Function Block: '<S7>/Int Decod' (stgenc) */
  {
    SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[0];
    real_T *sfcnX = ssGetContStates(rts);
    sfcnInitializeConditionsLevel1(sfcnX, rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Integrator Block: '<S2>/Integrator' */
  SlotineAdaptableMotor_X.Integrator_CSTATE_f =
    SlotineAdaptableMotor_P.Integrator_IC_c;

  /* Integrator Block: '<S3>/Integrator' */
  SlotineAdaptableMotor_X.Integrator_CSTATE_b[0] =
    SlotineAdaptableMotor_P.Integrator_IC_m;
  SlotineAdaptableMotor_X.Integrator_CSTATE_b[1] =
    SlotineAdaptableMotor_P.Integrator_IC_m;

  /* TransferFcn Block: '<Root>/Filtro' */
  SlotineAdaptableMotor_X.Filtro_CSTATE = 0.0;

  /* TransferFcn Block: '<S2>/Transfer Fcn' */
  SlotineAdaptableMotor_X.TransferFcn_CSTATE = 0.0;

  /* Level1 S-Function Block: '<S5>/Int AD' (stgad) */
  {
    SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[1];
    real_T *sfcnX = ssGetContStates(rts);
    sfcnInitializeConditionsLevel1(sfcnX, rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level1 S-Function Block: '<S6>/Int AD' (stgda) */
  {
    SimStruct *rts = SlotineAdaptableMotor_M->childSfunctions[2];
    real_T *sfcnX = ssGetContStates(rts);
    sfcnInitializeConditionsLevel1(sfcnX, rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }
}

void MdlStart(void)
{
  MdlInitialize();
}

RT_MODEL_SlotineAdaptableMotor *SlotineAdaptableMotor(void)
{
  SlotineAdaptableMotor_initialize(1);
  return SlotineAdaptableMotor_M;
}

void MdlTerminate(void)
{
  SlotineAdaptableMotor_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
#include "WinConLibrary.h"

/*************************************************************************
 *
 *  Name:      MdlRegister
 *
 *  Format:    void MdlRegister( void )
 *
 *  Purpose:   Register variables, plots, etc. in WinCon so that they are available
 *             for plotting, saving, etc. Individual blocks can register
 *             variables in WinCon by providing a "Register(block, system)"
 *             function within the block TLC file. For example, see the
 *             WinCon versions of:
 *
 *                     scope.tlc, display.tlc, towks.tlc
 *
 *             Variable names should include the full path name so that
 *             WinCon can decipher the hierarchy in which the variable
 *             appears. Vectors should be indexed (eg. "Motor Voltage[0]")
 *             and each element registered separately. For example, for a
 *             Scope titled "Motor Voltages" within the "Controller"
 *             subsystem and model "Test", the first motor voltage would
 *             be referred to as:
 *
 *                     "Test\vController\vMotor Voltages[0]"
 *
 *             Note that subsystems are separated by vertical tabs (\v).
 *
 **************************************************************************/
void MdlRegister( void )
{
  /****************************************************
   ************ Plots and Their Variables *************
   ****************************************************/

  /* Scope Block: <Root>/IEC */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vIEC",
                       &SlotineAdaptableMotor_B.Integrator);
    WCRegisterScope("SlotineAdaptableMotor\vIEC", 1
                    , &SlotineAdaptableMotor_B.Integrator
                    );
  }

  /* Scope Block: <Root>/q */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vq", &SlotineAdaptableMotor_B.Gain);
    WCRegisterScope("SlotineAdaptableMotor\vq", 1
                    , &SlotineAdaptableMotor_B.Gain
                    );
  }

  /* Scope Block: <Root>/q - qd */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vq - qd",
                       &SlotineAdaptableMotor_B.Sum1);
    WCRegisterScope("SlotineAdaptableMotor\vq - qd", 1
                    , &SlotineAdaptableMotor_B.Sum1
                    );
  }

  /* Scope Block: <Root>/q qd */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vq qd[0]",
                       &SlotineAdaptableMotor_B.Integrator1);
    WCRegisterVariable("SlotineAdaptableMotor\vq qd[1]",
                       &SlotineAdaptableMotor_B.Gain);
    WCRegisterScope("SlotineAdaptableMotor\vq qd", 2
                    , &SlotineAdaptableMotor_B.Integrator1
                    , &SlotineAdaptableMotor_B.Gain
                    );
  }

  /* Scope Block: <Root>/u */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vu",
                       &SlotineAdaptableMotor_B.Sum_a);
    WCRegisterScope("SlotineAdaptableMotor\vu", 1
                    , &SlotineAdaptableMotor_B.Sum_a
                    );
  }

  /* Scope Block: <S2>/qdmed */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vqdmed",
                       &SlotineAdaptableMotor_B.Integrator1);
    WCRegisterScope("SlotineAdaptableMotor\vGeneracion de trayectorias\vqdmed",
                    1
                    , &SlotineAdaptableMotor_B.Integrator1
                    );
  }

  /* Scope Block: <S2>/qdpmed */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vqdpmed",
                       &SlotineAdaptableMotor_B.Integrator_a);
    WCRegisterScope("SlotineAdaptableMotor\vGeneracion de trayectorias\vqdpmed",
                    1
                    , &SlotineAdaptableMotor_B.Integrator_a
                    );
  }

  /* Scope Block: <S2>/qdppmed */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vqdppmed",
                       &SlotineAdaptableMotor_B.Sum1_e);
    WCRegisterScope("SlotineAdaptableMotor\vGeneracion de trayectorias\vqdppmed",
                    1
                    , &SlotineAdaptableMotor_B.Sum1_e
                    );
  }

  /* Scope Block: <S3>/a */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\va",
                       &SlotineAdaptableMotor_B.Product3);
    WCRegisterScope("SlotineAdaptableMotor\vLey de adaptacion\va", 1
                    , &SlotineAdaptableMotor_B.Product3
                    );
  }

  /* Scope Block: <S3>/b */
  {
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vb",
                       &SlotineAdaptableMotor_B.MathFunction);
    WCRegisterScope("SlotineAdaptableMotor\vLey de adaptacion\vb", 1
                    , &SlotineAdaptableMotor_B.MathFunction
                    );
  }

  /****************************************************
   ************** Block Output Variables **************
   ****************************************************/
  {
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vIntegrator1",
                       &SlotineAdaptableMotor_B.Integrator1);
    WCRegisterVariable("SlotineAdaptableMotor\vSign",
                       &SlotineAdaptableMotor_B.Sign);
    WCRegisterVariable("SlotineAdaptableMotor\vIntegrator",
                       &SlotineAdaptableMotor_B.Integrator);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod[0]",
                       &SlotineAdaptableMotor_B.IntDecod[0] + 0);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod[1]",
                       &SlotineAdaptableMotor_B.IntDecod[0] + 1);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod[2]",
                       &SlotineAdaptableMotor_B.IntDecod[0] + 2);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod[3]",
                       &SlotineAdaptableMotor_B.IntDecod[0] + 3);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod[4]",
                       &SlotineAdaptableMotor_B.IntDecod[0] + 4);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod[5]",
                       &SlotineAdaptableMotor_B.IntDecod[0] + 5);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod[6]",
                       &SlotineAdaptableMotor_B.IntDecod[0] + 6);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod[7]",
                       &SlotineAdaptableMotor_B.IntDecod[0] + 7);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vGain",
                       &SlotineAdaptableMotor_B.Gain);
    WCRegisterVariable("SlotineAdaptableMotor\vSum1",
                       &SlotineAdaptableMotor_B.Sum1);
    WCRegisterVariable("SlotineAdaptableMotor\vAlgoritmo de Slotine\vSum",
                       &SlotineAdaptableMotor_B.Sum);
    WCRegisterVariable("SlotineAdaptableMotor\vAlgoritmo de Slotine\vGain",
                       &SlotineAdaptableMotor_B.Gain_c);
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vIntegrator",
                       &SlotineAdaptableMotor_B.Integrator_a);
    WCRegisterVariable("SlotineAdaptableMotor\vAlgoritmo de Slotine\vSum2",
                       &SlotineAdaptableMotor_B.Sum2);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vIntegrator[0]",
                       &SlotineAdaptableMotor_B.Integrator_f[0] + 0);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vIntegrator[1]",
                       &SlotineAdaptableMotor_B.Integrator_f[0] + 1);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vProduct1",
                       &SlotineAdaptableMotor_B.Product1);
    WCRegisterVariable("SlotineAdaptableMotor\vFiltro",
                       &SlotineAdaptableMotor_B.Filtro);
    WCRegisterVariable("SlotineAdaptableMotor\vAlgoritmo de Slotine\vSum1",
                       &SlotineAdaptableMotor_B.Sum1_k);
    WCRegisterVariable("SlotineAdaptableMotor\vAlgoritmo de Slotine\vGain1",
                       &SlotineAdaptableMotor_B.Gain1);
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vg2",
                       &SlotineAdaptableMotor_B.g2);
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vTransfer Fcn",
                       &SlotineAdaptableMotor_B.TransferFcn);
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vSum",
                       &SlotineAdaptableMotor_B.Sum_n);
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vg1",
                       &SlotineAdaptableMotor_B.g1);
    WCRegisterVariable("SlotineAdaptableMotor\vGeneracion de trayectorias\vSum1",
                       &SlotineAdaptableMotor_B.Sum1_e);
    WCRegisterVariable("SlotineAdaptableMotor\vAlgoritmo de Slotine\vSum3",
                       &SlotineAdaptableMotor_B.Sum3);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vProduct2",
                       &SlotineAdaptableMotor_B.Product2);
    WCRegisterVariable("SlotineAdaptableMotor\vAlgoritmo de Slotine\vSum4",
                       &SlotineAdaptableMotor_B.Sum4);
    WCRegisterVariable("SlotineAdaptableMotor\vGain",
                       &SlotineAdaptableMotor_B.Gain_p);
    WCRegisterVariable("SlotineAdaptableMotor\vSum",
                       &SlotineAdaptableMotor_B.Sum_a);
    WCRegisterVariable("SlotineAdaptableMotor\vGain1",
                       &SlotineAdaptableMotor_B.Gain1_c);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vMath Function",
                       &SlotineAdaptableMotor_B.MathFunction);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vProduct3",
                       &SlotineAdaptableMotor_B.Product3);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vGain[0]",
                       &SlotineAdaptableMotor_B.Gain_i[0] + 0);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vGain[1]",
                       &SlotineAdaptableMotor_B.Gain_i[0] + 1);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vProduct[0]",
                       &SlotineAdaptableMotor_B.Product[0] + 0);
    WCRegisterVariable("SlotineAdaptableMotor\vLey de adaptacion\vProduct[1]",
                       &SlotineAdaptableMotor_B.Product[0] + 1);
    WCRegisterVariable("SlotineAdaptableMotor\vMath Function",
                       &SlotineAdaptableMotor_B.MathFunction_o);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD[0]",
                       &SlotineAdaptableMotor_B.IntAD[0] + 0);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD[1]",
                       &SlotineAdaptableMotor_B.IntAD[0] + 1);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD[2]",
                       &SlotineAdaptableMotor_B.IntAD[0] + 2);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD[3]",
                       &SlotineAdaptableMotor_B.IntAD[0] + 3);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD[4]",
                       &SlotineAdaptableMotor_B.IntAD[0] + 4);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD[5]",
                       &SlotineAdaptableMotor_B.IntAD[0] + 5);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD[6]",
                       &SlotineAdaptableMotor_B.IntAD[0] + 6);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD[7]",
                       &SlotineAdaptableMotor_B.IntAD[0] + 7);
    WCRegisterVariable("SlotineAdaptableMotor\vServo\vGain1",
                       &SlotineAdaptableMotor_B.Gain1_e);
    WCRegisterVariable("SlotineAdaptableMotor\vSignal Generator",
                       &SlotineAdaptableMotor_B.SignalGenerator);
    WCRegisterVariable("SlotineAdaptableMotor\vStep",
                       &SlotineAdaptableMotor_B.Step);
  }

  /****************************************************
   ***************** Block Parameters *****************
   ****************************************************/
  {
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vGeneracion de trayectorias\vIntegrator1\vInitialCondition",
      &SlotineAdaptableMotor_P.Integrator1_IC);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vIntegrator\vInitialCondition",
      &SlotineAdaptableMotor_P.Integrator_IC);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vServo\vInterfaz Encoders\vInt Decod\vP1",
      &SlotineAdaptableMotor_P.IntDecod_P1);
    WCRegisterScalarParameter("SlotineAdaptableMotor\vServo\vGain\vGain",
      &SlotineAdaptableMotor_P.Gain_Gain);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vAlgoritmo de Slotine\vGain\vGain",
      &SlotineAdaptableMotor_P.Gain_Gain_j);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vGeneracion de trayectorias\vIntegrator\vInitialCondition",
      &SlotineAdaptableMotor_P.Integrator_IC_c);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vLey de adaptacion\vIntegrator\vInitialCondition",
      &SlotineAdaptableMotor_P.Integrator_IC_m);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vAlgoritmo de Slotine\vGain1\vGain",
      &SlotineAdaptableMotor_P.Gain1_Gain);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vGeneracion de trayectorias\vg2\vGain",
      &SlotineAdaptableMotor_P.g2_Gain);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vGeneracion de trayectorias\vg1\vGain",
      &SlotineAdaptableMotor_P.g1_Gain);
    WCRegisterScalarParameter("SlotineAdaptableMotor\vGain\vGain",
      &SlotineAdaptableMotor_P.Gain_Gain_m);
    WCRegisterScalarParameter("SlotineAdaptableMotor\vGain1\vGain",
      &SlotineAdaptableMotor_P.Gain1_Gain_g);
    WCRegisterVectorParameter(
      "SlotineAdaptableMotor\vLey de adaptacion\vGain\vGain", 2,
      &SlotineAdaptableMotor_P.Gain_Gain_f[0]);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD\vP1",
      &SlotineAdaptableMotor_P.IntAD_P1);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vServo\vInterfaz AD\vInt AD\vP2",
      &SlotineAdaptableMotor_P.IntAD_P2);
    WCRegisterScalarParameter("SlotineAdaptableMotor\vServo\vGain1\vGain",
      &SlotineAdaptableMotor_P.Gain1_Gain_p);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vServo\vInterfaz DA \vInt AD\vP1",
      &SlotineAdaptableMotor_P.IntAD_P1_i);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vServo\vInterfaz DA \vInt AD\vP2",
      &SlotineAdaptableMotor_P.IntAD_P2_o);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vServo\vInterfaz DA \vInt AD\vP3",
      &SlotineAdaptableMotor_P.IntAD_P3);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vSignal Generator\vAmplitude",
      &SlotineAdaptableMotor_P.SignalGenerator_Amplitude);
    WCRegisterScalarParameter(
      "SlotineAdaptableMotor\vSignal Generator\vFrequency",
      &SlotineAdaptableMotor_P.SignalGenerator_Frequency);
    WCRegisterScalarParameter("SlotineAdaptableMotor\vStep\vTime",
      &SlotineAdaptableMotor_P.Step_Time);
    WCRegisterScalarParameter("SlotineAdaptableMotor\vStep\vBefore",
      &SlotineAdaptableMotor_P.Step_Y0);
    WCRegisterScalarParameter("SlotineAdaptableMotor\vStep\vAfter",
      &SlotineAdaptableMotor_P.Step_YFinal);
  }
}

/*************************************************************************
 *
 *  Name:      MdlChecksum
 *
 *  Format:    void MdlChecksum( uint_T iValues[] )
 *
 *  Purpose:   Return the model checksum values. The checksum is used to
 *             determine whether the model has been modified.
 *
 **************************************************************************/
void MdlChecksum( uint_T iValues[4] )
{
  iValues[0] = 4251550148U;
  iValues[1] = 1075484270U;
  iValues[2] = 2047355761U;
  iValues[3] = 3372331732U;
}

/*************************************************************************
 *
 *  Name:      MdlGetNumDataTypes
 *
 *  Format:    uint_T MdlGetNumDataTypes()
 *
 *  Purpose:   Returns the number of data types in the model.
 *
 **************************************************************************/
uint_T MdlGetNumDataTypes()
{
  return 14;
}

/*************************************************************************
 *
 *  Name:      MdlGetDataTypeSizes
 *
 *  Format:    bool MdlGetNumDataTypeSizes(uint_T *puSizes, uint_T cDataTypes)
 *
 *  Purpose:   Returns the size of each data type defined in the model.
 *
 **************************************************************************/
boolean_T MdlGetDataTypeSizes(uint_T *puSizes, uint_T cDataTypes)
{
  // See <model>.reg for data type transition information setup and
  // see dt_info.h for data type structures. Note that we cannot use
  // the rtS SimStruct in this function because it is not initialized
  // at the time this function is called.
  if (cDataTypes == 14) {
    memcpy(puSizes, rtDataTypeSizes, cDataTypes * sizeof(uint_T));
    return 1;                          // Operation successful
  }

  return 0;                            // failed to perform operation
}

/*************************************************************************
 *
 *  Name:      MdlSamplingPeriod
 *
 *  Format:    real_T MdlSamplingPeriod( void )
 *
 *  Purpose:   Returns the base sampling period of the model
 *
 **************************************************************************/
real_T MdlSamplingPeriod( void )
{
  return(0.001);
}

/*************************************************************************
 *
 *  Name:      MdlSetTimer
 *
 *  Format:    void MdlSetTimer( void )
 *
 *  Purpose:   Sets the hardware timer to interrupt at the sampling rate.
 *
 **************************************************************************/
void MdlSetTimer( void )
{
  /* S-Function Block: <Root>/Servo (multiqtb) */
  {
    MQ_tbSetTimerPeriod(0x320, 0, 0.001);
  }
}

/*************************************************************************
 *
 *  Name:      MdlInterrupt
 *
 *  Format:    int_T MdlInterrupt( PInterrupt pInfo )
 *
 *  Purpose:   Returns information required to use hardware interrupts.
 *
 **************************************************************************/
int_T MdlInterrupt( PInterrupt pInfo )
{
  pInfo->m_InterfaceType = INTERFACE_EISA;
  pInfo->m_BusNumber = 0;
  pInfo->m_InterruptLine = 5;
  pInfo->m_InterruptVector = pInfo->m_InterruptLine;
  return 1;
}

/*************************************************************************
 *
 *  Name:      MdlIsInterruptSource
 *
 *  Format:    int_T MdlIsInterruptSource( void )
 *
 *  Purpose:   Returns true if the hardware interrupt was generated by
 *             the hardware timer. Otherwise it returns false.
 *
 **************************************************************************/
int_T MdlIsInterruptSource( void )
{
  return 1;
}

/*************************************************************************
 *
 *  Name:      MdlInterruptHandlers
 *
 *  Format:    int_T MdlInterruptHandlers( void )
 *
 *  Purpose:   Handles asynchronous interrupts. Returns 0 to indicate that
 *             no monitored interrupt source was responsible for the interrupt.
 *             Returns 1 to indicate that a monitored interrupt source was
 *             responsible for the interrupt and the interrupt was handled.
 *             Returns a negative number to indicate an error.
 *
 **************************************************************************/
int_T MdlInterruptHandlers( void )
{
  int_T __nHandled = 0;                /* default to interrupt not handled */
  if (rtmGetErrorStatus(SlotineAdaptableMotor_M)
      != NULL || rtmGetStopRequested(SlotineAdaptableMotor_M)
      != FALSE) {
    __nHandled = -1;
  }

  return __nHandled;
}

/*************************************************************************
 *
 *  Name:      MdlEnableInterrupts
 *
 *  Format:    void MdlEnableInterrupts( void )
 *
 *  Purpose:   Enables interrupts for asynchronous interrupt handlers.
 *
 **************************************************************************/
void MdlEnableInterrupts( void )
{
}

/*************************************************************************
 *
 *  Name:      MdlDisableInterrupts
 *
 *  Format:    void MdlDisableInterrupts( void )
 *
 *  Purpose:   Disables interrupts for asynchronous interrupt handlers.
 *
 **************************************************************************/
void MdlDisableInterrupts( void )
{
}
