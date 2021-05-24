//
// Created by Carlos Arbizu on 11/29/20.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int number1;
    int number2;
    int number3;

    int total;
    const int count {3};

    cout << "Input three number (separated by a space) that are integers: ";
    cin >> number1 >> number2 >> number3;
    cout << endl;
    cout << "Your avg is: " << static_cast<double>(number3 + number2 + number1)/count;
    // (double) (number3 + number2 + number1)/count is old style








    return 0;
}