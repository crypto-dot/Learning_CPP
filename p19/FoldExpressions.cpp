//
// Created by Carlos Arbizu on 9/17/21.
//
#include <iostream>
using std::cout;
using std::boolalpha;
template<typename ... Args>
bool all(Args... args){return (...&&args);}
template<typename ...Args>
bool any(Args... args){return (...||args);}
template<typename ...Args>
bool none(Args... args){return (...&&!args);}
int main(){
    cout << "All of the args are true: "<< boolalpha << all(true,true,false) << "\n";
    cout << "Any of the args are true: " << any(true,false,false) << "\n";
    cout << "None of the args are true: " << none(true,false,false) << "\n";

}