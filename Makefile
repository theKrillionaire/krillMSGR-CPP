build/messenger: main.cpp configHandler.cpp
	g++ main.cpp configHandler.cpp -o build/messenger --std=c++23
