//
// Created by Carlos Arbizu on 6/10/21.
//

#include <iomanip>
#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;
using std::noboolalpha;


int main(){
    cout << (0 == 1) << endl;
    cout << (1 == 1) << endl; //default settings
    cout << boolalpha; //changes to true/false
    cout << (0 ==1 ) << endl;
    cout << (0 == 0) << endl;

    cout << noboolalpha; //back to 0/1
    cout << (0 ==1) << endl;
    cout << (1 == 1) << endl;

    //Here we are using the member method, this can work for any of the manipulators we will be using in this lesson
    //std is the namespace ios is the class name and boolalpha is the flag
    cout.setf(std::ios::boolalpha);
    cout << (0==1) << endl;
    cout << (1 == 1) << endl;


    cout << (0==1) << endl;
    cout << (1 == 1) << endl;

    return 0;
}