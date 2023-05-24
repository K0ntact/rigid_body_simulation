#include <iostream>

#include "game.hpp"
#include "gameObject.hpp"

const Vector2 GRAVITY = {0, 20};

Game::Game() {
    m_bRunning = false;
    m_pWindow = nullptr;
    m_pRenderer = nullptr;
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

Game* Game::s_pInstance = nullptr;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int screenOpt) {
    // SDL init
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        const char* error = SDL_GetError();
        std::cout<< "SDL Init fail: " << error << "\n";
        return false;
    }

    int flags = 0;
    if(screenOpt) {
        flags = SDL_WINDOW_RESIZABLE;
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

    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
    m_bRunning = true;

    bool load_result = TextureManager::Instance()->load("..\\assets\\platform\\arc2.png", "animate", m_pRenderer);
    if(!load_result) {
        std::cout << "TextureManager Instance error" << std::endl;
        return false;
    }

    GameObject* gobj1 = new GameObject();
    gobj1->load(0, 0, 34, 42, "animate");
    go_arr.push_back(gobj1);

    return true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);

    std::vector<GameObject*>::iterator go_iter;
    for(go_iter = go_arr.begin(); go_iter != go_arr.end(); ++go_iter) {
        (*go_iter)->draw(m_pRenderer);
    }

    SDL_RenderPresent(m_pRenderer);
}

void Game::update(float time) {
    std::vector<GameObject*>::iterator go_iter;
    for(go_iter = go_arr.begin(); go_iter != go_arr.end(); ++go_iter) {
        (*go_iter)->addForce(GRAVITY);
        (*go_iter)->update(time);
        (*go_iter)->clearAccum();   // clear all external forces before next update
    }
}

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
    std::cout << "cleaning game" << std::endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}