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

	int rectX = ww / 8;
	int rectY = wh / 8;
	int rectWidth = ww - (rectX * 2);
	int rectHeight = wh - (rectY * 2);

	SDL_Rect fillRect = { rectX, rectY, rectWidth, rectHeight };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);

	int secondRectX = ww / 4;
	int secondRectY = wh / 4;
	int secondRectWidth = ww / 2;
	int secondRectHeight = wh / 2;

	SDL_Rect secondFillRect = { secondRectX, secondRectY, secondRectWidth, secondRectHeight };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &secondFillRect);


	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break;
		default: break;
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
}

Game::~Game() {
	delete window;
	delete renderer;
}