#pragma once
#include "raylib.h"

class Game;

class PlayPauseButton
{
public:
	PlayPauseButton(Game& game);
	~PlayPauseButton();
	void update(float dt);
	void handleInput(Vector2 mousePosition);
	void draw();


private:
	enum ButtonState {
		Normal,
		Hover,
		Click
	};
	ButtonState buttonState = Normal;

	const char* texturePath = "Content/PlayPause.png";
	Texture2D texture = LoadTexture(texturePath);
	Rectangle textureSource{ 0, 0, 16, 16 };
	Rectangle screenPosition{ 20, 20, 64, 64 };
	Game& game;
};