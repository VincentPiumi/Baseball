#include <random>
#include <algorithm>
#include <iostream>

#include "Inning.h"
#include "Random.h"

Inning::Inning(GameTeam & gt) : i_team(gt) {}

Inning &Inning::operator=(Inning other) {
  if(&other == this)
    return *this;
  i_outs = other.i_outs;
  i_points = other.i_points;
  i_bases = other.i_bases;
  i_team = other.i_team;
  return *this;
}

void Inning::half_inning() {
  initializer();
  while(i_outs < CONST::outs) {
    auto action = Random_Action();
    switch(action) {
      case Actions::HR : _homerun(); break;
      case Actions::SG : _single(); break;
      case Actions::DB : _double(); break;
      case Actions::TR : _triple(); break;
      case Actions::BB : _bb(); break;
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
  std::vector<int> tmp_bases = i_bases;
  for (int n = 0; n < i_bases.size(); n++) {
    if (tmp_bases.at(n) == 1 && n + (ac + 1) < i_bases.size()) {
      i_bases.at(n + (ac + 1)) = 1;
    }
  }
  for (int n = 0; n < ac; n++) {
    i_bases.at(n) = 0;
  }
  i_bases.at(ac) = 1;
}

void Inning::_single() {
  update_points(2);
  update_bases(0);
}

void Inning::_bb() {
  update_points(2);
  update_bases(0);
}

void Inning::_double() {
  update_points(1);
  update_bases(1);
}

void Inning::_triple() {
  update_points(0);
  update_bases(2);
}

void Inning::_homerun() {
  std::for_each(i_bases.begin(), i_bases.end(), [&] (int n) { i_points += n; });
  std::fill(i_bases.begin(), i_bases.end(), 0);
  i_points += 1;
}

std::vector<int> Inning::bases() {
  return i_bases;
}

int Inning::outs() {
  return i_outs;
}

int Inning::points() {
  return i_points;
}