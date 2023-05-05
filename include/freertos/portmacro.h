#pragma once

#include "stm32_def.h"
#include "FreeRTOSConfig.h"


#ifdef __cplusplus
extern "C" {
#endif

#if defined(configUSE_CUSTOM_PORT) && defined(configCUSTOM_PORT_PORTMACRO)
#if __has_include(configCUSTOM_PORT_PORTMACRO)
#include configCUSTOM_PORT_PORTMACRO
#else
#error "configCUSTOM_PORT_PORTMACRO not found!"
#endif 
#else 



#ifndef __CORTEX_M
#pragma GCC error "no \"__CORTEX_M\" definition"
#endif

#if (__CORTEX_M == 0x00U)
#include "../freertos/portable/GCC/ARM_CM0/portmacro.h"
#endif

#if (__CORTEX_M == 0x03U)
/* MPU not supported */
#if 0 /*(__MPU_PRESENT == 1)*/
#include "../freertos/portable/GCC/ARM_CM3_MPU/portmacro.h"
#else
#include "../freertos/portable/GCC/ARM_CM3/portmacro.h"
#endif
#endif

#if (__CORTEX_M == 0x04U)
/* MPU not supported */
#if 0 /*(__MPU_PRESENT == 1)*/
#include "../freertos/portable/GCC/ARM_CM4_MPU/portmacro.h"
#else
#include "../freertos/portable/GCC/ARM_CM4F/portmacro.h"
#endif
#endif

#if (__CORTEX_M == 0x07U)
/* MPU not supported */
#if 0 /*(__MPU_PRESENT == 1)*/
#include "../freertos/portable/GCC/ARM_CM7_MPU/r0p1/portmacro.h"
#else
#include "../freertos/portable/GCC/ARM_CM7/r0p1/portmacro.h"
#endif
#endif

#endif

#ifdef __cplusplus
} // extern "C"
#endif
