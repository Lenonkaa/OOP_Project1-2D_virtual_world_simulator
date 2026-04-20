//
// Created by lenai on 4/18/2026.
//

#include "Plant.h"
#define PLANT_INITIATIVE 0
#define PROBABILITY_SPREADING 0.15





Plant::Plant(World* world, Point position, int strength)
    : Organism(world, position, strength, PLANT_INITIATIVE)
{

}


void Plant::action()
{
    spread();
}

void Plant::spread() {

    if((float)rand()/(float) RAND_MAX <= PROBABILITY_SPREADING) {

        string msg = "Plant (at " + to_string(getPosition().x) + "," + to_string(getPosition().y) + ") spreaded.";
        getWorld()->addMessage(msg);

        Point position = this->getPosition();

        auto newPos = getWorld()->getRandomFreeNeighbor(position);

        if (newPos == position) return;

        spawnNew(newPos);
    }

}


//na razie niepotrzebna - plants have 0 initiative, ale dla porzadku
void Plant::collision(Organism* other) {
    //just get eaten

    string msg = string(1, draw()) + " (" + to_string(getPosition().x) + "," + to_string(getPosition().y)
                        + ") was eaten by" +string(1, other->draw());
    getWorld()->addMessage(msg);
    return;
}
