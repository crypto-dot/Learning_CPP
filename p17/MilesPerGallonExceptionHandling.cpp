//
// Created by Carlos Arbizu on 5/22/21.
//
#include <iostream>
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

double calculate(int miles, int gallons){
    if(gallons== 0){
        throw 0;
    }
    if(miles < 0 || gallons <0){
        throw std::string("Negative Value ERROR!");
    }
    return miles/gallons;
}



int main (){
    int gallon,miles;
    double gallons_per_mile;
    cout << "Enter the number of miles you wish to travel: ";cin >> miles;cout << endl;
    cout << "Enter the number of gallons you have ";cin >> gallon;cout << endl;
    try {
        gallons_per_mile = calculate(miles, gallon);
        cout << "Your mpg is: " << gallons_per_mile << endl;
    }
    catch(int &ex){
        cerr << "Tried to divide by 0" << endl;
    }
    catch(string &ex){
        cerr << ex << endl;
    }
    /*
    catch(...){
        cerr << "Unknown Error" << endl;
    } */ //This catches all errors
    return 0;
}