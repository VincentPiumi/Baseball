#ifndef BASEBALL_PLAYER_H
#define BASEBALL_PLAYER_H

#include <string>

class Player {

public:
    Player(std::string  name, const int position, const int order);

    std::string name();
    int position();
    int order();

private:
    std::string p_name;
    int p_position;
    int p_order;
};

#endif //BASEBALL_PLAYER_H