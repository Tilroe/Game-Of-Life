#pragma once
#include <vector>
#include "raylib.h"
#include "tileBuffer.h"

class Game 
{
public:
	Game(int screenWidth, int screenHighet);
	void update(float dt);
	void draw() const;

	enum GameState { PAUSE, PLAY };
	GameState& getGameState();

private:
	void swap();
	
	int TILE_SIZE = 32;
	const int worldWidth, worldHeight;
	float time = 0.f;
	const float updateTime = 0.5f;
	GameState state = PLAY;
	std::vector<TileBuffer> buffers;
	TileBuffer *current_;
	TileBuffer *next_;
};