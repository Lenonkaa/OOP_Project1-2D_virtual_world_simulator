//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_ANTELOPE_H
#define OOP1_ANTELOPE_H


#include "../Animal.h"

class Antelope : public Animal {
public:

    Antelope(World* world, Point position);

    ~Antelope() override = default;

    char draw() override;
    void action() override;
    bool hasDeflectedAttack(Organism* attacker) override;

protected:
    Animal* createChild(Point pos) override;

};


#endif //OOP1_ANTELOPE_H