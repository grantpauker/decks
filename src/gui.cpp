#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <assert.h>
#include <ncurses.h>
#include "gui.hpp"
#include "utils.hpp"

Gui::Gui(int max_len) : max_len(max_len)
{
    is_done = false;
}
void Gui::init()
{
    setlocale(LC_ALL, "");
    mainwin = initscr();
    assert(mainwin != NULL);

    clear();
    noecho();
    cbreak();

    keypad(mainwin, TRUE);
    // refresh();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    curs_set(0);
}
void Gui::close()
{
    delwin(mainwin);
    endwin();
}
void Gui::update()
{
    erase();
    refresh();
}
int Gui::get_center_x()
{
    return COLS / 2;
}
int Gui::get_center_y()
{
    return LINES / 2;
}

int Gui::print_centered(int offset, std::vector<std::string> strings)
{
    for (auto str : strings)
    {
        offset = print_centered(offset, str);
    }
    return offset;
}
int Gui::print_centered(int offset, std::string str)
{
    if (str.find('\n') != std::string::npos)
    {
        std::vector<std::string> strings = split_string(str, '\n');
        offset = print_centered(offset, strings);
        return offset;
    }
    else
    {
        offset = print_wrapped(offset, str);
        return offset;
    }
}

int Gui::print_wrapped(int offset, std::string str)
{
    std::stringstream ss(str);
    std::string buf;
    std::string word;
    while (std::getline(ss, word, ' '))
    {
        if (buf.length() + word.length() > max_len)
        {
            mvaddstr(get_center_y() + offset, get_center_x() - (strlen_utf8(buf) / 2), buf.c_str());
            buf = word;
            offset++;
        }
        else
        {
            buf += " " + word;
        }
    }
    mvaddstr(get_center_y() + offset, get_center_x() - (strlen_utf8(buf) / 2), buf.c_str());

    return offset + 1;
}
