//
// Created by Carlos Arbizu on 12/1/21.
//

// Kadane's algorithm is an iterative dynamic programming algorithm it's useful in finding the maximum contigious
// subarray in an array
#include <cstddef>
#include <algorithm>
#include <iostream>

int maxSubArray(const int arr[],size_t size){
    size_t i;
    int max_current {arr[0]};
    int max_global {-1};
    for(i = 1; i < size;i++){

        if(max_current > max_global){
            max_global = max_current;
            std::cout << max_current << '\n';
        }
    }
    return max_global;
}

double maxSubArray2(int arr[],size_t size){
    int maxCurrent {arr[0]};
    double maxGlobal = {std::numeric_limits<double>::infinity()};
    for(size_t i {0}; i < size; i++){
        maxCurrent = std::max(maxCurrent + arr[i],arr[i]);
        maxGlobal = std::max(static_cast<int>(maxGlobal),maxCurrent);
    }
    return maxGlobal;
}
























//non contigious maximum sum in an array

int maxSubArrayNonContigious(const int arr[],size_t size){
    int max_current = arr[0];
    int max_global = arr[0];
    for(size_t i {1}; i < size; i++){
            if(i == 1){
                max_current = std::max(arr[i],arr[0]);
            }
            else{
                //Am I bigger by myself or am I bigger than myself + the previous nonconsecutive integer
                int temp = std::max(arr[i],arr[i-2] + arr[i]);
                max_current = std::max(temp,max_current);
            }
            if(max_current > max_global){
                max_global = max_current;
            }
    }
    return max_global;
}

//Below is the tower hopping problem the premise is the minimum number of jumps needed to get to
//the end of an array you can jump as far as the current value you are on (if on 4 you can jump 4 different places)

/*
int TowerHop(const int arr[],size_t size){
    if(size == 1 && arr[0] == 0){
        return -1;
    }
    size_t indexOfMaxHoppable = arr[1];
    for(int i {static_cast<int>(0)}; i >= 0; i++){
        if( )
    }
}
*/


int main(){
    int arr[8] {1,2,3,4,5,6};
    int max = maxSubArray2(arr,6);
    int max2 = maxSubArrayNonContigious(arr,6);
    std::cout << max << '\n';
    std::cout << max2 << '\n';



    return 0;

}