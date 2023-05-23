#include <iostream>

#include "SDL_image.h"

#include "TextureManager.hpp"

TextureManager::TextureManager() = default;
TextureManager::~TextureManager() = default;

TextureManager* TextureManager::s_pInstance = nullptr;

bool TextureManager::load(const std::string filePath,
                          const std::string id,
                          SDL_Renderer *pRenderer) {
    SDL_Surface* pTempSurface = IMG_Load(filePath.c_str());
    if(pTempSurface == 0) {
        std::cout << "IMG_Load Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);  // we only need the texture, not the surface
    if(pTexture == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_textureMap[id] = pTexture;
    return true;
}

void TextureManager::draw(const std::string id,
                          int x, int y, int width, int height,
                          SDL_Renderer *pRenderer,
                          SDL_RendererFlip flip) {
    SDL_Rect srcRect;   // the texture
    SDL_Rect destRect;  // the screen

    srcRect.x = 0;
    srcRect.y = 0;

    // If destRect width and height are bigger than srcRect, the image will be stretched larger.
    // If it is smaller, then the image will be shrunk.
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

// For drawing sprite sheets
void TextureManager::drawFrame(const std::string id,
                               int x, int y, int width, int height,
                               int currentRow, int currentFrame,
                               SDL_Renderer *pRenderer,
                               SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * currentRow;

    // If destRect width and height are bigger than srcRect, the image will be stretched larger.
    // If it is smaller, then the image will be shrunk.
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}