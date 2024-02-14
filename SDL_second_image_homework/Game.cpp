#include "Game.h"

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::mouseDownX = 0;
	Game::mouseDownY = 0;
	Game::mouseDown = 0;
	Game::mouseUp = 0;
}

Game::~Game() {
	delete window;
	delete renderer;
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

				TextureManager::Instance()->loadTexture("assets/dog-small.png", "dog", renderer);
				TextureManager::Instance()->loadTexture("assets/cat-small.png", "cat", renderer);
				TextureManager::Instance()->loadTexture("assets/bunny-small.png", "bunny", renderer);
				TextureManager::Instance()->loadTexture("assets/hedgehog-small.png", "hedgehog", renderer);
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

	std::cout << "Init succes!\n";
	running = true;

	return true;
}

void Game::render() {
	// set window background
	SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);

	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	TextureManager::Instance()->drawTexture("dog", 0, 0, ww / 2, wh / 2, renderer);
	TextureManager::Instance()->drawTexture("cat", ww / 2, 0, ww / 2, wh / 2, renderer);
	TextureManager::Instance()->drawTexture("bunny", 0, wh / 2, ww / 2, wh / 2, renderer);
	TextureManager::Instance()->drawTexture("hedgehog", ww / 2, wh / 2, ww / 2, wh / 2, renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, ww / 2, 0, ww / 2, wh);
	SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);

	SDL_RenderPresent(renderer);
}

void Game::update() {}

void Game::handleEvent() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		int msx, msy, ww, wh;
		SDL_GetWindowSize(window, &ww, &wh);

		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		case SDL_MOUSEBUTTONDOWN: {
			
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				mouseDownX = msx;
				mouseDownY = msy;
				Game::mouseDown = (msx > ww / 2) + (msy > wh / 2) * 10;
			}
		}; break;
		case SDL_MOUSEBUTTONUP: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				Game::mouseUp = (msx > ww / 2) + (msy > wh / 2) * 10;
				switch (Game::mouseUp) {
					case 0:
						if (Game::mouseDown == 0) {
							TextureManager::Instance()->toggleVisibility("dog");
						}
						break;
					case 1:
						if (Game::mouseDown == 1) {
							TextureManager::Instance()->toggleVisibility("cat");
						}
						break;
					case 10:
						if (Game::mouseDown == 10) {
							TextureManager::Instance()->toggleVisibility("bunny");
						}
						break;
					case 11:
						if (Game::mouseDown == 11) {
							TextureManager::Instance()->toggleVisibility("hedgehog");
						}
						break;

					default:
						break;
				}
			}
		}

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