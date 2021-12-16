CXX = g++

CXXFLAGS += -std=c++20
CXXFLAGS += -O0 -g
#CXXFLAGS += -O3 -DNDEBUG

#SOURCES = $(wildcard *.cpp)
SOURCES = test.cpp
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all
all: test

test: $(OBJECTS)	
	$(CXX) $(LDFLAGS) -o $@ $^ 

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: run
run: test
	./test --log_level=all --result_code=no

.PHONY: clean
clean:
	rm -f $(OBJECTS) test

