//
// Created by Carlos Arbizu on 4/1/21.
//

#ifndef CPP_ACCOUNTUTILITYPOLY_H
#define CPP_ACCOUNTUTILITY_H
#include <vector>
#include "AccountChallenge.h"
#include "SavingsAccountChallenge.h"
#include "CheckingAccountChallenge.h"
#include "TrustAccountChallenge.h"
using std::vector;

void display(const vector<AccountChallenge> &listOfAccounts);
void deposit(vector<AccountChallenge> &listOfAccounts,double amount);
void withdraw(vector<AccountChallenge> &listOfAccounts,double amount);

void display(const vector<SavingsAccountChallenge> &listOfAccounts);
void deposit(vector<SavingsAccountChallenge> &listOfAccounts,double amount);
void withdraw(vector<SavingsAccountChallenge> &listOfAccounts,double amount);

void display(const vector<CheckingAccountChallenge> &listOfAccounts);
void deposit(vector<CheckingAccountChallenge> &listOfAccounts,double amount);
void withdraw(vector<CheckingAccountChallenge> &listOfAccounts,double amount);

void display(const vector<TrustAccountChallenge> &listOfAccounts);
void deposit(vector<TrustAccountChallenge> &listOfAccounts,double amount);
void withdraw(vector<TrustAccountChallenge> &listOfAccounts,double amount);

#endif //CPP_ACCOUNTUTILITYPOLY_H
