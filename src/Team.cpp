#include <string>
#include <iostream>

#include "Team.h"
#include "Player.h"
#include "Variables.h"

Team::Team(std::string name) : t_name(std::move(name)) {
  t_players.reserve(VARIABLES::players); // VARIABLE
}

void Team::add_player(const Player& p) {
  if (t_players.size() < VARIABLES::players) {
    t_players.push_back(p);
  } else {
    std::cout << "Already enough players on the lineup" << std::endl;
  }
}

void Team::add_player(const std::string& name, const int& position, const int& order) {
  add_player(Player(name, position, order));
}

std::string Team::name() {
  return t_name;
}