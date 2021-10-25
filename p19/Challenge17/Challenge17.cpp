//
// Created by Carlos Arbizu on 10/11/21.
//
#include <map>
#include <set>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

template<typename T,typename T2>
void displayUniqueWordCount(std::map<T,T2> m){
    std::cout << std::left << "Word" << std::setw(11) << "" << std::right << "Count \n";
    std::cout << std::setw(30) << std::setfill('=') << "" << '\n' << std::setfill(' ');
    for(const auto &element : m){
        std::cout << std::setw(15) << std::left << element.first << element.second << '\n';
    }

}
template<typename T,typename T2>
void displayUniqueWordPerLine(std::map<T,std::set<T2>> m){
    std::cout << std::left << "Word" << std::setw(11) << "" << std::right << "Occurrences\n";
    std::cout << std::setfill('=') << std::setw(30) << "" << '\n';
    for(const auto &element : m){
            std::cout << std::setw(15) << std::setfill(' ') << std::left << element.first << std::right << '[';
            for(const auto &setElement : element.second){
                if(&setElement != &(*(--element.second.end()))){
                    std::cout << setElement << ", ";
                }
                else {
                    std::cout << setElement << " ]\n";
                }
            }
    }
}

void cleanString(std::string &str){
    str.erase(std::remove_if(str.begin(),str.end(),[](const char &c){
        return !(std::isalpha(c) || c == '\'');
    }),str.end());
}

int main(){
    std::map<std::string,int> wordCount;
    std::map<std::string,std::set<int>> wordCountUniqueLine;
    std::ifstream inputFile{"words.txt"};
    std::string word;
    std::string line;
    int count {1};
    if(!inputFile){
        std::cerr<<"ERROR";
    }
    else {
        while (inputFile >> word) {
            cleanString(word);
            wordCount[word]++;
        }
        displayUniqueWordCount(wordCount);
    }
    std::cout << '\n';
    inputFile.clear();
    inputFile.seekg(0);
    while(std::getline(inputFile,line)){
        std::istringstream strStream {line};
        while(strStream >> word){
            cleanString(word);
            wordCountUniqueLine[word].insert(count);
        }
        count++;
    }
    displayUniqueWordPerLine(wordCountUniqueLine);
    inputFile.close();
    return 0;
}