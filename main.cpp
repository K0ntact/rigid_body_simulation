#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

#include "SDL.h"

#include "game.hpp"

typedef std::chrono::high_resolution_clock Clock;

int FPS = 60;
int DELAY_TIME = 1000 / FPS;

Game* g_game = nullptr;

int main(int argc, char* argv[]) {
    // for print log out to console
    AllocConsole();
    freopen("CON", "w", stdout);


    Game::Instance()->init("Chapter 1", 100, 100, 640, 480, true);

    float dt = 10;

    while(Game::Instance()->running()) {
        auto frameStart = Clock::now();

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        Game::Instance()->handleEvents();

        Game::Instance()->update(dt/1000);
        Game::Instance()->render();

        dt = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - frameStart).count();

//        unsigned int frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - frameStart).count();
//    unsigned int frameTime = SDL_GetTicks() - frameStart;
//    if (frameTime < DELAY_TIME) {   // To cap frame rate = FPS
//            unsigned int frameDelay = DELAY_TIME - frameTime;
//            SDL_Delay(frameDelay);
//        }
    }
    Game::Instance()->clean();

    return 0;
}

