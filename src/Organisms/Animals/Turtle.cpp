//
// Created by lenai on 4/19/2026.
//

#include "Turtle.h"



#define TURTLE_STRENGTH 2
#define TURTLE_INITIATIVE 1
#define PROBABILITY_MOVE 0.25
#define TURTLE_DEFLECTION 5



Turtle::Turtle(World* world, Point position)
    : Animal(world, position, TURTLE_STRENGTH, TURTLE_INITIATIVE) {}

char Turtle::draw() {
    return 'T';
}

Animal* Turtle::createChild(Point pos) {
    return new Turtle(this->world, pos);
}

bool Turtle::hasDeflectedAttack(Organism* attacker) {
    bool isReflecting = (attacker->getStrength() < TURTLE_DEFLECTION);

   return isReflecting;
}

void Turtle::action() {

    if ((float)rand()/(float) RAND_MAX <= PROBABILITY_MOVE) {
        Point currentPos = getPosition();
        Point nextPos = world->getRandomNeighbor(currentPos);

        moveYourself(currentPos, nextPos);
    }
}

