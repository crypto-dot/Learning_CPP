//
// Created by Carlos Arbizu on 1/21/21.
//

#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

void displayPlayers(){
    cout << "The number of current players " << Player::returnPlayerAmount() << endl;
}
int main(){
    const Player player(100);
    Player player1(100,200);
    {
        Player player2(300, 300);
        displayPlayers();
    }
    displayPlayers();

    return 0;
}