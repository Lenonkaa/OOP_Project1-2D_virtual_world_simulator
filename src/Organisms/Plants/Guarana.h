//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_GUARANA_H
#define OOP1_GUARANA_H


#include "../Plant.h"

class Guarana: public Plant {
public:
    Guarana(World* world, Point position);
    char draw() override;
    bool hasDeflectedAttack(Organism* attacker) override;
protected:
    void spawnNew(Point pos) override;
};
#endif //OOP1_GUARANA_H