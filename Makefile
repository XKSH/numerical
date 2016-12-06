CC=g++
FLAGS=-Wall -Werror -std=c++14 -pedantic
BUILD=./build
BIN=./bin

.PHONY: clean

clean:
	rm -f $(BUILD)/*
	rm -f $(BIN)/*
