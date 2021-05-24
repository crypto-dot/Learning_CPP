//
// Created by Carlos Arbizu on 1/5/21.
//

//Deep copy:
//Create a copy of the pointed to data
//Each copy will have a pointer to unique storage in the heap
//Deep copy when you have raw pointers
#include <iostream>
using std::cout;
using std::endl;

class Deep{
private:
    int *data{nullptr};
public:
    Deep(int num) : data{new int}{
        *data = num;
    }
    ~Deep(){
        delete data;
        cout << "destructor called " << endl;
    }
    Deep(const Deep &source) : Deep{*source.data}{
        // This code can be simiplifed using constructor delegation
       // data = new int;
       // *data = *source.data;

    }
};
int main(){

    return 0;
}