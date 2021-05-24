//
// Created by Carlos Arbizu on 12/22/20.
//

//passing pointer through functions can be done through c++
#include <iostream>
void doubleptr(int *ptr);
int main(){
    int value {3};
    //here we can pass the variable value through this function using the variable's address or a pointer pointing to the variable itself
    // NOTE: the variable changes remain after the function is called since the function is changing the value
    // at the address which is very different from pass by value functions and is the same as pass by reference functions
    doubleptr(&value);
    std::cout << value << " is the value of the variable";


    return 0;
}
void doubleptr(int *ptr){
    *ptr *= 2;
}
