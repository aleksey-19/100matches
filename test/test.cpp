#include "../src/libproj/game.h"
#include "acutest.h"

void vvod_count(void)
{
    int matches = 100;
    TEST_ASSERT_(
            raznostMatches(10) == (matches - 10), //���� �������� "10" � ��������� � ������� ����������� 100 - 10 = 90
            "getMatches(%d)==%d",
            10,
            (matches - 10));
    TEST_ASSERT_(
            raznostMatches(5) == (matches - 15), //���� �������� "5" � ��������� � ������� ����������� 90 - 5 = 85
            "getMatches(%d)==%d",
            5,
            (matches - 15));
    TEST_ASSERT_(
            raznostMatches(4) == (matches - 19), //���� �������� "4" � ��������� � ������� ����������� 85 - 4 = 81
            "getMatches(%d)==%d",
            4,
            (matches - 19));
    TEST_ASSERT_(
            raznostMatches(1) == (matches - 20), //���� �������� "1" � ��������� � ������� ����������� 81 - 1 = 80
            "getMatches(%d)==%d",
            1,
            (matches - 20));
}

void vvod_rus_char(void)
{
    TEST_ASSERT_(
            player_namesProv("����") == "����", //���� ������ "����" � ��������� � �������������� ������������ "����"
            "getMatches(%s)==%s",
            "����",
            "����");
}

TEST_LIST = {
        {"vvod_chisel", vvod_count}, {"vvod_rus_char", vvod_rus_char}, {0, 0}}; //����� �������