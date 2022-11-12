#include "../src/libproj/game.h"
#include "acutest.h"

void vvod_count(void)
{
    int matches = 100;
    TEST_ASSERT_(
            raznostMatches(10)
                    == (matches - 10), //ббнд гмювемхъ "10" х япюбмемхе я
                                       //рейсыхл пегскэрюрнл 100 - 10 = 90
            "getMatches(%d)==%d",
            10,
            (matches - 10));
    TEST_ASSERT_(
            raznostMatches(5)
                    == (matches - 15), //ббнд гмювемхъ "5" х япюбмемхе я рейсыхл
                                       //пегскэрюрнл 90 - 5 = 85
            "getMatches(%d)==%d",
            5,
            (matches - 15));
    TEST_ASSERT_(
            raznostMatches(4)
                    == (matches - 19), //ббнд гмювемхъ "4" х япюбмемхе я рейсыхл
                                       //пегскэрюрнл 85 - 4 = 81
            "getMatches(%d)==%d",
            4,
            (matches - 19));
    TEST_ASSERT_(
            raznostMatches(1)
                    == (matches - 20), //ббнд гмювемхъ "1" х япюбмемхе я рейсыхл
                                       //пегскэрюрнл 81 - 1 = 80
            "getMatches(%d)==%d",
            1,
            (matches - 20));
}

void vvod_rus_char(void)
{
    TEST_ASSERT_(
            player_namesProv("бЮЯЪ")
                    == "бЮЯЪ", //ббнд ярпнйх "бЮЯЪ" х япюбмемхе я опедонкнцюелшл
                               //бнгбпюыемхел "бЮЯЪ"
            "getMatches(%s)==%s",
            "бЮЯЪ",
            "бЮЯЪ");
}

TEST_LIST
        = {{"vvod_chisel", vvod_count},
           {"vvod_rus_char", vvod_rus_char},
           {0, 0}}; //бшгнб тсмйжхи