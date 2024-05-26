#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
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
void is_val(std::string & sets);
//Formating Example -> Game 9: 1 green, 5 blue; 4 blue; 2 red, 1 blue
std::unordered_map<std::string, int> bag_contains = {{"red",12},{"green", 13},{"blue", 14}}; 
int CubeConundrum(std::vector<std::string> & inputs){
    int ans = 0;
    std::string index = "";
    //We want to get the set
    std::string sets = "";
    //First we want to be able to go through the list of games
    for(int i = 0; i < inputs.size(); i++){
        //Lets get the substring of the sets (1 green, 5 blue; 4 blue; 2 red, 1 blue)
        std::string sets = inputs[i].substr(inputs[i].find(":")+2);
        
    }
    return ans;
}
//Here we want to get a list of cube number an color by sets, we know its a set when a ';' seperates them
std::vector<std::string> get_sets(std::string &sets){
    std::vector<std::string> set;
    for(int i = 0; i < sets.length(); i++){
        if(sets[i] == ';'){
            set.push_back(sets.substr(0,sets.find(";")));
            sets = sets.substr(sets.find(";")+2);
            i = sets.find(" ");
        }
    }
    set.push_back(sets);
    return set;
}