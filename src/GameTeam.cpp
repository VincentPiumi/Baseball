#include <algorithm>
#include <iostream>

#include "GameTeam.h"
#include "Inning.h"

GameTeam::GameTeam(Team & team, TeamStatus status) : gt_team(team), gt_status(status) {}

GameTeam& GameTeam::operator=(GameTeam other) {
  if(&other == this)
    return *this;
  gt_score_by_inning = other.gt_score_by_inning;
  gt_status = other.status();
  gt_team = other.team();
  return *this;
}

Team GameTeam::team() {return gt_team; }
TeamStatus GameTeam::status() {return gt_status; }

void GameTeam::update_score(int runs) {
  gt_score_by_inning.push_back(runs);
}

int GameTeam::current_score(int inning) {
  int final = 0;
  for (int sc = 0; sc < inning; sc++)
    final += gt_score_by_inning.at(sc);
  return final;
}
int GameTeam::final_score() {
  int final = 0;
  std::for_each(gt_score_by_inning.begin(), gt_score_by_inning.end(), [&] (int n) { final += n; });
  return final;
}

std::vector<int> GameTeam::score_by_inning() { return gt_score_by_inning; }

