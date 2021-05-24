//
// Created by Carlos Arbizu on 12/19/20.
//

// to allocate a variable to the heap use the new keyword.
#include <iostream>

int main(){
    int *int_ptr {nullptr};
    int_ptr = new int; // stores variable in the heap
    std::cout << int_ptr <<" is the value of the address of the pointer." << std::endl;
    *int_ptr = 5; //dereference the pointer to get to the variable value and set it to a new value
    // in this example the only way to access the variable is through the pointer since the int variable has no name.
    // it is important that you delallocate the storage to free up space in the memory as such:
    delete int_ptr;
    //************************************************************************
    int *size_ptr {nullptr};
    int size {};
    std::cout <<"Input the size that you want the array to be: ";
    std::cin >>size;
    size_ptr = new int{size};
    std::cout << size_ptr <<std::endl;
    //Now points to an array made in the heap
    //If we lose the ability to acess this pointer there is no way to remove this array
    // This is called a memory leak
    delete size_ptr;
    //If we have a pointer leading to an array allocated in the heap such as this we must use the delete keyword
    // to free up space.
    int array[4] {1,2,3,4};
    int *ptr_arry {array};

    std::cout << array << " is the address of the first element." << std::endl;
    std::cout << array + 1 << " is the address of the second element." << std::endl;
    std::cout << array +  2 << " is the address of the third element." << std::endl;
    std::cout << ptr_arry << " is the address of the first element using a pointer. " << std::endl;
    std::cout << ptr_arry + 1 << " is the address of the second element using a pointer." << std::endl;
    std::cout << ptr_arry +2 << " is the address of the third element using a pointer." << std::endl;

    std::cout << *array<< " is the first element." << std::endl;
    std::cout << *array + 1<< " is the second element." << std::endl;
    std::cout << *array + 2 << " is the third element." << std::endl;
    std::cout << *ptr_arry << " is the first element using a pointer and offset notation" << std::endl;
    std::cout << *ptr_arry + 1 << " is the second element using a pointer and offset notation" << std::endl;
    std::cout << *ptr_arry + 2 << " is the third element using a pointer and offset notation" << std::endl;

    std::cout << ptr_arry[0] << " is the first element using a pointer and subscript notation." << std::endl;
    std::cout << ptr_arry[1] << " is the second element using a pointer and subscript notation." << std::endl;
    std::cout << ptr_arry[2] << " is the third element using a pointer and subscript notation." << std::endl;

    std::cout << sizeof(int) << " is the amount of bytes of an int." << std::endl;

    return 0;
}