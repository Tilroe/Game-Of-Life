#pragma once
#include <vector>

constexpr char ON = 'w';
constexpr char OFF = 'b';


class TileBuffer 
{
public:
	TileBuffer(int width, int height);
	void clear();
	void turnOn(int x, int y);
	void turnOff(int x, int y);
	char& getTile(int x, int y);
	std::vector<std::vector<char>>& getTiles();

private:
	const int WIDTH;
	const int HEIGHT;

	std::vector<std::vector<char>> tiles;
};