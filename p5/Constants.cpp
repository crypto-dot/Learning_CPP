//
// Created by Carlos Arbizu on 11/27/20.
//
#include <iostream>
int main(){
    //use the const to declare read only variables
    const int constant{4};
    // CONSTANT CHALLENGE
    const double sales_tax = 0.06;
    const double small_room_fee = 25;
    const double large_room_fee = 35;
    const int estimate_expir = 30;

    std::cout << "Estimate for carpet cleaning service " << std::endl;

    std::cout << "Number of small rooms: ";
    int number_of_small_rooms;
    std::cin >> number_of_small_rooms;

    std::cout << "Number of large rooms: ";
    int number_of_large_rooms;
    std::cin >> number_of_large_rooms;

    double cost = ((number_of_large_rooms * large_room_fee) + (number_of_small_rooms * small_room_fee));

    std::cout << "Price per small room: $" << small_room_fee << std::endl;
    std::cout << "Price per large room: $" << large_room_fee << std::endl;
    std::cout << "Cost: $" << cost << std::endl;
    std::cout << "Tax: $" << (cost * sales_tax) << std::endl;
    std::cout << "Total: $" << (cost + (cost * sales_tax)) << std::endl;



    return 0;
}
