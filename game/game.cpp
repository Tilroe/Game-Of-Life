#include "game.h"

#include <cmath>
#include "SparseMatrix.h"


Game::Game(const int grid_width, const int grid_height) :
	grid_width(grid_width),
	grid_height(grid_height)
{
	kernels.push_back(new SparseMatrix(grid_width, grid_height));
	current_kernel = kernels[0];
}

Game::~Game()
{
	for (Kernel* k : kernels) {
		delete k;
	}
}

void Game::update(float dt)
{
	// Only update if gone over update_time
	time += dt;
	if (time < update_time) return;
	time = std::fmod(time, update_time);

	// Perform kernel update
	current_kernel->update();
}

void Game::draw() const
{
	current_kernel->draw();
}
