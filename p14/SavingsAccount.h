//
// Created by Carlos Arbizu on 3/29/21.
//

#ifndef CPP_SAVINGSACCOUNT_H
#define CPP_SAVINGSACCOUNT_H
#include "AccountUpdated.h"
#include <iostream>
using std::ostream;
class SavingsAccount : public AccountUpdated {
private:
    double_t interestRate;
public:
    SavingsAccount();
    explicit SavingsAccount(double_t amount);
    SavingsAccount(double_t amount,double_t interestRate);
    void deposit(double_t amount);
    friend ostream &operator<<(ostream &ostream,const SavingsAccount &savingsAccountOBJ);
};


#endif //CPP_SAVINGSACCOUNT_H
