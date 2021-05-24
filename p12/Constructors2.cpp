//
// Created by Carlos Arbizu on 1/4/21.
//
#include <string>
#include <iostream>
#include <utility>
using std::cout;
using std::endl;
using std::string;
class Player{
private:
    int health;
    int xp;
    string name;
public:
    string get_name(){

        return name;
    }
    int get_xp(){
        return xp;
    }
    int get_health(){

        return health;
    }
    Player(string name = "None",int xp = 0,int health = 0);
    Player(const Player &source);
    ~Player(){
        cout << "Destructor called " << endl;
    }

};
// Player::Player(stringptr name, int xp, int health) : name{move(name)},xp{xp},health{health} {}
// Player::Player() : Player{"None",0,0} {}
// Player::Player(stringptr name) : Player{name,0,0}
// instead of doing these 3 lines of code (3 separate constructors) we can save time and make our code more readable
// by simplifying this to a single default constructor BE CAREFUL not to create ambiguous constructors
Player::Player(string name, int xp, int health) : name{std::move((name))},xp{xp},health{health} {}
//Objects can be copied in C++ when an object is copied a new object is created from a previous object

//When is a copy of an object made?
//* passing an object by value as a parameter
//* return an object by value from a function
//* constructing one object from another of the same class

// If we do not provide a copy constructor the c++ compiler will automatically provide one
// Copy constructor will copy the values of all the data member of the class (default memberwise copy)
// BEWARE if you are using raw pointers then only the pointer WILL be copied not the data it is pointing to
// THIS IS REFERRED TO AS A SHALLOW COPY RATHER THAN A DEEP COPY

// ***********BEST PRACTICE*******************
// Provide a user defined copy constructor if you are using raw pointers
// Provide the copy constructor with a const reference parameter
// Use STL classes as they already provide copy constructors
// Avoid using raw pointers as data members or use smart pointers (some are outdated past c++17)
// ******************************************
// Below is an example of how we can create the copy constructor, however we can improve the code
// by delegating the copy constructor to our 3 arg player constructor
// Player::Player(const Player &source) : xp{source.xp},health{source.health},name{source.name} {}
// As such:
Player::Player(const Player &source) : Player(source.name,source.xp,source.health) {}

Player create_super_enemy(){
    Player enemy("Enemy-Super",1000,10000);

    return enemy; // here a copy of enemy is made and then returned and the player enemy inside the scope
    // is destroyed by the destructor
}
Player another_hero(Player hero){
    return hero; // here a copy is made of the input then returned (the copy is destoryed afterwards)
    //this is why it is better to pass by reference rather than value because it is more efficient.
    // Copying an object on the stack then returning the object then destroying on the stack it can
    // just be accomplished by taking the original object passed by reference copying
    // all its content then returns it
}
void displayPlayer(Player player){
    cout << player.get_name() << endl;
    cout << player.get_health() << endl;
    cout << player.get_xp() << endl;

    // copy of player is made
    // (some code to display the attributes of player)
    // destructor of player is called
}


int main (){
    Player Frank("Frank",25,1000);
    Player heroCopy = another_hero(Frank);
    cout << heroCopy.get_name() << endl;


    return 0;
};