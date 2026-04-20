//
// Created by lenai on 4/18/2026.
//

#ifndef OOP1_PLANT_H
#define OOP1_PLANT_H
#include "../Organism.h"


class Plant: public Organism {
public:
    virtual void action() override;
    virtual void collision(Organism* other) override;
    virtual ~Plant() = default;
    Plant(World* world, Point position, int strength);
    virtual void spawnNew(Point pos) = 0;
    OrganismType getType() const override { return OrganismType::PLANT; }

protected:
    void spread();





};


#endif //OOP1_PLANT_H