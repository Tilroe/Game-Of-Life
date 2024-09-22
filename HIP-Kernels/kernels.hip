#include "kernels.h"

__inline__ __device__ int out_value(const int in_value, const int neighbours) {
    if (in_value == 0) return (neighbours == 3) ? 1 : 0;
	else return (neighbours == 3 || neighbours == 2) ? 1 : 0;
}

__global__ void Kernels::game_of_life_global(int* in, int* out, const int width, const int height)
{
	int x = blockDim.x * blockIdx.x + threadIdx.x;
	int y = blockDim.y * blockIdx.y + threadIdx.y;
	if (x < 0 || y < 0 || x >= width || y >= height) return;
	
	int neighbours = 0;
	for (int dx : {-1, 0, 1})
	{
		for (int dy : {-1, 0, 1})
		{
			if (dx == 0 && dy == 0) continue;
			int xn = x + dx;
			int yn = y + dy;
			if (xn < 0 || yn < 0 || xn >= width || yn >= height) continue;
			neighbours += in[width * yn + xn];	
		}
	}

	out[width * y + x] = out_value(in[width * y + x], neighbours);
}