//
// Created by Carlos Arbizu on 5/4/21.
//
#include "AccountUtilityPoly.h"
void display(const vector<AccountPoly *> &Accounts){
    for(auto account : Accounts){
        cout << *account << endl;
    }
}
void deposit(const vector<AccountPoly *> &Accounts, double amount) {
    for (auto account : Accounts) {
        account->deposit(amount);
    }
}
void withdraw(const vector<AccountPoly *> &Accounts, double amount){
    for(auto account : Accounts){
        account->withdraw(amount);
    }
}