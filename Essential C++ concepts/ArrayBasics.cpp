//
// Created by Carlos Arbizu on 11/10/21.
//
#include <stdio.h>
#include <iostream>
#include <vector>

template <typename T1,size_t n>
void printArray(T1 array[n]){
    for(const auto &element : array){
        if(element)
        std::cout << element << "\n";
    }
}
int main(){
    size_t h;
    int arr[5] = {0};
    std::vector<int> vec{1,2,3,4,5};
    vec.push_back(1);
    std::cout << vec.size() << '\n';
    std::cout << vec.capacity() << '\n';
    printf("size of array %lu \n",sizeof(arr)/(sizeof(arr[0])));
    int count {1};
    for(int x : arr){
        printf("element number %i of array: %i \n",count++,x);
    }
    int arr2[5][4] = {{0}};

    long x = 4;
    bool isPowerofTwo = !(x & (x - 1));
    std::cout << x;
    if(isPowerofTwo){
        std::cout << "yes";
    }

    return 0;
}