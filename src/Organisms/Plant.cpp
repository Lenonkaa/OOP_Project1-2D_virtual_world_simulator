//
// Created by lenai on 4/18/2026.
//

#include "Plant.h"
#define PLANT_INITIATIVE 0
#define PROBABILITY_SPREADING 0.8

void Plant::action()
{
    //world->addMessage("plant action");
    spread();
}

void Plant::spread() {

    if((float)rand()/(float) RAND_MAX <= PROBABILITY_SPREADING) {

        string msg = "Plant (at " + to_string(getPosition().x) + "," + to_string(getPosition().y) + ") spreaded.";
        world->addMessage(msg);

        Point position = this->getPosition();

        auto newPos = world->getRandomFreeNeighbor(position);

        if (newPos == position) return;

        spawnNew(newPos);
    }



}



Plant::Plant(World* world, Point position, int strength)
    : Organism(world, position, strength, PLANT_INITIATIVE)
{

}


void Plant::collision(Organism* other) {
    //just get eaten
    return;
}
