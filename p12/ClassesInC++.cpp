//
// Created by Carlos Arbizu on 12/28/20.
//

//Adding a class to this file means that only this file can access the class
//There are better ways of allowing multiple files of using a class instead of just
// having one class for one file
#include <iostream>
#include <vector>
#include <string>

#include "Account.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;


class Player {
public: //important allows other methods from the same file to access items in here
    //attributes
    string name;
    int health;
    int xp;

    //methods

    void talk(string str){
        cout << name << " says " <<str << endl;
    };

    bool isdead(){
        if(health == 0 ){
            return true;
        }
        return false;
    }
    string getName() {
        return name;
    }
      int getXp() const{
        return xp;
    };
}; // Semicolon is important here
int main(){
    Player frank;
    Player john;
    john.name = "john";
    john.health = 100;
    john.xp = 2;

    if(john.isdead()){
        cout << "John died." << endl;
    }
    else {
        cout << "John is alive and well." << endl;
    }
    john.talk("What?");
    auto *enemy = new Player();
    //we can use a pointer to access the methods in the class
    enemy -> name = "Enemy";
    enemy -> health = 100;
    enemy -> xp = 2;
    enemy -> talk("Hello");
    
    delete enemy;
    //remember to delete objects on the heap

    // Using a separate header file for class specification and another cpp file for the implementation
    // of some of the methods
    AccountPoly Annie;
    AccountPoly John;
    AccountPoly Matt;
    AccountPoly Johnny;

    Annie.set_balance(100);
    Annie.set_name("Annie");
    John.set_balance(500);
    John.set_name("John");
    Matt.set_balance(230);
    Matt.set_name("Matt");
    Johnny.set_balance(550);
    Johnny.set_name("Johnny");
    vector<AccountPoly> listAccounts{Annie, John, Matt, Johnny};
    for(auto acc : listAccounts){
        cout << acc.get_name() << ": $" << acc.get_balance() << endl;
    }



    return 0;
}