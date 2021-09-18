#include "constructcard.h"
#include <iostream>

ConstructCard::ConstructCard(unsigned cost_, unsigned strenght_) : Card(cost_, strenght_)
{
    icon_name = "worker.png";
    std::cout << "Construct card constructed" << std::endl;
}

bool ConstructCard::operator()(Castle& player, Castle& enemy) {
    int diff = static_cast<int>(player.get_bricks()) - cost;
    if(diff >= 0){
        player.set_bricks(diff);
        player.set_hp(player.get_hp() + strenght);
        std::cout << "your hp is " << player.get_hp() << std::endl;
        return true;
    }
    else{
        return false;
    }
}

