#include <iostream>
#include "console.h"
#include "map.h"

int main(int argc, char *argv[])
{
	int WIDTH = stoi(argv[1]);
	int HEIGHT = stoi(argv[2]);
	int DENSITY = stoi(argv[3]);

	Console* console = new Console(WIDTH, HEIGHT);
	Map* map = new Map(WIDTH, HEIGHT);
	map->generate();
	map->seed(DENSITY);

	bool running = true;

	// Main loop
	while (running)
	{
		// Update map
		map->update();

		// Draw map
		console->clear();
		for (int y = 0; y < HEIGHT - 1; ++y)
		{
			for (int x = 0; x < WIDTH - 1; ++x)
			{
				console->printChar(x, y, map->cells[y][x]);
			}
		}
		console->update();
	}

	// Close ncurses and exit
	console->stop();

	return 0;
}
