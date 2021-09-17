#include "card.h"
#include <iostream>
#include <string>

Card::Card(unsigned cost_, unsigned strenght_)
    : cost(cost_), strenght(strenght_)
{
    std::cout << "Card constructed" << std::endl;
}

std::string Card::get_icon_name() const {
    return icon_name;
}
