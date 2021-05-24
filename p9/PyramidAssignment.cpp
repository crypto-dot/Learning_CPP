//
// Created by Carlos Arbizu on 12/6/20.
//
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    string input {};
    size_t Amount_of_spaces {};
    size_t endingIndex {};

    cout << "Enter a string to make a pyramid out of: "; cin >> input; cout << endl;
    cout << endl;
    Amount_of_spaces = input.length();
    endingIndex = 0;
    for(size_t i {0}; i < input.length(); i++){
        for(size_t j {0}; j < Amount_of_spaces ; j++){
            cout << " ";
        }
        Amount_of_spaces--;
        for(size_t k {0}; k <= endingIndex; k++){
            cout << input[k];
        }
        if(endingIndex != 0){
            for(int l{static_cast<int>(endingIndex - 1)}; l >= 0;l--){
                cout << input[l];
            }
        }
        endingIndex ++;
        cout << endl;
    }





    return 0;
}
