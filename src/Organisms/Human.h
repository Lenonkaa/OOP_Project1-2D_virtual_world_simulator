//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_HUMAN_H
#define OOP1_HUMAN_H
#include "Animal.h"

class Animal;

class Human: public Animal {
private:
    bool isAbilityActive;
    World::MOVE currentMove;

    Animal* createChild(Point pos);

    void moveNotRandom();
public:
    Human(World* world, Point position);
    ~Human() override = default;

    void action() override;
    char draw() override;
    void activateAbility();
    World::MOVE getMove();
    void setMove(World::MOVE move);

};


#endif //OOP1_HUMAN_H