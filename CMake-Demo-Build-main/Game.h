//Game.h
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Shapes.h"
class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	void updateGame(bool toRun, int frames = 10, int speed = 100);
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;
	int currentFrame;
	bool anim_state = false;
	SDL_RendererFlip frameFlip = SDL_FLIP_NONE;
	int SpriteX = 0, SpriteY = 0;
};
