#include "Game.h"

#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			}
			else {
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "window init failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	running = true;
	return true;
}

bool Game::ttf_init() {
	if (TTF_Init() == -1) {
		return false;
	}

	TTF_Font* font1 = TTF_OpenFont("fonts/Arcade.ttf", 48);
	TTF_Font* font2 = TTF_OpenFont("fonts/segoepr.ttf", 72);

	if (font1 == NULL || font2 == NULL) {
		return false;
	}

	SDL_Surface* tempSurfaceText = NULL;

	tempSurfaceText = TTF_RenderText_Blended(font1, "Hello World!", { 0, 0, 255, 255 });
	textTextureFont1 = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font2, "Hello World!", { 0, 0, 255, 255 });
	textTextureFont2 = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended_Wrapped(font1, "Hello World!\nThis wraps the text.", { 0, 255, 0, 255 }, 300);
	textTextureFont1Wrapped = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended_Wrapped(font2, "Hello World!\nThis wraps the text.", { 255, 0, 255, 255 }, 500);
	textTextureFont2Wrapped = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	int tw, th;
	SDL_QueryTexture(textTextureFont1, 0, 0, &tw, &th);
	dRectFont1 = { 10, 10 ,tw, th };

	SDL_QueryTexture(textTextureFont2, 0, 0, &tw, &th);
	dRectFont2 = { 10, 320 ,tw, th };

	SDL_QueryTexture(textTextureFont1Wrapped, 0, 0, &tw, &th);
	dRectFont1Wrapped = { 650, 10 ,tw, th };

	SDL_QueryTexture(textTextureFont2Wrapped, 0, 0, &tw, &th);
	dRectFont2Wrapped = { 650, 320 ,tw, th };

	SDL_FreeSurface(tempSurfaceText);
	TTF_CloseFont(font1);
	TTF_CloseFont(font2);

	return true;
}

void Game::render() {
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, textTextureFont1, NULL, &dRectFont1);
	SDL_RenderCopy(renderer, textTextureFont2, NULL, &dRectFont2);
	SDL_RenderCopy(renderer, textTextureFont1Wrapped, NULL, &dRectFont1Wrapped);
	SDL_RenderCopy(renderer, textTextureFont2Wrapped, NULL, &dRectFont2Wrapped);

	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: running = false; break;
		default: break;
		}
	}
}

void Game::update() {

}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return Game::running;
}

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::dRectFont1 = { 0, 0, 0, 0 };
	Game::dRectFont2 = { 0, 0, 0, 0 };
	Game::dRectFont1Wrapped = { 0, 0, 0, 0 };
	Game::dRectFont2Wrapped = { 0, 0, 0, 0 };
	Game::textTextureFont1 = NULL;
	Game::textTextureFont2 = NULL;
	Game::textTextureFont1Wrapped = NULL;
	Game::textTextureFont2Wrapped = NULL;
}

Game::~Game() {
	delete window;
	delete renderer;
}