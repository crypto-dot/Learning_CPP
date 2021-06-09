//
// Created by Carlos Arbizu on 5/31/21.
//
#include "IllegalBalanceException.h"
const char *IllegalBalanceException::what() const noexcept
{
    return "Balance is less than 0!";
}

