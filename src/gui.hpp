#ifndef H_GUI
#define H_GUI
#include <sstream>
#include <string>
#include <ncurses.h>
class Gui
{
  public:
    Gui();
    void init();
    void close();
    void update();
    int get_center_x();
    int get_center_y();
    void print_string_centered(int offset, std::string str);
    int print_nstring_centered(std::string str);
    WINDOW *mainwin;
    bool is_done;

  private:
    std::size_t strlen_utf8(std::string str);
};
#endif