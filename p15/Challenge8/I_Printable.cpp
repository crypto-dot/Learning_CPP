//
// Created by Carlos Arbizu on 5/1/21.
//
#include "I_Printable.h"
ostream &operator <<(ostream &ostream1, const I_Printable &obj)
{
obj.print(ostream1);
return ostream1;
}