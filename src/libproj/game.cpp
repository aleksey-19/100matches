#include "game.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

int matches = 100;
string player[2];
string winner;

void player_win()
{
    setlocale(LC_ALL, "Russian");
    cout << "Победил " << winner;
}

void game()
{
    setlocale(LC_ALL, "Russian");
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
    setlocale(LC_ALL, "Russian");
    bool flag = false;
    int ch;
    int const k = 2;
    char str[k] = {'\0'};
    int n = 0;
    int get;
    while (flag != true) {
        while (n < k) {
            ch = getchar();
            if (ch != 10) {
                if (ch >= 48 && ch <= 57) {
                    str[n] = char(ch);
                    n++;
                } else {
                    n = 0;
                    str[0] = {'0'};
                    str[1] = {'\0'};
                }
            } else {
                break;
            }
        }
        get = atoi(str);
        if (get >= 1 && get <= 10) {
            flag = true;
            while (ch != 10) {
                ch = getchar();
            }
        } else {
            cout << "Нужно ввести число от 1 до 10" << endl;
            n = 0;
            str[0] = {'0'};
            str[1] = {'\0'};
            while (ch != 10) {
                ch = getchar();
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
    setlocale(LC_ALL, "Russian");
    bool flag = false;
    int ch;
    int const k = 16;
    char str[k] = {'0'};
    int n = 0;
    while (flag != true) {
        flag = false;
        while (n < k) {
            ch = getchar();
            if (ch != 10) {
                if (((ch >= 192 && ch <= 223) || (ch >= 224 && ch <= 255))) {
                    str[n] = char(ch);
                    n++;
                }
            } else {
                if (str[0] != '0') {
                    flag = true;
                    break;
                } else {
                    cout << "Недопустимый символ" << endl;
                    n = 0;
                }
            }
        }
    }
    player[i] = str;
    return player[i];
}