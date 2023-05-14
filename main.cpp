#include <iostream>
#include <windows.h>

#include "SDL.h"

#include "game.hpp"

Game* g_game = nullptr;

int main(int argc, char* argv[]) {
    // for print log out to console
    AllocConsole();
    freopen("CON", "w", stdout);

    g_game = new Game();
    g_game->init("Chapter 1", 100, 100, 640, 480, true);

    while(g_game->running()) {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();

    return 0;
}

