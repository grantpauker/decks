
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "card.hpp"
#include "deck.hpp"
#include "gui.hpp"

int main(int argc, char **argv)
{
    std::string filename;
    if (argc == 1)
    {
        std::cerr << "No file specified.\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        filename = argv[1];
    }
    Deck deck;
    deck.load(filename);
    int index = 0;
    WINDOW *mainwin;

    setlocale(LC_ALL, "");
    if ((mainwin = initscr()) == NULL)
    {
        std::cerr << "Error initialising ncurses.\n";
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
        case KEY_DOWN:
        case KEY_UP:
        case ' ':
            deck.cards[index].is_flipped = !deck.cards[index].is_flipped;
            break;
        case KEY_LEFT:
        case 'h':
            index -= (index > 0);
            break;
        case KEY_RIGHT:
        case 'l':
            index += (index < deck.cards.size() - 1);
            break;
        case ';':
        case '/':
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
    deck.write(filename);
    return EXIT_SUCCESS;
}
