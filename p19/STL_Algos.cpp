//
// Created by Carlos Arbizu on 9/12/21.
//

//To show examples of some algos in C++ STL
#include <algorithm>
using std::count_if;
using std::replace;
using std::all_of;
using std::transform;

#include <vector>
using std::vector;
#include <set>
using std::set;
#include <map>
using std::map;
#include <list>
using std::list;
#include <iostream>

using std::cout;
using std::string;


void Count_if_test(){

    vector<uint64_t> vector{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    auto num { count_if(vector.begin(),vector.end(),[] (uint64_t x) {return x % 2 == 0; }) };
    cout << "The number of even numbers in the container is: " << num << "\n";

    num = count_if(vector.begin(),vector.end(), [] (uint64_t x) {return x%2 != 0;});
    cout << "The number of odd number in the contaienr is: " << num << "\n";
}

void Replace_test(){
    vector<uint64_t> vector{1,2,3,4,5,1,7,38,99,1,11,111,1,14,15,1,17,18,1,220};

    for(auto &num : vector){
        cout << num << " ";
    }
    cout << "\n";
    replace(vector.begin(),vector.end(),1,100);
    for(auto &num : vector){
        cout << num << " ";
    }
    cout << "\n";
}

void All_of_test(){
    //Tests to see if all the elements match the predicate requirements
    //Theres also an algo called any of it will test to see if any of the elements match the predicate requirements
    vector<uint64_t> vector{3,6,9,18,21,33};
    if(all_of(vector.begin(),vector.end(),[] (uint64_t x) {return x%3==0;}))
    {
        cout << "All the elements are divisible by 3 \n";
    }

    if(all_of(vector.begin(),vector.end(),[] (uint64_t x) {return x >20;}))
    {
        cout << "All of the elements are greater than 20 \n";
    }
    else {
        cout << "Not all of the elements are greater than 20 \n";
    }

}

void Transform_test(){
    string name {"carlos"};
    cout << "Name before transformation: " << name;
    cout << '\n';
    transform(name.begin(),name.end(),name.begin(),::toupper);
    cout << '\n';
    cout << "Name after transformation: " << name;

/*  First 2 args where to start and where to end
    3rd arg where to start placing the results
    4th arg what transformation function do you want to use
    Important note on ::toupper*/

/*  The :: without any name to the left of it tells the compiler to use the global namespace.
    This will use the toupper in the global namespace and not the one in std namespace.
    There are 2 different toupper functions.
    std::toupper and ::toupper which comes from C
    std::toupper is overloaded, so if we use it we have to use ugly casting to help the compiler resolve it.
    ::toupper keeps the code much cleaner.*/

    string name2 {"Peter Parker"};
    cout << "Name before transformation: " << name2 << '\n';
    transform(name2.begin(),name2.end(),name2.begin(),[](char c) {
        if (c != 127){
            return c + 1;}
            return -128;
    });
    cout << "After transformation: " << name2 << '\n';

}
int main(){
/*    Count_if_test();*/
    /*Replace_test();*/
/*    All_of_test();*/
    Transform_test();



    return 0;
}