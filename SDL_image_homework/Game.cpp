#include "Game.h"
#include "TextureManager.h"

static int speed = 5;
static int speedSecondCar = 5;
const  int maxSpeed = 20;
static int lap = 1;
static int secondImageX = 0;
SDL_RendererFlip flipCar = SDL_FLIP_NONE;

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::currentFrame = 0;
	Game::destRectangle.x = destRectangle.y = destRectangle.w = destRectangle.h = 0;
	Game::srcRectangle.x = srcRectangle.y = srcRectangle.w = srcRectangle.h = 0;
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

				TextureManager::Instance()->loadTexture("assets/small-car.png", "car", renderer);
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

	// Render the first image
	SDL_RenderCopy(renderer, texture, &srcRectangle, &destRectangle);

	// Get the window size
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	// Render the second image
	TextureManager::Instance()->drawTexture("car", secondImageX, 0, 64, 64, renderer, flipCar);

	if (secondImageX >= (ww - destRectangle.w)) {
		flipCar = SDL_FLIP_HORIZONTAL;
	}

	if (secondImageX <= 0) {
		secondImageX = 0;
		flipCar = SDL_FLIP_NONE;
	}

	if (flipCar != SDL_FLIP_HORIZONTAL) {
		secondImageX++;
	}
	else {
		secondImageX--;
	}

	SDL_RenderPresent(renderer);
}


void Game::update() {
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	destRectangle.y = (wh - destRectangle.h) / 2;

	destRectangle.x += speed;

	if (destRectangle.x >= (ww - destRectangle.w)) {
		destRectangle.x = ww - destRectangle.w;
		speed *= -1;
		speed--;

		std::cout << "Speed is: " << abs(speed) << std::endl;
	}

	if (destRectangle.x <= 0) {
		destRectangle.x = 0;
		speed *= -1;
		speed++;

		lap++;

		std::cout << "Lap is: " << lap << "\nSpeed is: " << speed << std::endl;
	}

	if (speed >= maxSpeed) {
		speed = maxSpeed;
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
