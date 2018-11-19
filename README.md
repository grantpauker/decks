# decks
An ncurses flash card tui

# creating flashcards
Create flashcard files (with the `.dk` extension) according to the following format (see the example.dk file for an example):
```
[*]term1
    definition1
    definition2
[*]term2
    definition1
...
```
Terms should contain no leading whitespace and definitions should be located directly beneath their term, beginning with a tab character. An astericks at the beginning of the term line indicates that that term is starred.

# (un)installing
To install, run:
```
make install
```
To uninstall, run:
```
make uninstall
```

# usage
To load a deck, run:
```
decks [filename]
```
Use the up/down arrows (j/k) (space) to flip the current card. Use the left/right arrows (h/l) to move to the previous or next card. Use / (;) to star a card.
