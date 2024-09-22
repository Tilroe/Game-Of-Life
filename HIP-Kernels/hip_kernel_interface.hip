#include "hip_kernel_interface.h"
#include "kernels.h"
#include "hip_utility.h"

int *device_in = nullptr, *device_out = nullptr;

void allocate_hip_memory(const int width, const int height)
{
    if (device_in != nullptr) HIP_CHECK(hipFree(device_in));
    if (device_out != nullptr) HIP_CHECK(hipFree(device_out));
    HIP_CHECK(hipMalloc((void**)&device_in, width * height * sizeof(int)));
    HIP_CHECK(hipMalloc((void**)&device_out, width * height * sizeof(int)));
}

void free_hip_memory()
{
    HIP_CHECK(hipFree(device_in));
    HIP_CHECK(hipFree(device_out));
}

void game_of_life_global(int* in, int* out, const int width, const int height)
{
    const int THREADS_PER_BLOCK_X = 4;
    const int THREADS_PER_BLOCK_Y = 4;
    const int THREADS_PER_BLOCK_Z = 1;
    const int GRID_X = int(width / THREADS_PER_BLOCK_X);
    const int GRID_Y = int(height / THREADS_PER_BLOCK_Y);

    dim3 dimGrid(GRID_X, GRID_Y);
    dim3 dimBlock(THREADS_PER_BLOCK_X, THREADS_PER_BLOCK_Y, THREADS_PER_BLOCK_Z);

    HIP_CHECK(hipMemcpy(device_in, in, width * height * sizeof(int), hipMemcpyHostToDevice));

    Kernels::game_of_life_global<<<dimGrid, dimBlock, 0, 0>>>(device_in, device_out, width, height);

    HIP_CHECK(hipMemcpy(out, device_out, width * height * sizeof(int), hipMemcpyDeviceToHost));
}