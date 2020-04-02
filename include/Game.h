#ifndef BASEBALL_GAME_H
#define BASEBALL_GAME_H

#include "Team.h"
#include "Variables.h"

class Game {
public:
    Game(std::string game_id, Team& home_team, Team& away_team);

    void update_home_score(int runs);
    void update_away_score(int runs);
    void update_inning();

    int half_inning();
    void play();
    bool over();

    std::string winner();
    std::string id();
    Team home_team();
    Team away_team();

    int home_score();
    int away_score();
    std::vector<int> home_score_by_inning();
    std::vector<int> away_score_by_inning();

    int inning();
    int last_inning();

private:
    std::string g_id;
    Team g_home_team;
    Team g_away_team;

    int g_home_score{0};
    int g_away_score{0};
    std::vector<int> g_home_score_by_inning = std::vector<int>(VARIABLES::max_innings, 0);
    std::vector<int> g_away_score_by_inning = std::vector<int>(VARIABLES::max_innings, 0);

    int g_inning{0};
    int g_last_inning{0};
};

#endif //BASEBALL_GAME_H
