//
// Created by Carlos Arbizu on 4/2/21.
//

#include "CheckingAccountChallenge.h"

CheckingAccountChallenge::CheckingAccountChallenge() : AccountChallenge() {}
CheckingAccountChallenge::CheckingAccountChallenge(string &&name) : AccountChallenge(name) {}
CheckingAccountChallenge::CheckingAccountChallenge(const string &name) : AccountChallenge(name) {}
CheckingAccountChallenge::CheckingAccountChallenge(string &&name, double amount) :AccountChallenge(name,amount){}
CheckingAccountChallenge::CheckingAccountChallenge(const string &name,double amount) : AccountChallenge(name,amount){}

bool CheckingAccountChallenge::withdraw(double amount) {
    amount += def_fee;
    return AccountChallenge::withdraw(amount);
}
ostream &operator<<(ostream &ostream1, const CheckingAccountChallenge &CheckingAccountOBJ){
    ostream1 << "Name: " << CheckingAccountOBJ.name << " Balance: " << CheckingAccountOBJ.balance;
    return ostream1;
}