#ifndef BASEBALL_RANDOM_H
#define BASEBALL_RANDOM_H

#include <random>

#include "Singleton.h"
#include "Variables.h"

class Random : public Singleton<Random>{
public:
    Actions generate_play() {
      std::random_device rd;
      std::mt19937 mt(rd());
      std::uniform_real_distribution<double> dist(1, VARIABLES::prob + 1);
      auto generated = dist(mt);
      return action_range(generated);
    }

private:

    Actions action_range(double rand) {
      if (single_range(rand)) {
        return Actions::SG;
      } else if (double_range(rand)) {
        return Actions::DB;
      } else if (triple_range(rand)) {
        return Actions::TR;
      } else if (hr_range(rand)) {
        return Actions::HR;
      } else if (bb_range(rand)) {
        return Actions::BB;
      } else {
      return Actions::OUT;
      }
    }

    bool single_range(double rand) {
      return rand >= 1.0 && rand < RANDOMSTATS::_single;
    }

    bool double_range(double rand) {
      return rand >= RANDOMSTATS::_single && rand < RANDOMSTATS::_double;
    }

    bool triple_range(double rand) {
      return rand >= RANDOMSTATS::_double && rand < RANDOMSTATS::_triple;
    }

    bool hr_range(double rand) {
      return rand >= RANDOMSTATS::_triple && rand < RANDOMSTATS::_homerun;
    }

    bool bb_range(double rand) {
      return rand >= RANDOMSTATS::_homerun && rand < RANDOMSTATS::_bb;
    }
};

#define Random_Action() Random::instance().generate_play()

#endif //BASEBALL_RANDOM_H
