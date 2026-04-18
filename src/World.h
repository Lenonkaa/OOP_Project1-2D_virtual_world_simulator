//
// Created by lenai on 4/10/2026.
//

#ifndef OOP1_WORLD_H
#define OOP1_WORLD_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;

#include "Organism.h"
#include "Point.h"

class Organism;

class World {
private:
    int width, height;
    int turnNumber;
    bool isGameActive;
    bool isHumanALive;
    vector<Organism*> organisms;
    Organism*** organismsOnGrid;
    //Human* human;

    vector<string> turnMessages;

    //void organismsTurn;

    void sortOrganisms();




public:
    void addMessage(string msg) { turnMessages.push_back(msg); }

    void playGame();

    bool getIsGameActive(){return isGameActive;}

    enum MOVE {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SPECIAL,
        STAY

    };

    World(int w, int h);

    ~World();

    void makeTurn();

    void addOrganism(Organism* organism);
    void removeOrganism(Organism* organism);
    void drawWorld() const;

        /*


    Organism* getOrganismAtPosition(Point p) const
    */

};




#endif //OOP1_WORLD_H