#include "Game.h"

int c = 0;

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
}

Game::~Game() {}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window != 0) { // window init success
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);

			if (renderer != 0) { // renderer init success
				std::cout << "renderer streation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				TextureManager::Instance()->loadTexture("assets/images.jpg", "jpg", renderer);
			}
			else {
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "window init failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail\n";
		return false;
	}

	std::cout << "init success\n";
	running = true;
	return true;
}

void Game::render() {
	SDL_RenderClear(renderer);

	//SDL_RenderCopy(renderer, texture, &sourceRectangle, &destinationRectangle);
	TextureManager::Instance()->drawTexture("jpg", 0, 0, 187, 269, renderer);
	TextureManager::Instance()->drawTexture("jpg", 200, 0, 187, 269, renderer, SDL_FLIP_HORIZONTAL);

	SDL_RenderPresent(renderer);
}

void Game::update() {
}

void Game::handleEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;

		default:
			break;
		}
	}
}

void Game::clean() {
	std::cout << "cleaning game\n";

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return Game::running;
}
