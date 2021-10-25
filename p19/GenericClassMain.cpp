//
// Created by Carlos Arbizu on 9/9/21.
//
#include "Array.h"
#include <iostream>
using std::cout;
int main(){
    Array<Array<Array<double,2>,3>,3> array{Array<Array<double,2>,3> (1)};
    cout << array << "\n";

    return 0;
}