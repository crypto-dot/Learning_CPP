//
// Created by Carlos Arbizu on 1/22/21.
//

#ifndef CPP_MOVIES_H
#define CPP_MOVIES_H
#include <vector>
#include "Movie.h"

using std::vector;


class Movies {
private:
    vector<Movie> *movieslist{nullptr};
public:
    Movies();
    void add(const string &name,const string &rating,int timesWatched);
    void incrementMovieWatched(string moviename);
    void displayAllMovies() const;
    Movies(const Movies &source) noexcept;
    Movies(Movies &&source) noexcept ;
    void ptrAddress();
    ~Movies();
};


#endif //CPP_MOVIES_H
