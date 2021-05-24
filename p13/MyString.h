//
// Created by Carlos Arbizu on 1/31/21.
//

#ifndef CPP_MYSTRING_H
#define CPP_MYSTRING_H

//This class is to practice operator overloading and use of raw pointers in the context of copy constructors and move constructors
#include <iostream>
class MyString {
private:
    char *ccstring{nullptr};
public:
    MyString(const MyString &source);
    MyString();
    /*Probably not best to make single argument constructors non-explicit because you can unintentionally call them
    **Great Stack Overflow answer to this problem: https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean/121163#121163x
     */
    MyString(const char *ccstring);

    ~MyString();

    void display() const;
    int getLength() const;
    char *get_str() const;

    MyString &operator=(const MyString &rhs);

    MyString &operator=(MyString &&rhs) noexcept;

    //Below are some unary operators overridden and overloaded using user defined code
    MyString operator-() const; //Returns lowercase MyString obj
    MyString operator+() const; //Returns uppercase MyString obj

    /*Return by value since it is a const function and we do not want to change the original value
    **A good rule that I read on is:
    **"Generally, an operator, whose result is a new value, must return, that new value, by value. An operator whose result is an existing value,
    **which modifies the value, must return, that modified value, by reference
    **For example, x + y should not change the value of x, so it is returned by value, since it makes a copy of the the result of x + y.
    **However, x += y changes the value of x and should be returned by reference, since it modifies the value of x. For the case of stringptr + stringptr,
    **the result is a new stringptr (both of the original strings are unchanged), so it must return by value,
    **otherwise you would be returning a reference to a temporary variable, which is considered undefine
     */

    friend MyString operator-(const MyString &lhs,const MyString &rhs);//removes similar alphanumeric characters from the left stringptr that are in the right stringptr
    //and replaces them with spaces
    //IMPORTANT NOTE: Friend functions can not use the *this pointer
    //Member functions always implicitly have a *this parameter while non member functions don't

    MyString operator+(const MyString &rhs) const; //combines the strings of 2 mystring objects
    /*
    **The second function requires that the left hand side is a MyString obj while the first function
    **doesn't essentially allowing you to add a stringptr literal to a MyString obj (with the help of implicit conversion done by
    ** the compiler)
    */

    bool operator==(const MyString &rhs) const;

    /* For stream insertion and extraction we must return by reference rather than by value
    **Good summary on why we must return by reference: The reason for using references with stream functions is to allow chaining,and also because using
    ** references allows the operator to assume the object exists (i.e. the caller is responsible for providing a valid reference, and the operator
    ** does not need to check for validity, like it would with a pointer) - Rob
    ** (stack overflow answer on this topic:
    ** https://stackoverflow.com/questions/28913009/why-we-need-to-return-reference-to-istream-ostream-while-overloading-and-o )
    */
    friend std::ostream &operator<<(std::ostream &ostream, const MyString &myStringobj);
    friend std::istream &operator>>(std::istream &instream,MyString &MyStringobj);
    friend MyString &operator+=(MyString &lhs, const MyString &rhs);
};
    #endif //CPP_MYSTRING_H
