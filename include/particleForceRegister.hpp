#ifndef PARTICLEFORCEREGISTER_HPP
#define PARTICLEFORCEREGISTER_HPP

#include <vector>

#include "particle2d.hpp"
#include "particleForceGenerator.hpp"

class ParticleForceRegister {
protected:
    struct Registration {
        Particle2D* particle;
        ParticleForceGenerator* forceGenerator;
    };

    // Keep track of all forces that is applying to particles
    std::vector<Registration> registrations;

public:
    void add(Particle2D* particle, ParticleForceGenerator* force);
    void remove(Particle2D* particle, ParticleForceGenerator* force);
    void clear();
};


#endif //PARTICLEFORCEREGISTER_HPP
