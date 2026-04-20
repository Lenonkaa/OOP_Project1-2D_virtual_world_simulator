//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_SONCHUS_H
#define OOP1_SONCHUS_H

#include "../Plant.h"

class Sonchus: public Plant {
public:
    Sonchus(World* world, Point position);
    char draw() override;
    void action() override;
protected:
    void spawnNew(Point pos) override;
};

#endif //OOP1_SONCHUS_H