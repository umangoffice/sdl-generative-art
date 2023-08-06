#pragma once

#include <SDL.h>

class Game {
private:
	SDL_bool isRunning = SDL_FALSE;

public:
	void init(const char*, int, int, int, int, int);
	void handleEvent();
	void update();
	void render();
	void clean();

	SDL_bool running() { return isRunning; }
};