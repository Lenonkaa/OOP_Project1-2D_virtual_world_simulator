//
// Created by lenai on 4/18/2026.
//

#ifndef OOP1_GRASS_H
#define OOP1_GRASS_H

#include "../Plant.h"

class Grass: public Plant {
public:
    Grass(World* world, Point position);
    char draw() override;
protected:
    void spawnNew(Point pos) override;
};


#endif //OOP1_GRASS_H