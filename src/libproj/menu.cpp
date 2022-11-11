#include "Start.h"
#include "bot.h"
#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

void onePlayer()
{
    games();
}
void twoPlayers()
{
    start();
}

int getNum()
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
            cout << "Ошибка ввода" << endl;
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

int menu()
{
    int input;
    setlocale(LC_ALL, "Russian");
    std::cout << "В игре есть 100 спичек вы по очереди вытаскиваете от 1 до 10 "
                 "спичек, до тех пор пока спичек не останется. Кто последний "
                 "вытянул спички, тот выиграл.\n\n";
    cout << "1. 1 Игрок\n";
    cout << "2. 2 Игрока\n";
    cout << "3. Выход\n";
    cout << "Выберите режим игры: ";
    do {
        int ch;
        input = getNum();
        switch (input) {
        case 1:
            onePlayer();
            break;
        case 2:
            twoPlayers();
            break;
        case 3:
            break;
        default:
            cout << "Нет режима с данным номером\n";
            break;
        }
    } while (input != 3);
    return 0;
}