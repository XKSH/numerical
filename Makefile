CC=g++
FLAGS=-Wall -Werror -std=c++14 -pedantic
BUILD=./build
BIN=./bin
SRC=./src
TEST=./test
vpath %.cpp src:
vpath %.cpp test:

#default: roots

roots.o: roots.cpp 
	$(CC) -o $(BUILD)/roots.o -c $(SRC)/roots.cpp $(FLAGS)

#roots: roots.o
#	$(CC) $(BUILD)/roots.o -o $(BIN)/roots

test: testcases.cpp roots.o
	$(CC) -o $(TEST)/test $(TEST)/testcases.cpp $(BUILD)/roots.o $(FLAGS)
	./test/test



.PHONY: clean

clean:
	rm -f $(BUILD)/*
	rm -f $(BIN)/*
