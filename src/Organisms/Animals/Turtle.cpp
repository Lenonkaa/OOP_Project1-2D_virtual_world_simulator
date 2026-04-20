//
// Created by lenai on 4/19/2026.
//

#include "Turtle.h"



#define TURTLE_STRENGTH 2
#define TURTLE_INITIATIVE 1
#define PROBABILITY_MOVE 0.25
#define TURTLE_STRENTH_DEFLECTION_LIMIT 5



Turtle::Turtle(World* world, Point position)
    : Animal(world, position, TURTLE_STRENGTH, TURTLE_INITIATIVE) {}

char Turtle::draw() {
    return 'T';
}

Animal* Turtle::createChild(Point pos) {
    return new Turtle(this->getWorld(), pos);
}


// ====================== TURTLE SPECIAL =========================

void Turtle::action() {

    if ( (float)rand()/(float) RAND_MAX <= PROBABILITY_MOVE ) {

        Point currentPos = getPosition();
        Point nextPos = getWorld()->getRandomNeighbor(currentPos);

        moveYourself(currentPos, nextPos);
    }
}


bool Turtle::hasDeflectedAttack(Organism* attacker) {

    bool isDeflecting = (attacker->getStrength() < TURTLE_STRENTH_DEFLECTION_LIMIT);

    if (isDeflecting) {
        getWorld()->addMessage("Turtle deflects attack of " + string(1, attacker->draw()));
    }

   return isDeflecting;
}


