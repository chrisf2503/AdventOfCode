# Introduction
Here I will be posting my solution of advent of code follow by some test cases in order to check for basic case.

I will be using basic doc testing and will be coming each one day at a time

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

# Cube Conundrum (Day 2 part 2)

Now using the same inputs, we want to be able to get the max value for each color cube, then we want to multiply all the max int an them sum everything up

例：

Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green -> red: 4, blue: 6, green: 2 are the max

Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue -> red: 1, blue: 4, green: 3 are the max

Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red -> red: 20, blue: 6, green: 8 are the max

Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red -> red: 14, blue: 15, green: 3 are the max

Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green -> red: 6, blue: 2, green: 3 are the max

Now is we multiply we would get 

Game 1: 48

Game 2: 12

Game 3: 1560

Game 4: 630

Game 5: 36

Now is we sum all the game then we would get 69110

# Day 3: Gear Ratios

You given a list of string that contains the following:
例：

                         0  1  2  3  4  5  6  7  8  9

0   467..114..          [4][6][7][.][.][1][1][4][.][.]

1   ...*......          [.][.][.][*][.][.][.][.][.][.]

2   ..35..633.          [.][.][3][5][.][.][6][3][3][.]

3   ......#...          [.][.][.][.][.][.][#][.][.][.]

4   617*......          [6][1][7][*][.][.][.][.][.][.]

5   .....+.58.          [.][.][.][.][.][+][.][5][8][.]

6   ..592.....          [.][.][5][9][2][.][.][.][.][.]

7   ......755.          [.][.][.][.][.][.][7][5][5][.]

8   ...$.*....          [.][.][.][$][.][*][.][.][.][.]

9   .664.598..          [.][6][6][4][.][5][9][8][.][.]

(This could be seen as a 2d maxtrix)

We want to be able to sum up all the number when

1. any number abjacent to a symbol 

2. even diagonally to a symbol

This rule apply only when its a symbol is not a period

説明：

On line 0, number 467 is diagonally across from the '*' because the number 7 is a row and col more then the *, therefore we can sum it up

How ever number 114 is not near any symbol, that is not a symbol, therefore we can not sum it up

Samething could be said with number 58 (line 5) where its 1 col off from the '+' symbol 

Now if were to sum up all number that are abjacent an even diagonally to a symbol that is not a '.', then we would get 4361

Therefore we want check if a number (any number), is diagonally/horizontally/vertically next to a symbol that is not a '.'
