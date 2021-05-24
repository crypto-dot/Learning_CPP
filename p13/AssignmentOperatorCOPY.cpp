//
// Created by Carlos Arbizu on 2/10/21.
//

#include <iostream>
#include "MyString.h"

int main(){
    //Don't confuse assignment with initialization
    MyString string {"Jack"};
    MyString& stringcopy = string; //THIS IS INITIALIZATION NOT ASSIGNMENT

    stringcopy = string; //This would be assignment
    //The default behavior for assignment is memberwise assignment (shallow copy)
    //If you class contains raw pointers you will need to overload the assignment operator for it to work properly
    //If a user defined operator= method is declared the above statement will be converted (behind the scenes)
    //to stringcopy.operator=stringptr (that calls the user defined operator= method)




    return 0;
}