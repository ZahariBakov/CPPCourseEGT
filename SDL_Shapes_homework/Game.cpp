#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success!\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "Window creation success!\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //renderer init success
			{
				std::cout << "Renderer creation success!\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			}
			else {
				std::cout << "Renderer init failed!\n";
				return false;
			}
		}
		else {
			std::cout << "Window init failed!\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail!\n";
		return false;
	}
	std::cout << "Init success!\n";
	running = true;
	return true;
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	Shapes::drawRecnatgle(renderer, ww / 4, wh / 4, ww / 2, wh / 2, 10);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	Shapes::drawCircle(renderer, ww / 2, wh / 2, wh / 2);

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	Shapes::drawPentagon(renderer, ww / 2, wh / 2, 360);

	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	Shapes::drawHexagon(renderer, ww / 2, wh / 2, 360);

	SDL_SetRenderDrawColor(renderer, 0, 0, 205, 255);
	Shapes::drawPolygon(renderer, ww / 2, wh / 2, Game::minSides, 150);


	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: 
			running = false; 
			break;
		case SDL_KEYDOWN: {
			if (event.key.keysym.sym == SDLK_UP) {
				Game::minSides++;
			}
			if (event.key.keysym.sym == SDLK_DOWN) {
				(minSides > 3) ? Game::minSides -= 1 : Game::minSides;
			}
			break;
		}; 

		default: 
			break;
		}
	}
}

void Game::update() {

}

void Game::clean() {
	std::cout << "Cleaning game!\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() const {
	return Game::running;
}

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::minSides = 3;
}

Game::~Game() {
	delete window;
	delete renderer;
}
