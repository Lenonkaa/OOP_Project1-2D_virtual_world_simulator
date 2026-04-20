//
// Created by lenai on 4/19/2026.
//

#include "Guarana.h"


#define GUARANA_STRENGTH 0
#define GUARANA_BOOST 3

Guarana::Guarana(World* world, Point position)
    : Plant(world, position, GUARANA_STRENGTH) {}

char Guarana::draw() {
    return 'g';
}


void Guarana::spawnNew(Point pos) {
    getWorld()->addOrganism(new Guarana(getWorld(), pos));
}


bool Guarana::hasDeflectedAttack(Organism* attacker) {

    if ((attacker->getType() == OrganismType::ANIMAL || attacker->getType() == OrganismType::HUMAN)) {
        attacker->strengthBoost(GUARANA_BOOST);
    }

    return false;
}
