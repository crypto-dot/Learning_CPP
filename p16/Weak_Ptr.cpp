//
// Created by Carlos Arbizu on 5/9/21.
//
#include <iostream>
#include <memory>
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::cout;
using std::endl;

class B; //forward declaration since we have to put the shared_ptr<B> in A similar to function prototypes
class A{
private:
    shared_ptr<B> b_ptr{nullptr};
public:
    void set_ptr(const shared_ptr<B> &Bptr){
        b_ptr = Bptr;
    }
    A(){
        cout << "A constructor called"<< endl;
    }
    ~A(){
        cout << "A destructor called" << endl;
    }
};
class B{
private:
    weak_ptr<A> a_ptr; //Weak pointer is needed here
public:
    void set_ptr(const shared_ptr<A> &aptr){
        a_ptr = aptr;
    }
    B(){
        cout << "B constructor called"<< endl;
    }
    ~B(){
        cout << "B destructor called" << endl;
    }
};
int main(){
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_ptr(b);
    b->set_ptr(a);
    cout << a.use_count() << endl;
    return 0;
}