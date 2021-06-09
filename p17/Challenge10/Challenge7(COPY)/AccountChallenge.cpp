//
// Created by Carlos Arbizu on 4/1/21.
//

#include "AccountChallenge.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

AccountChallenge::AccountChallenge(string &&name, double balance) : name{std::move(name)}, balance{balance} {
    if(balance < 0){
        throw IllegalBalanceException();
    }
}
AccountChallenge::AccountChallenge( const string &name, double balance) : name{name},balance{balance}{
    if(balance < 0){
        throw IllegalBalanceException();
    }
}
AccountChallenge::AccountChallenge() : AccountChallenge(def_name,def_balance){}
AccountChallenge::AccountChallenge(string &&name) : AccountChallenge(std::move(name),def_balance) {}
AccountChallenge::AccountChallenge(const string &name) : AccountChallenge(name,def_balance) {}
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
    if(balance < amount) {
       throw InsufficientFundsException();
    }
    if(amount < 0){
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
