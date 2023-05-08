#include <SDL.h>

#include <iostream>

SDL_Window* g_pWindow = nullptr;
SDL_Renderer* g_pRenderer = nullptr;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL init failed" << std::endl;
        return false;
    }
    g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    // if the window creation succeeded create our renderer
    if(g_pWindow != nullptr) {
        g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
    return true;
}

void render() {
    // set to black
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    // clear the window to black
    SDL_RenderClear(g_pRenderer);
    // show the window
    SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* argv[]) {
    if(init("Chapter 1: Setting up SDL",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640, 480,
            SDL_WINDOW_SHOWN))
    {
        g_bRunning = true;
    } else {
        return 1; // something's wrong
    }

    while(g_bRunning) {
        render();
    }

    // wait 5 seconds
    SDL_Delay(5000);

    // clean up SDL
    SDL_Quit();

    return 0;
}

