CXX = g++
CXXFLAGS = -Wall -g -std=c++11


main: main.o utility.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: utility.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

utility.o: utility.h utility.cpp
	$(CXX) $(CXXFLAGS) -c utility.cpp
