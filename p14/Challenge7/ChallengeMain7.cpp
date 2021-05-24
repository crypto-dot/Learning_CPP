
//
// Created by Carlos Arbizu on 4/1/21.
//
#include "SavingsAccountChallenge.h"
#include "AccountChallenge.h"
#include "AccountUtility.h"
#include "TrustAccountChallenge.h"
#include "CheckingAccountChallenge.h"
int main(){
    AccountChallenge account1("Charles",100);
    vector<AccountChallenge> listofAccounts {account1};
    AccountChallenge account2("Brian",300);
    listofAccounts.push_back(account2);
    AccountChallenge account3("Daniel",300);
    listofAccounts.push_back(account3);

    withdraw(listofAccounts,300);
    display(listofAccounts);
/****************************************************************************/
    SavingsAccountChallenge SavingsAccount("Carlos");
    SavingsAccount.deposit(100);
    SavingsAccountChallenge SavingsAccount1("Sam",200,.03);
    SavingsAccountChallenge SavingsAccount2("Bob",5500,.10);
    SavingsAccountChallenge SavingsAccount3{};
    vector<SavingsAccountChallenge> listofSavingsAccounts {};
    listofAccounts.push_back(SavingsAccount);
    listofAccounts.push_back(SavingsAccount1);
    listofAccounts.push_back(SavingsAccount2);
/****************************************************************************/
    TrustAccountChallenge TrustAccount("Tommy",1000,.06);
    TrustAccountChallenge TrustAccount2("Tom",3000,.06);
    TrustAccountChallenge TrustAccount3("Tim",1500,.06);

    vector<TrustAccountChallenge> listofTrustAccounts {TrustAccount,TrustAccount2,TrustAccount3};

    withdraw(listofTrustAccounts,599.99);
    display(listofTrustAccounts);

    deposit(listofTrustAccounts,-2);

    withdraw(listofTrustAccounts,-3);

    withdraw(listofTrustAccounts,30);
    withdraw(listofTrustAccounts,40);
    withdraw(listofTrustAccounts,50);

    withdraw(listofTrustAccounts,-2);

/****************************************************************************/
    CheckingAccountChallenge CheckingAccount("Brian",300);
    CheckingAccountChallenge CheckingAccount2("Batman",10000);
    CheckingAccountChallenge CheckingAccount3("Superman",51.50);
    CheckingAccountChallenge CheckingAccount4("Joker",1.50);
    //Side note if you have an empty pair of '()' characters the compiler will
    //interpret it as a function declaration 'This is related to what is known as "C++'s most vexing parse'
    //Good stackoverflow answer on this problem (https://stackoverflow.com/questions/180172/default-constructor-with-empty-brackets)
    CheckingAccountChallenge CheckingAccount5{};
    vector<CheckingAccountChallenge> listofCheckingAccounts{CheckingAccount,CheckingAccount2,CheckingAccount3,CheckingAccount4,CheckingAccount5};
    withdraw(listofCheckingAccounts,50);
    display(listofCheckingAccounts);

    return 0;
}