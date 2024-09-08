#include "game.h"

#include <cmath>
#include "raymath.h"
#include "SparseMatrix.h"


Game::Game(const int width, const int height) :
	width(width),
	height(height)
{
	kernels.push_back(new SparseMatrix(width, height));
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
	// Camera updates
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		Vector2 mouse_delta = Vector2Scale(GetMouseDelta(), -1);
		camera.target = Vector2Add(camera.target, mouse_delta);
		camera.target = Vector2Clamp(camera.target, { 0, 0 }, { width * 32 - (float)GetScreenWidth(), height * 32 - (float)GetScreenHeight() });
	}


	// Kernel updates
	if (state == PLAY) {
		time += dt;
		if (time > update_time) {
			time = std::fmod(time, update_time);
			current_kernel->update();
		}
	}
	
}

void Game::draw() const
{
	BeginMode2D(camera);
	current_kernel->draw();
	EndMode2D();
}
