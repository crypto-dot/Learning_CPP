//
// Created by Carlos Arbizu on 3/29/21.
//

#ifndef CPP_ACCOUNTUPDATED_H
#define CPP_ACCOUNTUPDATED_H

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
class AccountUpdated {
protected:
    double_t balance;
public:
    void Deposit(double_t amount);
    AccountUpdated();
    explicit AccountUpdated(double_t amount);
    void WithDraw(double_t amount);
    friend ostream &operator<<(ostream &ostream,const AccountUpdated &accountUpdatedOBJ);
};
#endif //CPP_ACCOUNTUPDATED_H
