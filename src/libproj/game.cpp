#include "game.h"
#include "bot.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

int matches = 100;
string player[2];
string winner;

void player_win() //ÂÛÂÎÄ ÏÎÁÅÄÈÒÅËß
{
    setlocale(LC_ALL, "Russian");
    cout << "Ïîáåäèë " << winner;
}

void game() //ÈÃĞÀ Ñ ×ÅËÎÂÅÊÎÌ
{
    setlocale(LC_ALL, "Russian");
    while (matches > 0) {
        for (int i = 0; i <= 1; i++) {
            cout << "Õîäèò " << player[i] << endl;
            int count = getMatches();
            raznostMatches(count);
            if (matches > 0) {
                cout << "Îñòàëîñòü ñïè÷åê: " << matches << endl;
            } else {
                winner = player[i];
                break;
            }
        }
    }
}

void gameBot() //ÈÃĞÀ Ñ ÁÎÒÎÌ
{
    int count;
    setlocale(LC_ALL, "Russian");
    while (matches > 0) {
        for (int i = 0; i <= 1; i++) {
            cout << "Õîäèò " << player[i] << endl;
            if (player[i] == player[0]) {
                count = getMatches();
                raznostMatches(count);
            }
            if (player[i] == player[1]) {
                count = easbot();
                raznostMatches(count);
            }
            if (matches > 0) {
                cout << "Îñòàëîñòü ñïè÷åê: " << matches << endl;
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
            cout << "Íóæíî ââåñòè ÷èñëî îò 1 äî 10" << endl;
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

int raznostMatches(int count) //ÂÛ×ÈÒÀÅÍÈÅ ÈÇ ÊÓ×È ÂÂÅÄ¨ÍÍÎÅ ÇÍÀ×ÅÍÈÅ
{
    if (count >= 1 && count <= 10) {
        matches = matches - count;
    }
    return matches;
}

char alfavit(char ch) //ÑĞÀÂÍÅÍÈÅ ÁÓÊÂ ÈÇ ÑÒĞÎÊÈ Ñ ĞÓÑÑÊÈÌÈ ÑÈÌÂÎËÀÌÈ ÈÇ ÌÀÑÑÈÂÀ
{
    bool flag = false;
    char rusName[66] = {'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', '¨', 'Æ', 'Ç', 'È', 'É',
                        'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ğ', 'Ñ', 'Ò', 'Ó', 'Ô',
                        'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ú', 'Û', 'Ü', 'İ', 'Ş', 'ß',
                        'à', 'á', 'â', 'ã', 'ä', 'å', '¸', 'æ', 'ç', 'è', 'é',
                        'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ğ', 'ñ', 'ò', 'ó', 'ô',
                        'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ı', 'ş', 'ÿ'};
    for (int i = 0; i <= 65; i++) {
        if (ch == rusName[i]) {
            flag = true; //ÁÓÊÂÀ ÍÀÉÄÅÍÀ
        }
        if (i == 65 && flag == false) { //ÅÑËÈ ÍÅÒ ÁÓÊÂÛ ÂÛÂÎÄÈÒÑß ÎØÈÁÊÀ
            cout << "Îøèáêà";
        }
        if (flag == true) {
            break; //ÅÑËÈ ÁÓÊÂÀ ÍÀÉÄÅÍÀ ÇÀÊÎÍ×ÈÒÜ ÏĞÎÂÅĞÊÓ
        }
    }
    return ch;
}

string player_namesProv(char* name) //ÏĞÎÂÅĞÊÀ ÑÒĞÎÊÈ ÈÌÅÍÈ Ñ ĞÓÑÑÊÈÌÈ ÁÓÊÂÀÌÈ
                                    //ÈÇ ÔÓÍÊÖÈÈ "alfavit"
{
    if (name[0] != '\0') {
        for (int i = 0; i <= *name; i++) {
            if (name[i] != '\0') {
                if (name[i] != alfavit(name[i])) {
                    for (int j = 0; j <= 15; j++) {
                        name[j] = '\0';
                    }
                    return name;
                }
            }
        }
    }
    return name;
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
                    cout << "Íåäîïóñòèìûé ñèìâîë" << endl;
                    n = 0;
                }
            }
        }
        if (player_namesProv(str) == "\0") {
            cout << "fail\n";
            flag = false;
        }
    }
    player[i] = str;
    return player[i];
}

string bot_name(int i)
{
    player[i] = "Êîìïüşòåğ";
    return player[i];
}