#include "bot.h"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int matche = 100;
string playe[2];
string winne;
string enemy = "Компьютер";

void player_wi()
{
    setlocale(LC_ALL, "Russian");
    cout << "Победил " << winne;
}

void gamebot()
{
    setlocale(LC_ALL, "Russian");
    while (matche > 0) {
        for (int i = 0; i <= 1; i++) {
            if (playe[i] == playe[0]) {
                cout << "Ходит " << playe[i] << endl;
                int count = getMatche();
                raznostMatche(count);
                if (matche > 0) {
                    cout << "Осталость спичек: " << matche << endl;
                } else {
                    winne = playe[i];
                    break;
                }
            }
            if (playe[i] == playe[1]) {
                cout << "Ходит " << playe[i] << endl;
                int count = easbot();
                raznostMatche(count);
                if (matche > 0) {
                    cout << "Осталость спичек: " << matche << endl;
                } else {
                    winne = playe[i];
                    break;
                }
            }
        }
    }
}

int getMatche()
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

int easbot()
{
    int geti;
    srand(time(NULL));

    if (matche <= 10) {
        geti = matche;
    } else {
        geti = rand() % 10 + 1;
    }
    return geti;
}

int raznostMatche(int count)
{
    if (count >= 1 && count <= 10) {
        matche = matche - count;
    }
    return matche;
}

string player_name(int i)
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
    playe[i] = str;
    return playe[i];
}

int games()
{
    system("cls");
    std::cout << "Представьтесь." << endl;
    std::cout << "Для написания имени можно использовать только русские символы"
              << endl;
    for (int i = 0; i <= 1; i++) {
        if (i == 0) {
            std::cout << "Игрок " << i + 1 << ": ";
            player_name(i);
        }
        if (i == 1) {
            playe[1] = enemy;
        }
    }
    std::cout << "В игре есть 100 спичек вы по очереди вытаскиваете от 1 до 10 "
                 "спичек, до тех пор пока спичек не останется. Кто последний "
                 "вытянул спички, тот выиграл.\n\n";
    easbot();
    gamebot();
    player_wi();
    getchar();
    return 0;
}
