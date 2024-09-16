#include "GPUKernel.h"

GPUKernel::GPUKernel(const int width, const int height) :
	Kernel(width, height)
{
	buffers = std::vector<std::vector<int>>(2, std::vector<int>(width * height, 0));
	current_ = &buffers[0];
	next_ = &buffers[1];
}
