#ifndef BASEBALL_VARIABLES_H
#define BASEBALL_VARIABLES_H

enum class TeamStatus {HOME, AWAY};
enum class Actions {HR, SG, DB, TR, OUT};
enum class Positions {DH, P, C, FB, SB, TB, SS, LF, CF, RF};

struct VARIABLES {
    static int const outs = 3;
    static int const players = 9;
    static int const innings = 9;
};
#endif //BASEBALL_VARIABLES_H
