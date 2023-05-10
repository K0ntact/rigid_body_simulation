#include <iostream>
#include "header/game.h"

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) {
    // SDL init
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        const char* error = SDL_GetError();
        std::cout<< "SDL Init fail: " << error << "\n";
        return false;
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