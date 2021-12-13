//
// Created by Carlos Arbizu on 11/29/21.
//

#ifndef CPP_MYVECTOR_H
#define CPP_MYVECTOR_H

#include <cstddef>
#include <initializer_list>
#include <cmath>
#include <bit>
#include <algorithm>
#include <iostream>
#include <exception>

const int INITIAL_CAPACITY = 2;
const int GROWTH_FACTOR = 2;
template <class T>
class MyVector {
public:
    MyVector() :array{new T[INITIAL_CAPACITY]},_size{0},cap{INITIAL_CAPACITY} {
    };
    MyVector(std::initializer_list<T> list): array{new T[list.size()]},_size{list.size()},cap{list.size()} {
        for(size_t i {0}; i < list.size(); i++){
            array[i] = *(list.begin() + i);
        }
    };
    MyVector(size_t size): _size{size},cap {size},array{new T[cap]}{

    };
    void push_back(T item)  {
        if(_size + 1 >= cap){
            resize();
        }
        *(array + _size) = item;
        ++_size;
    };
    void insert(size_t index, T element) {
        if(index >= _size) {
            throw std::out_of_range("Out of range");
        }

        if(_size + 1 >= cap){
            resize();
        }
        for(size_t i {++_size}; i > index; i--){
            *(array + i) = *(array + i - 1);
        }
        *(array + index) = element;
    };
    void del(size_t index) {
        if(index >= _size){
            throw std::out_of_range("Out of range");
        }
        if(_size - 1 <= cap/4){
            resize(cap/2);
        }
        for(size_t i{index}; i < _size; i++){
            *(array + i) = *(array + i + 1);
        }
        --_size;
    };
    void print() const{
        std::cout << '[';
        for(size_t i {0}; i < _size; i++){
            if(i == _size - 1){
                std::cout << *(array + i);
            }
            else{
                std::cout << *(array + i) << ',';
            }
        }
        std::cout << "]\n";
    };
    void pop() {
        if(_size == 0){
            return;
        }
        if(--_size == cap/4 ){
            resize(cap/2);
        }
    };
    T &at(size_t index) {
        if(index >= _size){
            throw std::out_of_range("Out of range");
        }
        return *(array + index);
    };
    T at(size_t index) const {
        if(index >= _size){
            throw std::out_of_range("Out of range");
        }
        return *(array + index);
    };
    size_t size() const {
        return _size;
    };
    size_t capacity() const{
        return cap;
    }



private:
    T *array;
    size_t _size;
    size_t cap = INITIAL_CAPACITY;

    void resize(){
        cap = cap * GROWTH_FACTOR;
        T *temp = new int[cap];
        std::copy(array,array + _size,temp);
        delete [] array;
        array = temp;
    }
    void resize(size_t new_capacity){
        cap = new_capacity;
        T *temp = new T[cap];
        std::copy(array,array + _size,temp);
        delete [] array;
        array = temp;
    }




};




#endif //CPP_MYVECTOR_H
