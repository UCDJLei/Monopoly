#include <iostream>
#include "GameState.h"
#include "Utility.h"
#include "Move.h"
int main(int argc, char** argv) {

  std::string args [argc];

  for (int i = 0; i < argc; i++) {
    //convert char* -> string
    std::string temp (argv[i]);
    args[i] = temp;
   // std::cout << "arg " << i << ": " << temp << std::endl;
  }

  //init Rules....
  //pass into game state
  GameState gamestate(args[1],args[2],args[3]);
 // gamestate.set_num_space();
  gamestate.set_players();

  //std::cout<<"after reading gamestate"<<std::endl;
  gamestate.display_gamestate();

  while(!(gamestate.is_game_over())) {
    Move move (gamestate);
    move.get_move(gamestate);//while loop in side to keep track whether the player has rolled the dice
    move.make_move(gamestate);
    gamestate.display_gamestate();

    //change_turn;
    gamestate.next_player();
  }
  gamestate.declare_winner();

  return 0;
}