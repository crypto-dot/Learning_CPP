//
// Created by Carlos Arbizu on 12/4/20.
//
#include <cstring> //for c style stringptr function
#include <cctype> //for character based functions
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

int main(){
    char last_name [30] {};
    char first_name [30]{};
    char full_name[30] {};
    char full_name2[30] {};
    char temp[50] {};

    cout<< "Enter your first name: "; cin >> first_name; cout << endl;
    cout << "Enter your last name: "; cin >> last_name; cout << endl;

    cout << "The length of your first name is " << strlen(first_name) << " and last name is " << strlen(last_name) << endl;
    strcpy(full_name,first_name); //copy first name to full name
    strcat(full_name, " "); // Add a space
    strcat(full_name,last_name); // Add the last name to full name
    cout << "Your full name is " << full_name << endl;
    cin.ignore();
    //WE MUST USE THE IGNORE METHOD SINCE THE LINE ABOVE USES ENDL/ "\N" BECAUSE CIN WILL READ IT AS AN INPUT
    cout << "Enter your full name: "; cin.getline(full_name,50);
    //another way to write getline is cin.getline(full_name,'x'); it uses 'x' char as a delimiter
    // In order to accomplish allowing spaces we have to use cin.getline()
    // The number indicates how many character to stop reading at
    for(size_t i {0}; i < strlen(full_name); i++){
        if(isalpha(full_name[i])){
            full_name[i] = toupper(full_name[i]);
        }
    }
    cout << full_name;

    std::string s1;  //empty
    std::string s2{"frank"}; //frank
    std::string s3{s2}; //frank
    std::string s4{"frank",3}; //fra
    std::string s5{"frank",0,3}; //2nd arg is pos 3rd arg is length
    std::string s6(3,'x')//Constructor syntax creates a stringptr with 3 Xs
    std::string s7{"C++"};
    std::string s8{"is powerful!"};

    std::string sentence;
    sentence = s7 + " " + s8; //OK to add a combination of cstyle strings and c++ strings
    //sentence = "C++" + " is powerful"; // NOT OKAY!!
    getline(cin,sentence);
    getline(cin,sentence,'x');
    //using getline() function on String objects;
    s8.find("powerful");
    //This find function allows us to find certain phrases in strings, it will return the index
    // at which the phrase begins at, if for some reason is is unable to find the stringptr
    // it will return the stringptr::npos



    return 0;
}
