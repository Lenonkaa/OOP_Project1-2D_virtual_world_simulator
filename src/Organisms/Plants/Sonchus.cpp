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
    getWorld()->addOrganism(new Sonchus(getWorld(), pos));
}

void Sonchus::action()
{
    //string msg = "Sow thistle (at " + to_string(getPosition().x) + "," + to_string(getPosition().y) + ") tries " + to_string(N_SPREAD_TRIALS) + " times to spread";
    //getWorld()->addMessage(msg);

    for (int i = 0; i < N_SPREAD_TRIALS; i++) {

        spread();
    }

}