#!/bin/sh

g++ -std=c++20 test.cpp $(pkg-config --cflags --libs catch2-with-main) -o test_executable

./test_executable
