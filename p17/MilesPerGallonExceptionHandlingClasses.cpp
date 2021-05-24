//
// Created by Carlos Arbizu on 5/23/21.
//
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

class NegativeValueException{
};
class DivideByZeroException{
};

double calculate(int miles, int gallons){
    if(gallons == 0){
        throw DivideByZeroException(); //calls the default constructor of the exception object
    }
    if(gallons < 0 || miles < 0){
        throw NegativeValueException();
    }
    return static_cast<double> (miles/gallons);
}
int main(){
    int miles, gallons;
    double mpg;

    cout << "Enter the number of miles you have driven: "; cin >> miles; cout << endl;
    cout << "Enter the number of gallons you have: "; cin >> gallons; cout << endl;
    try {
        mpg = calculate(miles, gallons);
        cout << "Result: " << mpg << endl;
    }
    catch(const NegativeValueException &ex){
        cerr << "Negative value was used!" << endl;
    }
    catch(const DivideByZeroException &ex){
        cerr << "You can't divide by zero! " << endl;
    }


    return 0;
}