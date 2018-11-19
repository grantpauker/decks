#ifndef H_UTILS
#define H_UTILS
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

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
std::vector<std::string> split_string(std::string str, char delim)
{
    std::vector<std::string> strings;
    std::stringstream ss(str);
    std::string line;
    while (std::getline(ss, line, delim))
    {
        strings.push_back(line);
    }
    return strings;
}
#endif