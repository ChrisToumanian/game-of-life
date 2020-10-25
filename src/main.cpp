#include <iostream>
#include "console.h"
#include "map.h"

int main(int argc, char *argv[])
{
	int WIDTH = 500;
	int HEIGHT = 500;
	int CONSOLE_WIDTH = 225;
	int CONSOLE_HEIGHT = 52;
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
	map->generate();
	map->seed(DENSITY);

	bool running = true;

	// View centering variables
	//int start_x = (WIDTH - CONSOLE_WIDTH) / 2;
	//int end_x = WIDTH - start_x;
	//int start_y = (HEIGHT - CONSOLE_HEIGHT) / 2;
	//int end_y = HEIGHT - start_y;

	// Main loop
	while (running)
	{
		// Update map
		map->update();

		// Draw map
		console->clear();
		for (int y = 0; y < CONSOLE_HEIGHT - 1; ++y)
		{
			for (int x = 0; x < CONSOLE_WIDTH - 1; ++x)
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
