//
// Created by Carlos Arbizu on 1/21/21.
//
//Static class members are shared for all members of the class
#ifndef CPP_PLAYER_H
#define CPP_PLAYER_H
class Player{
private:
    static int amount_of_player;
    int health;
    int xp;
public:
    Player(int health=0,int xp = 0);
    int getHealth() const;
    int getXp() const;
    static int returnPlayerAmount();
    ~Player();
};
#endif //CPP_PLAYER_H
