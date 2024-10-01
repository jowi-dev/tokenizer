test: 
	g++ -std=c++17 test.cpp $(pkg-config --cflags --libs catch2-with-main) -o test_executable 
