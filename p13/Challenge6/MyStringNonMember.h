//
// Created by Carlos Arbizu on 3/7/21.
//

#ifndef CPP_MYSTRINGNONMEMBER_H
#define CPP_MYSTRINGNONMEMBER_H
#include <iostream>

class MyStringNonMember {
private:
    char *stringptr{nullptr};
public:
    MyStringNonMember();
    MyStringNonMember(const char *stringptr);

    ~MyStringNonMember();

    MyStringNonMember(const MyStringNonMember &source);
    MyStringNonMember(MyStringNonMember &&source) noexcept;
    int getLength() const;

    friend MyStringNonMember operator+(const MyStringNonMember &lhs,const MyStringNonMember &rhs);
    friend MyStringNonMember operator-(const MyStringNonMember &lhs,const MyStringNonMember &rhs);//removes similar alphanumeric characters from the left side (case sensitive)
    friend MyStringNonMember operator*(const MyStringNonMember &lhs, const int &rhs);



    friend bool operator==(const MyStringNonMember &lhs,const MyStringNonMember &rhs);

    friend MyStringNonMember &operator+=(MyStringNonMember &lhs,const MyStringNonMember &rhs);

    friend std::ostream &operator<<(std::ostream &ostream,const MyStringNonMember &myStringNonMemberobj);
    friend std::istream &operator>>(std::istream &istream, MyStringNonMember &myStringNonMemberobj);
    //Assignment operator must be declared as member functions
    MyStringNonMember &operator=(const MyStringNonMember &source);
    MyStringNonMember &operator=(MyStringNonMember &&source) noexcept;
    friend MyStringNonMember operator-(const MyStringNonMember &MyStringNonMember);




};


#endif //CPP_MYSTRINGNONMEMBER_H
