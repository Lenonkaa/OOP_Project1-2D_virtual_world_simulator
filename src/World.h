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

class World {
private:
    int width, height;
    vector<Organism*> organisms;

    //void organismsTurn;

    int turnNumber;
    Organism*** organismsOnGrid;

    bool isGameActive;


public:

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


    void addOrganism(Organism* organism);


    void drawWorld() const {
        system("cls");
        cout << "Lena Idczak 208341" << endl;
        cout << "Numer tury " << turnNumber << endl;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (organismsOnGrid[y][x] == nullptr) {
                    // Puste pole wypełniamy kropką
                    cout << ". ";
                } else {
                    // Jeśli jest organizm, prosimy go, by się narysował
                    // Metoda draw() dla Wilka zwraca 'W'
                    cout << organismsOnGrid[y][x]->draw() << " ";
                }
            }
            cout << endl; // Nowa linia po każdym rzędzie
        }
    }

        /*
            void makeTurn();


    void removeOrganism(Organism* organism);

    Organism* getOrganismAtPositiom(Point p) const {
        Organism* szukany = nullptr;


        for(auto* organism : organisms) {
        }

        return szukany;
    }
    */

};




#endif //OOP1_WORLD_H