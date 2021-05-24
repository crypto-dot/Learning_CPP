//
// Created by Carlos Arbizu on 1/22/21.
//

#include "Movies.h"
#include <iostream>
using std::cout;
using std::endl;

Movies::Movies() : movieslist{new std::vector<Movie>} {
}

Movies::Movies(const Movies &source) noexcept : movieslist{new std::vector<Movie>}{
        for(const Movie& movie : *source.movieslist){
            movieslist->push_back(movie);
        }
        cout << "Copy constructor called for movies " << endl;
}
void Movies::ptrAddress(){
    cout << "Address of pointer is" << movieslist << endl;
}
Movies::~Movies() {
    delete movieslist;
    cout << "Destructor called " << endl;
}
void Movies::add(const string &name,const string &rating, int timesWatched) {
        Movie movie(name,rating,timesWatched);
        int index {-1};
        for(int i {0}; i < movieslist->size(); i++){
            if(movie.getname() == movieslist->at(i).getname()){
                index = i;
            }
        }
        if(index == -1){
            movieslist->push_back(movie);
            cout << "Movie added!" << endl;
        }
        else{
            cout << "ERROR the movie is already in the movies list, at index " << index << " !" << endl;
        }
}


void Movies::incrementMovieWatched(string moviename) {
    string name = move(moviename);
    if(movieslist->empty()){
        cout << "The movie list is empty!" << endl;
    }
    else {
        int index{-1};
        for(int i {0}; i < movieslist->size(); i++){
            if(name == movieslist->at(i).getname()){
                index = i;
            }
        }
        if(index == -1){
            cout << "ERROR the movie is not in the movies list!" << endl;
        }
        else{
            movieslist->at(index).incrementWatchednmbr();
            cout << "Movie watched!" << endl;
        }
    }

}
void Movies::displayAllMovies() const {
    if(movieslist->empty()){
        cout << "ERROR the movies list is empty!" << endl;

    }
    else {
        for(const Movie& movie : *movieslist){
            cout << "Movie: " << movie.getname() << endl;
            cout << "Rating: " << movie.getrating() << endl;
            cout << "Times watched: " << movie.getWatchednmbr() << endl;
        }
    }
}

Movies::Movies(Movies &&source) noexcept : movieslist{source.movieslist} {
    source.movieslist = nullptr;
    cout << "The move constructor was called for movies" << endl;
}

