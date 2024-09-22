#pragma once
#include "hip/hip_runtime.h"

#define HIP_CHECK(status)                                                                                     \
    if (status != hipSuccess) {                                                                               \
        fprintf(stderr, "error: '%s'(%d) at %s:%d\n", hipGetErrorString(status), status, __FILE__, __LINE__); \
        exit(0);                                                                                              \
    }