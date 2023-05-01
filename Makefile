CXX=g++
CXXFLAGS=-std=c++11 -Wall

all: myprogram

myprogram: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o myprogram

clean:
	rm -f myprogram