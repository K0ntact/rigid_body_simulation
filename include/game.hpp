#ifndef GAME_HPP
#define GAME_HPP
#include <vector>

#include "SDL.h"

#include "TextureManager.hpp"
#include "gameObject.hpp"

class Game {
private:
    bool m_bRunning;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    std::vector<GameObject*> go_arr;

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

#endif //GAME_HPP
