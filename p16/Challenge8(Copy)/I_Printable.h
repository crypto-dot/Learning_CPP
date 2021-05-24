//
// Created by Carlos Arbizu on 5/1/21.
//

#ifndef CPP_I_PRINTABLE_H
#define CPP_I_PRINTABLE_H
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

class I_Printable{
    friend ostream &operator<<(ostream &ostream1,const I_Printable &obj);
public:
    virtual void print(ostream &ostream1) const =0;
    virtual ~I_Printable() = default;
};
#endif //CPP_I_PRINTABLE_H
