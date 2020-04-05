#ifndef BASEBALL_INNING_H
#define BASEBALL_INNING_H

#include "GameTeam.h"
#include "Variables.h"

class Inning {
public:
    explicit Inning(GameTeam & gt);

    Inning& operator=(Inning other);

    void half_inning();

    void initializer();
    void update_points(int ac);
    void update_bases(int ac);

    void _single();
    void _double();
    void _triple();
    void _homerun();
    void _bb();

    std::vector<int> bases();
    int outs();
    int points();

private:
    GameTeam & i_team;
    std::vector<int> i_bases{0, 0, 0};
    int i_outs{0};
    int i_points{0};
};

#endif //BASEBALL_INNING_H
