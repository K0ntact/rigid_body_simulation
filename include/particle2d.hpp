#ifndef PARTICLE2D_HPP
#define PARTICLE2D_HPP

#include "vector2.hpp"

class Particle2D {
protected:
    // Internal forces of the particle.
    // External forces (gravity) are applied by the force generators.
    Vector2 position;
    Vector2 velocity;
    float damping;  // Percentage of velocity remains after each second. 0 is full drag, 1 is no drag.
    Vector2 forceAccum; // Accumulated force to be applied to the particle
    float inverseMass; // Allows for infinite mass when = 0 (immovable objects)

public:
    Particle2D();
    Particle2D(Vector2 pos, Vector2 vel, float damp, float invMass);
    void setInverseMass(float invMass);
    void setMass(float mass);
    void setVelocity(float x, float y);
    void setDamping(float damp);
    virtual void update(float time);
    void addForce(Vector2 force);
    void clearAccum();

    float getInverseMass() const;
    float getMass() const;
    Vector2 getPosition() const;
    Vector2 getVelocity() const;
};

#endif //PARTICLE2D_HPP