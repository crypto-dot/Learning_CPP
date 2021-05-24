//
// Created by Carlos Arbizu on 12/30/20.
//
//If the symbol _ACCOUNT_H has been defined (by the preprocessor) then the symbol does not need to be
// defined again and the program can run as usual
#ifndef CPP_ACCOUNT_H
#define CPP_ACCOUNT_H
#include <string>


class Account{
private:
    double balance;
    std::string name;

public:
    //Methods declared out of class
    void set_balance(double balance);
    double get_balance();
    //Methods declared inline
    //Not recommended best practice is to define functions and classes in the .h file
    //and to declare them in a separate .cpp file
    void set_name(std::string name){
        this->name = name;
    }
    std::string get_name(){
        return name;
    }

};
#endif //CPP_ACCOUNT_H
