//
// Created by lenai on 4/14/2026.
//

#include "Wolf.h"

#define WOLF_STRENGTH 9
#define WOLF_INITIATIVE 5



Wolf::Wolf(World* world, Point position)
    : Animal(world, position, WOLF_STRENGTH, WOLF_INITIATIVE) {}

char Wolf::draw() {
    return 'W';
}

Animal* Wolf::createChild(Point pos) {
    return new Wolf(this->world, pos);
}
