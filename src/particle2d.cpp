#include "particle2d.hpp"

Particle2D::Particle2D() {
    this->position = {0, 0};
    this->velocity = {0, 0};
    this->acceleration = {0, 0};
    this->damping = {0};
    this->forceAccum = {0, 0};
    this->inverseMass = {0};
}

Particle2D::Particle2D(Vector2 pos, Vector2 vel, Vector2 acc, float damp, float invMass) {
    this->position = pos;
    this->velocity = vel;
    this->acceleration = acc;
    this->damping = damp;
    this->forceAccum = {0, 0};
    this->inverseMass = invMass;
}

void Particle2D::setInverseMass(float invMass) {
    this->inverseMass = invMass;
}

void Particle2D::setMass(float mass) {
    this->inverseMass = 1 / mass;
}

void Particle2D::setVelocity(float x, float y) {
    this->velocity = { x,y };
}

void Particle2D::setAcceleration(float x, float y) {
    this->acceleration = { x, y };
}

void Particle2D::setDamping(float damp) {
    this->damping = damp;
}

void Particle2D::update(float time) {
    assert(time > 0.0);
    // Update position
    // x' = x + v*t + 1/2*a*t^2
    // x += (v*t + 1/2*a*t^2)
    this->position.addScaledVector(this->velocity, time);
    this->position.addScaledVector(this->acceleration, 0.5f * time * time); // Very small difference in position, consider removing

    // Update velocity
    // v = v0*damping + a*t
    // damping = damping^t (so that reduction of velocity is proportional to time)
    this->velocity *= powf(damping, time);
    this->velocity.addScaledVector(this->acceleration, time);
}

void Particle2D::clearAccum() {
    forceAccum = {0, 0};
}


