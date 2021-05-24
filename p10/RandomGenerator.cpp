//
// Created by Carlos Arbizu on 12/7/20.
//
#include <ctime> // THIS IS NEEDED for time()
#include <iostream>
#include <cstdlib> //THIS IS NEEDED for rand()
using std::cout;
using std::endl;



int main (){

    int random_number {0};
    size_t count {10}; //number of random numbers to generate between 1 and 6
    int min {1};
    int max {6};

    cout << "RAND_MAX on my system is " << RAND_MAX << endl; // LARGEST SIGNED INT POSSIBLE (FOR THIS SYSTEM ITS 32 BITS FOR OTHERS IT MAY BE AS LOW AS 16 BITS)
    srand(time(nullptr)); // SEEDING THE RANDOM NUMBER GENERATOR

    for(size_t i{1}; i < count; i++){
        random_number = rand() % max + min; //Generate a random number [min,max] we take the module of the max to give
        cout << random_number << endl;                                    // us values between 0 to 6 then add the min to it
    }


    return 0;
}
