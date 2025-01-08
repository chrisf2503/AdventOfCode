#include <iostream>
#include "advent_2024.h"
#include <fstream>
#include <vector>

void day1(){
    
    std::fstream f("inputs/day1.txt");
    if (!f.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }    
    int num1, num2;
    std::vector<int> l1, l2;    
    while (f >> num1 >> num2){
        l1.push_back(num1);
        l2.push_back(num2);
    }
    std::cout << day1_part1(l1,l2) << std::endl;
    std::cout << day1_part2(l1,l2) << std::endl;
}

int main(){
    //reading input
    day1();
}

