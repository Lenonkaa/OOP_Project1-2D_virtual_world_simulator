//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_BELLADONNA_H
#define OOP1_BELLADONNA_H


#include "../Plant.h"

class Belladonna: public Plant {
public:
    Belladonna(World* world, Point position);
    char draw() override;
    bool hasDeflectedAttack(Organism* attacker) override;
protected:
    void spawnNew(Point pos) override;
};


#endif //OOP1_BELLADONNA_H