//
// Created by Carlos Arbizu on 3/7/21.
//
#include <cstring>
#include <cctype>
#include "MyStringNonMember.h"
#include <iostream>
using std::cout;
using std::endl;

MyStringNonMember::MyStringNonMember() : stringptr{ new char[] {'\0'} } {
}
MyStringNonMember::MyStringNonMember(const char *stringptr) {
    //To account for null string pointers
    if(stringptr == nullptr){
        this->stringptr = new char[] {'\0'};
    }
    else{
        this->stringptr = new char[strlen(stringptr) + 1] {};
        strcpy(this->stringptr,stringptr);
    }
}
MyStringNonMember::MyStringNonMember(MyStringNonMember &&source) noexcept : stringptr{source.stringptr} {
    source.stringptr = nullptr;
}
MyStringNonMember::MyStringNonMember(const MyStringNonMember &source) : stringptr{new char[source.getLength() + 1] {}} {
    strcpy(stringptr,source.stringptr);
}
int MyStringNonMember::getLength() const{
    return strlen(stringptr);
}
MyStringNonMember operator+(const MyStringNonMember &lhs, const MyStringNonMember &rhs){
    char *temp = new char[lhs.getLength() + rhs.getLength() + 1]{};
    //strcpy would copy the null terminator in the first one but strcat will override the first null terminator
    strcpy(temp,lhs.stringptr);
    strcat(temp,rhs.stringptr);

    return MyStringNonMember(temp);
}
MyStringNonMember operator-(const MyStringNonMember &lhs,const MyStringNonMember &rhs){
    char *temp = new char[lhs.getLength() + 1]{};
    strcpy(temp,lhs.stringptr);
    for(int i{0};i < rhs.getLength() ;i++) {
        for (int j{0}; j < strlen(temp); j++) {
            if (temp[j] == rhs.stringptr[i] && isalpha(temp[j])) {
                temp[j] = '_';
            }
        }
    }
    MyStringNonMember tempObj(temp);
    delete [] temp;
    return tempObj;
}

bool operator==(const MyStringNonMember &lhs, const MyStringNonMember &rhs) {
    return (strcmp(lhs.stringptr,rhs.stringptr) == 0);
}

MyStringNonMember operator*(const MyStringNonMember &lhs, const int &rhs) {
    char *temp = new char[(lhs.getLength() * rhs)+ 1] {};
    MyStringNonMember tempObj(temp);
    for(size_t i {0}; i < rhs; i++){
        tempObj = tempObj + lhs;
    }
    return tempObj;
}

MyStringNonMember &operator+=(MyStringNonMember &lhs, const MyStringNonMember &rhs) {
    char *temp = new char [lhs.getLength() + 1] {};
    strcpy(temp,lhs.stringptr);
    delete [] lhs.stringptr;
    lhs.stringptr = new char[lhs.getLength() + rhs.getLength() + 1] {};
    strcpy(lhs.stringptr,temp);
    strcat(lhs.stringptr,rhs.stringptr);
    delete [] temp;
    return lhs;
}

MyStringNonMember &MyStringNonMember::operator=(const MyStringNonMember &source) {
    if(this == &source){
        return *this;
    }
    delete [] stringptr;
    this->stringptr = new char[source.getLength() + 1] {};
    strcpy(stringptr,source.stringptr);
    return *this;
}
MyStringNonMember &MyStringNonMember::operator=(MyStringNonMember &&source) noexcept {
    if(this == &source){
        return *this;
    }
    stringptr = source.stringptr;
    source.stringptr = nullptr;
    return *this;
}
std::ostream &operator<<(std::ostream &ostream, const MyStringNonMember &myStringNonMemberobj){
    ostream << myStringNonMemberobj.stringptr;
    return ostream;
}
std::istream &operator>>(std::istream &istream, MyStringNonMember &myStringNonMemberobj) {
    char *tempbuffer = new char[1000] {};
    istream >> tempbuffer;
    myStringNonMemberobj = MyStringNonMember(tempbuffer);
    delete [] tempbuffer;
    return istream;
}
MyStringNonMember::~MyStringNonMember() {
    delete [] stringptr;
}

MyStringNonMember operator-(const MyStringNonMember &MyStringObj) {
    char *temp = new char[MyStringObj.getLength() + 1] {};
    strcpy(temp,MyStringObj.stringptr);
    for(int i {0}; i < strlen(temp); i++){
        temp[i] = tolower(temp[i]);
    }
    MyStringNonMember tempObj(temp);
    delete [] temp;
    return tempObj;
}
