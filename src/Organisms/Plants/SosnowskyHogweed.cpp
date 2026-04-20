//
// Created by lenai on 4/19/2026.
//

#include "SosnowskyHogweed.h"
#include "../Animals/CyberSheep.h"


#define SOSNOWSKY_STRENGTH 10

SosnowskyHogweed::SosnowskyHogweed(World* world, Point position)
    : Plant(world, position, SOSNOWSKY_STRENGTH) {}



char SosnowskyHogweed::draw() {
    return HOGWEED_SYMBOL;
}


void SosnowskyHogweed::action() {
    spread();
    killAnimalNeighbors();
}


void SosnowskyHogweed::spawnNew(Point pos) {
    getWorld()->addOrganism(new SosnowskyHogweed(getWorld(), pos));
}


bool SosnowskyHogweed::hasDeflectedAttack(Organism* attacker) {

    if ((attacker->getType() == OrganismType::ANIMAL || attacker->getType() == OrganismType::HUMAN)
        && !isThatCyberSheep(attacker)) {
        getWorld()->addMessage( string(1, attacker->draw())
            +" (" + to_string(getPosition().x) + "," + to_string(getPosition().y)
            + ") ate Sosnowsky's Hogweed and died");

        attacker->kill();
        return true;
    }
    else {

        return false;
    }

}




// ================= PRIVATE ==============


bool SosnowskyHogweed::isThatCyberSheep(Organism* attacker) {

    if (attacker == nullptr) return false;

    return typeid(*attacker) == typeid(CyberSheep);
}


void SosnowskyHogweed::killAnimalNeighbors() {

    int range=1;
    Point position = getPosition();

    for (int dy = -range; dy <= range; dy++) {
        for (int dx = -range; dx <= range; dx++) {

            Point checkedPoint = {position.x + dx, position.y + dy};
            Organism* occupant = getWorld()->getOrganismAtPosition(checkedPoint);

            if (ifKillAtThisCell(checkedPoint, occupant)) {

                    getWorld()->addMessage("Sosnowsky's hogweed kills "
                        + string(1, occupant->draw()) + "!");
                    occupant->kill();
                }

            }
        }

}

bool SosnowskyHogweed::ifKillAtThisCell(Point checkedPoint, Organism* occupant) const {
    Point position = getPosition();


    bool test =(!(checkedPoint == position)
                && getWorld()->isValidPosition(checkedPoint)
                && occupant != nullptr
                && (occupant->getType() == OrganismType::ANIMAL || occupant->getType() == OrganismType::HUMAN)
                && typeid(*occupant) != typeid(CyberSheep));
    return test;
}