#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

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

	bool isRunning();
	bool isClickableTextureClicked(SDL_Texture* t, SDL_Rect* r, int xDown, int yDown, int xUp, int yUp);

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;
	SDL_Texture* textTextureFont1, 
			   * textTextureFont2, 
			   * textTextureFont1Wrapped, 
			   * textTextureFont2Wrapped;
	SDL_Rect dRectFont1, dRectFont2, 
		dRectFont1Wrapped, dRectFont2Wrapped;
	SDL_Texture* clickableTexture;
	SDL_Rect clickableRect;
	int mouseDownX, mouseDownY;
};
