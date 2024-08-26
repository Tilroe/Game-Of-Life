#pragma once
#include "raylib.h"

class PlayPauseButton
{
public:
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
	ButtonState state = Normal;

	const char* texturePath = "Content/PlayPause.png";
	Texture2D texture = LoadTexture(texturePath);
	Rectangle textureSource{ 0, 0, 16, 16 };
	Rectangle screenPosition{ 20, 20, 64, 64 };
	bool play = false;
};