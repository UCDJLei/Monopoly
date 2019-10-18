//
// Created by LEI on 2/10/2018.
//
#ifndef MONOPOLYC_V2_MOVE_H
#define MONOPOLYC_V2_MOVE_H
#include "GameState.h"

class Space;

class Move{
 public:
  Move(GameState& gamestate);
 // Move(int turn);
  //int move_step(int dice1, int dice2);
 // Move(GameState gameState);
  Space* current_space;
  Space* new_space;
  GameState* gameState;

  bool roll_dice;
  bool leave_game;


   int dice1;
   int dice2;
   int dice;

  int curret_position;
  int new_position;

  int current_owner_id;
  int num_round_pass_go;

  void get_move(GameState& gamestate);
  void make_move(GameState& gamestate);
  char action;

  bool property_is_owned_by_same_player(int position_ID);
};
#endif //MONOPOLYC_V2_MOVE_H
