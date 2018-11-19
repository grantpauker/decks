#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ncurses.h>
#include "card.hpp"
#include "deck.hpp"
#include "gui.hpp"

int main(int argc, char **argv)
{
    //Handle file input
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

    //Load deck from file
    Deck deck;
    deck.load(filename);

    //Initialize gui
    Gui gui;
    gui.init();

    //Set variables
    int key;
    int index = 0;
    int offset = 0;

    //Main loop
    while (!gui.is_done)
    {
        //Display card and other info
        if (!deck.cards[index].is_flipped)
        {
            offset = gui.print_nstring_centered(deck.cards[index].term);
        }
        else
        {
            offset = gui.print_nstring_centered(deck.cards[index].definition);
        }
        if (deck.cards[index].starred)
        {
            attron(COLOR_PAIR(1));
            gui.print_string_centered(offset, "●");
            attroff(COLOR_PAIR(1));
        }
        else
        {
            gui.print_string_centered(offset, "○");
        }

        std::string index_str = "(" + std::to_string(index) + ")";
        gui.print_string_centered(-1, index_str);
        gui.print_string_centered(-3, deck.name);

        //Handle keypresses
        key = getch();
        switch (key)
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
            gui.is_done = true;
            break;
        }

        //Update gui
        gui.update();
    }

    //Close gui and save deck
    gui.close();
    deck.write(filename);
    return EXIT_SUCCESS;
}
