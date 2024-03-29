#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "TextureManager.h"

class Game {
public:
	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void update();
	void handleEvent();
	void clean();

	bool isRunning() const;

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;
	int mouseDownX, mouseDownY;
	int mouseDown, mouseUp;

	SDL_RendererFlip frameFlip = SDL_FLIP_NONE;
	int currentFrame;
	int currentRow;
};
