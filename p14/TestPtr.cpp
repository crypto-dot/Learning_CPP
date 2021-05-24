//
// Created by Carlos Arbizu on 3/29/21.
//
#include <iostream>
using std::cout;
using std::endl;

int globalvar  = 3;
int *globalptr;
void func(int **const ptrptr){
    **ptrptr = 30; //derefernce twice the pointertopointer to hold an int
    *ptrptr = globalptr;       //derefernce once to change what pointer/reference it is pointing to
    *ptrptr = &globalvar;
}
void func2(int * &ptr){
   *ptr = 1000;
}
int main(){
    int var = 5;
    int *ptr = &var;

    int var2 = 10;
    int *ptr2 = &var2;

    func(&ptr);
    cout << globalvar << endl;

    cout << var << endl;

    func2(ptr2);
    cout << *ptr2 << endl;
    cout << var2 << endl;
    return 0;
}