//
// Created by Carlos Arbizu on 4/2/21.
//

#ifndef CPP_TRUSTACCOUNTCHALLENGE_H
#define CPP_TRUSTACCOUNTCHALLENGE_H
#include "SavingsAccountChallenge.h"

class TrustAccountChallenge : public SavingsAccountChallenge {
private:
    static constexpr double bonus_amount{50.0};
    static constexpr size_t withdrawalsmax{3};
    static constexpr double bonus_threshold{50000};
    static constexpr double max_withdrawal_percentage{0.2};

protected:

    size_t num_withdrawals;
public:
    TrustAccountChallenge();
    TrustAccountChallenge(const string &name, double balance, double interestRate);
    TrustAccountChallenge(string &&name, double balance,double interestRate);
    explicit TrustAccountChallenge(string &&name);
    explicit TrustAccountChallenge(const string &name);
    bool withdraw(double amount);
    bool deposit(double amount);
};


#endif //CPP_TRUSTACCOUNTCHALLENGE_H
