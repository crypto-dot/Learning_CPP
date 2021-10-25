//
// Created by Carlos Arbizu on 9/20/21.
//

#include "Song.h"
Song::Song(std::string name, std::string artists, uint16_t rating) : name{std::move(name)}, artists{std::move(artists)}, rating{rating} {
    if(rating > 5){
        this->rating = 5;
    }
    else {
        this->rating = rating;
    }
}

const std::string &Song::getArtists() const{
    return artists;
}
const std::string &Song::getName() const{
    return name;
}
uint16_t Song::getRating() const {
    return rating;
}

std::ostream &operator<<(std::ostream &ostream1, const Song &song){
    ostream1 << std::setw(30)<< std::left << song.getName() << std::setw(30) << song.getArtists() << std::setw(5) <<std::right << song.getRating();
    return ostream1;
}

bool operator<(const Song &lhs,const Song &rhs){
    return lhs.getName() < rhs.getName();
}
bool operator==(const Song &lhs,const Song &rhs){
    std::string lhsString {lhs.getName()};
    std::string rhsString {rhs.getName()};

    std::transform(lhsString.begin(),lhsString.end(),lhsString.begin(),[](const char &c){
        if(isalpha(c)) { return std::tolower(c); }
        return static_cast<int>(c);
    });
    std::transform(rhsString.begin(),rhsString.end(),rhsString.begin(),[](const char &c){
        if(isalpha(c)) { return std::tolower(c); }
        return static_cast<int>(c);
    });

    lhsString.erase(std::remove(lhsString.begin(),lhsString.end(),' '),lhsString.end());
    rhsString.erase(std::remove(rhsString.begin(),rhsString.end(),' '),rhsString.end());

    return lhsString == rhsString;
}