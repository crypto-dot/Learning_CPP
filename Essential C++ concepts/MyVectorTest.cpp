//
// Created by Carlos Arbizu on 11/21/21.
//
#include "MyVector.h"
#include <iostream>
int main(){
    MyVector vector{1,2,3,4};
    vector.print();
    std::cout << '\n';
    std::cout << "Size: ";
    std::cout << vector.size() << '\n';
    std::cout << "Capacity: ";
    std::cout << vector.capacity() << '\n';
    vector.push_back(5);
    vector.print();
    vector.pop();
    vector.print();
    vector.insert(3,9);
    vector.print();
    vector.del(3);
    vector.print();
    return 0;
}