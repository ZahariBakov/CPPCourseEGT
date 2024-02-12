#include "Game.h"

Game* game = NULL;

const int WINDOW_WIDTH = 1280;
const int WINDOWS_HEIGHT = 720;

int main(int argc, char* argv[]) {
	const int FPS = 60;
	const int frameDelay = 1500 / FPS;

	Uint32 frameStrart;
	int frameTime;

	game = new Game();

	game->init("SDL image window", // Title of window
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // X and Y be centered 
		WINDOW_WIDTH, WINDOWS_HEIGHT, // Get size of window from constatnts
		SDL_WINDOW_RESIZABLE); // Make window resizable

	while (game->isRunning()) {
		frameStrart = SDL_GetTicks();

		game->handleEvent();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStrart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}