#include <string>
#include <iostream>

#include <Inning.h>
#include "Game.h"
#include "Team.h"
#include "GameTeam.h"

#include "Variables.h"


Game::Game(std::string game_id, Team& home_team, Team& away_team) : g_id(std::move(game_id)),
                                                                    g_home_team(GameTeam(home_team, TeamStatus::HOME)),
                                                                    g_away_team(GameTeam(away_team, TeamStatus::AWAY)) {}

void Game::play() {
  while( !over() ) {
    play_inning(g_home_team);
    play_inning(g_away_team);
    update_inning();
  }
}

bool Game::over() { return g_inning >= CONST::innings && g_home_team.current_score(g_inning) != g_away_team.current_score(g_inning); }
Team Game::winner() { return g_home_team.final_score() > g_away_team.final_score() ? g_home_team.team() : g_away_team.team(); }

void Game::update_inning() { g_inning++; }

void Game::play_inning(GameTeam & gt) {
  Inning inn(gt);
  inn.half_inning();
}

std::string Game::id() { return g_id; }
GameTeam Game::home_team() { return g_home_team; }
GameTeam Game::away_team() { return g_away_team; }


