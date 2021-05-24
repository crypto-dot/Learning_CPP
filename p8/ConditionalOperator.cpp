//
// Created by Carlos Arbizu on 11/29/20.
//
#include <iostream>
int main(){
    // The conditional operator is a tertary operator in the form of (condition) ? exp1 : exp2
    // If condition is true exp1 is executed else exp2
    int num1;
    std::cout << "Enter a number: ";  std::cin >> num1;
    std::cout << "Your number is " << ((num1 %2 == 0) ? "even" : "odd" );
    std::cout << std::endl;

    std::cout << "Enter a number divisible by three: "; std::cin >> num1;
    std::cout << "Your number is " << ((num1%3 == 0) ?  "divisible by three!" : "not divisible by three!");

    return 0;
}