//
// Created by Carlos Arbizu on 5/1/21.
//

#include "SavingsAccountPoly.h"
SavingsAccountPoly::SavingsAccountPoly(string name, double balance, double interestRate) : AccountPoly(std::move(name),balance),interestRate{interestRate}{
}
SavingsAccountPoly::SavingsAccountPoly(string name, double balance) : AccountPoly(std::move(name),balance),interestRate{def_interestRate} {
}
void SavingsAccountPoly::print(ostream &ostream1) const {
    ostream1 << "+++++ Savings Account +++++" << endl;
    ostream1 << "Name: " << name << "| Balance: " << balance << endl;
}
bool SavingsAccountPoly::withdraw(double amount) {
    return AccountPoly::withdraw(amount);
}
bool SavingsAccountPoly::deposit(double amount) {
    return AccountPoly::deposit(amount);
}
