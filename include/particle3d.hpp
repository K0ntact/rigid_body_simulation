#ifndef PARTICLE3D_HPP
#define PARTICLE3D_HPP

#include "vector3.hpp"
#include "assert.h"

class Particle3D {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float damping;  // Percentage of velocity remains after each second. 0 is full drag, 1 is no drag.
    float forceAccum;   // Accumulated force to be applied next iteration
private:
    float inverseMass;    // Default immovable = 0 (infinite mass)

public:
    Particle3D();
    Particle3D(Vector3 pos, Vector3 vel, Vector3 acc, float damp, float mass);
    void setInverseMass(float invMass);
    void setMass(float mass);
    void setPosition(Vector3 pos);
    void setVelocity(Vector3 vel);
    void setAcceleration(Vector3 acc);
    void setDamping(float damp);
    void update(float time);
};

#endif //PARTICLE3D_HPP