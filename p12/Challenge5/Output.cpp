//
// Created by Carlos Arbizu on 1/22/21.
//
#include "Movie.h"
#include "Movies.h"
int main(){

    Movies movies;
    movies.add("Cinderalla","PG13",0);
    movies.incrementMovieWatched("Cinderalla");

    const string &&str = "hello";
    const string &&str1 = "PG13";
    const int &&int1 = 2;
    movies.add(str,str1,int1);


    movies.add("Cinderalla","PG13",0);

    movies.ptrAddress();

    Movies movies1{movies};

    movies1.ptrAddress();
    movies.displayAllMovies();

    vector<Movies> listofMovieslists;
    listofMovieslists.push_back(movies);
    listofMovieslists.push_back(movies1);


    return 0;

}