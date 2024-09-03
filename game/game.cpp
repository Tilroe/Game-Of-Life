#include "game.h"

Game::Game(const int grid_width, const int grid_height) :
	grid_width(grid_width),
	grid_height(grid_height)
{

}

inline Game::GameState& Game::get_game_state()
{
	return state;
}
