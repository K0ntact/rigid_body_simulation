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

    /**
     * Initialize the game
     *
     * @param title title of the window
     * @param xpos x position on the screen
     * @param ypos y position on the screen
     * @param width width of the window
     * @param height height of the window
     * @param screenOpt screen option. See SDL_WindowFlags enum
     *
     * @return true if initialization is successful, false otherwise
     */
    bool init(const char* title, int xpos, int ypos, int width, int height, int screenOpt);

    /**
     * Render all game objects
     */
    void render();

    /**
     * Update all game objects
     *
     * @param time time elapsed since last update
     */
    void update(float time);

    /**
     * Handle events and input
     */
    void handleEvents();

    /**
     * Clean up the game
     */
    void clean();

    bool running() const {
        return m_bRunning;
    }
};

#endif //GAME_HPP
