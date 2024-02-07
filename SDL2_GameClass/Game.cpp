#include "Game.h"

int c = 0;

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::currentFrame = 3;
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
				TextureManager::Instance()->loadTexture("assets/Sprite-Sheet.jpg", "sprite_sheet", renderer);
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
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // white color
	//SDL_SetRenderDrawColor(renderer, 0xAA, 0xAA, 0xAA, 0xFF); // dark grey color
	//SDL_SetRenderDrawColor(renderer, 0xCC, 0xCC, 0xCC, 0xFF); // grey color
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // black color
	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);
	SDL_Rect fillRect = { ww / 4, wh / 4, ww / 2, wh / 2 };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // red color
	SDL_RenderFillRect(renderer, &fillRect);

	SDL_Rect outlineRect = { ww / 6, wh / 6, ww * 2 / 3, wh * 2 / 3 };
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF); // green color
	SDL_RenderDrawRect(renderer, &outlineRect);

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh  / 2);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0x00); // yellow color
	for (int i = 0; i < wh; i += 4) {
		SDL_RenderDrawPoint(renderer, ww / 2, i);
	}

	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	Shapes::drawCircle(renderer, ww / 2, wh / 2, wh / 2);

	//TextureManager::Instance()->drawOneFrameFromTexture("sprite_sheet", 0, 0, 130, 130, 1, currentFrame, renderer);
	//TextureManager::Instance()->drawOneFrameFromTexture("sprite_sheet", 0, 130, 130, 130, 2, currentFrame, renderer);

	//SDL_RenderCopy(renderer, texture, &sourceRectangle, &destinationRectangle);
	//TextureManager::Instance()->drawTexture("jpg", 0, 0, 187, 269, renderer);
	//TextureManager::Instance()->drawTexture("jpg", 0, 0, 187, 269, renderer, SDL_FLIP_HORIZONTAL);

	//TextureManager::Instance()->drawTexture("sprite_sheet", 200, 0, 187, 269, renderer);
	//TextureManager::Instance()->drawTexture("sprite_sheet", 200, 0, 187, 269, renderer, SDL_FLIP_HORIZONTAL);

	SDL_RenderPresent(renderer);
}

void Game::update() {
	//std::cout << "SDL_TICKS: " << SDL_GetTicks() << "\n";
	//std::cout << "SDL_TICKS / 150: " << int((SDL_GetTicks() / 150)) << "\n";
	//std::cout << "SDL_TICKS / 150 % 5: " << int(((SDL_GetTicks() / 150) % 5)) << "\n" << std::endl;

	//currentFrame = int(((SDL_GetTicks() / 150) % 5)); // % 5 for 5 frames
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
