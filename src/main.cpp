#include <iostream>
#include "console.h"
#include "map.h"

int main(int argc, char *argv[])
{
	int WIDTH = 1000;
	int HEIGHT = 1000;
	int CONSOLE_WIDTH = 222;
	int CONSOLE_HEIGHT = 63;
	int DENSITY = 1;
	
	if (argc == 6)
	{
		WIDTH = stoi(argv[1]);
		HEIGHT = stoi(argv[2]);
		CONSOLE_WIDTH = stoi(argv[3]);
		CONSOLE_HEIGHT = stoi(argv[4]);
		DENSITY = stoi(argv[5]);
	}

	Console* console = new Console(CONSOLE_WIDTH, CONSOLE_HEIGHT);
	Map* map = new Map(WIDTH, HEIGHT);

	if (argc == 3)
	{
		map->young_cell = argv[1][0];
		map->old_cell = argv[2][0];
	}

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
		for (int y = 0; y < CONSOLE_HEIGHT; ++y)
		{
			for (int x = 0; x < CONSOLE_WIDTH; ++x)
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
