#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <cmath>
/**
 * Given a list of string with random characters, (containing letters an numbers), for each 
 * string we want to get the first an last numbers, convert it to a int, repeat this until 
 * the end of the list an sum everything
 * 例：1abc2, pqr3stu8vwx, a1b2c3d4e5f, treb7uchet
 * here we want to get 1 and 2 which makes 12
 * then we get 3 an 8 which makes 38
 * then 1 and 5 which makes 15
 * last would be 77 since it is the first an last number that occurs
 * so we get 12, 38, 15, 77, we add those up to get 142
*/
int Trebuchet(std::vector<std::string> & inputs){
    int ans = 0;
    //this will be keep track of our first an last digit number
    std::string num = "";
    //we first want to go over the list 
    for(int i = 0; i < inputs.size(); i++){
        std::string s = inputs[i];
        int j;
        //when we get each string we want to find the first non_alphabetic character
        for(j = 0; j < s.length(); j++){
            if(!isalpha(s[j])){
                num += s[j];
                break;
            }
        }
        //Now we want to get the last non_alphabetic character
        for(j = s.length()-1; j >= 0; j--){
            if(!isalpha(s[j])){
                num += s[j];
                break;
            }
        }
        //convert string to an int
        ans += stoi(num);
        //reset back a empty string
        num = "";
    }    
    return ans;
}
//Day 2
bool is_val(std::string & sets);
//Formating Example -> Game 9: 1 green, 5 blue; 4 blue; 2 red, 1 blue
std::unordered_map<std::string, int> bag_contains = {{"red",12},{"green", 13},{"blue", 14}}; 
int CubeConundrum(std::vector<std::string> & inputs){
    int ans = 0;
    //We want to get the set
    std::string sets = "";
    //First we want to be able to go through the list of games
    for(int i = 0; i < inputs.size(); i++){
        sets = inputs[i].substr(inputs[i].find(":")+2);
        if(is_val(sets)){
            ans += (i+1);
        }
    }
    return ans;
}
//Here we want to get a list of cube number an color by sets, we know its a set when a ';' seperates them
std::vector<std::string> get_sets(std::string &sets, char sep){
    std::vector<std::string> set;
    for(int i = 0; i < sets.length(); i++){
        if(sets[i] == sep){
            set.push_back(sets.substr(0,sets.find(sep)));
            sets = sets.substr(sets.find(sep)+2);
            i = sets.find(" ")+3;
        }
    }
    set.push_back(sets);
    return set;
}
bool is_val(std::string & sets){
    std::vector<std::string> set = get_sets(sets,';');
    for(int i = 0; i < set.size(); i++){
        std::vector<std::string> num_and_color = get_sets(set[i],',');
        for(int j = 0; j < num_and_color.size(); j++){
            std::string num = num_and_color[j].substr(0,num_and_color[j].find(" "));
            int n = stoi(num);
            num_and_color[j] = num_and_color[j].substr(num_and_color[j].find(" ")+1);
            if(n > bag_contains[num_and_color[j]]){
                return false;
            }
        }
    }
    return true;
}

//Day 2 part 2:
int get_multi(std::string & sets);
int CubeConundrumPart2(std::vector<std::string> & inputs){
    int ans = 0;
    std::string sets = "";
    for(int i = 0; i < inputs.size(); i++){
        sets = inputs[i].substr(inputs[i].find(":")+2);
        ans += get_multi(sets);
    }
    return ans;
}

int get_multi(std::string & sets){
    //We will use a hash map in order to do comparison
    std::unordered_map<std::string, int> max = {{"red", 0},{"blue",0},{"green",0}};
    std::vector<std::string> set = get_sets(sets, ';');
    for(int i = 0; i < set.size(); i++){
        std::vector<std::string> num_and_color = get_sets(set[i],',');
        for(int j = 0; j < num_and_color.size(); j++){
            std::string num = num_and_color[j].substr(0,num_and_color[j].find(" "));
            int n = stoi(num);
            num_and_color[j] = num_and_color[j].substr(num_and_color[j].find(" ")+1);
            //we will check which number is the max an set it to the hashmap
            max[num_and_color[j]] = std::max(n,max[num_and_color[j]]);
        }
    }
    int multi = 1;
    for(auto get: max){
        multi *= get.second;
    }
    return multi;
}