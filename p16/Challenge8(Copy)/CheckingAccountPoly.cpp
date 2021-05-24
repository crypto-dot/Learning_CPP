//
// Created by Carlos Arbizu on 5/4/21.
//

#include "CheckingAccountPoly.h"
bool CheckingAccountPoly::withdraw(double amount) {
    return AccountPoly::withdraw(amount+fee);
}
bool CheckingAccountPoly::deposit(double amount) {
    return AccountPoly::deposit(amount);
}
void CheckingAccountPoly::print(ostream &ostream1) const {
    ostream1 << "+++++++ Checking Account +++++++" << endl;
    ostream1 << "Name: " << name << "| Balance: " << balance << endl;
}
CheckingAccountPoly::CheckingAccountPoly(string name, double amount) : AccountPoly(std::move(name),amount) {}