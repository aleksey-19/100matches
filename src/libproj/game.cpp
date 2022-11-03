#include "game.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

int matches = 100;
string player[2];
string winner;

void player_win()
{
    cout << "Победил " << winner;
}

void game()
{
    while (matches > 0) {
        for (int i = 0; i <= 1; i++) {
            cout << "Ходит " << player[i] << endl;
            int count = getMatches();
            raznostMatches(count);
            if (matches > 0) {
                cout << "Осталость спичек: " << matches << endl;
            } else {
                winner = player[i];
                break;
            }
        }
    }
}

int getMatches()
{
    int ch;
    int const k = 2;
    char str[k] = {'\0'};
    int n = 0;
    int get;
    while (n < k) {
        ch = _getch();
        if (ch != 13) {
            if (ch == 224) {
                cout << endl;
                cout << "Недопустимый символ." << endl;
                n = 0;
                str[0] = {'0'};
                str[1] = {'\0'};
            } else {
                if (ch >= 48 && ch <= 57) {
                    cout << char(ch);
                    str[n] = char(ch);
                    n++;
                } else {
                    cout << endl;
                    cout << "Недопустимый символ, напишите число сначала"
                         << endl;
                    n = 0;
                    str[0] = {'0'};
                    str[1] = {'\0'};
                }
            }
        }
        get = atoi(str);
        if (ch == 13 || n == k) {
            if (get >= 1 && get <= 10) {
                cout << std::endl;
                break;
            } else {
                cout << endl;
                cout << "Нужно ввести число от 1 до 10" << endl;
                n = 0;
                str[0] = {'0'};
                str[1] = {'\0'};
            }
        }
    }
    return get;
}

int raznostMatches(int count)
{
    if (count >= 1 && count <= 10) {
        matches = matches - count;
    }
    return matches;
}

string player_names(int i)
{
    bool flag = false;
    int ch;
    int const k = 16;
    char str[k] = {'0'};
    int n = 0;
    while (n < k) {
        ch = _getch();
        if (ch != 13) {
            if ((ch == 72 || ch == 80 || ch == 77 || ch == 75)
                && flag == true) {
                std::cout << "Стрелки - Недопустимый символ" << endl;
                if (str[0] != '0') {
                    cout << str;
                }
                flag = false;
            }
            if ((ch != 72 && ch != 80 && ch != 77 && ch != 75)
                && flag == true) {
                cout << char(224);
                str[n] = char(224);
                n++;
                flag = false;
            }
            /*{
                ch = 224;
                cout << char(ch);
                str[n] = char(ch);
                n++;
            }*/
            if (ch == 224) {
                flag = true;
            }
            if (((ch >= 128 && ch <= 175) || (ch >= 225 && ch <= 243))) {
                cout << char(ch);
                str[n] = char(ch);
                n++;
            } else if (
                    (ch != 72 && ch != 80 && ch != 77 && ch != 75)
                    && flag == false) {
                std::cout << "Недопустимый символ" << endl;
                if (str[0] != '0') {
                    cout << str;
                }
            }

        } else {
            if (str[0] != '0') {
                break;
            } else {
                cout << "Нужно ввести имя." << endl;
            }
        }
    }
    cout << endl;
    player[i] = str;
    return player[i];
}