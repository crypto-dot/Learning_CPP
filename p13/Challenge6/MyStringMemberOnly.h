//
// Created by Carlos Arbizu on 3/5/21.
//

#ifndef CPP_MYSTRINGMEMBERONLY_H
#define CPP_MYSTRINGMEMBERONLY_H

#include <iostream>

class MyStringMemberOnly {
private:
    char *stringptr{nullptr};
public:

    MyStringMemberOnly();
    MyStringMemberOnly(const char *string);

    MyStringMemberOnly(const MyStringMemberOnly &source);
    MyStringMemberOnly(MyStringMemberOnly &&source) noexcept;

    ~MyStringMemberOnly();

    char *getString() const;
    int getLength() const;

    MyStringMemberOnly operator-() const;//Lowercase all alphanumeric characters
    MyStringMemberOnly operator+(const MyStringMemberOnly &rhs) const; //Combine the strings of MyStringMemberonly objs
    MyStringMemberOnly &operator+=(const MyStringMemberOnly &rhs);

    MyStringMemberOnly &operator=(const MyStringMemberOnly &rhs);
    MyStringMemberOnly &operator=(MyStringMemberOnly &&rhs) noexcept;
    MyStringMemberOnly operator*(const int &rhs) const; //repeats string x number of times

    bool operator==(const MyStringMemberOnly &rhs) const;
    std::ostream &operator<<(std::ostream &ostream);
    std::istream &operator>>(std::istream &istream);

    MyStringMemberOnly operator++(int); //Capitalize all letters (post increment)
    MyStringMemberOnly &operator++();
};


#endif //CPP_MYSTRINGMEMBERONLY_H
