
#include "SparseMatrix.h"
#include "point.h"
#include <unordered_map>

SparseMatrix::SparseMatrix(const int width, const int height) :
	Kernel(width, height)
{
	buffers = std::vector<std::unordered_set<Point>>(2, {});
	current_ = &buffers[0];
	next_ = &buffers[1];
}

void SparseMatrix::update()
{
	
	return;
}

void SparseMatrix::draw() const
{
	return; // TODO
}

void SparseMatrix::swap()
{
	return; // TODO
}
