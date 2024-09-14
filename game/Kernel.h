#pragma once
class Kernel
{
public:
	Kernel(const int width = 256, const int height = 256);
	virtual void update() = 0;
	virtual void draw(const int TILE_SIZE) const = 0;
	virtual void toggle(const int x, const int y) = 0;

protected:
	const int width, height;

private:
	virtual void swap() = 0;
};

