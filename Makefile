CXX = g++
CXXFLAGS = -Wall -g -std=c++11


BINARIES = main test

all: $(BINARIES)

test: test.o utility.o Word.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main: main.o utility.o Word.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: utility.h Word.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

utility.o: utility.h utility.cpp
	$(CXX) $(CXXFLAGS) -c utility.cpp

Word.o: Word.cpp Word.h
	$(CXX) $(CXXFLAGS) -c Word.cpp

clean:
	/bin/rm -f *.o $(BINARIES) 
