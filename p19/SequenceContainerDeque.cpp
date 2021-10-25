//
// Created by Carlos Arbizu on 9/18/21.
//
#include <deque>
#include <iostream>
using std::cout;
using std::deque;
#include <algorithm>
using std::back_inserter;
using std::front_inserter;
using std::copy;
template<typename T>
void display(const deque<T> &deq){
    cout << "[ ";
    for(const T &val : deq){
        if(&val == &(deq.back())){
            cout << val << " ";
        }
        else {
            cout << val << ", ";
        }
    }
    cout << "] ";
}
void test1(){
    deque<uint64_t> deque1 {1,2,3,4,5};
    display(deque1);
    cout << "\n";
    deque<uint64_t> deque2 (10,5);
    display(deque2);
}

void test2(){
    deque<int64_t> deque1 {1,2,3,4,5,67,8};
    deque<int64_t> deque2 {23,34,84,21,9};

    cout << "Deque1: ";
    display(deque1);
    cout << "\n";
    deque1.pop_back();
    cout << "Deque1: ";
    display(deque1);
    cout << "\n";
    deque1.push_front(5);
    cout << "Deque1: ";
    display(deque1);
    cout << "\n";
    deque1.pop_front();
    cout << "Deque1: ";
    display(deque1);
    cout << "\n";
    cout << "Front: " << deque1.front();
    cout << "\n";
    cout << "Back: " << deque1.back();
    cout << "\n";
    cout << "Size: " << deque1.size();
}
void test3(){
    deque<uint64_t> deque1 {1,2,3,4,5,6,7,8,9,10};
    deque<uint64_t> deque2;
    for(const auto &element : deque1){
        if(element %2 ==0){
            deque2.push_back(element);
        }
        else{
            deque2.push_front(element);
        }
    }
    cout << "Deque2: ";
    display(deque2);
    cout << "\n";

}
void test4(){
    deque<uint64_t> deque1{1,2,3,4,5,6,7,8,9,10};
    deque<uint64_t> deque2;
    cout << "Deque1 (Elements to be copied): ";
    display(deque1);
    cout << "\n";

    copy(deque1.begin(),deque1.end(),back_inserter(deque2));
    cout << "Deque2 (With elements copied from deque1(using back_inserter) ): ";
    display(deque2);
    cout << "\n";

    deque2.clear();

    copy(deque1.begin(),deque1.end(),front_inserter(deque2));
    cout << "Deque2 (With elements copied from deque1(using front_inserter) ): ";
    display(deque2);
    cout << "\n";
}
int main(){
/*
    test1();*//*
test2();*/
/*    test3();*/
test4();
    return 0;
}