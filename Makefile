bin/%: src/%.cpp
	g++ -Wall --std=c++20 -o $@ $<