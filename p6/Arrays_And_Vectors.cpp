//
// Created by Carlos Arbizu on 11/28/20.
//
#include <array>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
int main(){

    // Some different ways to initialize arrays
    int array[5] {10,11,12,13,14};
    int array0[5] = {10,11,12};
    int array1[5] {0};
    //The above example sets all the 5 elements in array to 0;

    int arrays[5] {1,2,3,4,5};
    //Static implementation
    int* arrays1 = new int[5];
    // Dynamic implementation
    std::vector<int> vec {};
    std::vector<int> vec1 (5,0); // FIRST ARG IS NUMBER SECOND ARG IS ELEMENTS (so we are getting 5 0s)
    int result {0};
    for(int i {0}; i < vec.size(); i++){
        for(int j {0};j < vec.size(); j++){
            result += vec.at(i) * vec.at(j);
        }
    }
//    std::cout << vec.size() << " is the size";
//    if(vec.size() > 1){
//    for(int i {0}; i < vec.size() - 1; i++){
//        for(int j {i+1}; j <= vec.size() -1; j++ ){
//            result += vec[i] * vec[j];
//        }
//    }
//        }
    std::cout << result;

    return 0;

}
