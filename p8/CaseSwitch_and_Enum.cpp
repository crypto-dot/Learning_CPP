//
// Created by Carlos Arbizu on 11/29/20.
//
#include <iostream>
// IF ENUM
int main(){
    //Enums are used only when we expect the variable to have one of the possible set of values,
    // for example, we have a dir variable that holds the direction.
    // Since we have four directions, this variable can take any one of the four values,
    // if we try to assign a another random value to this variable, it will throw a compilation error.
    // This increases compile-time checking and avoid errors that occurs by passing in invalid constants.

    //***************************************************************************************************

    //Every name in an enumeration is assigned an integral value that corresponds to
    // its place in the order of the values in the enumeration.
    // By default, the first value is assigned 0, the next one is assigned 1, and so on,
    // but you can explicitly set the value of an enumerator, as shown here:
    enum Suits{
        Diamond = 1, Hearts, Club, Spades
    };
    //enum Suit { Diamonds = 5, Hearts, Clubs = 4, Spades };
    // if this was put in the code hearts would be 6 and spades would be 5
    Suits card_suit{Spades};
    //below is a possible example using switch and enum
    switch (card_suit) {

        case Diamond:
            break;
        case Hearts:
            break;
        case Club:
            break;
        case Spades:
            {
            int num;
            num = card_suit;
            std::cout << num;
            break;
             }
        default:
            std::cout << "error";
            break;
    }
}

