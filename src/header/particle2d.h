#include "vector2.h"

class Particle2D {
private:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float damping;  // Percentage of velocity remains after each second. 0 is full drag, 1 is no drag.
    float forceAccum = { 0 };
    float inverseMass = { 0 }; // Allows for infinite mass (immovable objects)

public:
    void setInverseMass(float invMass) {
        this->inverseMass = invMass;
    }
    void setMass(float mass) {
        this->inverseMass = 1 / mass;
    }
    void setVelocity(float x, float y) {
        this->velocity = { x,y };
    }
    void setAcceleration(float x, float y) {
        this->acceleration = { x, y };
    }
    void setDamping(float damp) {
        this->damping = damp;
    }

    void update(float time) {
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
};

