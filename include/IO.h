#ifndef BASEBALL_IO_H
#define BASEBALL_IO_H

#include <iostream>

struct IO {
    static void scoreline(Game game) {
      std::cout << game.away_team().team().name() << " ";
      for (int point : game.away_team().score_by_inning()) {
        std::cout << point << " | ";
      }
      std::cout << std::endl;
      std::cout << game.home_team().team().name() << "     ";
      for (int point : game.home_team().score_by_inning()) {
        std::cout << point << " | ";
      }
    }

    static void winner(Game game) {
      std::cout << "Winner of game " << game.id() << " : " << game.winner().name() << std::endl;
    }
};

#define GAME_SCORELINE(GAME) IO::scoreline(GAME)
#define GAME_WINNER(GAME) IO::winner(GAME)

#endif //BASEBALL_IO_H
