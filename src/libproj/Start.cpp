#include "Start.h"
#include "game.h"
#include <iostream>
#include <Windows.h>


int start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "������, �� ������ � ���� 100 ������, �������������\n";
	for (int i = 0; i <= 1; i++) {
		player_names(i);
	}
	std::cout << "� ���� ���� 100 ������ �� �� ������� ������������ �� 1 �� 10 ������, �� ��� ��� ���� ������ �� ���������. ��� ��������� ������� ������, ��� �������.\n\n";
	game();
	player_win();
	getchar();
	return 0;
}
