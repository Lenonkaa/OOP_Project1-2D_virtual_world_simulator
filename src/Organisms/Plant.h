//
// Created by lenai on 4/18/2026.
//

#ifndef OOP1_PLANT_H
#define OOP1_PLANT_H
#include "../Organism.h"


class Plant: public Organism {
public:
    virtual void action() override;
    void collision() override;
    virtual ~Plant() = default;
    Plant(World* world, Point position, int strength);
    virtual void spawnNew(Point pos) = 0;


    //organism type?
private:
    void spread();




};


#endif //OOP1_PLANT_H