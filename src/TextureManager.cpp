#include <iostream>

#include "SDL_image.h"

#include "TextureManager.hpp"

TextureManager::TextureManager() = default;
TextureManager::~TextureManager() = default;

TextureManager* TextureManager::s_pInstance = nullptr;

bool TextureManager::load(const std::string& fileName,
                          const std::string& id,
                          SDL_Renderer *pRenderer) {
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if(pTempSurface == 0) {
        std::cout << "IMG_Load Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    if(pTexture == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // add the texture to map
    m_textureMap[id] = pTexture;
    return true;
}

void TextureManager::draw(const std::string& id,
                          int x, int y, int width, int height,
                          SDL_Renderer *pRenderer,
                          SDL_RendererFlip flip) {
    SDL_Rect srcRect;   // the texture
    SDL_Rect destRect;  // the screen

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    //
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(const std::string& id,
                               int x, int y, int width, int height,
                               int currentRow, int currentFrame,
                               SDL_Renderer *pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}




