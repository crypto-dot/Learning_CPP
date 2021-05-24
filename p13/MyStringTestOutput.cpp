//
// Created by Carlos Arbizu on 2/6/21.
//
#include "MyString.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;
int main() {
    MyString empty;
    cout << empty.get_str() << endl;
    MyString string{"Hello"};
    const MyString &stringcopy{string};


    cout << string.get_str() << endl;
    cout << stringcopy.get_str() << endl;

    MyString newstring{"fred"};
    MyString newstringcopy;
    newstringcopy = newstring;
    MyString newstring1{"dave"};
    MyString newstring2{"larry"};
    MyString newstring3{"megan"};
    vector<MyString> mystringlist{newstring, newstringcopy, newstring1, newstring2, newstring3};

    for (const MyString &str : mystringlist) {
        cout << str.get_str() << endl;
    }

    MyString difference{newstring2 - newstring3};
    cout << difference.get_str() << " is the difference and the length is " << difference.getLength() << endl;

    if (newstring == newstring1 || newstring == newstringcopy) {
        cout << "The strings are equal " << endl;
    } else {
        cout << "The strings are not equal " << endl;
    }
    //Overloaded insertion operator;
    cout << newstring << endl;
    //Overloaded extraction operator;
    MyString extraction_operator;
    cout << "Please insert a stringptr to create a MyString object: ";
    cin >> extraction_operator;
    cout << endl;


    MyString stringtest{"Use of "};
    MyString stringtest2("+= operator.");
    stringtest += stringtest2;
    cout << "Test output: " << stringtest << endl;
    stringtest += " Also with a stringptr literal.";
    cout << stringtest << endl;

     MyString stringtest3 = stringtest - "Use of ";
     //MyString stringtest3 = "use of " - stringtest;
     cout << "Test output: " << stringtest3 << endl;


    return 0;

}
