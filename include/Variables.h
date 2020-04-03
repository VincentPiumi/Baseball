#ifndef BASEBALL_VARIABLES_H
#define BASEBALL_VARIABLES_H

enum class TeamStatus {HOME, AWAY};
enum class Actions {HR, OUT};

struct VARIABLES {
    static int const outs = 3;
    static int const players = 9;
    static int const innings = 9;
    static int const max_innings = 25;
    static int const bases = 4;
};
#endif //BASEBALL_VARIABLES_H
