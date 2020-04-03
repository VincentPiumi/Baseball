#include <cstring>
#include <cstdlib>
#include <random>
#include <iostream>

#include "Inning.h"

Inning::Inning(GameTeam & gt) : i_team(gt) {}

void Inning::half_inning() {
  initializer();
  std::random_device rd;
  std::mt19937 mt(rd());

  while(i_outs < VARIABLES::outs) {
    std::uniform_real_distribution<float> dist(0.0, 2.0);
    auto action = static_cast<Actions>(int(dist(mt)));
    switch(action) {
      case Actions::HR :
        i_points++;
      case Actions::OUT :
        i_outs++;
    }
  }
  i_team.update_score(i_points);
}

void Inning::initializer() {
  i_outs = 0;
  i_points = 0;
  memset(i_bases, 0, VARIABLES::bases);
}