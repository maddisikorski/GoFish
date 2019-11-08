In this program, the main goal is to learn how to use the basics of C++. The program teaches about Object Oriented
Programming. It helps show how each class links, depending on private and public variables and functions.
To begin, you must unzip the files. Inside this zipped folder, you will find a
-player.cpp
-deck.cpp
-card.cpp
-go_fish.cpp
-readme.txt
-makefile

player.cpp, deck.cpp, and card.cpp also have header files.

Compile the file to ensure they are all linked.
g++ -o GoFish player.cpp deck.cpp card.cpp go_fish.cpp

Compiling can also be done by typing in the command line after being in the program directory: make

Then, run the code. In order to run the code, you must type in the command line: ./GoFish

linux prompt> ./GoFish

The code will show the game of Go Fish going. In the output file, each round of the loop will print out each player's
hand and the books of that player. At the end, the screen will output who the winner is and the final books of each
player.i