//
// Created by Carlos Arbizu on 11/30/20.
//

#include <iostream>
#include <vector>
#include <iomanip>
int main(){
    for(int i{1}; i <= 100; i++){
        std::cout << i  << ((i % 10 == 0) ?  "\n" : " ");
    }
    int scores [] {10,20,30,40,50};
    //use auto keyword to have c++ automatically assign the correct data type
    for(auto score : scores ){
        std::cout << score << "\n";
    }
    std::vector<double> temperatures {20.0,19.4,24.4,23.7,29.8};
    double total {};
    double avg {};
    for(auto temp : temperatures){
        total += temp;
    }
    avg = total/temperatures.size();
    std::cout << std::fixed << std::setprecision(2);
    //Sets the precision of double/ float values to 2

    std::cout << avg << std::endl;

    for(int value: {1,2,3,4,5}){
        std::cout << value << std::endl;
    }
    for(char c : "HELLO"){
        std::cout << c << std::endl;
    }
    for(char c: "String literal"){
        // if c does not equal a space char
        if(c!= ' '){
            std::cout << c << std::endl;
        }
    }
    return 0;
}