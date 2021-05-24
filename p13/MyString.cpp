//
// Created by Carlos Arbizu on 1/31/21.
//
//This is to practice operator overloading and use of raw pointers in the context of copy constructors and move constructors

#include "MyString.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

MyString::MyString(const char* ccstring) {
    if(ccstring == nullptr){
        this->ccstring = new char[]{'\0'};
    } else{
        this->ccstring = new char[strlen(ccstring) + 1];
        strcpy(this->ccstring,ccstring);
    }
}
MyString::MyString() : ccstring{new char[]{'\0'}}{
    cout << "No args called " << endl;
}
MyString::MyString(const MyString &source) : ccstring{new char[source.getLength() + 1] {}}{
    strcpy(ccstring,source.ccstring);
}
int MyString::getLength() const {
    //can be replaced with strlen() but wanted to try to implement my own version for fun
    int count{0};
    while(ccstring[count] != '\0'){
        count++;
    }
    return count;
}
void MyString::display() const {
    std::cout << ccstring << std::endl;
}

MyString::~MyString() {
    delete[] ccstring;
}

char* MyString::get_str() const {
    return ccstring;
}
MyString &MyString::operator=(const MyString &rhs){
    if(this == &rhs){
        //First compare the address of the obj to the rightside of the equal signs with the obj on the left side
        //If both objects have the same address (hence the & symbol) then nothing needs to be done
        cout << "Assignment copy called " << endl;
        return *this;
        //the 'this' keyword is a pointer to the current object by dereferencing it we can get the current object we are
        //working with
        // the 'this' pointer can be used so that
        // you can chain function calls, this way you can call all the functions for the current object in one go.
        //In the above case we can chain the equal operator as such:
        //obj1 = obj2 = obj3

    }
    delete [] this->ccstring;
    //First we need to delete the stringptr of char that are already dynamically allocated to create some space (even if the stringptr is potentially empty; memory is still used)
    //The 'this' keyword is not necessary however it may improve the readability of your code
    // (can just use ccstring by itself, but it may be confusing to others and yourself so it's best
    //practice to use this to specify)
    ccstring = new char [rhs.getLength() + 1] {};
    //Allocate space according to the length of the MyString on the right hand side in order to ensure that the stringptr can fit
    strcpy(this->ccstring, rhs.ccstring);
    //Again 'this' keyword is not necessary
    cout << "Assignment copy called " << endl;
    return *this;
    //Allows us to chain function calls also returns the current obj
}
//Down below is the code for the assignment operator using move
MyString &MyString::operator=(MyString &&rhs) noexcept{
    if(this == &rhs){
        return *this;
    }
    delete [] ccstring;
    ccstring = rhs.ccstring;
    rhs.ccstring = nullptr;
    return *this;
}

MyString MyString::operator-() const {

   char *temp = new char[this->getLength() + 1] {};
   strcpy(temp,this->get_str());

   for(size_t i {0}; i < strlen(temp);i++){
       temp[i]= tolower(temp[i]);
   }

   MyString tempObj(temp);
   delete [] temp; //Very important
   return tempObj;

}


MyString MyString::operator+() const{

    char* temp = new char[this->getLength() + 1] {};
    strcpy(temp, this->ccstring);

    for(size_t i {0}; i < strlen(temp); i++){
        temp[i] = toupper(temp[i]);
    }
    MyString tempObj{temp};
    delete [] temp;

    return tempObj;

}
MyString MyString::operator+(const MyString &rhs) const {
    char *temp = new char[this->getLength() + rhs.getLength() + 1] {};
    strcpy(temp, this->get_str());
    temp = strcat(temp, rhs.get_str());
    MyString objTemp(temp);
    delete[] temp;
    return objTemp;

}
bool MyString::operator==(const MyString &rhs) const {
    bool boolean {true};

    for(size_t i{0}; i < rhs.getLength(); i++){
        if(rhs.get_str()[i] != this->get_str()[i]){
            boolean = false;
        }
    }
    return boolean;
}

MyString operator-(const MyString &lhs, const MyString &rhs) {
    char *tempstr { new char[strlen(lhs.ccstring) + 1] {} };
    strcpy(tempstr,lhs.get_str());

    char previous {'\0'};


    for(size_t i {0}; i < strlen(rhs.ccstring); i++){
        char current = rhs.get_str()[i];
        if(current == previous || !isalpha(current)){
            continue;
        }
        else {
            for (size_t x{0}; x < strlen(tempstr); x++) {
                if (tempstr[x] == current) {
                    tempstr[x] = ' ';
                }
            }
            previous = current;
        }
    }

    MyString tempObj{tempstr};
    delete [] tempstr;
    return tempObj;
}






std::ostream &operator<<(std::ostream &ostream, const MyString &myStringobj){
    ostream << myStringobj.ccstring;
    return ostream;
}

std::istream &operator>>(std::istream &instream, MyString &MyStringobj) {
    char *buff = new char[1000];
    instream >> buff;
    MyStringobj = MyString(buff);
    delete [] buff;

    return instream;
}
MyString &operator+=(MyString &lhs, const MyString &rhs){
    strcat(lhs.ccstring,rhs.ccstring);
    return lhs;
}


