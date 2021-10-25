//
// Created by Carlos Arbizu on 9/20/21.
//

#ifndef CPP_SONG_H
#define CPP_SONG_H
#include <string>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <algorithm>
class Song {
public:
    Song()= default;
    Song(std::string name, std::string artists, uint16_t rating);
    uint16_t getRating() const;
    const std::string &getName() const;
    const std::string &getArtists() const;
    friend std::ostream &operator<<(std::ostream &ostream1, const Song &song);
    //important note if you want to use STL containers for custom classes you MUST overload
    //the following operators
    friend bool operator<(const Song &lhs,const Song &rhs);
    friend bool operator==(const Song &lhs,const Song &rhs);

private:
    std::string name;
    std::string artists;
    uint16_t rating;
};


#endif //CPP_SONG_H
