#include <iostream>
#include <ctime>
#include "World.h"
#include "Organisms/Animals/Sheep.h"
#include "Organisms/Animals/Wolf.h"
#include "Organisms/Plants/Grass.h"

int main() {

    srand(time(NULL));

    World mojSwiat(10, 10);

    Point pozycjaWilka = {5, 9};
    Point pozycjaGrass = {5, 4};

    Wolf* staryWilk = new Wolf(&mojSwiat, pozycjaWilka);

    Grass* trawa = new Grass(&mojSwiat, pozycjaGrass);

    Point pod = mojSwiat.getRandomFreeCell();
    Sheep* owca = new Sheep(&mojSwiat, pod);

    mojSwiat.addOrganism(staryWilk);
    mojSwiat.addOrganism(trawa);
    mojSwiat.addOrganism(owca);

    mojSwiat.playGame();

    return 0;
}
