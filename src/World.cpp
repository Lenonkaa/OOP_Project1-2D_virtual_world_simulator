//
// Created by lenai on 4/10/2026.
//

#include "World.h"


World::World(int w, int h) : width(w), height(h), turnNumber(0) {

    // tablica wskaznikow na wiersze
    organismsOnGrid = new Organism**[height];

    for (int i = 0; i < height; ++i) {
        // alokacja każdego wiersza
        organismsOnGrid[i] = new Organism*[width];
        // wypełnienie null
        for (int j = 0; j < width; ++j) {
            organismsOnGrid[i][j] = nullptr;
        }
    }
}

World::~World() {
    for (auto o : organisms) delete o;

    // usuwamy rzędy tablicy 2D
    for (int i = 0; i < height; ++i) {
        delete[] organismsOnGrid[i];
    }
    // usuwamy tablicę wskaźników na rzędy
    delete[] organismsOnGrid;
}


void World::addOrganism(Organism* organism) {
    organisms.push_back(organism);
    cout <<"adding organism "<<organism->draw()<<endl ;
    // przypisanie do tablicy 2D - gridu:
    organismsOnGrid[organism->getPosition().y][organism->getPosition().x] = organism;
}