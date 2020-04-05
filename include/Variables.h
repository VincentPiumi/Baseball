#ifndef BASEBALL_VARIABLES_H
#define BASEBALL_VARIABLES_H

enum class TeamStatus {HOME, AWAY};
//TODO : Reach on error ?
enum class Actions {HR, SG, DB, TR, BB, OUT};
enum class Positions {DH, P, C, FB, SB, TB, SS, LF, CF, RF};

struct VARIABLES {
    static int const prob = 1000;
};

struct CONST {
    static int const outs = 3;
    static int const bases = 3;
    static int const players = 9;
    static int const innings = 9;
};

struct GLOBALSTATS {
    static double constexpr rpg = 4.83;
    static double constexpr pa = 38.39;
    static double constexpr ab = 34.30;
    static double constexpr r = 4.83;
    static double constexpr h = 8.65;
    static double constexpr sg = 5.35;
    static double constexpr db = 1.76;
    static double constexpr tr = 0.16;
    static double constexpr hr = 1.39;
    static double constexpr rbi = 4.63;
    static double constexpr sb = 0.47;
    static double constexpr cs = 0.17;
    static double constexpr bb = 3.27;
    static double constexpr so = 8.81;
};

struct RANDOMSTATS {
    static double constexpr _single = (GLOBALSTATS::sg * VARIABLES::prob) / GLOBALSTATS::pa;
    static double constexpr _double = _single + ((GLOBALSTATS::db * VARIABLES::prob) / GLOBALSTATS::pa);
    static double constexpr _triple = _double + ((GLOBALSTATS::tr * VARIABLES::prob) / GLOBALSTATS::pa);
    static double constexpr _homerun = _triple + ((GLOBALSTATS::hr * VARIABLES::prob) / GLOBALSTATS::pa);
    static double constexpr _bb = _homerun + ((GLOBALSTATS::bb * VARIABLES::prob) / GLOBALSTATS::pa);
};

#endif //BASEBALL_VARIABLES_H
