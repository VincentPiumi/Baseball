#ifndef BASEBALL_GAME_H
#define BASEBALL_GAME_H

#include "Team.h"
#include "GameTeam.h"
#include "Variables.h"

class Game {
public:
    Game(std::string game_id, Team& home_team, Team& away_team);

    void play();
    bool over();
    Team winner();

    void update_inning();
    void play_inning(GameTeam & gt);

    std::string id();
    GameTeam home_team();
    GameTeam away_team();

private:
    std::string g_id;
    GameTeam g_home_team;
    GameTeam g_away_team;

    int g_inning{0};
};

#endif //BASEBALL_GAME_H
