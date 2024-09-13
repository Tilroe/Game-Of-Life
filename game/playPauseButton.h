#pragma once
#include "UI.h"

class Game;

class PlayPauseButton :
	public UI
{
public:
	PlayPauseButton(Game* game);
	~PlayPauseButton();
	void update(float dt);
	void handleInput(Vector2 mousePosition);
	void draw() const override;

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
	Game* game;
};