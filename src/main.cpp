#include <iostream>
#include "console.h"
#include "map.h"

#define WIDTH 200
#define HEIGHT 50
#define DENSITY 14

int main()
{
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
