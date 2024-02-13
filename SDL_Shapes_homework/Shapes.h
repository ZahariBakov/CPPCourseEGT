#pragma once

#include "Game.h"

class Shapes {
public:
	static void drawRecnatgle(SDL_Renderer* renderer, int xpos, int ypos, int width, int height, int border);
	static void drawPentagon(SDL_Renderer* renderer, int xpos, int ypos, int side);
	static void drawHexagon(SDL_Renderer* renderer, int xpos, int ypos, int side);
	static void drawCircle(SDL_Renderer* renderer, int xpos, int ypos, int radius);
	static void drawPolygon(SDL_Renderer* renderer, int xpos, int ypos, int side, int radius);
	static void drawEllipse(SDL_Renderer* renderer, int xRad, int yRad, int xpos, int ypos);

};
