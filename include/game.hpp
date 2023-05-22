#ifndef GAME_HPP
#define GAME_HPP
#include <vector>

#include "SDL.h"

#include "TextureManager.hpp"
#include "gameObject.hpp"

class Game {
private:
    static Game* s_pInstance;
    Game();

    bool m_bRunning;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    std::vector<GameObject*> go_arr;

public:
    static Game* Instance() {
        if(s_pInstance == nullptr) {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    ~Game();

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
