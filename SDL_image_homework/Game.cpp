#include "Game.h"

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::currentFrame = 0;
}

Game::~Game() {
	//delete window;
	//delete renderer;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success!\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window != 0) {
			std::cout << "Window creation success!\n";

			renderer = SDL_CreateRenderer(window, -1, 0);

			if (renderer != 0) {
				std::cout << "Renderer creation success!\n";

				// set white color for background
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				// Add picture to window
				TextureManager::Instance()->loadTexture("assets/soldier.png", "soldier", renderer);
				TextureManager::Instance()->loadTexture("assets/car.png", "car", renderer);
				TextureManager::Instance()->loadTexture("assets/cat-sprite.png", "cat-sprite", renderer);

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
		std::cout << "SDL init failed!\n";
		return false;
	}

	std::cout << "Init success!\n";
	running = true;

	return true;
}

void Game::render() {
	SDL_RenderClear(renderer);

	//TextureManager::Instance()->drawTexture("soldier", 200, 0, 640, 521, renderer);
	//TextureManager::Instance()->drawTexture("soldier", 200, 0, 640, 521, renderer, SDL_FLIP_HORIZONTAL);

	TextureManager::Instance()->drawTexture("car", 0, 0, 225, 225, renderer);
	//TextureManager::Instance()->drawTexture("car", 1055, 220, 225, 225, renderer, SDL_FLIP_HORIZONTAL);

	TextureManager::Instance()->drawOneFrameFromTexture("cat-sprite", 0, 300, 221, 150, 1, currentFrame, renderer);

	SDL_RenderPresent(renderer);
}

void Game::update() {
	currentFrame = int(((SDL_GetTicks() / 150) % 5));
}

void Game::handleEvent() {
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
	std::cout << "Cleaning game!" << std::endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() const {
	return Game::running;
}
