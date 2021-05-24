//
// Created by Carlos Arbizu on 5/1/21.
//

#ifndef CPP_SAVINGSACCOUNTPOLY_H
#define CPP_SAVINGSACCOUNTPOLY_H

#include "AccountPoly.h"
#include "I_Printable.h"
class SavingsAccountPoly : public AccountPoly {
protected:
    double interestRate;
    static constexpr double def_interestRate = 0.05;
public:
    SavingsAccountPoly(string name,double balance,double interestRate);
    SavingsAccountPoly(string name,double balance);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual ~SavingsAccountPoly() = default;
    virtual void print(ostream &ostream1) const override;

};


#endif //CPP_SAVINGSACCOUNTPOLY_H
