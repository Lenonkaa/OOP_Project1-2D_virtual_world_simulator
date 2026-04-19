//
// Created by lenai on 4/19/2026.
//

#include "SosnowskyHogweed.h"


#define SOSNOWSKY_STRENGTH 10

SosnowskyHogweed::SosnowskyHogweed(World* world, Point position)
    : Plant(world, position, SOSNOWSKY_STRENGTH) {}

char SosnowskyHogweed::draw() {
    return 's';
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