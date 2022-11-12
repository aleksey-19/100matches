#ifndef GAME
#define GAME
#include <string>
using namespace std;

void player_win();
void game();
void gameBot();
int getMatches();
int raznostMatches(int count);
char alfavit(char ch);
string player_namesProv(char name[16]);
string player_names(int i);
string bot_name(int i);

#endif