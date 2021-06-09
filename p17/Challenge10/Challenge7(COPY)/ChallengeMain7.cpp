
//
// Created by Carlos Arbizu on 4/1/21.
//
#include "SavingsAccountChallenge.h"
#include "AccountChallenge.h"
#include "AccountUtility.h"
#include "TrustAccountChallenge.h"
#include "CheckingAccountChallenge.h"
#include "InsufficientFundsException.h"
#include "IllegalBalanceException.h"
#include "exception"
#include <memory>
using std::make_unique;
using std::unique_ptr;
using std::exception;
using std::cerr;

int main(){
    try {
        try{
            unique_ptr<AccountChallenge> AccountTest2 {make_unique<TrustAccountChallenge>("Trust", -3, 2)};
        }
        catch(const IllegalBalanceException &ex){
            cerr << ex.what() << endl;
        }
        AccountChallenge AccountTest{"Test", 500};
        AccountTest.withdraw(501);
    }

    catch(const InsufficientFundsException &ex){
        cerr << ex.what() << endl;    }


    return 0;
}