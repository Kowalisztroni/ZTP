#!/bin/bash


#kompilacja bilbioteki hello stworzenie pliku obiektowego
g++ -c lib/hello/hello.cpp -o lib/hello/hello.o

# kompilacja prog1 i prog2
g++ -c src/prog1/main.cpp -o src/prog1/main.o
g++ -c src/prog2/main.cpp -o src/prog2/main.o

#linkowanie i tworzenie pliku wykonywalnego

g++ -o prog1.exe src/prog1/main.o lib/hello/hello.o
g++ -o prog2.exe src/prog2/main.o lib/hello/hello.o


