#pragma once
#include <vector>
#include "raylib.h"

class UI;
class Kernel;

class Game 
{
public:
	Game(const int width = 256, const int height = 256);
	~Game();
	void update(float dt);
	void draw() const;
	void register_ui(UI* ui);

	enum GameState { PAUSE, PLAY };
	inline GameState& get_game_state() { return state; }
	inline Vector2 get_bounds() const { return Vector2{ (float)width*TILE_SIZE, (float)height*TILE_SIZE }; }

private:
	GameState state = PLAY;

	// Camera members
	void handle_camera();
	Camera2D camera{ {0.f, 0.f}, {0.f, 0.f}, 0.f, 1.f };

	// Grid members
	const int TILE_SIZE = 32;
	const int width, height;

	// Kernel members
	void handle_toggling();
	Kernel* current_kernel;
	std::vector<Kernel*> kernels;
	float time = 0.f;
	const float update_time = 0.5f;

	// UI
	std::vector<UI*> ui;
	
};