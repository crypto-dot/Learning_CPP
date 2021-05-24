//
// Created by Carlos Arbizu on 5/4/21.
//

#ifndef CPP_ACCOUNTUTILITYPOLY_H
#define CPP_ACCOUNTUTILITYPOLY_H
#include "AccountPoly.h"
#include <vector>
using std::vector;
    void deposit(const vector<AccountPoly *> &accounts,double amount);
    void display(const vector<AccountPoly *> &accounts);
    void withdraw(const vector<AccountPoly *> &accounts,double amount);
#endif //CPP_ACCOUNTUTILITYPOLY_H
