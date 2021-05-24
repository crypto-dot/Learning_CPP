//
// Created by Carlos Arbizu on 12/30/20.
//

//Class members can be implemented in a couple of different ways
//They can be implemented inside the class declaration (implemented inline)
//or outside (using Class_name::method_name)
//.h file can be used for class declaration
//.cpp file can be used for class implementation

#include <string>
using std::string;
class Person{
private:
    int age;
    string name;
    const int SSN;

public:
    int getAge(){
        return age;
    }
    string getName(){
        return name;
    }
    int getSSN();
};

int Person::getSSN(){
    return SSN;
}
//cpp class declaration with outside class implementation
int main(){




    return 0;
}