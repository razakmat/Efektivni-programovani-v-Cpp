CXX = g++

CXXFLAGS += -std=c++11
CXXFLAGS += -O0 -g
#CXXFLAGS += -O3 -DNDEBUG

.PHONY: all
all: test_case1_enabled test_case2_enabled test_case3_enabled \
	test_case1_disabled test_case2_disabled test_case3_disabled \

test_case1_enabled: test.cpp X.h
	$(CXX) -DCASE1 $(CXXFLAGS) $(LDFLAGS) -o $@ $< 

test_case2_enabled: test.cpp X.h
	$(CXX) -DCASE2 $(CXXFLAGS) $(LDFLAGS) -o $@ $< 

test_case3_enabled: test.cpp X.h
	$(CXX) -DCASE3 $(CXXFLAGS) $(LDFLAGS) -o $@ $< 

test_case1_disabled: test.cpp X.h
	$(CXX) -DCASE1 $(CXXFLAGS) -fno-elide-constructors $(LDFLAGS) -o $@ $< 

test_case2_disabled: test.cpp X.h
	$(CXX) -DCASE2 $(CXXFLAGS) -fno-elide-constructors $(LDFLAGS) -o $@ $< 

test_case3_disabled: test.cpp X.h
	$(CXX) -DCASE3 $(CXXFLAGS) -fno-elide-constructors $(LDFLAGS) -o $@ $< 

.PHONY: run
run: all
	./test_case1_enabled
	./test_case2_enabled
	./test_case3_enabled
	./test_case1_disabled
	./test_case2_disabled
	./test_case3_disabled

.PHONY: clean
clean:
	rm -f test_case1_enabled test_case2_enabled test_case3_enabled test_case1_disabled test_case2_disabled test_case3_disabled
