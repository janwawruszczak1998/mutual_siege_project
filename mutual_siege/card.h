#ifndef CARD_H
#define CARD_H

#include <string>

class Castle;


class Card{
public:
    Card(unsigned, unsigned);

    virtual ~Card() = default;
    virtual bool operator()(Castle&, Castle&) = 0;

    std::string get_icon_name() const;

protected:
    unsigned cost{};
    unsigned strenght{};
    std::string icon_name{};
};

#endif // CARD_H
