//
// Created by Carlos Arbizu on 1/16/21.
//

//C++ has very specific rules about const classes
//When declaring a const class ( a class that is not modifiable aka read only)
//C++ only allows methods with the keyword const to be called using the class
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Player {
private:
    //c++ allows us to use static keywords to create variables shared within the class rather than within each object
    static int count;
    string name;
    int health;
    int xp;

public:

    //constructors
    Player(string name,int xp,int health) : name{move(name)},xp{xp},health{health}{
        ++count;
    };
    Player(string name) : Player(move(name),0,0){

    };
    Player(string name,int xp) : Player(move(name),xp,0) {

    };
    //destructor since we are keeping count of how many player objects we need to decrement count everytime
    //it is called
    ~Player();
    static int getCount();

    void talk(string str){
        cout << name << " says " <<str << endl;
    };

    bool isdead(){
        if(health == 0 ){
            return true;
        }
        return false;
    }
    //l - values only (references only)
    void displayName(const Player &p){
        cout << p.getName() <<endl;
    }
    //here both the methods getname and get xp are const, logically this makes sense
    //since these are getter methods and they do not need to have any code that modifies
    //anything
    string getName() const;
    int getXp() const;

};

string Player::getName() const {return name;}
int Player::getXp() const {return xp;}

//here we would use a Player.cpp for the implementation of the methods and the static variable and Player.h
//for the specification of our classes
//No need to add static here since the class has the static keyword in the method prototype
int Player::getCount() {return count;}
Player::~Player() {count--;}

int main()
{
    Player hero("hero",100,100);
    hero.displayName(hero);
    return 0;
}