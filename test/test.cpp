#include "acutest.h"
#include "../src/libproj/game.h"

void vvod_count(void)
{
	int matches = 100;
	TEST_ASSERT_(raznostMatches(10) == (matches - 10), "getMatches(%d)==%d",10, (matches - 10));
	TEST_ASSERT_(raznostMatches(5) == (matches - 15), "getMatches(%d)==%d", 5, (matches - 15));
	TEST_ASSERT_(raznostMatches(4) == (matches - 19), "getMatches(%d)==%d", 4, (matches - 19));
	TEST_ASSERT_(raznostMatches(1) == (matches - 20), "getMatches(%d)==%d", 1, (matches - 20));
}

TEST_LIST = {
	{"int vvod(int);", vvod_count},
	{0}
};