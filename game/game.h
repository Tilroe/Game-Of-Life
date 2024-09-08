#pragma once
#include <vector>
#include "raylib.h"
#include "Kernel.h"

class Game 
{
public:
	Game(const int width = 256, const int height = 256);
	~Game();
	void update(float dt);
	void draw() const;

	enum GameState { PAUSE, PLAY };
	inline GameState& get_game_state() { return state; }

private:
	Camera2D camera{ {0.f, 0.f}, {0.f, 0.f}, 0.f, 1.f };

	Kernel* current_kernel;
	std::vector<Kernel*> kernels;
	GameState state = PLAY;
	const int width, height;
	float time = 0.f;
	const float update_time = 0.5f;
	
};