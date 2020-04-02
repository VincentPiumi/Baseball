#ifndef BASEBALL_IO_H
#define BASEBALL_IO_H

#include <iostream>

struct IO {
    static void scoreline(Game game) {
      std::cout << game.away_team().name() << " ";
      for (int point = 0; point < game.last_inning(); point++) {
        std::cout << game.away_score_by_inning().at(point) << " | ";
      }
      std::cout << std::endl;
      std::cout << game.home_team().name() << "     ";
      for (int point = 0; point < game.last_inning(); point++) {
        std::cout << game.home_score_by_inning().at(point) << " | ";
      }
    }

    static void winner(Game game) {
      std::cout << "Winner of game " << game.id() << " : " << game.winner() << std::endl;
    }
};

#define GAME_SCORELINE(GAME) IO::scoreline(GAME)
#define GAME_WINNER(GAME) IO::winner(GAME)

#endif //BASEBALL_IO_H
