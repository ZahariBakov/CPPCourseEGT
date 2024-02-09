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

void Game::render() {
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: {
				if (event.key.keysym.sym == SDLK_0) {
					SoundManager::Instance()->changeVolume(1);
					SoundManager::Instance()->changeVolumeSfk("woosh", 1);
				}
				if (event.key.keysym.sym == SDLK_9) {
					SoundManager::Instance()->changeVolume(-1);
					SoundManager::Instance()->changeVolumeSfk("woosh", -1);
				}
				if (event.key.keysym.sym == SDLK_SPACE) {
					SoundManager::Instance()->pauseOrPlay();
				}
				if (event.key.keysym.sym == SDLK_5) {
					SoundManager::Instance()->setMusicPosition(20.00);
				}
			}

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

void Game::LoadAndPlaySound() {
	SoundManager::Instance()->load("assets/rf-16.mp3", "bg_music", 1);
	SoundManager::Instance()->load("assets/gamer-213.wav", "game_over", 0);
	SoundManager::Instance()->load("assets/noti-212.wav", "notification", 0);
	SoundManager::Instance()->load("assets/woosh-89.wav", "woosh", 0);

	SoundManager::Instance()->playMusic("bg_music", 0, 5000);
	//SoundManager::Instance()->playSound("woosh", -1, 0);
}

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
}

Game::~Game() {
	delete window;
	delete renderer;
}
