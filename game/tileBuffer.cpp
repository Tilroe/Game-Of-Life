#include "tileBuffer.h"

TileBuffer::TileBuffer(int width, int height) :
	WIDTH(width),
	HEIGHT(height)
{
	tiles = std::vector<std::vector<char>>(height, std::vector<char>(width, OFF));
}

void TileBuffer::clear()
{
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			turnOff(col, row);
		}
	}
}

char& TileBuffer::getTile(int x, int y)
{
	return tiles[y][x];
}

void TileBuffer::turnOn(int x, int y)
{
	tiles[y][x] = ON;
}

void TileBuffer::turnOff(int x, int y)
{
	tiles[y][x] = OFF;
}

std::vector<std::vector<char>>& TileBuffer::getTiles()
{
	return tiles;
}


