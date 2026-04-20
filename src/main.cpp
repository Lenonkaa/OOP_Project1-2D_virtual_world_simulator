#include <iostream>
#include <ctime>
#include "World.h"
#include "Organisms/Animals/Sheep.h"
#include "Organisms/Animals/Wolf.h"
#include "Organisms/Plants/Grass.h"
#include "Organisms/Human.h"

int main() {

    srand(time(NULL));

    bool playAgain=false;
    do {
        int w, h;
        double fill;

        cout << "========================================" << endl;
        cout << "  2D WORLD SIMULATOR" << endl;
        cout << "========================================" << endl;

        cout << "Enter the world width: ";
        cin >> w;
        cout << "Enter the world height: ";
        cin >> h;
        cout << "Enter initial filling of the world (between 0.1 and 1.0)";
        cin >> fill;


        if (w < 5) w = 5;
        if (h < 5) h = 5;
        if (fill <= 0.0) fill = 0.1;
        if (fill > 1.0) fill = 1.0;

        World gameWorld(w, h);

        gameWorld.populateWorld(fill);

        gameWorld.playGame();

        playAgain = gameWorld.getStartNewGame();
    }
    while (playAgain);

    return 0;
}
