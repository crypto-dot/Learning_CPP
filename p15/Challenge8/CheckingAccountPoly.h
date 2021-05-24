//
// Created by Carlos Arbizu on 5/4/21.
//

#ifndef CPP_CHECKINGACCOUNTPOLY_H
#define CPP_CHECKINGACCOUNTPOLY_H
#include "AccountPoly.h"

class CheckingAccountPoly : public AccountPoly {
private:
    static double constexpr fee {1.50};
public:
    CheckingAccountPoly(string name,double amount);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &ostream1) const override;
    virtual ~CheckingAccountPoly() = default;
};


#endif //CPP_CHECKINGACCOUNTPOLY_H
