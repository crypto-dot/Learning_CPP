//
// Created by Carlos Arbizu on 5/26/21.
//

#ifndef CPP_ILLEGALBALANCEEXCEPTION_H
#define CPP_ILLEGALBALANCEEXCEPTION_H
#include <exception>
using std::exception;
class IllegalBalanceException :public exception{
public:
    ~IllegalBalanceException() = default;
    IllegalBalanceException() noexcept = default;
    const char *what() const noexcept override;

};


#endif //CPP_ILLEGALBALANCEEXCEPTION_H
