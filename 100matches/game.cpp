#include "game.h"
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

int matches = 100;
string player[2];
string winner;

void player_win()
{
	std::cout << "Победил " << winner;
}

void game()
{
	int count;
	while (matches > 0)
	{
		for (int i = 0; i <= 1; i++)
		{
			bool flag = false;
			std::cout << "Ходит " << player[i] << "\n";
			while (flag != true)
			{
				std::cin >> count;
				if (count >= 1 && count <= 10)
				{
					getMatches(count);
					flag = true;
				}
				else
				{
					std::cout << "Возьмите от 1 до 10 спичек!\n";
				}
			}
			if (matches > 0)
			{
				std::cout << "Осталость спичек: " << matches << "\n";
			}
			else
			{
				winner = player[i];
				break;
			}
		}
	}
}

int getMatches(int count)
{
	if (count >= 1 && count <= 10)
	{
		matches = matches - count;
		return matches;
	}
	else
	{
		return matches;
	}
}

string player_names(int i)
{
	char name[16];
	std::cout << "Игрок " << i + 1 << ": ";
	std::cin >> name;
	player[i] = name;
	return player[i];
}