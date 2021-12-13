//
// Created by Carlos Arbizu on 11/23/21.
//
#include <cstddef>
#include <iostream>
#include <iomanip>
void insertionSort(int arr[],size_t size){
    size_t i,j;
    for(i =1; i < size;i++){
        j = i;
        while((j > 0) && (arr[j] < arr[j -1])){
            std::swap(arr[j],arr[j-1]);
            j--;
            for(size_t h{0}; h < 4; h++){
                std::cout << arr[h] << ' ';
            }
            std::cout << '\n';

        }
    }
}
void selectionSort(int arr[],size_t size){
    int i,j;
    int min;
    for(i = 0; i < size; i++){
        min = i;
        for(j = i + 1; j < size; j++ ){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
        for(size_t j{0}; j < 4; j++){
            std::cout << arr[j] << ' ';
        }
        std::cout << '\n';
    }
}

void insertionSort2(int arr[],size_t size){
    size_t i,j;
    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            std::swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
void selectionSort2(int arr[],size_t size){
    size_t i,j;
    size_t min;

    for(i = 0; i < size; i++){
        min = i;
        for(j = i+1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}
void selectionSort3(int arr[],size_t size){
    size_t i,j;
    size_t min;

    for(i = 0; i < size; i++){
        min = i;
        for(j = i+1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}
void insertionSort3(int arr[],size_t size){
    size_t i,j;

    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }

}

void selectionSort4(int arr[],size_t size){
    size_t i,j;
    size_t min;
    for(i = 0; i < size; i ++){
        min = i;

        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
    }

}
void insertionSort4(int arr[],size_t size){
    size_t i,j;
    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void reverseSelectionSort(int arr[], size_t size){
    size_t i,j;
    size_t max;
    for(i = 0; i < size; i++){
        max = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] > arr[max]){
                max = j;
            }
        }
        std::swap(arr[i],arr[max]);
    }
}
void reverseInsertionSort(int arr[],size_t size){
    std::cout << "Insertion Sort(Reverse) \n";
    size_t i,j;
    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] > arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void reverseSelectionSort2(int arr[],size_t size){

    size_t i,j;
    size_t max;
    for(i = 0; i < size; i++){
        max = i;
        for(j = i +1; j < size; j++){
            if(arr[j] > arr[max]){
                max = j;
            }
        }
        std::swap(arr[i],arr[max]);
    }
}

void reverseInsertionSort2(int arr[],size_t size){
    size_t i,j;
    for(i = 1; i < size; i++){
        j=i;
        while(j > 0 && arr[j] > arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
void reverseSelectionSort3(int arr[],size_t size){
    size_t i,j;
    size_t max;
    for(i = 0; i < size; i++){
        max = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] > arr[max]){
                max = j;
            }
        }
        std::swap(arr[i],arr[max]);
    }

}

void reverseInsertionSort3(int arr[],size_t size){
    size_t i, j;
    for(i = 1; i < size; i++ ){
        j = i;
        while(j > 0 && arr[j] > arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void reverseSelectionSort4(int arr[],size_t size){
    size_t i,j;
    size_t max;

    for(i = 0; i < size; i++){
        max = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] > arr[max]){
                max = j;
            }
        }
        std::swap(arr[i],arr[max]);
    }
}

void ReverseInsertionSort4(int arr[],size_t size){
    size_t i,j;
    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] > arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void selectionSort5(int arr[],size_t size){
    size_t i,j;
    size_t min;

    for(i = 0; i < size; i++){
        min = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}

void insertionSort5(int arr[],size_t size){
    size_t i,j;

    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j -1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void insertionSort6(int arr[],size_t size){
    size_t i,j;
    for(i = 1; i < size; i++){
        j = i;
        while(j>0 && arr[j] < arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            --j;
        }
    }
}

void selectionSort6(int arr[],size_t size){
    size_t i,j;
    size_t min;
    for(i = 0; i < size; i++){
        min = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}

void selectionSort7(int arr[],size_t size){
    size_t i,j;
    size_t min;
    for(i = 0; i < size; i++){
        min = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}

void insertionSort7(int arr[],size_t size){
    size_t i,j;

    for(i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }

    }
}

void selectionSort8(int arr[],size_t size){
    size_t i,j;
    size_t min;
    for(i = 0; i < size; i++){
        min = i;
        for(j = i +1; j < size; j++){
            if(arr[j] < arr[min]){
                min= j;
            }
        }
        std::swap(arr[i],arr[min]);
    }
}

void insertionSort8(int arr[],size_t size){
    size_t i,j;
    for(i= 1;i < size; i++){
        j  = i;
        while(j > 0 && arr[j] < arr[j -1]){
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void reverseSelectionSort5(int arr[],size_t size){
    size_t i,j;
    size_t max;

    for(i = 0; i < size; i++){
        max = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] > arr[max]){
                max = j;
            }
        }
        std::swap(arr[i],arr[max]);
    }
}

void reverseInsertionSort5(int arr[],size_t size){
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

    int arr[4] {22,20,5,3};
    for(size_t i{0}; i < 4; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
    std::cout << std::setw(30) << std::setfill('=') << "" << std::setfill(' ') << '\n';
    reverseInsertionSort5(arr,4);
    for(size_t j{0}; j < 4; j++){
        std::cout << arr[j] << ' ';
    }
    std::cout << '\n';


    int arr2[4] {3,5,20,22};
    std::cout << std::setw(30) << std::setfill('=') << "" << std::setfill(' ') << '\n';
    ReverseInsertionSort4(arr2,4);

    for(size_t j{0}; j < 4; j++){
        std::cout << arr2[j] << ' ';
    }
    std::cout << '\n';
}