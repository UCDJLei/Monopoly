//
// Created by LEI on 2/9/2018.
//

#ifndef MONOPOLYC_V2_PLAYER_H
#define MONOPOLYC_V2_PLAYER_H
#include <iostream>
#include <stdio.h>
class Space;

class Player{
 public:
  Player(std::string& input_name, int player_id);
  int get_cash();
  std::string& get_name();
  bool get_in_game();
  int get_position();
  int get_player_id();
  Space*& get_space_ptr();
  //Player& get_player_address();
  Space* space_ptr;

 private:
  std::string name;
  int cash;
  bool in_the_game;
  int property_worth;
  int asset;
  int position;
  int player_id;
};
#endif //MONOPOLYC_V2_PLAYER_H
