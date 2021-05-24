//
// Created by Carlos Arbizu on 1/22/21.
//

//Structs are just like classes and they allow for compatibility between c and c++
//One difference between structs and classes are the fact that data members of classes
// are private by default while they are public by default in structs
//When to use structs vs classes:
//Structs:
//*Passive objects with public access
//*Don't declare methods in structs
//Classes:
//*Use class for active objects with private access
//*implement getters/setters as needed
//*implement member methods as needed
#include <string>
using std::string;
struct person{
    string name; //Public
};