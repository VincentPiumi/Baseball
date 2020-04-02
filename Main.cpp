#include "time.h"
#include<iostream>
#include <utility>
#include <vector>

enum class Actions {HR, OUT};
enum class TeamStatus {HOME, AWAY};

struct Rules {
    const int g_innings = 9;
    const int g_outs = 3;
};

class Player {
public:
    explicit Player(std::string  name, const int position, const int order) : p_name(std::move(name)), p_position(position), p_order(order) {}

private:
    std::string p_name;
    int p_position;
    int p_order;
};

class Team {

public:
    explicit Team(std::string name, TeamStatus status) : t_name(std::move(name)), t_status(status) {
      t_players.reserve(9); // VARIABLE
    }

    void add_player(const Player& p) {
      if (t_players.size() < 9) {
        t_players.push_back(p);
      } else {
        std::cout << "Already enough players on the lineup" << std::endl;
      }
    }

    void add_player(const std::string& name, const int& position, const int& order) {
      add_player(Player(name, position, order));
    }

    std::string get_team_name() {
      return t_name;
    }

    TeamStatus get_team_status() {
      return t_status;
    }

private:
    std::string t_name;
    std::vector<Player> t_players;
    TeamStatus t_status;
};

class Game {
public:
    explicit Game(std::string game_id, Team& home_team, Team& away_team) : g_id(std::move(game_id)), g_home_team(home_team), g_away_team(away_team) {}

    void update_home_score(int runs) { g_home_score += runs; g_home_score_by_inning.at(g_inning) = runs;}
    void update_away_score(int runs) { g_away_score += runs; g_away_score_by_inning.at(g_inning) = runs;}
    void update_inning() { g_inning++;}

    bool over() { return g_inning >= 9 && g_home_score != g_away_score; }
    std::string winner() { return g_home_score > g_away_score ? g_home_team.get_team_name() : g_away_team.get_team_name(); }

    int get_inning() { return g_inning; }
    std::string get_id() { return g_id; }

    int half_inning(Team t) {
      int outs = 0, points = 0;
      while(outs < 3) {
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

    void play() {
      while( !over() ) {
        update_home_score(half_inning(g_home_team));
        update_away_score(half_inning(g_away_team));
        update_inning();
      }
      g_last_inning = g_inning;
    }

    void scoreline() {
      std::cout << g_away_team.get_team_name() << " ";
      for (int point = 0; point < g_last_inning; point++) {
        std::cout << g_away_score_by_inning.at(point) << " | ";
      }
      std::cout << std::endl;
      std::cout << g_home_team.get_team_name() << "     ";
      for (int point = 0; point < g_last_inning; point++) {
        std::cout << g_home_score_by_inning.at(point) << " | ";
      }
    }

private:
    std::string g_id;
    Team g_home_team;
    Team g_away_team;

    int g_home_score{0};
    int g_away_score{0};
    std::vector<int> g_home_score_by_inning = std::vector<int>(25, 0);
    std::vector<int> g_away_score_by_inning = std::vector<int>(25, 0);

    int g_inning{0};
    int g_last_inning{0};
};

int main(int argc, char *argv[]){

  srand(time(NULL));

  Team home_team("PUC", TeamStatus::HOME);
  Team away_team("Becrews", TeamStatus::AWAY);

  home_team.add_player("Florian", 1, 1);
  home_team.add_player("Thomas", 2, 2);
  home_team.add_player("Nassim", 3, 3);
  home_team.add_player("Sohel", 4, 4);
  home_team.add_player("Laurent", 5, 5);
  home_team.add_player("Rémi", 6, 6);
  home_team.add_player("Maxime", 7, 7);
  home_team.add_player("Vincent", 8, 8);
  home_team.add_player("Rémy", 9, 9);

  away_team.add_player("Gégé", 1, 1);
  away_team.add_player("Gégé", 2, 2);
  away_team.add_player("Gégé", 3, 3);
  away_team.add_player("Gégé", 4, 4);
  away_team.add_player("Gégé", 5, 5);
  away_team.add_player("Gégé", 6, 6);
  away_team.add_player("Gégé", 7, 7);
  away_team.add_player("Gégé", 8, 8);
  away_team.add_player("Gégé", 9, 9);

  Game game("0", home_team, away_team);
  game.play();

  std::cout << "Winner of game " << game.get_id() << " : " << game.winner() << std::endl;
  game.scoreline();
   return 0;
}