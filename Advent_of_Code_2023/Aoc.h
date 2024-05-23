#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
    //we first want to go over the list 
    std::string num = "";
    for(int i = 0; i < inputs.size(); i++){
        //when we get each string we want to find the first non_alphabetic character
        std::string s = inputs[i];
        int j;
        for(j = 0; j < s.length(); j++){
            if(!isalpha(s[j])){
                num += s[j];
                break;
            }
        }
        for(j = s.length()-1; j >= 0; j--){
            if(!isalpha(s[j])){
                num += s[j];
                break;
            }
        }
        ans += stoi(num);
        num = "";
    }    
    return ans;
}