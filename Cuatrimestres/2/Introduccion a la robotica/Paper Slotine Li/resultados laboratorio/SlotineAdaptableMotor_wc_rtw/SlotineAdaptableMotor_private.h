/*
 * SlotineAdaptableMotor_private.h
 *
 * Real-Time Workshop code generation for Simulink model "SlotineAdaptableMotor.mdl".
 *
 * Model Version              : 1.22
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Apr 16 11:46:18 2015
 */
#ifndef _RTW_HEADER_SlotineAdaptableMotor_private_h_
#define _RTW_HEADER_SlotineAdaptableMotor_private_h_
#include "rtwtypes.h"
#include "multiqtb.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

/* private model entry point functions */
extern void SlotineAdaptableMotor_derivatives(void);
extern void stgenc(SimStruct *rts);
extern void stgad(SimStruct *rts);
extern void stgda(SimStruct *rts);

#endif                                 /* _RTW_HEADER_SlotineAdaptableMotor_private_h_ */
