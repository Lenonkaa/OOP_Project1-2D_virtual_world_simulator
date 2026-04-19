//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_SOSNOWSKYBARSZCZ_H
#define OOP1_SOSNOWSKYBARSZCZ_H

#include "../Plant.h"

class SosnowskyHogweed: public Plant {
public:
    SosnowskyHogweed(World* world, Point position);
    char draw() override;
    bool hasDeflectedAttack(Organism* attacker) override;
    void action() override;
protected:
    void spawnNew(Point pos) override;
private:
    bool isThatCyberSheep(Organism* attacker);
    void killAnimalNeighbors();
};


#endif //OOP1_SOSNOWSKYBARSZCZ_H