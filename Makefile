CC=g++
FLAGS=-Wall -Werror -std=c++14 -pedantic
BUILD=./build
BIN=./bin
BUILD=./build
BIN=./bin
SRC=./src
vpath %.cpp src:

default: roots

roots.o: roots.cpp
	$(CC) -o $(BUILD)/roots.o -c $(SRC)/roots.cpp 

roots: roots.o
	$(CC) $(BUILD)/roots.o -o $(BIN)/roots


.PHONY: clean

clean:
	rm -f $(BUILD)/*
	rm -f $(BIN)/*
