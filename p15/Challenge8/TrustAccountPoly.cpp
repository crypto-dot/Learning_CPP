//
// Created by Carlos Arbizu on 5/3/21.
//

#include "TrustAccountPoly.h"

TrustAccountPoly::TrustAccountPoly(string name, double amount, double interestRate) : SavingsAccountPoly(std::move(name),amount,interestRate) {

}
TrustAccountPoly::TrustAccountPoly(string name, double amount) : SavingsAccountPoly(std::move(name),amount) {
    interestRate = def_interestRate;
}
bool TrustAccountPoly::deposit(double amount) {
    if(amount > 50000){
       return SavingsAccountPoly::deposit( amount + 50);
    }
    return SavingsAccountPoly::deposit(amount);
}
bool TrustAccountPoly::withdraw(double amount) {
    if( numOfWithdrawals < 3 && (amount/balance) <= maxWithdrawPercentage){
        SavingsAccountPoly::withdraw(amount);
        ++numOfWithdrawals;
        return true;
    }
    cout << "You have either reached the maximum number of withdrawals for this type of account or you're withdrawing too much" << endl;
    return false;
}
void TrustAccountPoly::print(ostream &ostream1) const {
    ostream1 << "+++++ Trust Account +++++" << endl;
    ostream1 << "Name: " << name << "| Balance: " << balance << endl;
}