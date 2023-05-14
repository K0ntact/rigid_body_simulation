#include <iostream>
#include "game.hpp"

Game::Game() {
    m_bRunning = false;
    m_pWindow = nullptr;
    m_pRenderer = nullptr;
    m_pTexture = nullptr;
}

Game::~Game() {
    if (m_pRenderer) {
        SDL_DestroyRenderer(m_pRenderer);
        m_pRenderer = nullptr;
    }
    if (m_pWindow) {
        SDL_DestroyWindow(m_pWindow);
        m_pWindow = nullptr;
    }
}

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int fullscreen) {
    // SDL init
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        const char* error = SDL_GetError();
        std::cout<< "SDL Init fail: " << error << "\n";
        return false;
    }

    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_SHOWN;
    }

    // Window init
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(m_pWindow == nullptr) {
        const char* error = SDL_GetError();
        std::cout<< "Window Init fail: " << error << "\n";
        return false;
    }

    // Renderer init
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    if(m_pRenderer == nullptr) {
        const char* error = SDL_GetError();
        std::cout<< "Renderer Init fail: " << error << "\n";
        return false;
    }

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    m_bRunning = true;

    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    SDL_QueryTexture(m_pTexture, NULL, NULL,
                    &m_sourceRectangle.w,
                    &m_sourceRectangle.h);

    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;

    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

void Game::update() {}

void Game::handleEvents() {
    SDL_Event event;
    if(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;

                // TODO: implement more events

            default:
                break;  // TODO: implement default case
        }
    }
}

void Game::clean() {
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}