#ifndef CONSTRUCTCARD_H
#define CONSTRUCTCARD_H

#include "card.h"
#include "castle.h"

class ConstructCard : public Card
{
public:
    ConstructCard(unsigned, unsigned);
    bool operator()(Castle&, Castle&) override;
};

#endif // CONSTRUCTCARD_H
