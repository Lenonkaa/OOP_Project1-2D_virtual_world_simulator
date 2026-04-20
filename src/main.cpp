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

        World* gameWorld = nullptr;
        char choice;

        cout << "========================================" << endl;
        cout << "  2D WORLD SIMULATOR" << endl;
        cout << "========================================" << endl;
        cout << "Choose [N] - New Game or [L] - Load Game" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 'l' || choice == 'L') {
            gameWorld = World::loadWorld(FILE_SAVE_NAME);
            if (gameWorld == nullptr) {
                cout << "Failed to load file. Starting a new game" << endl;
            }
        }

        if (gameWorld == nullptr) {
            int w, h;
            double fill;
            cout << "Enter the world width (5-500): ";
            cin >> w;
            cout << "Enter the world height (5-500): ";
            cin >> h;
            cout << "Enter initial filling of the world (between 0.05 and 1.0)";
            cin >> fill;

            if (w < 5) w = 5;
            if (h < 5) h = 5;
            if (w>500) w = 500;
            if (h>500) h = 500;
            if (fill <= 0.0) fill = 0.05;
            if (fill > 1.0) fill = 1.0;

            gameWorld = new World(w, h);
            gameWorld->populateWorld(fill);
        }



        gameWorld->playGame();
        playAgain=false;
        playAgain=gameWorld->getStartNewGame();

        delete gameWorld;

    }
    while (playAgain);

    return 0;
}
