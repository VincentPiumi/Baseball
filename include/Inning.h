#ifndef BASEBALL_INNING_H
#define BASEBALL_INNING_H

#include "GameTeam.h"
#include "Variables.h"

class Inning {
public:
    explicit Inning(GameTeam & gt);

    void half_inning();
    void initializer();

private:

    GameTeam & i_team;

    int i_bases[VARIABLES::bases] = {0, 0, 0, 0};
    int i_outs{0};
    int i_points{0};
};

#endif //BASEBALL_INNING_H
