#include "card.hpp"
Card::Card(std::string term, std::string definition, bool starred, bool is_flipped) : term(term), definition(definition), starred(starred), is_flipped(is_flipped) {}
Card::Card() {}
void Card::print()
{
    std::cout << term << " - " << definition << std::endl;
}
