#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success!\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) {
			std::cout << "Window creation success!\n";
			renderer = SDL_CreateRenderer(window, -1, 0);

			if (renderer != 0) {
				std::cout << "Renderer creation success!\n";
				SDL_SetRenderDrawColor(renderer, 0, 153, 0, 255);

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

bool Game::ttf_init() {
	if (TTF_Init() == -1) {
		return false;
	}

	TTF_Font* font1 = TTF_OpenFont("fonts/Arcade.ttf", 24);

	if (font1 == NULL) {
		std::cout << "Font 1 is NULL" << std::endl;
		return false;
	}

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); // get window size

	SDL_Surface* tempSurfaceText = NULL;

	tempSurfaceText = TTF_RenderText_Blended(font1, "DEALER :", { 0, 0, 0, 255 });
	dealerTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font1, "PLAYER :", { 0, 0, 0, 255 });
	playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	int tw, th;
	SDL_QueryTexture(dealerTexture, 0, 0, &tw, &th);
	dealerRect = { 10, 10, tw, th };

	SDL_QueryTexture(playerTexture, 0, 0, &tw, &th);
	playerRect = { 10, wh / 2 + 10, tw, th };

	SDL_FreeSurface(tempSurfaceText);
	TTF_CloseFont(font1);

	return true;
}

void Game::render() {
	//SDL_SetRenderDrawColor(renderer, 0, 153, 0, 255); // base table color
	SDL_RenderClear(renderer);

	// drawing a line in the middle
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);

	SDL_RenderCopy(renderer, dealerTexture, NULL, &dealerRect);
	SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);

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

void Game::update() {}

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
	Game::dealerTexture = NULL;
	Game::playerTexture = NULL;
	Game::dealerRect = { 0, 0, 0, 0 };
	Game::playerRect = { 0, 0, 0, 0 };
}

Game::~Game() {
	delete window;
	delete renderer;
}
