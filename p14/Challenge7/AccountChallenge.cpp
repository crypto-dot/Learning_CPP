//
// Created by Carlos Arbizu on 4/1/21.
//

#include "AccountChallenge.h"



AccountChallenge::AccountChallenge(string &&name, double balance) : name{std::move(name)}, balance{balance} {
}
AccountChallenge::AccountChallenge( const string &name, double balance) : name{name}, balance{balance} { }
AccountChallenge::AccountChallenge() : name{def_name}, balance{def_balance}{}
AccountChallenge::AccountChallenge(string &&name) : name{std::move(name)} {}
AccountChallenge::AccountChallenge(const string &name) : name{name} {}
bool AccountChallenge::deposit(double amount) {
    if (amount < 0) {
        cout << "Error: Depositing an invalid amount" << endl;
        return false;
    }
    balance += amount;
    cout << "Deposit successful! " << endl;
    return true;
}
bool AccountChallenge::withdraw(double amount) {
    if(balance - amount < 0) {
        cout << "Error: Withdrawing an invalid amount (less than 0)" << endl;
        return false;
    }
    else if(amount < 0){
        cout << "Error: Withdrawing a negative amount " << endl;
        return false;
    }
    balance -= amount;
    return true;
    }
string AccountChallenge::getName() const {
    return name;
}
double AccountChallenge::getBalance() const {
    return balance;
}
    ostream &operator<<(ostream &ostream1, const AccountChallenge &AccountObj) {
        ostream1 << "Name: " << AccountObj.name << " Balance: " << AccountObj.balance;
        return ostream1;
    }
