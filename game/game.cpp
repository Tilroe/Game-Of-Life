#include "game.h"

Game::Game(int screenWidth, int screenHeight) :
	worldWidth(screenWidth / TILE_SIZE),
	worldHeight(screenHeight / TILE_SIZE)
{
	buffers = std::vector<TileBuffer>(2, TileBuffer(worldWidth, worldHeight));

	current_ = &buffers[0];
	next_ = &buffers[1];
}

void Game::handleInput()
{
	switch (state)
	{
	default:
		break;
	}
}


void Game::update() 
{
	next_->clear();

	// Iterate each tile
	for (int row = 0; row < worldHeight; row++) 
	{
		for (int col = 0; col < worldWidth; col++) 
		{
			char& tile = current_->getTile(col, row);

			// Check tile neighbours
			int yMin = std::max(0, row - 1);
			int yMax = std::min(worldHeight - 1, row + 1);
			int xMin = std::max(0, col - 1);
			int xMax = std::min(worldWidth - 1, col + 1);
			int neighbours = 0;
			for (int y = yMin; y <= yMax; y++) 
			{
				for (int x = xMin; x <= xMax; x++) 
				{
					if ((x == col) && (y == row)) continue; // Don't count self
					if (current_->getTile(x, y) == ON) { neighbours++; }
				}
			}

			// Rules
			switch (tile) 
			{
			case ON:
				if (neighbours == 2 || neighbours == 3) { next_->turnOn(col, row); }
				break;
			case OFF:
				if (neighbours == 3) { next_->turnOn(col, row); }
				break;
			}
		}
	}

	swap();
}

void Game::swap()
{
	TileBuffer* temp = current_;
	current_ = next_;
	next_ = temp;
}

void Game::draw() const 
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	for (int row = 0; row < worldHeight; row++) 
	{
		for (int col = 0; col < worldWidth; col++) 
		{
			Color c = BLACK;
			switch (current_->getTile(col, row))
			{
			case ON:
				c = RAYWHITE;
				break;
			case OFF:
				c = BLACK;
				break;
			}
			DrawRectangle(col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE, c);
		}
	}
	EndDrawing();
}