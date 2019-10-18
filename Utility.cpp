//
// Created by LEI on 2/8/2018.
//

#include "Utility.h"
#include "GameState.h"
#include "Player.h"
bool is_yes(std::string& temp){
  if (temp[0] == 'Y' || temp[0] == 'y')
    return true;
  else if (temp[0] == 'N' || temp[0] == 'n')
    return  false;
  else
    return false;
}

/*bool is_game_over(GameState gameState){
  if (gameState.get_num_players() <= gameState.get_num_players_left())
    return true;
}*/






