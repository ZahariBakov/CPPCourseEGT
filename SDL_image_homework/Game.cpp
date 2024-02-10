#include "Game.h"

static int speed = 5;
const  int maxSpeed = 30;
static int lap = 1;

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = NULL;
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

				// set white color for background
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				// add picture to window
				SDL_Surface* tmpSurface = IMG_Load("assets/small-car.png");
				texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
				SDL_FreeSurface(tmpSurface);

				SDL_QueryTexture(texture, NULL, NULL, &srcRectangle.w, &srcRectangle.h);

				srcRectangle.x = 0;
				srcRectangle.y = 0;
				srcRectangle.w = 64;
				srcRectangle.h = 64;

				destRectangle.x = 0;
				destRectangle.y = 0;
				destRectangle.w = srcRectangle.w;
				destRectangle.h = srcRectangle.h;
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
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, texture, &srcRectangle, &destRectangle);

	SDL_RenderPresent(renderer);
}

void Game::update() {
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	// Center the image vertically
	destRectangle.y = (wh - destRectangle.h) / 2;

	if (SDL_GetTicks() % 50 == 0) {
		destRectangle.x += speed;

		if (destRectangle.x >= (ww - destRectangle.w)) {
			destRectangle.x = ww - destRectangle.w;
			speed *= -1;
			speed--;

			if (speed == maxSpeed) {
				speed = maxSpeed;
			}	

			std::cout << "Speed is: " << abs(speed) << std::endl;
		}

		if (destRectangle.x <= 0) {
			destRectangle.x = 0;
			speed *= -1;
			speed++;

			lap++;

			if (speed == maxSpeed) {
				speed = maxSpeed;
			}

			std::cout << "Lap is: " << lap << "\nSpeed is: " << speed << std::endl;
		}
	}
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
