//
// Created by Carlos Arbizu on 10/16/21.
//
#include <iostream>
#include <queue>
#include <list>
template<typename T>
void display(std::queue<T> q){
    //Here we pass by value to avoid messing with our original data structure
    //Remember for queues and stacks we have to access the elements one by one then pop them off
    std::cout << "[";
    while(!q.empty()){
        if(q.front() == q.back()){
            std::cout << q.front();
        }
        else {
            std::cout << q.front();
            std::cout << ",";
        }
        q.pop();
    }
    std::cout << "] \n";
}
int main(){
    std::queue<int> q;
    std::queue<int,std::list<int>> q2; //We can make it a list alos
    //Queues follow a FIFO motto compared to stack's LIFO
    for(int i: {1,2,3,4,5}){
        q.push(i);
    }
    display(q);
    q.push(100);
    display(q);
    q.push(2000);
    display(q);
    q.pop();
    q.pop();
    display(q);

    std::cout << "Front: " << q.front() << '\n';
    std::cout << "Back: " << q.back() << '\n';

    return 0;
}