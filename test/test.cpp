#include "../src/libproj/game.h"
#include "acutest.h"

void vvod_count(void)
{
    int matches = 100;
    TEST_ASSERT_(
            raznostMatches(10) == (matches - 10),
            "getMatches(%d)==%d",
            10,
            (matches - 10));
    TEST_ASSERT_(
            raznostMatches(5) == (matches - 15),
            "getMatches(%d)==%d",
            5,
            (matches - 15));
    TEST_ASSERT_(
            raznostMatches(4) == (matches - 19),
            "getMatches(%d)==%d",
            4,
            (matches - 19));
    TEST_ASSERT_(
            raznostMatches(1) == (matches - 20),
            "getMatches(%d)==%d",
            1,
            (matches - 20));
}

void vvod_rus_char(void)
{
    TEST_ASSERT_(
            player_namesProv("Вася") == "Вася",
            "getMatches(%s)==%s",
            "Вася",
            "Вася");
}

TEST_LIST = {{"vvod_chisel", vvod_count}, {"vvod_rus_char", vvod_char}, {0, 0}};