#ifndef BASEBALL_GAMETEAM_H
#define BASEBALL_GAMETEAM_H

#include "Team.h"
#include "Variables.h"

class GameTeam {

public:
    GameTeam(Team & team, TeamStatus status);
    GameTeam& operator=(GameTeam other);

    Team team();
    TeamStatus status();

    std::vector<int> score_by_inning();
    int current_score(int inning);
    int final_score();
    void update_score(int runs);

private:
    Team & gt_team;
    TeamStatus gt_status;

    std::vector<int> gt_score_by_inning;
};

#endif //BASEBALL_GAMETEAM_H
