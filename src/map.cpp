#include "map.h"

Map::Map(int _width, int _height)
{
	width = _width;
	height = _height;
}

void Map::generate()
{
	cells = new char*[height];
	for (int i = 0; i < height; ++i)
	{
    	cells[i] = new char[width];
	}

	// fill
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			cells[y][x] = ' ';
		}
	}
}

void Map::seed(int density)
{
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, density); // define the range

	// fill
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (distr(gen) == 1)
				cells[y][x] = 'o';
		}
	}
}

void Map::update()
{	
	new_gen = new char*[height];
	for (int i = 0; i < height; ++i)
	{
    	new_gen[i] = new char[width];
	}

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			new_gen[y][x] = ' ';
			int neighbors = getLiveNeighbors(x, y);

			// Any cell with fewer than two live neighbors dies, as if by underpopulation.
			if (neighbors < 2)
			{
				new_gen[y][x] = ' ';
			}
			
			// Any cell with two or three live neighbors lives to the next generation.
			if (cells[y][x] != ' ' && (neighbors == 2 || neighbors == 3))
			{
				new_gen[y][x] = old_cell;
			}

			// Any cell with more than three live neighbors dies, as if by overcrowding.
			if (neighbors > 3)
			{
				new_gen[y][x] = ' ';
			}

			// Any cell with exactly three live neighbors becomes a live cell, as if by reproduction.
			if (neighbors == 3)
			{
				new_gen[y][x] = young_cell;
			}
		}
	}

	cells = new_gen;
}

int Map::getLiveNeighbors(int x, int y)
{
	int neighbors = 0;

	if (y > 0 && x > 0 && getCell(x - 1, y - 1) != ' ') neighbors++; // upper-left
	if (y > 0 && getCell(x, y - 1) != ' ') neighbors++; // upper-center
	if (y > 0 && x < width && getCell(x + 1, y - 1) != ' ') neighbors++; // upper-right
	if (x > 0 && getCell(x - 1, y) != ' ') neighbors++; // middle-left
	if (x < width && getCell(x + 1, y) != ' ') neighbors++; // middle-right
	if (y < height && x > 0 && getCell(x - 1, y + 1) != ' ') neighbors++; // lower-left
	if (y < height && getCell(x, y + 1) != ' ') neighbors++; // lower-center
	if (y < height && x < width && getCell(x + 1, y + 1) != ' ') neighbors++; // lower-right

	return neighbors;
}

char Map::getCell(int x, int y)
{
	if (x < 0) x = width - 1;
	if (x > width - 1) x = 0;
	if (y < 0) y = height - 1;
	if (y > height - 1) y = 0;
	
	return cells[y][x];
}
