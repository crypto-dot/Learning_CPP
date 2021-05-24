//
// Created by Carlos Arbizu on 4/30/21.
//

#ifndef CPP_ACCOUNTPOLY_H
#define CPP_ACCOUNTPOLY_H

#include <string>
#include "I_Printable.h"
using std::string;

class AccountPoly : public I_Printable {
protected:
    string name;
    double balance;
public:
    AccountPoly(string name,double balance) : name{std::move(name)},balance{balance}{};
    virtual bool withdraw(double amount) = 0;
    virtual bool deposit(double amount) = 0;
    virtual ~AccountPoly() = default;
};


#endif //CPP_ACCOUNTPOLY_H
