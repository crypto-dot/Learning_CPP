//
// Created by Carlos Arbizu on 12/9/20.
//

// To create a pointer use an astrik (*) on the data type or variable name
// Pointers point to the address of a specific function or variable
// This can allow objects or functions to access information outside of their scope
// IT IS VERY IMPORTANT to remember that pointers unintiliazed will point anywhere
// that means it can access any type of variable or function without you realizing it
// this it is important to initialize it to the nullptr
// as such
// int *int_ptr {nullptr}; (before we use)
// pointers can use the const keyword
// using the const keyword as seen below makes THE DATA that the pointer points to constant not the pointer itself
// const int *int_ptr {highscore}; //here we can still change the pointer but not the data pointed to
// int *const int_ptr // HERE WE CANNOT CHANGE THE POINTER however we can the data pointed to
// const int *const int_ptr // Here we cannot change the pointer nor the data pointed to by the pointer
// ****************************************************************************************************
// To create a function that returns a pointer see below
// NEVER RETURN A POINTER TO A LOCAL VARIABLE!!!
// Since the local variable is contained within the function as soon as the function ends and the stack is
// popped the local variable is deleted
// BELOW ARE SOME EXAMPLES OF WHAT NOT TO DO!!

// int *DONTDOTHIS(){
// int size {};
// return &size;
// }

// int *ORTHIS(){
// int size {};
// int *ptr{&size};
// return ptr;
// }

#include <iostream>
using std::cout;
using std::endl;
using std::string;

int *createArray(size_t size, int initial_value = 5){
    int *arryptr{nullptr};
    arryptr = new int[size];

    for(size_t i {0}; i < size; i++){
        arryptr[i] = initial_value;
    }
    return arryptr;
}
void displayArray(const int *const arryptr,size_t size){
    // POINTER ADDRESS IS CONST AND DATA IS CONST NONE CAN BE CHANGED
    for(size_t i {0}; i < size; i++){
        cout << arryptr[i] << endl;
    }
}
int main()
{

    int num {10};
    int *p;

    string Array[] {"Larry","Moe","Curly"};
    cout << "Garbage output since p was not intialized " << p << endl;
    cout << "Value of the address of p " << &p << endl;
    cout << "Size of p (also the amount of bytes an address can hold) " << sizeof(p) << endl;
    cout << "It is important to note that the size does NOT change for the datatype the datatype only indicates"
            " what values(double int etc.) that pointer points to." << endl;

    p = nullptr;
    cout << "Now the value of p since it was set to nullptr " << p << endl;
    //to set a pointer to a varialble it must be in the form of int *ptr = &variableName
    p = &num;
    cout << "The address where the num variable is stored is " << p << endl;
    int *arryptr = createArray(5,9);
    std::cout << "**************" << endl;
    displayArray(arryptr,5);


    return 0;


}