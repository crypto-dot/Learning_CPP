//
// Created by Carlos Arbizu on 7/18/21.
//
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;

int main(){
    string line;
    ifstream in_file {"FilePractice2.txt"};
    while(getline(in_file,line)){
        cout << line << endl;
    }

    in_file.close();
    return 0;
}