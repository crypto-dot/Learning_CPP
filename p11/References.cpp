//
// Created by Carlos Arbizu on 12/26/20.
//
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
    string Array[]{"Curly","Moe","Larry"};
    //This for loop will not change the variable since it is a copy of the
    // stringptr variables in Array
    for(string str : Array){
        str = "funny";
    }
    //To overcome this we use the actual variable value instead of the copies
    // behind the scenes it's a pointer that has been abstracted
    for(string &str : Array){
        str = "funny";
        //now we change the value
    }
    for(string const &str : Array){
        cout << str << endl;
    }

    int num {100};
    int &ref {num};
    //here ref acts like a pointer to number
    // it will automatically be dereferenced when used
    // and will automatically change the value of num and be changed when the value of num is updated.
    cout << num << " is the value of num" << endl;
    cout << ref << " is the value of ref" << endl;
    num = 200;

    cout << num << " is the value of num after num was updated" << endl;
    cout << ref << " is the value of ref after the value of num was updated" << endl;
    ref = 300;

    cout << num << " is the value of num after ref was updated" << endl;
    cout << ref << " is the value of ref after the value of ref was updated" << endl;


    return 0;
}