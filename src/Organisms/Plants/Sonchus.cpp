//
// Created by lenai on 4/19/2026.
//

#include "Sonchus.h"



#define SONCHUS_STRENGTH 0
#define N_SPREAD_TRIALS 3

Sonchus::Sonchus(World* world, Point position)
    : Plant(world, position, SONCHUS_STRENGTH) {}

char Sonchus::draw() {
    return 's';
}


void Sonchus::spawnNew(Point pos) {
    world->addOrganism(new Sonchus(world, pos));
}

void Sonchus::action()
{
    //world->addMessage("plant action");
    for (int i = 0; i < N_SPREAD_TRIALS; i++) {
        spread();
    }

}