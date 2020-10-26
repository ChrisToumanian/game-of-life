#ifndef MAP_H
#define MAP_H

#include <random>

class Map
{
public:
	Map(int _width, int _height);

	char** cells;
	char** new_gen;
	char young_cell = 'O';
	char old_cell = 'O';

	void generate();
	void seed(int density);
	void update();

private:
	int width;
	int height;
	std::random_device rd;

	int getLiveNeighbors(int x, int y);
	char getCell(int x, int y);
};

#endif
