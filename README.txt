Sarah Caruthers
2350081
caruthers@chapman.edu
CPSC 350-03
Course Project

FileReader.h
FileReader.cpp
Converter.h
Converter.cpp
FileWriter.h
FileWriter.cpp
main.cpp

All sources used are directly commented in each class.
Nick helped me with function calling in main. I used a function found online from Geeks for Geeks to find the power set.
I used the c++ standard library to import a HashMap and utilize it's functions. Other one-line help gotten from
Stackoverflow and Geeks for Geeks commented in-line.

Some bugs: Could not parse out the newline at the end of the file, so delta has an extra line with empty brackets
for both the current state and next state. I also could not figure out how to take care of any null sets of states,
and my map for some reason does not read in the last line of transition function, thus I am missing a key-value pair
and some transiton functions are thus incomplete. 
