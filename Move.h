//
// Created by LEI on 2/10/2018.
//
#ifndef MONOPOLYC_V2_MOVE_H
#define MONOPOLYC_V2_MOVE_H
#include "GameState.h"

class Space;

class Move{
 public:
  Move();
 // Move(int turn);
  //int move_step(int dice1, int dice2);
 // Move(GameState gameState);
  Space* current_space;
  Space* new_space;


  bool roll_dice;
  bool leave_game;


  unsigned int dice1;
  unsigned int dice2;
   int dice;

  int curret_position;
  int new_position;

  void get_move(GameState gamestate);
  void make_move(GameState gamestate);

};
#endif //MONOPOLYC_V2_MOVE_H
