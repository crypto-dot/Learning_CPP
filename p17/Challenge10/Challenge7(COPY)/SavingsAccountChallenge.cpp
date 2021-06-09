//
// Created by Carlos Arbizu on 4/1/21.
//

#include "SavingsAccountChallenge.h"

SavingsAccountChallenge::SavingsAccountChallenge(string &&name, double amount, double interestRate) : AccountChallenge(name,amount), interestRate{interestRate}  {

}
SavingsAccountChallenge::SavingsAccountChallenge(const string &name, double amount, double interestRate): AccountChallenge(name,amount), interestRate{interestRate}
{}
SavingsAccountChallenge::SavingsAccountChallenge(string &&name) : AccountChallenge(name),interestRate{def_interestRate}  {
}
SavingsAccountChallenge::SavingsAccountChallenge(const string &name) : AccountChallenge(name),interestRate(def_interestRate) {

}
SavingsAccountChallenge::SavingsAccountChallenge() : AccountChallenge(), interestRate{def_interestRate} {}
bool SavingsAccountChallenge::deposit(double amount) {
    amount += amount * interestRate;
    return AccountChallenge::deposit(amount);
}
ostream &operator<<(ostream &ostream1, const SavingsAccountChallenge &SavingsAccountOBJ){
    ostream1 << "Name: " << SavingsAccountOBJ.name << " Balance: " << SavingsAccountOBJ.balance << " Interest rate: "<< SavingsAccountOBJ.interestRate;
    return ostream1;
}