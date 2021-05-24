//
// Created by Carlos Arbizu on 1/22/21.
//

#ifndef CPP_MOVIE_H
#define CPP_MOVIE_H
#include <string>
using std::string;
class Movie{
private:
    string name;
    string rating;
    int number_of_times_watched;
public:
    Movie(const string &name = "NA",const string &rating = "NA",const int &number_of_times_watched = -1);
    string getname() const;
    string getrating() const;
    int getWatchednmbr() const;
    void incrementWatchednmbr();
    Movie(Movie &&source) noexcept;
    Movie(const Movie &source);
};
#endif //CPP_MOVIE_H
