
#include "SparseMatrix.h"

#include <unordered_map>
#include "point.h"
#include "raylib.h"

SparseMatrix::SparseMatrix(const int width, const int height) :
	Kernel(width, height)
{
	buffers = std::vector<std::unordered_set<Point>>(2, {});
	current_ = &buffers[0];
	next_ = &buffers[1];
}

void SparseMatrix::update()
{
	next_->clear();
	std::unordered_map<Point, int> neighbours;

	// Calculate neighbour counts
	for (const Point& p : *current_) {
		for (int x_offset : {-1, 0, 1}) {
			for (int y_offset : {-1, 0, 1}) {
				Point neighbour{ p.x + x_offset, p.y + y_offset };

				// Don't count neighbour for self
				if (neighbour == p) continue;

				// Bounds check
				if ((neighbour.x < 0) ||
					(neighbour.x >= width) ||
					(neighbour.y < 0) ||
					(neighbour.y >= height)) continue;

				auto result = neighbours.emplace(neighbour, 1);
				bool exists = result.second;
				std::unordered_map<Point, int>::iterator iter = result.first;
				if (!exists) {
					// neighbour already exists in neighbours, just update count
					iter->second = iter->second + 1;
				}
			}
		}
	}

	// Figure out which points need to be alive
	for (const std::pair<Point, int>& kv : neighbours) {
		const Point& p = kv.first;
		const int& n_neighbours = kv.second;

		if (current_->find(p) == current_->end()) {
			// Point is not alive
			if (n_neighbours == 3) { next_->emplace(p); }
		}
		else {
			// Point is alive
			if (n_neighbours == 2 || n_neighbours == 3) { next_->emplace(p); }
		}
	}

	swap();
}

void SparseMatrix::draw() const
{
	for (const Point& p : *current_) {
		DrawRectangle(p.x * 32, p.y * 32, 32, 32, RAYWHITE);
	}
}

void SparseMatrix::toggle(const int x, const int y)
{
	if (x < 0 || y < 0 || x >= width || y >= height) return;
	if (current_->find(Point{ x, y }) == current_->end()) current_->emplace(Point{ x, y });
	else current_->erase(Point{ x, y });
}

void SparseMatrix::swap()
{
	std::unordered_set<Point>* temp = current_;
	current_ = next_;
	next_ = temp;
}
