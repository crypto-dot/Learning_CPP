//
// Created by Carlos Arbizu on 4/1/21.
//

#include "AccountUtility.h"

void display(const vector<AccountChallenge> &listOfAccounts){
    for(auto &account : listOfAccounts){
        cout << account << endl;
    }
}
void deposit( vector<AccountChallenge> &listOfAccounts,double amount) {
    for(auto &account : listOfAccounts) {
        account.deposit(amount);
    }
}
void withdraw(vector<AccountChallenge> &listOfAccounts,double amount){
    for(auto &account : listOfAccounts) {
        account.withdraw(amount);
    }
}

void display(const vector<SavingsAccountChallenge> &listOfAccounts){
    for( auto &account : listOfAccounts){
        cout << account << endl;
    }
}
void deposit( vector<SavingsAccountChallenge> &listOfAccounts,double amount) {
    for(auto &account : listOfAccounts) {
        account.deposit(amount);
    }
}
void withdraw(vector<SavingsAccountChallenge> &listOfAccounts,double amount){
    for(auto &account : listOfAccounts) {
        account.withdraw(amount);
    }
}

void display(const vector<CheckingAccountChallenge> &listOfAccounts){
    for(auto & account : listOfAccounts){
        cout << account << endl;
    }
}

void deposit( vector<CheckingAccountChallenge> &listOfAccounts,double amount){
    for(auto & account : listOfAccounts){
        account.deposit(amount);
    }
}

void withdraw( vector<CheckingAccountChallenge> &listOfAccounts,double amount){
    for(auto & account : listOfAccounts){
        account.withdraw(amount);
    }
}

void display(const vector<TrustAccountChallenge> &listOfAccounts){
    for(auto & account : listOfAccounts){
        cout << account << endl;
    }
}

void deposit(vector<TrustAccountChallenge> &listOfAccounts,double amount){
    for(auto & account : listOfAccounts){
        account.deposit(amount);
    }
}

void withdraw(vector<TrustAccountChallenge> &listOfAccounts,double amount){
    for(auto & account : listOfAccounts){
        account.withdraw(amount);
    }
}