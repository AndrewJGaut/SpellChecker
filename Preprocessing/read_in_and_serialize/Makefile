CXX = g++

CXXFLAGS = -g -Wall -std=c++11

serializer: serializer.o Word.o
	$(CXX) $(CXXFLAGS) -o $@ $^

serializer.o: serializer.cpp Word.h
	$(CXX) $(CXXFLAGS) -c serializer.cpp

Word.o: Word.h Word.cpp
	$(CXX) $(CXXFLAGS) -c Word.cpp
