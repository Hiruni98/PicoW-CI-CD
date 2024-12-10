/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuPidInt.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : PID_Int
**     Version     : Component 01.010, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-08-14, 06:24, # CodeGen: 679
**     Abstract    :
**
**     Settings    :
**          Component name                                 : McuPidInt
**          Variable for controller set point              : no
**          P - Proportional                               : Enabled
**            constant                                     : yes
**            Kp Factor                                    : 1
**            Kp Divisor                                   : 8
**          I - Integral                                   : Enabled
**            constant                                     : yes
**            Ki Factor                                    : 1
**            Ki Divisor                                   : 512
**            Anti Wind-Up                                 : Enabled
**              constant                                   : yes
**              Value                                      : 1024
**          D - Differential                               : Enabled
**            constant                                     : yes
**            Kd Factor                                    : 4
**            Kd Divisor                                   : 1
**          Hardware                                       : Disabled
**          System                                         : 
**            SDK                                          : McuLib
**     Contents    :
**         PID      - int32_t McuPidInt_PID(int32_t setPoint, int32_t currValue);
**         Control  - void McuPidInt_Control(void);
**         SetPoint - void McuPidInt_SetPoint(int32_t value);
**         GetPoint - int32_t McuPidInt_GetPoint(void);
**
** * Copyright (c) 2012-2020, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuPidInt.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup McuPidInt_module McuPidInt module documentation
**  @{
*/         

/* MODULE McuPidInt. */

#include "McuPidInt.h"

static int McuPidInt_setPoint; /* the value to be reached by the PID algorithm */
static const int32_t McuPidInt_KpMul = 1, McuPidInt_KpDiv = 8; /* the Kp adjustment values */
static const int32_t McuPidInt_KiMul = 1, McuPidInt_KiDiv = 512; /* the Ki adjustment values */
static const int32_t McuPidInt_KdMul = 4, McuPidInt_KdDiv = 1; /* the Kd adjustment values */

/*
** ===================================================================
**     Method      :  PID (component PID_Int)
**
**     Description :
**         Performs PID calculation
**     Parameters  :
**         NAME            - DESCRIPTION
**         setPoint        - current setpoint (desired value)
**         currValue       - current sensor value
**     Returns     :
**         ---             - output of PID calculation
** ===================================================================
*/
#ifdef __HIWARE__
  #pragma MESSAGE DISABLE C5904 /* Division by one */
  #pragma MESSAGE DISABLE C5905 /* Multiplication with one */
#endif
int32_t McuPidInt_PID(int32_t setPoint, int32_t currValue)
{
  /* Performs a PID calculation */
  int32_t regDifferential; /* temporary variable for the D part */
  static int32_t oldDiff = 0; /*!< Remember error for next round (for D part) */
  static int32_t regIntegral = 0;  /*!< Remember integral part for next iteration */
  int32_t diff; /* actual error */
  int32_t pid;  /* pid calculation value */

  pid = 0; /* initialize */
  diff = setPoint-currValue;
  /* P-Part */
  pid += (McuPidInt_KpMul*diff)/McuPidInt_KpDiv;
  /* I-Part */
  regIntegral += diff; /* integrate error */
  if (regIntegral > 1024) { /* anti wind-up */
    regIntegral = 1024;
  } else if (regIntegral < -1024) {
    regIntegral = -1024;
  }
  pid += (McuPidInt_KiMul*regIntegral)/McuPidInt_KiDiv;
  /* D-Part */
  regDifferential = diff-oldDiff;
  oldDiff = diff; /* remember for next iteration */
  pid += (McuPidInt_KdMul*regDifferential)/McuPidInt_KdDiv; /* add D part */
  return pid;
}

/*
** ===================================================================
**     Method      :  Control (component PID_Int)
**
**     Description :
**         Performs the PID control calculation.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuPidInt_Control(void)
{
  return; /* hardware for sensor and actuator not enabled: enable them in the properties or use the PID() function instead */
}

/*
** ===================================================================
**     Method      :  SetPoint (component PID_Int)
**
**     Description :
**         Specifies the value to be reached by the PID controller.
**     Parameters  :
**         NAME            - DESCRIPTION
**         value           - The value to be reached.
**     Returns     : Nothing
** ===================================================================
*/
void McuPidInt_SetPoint(int32_t value)
{
  McuPidInt_setPoint = value;
}

/*
** ===================================================================
**     Method      :  GetPoint (component PID_Int)
**
**     Description :
**         Returns the current set point value
**     Parameters  : None
**     Returns     :
**         ---             - The current set point
** ===================================================================
*/
int32_t McuPidInt_GetPoint(void)
{
  return McuPidInt_setPoint;
}

/* END McuPidInt. */

/*!
** @}
*/
