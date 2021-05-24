//
// Created by Carlos Arbizu on 11/29/20.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){

    cout << "In the U.S.: " << endl;
    cout << "1 dollar is 100 cents." << endl;
    cout << "1 quarter is 25 cents." << endl;
    cout << "1 dime is 10 cents." << endl;
    cout << "1 nickle is 5 cents." << endl;
    cout << "1 penny is 1 cent. " << endl;

    int amount_in_cents;
    int amount_of_quarters;
    int amount_of_dollars;
    int amount_of_nickels;
    int amount_of_dimes;
    int amount_of_pennies;

    const int value_of_quarters = 25;
    const int value_of_dollars = 100;
    const int value_of_nickels = 5;
    const int value_of_dimes = 10;
    int leftover;

    cout<< "Enter an amount in cents: "; cin >> amount_in_cents; cout<<endl;
    amount_of_dollars = amount_in_cents/value_of_dollars;
    leftover = amount_in_cents % value_of_dollars;
    amount_of_quarters = leftover/value_of_quarters;
    leftover %= value_of_quarters;
    amount_of_dimes = leftover/value_of_dimes;
    leftover %= value_of_dimes;
    amount_of_nickels = leftover/value_of_nickels;
    leftover %= value_of_nickels;
    amount_of_pennies = leftover;

    cout<< "You can provide the change as following: "<< endl;
    cout<< "dollars: " << amount_of_dollars << endl;
    cout<< "quarters: " << amount_of_quarters << endl;
    cout<< "dimes: " << amount_of_dimes << endl;
    cout<< "nickels: " << amount_of_nickels << endl;
    cout<< "pennies: " << amount_of_pennies << endl;




    return 0;
}