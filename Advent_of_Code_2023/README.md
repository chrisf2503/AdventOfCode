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
# Trebuchet
We are given a list of string that contains alpthabetical characters or number 0-9. We want to be able to get the first number in the string and the last number within the string. We want to do the same thing for the rest of the string an be able to sum up the 2 digit integer
例(Example)："324filr02fsrlin23fgrs9", "getThisnumber2", "424234324532", "filnf3fnlrnflin49fslinfrs0"
"324filr02fsrlin23fgrs9" -> 39 since 3 is the first number an 9 is the last
"getThisnumber2" -> 2 since 2 is the first number an also the last number
"424234324532" -> 42, 4 is the first, 2 is the last
"filnf3fnlrnflin49fslinfrs0" -> 30, 3 is the first, 0 is the last
Therefore we try to sum everything up we will get 133