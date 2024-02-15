#include "Game.h"

#include <string>

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;

	Game::running = true;
	Game::hitClick = false;

	Game::dealerTexture = NULL;
	Game::playerTexture = NULL;
	Game::scoreTexture = NULL;
	Game::scoreStrTexture = NULL;
	Game::moneyTexture = NULL;
	Game::moneyStrTexture = NULL;
	Game::betTexture = NULL;
	Game::betStrTexture = NULL;
	Game::hitBtnTexture = NULL;
	Game::stayBtnTexture = NULL;

	Game::dealerRect = { 0, 0, 0, 0 };
	Game::playerRect = { 0, 0, 0, 0 };
	Game::scoreRect = { 0, 0, 0, 0 };
	Game::scoreStrRect = { 0, 0, 0, 0 };
	Game::moneyRect = { 0, 0, 0, 0 };
	Game::moneyStrRect = { 0, 0, 0, 0 };
	Game::betRect = { 0, 0, 0, 0 };
	Game::betStrRect = { 0, 0, 0, 0 }; 
	Game::hitBtnRect = { 0, 0, 0, 0 };
	Game::stayBtnRect = { 0, 0, 0, 0 };

	Game::playerMoney = 100000;
	Game::score = Game::mouseDownX = Game::mouseDownY = 0;
	Game::bet = 100;
}

Game::~Game() {
	delete renderer;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success!\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) {
			std::cout << "Window creation success!\n";
			renderer = SDL_CreateRenderer(window, -1, 0);

			if (renderer != 0) {
				std::cout << "Renderer creation success!\n";

				TextureManager::Instance()->loadTexture("assets/table-background.jpg", "background", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/cardBack_blue3.png", "card-back", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/cardDiamondsK.png", "card-DK", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/cardSpades7.png", "card-S7", renderer);
				TextureManager::Instance()->loadTexture("assets/cards/cardHearts2.png", "card-H2", renderer);

			}
			else {
				std::cout << "Renderer init failed!\n";
				return false;
			}
		}
		else {
			std::cout << "Window init failed!\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail!\n";
		return false;
	}
	std::cout << "Init success!\n";
	running = true;

	return true;
}

bool Game::ttf_init() {
	if (TTF_Init() == -1) {
		return false;
	}

	TTF_Font* font1 = TTF_OpenFont("fonts/Arcade.ttf", 24);
	TTF_Font* font2 = TTF_OpenFont("fonts/COLONNA.ttf", 20);
	TTF_Font* font3 = TTF_OpenFont("fonts/arial.ttf", 24);

	if (font1 == NULL || font2 == NULL || font3 == NULL) {
		std::cout << "Font 1 or Font 2 or Font3 is NULL" << std::endl;
		return false;
	}

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	SDL_Surface* tempSurfaceText = NULL;

	tempSurfaceText = TTF_RenderText_Blended(font1, "DEALER :", { 0, 0, 0, 255 });
	dealerTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font1, "PLAYER :", { 0, 0, 0, 255 });
	playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font2, "Money: $", { 255, 255, 255, 255 });
	moneyStrTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	playerMoney -= bet;
	std::string t = std::to_string(playerMoney);
	char const* playerMoneyToString = t.c_str();

	tempSurfaceText = TTF_RenderText_Blended(font2, playerMoneyToString, { 255, 255, 255, 255 });
	moneyTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font2, "Score: ", { 255, 255, 255, 255 });
	scoreStrTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	score += 19;
	t = std::to_string(score);
	char const* scoreStr = t.c_str();

	tempSurfaceText = TTF_RenderText_Blended(font2, scoreStr, { 255, 255, 255, 255 });
	scoreTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font2, "Current Bet: $", { 255, 255, 255, 255 });
	betStrTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	t = std::to_string(bet);
	char const* betStr = t.c_str();

	tempSurfaceText = TTF_RenderText_Blended(font2, betStr, { 255, 255, 255, 255 });
	betTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font3, "HIT", { 255, 255, 255, 255 });
	hitBtnTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font3, "STAY", { 255, 255, 255, 255 });
	stayBtnTexture = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	int tw, th;
	SDL_QueryTexture(dealerTexture, 0, 0, &tw, &th);
	dealerRect = { 10, 10, tw, th };

	SDL_QueryTexture(playerTexture, 0, 0, &tw, &th);
	playerRect = { 10, wh / 2 + 10, tw, th };

	SDL_QueryTexture(moneyStrTexture, 0, 0, &tw, &th);
	moneyStrRect = { 10, wh / 2 + 30, tw, th };

	SDL_QueryTexture(moneyTexture, 0, 0, &tw, &th);
	moneyRect = { 85, wh / 2 + 30, tw, th };

	SDL_QueryTexture(scoreStrTexture, 0, 0, &tw, &th);
	scoreStrRect = { 10, wh / 2 + 50, tw, th };

	SDL_QueryTexture(scoreTexture, 0, 0, &tw, &th);
	scoreRect = { 70, wh / 2 + 50, tw, th };

	SDL_QueryTexture(betStrTexture, 0, 0, &tw, &th);
	betStrRect = { 10, wh / 2 + 70, tw, th };

	SDL_QueryTexture(betTexture, 0, 0, &tw, &th);
	betRect = { 125, wh / 2 + 70, tw, th };

	SDL_QueryTexture(hitBtnTexture, 0, 0, &tw, &th);
	hitBtnRect = { 30, wh / 2 + 120, tw, th };

	SDL_QueryTexture(stayBtnTexture, 0, 0, &tw, &th);
	stayBtnRect = { 30, wh / 2 + 180, tw, th };

	SDL_FreeSurface(tempSurfaceText);
	TTF_CloseFont(font1);
	TTF_CloseFont(font2);
	TTF_CloseFont(font3);

	return true;
}

void Game::render() {
	//SDL_SetRenderDrawColor(renderer, 0, 153, 0, 255); // base table color
	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); // get window size

	TextureManager::Instance()->drawTexture("background", 0, 0, ww, wh, renderer);
	TextureManager::Instance()->drawTexture("card-back", 150, 10, 140, 190, renderer);
	TextureManager::Instance()->drawTexture("card-DK", 180, wh / 2 + 20, 140, 190, renderer);
	TextureManager::Instance()->drawTexture("card-S7", 210, wh / 2 + 20, 140, 190, renderer);
	TextureManager::Instance()->drawTexture("card-H2", 240, wh / 2 + 20, 140, 190, renderer);

	// drawing a line in the middle
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);

	TextureManager::Instance()->drawRecnatgle(renderer, 10, wh / 2 + 115, 80, 40);
	TextureManager::Instance()->drawRecnatgle(renderer, 10, wh / 2 + 175, 100, 40);

	// Render texture on window
	SDL_RenderCopy(renderer, dealerTexture,   NULL, &dealerRect);
	SDL_RenderCopy(renderer, playerTexture,   NULL, &playerRect);
	SDL_RenderCopy(renderer, moneyStrTexture, NULL, &moneyStrRect);
	SDL_RenderCopy(renderer, moneyTexture,    NULL, &moneyRect);
	SDL_RenderCopy(renderer, scoreStrTexture, NULL, &scoreStrRect);
	SDL_RenderCopy(renderer, scoreTexture,    NULL, &scoreRect);
	SDL_RenderCopy(renderer, betStrTexture,   NULL, &betStrRect);
	SDL_RenderCopy(renderer, betTexture,      NULL, &betRect);
	SDL_RenderCopy(renderer, hitBtnTexture,   NULL, &hitBtnRect);
	SDL_RenderCopy(renderer, stayBtnTexture,  NULL, &stayBtnRect);

	SDL_RenderPresent(renderer);
}

void Game::update() {}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		int msx, msy;

		switch (event.type) {
		case SDL_QUIT: running = false; break;
		case SDL_MOUSEBUTTONDOWN: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				Game::mouseDownX = msx;
				Game::mouseDownY = msy;
			}
		}; break;
		case SDL_MOUSEBUTTONUP: {
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msx, &msy);
				Game::isClicked(mouseDownX, mouseDownY, msx, msy);
			}
		}

		default: break;
		}
	}
}

void Game::clean() {
	std::cout << "Cleaning game!\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() const {
	return Game::running;
}

void Game::isClicked( int xDown, int yDown, int xUp, int yUp) {
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	int hitBtnX = 10;
	int hitBtnY = wh / 2 + 115;
	int hitBtnW = 80;
	int hitBtnH = 40;

	if ((xDown > hitBtnX && xDown < (hitBtnX + hitBtnW)) && (xUp > hitBtnX && xUp < (hitBtnX + hitBtnW)) &&
		(yDown > hitBtnY && yDown < (hitBtnY + hitBtnH)) && (yUp > hitBtnY && yUp < (hitBtnY + hitBtnH))) {
		Game::hitClick = true;
		std::cout << "Hit BTN is clicked!" << std::endl;
		
		return;
	}

	int stayBtnX = 10;
	int stayBtnY = wh / 2 + 175;
	int stayBtnW = 100;
	int stayBtnH = 40;

	if ((xDown > stayBtnX && xDown < (stayBtnX + stayBtnW)) && (xUp > stayBtnX && xUp < (stayBtnX + stayBtnW)) &&
		(yDown > stayBtnY && yDown < (stayBtnY + stayBtnH)) && (yUp > stayBtnY && yUp < (stayBtnY + stayBtnH))) {
		//Game::hitClick = true;
		std::cout << "Stay BTN is clicked!" << std::endl;

		return;
	}
}
