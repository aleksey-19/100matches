#include "Start.h"
#include "game.h"
#include <iostream>

int start()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "������, �� ������ � ���� 100 ������, �������������\n";
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