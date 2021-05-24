//
// Created by Carlos Arbizu on 12/22/20.
//

#include <iostream>

int main(){
    //pointers can be added or subtracted by n
    //adding or subtracting a pointer by n is the same as adding by n and
    // multiplying n by sizeof(DATATYPE) the datatype you are using
    // adding and subtracting pointers returns the difference
    //we can compare pointers to see if they point to the same LOCATION
    // not the same data stored if you want to see if the data is the same
    // DEREFERENCE the pointer
    int scores[5] {100,300,200,800,-1};
    int *ptr_int {scores};
    int n {0};
    int *ptr_int2 {scores};
    //accessing elements in array using pointers
    while(*ptr_int!= -1){
        std::cout << *ptr_int << std::endl;
        n = ptr_int - ptr_int2;
        std::cout << n * sizeof(int) << " is the difference between the two pointers' address (in bytes)." << std::endl;
        ptr_int++; //increment the pointer address by 4 (value is specific to this system)
    }

    //The pointer can be dereferenced and incremented all in one line using the ++ operator
    ptr_int = scores;
    while(*ptr_int != -1){
        std::cout << *ptr_int++ << std::endl;
    }

    return 0;
}