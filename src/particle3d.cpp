#include "particle3d.hpp"

Particle3D::Particle3D() {
    this->position = {0, 0, 0};
    this->velocity = {0, 0, 0};
    this->acceleration = {0, 0, 0};
    this->damping = 0;
    this->forceAccum = 0;
    this->inverseMass = 0;
}

Particle3D::Particle3D(Vector3 pos, Vector3 vel, Vector3 acc, float damp, float mass) {
    this->position = pos;
    this->velocity = vel;
    this->acceleration = acc;
    this->damping = damp;
    this->forceAccum = 0;
    this->inverseMass = 1 / mass;
}

void Particle3D::setInverseMass(float invMass) {this->inverseMass = invMass;}
void Particle3D::setMass(float mass) {this->inverseMass = 1 / mass;}
void Particle3D::setPosition(Vector3 pos) {this->position = pos;}
void Particle3D::setVelocity(Vector3 vel) {this->velocity = vel;}
void Particle3D::setAcceleration(Vector3 acc) {this->acceleration = acc;}
void Particle3D::setDamping(float damp) {this->damping = damp;}


void Particle3D::update(float time) {
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
