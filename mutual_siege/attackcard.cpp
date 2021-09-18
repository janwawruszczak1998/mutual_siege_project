#include "attackcard.h"
#include "card.h"
#include "objectcounter.hpp"
#include "castle.h"

#include <iostream>
#include <math.h>




AttackCard::AttackCard(unsigned cost_, unsigned strenght_) : Card(cost_, strenght_), ObjectCounter<AttackCard>()
{
    icon_name = "sword.png";
    std::cout << "Attack card constructed" << std::endl;
}


bool AttackCard::operator()(Castle& player, Castle& enemy) {
    int diff = static_cast<int>(player.get_weapons()) - cost;
    if(diff >= 0){
        player.set_weapons(diff);
        int hp_diff = static_cast<int>(enemy.get_hp()) - strenght;
        enemy.set_hp(std::max(0, hp_diff));
        std::cout << "enemy hp is " << enemy.get_hp() << std::endl;
        return true;
    }
    else{
        return false;
    }
}

AttackCard::~AttackCard(){

}

