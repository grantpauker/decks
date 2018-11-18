#ifndef H_GUI
#define H_GUI
#include <ncurses.h>
#include <sstream>
#include <string>

#define CENTER_X (COLS / 2)
#define CENTER_Y (LINES / 2)

std::size_t strlen_utf8(std::string str)
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

void print_string_centered(int offset, std::string str)
{
    mvprintw(CENTER_Y + offset, CENTER_X - (strlen_utf8(str) / 2), str.c_str());
}
int print_nstring_centered(std::string str)
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
#endif