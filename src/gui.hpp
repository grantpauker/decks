#ifndef H_GUI
#define H_GUI
#include <sstream>
#include <string>
#include <vector>
#include <ncurses.h>
class Gui
{
public:
  Gui(int max_len = 80);
  void init();
  void close();
  void update();
  int get_center_x();
  int get_center_y();
  int print_centered(int offset, std::string str);
  int print_centered(int offset, std::vector<std::string> str);

  int print_wrapped(int offset, std::string str);

  WINDOW *mainwin;
  bool is_done;
  int max_len;
};
#endif