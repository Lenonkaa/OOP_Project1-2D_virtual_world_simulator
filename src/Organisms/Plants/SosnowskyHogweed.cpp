//
// Created by lenai on 4/19/2026.
//

#include "SosnowskyHogweed.h"


#define SOSNOWSKY_STRENGTH 10

SosnowskyHogweed::SosnowskyHogweed(World* world, Point position)
    : Plant(world, position, SOSNOWSKY_STRENGTH) {}

char SosnowskyHogweed::draw() {
    return HOGWEED_SYMBOL;
}


void SosnowskyHogweed::spawnNew(Point pos) {
    world->addOrganism(new SosnowskyHogweed(world, pos));
}


bool SosnowskyHogweed::hasDeflectedAttack(Organism* attacker) {
    if (!isThatCyberSheep(attacker)) {
        attacker->kill();
        return true;
    }
    else {
        return false;
    }

}


bool SosnowskyHogweed::isThatCyberSheep(Organism* attacker) {
    char type = attacker->draw();
    return type == CYBER_SHEEP_SYMBOL;
}

void SosnowskyHogweed::action() {
    spread();
}

void SosnowskyHogweed::killAnimalNeighbors() {
    int range=1;
    Point position = getPosition();

    for (int dy = -range; dy <= range; dy++) {
        for (int dx = -range; dx <= range; dx++) {

            Point checkedPoint = {position.x + dx, position.y + dy};
            Organism* occupant = world->getOrganismAtPosition(checkedPoint);

            if (!(checkedPoint == position)
                && !checkedPoint.isOutGrid(world->getHeight(), world->getWidth() )
                && occupant->isAnimal()
                && occupant->draw() != CYBER_SHEEP_SYMBOL) {

                    world->addMessage("Sosnowsky's hogweed kills " + string(1, occupant->draw()) + "!");
                    occupant->kill();
                }

            }
        }

}