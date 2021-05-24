//
// Created by Carlos Arbizu on 11/27/20.
//
#include <iostream>
#include <climits>
#include <cfloat>
// CLIMIT and CFLOAT allow you to get the minimum and maximum values for data types
int main (){
    //Char datatype
    char middleInitial{'a'};
    std::cout << "My middle intial is " << middleInitial << std::endl;
    //Signed short integers (many different ways to write them
    // short integers are at least 16 bits and at most 16 bits
    short int integer1 {2};
    short integer2 {2};
    signed short int integer3 {2};

    // Integers are at least 16 bits and at most 32 bits
    signed int integer4 {2};
    int integer5 {2};
    signed integer6 {2};
    // The above examples are signed
    unsigned int integer7 {2};
    unsigned integer8{2};

    //Long ints are at least 32 bits and at most 64 bits
    long int integer9{2};
    long signed int integer10{2};
    signed long integer11{2};
    long integer12{2};
    //The above examples are signed
    unsigned long integer13{2};
    unsigned long int integer14{2};

    // Long long ints are at least 64 bits and at most 64 bits
    long long int integer15{2};
    signed long long int integer16{2};
    signed long long integer17{2};
    long long integer18{2};
    // The above examples are signed
    unsigned long long int integer19{2};
    unsigned long long integer20{2};

    //Char is represented in 8 bits
    char character {'8'};
    //wchart is large enough to represent any supported character code point
    // (32 bits on systems that support Unicode.
    // A notable exception is Windows, where wchar_t is 16 bits and holds UTF-16 code units)
    // It has the same size, signedness, and alignment as one of the integer types, but is a distinct type.
    wchar_t character1 {'s'};
    //Char16_t represents 16 bit
    char16_t character2 {'s'};
    //Char32_t represents 32 bit
    char32_t character3 {'2'};

    // USING sizeof will allow u to find the size of the specific variable or data type on a certain compiler or machine

    std::cout << sizeof(int) << " Size of int in bytes" << std::endl;
    std::cout << sizeof(long int) << " Size of long int in bytes" << std::endl;

    std::cout << "Minimum values" << std::endl;
    std::cout << "char " << CHAR_MIN << std::endl;
    std::cout << "short " << SHRT_MIN << std::endl;
    std::cout << "int " << INT_MIN << std::endl;
    std::cout << "long " << LONG_MIN <<std::endl;

    std::cout << "Maxmium values" << std::endl;
    std::cout << "char " << CHAR_MAX << std::endl;
    std::cout << "short " << SHRT_MAX << std::endl;
    std::cout << "int " << INT_MAX << std::endl;
    std::cout << "long " << LONG_MAX <<std::endl;

}
