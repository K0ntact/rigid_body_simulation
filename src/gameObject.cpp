#include <iostream>

#include "gameObject.hpp"
#include "TextureManager.hpp"

void GameObject::load(int x, int y, int width, int height, std::string textureID) {
    position = {x + width/2, y + height/2};  // center of the object
    m_width = width;
    m_height = height;
    m_textureID = textureID;
}

void GameObject::draw(SDL_Renderer* pRenderer) {
    // Draw position is the top left corner of the object
    int m_x = (int)position.x - m_width/2;
    int m_y = (int)position.y - m_height/2;

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

    Vector2 acceleration = this->forceAccum * this->inverseMass;    // a = F * 1/m

    // Get the position at the start of the frame for collision detection
    float x0 = position.x;
    float y0 = position.y;

    // v = v0*damping + a*t
    // damping = damping^t (so that reduction of velocity is proportional to time)
    velocity *= powf(damping, time);
    velocity.addScaledVector(acceleration, time);

    position.addScaledVector(velocity, time);
    position.addScaledVector(acceleration, 0.5f * time * time);

    std::cout<<"X: " << position.x << " Y: " << position.y <<std::endl;

    // Stop the object if it is slow enough and is near the bottom
    if (velocity.magnitude() < 10 && position.y > 480 - m_height/2 - 1) {
        position.y = 480 - m_height/2;
        velocity = {0, 0};
        forceAccum = {0, 0};
        return;
    }

    // Collision detection
    if (position.y > 480 - m_height/2) {
        // Calculate collision point using linear interpolation
        // (xC - x0)/(yC - y0) = (x1 - x0)/(y1 - y0)
        // xC = [(x1 - x0)(yC - y0) + x0(y1 - y0)] / (y1 - y0)
        float x1 = position.x;
        float y1 = position.y;
        float yC = 480 - m_height/2;
        float xC = ((x1 - x0)*(yC - y0) + x0*(y1 - y0)) / (y1 - y0);

        Vector2 collisionPoint = {xC, yC};

        // Calculate time until collision
        float distance = (collisionPoint - position).magnitude();
        float timeToCollision = distance / velocity.magnitude();

        // Set bounce back velocity and position at the end of frame
        velocity.y = -velocity.y;
        float timeAfterCollision = time - timeToCollision;
        collisionPoint.addScaledVector(velocity, timeAfterCollision);
        position = collisionPoint;
    }
    else if (position.y < m_height/2) {
        float x1 = position.x;
        float y1 = position.y;
        float yC = m_height/2;
        float xC = ((x1 - x0)*(yC - y0) + x0*(y1 - y0)) / (y1 - y0);

        Vector2 collisionPoint = {xC, yC};

        float distance = (collisionPoint - position).magnitude();
        float timeToCollision = distance / velocity.magnitude();

        velocity.y = -velocity.y;
        float timeAfterCollision = time - timeToCollision;
        collisionPoint.addScaledVector(velocity, timeAfterCollision);
        position = collisionPoint;
    }

    if (position.x < m_width/2) {
        float x1 = position.x;
        float y1 = position.y;
        float xC = m_width/2;
        float yC = ((y1 - y0)*(xC - x0) + y0*(x1 - x0)) / (x1 - x0);

        Vector2 collisionPoint = {xC, yC};

        float distance = (collisionPoint - position).magnitude();
        float timeToCollision = distance / velocity.magnitude();

        velocity.x = -velocity.x;
        float timeAfterCollision = time - timeToCollision;
        collisionPoint.addScaledVector(velocity, timeAfterCollision);
        position = collisionPoint;
    }
    else if (position.x > 640 - m_width/2) {
        float x1 = position.x;
        float y1 = position.y;
        float xC = 640 - m_width/2;
        float yC = ((y1 - y0)*(xC - x0) + y0*(x1 - x0)) / (x1 - x0);

        Vector2 collisionPoint = {xC, yC};

        float distance = (collisionPoint - position).magnitude();
        float timeToCollision = distance / velocity.magnitude();

        velocity.x = -velocity.x;
        float timeAfterCollision = time - timeToCollision;
        collisionPoint.addScaledVector(velocity, timeAfterCollision);
        position = collisionPoint;
    }

}

void GameObject::clean() {

}