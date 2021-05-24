//
// Created by Carlos Arbizu on 1/5/21.
//

//Shallow Copy :
// The default copy constructor uses a shallow copy
// The pointer is copied NOT what it points
// Problem: When we release the storage in the destructor, the other object still refers to the
// released storage!!
#include <iostream>
using std::cout;
using std::endl;
//Below is an example of WHAT NOT to do:
class Shallow{
private:
    int *data{nullptr};
public:
    //constructors
    Shallow(int num) : data{new int}{
        *data = num;
    }
    Shallow(const Shallow &source) : data{source.data}{
        cout << "Copy Constructor called - shallow " << endl;

    }
    //destructor
    ~Shallow(){
        cout << "Destructor called" << endl;
    }
    //get
    int getData(){
        return *data;
    }
    void setData(int num){
        *data = num;
    }

};
//Here only the pointer is copied not what it is pointing to !
//Both source and the new object created from source is pointing to the same data
void DisplayShallow(Shallow obj){
    cout << obj.getData() << endl;
    //The copy has a pointer pointing to the same data address as obj1

} //copy gets destroyed the pointer and the memory it is pointing to is gone
int main(){
    Shallow obj1(5);
    DisplayShallow(obj1);
    //HERE SHALLOW OBJECT'S DATA HAS BEEN RELEASED!

    Shallow obj2(obj1);
    //A copy is made of the data that obj1 has however it has been deleted
    //this type of bug does not always result in crashes, so it is very hard to detect
    //all of this could have been avoided with a deep copy
    cout << obj2.getData() << endl;



    return 0;
}