#ifndef CASTLE_H
#define CASTLE_H

#include <vector>

#include "card.h"
#include "attackcard.h"
#include "constructcard.h"

class Castle
{
public:
    Castle() = default;

    unsigned get_weapons() const;
    unsigned get_magic() const;
    unsigned get_bricks() const;
    unsigned get_hp() const;

    unsigned get_weapons_inc() const;
    unsigned get_magic_inc() const;
    unsigned get_bricks_inc() const;

    void set_weapons(unsigned value);
    void set_magic(unsigned value);
    void set_bricks(unsigned value);
    void set_hp(unsigned value);

    void update_supplies();

    std::vector<Card*>& get_cards();

private:
    unsigned weapons{20}, magic{10}, bricks{15}, hp{100};
    unsigned weapons_inc{2}, magic_inc{2}, bricks_inc{2};

    std::vector<Card*> cards;
};

#endif // CASTLE_H
