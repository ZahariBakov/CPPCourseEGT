#include "TextureManager.h"

int TextureManager::rgb[3] = { 0, 0, 0 };

bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* ren) {
    SDL_Surface* tempSurface = IMG_Load(fileName);

    if (tempSurface == 0) {
        std::cout << "tempSurface not created!" << std::endl;
        return false;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface); //create texture
    SDL_FreeSurface(tempSurface); //delete surface

    if (tex != 0) {
        textureMap[id] = tex; //add the created texture in the textureMap map
        display[id] = 0; //set display of the texture initially to hidden
        return true;
    }

    return false;
}

void TextureManager::drawTexture(std::string id, int x, int y, int width, int height, SDL_Renderer* ren, SDL_RendererFlip flip) {
    if (display[id]) { //check if texture is hidden
        SDL_Rect srcRect;
        SDL_Rect destRect;
        srcRect.x = srcRect.y = 0;
        srcRect.w = destRect.w = width;
        srcRect.h = destRect.h = height;
        destRect.x = x;
        destRect.y = y;

        SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip); //paint on renderer
    }
    else { 
        return; 
    }
}

void TextureManager::drawOneFrameFromTexture(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, 
                                                                                           SDL_Renderer* ren, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::toggleVisibility(std::string id) {
    bool visibility = display[id];

    if (visibility) {
        visibility = false;
    }
    else {
        visibility = true;
    }

    display[id] = visibility;
}

TextureManager* TextureManager::Instance() {
    if (instance == 0) {
        instance = new TextureManager();

        return instance;
    }

    return instance;
}

void TextureManager::drawRecnatgle(SDL_Renderer* renderer, int xpos, int ypos, int width, int height, int border) {
    SDL_Rect fillRect = { xpos, ypos, width, height };
    SDL_SetRenderDrawColor(renderer, TextureManager::rgb[0], TextureManager::rgb[1], TextureManager::rgb[2], 255);
    SDL_RenderFillRect(renderer, &fillRect);

    SDL_Rect secondFillRect = { xpos + border, ypos + border, width - (border * 2), height - (border * 2) };
    SDL_SetRenderDrawColor(renderer, TextureManager::rgb[2], TextureManager::rgb[0], TextureManager::rgb[1], 255);
    SDL_RenderFillRect(renderer, &secondFillRect);
}

TextureManager* TextureManager::instance = 0;
