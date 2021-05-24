//
// Created by Carlos Arbizu on 5/6/21.
//
#include <memory>
#include <vector>
#include "CheckingAccountPoly.h"
#include "TrustAccountPoly.h"
#include "SavingsAccountPoly.h"
using std::vector;
using std::unique_ptr;
using std::make_unique;

int main(){

    unique_ptr<int> p1 {new int{100}};
    //A better way to initialize unique ptrs below
    unique_ptr<int> p3 = make_unique<int>(100);
    auto p2 = make_unique<int>(100);

    vector<unique_ptr<AccountPoly>> accounts;
    //No need to use std::move since we are creating temporary objects (xvalues) with make_unique function
    accounts.push_back(make_unique<TrustAccountPoly>("Matt",300));
    accounts.push_back(make_unique<CheckingAccountPoly>("pat",500));
    accounts.push_back(make_unique<SavingsAccountPoly>("Ron",600));
    for(const auto &acc : accounts){
        cout << *acc << endl;
        acc->deposit(100);
        cout << *acc << endl;
    }
    //No need
    return 0;
}