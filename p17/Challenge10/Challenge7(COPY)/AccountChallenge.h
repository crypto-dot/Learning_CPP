//
// Created by Carlos Arbizu on 4/1/21.
//

#ifndef CPP_ACCOUNTCHALLENGE_H
#define CPP_ACCOUNTCHALLENGE_H
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::ostream;
class AccountChallenge {

private:
    //These variables are for the default values
    static double constexpr def_balance {0};
    static constexpr const char* def_name {"Unnamed"};
protected:
    string name;
    double balance;
public:
    AccountChallenge(string &&name,double amount);
    AccountChallenge(const string &name, double amount);
    AccountChallenge();
    explicit AccountChallenge(string &&name);
    explicit AccountChallenge(const string &name);
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    string getName() const;
    friend ostream &operator<<(ostream &ostreamAccount, const AccountChallenge &AccountObj);

};


#endif //CPP_ACCOUNTCHALLENGE_H
