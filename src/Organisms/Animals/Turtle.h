//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_TURTLE_H
#define OOP1_TURTLE_H

#include "../Animal.h"

class Turtle : public Animal {
public:

    Turtle(World* world, Point position);

    ~Turtle() override = default;

    char draw() override;

    Animal* createChild(Point pos) override;
    bool hasDeflectedAttack(Organism* attacker) override;
    void action() override;
};

#endif //OOP1_TURTLE_H