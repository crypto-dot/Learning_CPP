//
// Created by Carlos Arbizu on 5/4/21.
//

#include "AccountPoly.h"

bool AccountPoly::deposit(double amount) {
    if (amount == 0){
        cout << "You cannot withdraw 0 funds!" << endl;
        return false;
    }
    else if(amount < 0){
        cout << "Deposit amount is less than 0!" << endl;
        return false;
    }
    cout << "Deposit successful!" << endl;
    balance +=amount;
    return true;
}

bool AccountPoly::withdraw(double amount) {
    if(amount == 0){
        cout << "The amount you tried to withdraw is 0" << endl;
        return false;
    }
    else if(balance - amount < 0){
        cout << "withdraw amount for the account is greater than available balance." << endl;
        return false;
    }
    cout << "Withdrawal successful!" << endl;
    balance -= amount;
    return true;
}