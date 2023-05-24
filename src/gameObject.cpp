#include <iostream>

#include "gameObject.hpp"
#include "TextureManager.hpp"

void GameObject::load(int x, int y, int width, int height, std::string textureID) {
    position = {x, y};
    m_width = width;
    m_height = height;
    m_textureID = textureID;
}

void GameObject::draw(SDL_Renderer* pRenderer) {
    int m_x = (int)position.x;
    int m_y = (int)position.y;
//    TextureManager::Instance()->draw(m_textureID,
//                                     m_x, m_y, m_width, m_height,
//                                     pRenderer,
//                                     33*15, 33);
    TextureManager::Instance()->drawFrame(m_textureID,
                                          m_x, m_y, m_width, m_height,
                                          0, 15,
                                          pRenderer,
                                          33, 33);
}

// TODO: Implement energy loss on collision
void GameObject::update(float time) {
    assert(time > 0.0);

    time /= 500;

    Vector2 acceleration = this->forceAccum * this->inverseMass;
    position.addScaledVector(velocity, time);
    position.addScaledVector(acceleration, 0.5f * time * time);

    // v = v0*damping + a*t
    // damping = damping^t (so that reduction of velocity is proportional to time)
    velocity *= powf(damping, time);
    velocity.addScaledVector(acceleration, time);

    std::cout<<"X: " << position.x << " Y: " << position.y <<std::endl;

    if (position.x < 0 || (int)position.x > (640 - m_width)) {
        if (!out_of_bounds_x) {
            out_of_bounds_x = true;
            velocity.x = -velocity.x;
        }
    }
    else {
        out_of_bounds_x = false;
    }

    if (position.y < 0 || (int)position.y > (480 - m_height)) {
        if (!out_of_bounds_y) {
            out_of_bounds_y = true;
            velocity.y = -velocity.y;
        }
    }
    else {
        out_of_bounds_y = false;
    }
}

void GameObject::clean() {

}