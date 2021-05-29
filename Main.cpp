#define SDL_MAIN_HANDLED
#include <iostream>

#include "Game.hpp"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int width = 600;
	const int height = 400;

	game = new Game();

	game->init("Insider Engine",
	           SDL_WINDOWPOS_CENTERED,
	           SDL_WINDOWPOS_CENTERED,
	           width, height,
	           false);

	while (game->running())
	{
		game->handle_events();
		game->update();
		game->render();
	}

	game->clean();
	std::cout << "Program Ended" << std::endl;

	return 0;
}
