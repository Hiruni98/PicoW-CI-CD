/**
 * \file
 * \brief Configuration header file for Wait
 * Copyright (c) 2020-2024, Erich Styger
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * This header file is used to configure settings of the busy waiting module.
 */

#ifndef __McuWait_CONFIG_H
#define __McuWait_CONFIG_H

#include "McuLib.h" /* include library configuration */

#ifndef McuWait_CONFIG_USE_CYCLE_COUNTER
  #define McuWait_CONFIG_USE_CYCLE_COUNTER  (1 && (McuLib_CONFIG_CPU_IS_ARM_CORTEX_M && McuLib_CONFIG_CORTEX_M>=3))
    /*!< 1: Use hardware cycle counter (if present, only on Cortex-M3 or higher), 0: not using hardware cycle counter */
#endif

#ifndef McuWait_CONFIG_NOF_CYCLES_FOR_NOP_MUL
  #define McuWait_CONFIG_NOF_CYCLES_FOR_NOP_MUL   (1)
    /*!< by default, use a single cycle for a NOP instruction. Some devices like the LPC804 need more. This factor gets it multiplied, see McuWait_CONFIG_NOF_CYCLES_FOR_NOP_DIV. */
#endif

#ifndef McuWait_CONFIG_NOF_CYCLES_FOR_NOP_DIV
  #define McuWait_CONFIG_NOF_CYCLES_FOR_NOP_DIV   (1)
    /*!< by default, use a single cycle for a NOP instruction. Some devices like the LPC804 need more. This factor gets it divided, see McuWait_CONFIG_NOF_CYCLES_FOR_NOP_MUL. */
#endif

#ifndef McuWait_CONFIG_USE_RTOS_WAIT
  #define McuWait_CONFIG_USE_RTOS_WAIT  (1 && McuLib_CONFIG_SDK_USE_FREERTOS)
    /*!< 1: Use RTOS wait if RTOS is present; 0: use normal busy waiting */
#endif

#if McuWait_CONFIG_USE_CYCLE_COUNTER
  #include "McuArmTools.h" /* include Cortex utility functions */
#endif

#endif /* __McuWait_CONFIG_H */
