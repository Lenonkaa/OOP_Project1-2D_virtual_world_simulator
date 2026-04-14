#include <iostream>
#include <ctime>
#include "World.h"
#include "Organisms/Animals/Wolf.h"

int main() {

    srand(time(NULL));

    World mojSwiat(10, 10);

    Point pozycjaWilka = {5, 9};


    Wolf* staryWilk = new Wolf(&mojSwiat, pozycjaWilka);


    mojSwiat.addOrganism(staryWilk);
    mojSwiat.drawWorld();


    return 0;
}