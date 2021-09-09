//
// Created by Carlos Arbizu on 8/1/21.
//
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <string>
using std::string;
#include <iomanip>
using std::setw;
#include <fstream>
using std::ofstream;
using std::ifstream;
int main(){
    ifstream in_file{"RomeoAndJuilet.txt"};
    ofstream out_file{"RomeoAndJuiletCopy.txt"};
    string line;
    size_t counter {1};
    if(!in_file){
        cerr << "Unable to open input file.";
        return 1;
    }
    if(!out_file){
        cerr << "Unable to create an output file. ";
        return 1;
    }

    while(getline(in_file,line)){
        if(line.empty()){
            out_file << line << "\n";
            continue;
        }
        out_file << setw(5) << counter << "     ";
        out_file << line << "\n";
        counter++;
    }
    cout << "File successfully copied! \n";
    in_file.close();
    out_file.close();

    return 0;
}