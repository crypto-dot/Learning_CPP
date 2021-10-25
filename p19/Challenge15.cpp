//
// Created by Carlos Arbizu on 9/19/21.
//
#include <deque>
using std::deque;
#include <iostream>
using std::cout;
using std::string;
#include <algorithm>
using std::equal;
using std::count_if;
#include <cctype>
using std::isalpha;
using std::toupper;
bool isPalidrome(const string &input){
    //One way to do it inefficient uses 2 deques
/*    deque<char> stringInputReversed;
    deque<char> stringInputForward;
    for(const char &c : input){
        if(isalpha(c)) {
            stringInputReversed.push_front(toupper(c));
        }
    }
    for(const char &c : input){
        if(isalpha(c)) {
            stringInputForward.push_back(toupper(c));
        }
    }

    return equal(stringInputReversed.begin(),stringInputReversed.end(),stringInputForward.begin());*/
//Better way to do it using 1 deque
    char c,c2;
    deque<char> stringInput;
    for(const auto &character : input){
        if(isalpha(character)) {
            stringInput.push_back(toupper(character));
        }
    }
    while(stringInput.size() > 1){
        c = stringInput.front();
        c2 = stringInput.back();
        cout << "\n";
        if(c != c2){
            return false;
        }
        stringInput.pop_front();
        stringInput.pop_back();
    }
    return true;
}

int main(){
    if(isPalidrome("hello")){
        cout << "The phrase is a palindrome";
    }
    else {
        cout << "The phrase is not a palindrome";
    }

    return 0;
}