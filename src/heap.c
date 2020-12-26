
#include "FreeRTOS.h"


#ifndef configMEMMANG_HEAP_NB
#define configMEMMANG_HEAP_NB      -1
#endif
#if (configMEMMANG_HEAP_NB == -1)
#include "../portable/MemMang/heap_useNewlib_ST.c"
#elif (configMEMMANG_HEAP_NB == 1)
#include "../freertos/portable/MemMang/heap_1.c"
#elif (configMEMMANG_HEAP_NB == 2)
#include "../freertos/portable/MemMang/heap_2.c"
#elif (configMEMMANG_HEAP_NB == 3)
#include "../freertos/portable/MemMang/heap_3.c"
#elif (configMEMMANG_HEAP_NB == 4)
#include "../freertos/portable/MemMang/heap_4.c"
#elif (configMEMMANG_HEAP_NB == 5)
#include "../freertos/portable/MemMang/heap_5.c"
#else
#error "Wrong Memory allocation implementations defined"
#endif
