#include "particleForceRegister.hpp"


void ParticleForceRegister::add(Particle2D* particle, ParticleForceGenerator* force) {
    Registration reg{};
    reg.particle = particle;
    reg.forceGenerator = force;
    registrations.push_back(reg);
}

void ParticleForceRegister::remove(Particle2D* particle, ParticleForceGenerator* force) {
    for (auto it = registrations.begin(); it != registrations.end(); ++it) {
        if (it->particle == particle && it->forceGenerator == force) {
            registrations.erase(it);
            break;
        }
    }
}

void ParticleForceRegister::clear() {
    registrations.clear();
}