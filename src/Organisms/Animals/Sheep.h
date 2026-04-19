//
// Created by lenai on 4/18/2026.
//

#ifndef OOP1_SHEEP_H
#define OOP1_SHEEP_H


#include "../Animal.h"

class Sheep : public Animal {
public:

    Sheep(World* world, Point position);

    ~Sheep() override = default;

    char draw() override;

    Animal* createChild(Point pos) override;
};




#endif //OOP1_SHEEP_H