//
// Created by Carlos Arbizu on 9/12/21.
//

//Using functor,function pointer, and lambdas for STL algos
#include <iostream>
using std::cout;
#include <algorithm>
using std::for_each;
#include <vector>

using std::vector;

struct Square_functor{
    void operator()(uint64_t x){
        cout << x * x << " ";
    }
};

void Square(uint64_t x) {
    cout << x * x << " ";
};

int main(){

    Square_functor square;

    vector<uint64_t> vector {1, 2, 3, 4, 5, 6};

    for_each(vector.begin(),vector.end(),square);
    //Functor object is passed

    cout << "\n";

    for_each(vector.begin(),vector.end(),Square);
    //Function pointer is passed (Address of the function is passed)

    cout << "\n";

    for_each(vector.begin(),vector.end(), [] (uint64_t x) {cout << x * x << " ";});
    //Lambda expression is passed (aka anonymous function)


    cout << "\n";
    for(const auto &value : vector){
        cout << value << "\n";
    }

    return 0;
}