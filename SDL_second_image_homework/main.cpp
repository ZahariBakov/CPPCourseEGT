#include "Game.h"

Game* game = NULL;

const int WINDOW_WIDTH = 640;
const int WINDOWS_HEIGHT = 360;

int main(int argc, char* argv[]) {

	game = new Game();

	game->init("SDL image window", // Title of window
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // X and Y be centered 
		WINDOW_WIDTH, WINDOWS_HEIGHT, // Get size of window from constatnts
		SDL_WINDOW_RESIZABLE); // Make window resizable

	while (game->isRunning()) {
		game->handleEvent();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}
