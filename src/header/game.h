#ifndef GAME_H_
#define GAME_H_

#include "SDL.h"

class Game {
private:
    bool m_bRunning;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

public:
    Game();
    ~Game(); // Destructor

    bool init(const char* title, int xpos, int ypos, int width, int height, int fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() const {
        return m_bRunning;
    }
};

#endif //GAME_H_
