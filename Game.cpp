#include "Game.hpp"

#include <cassert>
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int x_pos, int y_pos,
                int width, int height, bool is_full_screen)
{
	int flags = 0;

	if (is_full_screen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized!" << std::endl;

		window = SDL_CreateWindow(title, x_pos, y_pos,
		                          width, height, flags);

		if (window != nullptr)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			std::cout << "Renderer Created!" << std::endl;
		}

		is_running_ = true;
	}

	else
	{
		is_running_ = false;
	}
}

void Game::handle_events()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		is_running_ = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Cleaning Memory..." << std::endl;
}
