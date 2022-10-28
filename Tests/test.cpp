#include "acutest.h"
#include "../100matches/game.h"

void vvod_count(void)
{
	int matches = 100;
	TEST_ASSERT_(getMatches(10) == (matches - 10), "getMatches(%d)==%d",10, (matches - 10));
	TEST_ASSERT_(getMatches(5) == (matches - 15), "getMatches(%d)==%d", 5, (matches - 15));
	TEST_ASSERT_(getMatches(4) == (matches - 19), "getMatches(%d)==%d", 4, (matches - 19));
	TEST_ASSERT_(getMatches(1) == (matches - 20), "getMatches(%d)==%d", 1, (matches - 20));
}

TEST_LIST = {
	{"int vvod(int);", vvod_count},
	{0}
};
