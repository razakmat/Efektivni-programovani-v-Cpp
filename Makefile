CXX = g++

CXXFLAGS += -std=c++14
CXXFLAGS += -O0 -g
#CXXFLAGS += -O3 -DNDEBUG

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all
all: test

test: $(OBJECTS)	
	$(CXX) $(LDFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
