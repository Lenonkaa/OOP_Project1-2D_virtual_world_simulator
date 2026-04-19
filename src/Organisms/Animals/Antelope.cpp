//
// Created by lenai on 4/19/2026.
//

#include "Antelope.h"



#define ANTELOPE_STRENGTH 9
#define ANTELOPE_INITIATIVE 5
#define ANTELOPE_RANGE 2



Antelope::Antelope(World* world, Point position)
    : Animal(world, position, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE) {}

char Antelope::draw() {
    return 'A';
}

Animal* Antelope::createChild(Point pos) {
    return new Antelope(this->world, pos);
}

bool Antelope::hasDeflectedAttack(Organism* attacker) {
    bool canEscape = (rand() % 2 == 0);
    if (canEscape) {
        Point currentPos = getPosition();
        Point newPos = world->getRandomFreeNeighbor(currentPos);
        this->moveYourself(currentPos,newPos);
        return true;
    }
    else {
        return false;
    }
}

void Antelope::action() {
    Point currentPos = getPosition();

    Point nextPos = world->getRandomNeighbor(currentPos, ANTELOPE_RANGE);

    moveYourself(currentPos, nextPos);
}

