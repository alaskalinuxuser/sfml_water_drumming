#!/bin/bash

# You need libsfml installed on your system!

g++ -I./  -Wall -ansi -Wextra -g -c -std=c++14 DrumGame.cpp -o DrumGame.o
g++ DrumGame.o -o DrumGame-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

./DrumGame-app

echo "type ./DrumGame-app to launch"
exit
