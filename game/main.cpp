#include "game.h"
#include <cmath>

int main() 
{
	InitWindow(0, 0, "Game Of Life");
	ToggleBorderlessWindowed();
	SetTargetFPS(60);
	
	while (!IsWindowReady());

	const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
	const int screenHeight = GetMonitorHeight(GetCurrentMonitor());

	const float UPDATE_TIME = 0.5f;
	Game game(screenWidth, screenHeight);
	float time = 0.f;

	while (!WindowShouldClose()) 
	{
		time += GetFrameTime();
		if (time > UPDATE_TIME)
		{
			game.update();
			time = std::fmod(time, UPDATE_TIME);
		}
		game.draw();
	}

	return 0;
}