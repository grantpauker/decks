#ifndef H_CARD
#define H_CARD
#include <string>
#include <iostream>
class Card
{
public:
  std::string term;
  std::string definition;
  bool starred;
  bool is_flipped;
  Card(std::string term, std::string definition, bool starred, bool is_flipped);
  Card();
  void print();
};
#endif