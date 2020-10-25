#include <iostream>
#include "console.h"
#include "map.h"

int main(int argc, char *argv[])
{
	int WIDTH = 250;
	int HEIGHT = 100;
	int DENSITY = 1;
	
	if (argc == 4)
	{
		std::cout << argv[1];
		WIDTH = stoi(argv[1]);
		HEIGHT = stoi(argv[2]);
		DENSITY = stoi(argv[3]);
	}

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
