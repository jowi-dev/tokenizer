#!/bin/sh

#g++ -std=c++20 test/test.cpp $(pkg-config --cflags --libs catch2-with-main) -o build/test_executable
g++ -std=c++20 -g -O0 -Wall -Wextra test/test.cpp $(pkg-config --cflags --libs catch2-with-main) -o build/test_executable

./build/test_executable
