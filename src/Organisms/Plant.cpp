//
// Created by lenai on 4/18/2026.
//

#include "Plant.h"
#define PLANT_INITIATIVE 0

void Plant::action()
{
    world->addMessage("plant action");
    if (rand() % 100 < 90) spread();
}

void Plant::spread() {
    string msg = "Plant (at " + to_string(getPosition().x) + "," + to_string(getPosition().y) + ") spreaded.";
    world->addMessage(msg);
}

Plant::Plant(World* world, Point position, int strength)
    : Organism(world, position, strength, PLANT_INITIATIVE)
{

}


void Plant::collision() {
    world->addMessage("plant collision");
}
