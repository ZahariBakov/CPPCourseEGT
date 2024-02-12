#pragma once

#include "Game.h"

class Shapes {
public:
	static void drawRecnatgle(SDL_Renderer* renderer, int xpos, int ypos, int width, int height, int border);
	static void drawPentagon(SDL_Renderer* renderer, int centerX, int centerY, int side);
	static void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius);

};
