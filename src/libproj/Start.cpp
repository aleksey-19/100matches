#include "Start.h"
#include "bot.h"
#include "game.h"
#include <iostream>

int start()
{
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i <= 1; i++) {
        std::cout << "����� " << i + 1 << ": ";
        player_names(i);
    }
    std::cout << "� ���� ���� 100 ������ �� �� ������� ������������ �� 1 �� 10 "
                 "������, �� ��� ��� ���� ������ �� ���������. ��� ��������� "
                 "������� ������, ��� �������.\n\n";
    game();
    player_win();
    getchar();
    return 0;
}

int startBot()
{
    for (int i = 0; i <= 1; i++) {
        if (i == 0) {
            std::cout << "����� " << i + 1 << ": ";
            player_names(i);
        }
        if (i == 1) {
            bot_name(i);
        }
    }
    std::cout << "� ���� ���� 100 ������ �� �� ������� ������������ �� 1 �� 10 "
                 "������, �� ��� ��� ���� ������ �� ���������. ��� ��������� "
                 "������� ������, ��� �������.\n\n";
    gameBot();
    player_win();
    getchar();
    return 0;
}