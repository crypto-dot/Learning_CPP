//
// Created by Carlos Arbizu on 1/22/21.
//

#include "Movie.h"
#include <iostream>
using std::cout;
using std::endl;

Movie::Movie(const string &name,const string &rating,const int &number_of_times_watched) : name{name},rating{rating},number_of_times_watched{number_of_times_watched}{

}
int Movie::getWatchednmbr() const{
    return number_of_times_watched;
}
string Movie::getname() const{
    return name;
}
string Movie::getrating() const{
    return rating;
}
void Movie::incrementWatchednmbr(){
    number_of_times_watched++;
}
Movie::Movie(Movie &&source)  noexcept : name{move(source.name)},rating{move(source.rating)},number_of_times_watched{source.number_of_times_watched} {
    cout << "The move constructor was called for movie" << endl;

}

Movie::Movie(const Movie &source) : Movie(source.name,source.rating,source.number_of_times_watched)
{
    cout << "The copy constructor was called for movie" << endl;
}
