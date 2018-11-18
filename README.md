# decks
An ncurses flash card tui

# creating flashcards
Create flashcard files (with the `.dk` extension) according to the following format (see the example.dk file for an example):
```
[*]TERM1
    DEFINITION1
    DEFINITION2
[*]TERM2
    DEFINITION1
...
```
Terms should contain no leading whitespace and definitions should be located directly beneath their term, beginning with a tab character. An astericks at the beginning of the term line indicates that that term is starred.

# usage
To load a deck, run:
```
./decks [filename]
```
Use the up/down arrows (j/k) to flip the current card. Use the left/right arrows (h/l) to move to the previous or next card. Use the / (;) to star a card.
