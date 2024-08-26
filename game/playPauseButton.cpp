#include "playPauseButton.h"

PlayPauseButton::~PlayPauseButton()
{
	UnloadTexture(texture);
}

void PlayPauseButton::update(float dt)
{
	handleInput(GetMousePosition());
}

void PlayPauseButton::handleInput(Vector2 mousePosition)
{
	switch (state) {
	case Normal:
		if (CheckCollisionPointRec(mousePosition, screenPosition)) 
		{
			state = Hover;
			textureSource = { 0, 16, 16, 16 };
		}
		break;

	case Hover:
		if (!CheckCollisionPointRec(mousePosition, screenPosition))
		{
			state = Normal;
			textureSource = { 0, 0, 16, 16 };
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			state = Click;
			textureSource = { 0, 32, 16, 16 };
		}
		break;

	case Click:
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			play = !play;
			state = Normal;
			textureSource = { 0, 0, 16, 16 };
		}
		break;

	}
}

void PlayPauseButton::draw()
{
	textureSource.x = (play) ? 0.0 : 16.0;
	DrawTexturePro(texture, textureSource, screenPosition, {0, 0}, 0.0, WHITE);
}
