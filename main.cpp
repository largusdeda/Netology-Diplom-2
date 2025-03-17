#include <iostream>
#include "game_status.h"
#include "game.h"

using namespace race;

int main() {
#ifdef _WIN32
    setlocale(LC_ALL, "rus");
#endif

    Game g;
    while (g.play() != GameStatus::EXIT) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    return EXIT_SUCCESS;
}