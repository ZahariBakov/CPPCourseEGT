#include "Game.h"
static int mrSmallX = 288;
static int mrSmallY = 148;

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

				TextureManager::Instance()->loadTexture("assets/mr.small.png", "small", renderer);
				TextureManager::Instance()->toggleVisibility("small");
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
	TextureManager::Instance()->drawTexture("small", mrSmallX, mrSmallY, 64, 64, renderer);

	TextureManager::Instance()->drawRecnatgle(renderer, 0, 0, 40, 20, 2);

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
				Game::mouseDown = (msx > ww / 2) + (msy > wh / 2) * 2;
			}

			if (event.button.button == SDL_BUTTON_RIGHT) {
				SDL_GetMouseState(&msx, &msy);
				mrSmallX = msx - 32;
				mrSmallY = msy - 32;
			}
		}; break;
		case SDL_MOUSEBUTTONUP: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				Game::mouseUp = (msx > ww / 2) + (msy > wh / 2) * 2;
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
					case 2:
						if (Game::mouseDown == 2) {
							TextureManager::Instance()->toggleVisibility("bunny");
						}
						break;
					case 3:
						if (Game::mouseDown == 3) {
							TextureManager::Instance()->toggleVisibility("hedgehog");
						}
						break;

					default:
						break;
				}
			}
		}
		case SDL_KEYDOWN: {
			if (event.key.keysym.sym == SDLK_UP && mrSmallY > 0) {
				mrSmallY -= 5;
			}
			if (event.key.keysym.sym == SDLK_DOWN && mrSmallY < wh - 64) {
				mrSmallY += 5;
			}
			if (event.key.keysym.sym == SDLK_LEFT && mrSmallX > 0) {
				mrSmallX -= 5;
			}
			if (event.key.keysym.sym == SDLK_RIGHT && mrSmallX < ww - 64) {
				mrSmallX += 5;
			}
		}; break;
		case SDL_MOUSEMOTION: {
			SDL_GetMouseState(&msx, &msy);
			TextureManager::rgb[0] = (int)(((double)msx / ww) * 255);
			TextureManager::rgb[1] = (int)(((double)msy / wh) * 255);
			TextureManager::rgb[2] = (int)(((((double)msx / ww) + ((double)msy / wh)) / 2) * 255);
		}; break;

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