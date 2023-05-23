#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <string>

#include "SDL.h"

#include "particle2d.hpp"

class GameObject : public Particle2D {
private:
    bool out_of_bounds_x = false;
    bool out_of_bounds_y = false;

protected:
    std::string m_textureID;

//    currently not needed
//    int m_currentFrame;
//    int m_currentRow;

    int m_width;
    int m_height;

public:
    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update(float time);
    virtual void clean();
};


#endif //GAMEOBJECT_HPP
