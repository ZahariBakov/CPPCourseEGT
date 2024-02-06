#include <iostream>
#include <SDL.h>

const int FPS = 30;

void limitFPS(Uint32 startingTick) {
	if ((1000 / FPS) > SDL_GetTicks() - startingTick) {
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - startingTick));
	}
}

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = nullptr;

	SDL_Renderer* renderer = nullptr;

	window = SDL_CreateWindow("Hello World!", 
							  SDL_WINDOWPOS_CENTERED, 
							  SDL_WINDOWPOS_CENTERED, 
		                      600, 400, 0);

	renderer = SDL_CreateRenderer(window, -1, 0);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	bool running = true;
	SDL_Event event;
	Uint32 startingTick;

	while (running) {
		startingTick = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		limitFPS(startingTick);
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	
	return 0;
}
