#include "bot.h"
#include "game.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

int easbot()
{
    int geti;
    srand(time(NULL));
    int matchesBot = raznostMatches(0);
    if (matchesBot <= 10) {
        geti = matchesBot;
    } else {
        geti = rand() % 10 + 1;
    }
    return geti;
}
