//
// Created by lenai on 4/18/2026.
//

#include "Sheep.h"


#define SHEEP_STRENGTH 4
#define SHEEP_INITIATIVE 4



Sheep::Sheep(World* world, Point position)
    : Animal(world, position, SHEEP_STRENGTH, SHEEP_INITIATIVE) {}

char Sheep::draw() {
    return 'S';
}

Animal* Sheep::createChild(Point pos) {
    return new Sheep(this->world, pos);
}
