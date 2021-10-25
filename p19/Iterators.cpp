//
// Created by Carlos Arbizu on 9/11/21.
//
#include <iterator>
#include <list>
using std::list;
#include <map>
using std::map;
#include <set>
using std::set;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
#include <string>
using std::string;

void test1(){

    std::vector<uint64_t> vector{1, 3, 5, 9};

    auto it {vector.begin()};

    cout << *it++ << "\n"; //prints 1 then post increments
    cout << *it++ << "\n"; //prints 3 then post increments
    cout << *(it-=2) << "\n"; //1
    cout << *(it+=2) << "\n"; //prints 5
}

void test2(){
    std::vector<uint64_t> vector{1, 3, 5, 9};

    auto it {vector.begin()};
    while(it != vector.end()){
        std::cout << *it++ << "\n";
    }
    it = vector.begin();
    while(it != vector.end()){
        *it = 0;
        std::cout << *it++ << "\n";
    }
}

void test3(){
    std::vector<uint64_t> vector{1, 3, 5, 9};
    auto it{vector.cbegin()};
    while(it != vector.cend()){
        std::cout << *it++ << "\n";
    }
    //Constant iterators prevent you from changing the value of the elements in the container
}

void test4(){
    std::vector<uint64_t> vector{1, 3, 5, 9};
    auto it = vector.rbegin();
    while(it != vector.rend()){
        cout << *it++ << "\n";
    }
}

void test5(){
    list<string> names{"Larry","Moe","Curly"};

    auto it  {names.rbegin()};
    cout << *it << "\n";
    it++; //go to Moe (go back 1)
    cout << *it << "\n";

    map<string,string> stringPairs {
            {"Frank","C++"},
            {"Matt","C"},
            {"Kim","Java"}

    };



    for(auto it1 {stringPairs.begin()};it1 != stringPairs.end(); ++it1){
        cout << it1->first << " " << it1->second << "\n";
    }

}

void test6(){
    //iterating over a subset in a container
    std::vector<uint64_t> vector{1, 2, 3, 4, 5, 6};
    auto start = vector.begin() + 2;
    auto finish = vector.end() -1;
    //Note vector.end() is not pointing to the last element in vector
    while(start != finish){
        cout << *start++ << "\n";
    }

}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();



    return 0;
}