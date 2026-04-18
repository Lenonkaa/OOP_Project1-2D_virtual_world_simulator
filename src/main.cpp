#include <iostream>
#include <ctime>
#include "World.h"
#include "Organisms/Animals/Wolf.h"
#include "Organisms/Plants/Grass.h"

int main() {

    srand(time(NULL));

    World mojSwiat(10, 10);

    Point pozycjaWilka = {5, 9};
    Point pozycjaGrass = {5, 4};

    Wolf* staryWilk = new Wolf(&mojSwiat, pozycjaWilka);

    Grass* trawa = new Grass(&mojSwiat, pozycjaGrass);


    mojSwiat.addOrganism(staryWilk);
    mojSwiat.addOrganism(trawa);

    mojSwiat.playGame();

    return 0;
}
