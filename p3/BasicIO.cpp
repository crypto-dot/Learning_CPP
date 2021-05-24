//
// Created by Carlos Arbizu on 11/26/20.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main(){

    cout << "Hello world" <<endl;
    cout << "Hello";
    cout << " World" <<endl;


    int number;
    int number2;
    double number3;


    cout << "Enter a number\n";
    cin >> number;
    cout << "You typed " << number << "\n";
    // **********************************************************************
    cout << "Great! Now type a number\n";
    cin >> number;
    cout << "Now type another number\n";
    cin >> number2;

    // Two input streams

    cout << "Great! The 2 numbers you typed were " << number << " and " << number2 << "\n";

    cout << "Great! Now type two numbers separated by space\n";

    cin >> number >> number2;
    //one input stream

    cout << "Great! The 2 numbers are " << number << " and " << number2 << "\n";
    // ************************************************************************
    cout << "Enter a double and an integer";

    cin >> number3 >> number;

    //one input stream

    cout << "You typed " << number3 << " and " << number << "\n";

    int age = 21;
    int Age = {21};
    //Initialize as a list with 1 element
    int age3 (21);
    // Intitialize as a constructor

    // THREE VALID WAYS TO INTIALIZE A VARIABLE.
    return 0;


}