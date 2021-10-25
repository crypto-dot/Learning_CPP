//
// Created by Carlos Arbizu on 9/11/21.
//
#include <algorithm>
using std::find;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::ostream;
#include <string>

using std::string;
struct Player {
public:
    Player() = default;
    Player(uint64_t xp, uint64_t hp, string name) : xp(xp), hp(hp), name(std::move(name)){
    }

private:
    uint64_t xp;
    uint64_t hp;
    string name;

    friend bool operator==(const Player &lhs, const Player &rhs){
        if(lhs.xp == rhs.xp && lhs.hp == rhs.hp && lhs.name == rhs.name)
        {
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &ostream1, const Player &player){
        ostream1 << player.name << " xp: " << player.xp << " hp: " << player.hp;
        return ostream1;
    }
};
int main(){
    Player player {100,100,"Sam"};
    Player player2 {200,100,"Mike"};
    Player player3 {100,100,"Matt"};
    Player player4 {109,100,"Sam"};

    vector<Player> team {player,player2,player3,player4};


    auto loc = find(team.begin(),team.end(),Player(100,100,"Sam"));

    if(loc != team.end()){
        cout << "Found Player: " << *loc << "\n";
    }
    else {
        cout << "Player was not found. \n";
    }
    return 0;
}