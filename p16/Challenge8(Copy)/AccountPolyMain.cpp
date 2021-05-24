//
// Created by Carlos Arbizu on 5/4/21.
//
#include "TrustAccountPoly.h"
#include "CheckingAccountPoly.h"
#include "SavingsAccountPoly.h"
#include "AccountUtilityPoly.h"
int main(){
    //Static binding
    TrustAccountPoly trustAccount("Mark",3000);
    TrustAccountPoly trustAccount2("Zack",500);
    TrustAccountPoly trustAccount3("Brian",0);
    CheckingAccountPoly checkAccount("Zane",20);
    CheckingAccountPoly checkAccount2("Pat",0);
    CheckingAccountPoly checkAccount3("Ryan",1.50);
    SavingsAccountPoly saveAccount("Mike",100,.04);
    SavingsAccountPoly saveAccount2("Walt",1000);
    SavingsAccountPoly saveAccount3("Jordan",10,.01);

    //Dynamic binding
    AccountPoly *dynamicTrustAccount = new TrustAccountPoly("Mark",3000);
    AccountPoly *dynamicTrustAccount2 = new TrustAccountPoly("Zack",500);
    AccountPoly *dynamicTrustAccount3 = new TrustAccountPoly("Brian",0);
    AccountPoly *dynamicCheckAccount = new CheckingAccountPoly("Zane",20);
    AccountPoly *dynamicCheckAccount2 = new CheckingAccountPoly("Pat",0);
    AccountPoly *dynamicCheckAccount3 = new CheckingAccountPoly("Ryan",1.50);
    AccountPoly *dynamicSaveAccount = new SavingsAccountPoly("Mike",100,.04);
    AccountPoly *dynamicSaveAccount2 = new SavingsAccountPoly("Walt",1000);
    AccountPoly *dynamicSaveAccount3 = new SavingsAccountPoly("Jordan",10,.01);

    vector<AccountPoly *> accounts {dynamicSaveAccount,dynamicSaveAccount2,dynamicSaveAccount3,dynamicCheckAccount,dynamicCheckAccount2,dynamicCheckAccount3,
    dynamicTrustAccount,dynamicTrustAccount2,dynamicTrustAccount3};

    display(accounts);
    withdraw(accounts,10);
    deposit(accounts,5);
    display(accounts);
    withdraw(accounts,10);
    withdraw(accounts,10);
    withdraw(accounts,10);
    display(accounts);
}