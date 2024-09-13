#include "playPauseButton.h"
#include "game.h"

PlayPauseButton::PlayPauseButton(Game* game) :
	game(game)
{
	screen_position = Rectangle{ 20, 20, 64, 64 };
}

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
	switch (buttonState) {
	case Normal:
		if (CheckCollisionPointRec(mousePosition, screen_position)) 
		{
			buttonState = Hover;
			textureSource = { 0, 16, 16, 16 };
		}
		break;

	case Hover:
		if (!CheckCollisionPointRec(mousePosition, screen_position))
		{
			buttonState = Normal;
			textureSource = { 0, 0, 16, 16 };
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			buttonState = Click;
			textureSource = { 0, 32, 16, 16 };
		}
		break;

	case Click:
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			Game::GameState& gameState = game->get_game_state();
			gameState = (gameState == Game::PLAY) ? Game::PAUSE : Game::PLAY;
			buttonState = Normal;
			textureSource = { 0, 0, 16, 16 };
		}
		break;

	}
	textureSource.x = (game->get_game_state() == Game::PAUSE) ? 0.0f : 16.0f;
}

void PlayPauseButton::draw() const
{
	DrawTexturePro(texture, textureSource, screen_position, {0, 0}, 0.0, WHITE);
}
