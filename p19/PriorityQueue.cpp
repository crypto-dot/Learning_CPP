//
// Created by Carlos Arbizu on 10/16/21.
//
#include <cstdint>
#include <string>
#include <iostream>
#include <queue>
class Person{
public:
    Person() : age{0},name {"n\a"}{}
    Person(std::string name,uint64_t age) : age {age},name{std::move(name)}{}
    friend bool operator==(const Person &lhs, const Person &rhs) {
        return lhs.name == rhs.name;
    }
    friend bool operator<(const Person &lhs,const Person &rhs){
        return lhs.age < rhs.age;
    }
    friend std::ostream &operator<<(std::ostream &ostream1,const Person &person){
        ostream1 << " Name: " << person.name << " Age: " << person.age;
        return ostream1;
    }

private:
    uint64_t age;
    std::string name;
};
template<typename T>
void display(std::priority_queue<T> q){
    //Again pass by value is necessary to retain invariance
    std::cout << "[";
    while(!q.empty()){
        if(q.size() == 1){
            std::cout << q.top();
        }
        else {
            std::cout << q.top() << ",";
        }
        q.pop();
    }
    std::cout << "] \n";
}
int main(){
    std::priority_queue<int> q; //vector by default
    for(int i : {1,2,3,4,5,6,20,19,18,17,16,15,14,10,9,8,7,12,11}){
        q.push(i);
    }
    display(q);

    std::priority_queue<Person> q2;
    q2.push(Person("A",33));
    q2.push(Person("B",10));
    q2.push(Person("C",44));
    q2.push(Person("D",99));
    q2.push(Person("E",111));
    display(q2);

    return 0;
}