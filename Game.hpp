#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int x_pos, int y_pos,
	          int width, int height, bool is_full_screen);

	void handle_events();
	void update();
	void render();
	void clean();

	bool running() const { return is_running_; }

private:
	bool is_running_;

	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif
