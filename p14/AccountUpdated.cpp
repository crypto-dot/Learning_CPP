//
// Created by Carlos Arbizu on 3/29/21.
//

#include "AccountUpdated.h"
void AccountUpdated::Deposit(double_t amount) {
        balance += amount;
}
AccountUpdated::AccountUpdated() : balance{0}{
}
AccountUpdated::AccountUpdated(double_t amount) : balance{amount}{}
void AccountUpdated::WithDraw(double_t amount) {
    if(amount > balance || amount < 0){
        cout << "Error" << endl;
    }
    else {
        balance -= amount;
    }
}
ostream &operator<<(ostream &ostream,const AccountUpdated &accountUpdatedOBJ){
    ostream << accountUpdatedOBJ.balance;
    return ostream;
}

