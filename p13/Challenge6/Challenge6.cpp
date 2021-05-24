//
// Created by Carlos Arbizu on 3/5/21.
//
#include "MyStringMemberOnly.h"
#include "MyStringNonMember.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

int main(){
    MyStringMemberOnly string {"hello"};
    MyStringMemberOnly string1 {"Hello"};
    MyStringMemberOnly stringMemberOnly = string * 3;
    if(string == string1){
        cout << "The strings are equal" << endl;
    }
    else {
        cout << "The strings are not equal "  << endl;
    }


    string << cout << endl;
    //This is odd and not recommended for this operator
    //Remember this operator << was overloaded as a member method (rather than a nonmember) so the this pointer
    // is an implicit parameter and MyStringMemberOnly MUST go to the left of cout and endl
    //again it is not recommended to implement these methods like this because it will confuse others.
    cout << "Enter a character for the MyStringMemberOnly object: ";
    string >> cin; //Same as above
    string << cout << endl;
    -string << cout << endl;
    string << cout << endl;
    string += string1;
    string << cout << endl;

    string * 3 << cout << endl;
    //______________________NON MEMBER MYSTRING CLASS__________________________-
    char *testptr = nullptr;
    MyStringNonMember test {testptr};
    MyStringNonMember test1 {"Hello"};
    MyStringNonMember test2 {"Hi"};
    MyStringNonMember test3 {"Look"};

    cout << test << endl;
    test = -test2;
    cout << test2 << endl;
    cout << test << endl;
    test1+=test2+=test3;
    //Returning Objects by value or by references allows us to chain functions
    //Remember to return either by value (if you are adding,subtracting,dividing, or mulitplying) or by reference (if
    // you are using -= and +=) if you want to chain functionsx

    cout << test1 << endl;
    cout << test1 - test3 << endl;
    cout << test3 * 3 << endl;

    return 0;
}