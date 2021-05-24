//
// Created by Carlos Arbizu on 4/2/21.
//

#include "TrustAccountChallenge.h"
TrustAccountChallenge::TrustAccountChallenge() : SavingsAccountChallenge(),num_withdrawals{0} {}
TrustAccountChallenge::TrustAccountChallenge(const string &name) : SavingsAccountChallenge(name),num_withdrawals{0} {}
TrustAccountChallenge::TrustAccountChallenge(string &&name) : SavingsAccountChallenge(name),num_withdrawals{0} {}
TrustAccountChallenge::TrustAccountChallenge(string &&name, double balance, double interestRate) : SavingsAccountChallenge(name,balance,interestRate),num_withdrawals{0} {}
TrustAccountChallenge::TrustAccountChallenge(const string &name, double balance, double interestRate) : SavingsAccountChallenge(name,balance,interestRate),num_withdrawals{0} {}
bool TrustAccountChallenge::deposit(double amount) {
   if(amount >= bonus_threshold){
        return SavingsAccountChallenge::deposit(amount + bonus_amount);
    }
    return SavingsAccountChallenge::deposit(amount);
}
bool TrustAccountChallenge::withdraw(double amount) {
    if(amount < balance * max_withdrawal_percentage && num_withdrawals <= withdrawalsmax){
        num_withdrawals++;
        return SavingsAccountChallenge::withdraw(amount);
    }
    else if(amount >= balance * max_withdrawal_percentage){
        cout << "You are withdrawing over " << max_withdrawal_percentage << " of you account balance"  << endl;

        return false;
    }
    cout << "Your withdrawalsmax this year are over " << withdrawalsmax<< endl;

    return false;
}