#pragma once
#include <vector>
#include "raylib.h"
#include "Kernel.h"

class Game 
{
public:
	Game(const int grid_width = 256, const int grid_height = 256);
	~Game();
	void update(float dt);
	void draw() const;

	enum GameState { PAUSE, PLAY };
	inline GameState& get_game_state() { return state; }

private:
	Kernel* current_kernel;
	std::vector<Kernel*> kernels;

	GameState state = PLAY;
	const int grid_width, grid_height;
	float time = 0.f;
	const float update_time = 0.5f;
	
};