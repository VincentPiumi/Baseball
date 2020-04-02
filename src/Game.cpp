#include <string>
#include <iostream>

#include "Game.h"
#include "Team.h"
#include "Variables.h"

Game::Game(std::string game_id, Team& home_team, Team& away_team) : g_id(std::move(game_id)), g_home_team(home_team), g_away_team(away_team) {}

void Game::update_home_score(int runs) {
  g_home_score += runs;
  g_home_score_by_inning.at(g_inning) = runs;
}
void Game::update_away_score(int runs) {
  g_away_score += runs;
  g_away_score_by_inning.at(g_inning) = runs;
}
void Game::update_inning() { g_inning++;}

int Game::half_inning() {
  int outs = 0, points = 0;
  while(outs < VARIABLES::outs) {
    Actions action = static_cast<Actions>(rand() % 2);
    switch(action) {
      case Actions::HR :
        points++;
      case Actions::OUT :
        outs++;
    }
  }
  return points;
}

void Game::play() {
  while( !over() ) {
    update_home_score(half_inning());
    update_away_score(half_inning());
    update_inning();
  }
  g_last_inning = g_inning;
}

bool Game::over() { return g_inning >= VARIABLES::innings && g_home_score != g_away_score; }

std::string Game::winner() { return g_home_score > g_away_score ? g_home_team.name() : g_away_team.name(); }

std::string Game::id() { return g_id; }
Team Game::home_team() { return g_home_team; }
Team Game::away_team() { return g_away_team; }

int Game::home_score() { return g_home_score; }
int Game::away_score() { return g_away_score; }
std::vector<int> Game::home_score_by_inning() { return g_home_score_by_inning; }
std::vector<int> Game::away_score_by_inning() { return g_away_score_by_inning; }

int Game::inning() { return g_inning; }
int Game::last_inning() { return g_last_inning; }


