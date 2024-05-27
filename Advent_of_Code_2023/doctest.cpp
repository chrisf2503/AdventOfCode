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
TEST_CASE("Testing CubeConundrum"){
    std::vector<std::string> list1 = {"Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"};
    CHECK(list1.size()==5);
    CHECK(CubeConundrum(list1) == 8);
}
TEST_CASE("getting sets"){
    std::string set1 = "Game 5: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
    std::string get_sets_list = set1.substr(set1.find(":")+2);
    std::vector<std::string> sets = get_sets(get_sets_list,';');
    CHECK(sets[0] == "3 blue, 4 red");
    CHECK(sets[1] == "1 red, 2 green, 6 blue");
    CHECK(sets[2] == "2 green");
    CHECK(sets.size() == 3);
    std::string set2 = "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue";
    get_sets_list = set2.substr(set1.find(":")+2);
    sets = get_sets(get_sets_list,';');
    CHECK(sets[0] == "1 blue, 2 green");
    CHECK(sets[1] == "3 green, 4 blue, 1 red");
    CHECK(sets[2] == "1 green, 1 blue");
    CHECK(sets.size() == 3);
    std::string set3 = "6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";
    std::vector<std::string> sets2 = get_sets(set3,';');
    CHECK(sets2[0] == "6 red, 1 blue, 3 green");
    CHECK(sets2[1] == "2 blue, 1 red, 2 green");
    CHECK(sets2.size() == 2);
    std::string s1 = "1 blue, 2 green";
    std::vector<std::string> num_color = get_sets(s1, ',');
    CHECK(num_color[0] == "1 blue");
    CHECK(num_color[1] == "2 green");
    CHECK(num_color.size()==2);
    std::string s2 = "3 green, 59 red";
    num_color = get_sets(s2,',');
    CHECK(num_color[0] == "3 green");
    CHECK(num_color[1] == "59 red");
    CHECK(num_color.size()==2);
    std::string s3 = "6 red, 1 blue, 3 green";
    std::vector<std::string> num_color2 = get_sets(s3,',');
    CHECK(num_color2[0] == "6 red");
    CHECK(num_color2[1] == "1 blue");
    CHECK(num_color2[2] == "3 green");
    CHECK(num_color2.size() == 3);
    std::string s4 = "2 blue, 1 red, 2 green";
    num_color2 = get_sets(s4,',');
    CHECK(num_color2[0] == "2 blue");
    CHECK(num_color2[1] == "1 red");
    CHECK(num_color2[2] == "2 green");
    CHECK(num_color2.size() == 3);
}
TEST_CASE("is_valid function"){
    std::vector<std::string> list1 = {"Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"};
    for(int i = 0; i < list1.size(); i++){
        std::string get_sets_list = list1[i].substr(list1[i].find(":")+2);
        if(i == 2 || i == 3){
            CHECK(!is_val(get_sets_list));
        }
        else{
            CHECK(is_val(get_sets_list));
        }

    }
    
}
TEST_CASE("day 2 part 2"){
    std::vector<std::string> list1 = {"Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"};
    CHECK(CubeConundrumPart2(list1) == 2286);
}