#pragma once
#include "msvc_defines.h"
#include <hip/hip_runtime.h>

__global__ void game_of_life_global(bool* in, bool* out, const int width, const int height);