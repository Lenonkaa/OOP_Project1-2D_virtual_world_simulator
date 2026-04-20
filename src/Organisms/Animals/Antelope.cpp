//
// Created by lenai on 4/19/2026.
//

#include "Antelope.h"



#define ANTELOPE_STRENGTH 4
#define ANTELOPE_INITIATIVE 4
#define ANTELOPE_RANGE 2



Antelope::Antelope(World* world, Point position)
    : Animal(world, position, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE) {}

char Antelope::draw() {
    return 'A';
}

Animal* Antelope::createChild(Point pos) {
    return new Antelope(this->getWorld(), pos);
}

// =================== ANTELOPE SPECIAL ================


void Antelope::action() {
    Point currentPos = getPosition();

    Point nextPos = getWorld()->getRandomNeighbor(currentPos, ANTELOPE_RANGE);

    moveYourself(currentPos, nextPos);
}


bool Antelope::hasDeflectedAttack(Organism* attacker) {

    bool canEscape = (rand() % 2 == 0);

    if (canEscape) {
        Point currentPos = getPosition();
        Point newPos = getWorld()->getRandomFreeNeighbor(currentPos);
        this->moveYourself(currentPos,newPos);
        return true;
    }
    return false;
}