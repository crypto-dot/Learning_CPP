//
// Created by Carlos Arbizu on 3/30/21.
//
#include <iostream>
#include "SavingsAccount.h"
#include "AccountUpdated.h"
using std::cout;
using std::endl;
int main(){
    AccountUpdated accountUpdated(10);
    accountUpdated.WithDraw(14);
    SavingsAccount savingsAccount(0);
    savingsAccount.deposit(100);
    cout << savingsAccount << endl;
    savingsAccount.WithDraw(50);
    cout << savingsAccount << endl;
    savingsAccount.deposit(200);
    cout << savingsAccount << endl;

    return 0;
}