//
// Created by Carlos Arbizu on 3/27/21.
//
#include <iostream>
using std::cout;
using std::endl;

class Base {
private:
    int value;
public:
    Base(const Base& other) : value{other.value} {
        cout << "Base copy constructor called" << endl;
        //Compile provided copy constructed would work fine here this is just to
        //show inheritance when dealing with copy constructors
    }
    Base() : value{0}{
        cout << "No args constructor called for base" << endl;
    }
    Base(int x) : value{x}{
        cout << "1 arg constructor called for base" << endl;
    }
    ~Base(){
        cout << "Destructor called for base" << endl;
    }
    int returnValue(){
        return value;
    }
    Base &operator=(const Base &rhs) {
        cout << "Base copy assignment operator called" << endl;
        if(this != &rhs) {
            value = rhs.value;
        }
        return *this;
    }

};

class Derived :public Base {
    //using Base::Base; Allows us to inherit all the nonspecial constructors
private:
    int ValueDoubled;
public:
    Derived() : ValueDoubled{0} {
        cout << "No args constructor called for derived" << endl;
    }
    Derived(int x) :Base(x), ValueDoubled{x * 2} /*optional initializers for base */ {
        cout << "1 args constructor called for derived" << endl;
    }
    ~Derived(){
        cout << "Destructor called for derived class " << endl;
    }
    Derived(const Derived& other) : Base(other), ValueDoubled{other.ValueDoubled} {
        cout << "Copy constructor called for the derived Object" << endl;
        //Base part of the derived object will be 'spliced' and used for the copy
        //constructor of the base
    }
    Derived &operator=(const Derived &rhs) {
        cout << "Derived copy assignment operator called" << endl;

        if(this != &rhs){
            Base::operator=(rhs); //Calling the base class overloaded assignment operator
            ValueDoubled = rhs.ValueDoubled;
        }


        return *this;
    }

};

int main(){

  /*  Base base; */ //(calls the Constructor and destructor of base)
  /* Derived derived; */ //(calls the constructor of base the then the constructor of
    //derived after the object derived goes out of scope the destructor for it is
    /*Derived derived;*/
    Derived derived1(1000);  //Normally this would only call the special constructors
    //of the base class (in this case the no args constructor of the base), but if you implement
    // the class with 'using Base:Base;' then the compilier will use the Base 1 args constructor
    // IF there is no other corresponding constructor for the derived class

    Derived derived2(derived1);

    cout << derived2.returnValue() << endl;
    return 0;
}