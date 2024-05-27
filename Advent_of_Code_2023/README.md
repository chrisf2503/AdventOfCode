# Introduction
Here I will be posting my solution of advent of code follow by some test cases in order to check for basic case.
Here I will be using basic doc testing and will be coming each one day at a time
I will also post my explaination an my thought process an try to commonent what each line of code does an reason behind it. 
In order to run doctest do the following command 
1. make doctest
2. ./doctest
In order to get the answer of the inputs that were provided for me, you want to do the following
1. make main
2. ./main

# Trebuchet (Day 1)
We are given a list of string that contains alpthabetical characters or number 0-9. We want to be able to get the first number in the string and the last number within the string. We want to do the same thing for the rest of the string an be able to sum up the 2 digit integer
例(Example)："324filr02fsrlin23fgrs9", "getThisnumber2", "424234324532", "filnf3fnlrnflin49fslinfrs0"
説明(Explaination):
"324filr02fsrlin23fgrs9" -> 39 since 3 is the first number an 9 is the last
"getThisnumber2" -> 2 since 2 is the first number an also the last number
"424234324532" -> 42, 4 is the first, 2 is the last
"filnf3fnlrnflin49fslinfrs0" -> 30, 3 is the first, 0 is the last
Therefore we try to sum everything up we will get 133

# Cube Conundrum (Day 2)
You are given a list of string where each is formatted by the following:
Game #: {set 1}; ...; {set N} 
Each game you play you will choose a cube with some color an some number within a bag
Let the game number be the ID an for each set can have a # follow by a color that can be blue, green, or red
Therefore it can look like the following formate:
例：
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green

We want to find out out of the 5 games, if it's possible if the bag contained only 12 red cubes, 13 green cubes, and 14 blue cubes?
For those that are possible, we want to sum up the ID an return the results

説明：
Game 3 would not be possilbe since within the first set, we 20 reds at once
Game 4 would not be possible since within the third set we get 15 blue at once

We are left with Games 1,2,5, Therefore if we sum the ID up, we will get 8

We first want to go through each set an get the color then the number that is assicated with it

Then we want to be able to check if it does surpass the number the color was assigned to

If it does then we can say this game isnt valid an move on to the next game, but if its valid when we can sum up the Id numbers