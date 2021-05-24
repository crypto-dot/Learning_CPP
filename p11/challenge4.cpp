//
// Created by Carlos Arbizu on 12/26/20.
//


#include <iostream>
using std::cout;
using std::endl;
//FOR CONST INT *CONST POINTERS IT IS NOT NECESSARY TO SPECIFY CONST INT *CONST IN THE FUNCTION
//PROTOTYPE
int *applyAll(const int *arryptr1,size_t size1,const int *arryptr2,size_t size2);
void print(const int *arryptr,size_t size);

int main(){
    int array1[3] {3,5,6};
    size_t size = 3;
    int array2[3] {1,2,3};

    int *arryptrHeap {applyAll(array1,size,array2,size)};
    print(arryptrHeap,size * size);

    return 0;
}
void print(const int *const arryptr, size_t size){
    cout << "[ ";
    for(size_t i {0}; i < size; i++){
        cout << arryptr[i] << " ";
    }
    cout << "]";
}
int *applyAll(const int *const arryptr1,size_t size1, const int *const arryptr2,size_t size2){
    //the size of the new array
    size_t newSize {size2 * size1};
    int *newArryptr {new int[newSize]};
    // index of the new array that increases every loop instance
    size_t counter {0};
    //loop through all the elments of one array multiplying it by all the elements of the other array
    //
    for(size_t i {0}; i < size1; i++ ){
        for(size_t j {0}; j < size2; j++) {
            newArryptr[counter] = arryptr1[i] * arryptr2[j];
            counter++;
        }
    }
    return newArryptr;
}
