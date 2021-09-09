//
// Created by Carlos Arbizu on 9/9/21.
//
#include <iostream>
using std::cout;
#include <sstream>
using std::string;
using std::ostringstream;

int main(){
    ostringstream oss;
    string name {"Pat"};
    int64_t num {100};
    double value {199.9};

    oss << name << " " << num << " " << value << "\n";
    cout << oss.str();
    return 0;
}