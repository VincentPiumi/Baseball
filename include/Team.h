#ifndef BASEBALL_TEAM_H
#define BASEBALL_TEAM_H

#include <vector>

#include "Player.h"
#include "Variables.h"

class Team {

public:
    explicit Team(std::string name);

    void add_player(const Player& p);
    void add_player(const std::string& name, const int& position, const int& order);

    std::string name();

private:
    std::string t_name;
    std::vector<Player> t_players;
};

#endif //BASEBALL_TEAM_H
