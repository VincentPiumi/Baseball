#include "Team.h"
#include "Game.h"
#include "IO.h"

int main(int argc, char *argv[]){
  Team home_team("PUC");
  Team away_team("Becrews");

  home_team.add_player("Florian", 1, 1);
  home_team.add_player("Thomas", 2, 2);
  home_team.add_player("Nassim", 3, 3);
  home_team.add_player("Sohel", 4, 4);
  home_team.add_player("Laurent", 5, 5);
  home_team.add_player("Rémi", 6, 6);
  home_team.add_player("Maxime", 7, 7);
  home_team.add_player("Vincent", 8, 8);
  home_team.add_player("Rémy", 9, 9);

  away_team.add_player("Gégé1", 1, 1);
  away_team.add_player("Gégé2", 2, 2);
  away_team.add_player("Gégé3", 3, 3);
  away_team.add_player("Gégé4", 4, 4);
  away_team.add_player("Gégé5", 5, 5);
  away_team.add_player("Gégé6", 6, 6);
  away_team.add_player("Gégé7", 7, 7);
  away_team.add_player("Gégé8", 8, 8);
  away_team.add_player("Gégé9", 9, 9);

  Game game("0", home_team, away_team);
  game.play();

  Game_Winner(game);
  Game_Scoreline(game);
  return 0;
}