//
// Created by Carlos Arbizu on 1/21/21.
//

#include "Player.h"
int Player::amount_of_player{0};
//here amount of player must be intiatilzed in the .cpp file (if u try to initialize in the .h file u will get a
// compile error).

int Player::getXp() const {
    return xp;
}
int Player::getHealth() const {
    return health;
}
Player::Player(int health,int xp) : health{health},xp{xp}{
    amount_of_player++;
}
Player::~Player(){
    amount_of_player--;
}
int Player::returnPlayerAmount() {
    return amount_of_player;
}