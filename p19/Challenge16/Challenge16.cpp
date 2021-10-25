//
// Created by Carlos Arbizu on 9/20/21.
//
#include "Song.h"
using std::cout;
#include <list>
using std::list;
using std::cin;
using std::string;
#include <algorithm>
using std::advance;
using std::for_each;
using std::distance;

using std::any_of;
using std::find;

#include <cctype>
#include <sstream>
using std::istringstream;
using std::toupper;
using std::getline;
void mainMenu(list<Song> &songList);
void selectionMenu();
bool executeSelection(const char &c,list<Song> &songList,auto &currentSongLocation);
void addSong(auto &currentSongLocation,list<Song> &songList);
void songQueue(list<Song> &songList);
void prevSong(auto &currentSongLocation,const list<Song> &songList);
void nextSong( auto &currentSongLocation,const list<Song> &songList);
bool checkIfContainsChar(const string &input);
int main(){
    list<Song> StartingsongList {
            {"God's Plan","Drake",5},{"Starboy","The Weeknd",5},{"Stairway To Heaven", "Led Zeppelin",4}
    };
    mainMenu( StartingsongList);
    return 0;
}

void mainMenu(list<Song> &songList){
    bool done;
    char input;
    auto currentSongLocation {songList.cbegin()};
    songQueue(songList);
    do {
        selectionMenu();
        cin >> input;
        cout << '\n';
        done = executeSelection(toupper(input),songList,currentSongLocation);
    }
    while(!done);
}
void selectionMenu(){
        cout << "C - Current Song \n";
        cout << "N - Next Song \n";
        cout << "P - Previous Song \n";
        cout << "F - First Song \n";
        cout << "A - Add and Play Song at the current location\n";
        cout << "L - List current playlist \n";
        cout << "Q - Quit Song Playlist \n";
}

bool executeSelection(const char &c,list<Song> &songList,auto &currentSongLocation){
    switch(c){
        case 'A':
        {
            addSong(currentSongLocation,songList);
            return false;
        }
        case 'C':
            cout << "Current song now playing: " << *currentSongLocation << "\n\n";
            return false;
        case 'Q':
            cout << "Quitting... \n";
            return true;
        case 'N':
        {
            nextSong(currentSongLocation,songList);
            return false;
        }
        case 'P':
        {
            prevSong(currentSongLocation, songList);
            return false;
        }
        case 'L':
        {
            songQueue(songList);
            return false;
        }
        case 'F':
        {
            currentSongLocation = songList.cbegin();
            cout << "Current Song now playing: " << *currentSongLocation << "\n\n";
            return false;
        }
        default:
            cout << "Invalid response! Listing all commands\n";
            selectionMenu();
            return false;
    }

}
void addSong(auto &currentSongLocation,list<Song> &songList) {
    string input;
    string name;
    string artistName;
    uint16_t rating;
    bool correctRating {false};

    cout << "Adding a song to current location \n";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();
    cout << "Input the song name: "; getline(cin,name,'\n'); cout << "\n";
    cin.clear();

    cout << "Input the Artist(s) name(s): "; getline(cin,artistName,'\n'); cout << "\n";

    do{
        cout << "Input your rating (1 - 5) : "; cin >> input; cout << "\n";
        istringstream iss{input};

        if(iss >> rating){
            if(rating == 0){
                cout << "ERROR Invalid rating (Zero is not a valid rating) \n";
            }
            else if (rating > 5){
                cout << "ERROR Invalid rating (number too large) \n";
            }
            else {correctRating= true;}
        }
        else if (checkIfContainsChar(input)){
            cout << "ERROR Invalid rating (contains character)! \n";
        }
        else {
            cout << "ERROR Invalid rating (number too large or negative! ) \n";
        }
    }
    while(!correctRating);
    Song songEntry {name,artistName,rating};
    auto it = find(songList.begin(),songList.end(),songEntry);
    if(it != songList.end()){
        cout << "The element is already in the list! \n";
    }
    else {
        songList.emplace(currentSongLocation,songEntry);
    }
    prevSong(currentSongLocation,songList);
}
void songQueue(list<Song> &songList){
    cout << std::setfill('=') << std::setw(30) << "" << "Song Queue" << std::setw(30) << "" << std::setfill(' ') << "\n";
    for(const auto &song : songList){
        cout << song << "\n";
    }
    cout << "\n";
}
void nextSong(auto &currentSongLocation,const list<Song> &songList){
    advance(currentSongLocation,1);
    if(currentSongLocation == songList.cend()){
        //Do not need to specify constant iterator const container automatically return iterators to const elements
        currentSongLocation = songList.cbegin();
    }
    cout << "Current Song now playing: " << *currentSongLocation << "\n\n";
}
void prevSong(auto &currentSongLocation,const list<Song> &songList){
    if(currentSongLocation == songList.cbegin()){
        //Prev can be used instead of advance to move iterators backwards

        currentSongLocation = songList.cend();
    }
    currentSongLocation--;
    cout << "Current Song now playing: " << *currentSongLocation << "\n\n";
}
bool checkIfContainsChar(const string &input ){
    bool returnVal;
    for_each(input.begin(),input.end(),[&returnVal](const char &c)
    {if(isalpha(c))
    {
        returnVal = true;
    }
    });
    return returnVal;
}
