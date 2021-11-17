CXX = g++

CXXFLAGS += -std=c++14
CXXFLAGS += -O0 -g
#CXXFLAGS += -O3 -DNDEBUG

.PHONY: all
all: test_case1 test_case2 test_case3

test_case1: test.cpp X.h
	$(CXX) -DCASE1 $(CXXFLAGS) $(LDFLAGS) -o $@ $^ 

test_case2: test.cpp X.h
	$(CXX) -DCASE1 $(CXXFLAGS) $(LDFLAGS) -o $@ $^ 

test_case3: test.cpp X.h
	$(CXX) -DCASE1 $(CXXFLAGS) $(LDFLAGS) -o $@ $^ 


.PHONY: run
run: all
	./test_case1
	./test_case2
	./test_case3

.PHONY: clean
clean:
	rm -f test_case1 test_case2 test_case3
