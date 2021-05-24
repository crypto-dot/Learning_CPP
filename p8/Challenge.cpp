//
// Created by Carlos Arbizu on 12/1/20.
//
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
int main() {
    char inputMenu {};
    int inputNum {};
    vector<int> vec {};
    do{
        cout<< "P - Print numbers" << endl;
        cout<< "A - Add a number" << endl;
        cout<< "M - Display the mean of the numbers" << endl;
        cout<< "S - Display the smallest number" << endl;
        cout<< "L - Display the largest number" << endl;
        cout<< "D - Delete a number " << endl;
        cout<< "Q - Quit" << endl;
        cout << endl;
        cout<< "Enter your choice: "; cin >> inputMenu; cout << endl;
        switch(inputMenu){
            case 'p':
            case 'P':
                if(vec.empty()){
                    cout << "[] - the list is empty." << endl;
                }
                else{
                    cout << "[";
                for(int x : vec){
                    cout << " " << x << " ";
                }
                    cout << "]" << endl;
                }
                break;
            case 'a':
            case 'A':
                cout << "Enter an integer to add to the list: "; cin >> inputNum; cout << endl;
                vec.push_back(inputNum);
                break;
            case 'm':
            case 'M':
                if(vec.empty()){
                    cout << "Unable to determine the mean, the list is empty." << endl;
                }
                else{
                    double result {0};
                    for(int x : vec){
                        result += x;
                    }
                    cout << "The mean of the list of numbers is " << result/vec.size() << endl;
                }
                break;
            case 's':
            case 'S':
                if(vec.empty()){
                    cout << "Unable to determine the smallest number, the list is empty." << endl;
                }
                else{
                    int smallest {vec[0]};
                    for(int x {0}; x < vec.size(); x++){
                        if(smallest > vec[x]){
                            smallest = vec[x];
                        }
                    }
                    cout << "The smallest number is  " << smallest << endl;
                }
                break;
            case 'l':
            case 'L':
                if(vec.empty()){
                    cout << "Unable to determine the largest number, the list is empty." << endl;
                }
                else{
                    int largest {vec[0]};
                    for(int x {0}; x < vec.size(); x++){
                        if(largest < vec[x]){
                            largest = vec[x];
                        }

                    }
                    cout << "The largest number is " << largest << endl;

                }
                break;
            case 'd':
            case 'D':
                {
                    if(vec.empty()){
                        cout << "This list is empty!!" << endl;
                        break;
                    }
                int num{0};
                cout << "Enter a number to delete: ";
                cin >> num;
                int index {-1};
                for (int i{static_cast<int>(vec.size() - 1)}; i >= 0; i--)
                {
                if(vec[i] == num){
                    index = i;
                    break;
                }
                }
                if(index != -1){
                    vec.erase(vec.begin() + index);
                    cout << "The number " << num << " was deleted" << endl;
                }
                else{
                    cout << "The number " << num << " does not exist in this list!" <<endl;
                }
                break;
            }
            case 'Q':
            case 'q':
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
                break;
        }
    }
     while(inputMenu != 'Q' &&  inputMenu != 'q');

    return 0;
}
