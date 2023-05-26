#ifndef PARTICLEFORCEGENERATOR_HPP
#define PARTICLEFORCEGENERATOR_HPP

#include "particle2d.hpp"
#include "vector2.hpp"

class ParticleForceGenerator {
public:
    virtual void updateForce(Particle2D* particle, float duration) = 0;
};

#endif //PARTICLEFORCEGENERATOR_HPP
