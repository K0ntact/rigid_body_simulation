#include "particle2d.hpp"

Particle2D::Particle2D() {
    this->position = {0, 0};
    this->velocity = {0, 0};
    this->damping = {0.99}; // Object will clip through wall if damping = 0. Need fix
    this->forceAccum = {0, 0};
    this->inverseMass = {0};
}

Particle2D::Particle2D(Vector2 pos, Vector2 vel, float damp, float invMass) {
    this->position = pos;
    this->velocity = vel;
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

void Particle2D::setDamping(float damp) {
    this->damping = damp;
}

void Particle2D::update(float time) {
    assert(time > 0.0);
    // Mass-based physics: replace acceleration with F/m = F * inv_mass (2nd Newton law)
    // When inverse mass = 0, acceleration = 0 (immovable object)
    Vector2 acceleration = this->forceAccum * this->inverseMass;

    // Update position
    // x' = x + v*t + 1/2*a*t^2
    // x += (v*t + 1/2*a*t^2)
    this->position.addScaledVector(this->velocity, time);
    this->position.addScaledVector(acceleration, 0.5f * time * time); // Very small difference in position, consider removing

    // Update velocity
    // v = v0*damping + a*t
    // damping = damping^t (so that reduction of velocity is proportional to time)
    this->velocity *= powf(damping, time);
    this->velocity.addScaledVector(acceleration, time);
}

void Particle2D::addForce(const Vector2 force) {
    this->forceAccum += force;
}

void Particle2D::clearAccum() {
    forceAccum = {0, 0};
}


