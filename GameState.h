//
// Created by LEI on 2/8/2018.
//


#ifndef MONOPOLYC_V2_GAMESTATE_H
#define MONOPOLYC_V2_GAMESTATE_H

#include "Player.h"
#include <iostream>
#include <vector>
#include "Board.h"
#include "Rules.h"
#include "DiceRoller.h"

class GameState{
 public:
  GameState (const std::string& rules_file_name, const std::string& board_file_name, const std::string& random_nums_file_name);
  Board& get_board();
  int get_num_players();
  int get_num_players_left();
  DiceRoller& get_diceRoller();
  int get_current_turn();
  //Player get_current_player();
  std::vector<Player>& get_playersvec();
  int get_current_player_id();
  void set_players();
  std::string& get_current_player_name();
  Player& get_current_player();
  void set_num_space();
  int get_num_space();
  //Player& get_player_address();


 private:
  Board  board;
  std::vector<Player> playersvec;
  Rules rule;
  DiceRoller diceRoller;
  int num_of_players;
  int num_of_players_left;
  int current_turn;
  //int player_id;
  int current_player_id;
  std::string current_player_name;
  int num_space;
 // Player current_player;
};
#endif //MONOPOLYC_V2_GAMESTATE_H
