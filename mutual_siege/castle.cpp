#include "castle.h"

unsigned Castle::get_weapons() const {
    return weapons;
}
unsigned Castle::get_magic() const {
    return magic;
}
unsigned Castle::get_bricks() const {
    return bricks;
}
unsigned Castle::get_hp() const {
    return hp;
}

unsigned Castle::get_weapons_inc() const {
    return weapons_inc;
}
unsigned Castle::get_magic_inc() const {
    return magic_inc;
}
unsigned Castle::get_bricks_inc() const {
    return bricks_inc;
}


void Castle::set_weapons(unsigned value){
    weapons = value;
}
void Castle::set_magic(unsigned value){
    magic = value;
}
void Castle::set_bricks(unsigned value){
    bricks = value;
}

void Castle::set_hp(unsigned value){
    hp = value;
}
std::vector<Card*>& Castle::get_cards(){
    return cards;
}
void Castle::update_supplies(){
    weapons += weapons_inc;
    magic += magic_inc;
    bricks += bricks_inc;
}
