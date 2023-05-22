#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>

#include "SDL.h"

class GameObject {
protected:
    std::string m_textureID;

//    currently not needed
//    int m_currentFrame;
//    int m_currentRow;

    int m_x;
    int m_y;

    int m_width;
    int m_height;

public:
    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();
    virtual void clean();
};


#endif //GAMEOBJECT_HPP
