//
// Created by Carlos Arbizu on 4/2/21.
//

#ifndef CPP_CHECKINGACCOUNTCHALLENGE_H
#define CPP_CHECKINGACCOUNTCHALLENGE_H
#include "AccountChallenge.h"
class CheckingAccountChallenge : public AccountChallenge{
private:
    static constexpr double def_fee {1.50};
public:
    CheckingAccountChallenge(const string &name,double amount);
    explicit CheckingAccountChallenge(const string &name);
    explicit CheckingAccountChallenge(string &&name);
    CheckingAccountChallenge(string &&name,double amount);
    CheckingAccountChallenge();

    bool withdraw(double amount);
    friend ostream &operator<<(ostream &ostream1, const CheckingAccountChallenge &CheckingAccountOBJ);

};
#endif //CPP_CHECKINGACCOUNTCHALLENGE_H
