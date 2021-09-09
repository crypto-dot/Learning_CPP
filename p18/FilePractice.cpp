//
// Created by Carlos Arbizu on 7/11/21.
//
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
#include <iomanip>
using std::setw;
int main(){

    ifstream in_file{"FilePractice.txt"};
    string word;
    int num;
    double num2;

    if(!in_file){
        cerr << "Problem opening file" << endl;
        return 1; //exit(1) or return -1 can be used when exit(1) is used it calls a function that wraps up everything (aka destroys local variables and cleans the memory)

    }
    cout << "File is good to go"<< endl;
/*    while(!in_file.eof()) {
        in_file >> word >> num >> num2;
        cout << std::fixed << std::setprecision(2) << setw(10) << word;
        cout << setw(10) << num2;
        cout << setw(10) << num << endl;
    }*/
//Another more efficient way to write the above code
    while(in_file >> word >> num >> num2) {
        cout << std::fixed << std::setprecision(2) << setw(10) << word;
        cout << setw(10) << num2;
        cout << setw(10) << num << endl;
    }
    in_file.close();

    return 0;
}