//
// Created by Carlos Arbizu on 2/13/21.
//
#include <iostream>
using std::cout;
using std::endl;

int main(){
    /*C++ also allows us to overload the move assignment operator
    **This move operator works with R-value references (temporary unnamed objects)
    **MyString s1; (empty MyString object)
    **s1 = MyString {"Bob"}; (A temporary object is created for this unnamed object and it must be moved into s1)
    ** s1 = "Frank"
    **If we have a raw pointer in our class then using a user defined move .operator=(obj &&source)
    **allows for more efficiency
    */
    return 0;
}
