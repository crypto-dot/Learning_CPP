//
// Created by Carlos Arbizu on 1/5/21.
//

//Move Constructor/semantics:
//Sometimes when we execute code the compilier creates temporary values

//int total {0};
//total = 100 + 200;
//Here 100 + 200 is calculated then stored in a temporary unnamed value
//the 300 is then stored in total variable
//then the temp value is discarded

//When we have objects that are being copied temporary unnamed values are sometimes used
// The overhead of these objects can be too costly

// R value objects are the objects that move value semantics addresses

//* Sometimes copy constructors are called many times automatically due to the copy semantics of c++
//* Copy constructors doing deep copying can have a significant performance bodyneck
//* C++11 introduced move semantics and move constructors
//* Move constructor moves an object rather than copying it
//* Optional but it is recommended when you have a raw pointer
//* Copy elision - C++ may optimize copying away completely (RVO- Return Value Optimization)
// R Value References:
// * Used in move semantics and perfect fowarding
// * Move semantics is all about r-value references
// * Used by move constructor and move assignment operator to efficiently move an object rather
// than copying it
// *R-value operator (&&) (This differs from L-value operator (&))

//void func(int &num) //A function like this expects an l value (addressable value)
//void func(x) //THIS IS OK
//void func(200) //NOT OK
//We can overload the function as such:
//void func(int &x);
//void func(int  &&x);
//*********************Move Constructor***********************
//Why use a move constructor ?
//sometimes in your code the compiler will generate a temporary object to execute your code
//For example :
// std::vector<A> objLst;
// objLst.pushback(A(10))
//Here there is a temporary object A being created
//Now c++ will copy all the content from the obj (A(10)), create a temp. obj
// and put it into objLst then deconstruct both the A(10) and the temp. obj made out of A(10)
//This is very inefficient and can be done by using a move constructor that nulls out the source
// and the temporary obj "steals" the data for use
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class obj{
private:
    int *data;
public:
    explicit obj(int num);
    obj(const obj &source);
    obj(obj &&source) noexcept;
    ~obj();
};
obj::obj(int num) : data{new int} {
    *data = num;

}
obj::obj(const obj &source) : obj{*source.data}{
    cout << "Deep copy constructor called for " << *source.data << endl;
}
obj::obj(obj &&source)  noexcept : data(source.data) {
    cout << "Move constructor called for " << *source.data << endl;
    source.data = nullptr;

}
obj::~obj(){
    if(data == nullptr){
        cout << "Calling destructor for null" << endl;
    }
    else {
        cout << "Calling destructor for " << *data << endl;
        delete data;
    }
}
int main(){
    int x{100};
    int &l_ref = x; // L-value reference (is addressable)
    l_ref = 10; // x is now 10

    int &&r_ref = 300; // R-value reference (is not addressable)
    r_ref = 500;    //change r_ref to 500

   // int &&x_ref = x; compiler error

    vector<obj> objlist;
    objlist.push_back(obj(30));
    //here the object list is creating a temporary object then copying that object to the vector
    //while it may not seem too bad at first it can get out of hand when the vector container
    // is continously growing and the objects need to be recopied to the new vector container to
    //account for size changes (as seen below)
    objlist.push_back(obj(50));
    objlist.push_back(obj(60));
    objlist.push_back(obj(70));
    objlist.push_back(obj(80));
    objlist.push_back(obj(90));

    return 0;
}