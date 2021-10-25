//
// Created by Carlos Arbizu on 10/16/21.
//
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

bool isPalidrome(const std::string &input){
    std::stack<char> stak{};
    std::queue<char> que{};
    std::for_each(input.begin(),input.end(),[&stak,&que](const char &c){
        if(isalpha(c)) {
            stak.push(toupper(c));
            que.push(toupper(c));
        }
    });
    char c;
    char c2;

    while(!que.empty()){
        c = que.front();
        c2 = stak.top();
        if(c != c2) {
            return false;
        }
        que.pop();
        stak.pop();
    }


    return true;
}
int main(){

    std::string word {"Racecar"};
    std::vector<std::string> testStrings {"a","aa","aba","abbcbba","bob","radar","C++","A santa at NASA"};
    std::for_each(testStrings.begin(),testStrings.end(),[](std::string word){
        if(isPalidrome(word)){
            std::cout << word << " is a palindrome. \n";
        }
        else {
            std::cout << word << " is not a palindrome. \n";
        }
    });

    return 0;
}