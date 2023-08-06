#include "Game.h"
#include "ExternDecl.h"
#include <time.h>
#include <random>

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Renderer* ren2 = nullptr;

SDL_Point* current = nullptr;

vector<SDL_Point*> group_of_points{};

void Game::init(const char* title, int x, int y, int w, int h, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		// create window
		gWindow = SDL_CreateWindow(title, x, y, w, h, flags); 

		if (gWindow != NULL) {
			// create renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
			ren2 = SDL_CreateRenderer(gWindow, -1, 0);

			isRunning = SDL_TRUE;
		}
	}
}

void Game::handleEvent() {
	SDL_Event e;

	while (SDL_PollEvent(&e)) {

		switch (e.type) {

		case SDL_QUIT:
			isRunning = SDL_FALSE;
			break;
		}
	}
}

void Game::update() {
	uint16_t srand(time(NULL));

	auto x_generator = rand() % 800;
	auto y_generator = rand() % 600;

	if (x_generator != NULL && y_generator != NULL) {
		current = new SDL_Point;
	}

	current->x = x_generator;
	current->y = y_generator;

	group_of_points.push_back(current);
}

void Game::render() {
	SDL_RenderClear(gRenderer);
	//------------------------
	SDL_Delay(200);

	for (int count = 0; count < group_of_points.size(); count++) {
		SDL_RenderDrawPoint(gRenderer, group_of_points[count]->x, group_of_points[count]->y);
	}

	SDL_SetRenderDrawColor(gRenderer, 0, 188, 227, 1);

	for (int count = 0; count < (group_of_points.size() - 1); count++) {
		for (int index = 0; index < count; index++) {
			SDL_RenderDrawLine(gRenderer, group_of_points[count]->x, group_of_points[count]->y, group_of_points[index]->x, group_of_points[index]->y);
		}
	}

	if (group_of_points.size() >= 40) {
		group_of_points.erase(group_of_points.begin());
	}
	//------------------------
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_RenderPresent(gRenderer);
}

void Game::clean() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}