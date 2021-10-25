//
// Created by Carlos Arbizu on 10/12/21.
//
#include <stack>
#include <iostream>
#include <deque>
#include <list>
#include <vector>

template <typename T>
void display(std::stack<T> stak){
    std::cout << "[";
    //We can't use iterators for stacks
    //We must pop each element (remove) it
    //This is also the reason why we pass the stack by value
    while(!(stak.empty())){
        T element = stak.top();
        std::cout << element << " ";
        stak.pop();
    }
    std::cout << "]";
}

int main(){
    std::stack<int> s;
    std::stack<int,std::deque<int>> s1;
    std::stack<int,std::list<int>> s2;
    std::stack<int, std::vector<int>> s3;

    for(int i: {1,2,3,4,5}){
        s.push(i);
    }
    display(s);
    s.push(100);
    display(s);
    s.pop();
    s.pop();
    display(s);
    while(!s.empty()){
        s.pop();
    }
    display(s);
    std::cout << "Size of stack: " << s.size() << '\n';
    s.push(5);
    display (s);
    s.top() = 100;
    display(s);


    return 0;
}