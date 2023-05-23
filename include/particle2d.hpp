#ifndef PARTICLE2D_HPP
#define PARTICLE2D_HPP

#include "vector2.hpp"

class Particle2D {
protected:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float damping;  // Percentage of velocity remains after each second. 0 is full drag, 1 is no drag.
    Vector2 forceAccum; // Accumulated force to be applied to the particle
    float inverseMass; // Allows for infinite mass when = 0 (immovable objects)

public:
    Particle2D();
    Particle2D(Vector2 pos, Vector2 vel, Vector2 acc, float damp, float invMass);
    void setInverseMass(float invMass);
    void setMass(float mass);
    void setVelocity(float x, float y);
    void setAcceleration(float x, float y);
    void setDamping(float damp);
    virtual void update(float time);
    void clearAccum();
};

#endif //PARTICLE2D_HPP