//
// Created by lenai on 4/10/2026.
//

#ifndef OOP1_WORLD_H
#define OOP1_WORLD_H
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

#include "Organism.h"
#include "Point.h"


#define FILE_SAVE_NAME "stateSave.txt"

class Human;
class Organism;

class World {
private:
    int width, height;
    int turnNumber;
    bool isGameActive;
    bool startNewGame;
    bool isHumanALive;
    vector<Organism*> organisms;
    Organism*** organismsOnGrid;
    Human* human;

    vector<string> turnMessages;


    void sortOrganisms();
    void handleInput();
    void makeTurn();
    void drawWorld() const;


    void addHuman();
    Point getRandomFreeCell();


    void saveWorld(const string& filename);
    void clearWorld();

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


    void playGame();
    void populateWorld(double fillPercentage);

    void addMessage(string msg) { turnMessages.push_back(msg);}

    //getters setters

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool getIsGameActive(){return isGameActive;}
    bool getStartNewGame(){return startNewGame;}

    void setIfHumanAlive(bool state) { isHumanALive = state; }

    //managing organisms and positions


    void addOrganism(Organism* organism);
    void removeOrganism(Organism* organism);


    bool isValidPosition(Point p) const;
    Organism* getOrganismAtPosition(Point p) const;
    void setOrganismAt(Point p, Organism* o);

    Point getRandomFreeNeighbor(Point p, int range = 1);
    Point getRandomNeighbor(Point p, int range = 1);

    //state to/from files

    static World* loadWorld(const string& filename);
    void setTurnNumber(int n) { turnNumber = n; }


};




#endif //OOP1_WORLD_H