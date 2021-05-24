//
// Created by Carlos Arbizu on 3/5/21.
//

#include "MyStringMemberOnly.h"
#include <cstring>
#include <cctype>
#include <iostream>

using std::endl;
using std::cout;

MyStringMemberOnly::MyStringMemberOnly() : stringptr{new char[]{'\0'}} {

}
MyStringMemberOnly::MyStringMemberOnly(const char * const string) {
    if(string == nullptr){
        this->stringptr = new char[] {'\0'};
    }
    else {
        this->stringptr = new char[strlen(string) + 1] {};
        strcpy(this->stringptr, string);

    }
}
int MyStringMemberOnly::getLength() const{
   return strlen(stringptr);
}
char *MyStringMemberOnly::getString() const{
    return stringptr;
}
MyStringMemberOnly::MyStringMemberOnly(const MyStringMemberOnly &source) : stringptr{new char[strlen(source.stringptr) + 1]} {
    strcpy(this->stringptr, source.stringptr);
}
MyStringMemberOnly::MyStringMemberOnly(MyStringMemberOnly &&source) noexcept : stringptr{source.stringptr} {
    source.stringptr = nullptr;
}
MyStringMemberOnly MyStringMemberOnly::operator*(const int &rhs) const{
    char *temp = new char[(strlen(this->stringptr) * rhs) + 1] {};
    MyStringMemberOnly tempObj(temp);
    for(size_t i {0}; i < rhs; i++){
        tempObj = tempObj + *this;
    }
    delete [] temp;
    return tempObj;

}
MyStringMemberOnly MyStringMemberOnly::operator-() const{
    char *temp = new char[this->getLength() + 1] {};
    strcpy(temp, this->stringptr);
    for(size_t i {0}; i < strlen(temp); i++){
        temp[i] = tolower(temp[i]);
    }
    MyStringMemberOnly buffer(temp);
    delete [] temp;
    return buffer;
}
MyStringMemberOnly MyStringMemberOnly::operator+(const MyStringMemberOnly &rhs) const {
    char *temp = new char[this->getLength() + rhs.getLength() + 1] {};
    strcpy(temp, this->stringptr);
    strcat(temp,rhs.getString());
    MyStringMemberOnly tempobj(temp);
    delete [] temp;
    return tempobj;
}

MyStringMemberOnly &MyStringMemberOnly::operator+=(const MyStringMemberOnly &rhs) {
    char *temp = new char[strlen(this->stringptr) + 1] {};
    strcpy(temp, this->stringptr);
    delete[] this->stringptr;
    stringptr = new char [strlen(rhs.stringptr) + strlen(temp) + 1] {};
    strcat(stringptr, temp);
    strcat(stringptr, rhs.stringptr);
    return *this;
}
MyStringMemberOnly &MyStringMemberOnly::operator=(const MyStringMemberOnly &rhs){
    if(this == &rhs){
        cout << "The same " << endl;
        return *this;
    }
    delete[] this->stringptr;
    stringptr = new char[strlen(rhs.stringptr) + 1] {};
    strcpy(stringptr, rhs.stringptr);
    return *this;
}
MyStringMemberOnly &MyStringMemberOnly::operator=(MyStringMemberOnly &&rhs) noexcept{
    if(this == &rhs){
        cout << "The same " << endl;
        return *this;
    }
    delete [] this->stringptr;
    stringptr = rhs.stringptr;
    rhs.stringptr = nullptr;
    return *this;
}
bool MyStringMemberOnly::operator==(const MyStringMemberOnly &rhs)const {
    return (strcmp(this->stringptr, rhs.stringptr) == 0);
}
std::ostream &MyStringMemberOnly::operator<<(std::ostream &ostream){
    ostream << this->stringptr;
    return ostream;
}
std::istream &MyStringMemberOnly::operator>>(std::istream &istream){
    char *buffer = new char[1000]{};
    istream >> buffer;
    *this = MyStringMemberOnly(buffer);
    delete [] buffer;
    return istream;
}
MyStringMemberOnly::~MyStringMemberOnly() {
    delete [] stringptr;
}
MyStringMemberOnly &MyStringMemberOnly::operator++() {
    for(size_t i {0}; i < this->getLength(); i++){
        this->getString()[i]= toupper(this->getString()[i]);
    }
    return *this;
}
 MyStringMemberOnly MyStringMemberOnly::operator++(int) {
    MyStringMemberOnly temp(*this);
    operator++();
    return temp;
}