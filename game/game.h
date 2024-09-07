#pragma once
#include <vector>
#include "raylib.h"
#include "tileBuffer.h"

class Game 
{
public:
	Game(const int grid_width = 256, const int grid_height = 256);
	virtual void update(float dt) = 0;
	virtual void draw() const = 0;

	enum GameState { PAUSE, PLAY };
	inline GameState& get_game_state() { return state; }

private:
	virtual void swap() = 0;
	
	GameState state = PLAY;
	const int grid_width, grid_height;
	float time = 0.f;
	const float update_time = 0.5f;
	
};