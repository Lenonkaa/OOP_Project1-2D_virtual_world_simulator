//
// Created by lenai on 4/14/2026.
//

#ifndef OOP1_WOLF_H
#define OOP1_WOLF_H


#include "../Animal.h"

class Wolf : public Animal {
public:

    Wolf(World* world, Point position);

    ~Wolf() override = default;

    char draw() override;

    Animal* createChild(Point pos) override;
};


#endif //OOP1_WOLF_H