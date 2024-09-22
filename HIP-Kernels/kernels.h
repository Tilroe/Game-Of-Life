#pragma once
#include "msvc_defines.h"
#include <hip/hip_runtime.h>

namespace Kernels {
	__global__ void game_of_life_global(int* in, int* out, const int width, const int height);
}