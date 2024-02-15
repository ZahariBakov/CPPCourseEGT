#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "TextureManager.h"

class Game {
public:
	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	bool ttf_init();

	void render();
	void update();
	void handleEvents();
	void clean();

	bool isRunning() const;
	void isClicked(int xDown, int yDown, int xUp, int yUp);

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running, hitClick;

	SDL_Texture* dealerTexture,
		* playerTexture,
		* scoreTexture,
		* scoreStrTexture,
		* moneyTexture,
		* moneyStrTexture,
		* betStrTexture,
		* betTexture,
		* hitBtnTexture,
		* stayBtnTexture;

	SDL_Rect dealerRect,
		playerRect,
		scoreRect,
		scoreStrRect,
		moneyRect,
		moneyStrRect,
		betStrRect,
		betRect,
		hitBtnRect,
		stayBtnRect;

	int playerMoney, score, bet, mouseDownX, mouseDownY;
};
