//
// Created by Carlos Arbizu on 11/29/20.
//
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main (){
    bool equal_result;
    bool notequal_result;

    int num1; int num2;
    std::boolalpha(cout); // Puts true / false instead of (0 / 1) // can also do cout << std::boolalpha
    cout << "Input two integers separated by a space: ";
    cin >> num1 >> num2;
    equal_result = (num1 == num2);
    notequal_result = (num1 != num2);
    cout << endl;
    cout << "Comparison results(equality): " << equal_result << endl;
    cout << "Comparison results(inequality): " << notequal_result << endl;

    double num3; double num4;
    cout << "Input two doubles separated by a space: ";
    cin >> num3 >> num4;
    equal_result = (num3 == num4);
    notequal_result = (num3 != num4);
    cout << endl;
    cout << "Comparison results(equality): " << equal_result << endl;
    cout << "Comparison results(inequality): " << notequal_result << endl;

    int num5; double num6;
    cout << "Input one double and one int separated by a space: ";
    cin >> num6 >> num5;
    equal_result = (num5 == num6);
    notequal_result = (num5 != num6);
    cout << endl;
    cout << "Comparison results(equality): " << equal_result << endl;
    cout << "Comparison results(inequality): " << notequal_result << endl;
    cout << "The int is " << num5 << endl;
    cout << "The double is " << num6;





    return 0;
}