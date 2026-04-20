//
// Created by lenai on 4/10/2026.
//

#include "World.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <conio.h>

#define IS_ARROW 224

#define A_UP 72
#define A_DOWN 80
#define A_LEFT 75
#define A_RIGHT 77
#define NEXT_TURN 13 //enter

#define NUMBER_OF_SPECIES 11

#define COLOR_RESET  "\033[0m"
#define COLOR_RED    "\033[31m"
#define COLOR_GREEN  "\033[32m"
#define COLOR_BLUE   "\033[34m"

#include "Organisms/Human.h"
#include "Organisms/Animals/Wolf.h"
#include "Organisms/Animals/Sheep.h"
#include "Organisms/Animals/Fox.h"
#include "Organisms/Animals/Turtle.h"
#include "Organisms/Animals/Antelope.h"
#include "Organisms/Animals/CyberSheep.h"
#include "Organisms/Plants/Grass.h"
#include "Organisms/Plants/Sonchus.h"
#include "Organisms/Plants/Guarana.h"
#include "Organisms/Plants/Belladonna.h"
#include "Organisms/Plants/SosnowskyHogweed.h"


//=======================================================================================================
//==================================CONTRUCTING / DESTRUCTING WORLD==============================
//=======================================================================================================


World::World(int w, int h) : width(w), height(h), turnNumber(0), isGameActive(1) {


    organismsOnGrid = new Organism**[height]; // wskazniki na wiersze

    for (int i = 0; i < height; ++i) {
        organismsOnGrid[i] = new Organism*[width]; //each wiersz wypełniony null

        for (int j = 0; j < width; ++j) {
            organismsOnGrid[i][j] = nullptr;
        }
    }
}

World::~World() {
    for (auto o : organisms) delete o;

    // delete rzędy
    for (int i = 0; i < height; ++i) {
        delete[] organismsOnGrid[i];
    }

    delete[] organismsOnGrid; // delete tablice rzedow
}


void World::populateWorld(double fillPercentage) {

    int totalCells = width * height;
    int cellsToFill = totalCells * fillPercentage;

    if (cellsToFill <= 0) return;

    addHuman();
    cellsToFill--;

    for (int i = 0; i < cellsToFill; ++i) {

        Point p = getRandomFreeCell();
        if (p.x == -1) break; // when no free cells

        int species = rand() % NUMBER_OF_SPECIES;

        switch (species) {
            case 0: addOrganism(new Wolf(this, p)); break;
            case 1: addOrganism(new Sheep(this, p)); break;
            case 2: addOrganism(new Fox(this, p)); break;
            case 3: addOrganism(new Turtle(this, p)); break;
            case 4: addOrganism(new Antelope(this, p)); break;
            case 5: addOrganism(new CyberSheep(this, p)); break;
            case 6: addOrganism(new Grass(this, p)); break;
            case 7: addOrganism(new Sonchus(this, p)); break;
            case 8: addOrganism(new Guarana(this, p)); break;
            case 9: addOrganism(new Belladonna(this, p)); break;
            case 10: addOrganism(new SosnowskyHogweed(this, p)); break;
        }
    }

    for (Organism* org : organisms) {
        org->incrementAge(); // all org have age 1 so can start moving at turn 0
    }
}


//=======================================================================================================
//==================================GAME/TURNS/DRAWING/INPUT==============================
//=======================================================================================================


void World::playGame() {

    while (isGameActive) {
        drawWorld();
        handleInput();
        makeTurn();
    }
}



void World::drawWorld() const {
    system("cls");
    cout << "\nLAST TURN ACTIONS:" << endl; // Sekcja raportów
    for (const auto& m : turnMessages) {
        cout << " - " << m << endl;
    }

    cout << "========================================" << endl;
    cout << "Lena Idczak 208341" << endl;
    cout << "Turn number " << turnNumber << endl;
    cout << "========================================" << endl;
    cout << "To load saved state, please start a new game with n/N"<<endl;
    cout << "Move Human: Arrows | p/P Activate purifying | ENTER - next turn | n/N - new game | q/Q - quit | s/S Save" << endl;
    cout << human->messageState()<<endl;
    cout << "========================================" << endl;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Organism* org = organismsOnGrid[y][x];

            if (org == nullptr) {
                cout << ". ";
            } else {

                switch (org->getType()) {
                    case OrganismType::HUMAN:
                        cout << COLOR_BLUE << org->draw() << COLOR_RESET << " ";
                        break;
                    case OrganismType::PLANT:
                        cout << COLOR_GREEN << org->draw() << COLOR_RESET << " ";
                        break;
                    case OrganismType::ANIMAL:
                        cout << COLOR_RED << org->draw() << COLOR_RESET << " ";
                        break;
                }
            }
        }
        cout << endl;

    }


}



void World::handleInput(){
    if (isHumanALive) {
        human->setMove(STAY);
        human->setWantsToActivateAbility(false);
    }

    bool turnConfirmed = false;

    while (!turnConfirmed) {
        int key = _getch();

        if (key == IS_ARROW || key == 0) {
            key = _getch();
            if (isHumanALive) {

                switch (key) {
                    case A_UP: human->setMove(UP); turnConfirmed = true; break;
                    case A_DOWN: human->setMove(DOWN); turnConfirmed = true; break;
                    case A_LEFT: human->setMove(LEFT); turnConfirmed = true; break;
                    case A_RIGHT: human->setMove(RIGHT); turnConfirmed = true; break;
                    default: human->setMove(STAY); break;
                }
            }
            else {
                addMessage("human is not alive, you can't move him");
            }

        }
        else if (key == 'p' || key == 'P') {
            if (isHumanALive) {
                human->setWantsToActivateAbility(true);
            }
            else {
                addMessage("human is not alive, you can't activate his power");
            }
        }
        else if (key == 'q' || key == 'Q') {
            isGameActive = false;
            turnConfirmed = true;
            startNewGame = false;
        }
        else if (key == NEXT_TURN) {
            turnConfirmed = true;
        }
        else if (key == 'n' || key == 'N') { //new game
            isGameActive = false;
            startNewGame = true;
            turnConfirmed = true;
        }else if (key == 's' || key == 'S') {
            cout<<"saving to the file"<<endl;
            saveWorld(FILE_SAVE_NAME);


        }

    }

}



void World::makeTurn() {
    turnMessages.clear();
    if (! isGameActive) return;


    sortOrganisms();
    //action for every organism
    for (size_t i = 0; i < organisms.size(); ++i) {
        if (organisms[i]->getIsAlive()) {

            if (organisms[i]->getAge()>0) organisms[i]->action();

            organisms[i]->incrementAge();

        }
    }

    for (auto it = organisms.begin(); it != organisms.end(); ) {
        if (!(*it)->getIsAlive()) {
            removeOrganism(*it);
        } else {
            ++it;
        }
    }
    drawWorld();
    turnNumber++;
}



//=======================================================================================================
//==================================MANAGING ORGANISMS EXISTENCE==============================
//=======================================================================================================

void World::addOrganism(Organism* organism) {
    organisms.push_back(organism);

    //string msg = string("adding organism ") + organism->draw() + " to the world";
    //this->addMessage(msg);

    // przypisanie do gridu
    organismsOnGrid[organism->getPosition().y][organism->getPosition().x] = organism;
}


void World::addHuman() {
    Point humanPos = this->getRandomFreeCell();
    Human* czlowiek = new Human(this, humanPos);
    addOrganism(czlowiek);
    this->human = czlowiek;
    this->isHumanALive = true;
}


void World::removeOrganism(Organism* organism) {
    if (organism == nullptr) return;

    // remove from grid
    Point pos = organism->getPosition();


    if (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height) {
        if (organismsOnGrid[pos.y][pos.x] == organism){ //to not delete attacker winner
            organismsOnGrid[pos.y][pos.x] = nullptr;
        }
    }

    // remove from organism vector
    erase(organisms, organism);
    delete organism;
}


void World::sortOrganisms()
{
    sort(organisms.begin(), organisms.end(),

    [](Organism* a, Organism* b) {

        if (a->getInitiative() != b->getInitiative()) {
            return a->getInitiative() > b->getInitiative();
        }
        return a->getAge() > b->getAge();
    });

}



//=======================================================================================================
//==================================MANAGING ORGANISMS POSITION==============================
//=======================================================================================================


bool World::isValidPosition(Point p) const {
    return p.x >= 0 && p.y >= 0 && p.x < width && p.y < height;
}



void World::setOrganismAt(Point p, Organism* o) {
    if (isValidPosition(p)){
        organismsOnGrid[p.y][p.x] = o;
    }
}


Organism* World::getOrganismAtPosition(Point p) const {
    if (!isValidPosition(p)) return nullptr;

    return organismsOnGrid[p.y][p.x];
}




Point World::getRandomFreeNeighbor(Point p, int range) {

    vector<Point> potentialNeighbors;

    for(int dy = -range; dy <= range; dy++){

        for(int dx = -range; dx <= range; dx++){
            Point checkedPoint = {p.x + dx, p.y + dy};

            if(!(checkedPoint == p)
            && isValidPosition(checkedPoint)
            && getOrganismAtPosition(checkedPoint) == nullptr){

                potentialNeighbors.push_back(checkedPoint);
            }
        }
    }

    if (potentialNeighbors.empty()) return p;

    int index = rand() % potentialNeighbors.size();
    return potentialNeighbors[index];

}


Point World::getRandomNeighbor(Point p, int range) {

    vector<Point> potentialNeighbors;
    for(int dy = -range; dy <= range; dy++){

        for(int dx = -range; dx <= range; dx++){

            Point checkedPoint = {p.x + dx, p.y + dy};

            if(checkedPoint != p
            && isValidPosition(checkedPoint)){

                potentialNeighbors.push_back(checkedPoint);
            }
        }
    }
    if (potentialNeighbors.empty()) return p;

    int index = rand() % potentialNeighbors.size();
    return potentialNeighbors[index];

}

Point World::getRandomFreeCell()
{
    vector<Point> freeCells;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (organismsOnGrid[y][x] == nullptr) {
                freeCells.push_back({x, y});
            }
        }
    }

    //if no empty cells
    if (freeCells.empty()) {
        return {-1, -1};
    }

    int randomIndex = rand() % freeCells.size();
    return freeCells[randomIndex];
}











//=======================================================================================================
//==================================HANDLING SAVING TO FILES, LOADING STATE==============================
//=======================================================================================================

void World::clearWorld() {
    for (auto o : organisms) {
        delete o;
    }
    organisms.clear();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            organismsOnGrid[y][x] = nullptr;
        }
    }
    human = nullptr;
    isHumanALive = false;
}



void World::saveWorld(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout<<"Error opening file for saving"<<endl;
        //addMessage("Error opening file for saving");
        return;
    }

    file << width << " " << height << " " << turnNumber << endl;
    file << organisms.size() << endl; // number od organisms


    for (Organism* org : organisms) {
        file << org->draw() << " "
             << org->getPosition().x << " "
             << org->getPosition().y << " "
             << org->getStrength() << " "
             << org->getAge();

        // human
        Human* h = dynamic_cast<Human*>(org); //czy to instacja klasy + pointer conversion, nullptr jak nie
        if (h != nullptr) {
            file << " " << h->getIsAbilityActive()
            << " " << h->getAbilityDuration()
            << " " << h->getAbilityCooldown();

        }
        file << endl;
    }

    file.close();
    cout<<"State saved successfully to "<< filename<<endl;
    //addMessage("State saved successfully to " + filename);
}



World* World::loadWorld(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return nullptr;

    int w, h, turn, numOrg;
    if (!(file >> w >> h >> turn)) return nullptr;


    World* newWorld = new World(w, h);
    newWorld->setTurnNumber(turn);

    file >> numOrg;
    for (int i = 0; i < numOrg; i++) {
        char type;
        int x, y, str, age;
        file >> type >> x >> y >> str >> age;

        Point p = {x, y};
        Organism* org = nullptr;

        switch (type) {
            case 'W': org = new Wolf(newWorld, p); break;
            case 'S': org = new Sheep(newWorld, p); break;
            case 'F': org = new Fox(newWorld, p); break;
            case 'T': org = new Turtle(newWorld, p); break;
            case 'A': org = new Antelope(newWorld, p); break;
            case CYBER_SHEEP_SYMBOL: org = new CyberSheep(newWorld, p); break;
            case 't': org = new Grass(newWorld, p); break;
            case 's': org = new Sonchus(newWorld, p); break;
            case 'g': org = new Guarana(newWorld, p); break;
            case 'b': org = new Belladonna(newWorld, p); break;
            case HOGWEED_SYMBOL: org = new SosnowskyHogweed(newWorld, p); break;

            case 'H': {
                Human* humanOrg = new Human(newWorld, p);
                bool active;
                int dur, cool;
                file >> active >> dur >> cool;
                humanOrg->setAbilityState(active, dur, cool);
                org = humanOrg;

                newWorld->human = humanOrg;
                newWorld->isHumanALive = true;
                break;
            }
        }

        if (org!= nullptr) {
            org->setStrength(str);
            org->setAge(age);
            newWorld->addOrganism(org);
        }
    }

    file.close();
    return newWorld;
}