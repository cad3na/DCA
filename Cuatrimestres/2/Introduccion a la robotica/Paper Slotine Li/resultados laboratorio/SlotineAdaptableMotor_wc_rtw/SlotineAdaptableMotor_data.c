/*
 * SlotineAdaptableMotor_data.c
 *
 * Real-Time Workshop code generation for Simulink model "SlotineAdaptableMotor.mdl".
 *
 * Model Version              : 1.22
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Apr 16 11:46:18 2015
 */

#include "SlotineAdaptableMotor.h"
#include "SlotineAdaptableMotor_private.h"

/* Block parameters (auto storage) */
Parameters_SlotineAdaptableMotor SlotineAdaptableMotor_P = {
  0.0,                                 /* Integrator1_IC : '<S2>/Integrator1'
                                        */
  0.0,                                 /* Integrator_IC : '<Root>/Integrator'
                                        */

  /*  IntDecod_P1_Size : '<S7>/Int Decod'
   */
  { 1.0, 1.0 },
  0.001,                               /* IntDecod_P1 : '<S7>/Int Decod'
                                        */
  -0.000244140625,                     /* Gain_Gain : '<S4>/Gain'
                                        */
  1.0,                                 /* Gain_Gain_j : '<S1>/Gain'
                                        */
  0.0,                                 /* Integrator_IC_c : '<S2>/Integrator'
                                        */
  0.0,                                 /* Integrator_IC_m : '<S3>/Integrator'
                                        */
  -300.0,                              /* Filtro_A : '<Root>/Filtro'
                                        */
  300.0,                               /* Filtro_C : '<Root>/Filtro'
                                        */
  1.0,                                 /* Gain1_Gain : '<S1>/Gain1'
                                        */
  200.0,                               /* g2_Gain : '<S2>/g2'
                                        */
  -100.0,                              /* TransferFcn_A : '<S2>/Transfer Fcn'
                                        */
  100.0,                               /* TransferFcn_C : '<S2>/Transfer Fcn'
                                        */
  10000.0,                             /* g1_Gain : '<S2>/g1'
                                        */
  1.0,                                 /* Gain_Gain_m : '<Root>/Gain'
                                        */
  100.0,                               /* Gain1_Gain_g : '<Root>/Gain1'
                                        */

  /*  Gain_Gain_f : '<S3>/Gain'
   */
  { -10.0, -10.0 },

  /*  IntAD_P1_Size : '<S5>/Int AD'
   */
  { 1.0, 1.0 },
  0.001,                               /* IntAD_P1 : '<S5>/Int AD'
                                        */

  /*  IntAD_P2_Size : '<S5>/Int AD'
   */
  { 1.0, 1.0 },
  8.0,                                 /* IntAD_P2 : '<S5>/Int AD'
                                        */
  2.3809523809523809E+000,             /* Gain1_Gain_p : '<S4>/Gain1'
                                        */

  /*  IntAD_P1_Size_a : '<S6>/Int AD'
   */
  { 1.0, 1.0 },
  0.001,                               /* IntAD_P1_i : '<S6>/Int AD'
                                        */

  /*  IntAD_P2_Size_h : '<S6>/Int AD'
   */
  { 1.0, 1.0 },
  0.0,                                 /* IntAD_P2_o : '<S6>/Int AD'
                                        */

  /*  IntAD_P3_Size : '<S6>/Int AD'
   */
  { 1.0, 1.0 },
  0.0,                                 /* IntAD_P3 : '<S6>/Int AD'
                                        */
  0.5,                                 /* SignalGenerator_Amplitude : '<Root>/Signal Generator'
                                        */
  0.5,                                 /* SignalGenerator_Frequency : '<Root>/Signal Generator'
                                        */
  10.0,                                /* Step_Time : '<Root>/Step'
                                        */
  0.0,                                 /* Step_Y0 : '<Root>/Step'
                                        */
  1.0                                  /* Step_YFinal : '<Root>/Step'
                                        */
};
