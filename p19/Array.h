//
// Created by Carlos Arbizu on 9/10/21.
//

#ifndef CPP_ARRAY_H
#define CPP_ARRAY_H
#include <iostream>
using std::ostream;
//It is best to use std::array instead of raw arrays whenever possible
template<typename T,uint64_t N>
class Array{
public:
    Array(T val) {
        for(auto &value : values){
            value = val;
        }
    }
    Array()= default;
    friend ostream &operator<<(ostream &ostream1, const Array &array){
        ostream1 << "[ ";
        for(const auto &value : array.values){
             if(&value == &array.values[sizeof(array.values)/sizeof(array.values[0]) - 1]){
                 ostream1 << value << " ";
             }
             else {
                 ostream1 << value << ", ";
             }
        }
        ostream1 << "]";
        return ostream1;
    }
    void fill(T val){
        for(auto &value : values){
            value = val;
        }
    }
    uint64_t getSize(){
        return size;
    }

    T &operator[](int index){
        return values[index];
    }
    const T &operator[](int index) const{
        return values[index];
    }

private:
    uint64_t size {N};
    T values[N];
};
#endif //CPP_ARRAY_H
