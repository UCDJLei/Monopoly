//
// Created by LEI on 2/8/2018.
//

#include "Utility.h"
#include "GameState.h"
#include "Player.h"
bool is_yes(std::string& temp){
  if (temp == "Yes")
    return true;
  else if (temp == "No")
    return  false;

}

bool is_game_over(GameState gameState){
  if (gameState.get_num_players() <= gameState.get_num_players_left())
    return true;
}

/*void display_game_state(GameState gamestate){
  std::cout<<"Space Number | Space Name | Owner | Players"<<std::endl;
  for(int i = 0 ; i <gamestate.get_num_space(); i ++){
  // gamestate.get_board().get_spacevec().at(0
    //std::cout<<i << "|"<< *(gamestate.get_board().get_spacevec()[i])
    gamestate.get_board().
  }
}*/




