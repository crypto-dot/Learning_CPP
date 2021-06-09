//
// Created by Carlos Arbizu on 4/1/21.
//

#ifndef CPP_SAVINGSACCOUNTCHALLENGE_H
#define CPP_SAVINGSACCOUNTCHALLENGE_H
#include "AccountChallenge.h"

class SavingsAccountChallenge : public AccountChallenge {
private:
    static constexpr double def_interestRate{0.05};
protected:
    double interestRate;
public:
    SavingsAccountChallenge(string &&name, double amount,double interestRate);
    SavingsAccountChallenge(const string &name, double amount,double interestRate);
    explicit SavingsAccountChallenge(string &&name);
    explicit SavingsAccountChallenge(const string &name);
    SavingsAccountChallenge();
    bool deposit(double amount);
    friend ostream &operator<<(ostream &ostream1, const SavingsAccountChallenge &SavingsAccountobj);
};


#endif //CPP_SAVINGSACCOUNTCHALLENGE_H
