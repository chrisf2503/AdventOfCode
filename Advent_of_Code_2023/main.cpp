#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Aoc.h"

std::vector<std::string> readFile(std::string && fileName){
    std::ifstream f(fileName);
    if(!f.is_open()){
        std::cerr << "Can not open file" << std::endl;
    }
    std::vector<std::string> input;
    std::string s;
    while(f >> s){
        input.push_back(s);
    }
    return input;
}

int main(){
    std::vector<std::string> get_input = readFile("TrebuchetInputs.txt");
    int ans = Trebuchet(get_input);
    std::cout << "Trebuchet Ans: " << ans << std::endl;
}