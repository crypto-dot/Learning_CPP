//
// Created by Carlos Arbizu on 5/31/21.
//

#ifndef CPP_INSUFFICIENTFUNDSEXCEPTION_H
#define CPP_INSUFFICIENTFUNDSEXCEPTION_H

#include <exception>
using std::exception;
class InsufficientFundsException : public exception{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
     const char *what() const noexcept override;
};


#endif //CPP_INSUFFICIENTFUNDSEXCEPTION_H
