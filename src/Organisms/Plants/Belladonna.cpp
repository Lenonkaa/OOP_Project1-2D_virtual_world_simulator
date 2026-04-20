//
// Created by lenai on 4/19/2026.
//

#include "Belladonna.h"


#define BELLADONNA_STRENGTH 99

Belladonna::Belladonna(World* world, Point position)
    : Plant(world, position, BELLADONNA_STRENGTH) {}

char Belladonna::draw() {
    return 'b';
}


void Belladonna::spawnNew(Point pos) {
    world->addOrganism(new Belladonna(world, pos));
}


bool Belladonna::hasDeflectedAttack(Organism* attacker) {
    world->addMessage(string(1, attacker->draw()) + " (" + to_string(attacker->getPosition().x) + "," + to_string(attacker->getPosition().y)
        + ") ate Belladonna and died!");
    attacker->kill();
    return true;
}