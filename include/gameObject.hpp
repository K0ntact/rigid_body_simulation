#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>

#include "SDL.h"

#include "particle2d.hpp"

class GameObject : public Particle2D {
protected:
    std::string m_textureID;
//    currently not needed
//    int m_currentFrame;
//    int m_currentRow;

    int m_width;
    int m_height;

public:
    /**
     * Construct a new Game Object from a texture ID.
     * (x, y) is the position of the object's top left corner.
     * @param x x position on the screen
     * @param y y position on the screen
     * @param width width of the object
     * @param height height of the object
     * @param textureID the ID of the texture
     */
    virtual void load(int x, int y, int width, int height, std::string textureID);

    /**
     * Draw the object on the screen
     * @param pRenderer the renderer to draw the object
     */
    virtual void draw(SDL_Renderer* pRenderer);

    /**
     * Update the object
     * @param time time elapsed since last update
     */
    virtual void update(float time) override;
    virtual void clean();
};


#endif //GAMEOBJECT_HPP
