#ifndef ATTACKCARD_H
#define ATTACKCARD_H

#include "card.h"
#include "objectcounter.hpp"

class AttackCard : public Card, ObjectCounter<AttackCard>
{
public:
    AttackCard(unsigned, unsigned);
    ~AttackCard();
    bool operator()(Castle&, Castle&) override;
};

#endif // ATTACKCARD_H
