#include <iostream>
#include <windows.h>

#include "SDL.h"

#include "game.hpp"

int FPS = 60;
int DELAY_TIME = 1000 / FPS;

Game* g_game = nullptr;

int main(int argc, char* argv[]) {
    // for print log out to console
    AllocConsole();
    freopen("CON", "w", stdout);


    Game::Instance()->init("Chapter 1", 100, 100, 640, 480, true);

    while(Game::Instance()->running()) {
        unsigned int frameStart = SDL_GetTicks();

        Game::Instance()->handleEvents();
        Game::Instance()->update(DELAY_TIME);
        Game::Instance()->render();

        unsigned int frameTime = frameStart - SDL_GetTicks();
        if (frameTime < DELAY_TIME) {   // To cap frame rate = FPS
            unsigned int frameDelay = DELAY_TIME - frameTime;
            SDL_Delay(frameDelay);
        }
    }
    Game::Instance()->clean();

    return 0;
}

