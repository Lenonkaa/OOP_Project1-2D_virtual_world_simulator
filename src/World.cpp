//
// Created by lenai on 4/10/2026.
//

#include "World.h"


#define IS_ARROW 224

#define A_UP 72
#define A_DOWN 80
#define A_LEFT 75
#define A_RIGHT 77
#define ABILITY 112
#define ABILITY2 80

#include "Organisms/Human.h"

void World::addHuman() {
    Point humanPos = this->getRandomFreeCell();
    Human* czlowiek = new Human(this, humanPos);
    addOrganism(czlowiek);
    this->human = czlowiek;
    this->isHumanALive = true;
}

void World::handleInput() {
    int key = _getch();

    if (key == IS_ARROW || key == 0) {
        key = _getch();
        if (isHumanALive) {
            switch (key) {
                case A_UP: human->setMove(UP); break;
                case A_DOWN: human->setMove(DOWN); break;
                case A_LEFT: human->setMove(LEFT); break;
                case A_RIGHT: human->setMove(RIGHT); break;
                default: human->setMove(STAY); break;
            }
        }
        else {
            addMessage("human is not alive, you can't move him");
        }

    } else {
        // s - activate special
        switch (key) {
            case 's':
            case 'S':
                if (isHumanALive) {
                    human->setMove(SPECIAL);
                }
                else {
                    addMessage("human is not alive, you can't activate his power");
                }
                break;
            default:
                human->setMove(STAY);
                break;
        }
    }
}

void World::setOrganismAt(Point p, Organism* o) {
    if (!p.isOutGrid(height,width)){
        organismsOnGrid[p.y][p.x] = o;
    }
}


Organism* World::getOrganismAtPosition(Point p) const {
    if (p.isOutGrid(height,width)) return nullptr;

    return organismsOnGrid[p.y][p.x];
}

Point World::getRandomFreeNeighbor(Point p, int range) {
    vector<Point> potentialNeighbors;
    for(int dy = -range; dy <= range; dy++){

        for(int dx = -range; dx <= range; dx++){
            Point checkedPoint = {p.x + dx, p.y + dy};

            if(!(checkedPoint == p)
            && !checkedPoint.isOutGrid(height,width)
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
            && !checkedPoint.isOutGrid(height,width)){

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

void World::playGame() {

    addHuman();
    while (isGameActive) {
        drawWorld();
        handleInput();
        makeTurn();
    if (turnNumber==10) {
        isGameActive = false;
    }
    }
}

World::World(int w, int h) : width(w), height(h), turnNumber(0), isGameActive(1) {

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
/*
void Swiat::WykonajTure()
{
    Komentator::WyczyscKomentarzy();
    ObslugaInputu();
    if (czyJestKoniecGry) return;
    numerTury++;
    RysujSwiat();
    SortujOrganizmy();
    for (size_t i = 0; i < organizmy.size(); i++) {
        if (organizmy[i]->GetCzyUmarl() == true) { continue; }
        else if (organizmy[i]->GetTuraUrodzenia() != numerTury) {
            organizmy[i]->Akcja();
            RysujSwiat();
        }
    }

    for (size_t i = 0; i < organizmy.size(); i++) {
        if (organizmy[i]->GetCzyUmarl() == true) {
            delete organizmy[i];
            organizmy.erase(organizmy.begin() + i);
        }
    }
    for (size_t i = 0; i < organizmy.size(); i++) {
        organizmy[i]->SetCzyRozmnazalSie(false);
    }
}
*/
void World::addOrganism(Organism* organism) {
    organisms.push_back(organism);

    string msg = string("adding organism ") + organism->draw() + " to the world";
    this->addMessage(msg);

    // przypisanie do tablicy 2D - gridu:
    organismsOnGrid[organism->getPosition().y][organism->getPosition().x] = organism;
}


void World::drawWorld() const {
    system("cls");
    cout << "========================================" << endl;
    cout << "Lena Idczak 208341" << endl;
    cout << "Turn number " << turnNumber << endl;
    cout << "========================================" << endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (organismsOnGrid[y][x] == nullptr) { //empty cell
                cout << ". ";
            } else { //cell with organism
                cout << organismsOnGrid[y][x]->draw() << " ";
            }
        }
        cout << endl;

    }

    cout << "\nLAST TURN ACTIONS:" << endl; // Sekcja raportów
    for (const auto& m : turnMessages) {
        cout << " - " << m << endl;
    }
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