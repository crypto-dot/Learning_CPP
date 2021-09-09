//
// Created by Carlos Arbizu on 7/21/21.
//
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <fstream>
using std::ifstream;
//Unformatted output of FilePractice2

int main(){
    char c;
    ifstream in_file {"FilePractice2.txt"};
    if(!in_file){
        cerr << "Problem opening file" << endl;
        return 1;
    }
    while(in_file.get(c)){
        cout << c;
    }


    return 0;
}