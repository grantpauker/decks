
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "card.hpp"
#include "deck.hpp"
#include "gui.hpp"

void write_deck(std::string filename, Deck deck)
{
    deck.print();
    return;
}

int main(void)
{
    Deck deck;
    deck.load("example");
    int index = 0;
    WINDOW *mainwin;

    setlocale(LC_ALL, "");
    if ((mainwin = initscr()) == NULL)
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }
    clear();
    noecho();
    cbreak();

    keypad(mainwin, TRUE);
    refresh();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);

    bool exit = true;
    int c;
    curs_set(0);
    while (exit)
    {
        int offset = 0;
        if (!deck.cards[index].is_flipped)
        {
            offset = print_nstring_centered(deck.cards[index].term);
        }
        else
        {
            offset = print_nstring_centered(deck.cards[index].definition);
        }
        if (deck.cards[index].starred)
        {
            attron(COLOR_PAIR(1));
            print_string_centered(offset, "●");
            attroff(COLOR_PAIR(1));
        }
        else
        {
            print_string_centered(offset, "○");
        }
        std::ostringstream index_str;
        index_str << "(" << index << ")";
        print_string_centered(-1, index_str.str());
        c = getch();
        switch (c)
        {
        case 'j':
        case 'k':
            deck.cards[index].is_flipped = !deck.cards[index].is_flipped;
            break;
        case 'h':
            index -= (index > 0);
            break;
        case 'l':
            index += (index < deck.cards.size() - 1);
            break;
        case ';':
            deck.cards[index].starred = !deck.cards[index].starred;
            break;
        case 'q':
            exit = false;
            break;
        }
        erase();
        refresh();
    }
    delwin(mainwin);
    endwin();
    refresh();
    deck.write("out");
    return EXIT_SUCCESS;
}