#include "raylib.h"
#include "game.h"
#include "playPauseButton.h"

int main() 
{
	InitWindow(0, 0, "Game Of Life");
	ToggleBorderlessWindowed();
	SetTargetFPS(60);
	
	while (!IsWindowReady());

	const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
	const int screenHeight = GetMonitorHeight(GetCurrentMonitor());

	Game game;
	PlayPauseButton button(&game);
	game.register_ui(&button);

	while (!WindowShouldClose()) 
	{
		float dt = GetFrameTime();
		game.update(dt);
		button.update(dt);

		BeginDrawing();
		ClearBackground(BLACK);
		game.draw();
		button.draw();
		EndDrawing();
	}

	return 0;
}