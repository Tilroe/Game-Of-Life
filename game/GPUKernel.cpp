#include "GPUKernel.h"
#include "raylib.h"

GPUKernel::GPUKernel(const int width, const int height) :
	Kernel(width, height)
{
	buffers = std::vector<std::vector<int>>(2, std::vector<int>(width * height, 0));
	current_ = &buffers[0];
	next_ = &buffers[1];
}

void GPUKernel::update()
{
	next_->clear();
}

void GPUKernel::draw(const int TILE_SIZE) const
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (current_->at(y * width + x) == 1) 
			{
				DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, RAYWHITE);
			}
		}
	}
}

void GPUKernel::toggle(const int x, const int y)
{
	int& val = current_->at(y * width + x);
	if (val == 1) val = 0;
	else val = 1;
}

void GPUKernel::swap()
{
	std::vector<int>* temp = current_;
	current_ = next_;
	next_ = temp;
}