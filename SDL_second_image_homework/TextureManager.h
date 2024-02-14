#pragma once

#include "Game.h"

#include <map>

class TextureManager {
public:
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren);

	void drawTexture(std::string id,int x, int y, int width, int height, SDL_Renderer* ren, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void toggleVisibility(std::string id);

	static TextureManager* Instance();

private:
	std::map<std::string, SDL_Texture*> textureMap; //map to store the loaded textures with loadTexture
	std::map<std::string, bool> display; //map to store instruction for displaying the loaded textures
	TextureManager() {}
	static TextureManager* instance;
};
