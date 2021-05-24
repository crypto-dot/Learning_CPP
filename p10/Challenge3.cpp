//
// Created by Carlos Arbizu on 12/8/20.
//

#include <iostream>
#include <cctype>
#include <vector>
#include <iomanip>

using std::cout;
using std::vector;
using std::endl;
using std::cin;

char printMenu();
char selectionProcess(char input,vector<int> &list);
void printElements(const vector<int> &list);
void errorMessage();
void addElements(vector<int> &list);
void smallestElement(const vector<int> &list);
void meanElements(const vector<int> &list);
void largestElement(const vector<int> &list);
void deleteElement(vector<int> &list);



int main(){
    vector<int> list{};
    char selection;

     do{
        selection = selectionProcess(printMenu(),list);

     }while(selection != 'Q');
    return 0;
}

char printMenu(){
    char inputMenu{};
    cout<< "P - Print numbers" << endl;
    cout<< "A - Add a number" << endl;
    cout<< "M - Display the mean of the numbers" << endl;
    cout<< "S - Display the smallest number" << endl;
    cout<< "L - Display the largest number" << endl;
    cout<< "D - Delete a number " << endl;
    cout<< "Q - Quit" << endl;
    cout << endl;
    cout<< "Enter your choice: "; cin >> inputMenu; cout << endl;
    return toupper(inputMenu);
}
char selectionProcess(char input,vector<int> &list){

    switch(input){
        case 'P':
            printElements(list);
            break;
        case 'A':
            addElements(list);
            break;
        case 'M':
             meanElements(list);
            break;
        case 'S':
            smallestElement(list);
            break;
        case 'L':
            largestElement(list);
            break;
        case 'D':
            deleteElement(list);
            break;
        case 'Q':
            return 'Q';
        default:
            cout << "UNKNOWN INPUT" << endl;
            break;
    }
}
void printElements(const vector<int> &list){
    if(list.empty()){
        errorMessage();
    }
    else {
        cout << "[";
        for (int x : list) {
            cout << " " << x << " ";
        }
        cout << "]" << endl;
    }
}
void errorMessage(){
    cout << "ERROR UNABLE TO PERFORM ACTION! THIS LIST IS EMPTY! " << endl;
}
void addElements(vector<int> &list){
        int num {};
        cout << "Input a number: "; cin >> num;cout << endl;
        list.push_back(num);
}
void smallestElement(const vector<int> &list){
    if(list.empty()){
        errorMessage();
    }
    else {
        int smallest {list[0]};
        for(int i{1};i < list.size();i++ ){
            if(smallest > list[i]){
                smallest = list[i];
            }
        }
        cout << "The smallest element is " << smallest << endl;
    }
}
void largestElement(const vector<int> &list){
    if(list.empty()){
        errorMessage();
    }
    else {
        int largest {list[0]};
        for(int i{1};i < list.size();i++ ){
            if(largest < list[i]){
                largest = list[i];
            }
        }
        cout << "The smallest element is " << largest << endl;
    }
}
void deleteElement(vector<int> &list){
    if(list.empty()){
        errorMessage();
    }else {
        int element{};
        int index{-1};
        cout << "Input the number you want to delete: "; cin >> element; cout << endl;
        for(int x{0}; x < list.size(); x++){
            if(list[x] == element){
                index = x;
                break;
            }
        }
        if(index == -1){
            cout << "Error unable to find element within list" << endl;
        }
        else {
            list.erase(list.begin()+index);
            cout << element << " was deleted" << endl;
        }

    }

}
void meanElements(const vector<int> &list){
    if(list.empty()){
        errorMessage();
    }
    else{
        double result {};
        for(int x : list){
            result += x;
        }

        cout << "The mean of the list is " << std::setprecision(2) << result/list.size() << endl;
    }
}