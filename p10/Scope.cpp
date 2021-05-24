//
// Created by Carlos Arbizu on 12/8/20.
//



// LOCAL VARIABLES CAN ONLY BE SEEN WITHIN THE {} BLOCK THEY ARE DECLARED IN
// Function local variables are only active while the function is executing
// They are not preserved in between function calls
// There is one exeception
// Static local variables' lifetime is the time of the program
// static local variables in functions also do not get reinitialized every time the function is called
// unlike local variables
// global variables can be seen by all parts of the program
// Don't use global variables use global constants
// ****************************************************************************************************************

//Functions use the 'function call stack'
//LIFO -Last in First out like placing dishes on a counter and taking the top dishes (the last ones to be placed)
// and using them
// Push and pop methods are used
// Stack Frame/ Activation Record
// Functions must return to function that called it
// Each time a function is called we create a new activation record and push it on stack
// When function terminates we pop the actvation record and retrun
// Local variables and function parameters are allocated on the stack
/*
 * How memory is stored
 *
 * ______________________________________________
 * |                                            |
 * |                                            |
 * |                                            |
 * |                                            |
 * |               Heap                         |
 * |               Free Store                   |
 * |                                            |
 * |                                            |
 * |                                            |
 * |                                            |
 * |                                            |
 * |                                            |
 * |                                            |
 * |____________________________________________|
 * |                                            |
 * |                                            |
 * |                         |       ^          |
 * |                         |       |          |
 * |           Stack         |       |          |
 * |                         v       |          |
 * |                                            |
 * |                                            |
 * |                                            |
 * |____________________________________________|
 * |                                            |
 * |          Static Area                       |
 * |____________________________________________|
 * |                                            |
 * |                                            |
 * |           Code Area                        |
 * |                                            |
 * |                                            |
 * |____________________________________________|
 *
 *
 *
 *
 */
// Recursive functions need a base case and a recusive case
unsigned long long factorial(unsigned  long long n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}
unsigned long long fib(unsigned long long n){
    if(n <= 1 ){
        return n;
    }    // IF N IS 1 OR 0 THIS STOPS THE FUNCTION

    return fib(n -1) + fib(n -2);


}
#include <iostream>
using std::cout;
using std::endl;
inline int add(int a, int b){
    return a + b;
}

void func2(int &x,int y, int z){
    x += y + z;
}
int func1(int a, int b){
    int result {};
    result = a+b;
        func2(result,a,b);
        return result;
}
int main(){
    int val {100};  //local to main
    int val2 {200}; // local to main
    int x {10};
    int y {20};
    int z {};
    z = func1(x,y);
    cout << z << endl;
    /* What typically happens when main calls func1(or any function calls another).
     * There are other ways to achieve the same result.
     * main:
     * push space for the return value.
     * push space for the parameters.
     * push the return address. (tells where func1 should come back to)
     * transfer control to func1(jmp).
     * func1:
     * push the address of the previous activation record (moves a stack point so it knows where the top of the stack is
     * push any register values that need to be restored before returning to the caller.
     * perform the code in func1
     * restore the register values
     * restore the previous activation record (moves the stack pointer)
     * store any previous function result
     * transfer control to the return address (jmp (main in this case))
     * main:
     * pop the parameters
     * pop the return values
     * ------------------------------------------------------------------------------
     * Since this process can create a lot of overhead we can inline functions
     * inline functions generate assmebly code
     * avoid function call overhead
     * faster
     * but can cause code bloat




    */
    {
        int val{123};
        //The compilier will look for the closest variable within the scope
        cout << val << endl;
        cout << "Inner scope can see outer scope value of variable outside of this scope is " << val2 << endl;
    }

    cout << val << " is the value of the nearest variable in the local scope." << endl;
}