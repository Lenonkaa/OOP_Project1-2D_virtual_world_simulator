//
// Created by lenai on 4/14/2026.
//

#include "Wolf.h"


Wolf::Wolf(World* world, Point position)
    : Animal(world, position, 9, 5) {}

char Wolf::draw() {
    return 'W';
}