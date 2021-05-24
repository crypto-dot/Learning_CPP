//
// Created by Carlos Arbizu on 12/6/20.
//

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(){
    string alphabet {"abcdefghijklmnopqrstuvwxyz"};
    string cypher {"stuvwxyzjklmfghinopabcdeqr"};
    string secret_message {""};

     cout << "Input your secret message: "; getline(cin,secret_message); cout  << endl;
     for(size_t i {0}; i < secret_message.length(); i++){
         if(isalpha(secret_message[i]) && islower(secret_message[i])){
            secret_message[i] = toupper(cypher[ 25 - alphabet.find(secret_message[i])]);
         }
         else if(isalpha(secret_message[i]) && isupper(secret_message[i])){
             secret_message[i] = tolower(secret_message[i]);
             secret_message[i] = cypher[25 - alphabet.find( secret_message[i])];
         }
     }
     cout << "------------------------------------------------------------------------------------" << endl;
     cout << "Encrpyting Message........" << endl;
     cout << "Your secret Message: " << secret_message << endl;
     cout << "------------------------------------------------------------------------------------" << endl;
    for(size_t i {0}; i < secret_message.length(); i++){
        if(isalpha(secret_message[i]) && islower(secret_message[i])){
            secret_message[i] = toupper(alphabet[25 - cypher.find(secret_message[i])]);
        }
        else if(isalpha(secret_message[i]) && isupper(secret_message[i])){
            secret_message[i] = tolower(secret_message[i]);
            secret_message[i] = alphabet[25 - cypher.find(secret_message[i])];
        }

    }
     cout << "Decrpyting Message........" << endl;
     cout << "Your secret Message: " << secret_message << endl;




    return 0;
};