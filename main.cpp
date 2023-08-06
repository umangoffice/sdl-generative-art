#include <iostream>
#include "Game.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game* game = nullptr;

int main(int num_args, char* argc[]) {
	game = new Game;

	game->init("Art Generator v1.0.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

	while (game->running() == SDL_TRUE) {

		game->handleEvent();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}