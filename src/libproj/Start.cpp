#include "Start.h"
#include "bot.h"
#include "game.h"
#include <iostream>

int start()
{
    setlocale(LC_ALL, "Russian");
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

int startBot()
{
    for (int i = 0; i <= 1; i++) {
        if (i == 0) {
            std::cout << "Игрок " << i + 1 << ": ";
            player_names(i);
        }
        if (i == 1) {
            bot_name(i);
        }
    }
    std::cout << "В игре есть 100 спичек вы по очереди вытаскиваете от 1 до 10 "
                 "спичек, до тех пор пока спичек не останется. Кто последний "
                 "вытянул спички, тот выиграл.\n\n";
    gameBot();
    player_win();
    getchar();
    return 0;
}