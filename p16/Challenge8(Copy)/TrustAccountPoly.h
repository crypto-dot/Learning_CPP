//
// Created by Carlos Arbizu on 5/3/21.
//

#ifndef CPP_TRUSTACCOUNTPOLY_H
#define CPP_TRUSTACCOUNTPOLY_H
#include "SavingsAccountPoly.h"

class TrustAccountPoly : public SavingsAccountPoly {
private:
    int numOfWithdrawals {0};
    static double constexpr maxWithdrawPercentage{.2};
public:
    TrustAccountPoly(string name,double amount,double interestRate);
    TrustAccountPoly(string name,double amount);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(ostream &ostream1) const override;
    virtual ~TrustAccountPoly() = default;
};


#endif //CPP_TRUSTACCOUNTPOLY_H
