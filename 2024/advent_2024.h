#pragma once
#include <iostream>
#include <vector>
#include <queue>          // std::priority_queue
#include <unordered_map> 
#include <cmath>

/** Day 1: 
 * A list of location ID
 * Location Id: unique number 
 * list of 2
 * We want to pair up the smallest number from list 1 to list 2, soon we 
 * want to find out how far apart the numbers are an then sum it all up
 * 
 * Therefore we want to sort the both list from least to greatest 
 * then pair the 2 smallest together 
 * 
 */

int day1_part1(std::vector<int> list1, std::vector<int> list2){
    std::priority_queue<int> sort1(list1.begin(),list1.end());
    std::priority_queue<int> sort2(list2.begin(), list2.end());
    int sum = 0;
    while(!sort1.empty()){
        sum += std::abs(sort1.top()-sort2.top());
        sort1.pop();
        sort2.pop();

    }
    return sum;
}
/**
 * Location ID repeat on both list at a certain number of times
 * Chek of often each number for the l1 appear on l2
 * once we found out the number of times it accures, we want to multiply then sum it up 
 * sum += l[i] * n 
 * The example that was given l1 = [3,4,2,1,3,3], l2 = [4,3,5,3,9,3]
 * We can put l2 into a hashtable in to count the number time each number appears within the list
 * and then go through l1 to check if the count exist meaning when hash[i] > 0
 */
int day1_part2(std::vector<int> l1, std::vector<int> l2){
    int sum = 0;
    std::unordered_map<int,int> count;//everything should be set to 0 for each key that doesnt exist
    for(int i = 0; i < l2.size(); i++){
        count[l2[i]]++;
    }

    for(int i = 0; i < l1.size(); i++){
        if(count[l1[i]] > 0){
            sum += l1[i] * count[l1[i]];
        }
    }
    return sum; 
}
