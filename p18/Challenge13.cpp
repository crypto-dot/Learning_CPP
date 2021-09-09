//
// Created by Carlos Arbizu on 7/27/21.
//
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
using std::toupper;
#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
string mainMenu();
bool testResponse(string &response);
bool caseSensitive();
size_t search(ifstream &in_file,const string &word);
size_t searchCaseSensitive( ifstream &in_file,const string &word);
int main(){
    ifstream in_file {"RomeoAndJuilet.txt"};
    if(!in_file){
        cerr << "Error opening file! \n";
        return 1;
    }
    size_t counter;
    string word = mainMenu();
    if(caseSensitive()) {
        counter = search(in_file,word);
    }
    else{
        counter = searchCaseSensitive(in_file,word);
    }
    cout << "Found " << word << " " << counter << " times!" << "\n";
    in_file.close();
    return 0;
}

string mainMenu() {
    string word;
    string response;
    bool proceed;
    do {
        cout << "Please type the word you are looking for in Romeo and Juilet: ";
        cin >> word;
        cout << '\n';
        cout << "The word you typed is \'" << word << "\' is this correct? (Type Yes/No (Y/N)) ";
        cin >> response;
        cout << "\n";
        for (size_t i{0}; i < response.length(); i++) {
            response.at(i) = toupper(response.at(i));
        }
        proceed = testResponse(response);

    } while (proceed == false);
    return word;
}
bool caseSensitive(){
    string response;
    cout << "Would you like to search your word in a case sensitive fashion (Love and love would be 2 different words if case matters) ?"; cin >> response; cout << "\n";
    return testResponse(response);
}
bool testResponse(string &response){
    for(size_t i {0}; i < response.length(); i++){
        response.at(i)= toupper(response.at(i));
    }
    while(true){
    if (response == "YES" || response == "Y") {
        return true;
    }
    else if (response == "NO" || response == "N") {
        return false;
    }
    else {
        cout << "Invalid response! Please retype your response: ";
        cin >> response; cout << "\n";
    }
}
}
size_t search( ifstream &in_file,const string &word){
    string wordBeingCompared;
    size_t counter {0};
    while (in_file >> wordBeingCompared) {
        size_t found = wordBeingCompared.find(word);
        if(found != string::npos){
            counter++;
        }
    }
    return counter;
}
size_t searchCaseSensitive(ifstream &in_file,const string &word){
    string wordNonCaseSensitive = word;
    string wordBeingCompared;
    size_t counter {0};
    for(size_t j{0}; j < wordNonCaseSensitive.length(); j++){
        wordNonCaseSensitive.at(j) = toupper(wordNonCaseSensitive.at(j));
    }

    while (in_file >> wordBeingCompared) {
        for(size_t j{0}; j < wordBeingCompared.length(); j++){
            wordBeingCompared.at(j) = toupper(wordBeingCompared.at(j));
        }
        size_t found = wordBeingCompared.find(wordNonCaseSensitive);
        if(found != string::npos){
            counter++;
        }
    }
    return counter;
}
