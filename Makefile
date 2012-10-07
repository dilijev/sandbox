CXX=g++
CXXFLAGS=-pedantic -std=c++0x -Wall -O2
DEBUGFLAGS=-pedantic -std=c++0x -Wall -O0 -g

EXE=sandbox

all: const
	

const: const/const.cpp
	$(CXX) $(DEBUGFLAGS) const/const.cpp -o $(EXE)

clean:
	rm -rf *.o $(EXE)

