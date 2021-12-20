//
// Created by Carlos Arbizu on 12/19/21.
//
#include <iostream>
#include <algorithm>
void insertionSortReverse(int array[],size_t size){
    for(int j = 1; j < size; j++){
        int key = array[j];
        int i = j - 1;
        while(i > -1 && array[i] < key){
            array[i + 1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}
void insertionSortReverse2(int arr[], size_t size){
    size_t i,j;
    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] > arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
int main(){
    int array[5] = {21,33,3,30,69};
    insertionSortReverse2(array,5);
    for(const auto &element : array){
        std::cout << element << '\n';
    }
}