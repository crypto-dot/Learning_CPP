//
// Created by Carlos Arbizu on 6/14/21.
//
#include <iostream>
#include <iomanip>
using std::hex;
using std::dec;
using std::oct;
using std::showbase;
using std::showpos;
using std::resetiosflags;
using std::cout;
using std::endl;

int main(){

    int num {255};

    cout << showbase; //std::noshowbase
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;

    int num2 {-255};
    cout << showpos;
    cout << oct << endl;
    cout << num << endl;
    cout << num2 << endl;

    cout << resetiosflags(std::ios::showpos); //resets the flags to default
    cout << resetiosflags(std::ios::showbase);






    return 0;
}