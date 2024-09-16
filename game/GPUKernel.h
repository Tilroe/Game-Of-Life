#pragma once
#include "Kernel.h"
#include <vector>

class GPUKernel :
    public Kernel
{
public:
    GPUKernel(const int width, const int height);
    void update() override;
    void draw(const int TILE_SIZE) const override;
    void toggle(const int x, const int y) override;

private:
    std::vector<std::vector<int>> buffers;
    std::vector<int>* current_;
    std::vector<int>* next_;
};

