.PHONY: clean
CC=g++
CXXFLAGS=-lncurses

all: src/*.o
	$(CC) $(CXXFLAGS) src/*.cpp -o decks
src/%.o: src/%.cpp
	$(CC) $(CXXFLAGS) -c $^

debug: CXXFLAGS += -g
debug: all

clean: 
	-rm src/*.o
	-rm src/*.gch
	-rm a.out 
