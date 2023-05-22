#include <iostream>
#include <windows.h>

#include "SDL.h"

#include "game.hpp"

Game* g_game = nullptr;

int main(int argc, char* argv[]) {
    // for print log out to console
    AllocConsole();
    freopen("CON", "w", stdout);


    Game::Instance()->init("Chapter 1", 100, 100, 640, 480, true);

    while(Game::Instance()->running()) {
        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();
        SDL_Delay(10);
    }
    Game::Instance()->clean();

    return 0;
}

