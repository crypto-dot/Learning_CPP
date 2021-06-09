//
// Created by Carlos Arbizu on 5/31/21.
//

#include "InsufficientFundsException.h"

const char *InsufficientFundsException::what() const noexcept {
    return "Not enough funds for this transaction!";
}
