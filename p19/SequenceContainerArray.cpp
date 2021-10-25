//
// Created by Carlos Arbizu on 9/14/21.
//
#include <array>
using std::array;
#include <iostream>
using std::cout;
using std::cerr;
using std::flush;
#include <algorithm>
using std::sort;
using std::min_element;
using std::max_element;
using std::adjacent_find;
#include <numeric>

using std::accumulate;
template <typename T, size_t N>
void display(const array<T,N> &arr){
    cout << "[ ";
    for(const T &i : arr){
        cout << i << " ";
    }
    cout << "]";
}
void test1(){
    array<uint64_t,5> array1 {1, 2, 3, 4, 5};
    array<uint64_t,5> array2 {99, 20, 14, 15, 19};


    cout << "\n";
    cout << "Front of array1: " << array1.front() << "\n";
    cout << "Back of array1: " << array1.back() << "\n";
    cout << "Front of array2: " << array2.front() << "\n";
    cout << "Back of array2" << array2.back() << "\n";

    cout << "\n";\
    cout << array1[0] <<  //No bounds checking
    "\n";
    cout  << array1.at(0) //Bounds checking
     << "\n";

    cout << "Swapping the contents of array1 and array2 \n";
    cout << "Contents of array1: ";
    display(array1);
    cout <<"\n";
    cout << "Contents of array2: ";
    display(array2);
    cout << "\n";
    array1.swap(array2);
    cout << "Contents of array1: ";
    display(array1);
    cout <<"\n";
    cout << "Contents of array2: ";
    display(array2);
    cout << "\n";

    display(array1);

    cout << "Filling array1 with zeros: ";

    array1.fill(0);

}
void test2(){

    array<uint64_t,5> array{1, 2, 3, 4, 5};
    uint64_t *ptr = array.data(); //Gives the memory address to the first array element
    *ptr = 1000;//set the first element equal to 1000
    display(array);
}
void test3(){
    std::array<uint64_t,5> array{2, 1, 5, 4, 3};
    display(array);
    cout << "\n";
    sort(array.begin(),array.end());
    display(array);
    cout << "\n";

}
void test4(){
    array<uint64_t,6> array1 {2, 14, 5, 1, 0, 92};
    auto min {min_element(array1.begin(), array1.end())};
    auto max {max_element(array1.begin(),array1.end())};
    cout << "The minimum element is: " << *min << "\n"; //dont forget to derefeence the iterator
    cout << "The maxmium element is: " << *max << "\n";


}
void test5(){
    array<uint64_t,5> array {1, 2, 3, 4, 4};
    auto adjacent {adjacent_find(array.begin(),array.end())}; //Returns the first instance of 2 elements that are equal
    if(adjacent != array.end()){
        cout << "Found 2 elements that are the same \n";
    }
    else {
        cout << "There are no elements that are the same in this container \n";
    }


}
void test6(){
    array<uint64_t,5> array1 {1, 2, 3, 4, 5};
    uint64_t sum {static_cast<uint64_t>(accumulate(array1.begin(),array1.end(),0))};
    cout << "Sum: " << sum << '\n';

}
int main(){
/*    test1();*/
/*    test2();*/
/*    test3();*/
/*    test4();*/
/*    test5();*/
/*    test6();*/



    return 0;
}