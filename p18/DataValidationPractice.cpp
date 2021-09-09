//
// Created by Carlos Arbizu on 9/9/21.
//
#include <sstream>
using std::istringstream;
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::numeric_limits;
int main(){
    string response;
    int64_t value;
    bool done {false};

    do {
        cout << "Please input the integer you want the value to be: ";
        cin >> response;
        cout << "\n";
        istringstream iss {response};
        if(iss >> value){
            cout << "A integer was entered! The value was: " << value <<"\n";
        }
        else {
            cout << "An integer was not entered!";
            done = true;
        }
       cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
    }
    while(!done);

    return 0;
}