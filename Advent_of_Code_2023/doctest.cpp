#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Aoc.h"

TEST_CASE("Trebuchet test case"){
    std::vector<std::string> list1 = {"1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"};
    CHECK(Trebuchet(list1) == 142);
    std::vector<std::string> list2 = {"fvin1flifjsr4ilfjs0fjsrli3fk","12","f0f4mfo4fow2gf","3", "fslrfjirsfl4lfisrjsr"};
    CHECK(Trebuchet(list2) == 104);
    std::vector<std::string> list3 = {"324filr02fsrlin23fgrs9", "getThisnumber2", "424234324532", "filnf3fnlrnflin49fslinfrs0"};
    CHECK(Trebuchet(list3) == 133);
}