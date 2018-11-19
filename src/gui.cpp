#include <iostream>
#include <ncurses.h>
#include <assert.h>
#include "gui.hpp"
Gui::Gui()
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
std::size_t Gui::strlen_utf8(std::string str)
{
    std::size_t len = 0;
    for (char c : str)
    {
        if ((c & 0xC0) != 0x80)
        {
            ++len;
        }
    }
    return len;
}
void Gui::print_string_centered(int offset, std::string str)
{
    mvprintw(get_center_y() + offset, get_center_x() - (strlen_utf8(str) / 2), str.c_str());
}
int Gui::print_nstring_centered(std::string str)
{
    std::stringstream ss(str);
    std::string buf;
    int offset = 0;
    while (std::getline(ss, buf, '\n'))
    {
        print_string_centered(offset, buf);
        offset++;
    }
    return offset;
}
