//
// Created by Carlos Arbizu on 12/30/20.
//
#include <iostream>
#include <cstdlib>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main(){

    double input;

    cout << "Input the number you want to take the square root of: "; cin >> input; cout << endl;

    double middlenum = {input/2};
    const double error = {.000000000001};
    double max = input;

    while(abs(middlenum * middlenum - input) >=  error )
    {
        if(middlenum * middlenum > input){
            max = middlenum;
            middlenum = middlenum/2;
        }
        else {
            middlenum = (max + middlenum)/2;
        }
    }
    cout << middlenum << endl;

    //for answers just a bit above or below due to error
    if(int(middlenum) * int(middlenum) == input){
        middlenum = int(middlenum);
    }
    else if((int(middlenum) + 1) * (int(middlenum) + 1) == input){
        middlenum = int(middlenum) + 1;
    }

    cout << std::setprecision(11);
    cout << "The result is: " << middlenum;


    return 0;
}