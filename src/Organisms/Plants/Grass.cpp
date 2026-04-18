//
// Created by lenai on 4/18/2026.
//

#include "Grass.h"


#define GRASS_STRENGTH 0


Grass::Grass(World* world, Point position)
    : Plant(world, position, GRASS_STRENGTH) {}

char Grass::draw() {
    return 'G';
}