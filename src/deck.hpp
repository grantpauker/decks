#ifndef H_DECK
#define H_DECK
#include <vector>
#include <string>
#include "card.hpp"
class Deck
{
  public:
    std::string name;
    std::vector<Card> cards;
    Deck(std::string name, std::vector<Card> cards);
    Deck(std::string name);
    Deck();
    void add_card(Card card);
    void print();
    void load(std::string filename);
    void write(std::string filename);
};
enum class TokenKind
{
    TERM,
    DEFINITION,
};
#endif