#include "Start.h"
#include "game.h"
#include <Windows.h>
#include <iostream>

int start()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Привет, вы пришли в игру 100 спичек, представьтесь\n";
    for (int i = 0; i <= 1; i++) {
        std::cout << "Игрок " << i + 1 << ": ";
        player_names(i);
    }
    std::cout << "В игре есть 100 спичек вы по очереди вытаскиваете от 1 до 10 "
                 "спичек, до тех пор пока спичек не останется. Кто последний "
                 "вытянул спички, тот выиграл.\n\n";
    game();
    player_win();
    getchar();
    return 0;
}
