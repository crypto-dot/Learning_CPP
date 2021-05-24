//
// Created by Carlos Arbizu on 12/7/20.
//

//The compilier must know information about a function
//They are typically used in heading files because
// FUNCTIONS MUST BE DEFINED BEFORE THEY ARE CALLED
// This is important for large files and/or large projects that use many files
// with many different functions

#include <iostream>

//FUNCTION HAS NO IDEA the size of the ARRAY IF U DONT SPECIFY IT
//HOWEVER IT CAN STILL MODIFY THE ELEMENTS WITHIN THE ARRAY
// SINCE ARRAYS ARE CALLED BY THEIR LOCATION IN MEMORY
// TO FIX THIS USE THE const data type
void print_array(const int array[],size_t value);
void print_string (const std::string &guest);
// (Technically this array is a constant pass by reference, meaning we cant change the value and the function is
// unable to change the values in the array (by default of course) )
// Functions make a copy of variables in order to manipulate them
// Thus changing the value of any variable within a function does not
// update the value of the variable UNLESS you specify this
// using the '&' symbol this symbol (called Pass by Reference)
// The compiler looks for the location of the variable given this symbol
// and passes it through the function possiblely allowing u to chang any value(s) to it
// Additonally, it is helpful to use this method for large vectors
// since they can typically take up a lot of resources copying and allocating
// memory. REMEMBER VECTORS ARE PASS BY VALUE DEFAULT NOT BY REFERENCE LIKE ARRAYS ARE !!
// We can use both the & and the const keyword to create datatypes that are pass by reference (not copied)
// and unable to be changed by accident
int test();
#include <string>
int main(){
    int array[5]{0,2,3,4};
    std::cout << test();


    return 0;
}
// Now we can call our function before even defining it !
int test(){
    return 2;
}
void print_array(const int array[],size_t value){
    for(int x {0}; x < value; x++){
        std::cout << x << std::endl;
    }
}