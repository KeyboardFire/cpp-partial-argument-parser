KingOfTheCode: src/*.cpp
	clang++ -std=c++11 src/*.cpp -pthread -o KingOfTheCode

KingOfTheCodeGPP: src/*.cpp
	g++ -std=c++11 src/*.cpp -pthread -o KingOfTheCode
