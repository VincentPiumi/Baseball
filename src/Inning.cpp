#include <random>
#include <algorithm>

#include "Inning.h"

Inning::Inning(GameTeam & gt) : i_team(gt) {}

void Inning::half_inning() {
  initializer();
  std::random_device rd;
  std::mt19937 mt(rd());

  while(i_outs < VARIABLES::outs) {
    std::uniform_real_distribution<float> dist(0.0, 5.0);
    auto action = static_cast<Actions>(int(dist(mt)));

    switch(action) {
      case Actions::HR : _homerun(); break;
      case Actions::SG : _single(); break;
      case Actions::DB : _double(); break;
      case Actions::TR : _triple(); break;
      case Actions::OUT : i_outs++; break;
      default: break;
    }
  }
  i_team.update_score(i_points);
}

void Inning::initializer() {
  i_outs = 0;
  i_points = 0;
  std::fill(i_bases.begin(), i_bases.end(), 0);
}

void Inning::update_points(int ac) {
  std::for_each(i_bases.begin() + ac, i_bases.end(), [&] (int n) { i_points += n; });
}

void Inning::update_bases(int ac) {
  for (int n = 0; n < i_bases.size(); n++) {
    if (n < ac) i_bases.at(n) = 0;
    else i_bases.at(n) = i_bases.at(n - ac);
  }
  i_bases.at(ac) = 1;
}

void Inning::_single() {
  update_points(3);
  update_bases(0);
}

void Inning::_double() {
  update_points(2);
  update_bases(1);
}

void Inning::_triple() {
  update_points(1);
  update_bases(2);
}

void Inning::_homerun() {
  update_points(0);
  update_bases(3);
}