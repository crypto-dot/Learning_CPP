//
// Created by Carlos Arbizu on 3/29/21.
//

#include "SavingsAccount.h"
#include "AccountUpdated.h"
SavingsAccount::SavingsAccount() : interestRate(.05) {

}
SavingsAccount::SavingsAccount(double_t amount) : interestRate{.05}  {
    AccountUpdated::balance = amount;
}
SavingsAccount::SavingsAccount(double_t amount, double_t interestRate) : interestRate{interestRate}, AccountUpdated(amount) {

}
void SavingsAccount::deposit(double_t amount) {
    amount += amount * interestRate;
    AccountUpdated::Deposit(amount);
}
ostream &operator<<(ostream &ostream, const SavingsAccount &SavingsAccountOBJ){
    ostream << "Balance: " << SavingsAccountOBJ.balance << " Interest rate: " << SavingsAccountOBJ.interestRate;
    return ostream;
}