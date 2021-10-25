//
// Created by Carlos Arbizu on 9/9/21.
//
#include <iostream>
using std::cout;
using std::string;

template <typename T>
T max(const T &a,const T &b) {
    return (a > b) ? a : b;
}

template <typename T2,typename T1>
void func(const T1 &a,const T2 &b){
    cout << a << " " << b << "\n";
}
//Allows for different types (or the same)
int main(){

    string name1 {"Test"};
    string name2 {"test"};
    cout << max(3.08,3.0);

    func(name2,name1);
    func(3.4,name1);

    return 0;
}