.PHONY: clean install uninstall

CC=g++
CXXFLAGS=-lncurses
PREFIX=~

all: src/*.o
	$(CC) $(CXXFLAGS) src/*.cpp -o decks
src/%.o: src/%.cpp
	$(CC) $(CXXFLAGS) -c $^

debug: CXXFLAGS += -g
debug: all

install: decks
	mkdir -p $(DESTDIR)$(PREFIX)/.bin
	cp $< $(DESTDIR)$(PREFIX)/.bin/decks

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/.bin/decks

clean: 
	-rm src/*.o
	-rm src/*.gch
	-rm decks
