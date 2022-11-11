#include "Start.h"
#include "game.h"
#include <iostream>

int start()
{
    setlocale(LC_ALL, "Russian");
    system("cls");
    for (int i = 0; i <= 1; i++) {
        std::cout << "Игрок " << i + 1 << ": ";
        player_names(i);
    }
    game();
    player_win();
    getchar();
    return 0;
}